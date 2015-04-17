#include "StereoVision.h"

RobotVisionWindows::StereoVision::StereoVision(void)
{
}
//************************************
void RobotVisionWindows::StereoVision::Initialize(System::String^ FilePath){

	LoadCamerasIDFromFile(FilePath);

	CameraLeft.open(LeftCameraDeviceID);//1
	if(!(CameraLeft.isOpened())) {LeftCameraAvailable = false;System::Windows::Forms::MessageBox::Show("Cannot Find The Left Camera","Camera Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);ProgramLog::write_log("(!)Error On Left Camera");}
	else LeftCameraAvailable = true;

	CameraLeft.set(CV_CAP_PROP_FRAME_WIDTH,432);
	CameraLeft.set(CV_CAP_PROP_FRAME_HEIGHT,240);

	CameraLeft  >> MatCamImageLeft;

	Threading::Thread::Sleep(50);

	CameraRight.open(RightCameraDeviceID);//0
	if(!(CameraRight.isOpened())){RightCameraAvailable = false;System::Windows::Forms::MessageBox::Show("Cannot Find The Right Camera","Camera Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);ProgramLog::write_log("(!)Error On Right Camera");}
	else RightCameraAvailable = true;

	mx1 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );
	my1 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );
	mx2 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );
	my2 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );

	CalibrationMatrixLoaded = false;
	ProjectionMatrixLoaded = false;
	VideoCapturing = false;
	//************************************
	LoadCamerasConfigFromFile(FilePath);
	//************************************
	LoadStereoConfigFromFile(FilePath);
	//************************************
	CameraRight.set(CV_CAP_PROP_FRAME_WIDTH,432);
	CameraRight.set(CV_CAP_PROP_FRAME_HEIGHT,240);

}
//************************************
void RobotVisionWindows::StereoVision::InitializeCameras(){
	if(!RightCameraAvailable)CameraRight.open(RightCameraDeviceID);//0
	if(!LeftCameraAvailable)CameraLeft.open(LeftCameraDeviceID);//1
	if(CameraRight.isOpened()) RightCameraAvailable = true;
	if(CameraLeft.isOpened()) LeftCameraAvailable = true;
}
//************************************
void RobotVisionWindows::StereoVision::CaptureFramFromCAM(){
	CameraRight >> MatCamImageRight;
	CameraLeft  >> MatCamImageLeft;
	if(MatCamImageRight.empty()){RightCameraAvailable = false;}
	if(MatCamImageLeft.empty()) {LeftCameraAvailable = false;}
};
//************************************
void RobotVisionWindows::StereoVision::LoadCamerasIDFromFile(System::String^ FilePath){
	RightCameraDeviceID = 0;
	LeftCameraDeviceID = 1;
	try{array<System::String^>^ FileString =  System::IO::File::ReadAllLines(FilePath);
	LeftCameraDeviceID = int::Parse(FileString[45]->Substring(21));
	RightCameraDeviceID = int::Parse(FileString[46]->Substring(21));
	}
	catch(...){System::Windows::Forms::MessageBox::Show("Cannot Read Stereo Configuration File","File Read Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);ProgramLog::write_log("(!)Error On Reading Stereo Config");}
}
//************************************
void RobotVisionWindows::StereoVision::LoadCamerasConfigFromFile(System::String^ FilePath){
	try{array<System::String^>^ FileString =  System::IO::File::ReadAllLines(FilePath);
	CameraRight.set(CV_CAP_PROP_BRIGHTNESS,int::Parse(FileString[23]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_CONTRAST,int::Parse(FileString[24]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_SATURATION,int::Parse(FileString[25]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_GAIN,int::Parse(FileString[26]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_EXPOSURE,int::Parse(FileString[27]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_WHITE_BALANCE_BLUE_U,int::Parse(FileString[28]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_SHARPNESS,int::Parse(FileString[29]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_ZOOM,int::Parse(FileString[30]->Substring(21)));
	CameraRight.set(CV_CAP_PROP_FOCUS,int::Parse(FileString[31]->Substring(21)));

	CameraLeft.set(CV_CAP_PROP_BRIGHTNESS, int::Parse(FileString[34]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_CONTRAST,int::Parse(FileString[35]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_SATURATION,int::Parse(FileString[36]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_GAIN,int::Parse(FileString[37]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_EXPOSURE,int::Parse(FileString[38]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_WHITE_BALANCE_BLUE_U,int::Parse(FileString[39]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_SHARPNESS,int::Parse(FileString[40]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_ZOOM,int::Parse(FileString[41]->Substring(21)));
	CameraLeft.set(CV_CAP_PROP_FOCUS,int::Parse(FileString[42]->Substring(21)));
	}
	catch(...){System::Windows::Forms::MessageBox::Show("Cannot Read Robot Configuration File","File Read Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);ProgramLog::write_log("(!)Error On Reading Stereo Config");}
}
//************************************
void RobotVisionWindows::StereoVision::LoadStereoConfigFromFile(System::String^ FilePath){
	ndisparities=48;
	SADWindowSize=21;
	newVal=0;
	maxSpeckleSize=500;
	MaxDiff=25;
	dilateVal=2;
	blurVal=3;
	try{array<System::String^>^ FileString =  System::IO::File::ReadAllLines(FilePath);
	ndisparities = int::Parse(FileString[47]->Substring(21));
	SADWindowSize = int::Parse(FileString[48]->Substring(21));
	newVal = int::Parse(FileString[49]->Substring(21));
	maxSpeckleSize = int::Parse(FileString[50]->Substring(21));
	MaxDiff = int::Parse(FileString[51]->Substring(21));
	dilateVal = int::Parse(FileString[52]->Substring(21));
	blurVal = int::Parse(FileString[53]->Substring(21));
	}
	catch(...){System::Windows::Forms::MessageBox::Show("Cannot Read Stereo Configuration File","File Read Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);ProgramLog::write_log("(!)Error On Reading Stereo Config");}
}
//************************************
void RobotVisionWindows::StereoVision::LoadCalibrationMatrix(){
	FileStorage fs;
	try{
		fs = FileStorage("Matrix/stereoCalibrateUndistorted_432x240.yml", FileStorage::READ); 
		if (fs.isOpened()){ 
			fs["MX1"] >> mx1; 
			fs["MY1"] >> my1; 
			fs["MX2"] >> mx2; 
			fs["MY2"] >> my2;
			CalibrationMatrixLoaded = true;} 
		fs.release();}
	catch(...){System::Windows::Forms::MessageBox::Show("Cannot Read Calibration Matrix File","File Read Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);}
}
//************************************
void RobotVisionWindows::StereoVision::UseCalibrationMatrix(){
	if(CalibrationMatrixLoaded){	
		remap(MatCamImageRight, MatCamImageRight, mx1, my1, INTER_LINEAR, BORDER_CONSTANT, Scalar());
		remap(MatCamImageLeft, MatCamImageLeft, mx2, my2, INTER_LINEAR, BORDER_CONSTANT, Scalar());}}
//************************************
void RobotVisionWindows::StereoVision::DisparityMapCalculation(){

	bool Speckle_Flag = true, Dilate_Flag = false, Blur_Flag = false;

	if (SADWindowSize <= 3)SADWindowSize=4;
	if (SADWindowSize % 2 == 0) {SADWindowSize += 1;}
	if (ndisparities == 0)ndisparities =16;
	if (ndisparities % 16 != 0){ndisparities += (16 - ndisparities%16);}

	StereoBM BM_Stereo;
	BM_Stereo.init(BM_Stereo.FISH_EYE_PRESET,ndisparities,SADWindowSize);
	Mat Disparity_map_visual;
	Mat Disparity_map_RTL,Disparity_map_LTR;
	Mat Disparity_map_RTL_converted,Disparity_map_LTR_converted;
	Mat ROI_temp_RTL, ROI_temp_LTR;
	Mat frame_Right_Gray, frame_Left_Gray;
	Mat frame_Right_Gray_fliped,frame_Left_Gray_fliped;

	cvtColor(MatCamImageRight,frame_Right_Gray,CV_BGR2GRAY);
	cvtColor(MatCamImageLeft,frame_Left_Gray,CV_BGR2GRAY);

	flip(frame_Left_Gray,frame_Left_Gray_fliped,1);
	flip(frame_Right_Gray,frame_Right_Gray_fliped,1);
	BM_Stereo(frame_Right_Gray_fliped,frame_Left_Gray_fliped, Disparity_map_RTL,CV_16S);
	if(Speckle_Flag){filterSpeckles(Disparity_map_RTL,newVal,maxSpeckleSize,MaxDiff,noArray());}
	Disparity_map_RTL.convertTo(ROI_temp_RTL, CV_8UC1, 15.9375 /(ndisparities-1));
	Disparity_map_RTL_converted=ROI_temp_RTL(Range(0,ROI_temp_RTL.rows),Range(DISPARITY_CONST,ROI_temp_RTL.cols));
	flip(Disparity_map_RTL_converted,Disparity_map_RTL_converted,1);

	BM_Stereo(frame_Left_Gray,frame_Right_Gray,Disparity_map_LTR,CV_16S);
	if(Speckle_Flag){filterSpeckles(Disparity_map_LTR,newVal,maxSpeckleSize,MaxDiff,noArray());}
	Disparity_map_LTR.convertTo(ROI_temp_LTR, CV_8UC1, 15.9375 /(ndisparities-1));
	Disparity_map_LTR_converted=ROI_temp_LTR(Range(0,ROI_temp_LTR.rows),Range(DISPARITY_CONST,ROI_temp_LTR.cols));

	Mat Disparity_map_RTL_converted_with_offset = Mat::zeros( Disparity_map_RTL_converted.rows, Disparity_map_RTL_converted.cols+25, CV_8UC1 );
	Mat roiImgResult_RTL  = Disparity_map_RTL_converted_with_offset(Rect(0,0,Disparity_map_RTL_converted.cols,Disparity_map_RTL_converted.rows)); 
	Disparity_map_RTL_converted.copyTo(roiImgResult_RTL);

	Mat Disparity_map_LTR_converted_with_offset = Mat::zeros( Disparity_map_LTR_converted.rows, Disparity_map_LTR_converted.cols+25, CV_8UC1 );
	Mat roiImgResult_LTR  = Disparity_map_LTR_converted_with_offset(Rect(25,0,Disparity_map_LTR_converted.cols,Disparity_map_LTR_converted.rows)); 
	Disparity_map_LTR_converted.copyTo(roiImgResult_LTR);

	for(int i=0;i<Disparity_map_RTL_converted_with_offset.cols;i++){
		for(int j=0;j<Disparity_map_RTL_converted_with_offset.rows;j++){
			if((Disparity_map_LTR_converted_with_offset.at<uchar>(j,i)) == 0)
				Disparity_map_LTR_converted_with_offset.at<uchar>(j,i) = Disparity_map_RTL_converted_with_offset.at<uchar>(j,i);}}

	Disparity_map_visual = Disparity_map_LTR_converted_with_offset;

	if(Dilate_Flag){dilate(Disparity_map_visual,Disparity_map_visual,Mat(),cvPoint(-1,-1),dilateVal,BORDER_CONSTANT,morphologyDefaultBorderValue());}
	if(Blur_Flag){if((blurVal%2) == 0)blurVal=blurVal-1;if(blurVal<3)blurVal=3;medianBlur(Disparity_map_visual,Disparity_map_visual,blurVal);}

	MatDisparityMap = Mat::zeros(MatCamImageRight.rows, MatCamImageRight.cols, CV_8UC1);
	resize(Disparity_map_visual,MatDisparityMap,Size(432,240),0,0,INTER_CUBIC);

	//cvtColor(MatDisparityMap,MatDisparityMap3Channel,CV_GRAY2BGR);

	MatDisparityMap3Channel = Mat(MatDisparityMap.rows, MatDisparityMap.cols, CV_8UC3);
	Mat disparitychannels[3];
	disparitychannels[0] = MatDisparityMap.clone();
	disparitychannels[1] = MatDisparityMap.clone();
	disparitychannels[2] = MatDisparityMap.clone();
	merge(disparitychannels,3,MatDisparityMap3Channel);
}
//************************************
bool RobotVisionWindows::StereoVision::IsRightCameraAvaiable(void){return RightCameraAvailable;}
//************************************
bool RobotVisionWindows::StereoVision::IsLeftCameraAvaiable(void){return LeftCameraAvailable;}
//************************************
Mat RobotVisionWindows::StereoVision::getCamImageRight(void){return MatCamImageRight;}
//************************************
Mat RobotVisionWindows::StereoVision::getCamImageLeft(void){return MatCamImageLeft;}
//************************************
Mat RobotVisionWindows::StereoVision::getDisparityMap3Channel(void){return MatDisparityMap3Channel;}
//************************************
int RobotVisionWindows::StereoVision::getRightCameraDeviceID(void){return RightCameraDeviceID;}
//************************************
int RobotVisionWindows::StereoVision::getLeftCameraDeviceID(void){return LeftCameraDeviceID;}
//************************************
void RobotVisionWindows::StereoVision::SetBrightness(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_BRIGHTNESS,value);
	else CameraRight.set(CV_CAP_PROP_BRIGHTNESS,value);}
//************************************
void RobotVisionWindows::StereoVision::SetContrast(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_CONTRAST,value);
	else CameraRight.set(CV_CAP_PROP_CONTRAST,value);}
//************************************
void RobotVisionWindows::StereoVision::SetSaturation(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_SATURATION,value);
	else CameraRight.set(CV_CAP_PROP_SATURATION,value);}
//************************************
void RobotVisionWindows::StereoVision::SetGain(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_GAIN,value);
	else CameraRight.set(CV_CAP_PROP_GAIN,value);}
//************************************
void RobotVisionWindows::StereoVision::SetExposure(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_EXPOSURE,value);
	else CameraRight.set(CV_CAP_PROP_EXPOSURE,value);}
//************************************
void RobotVisionWindows::StereoVision::SetWhiteBalance(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_WHITE_BALANCE_BLUE_U,value);
	else CameraRight.set(CV_CAP_PROP_WHITE_BALANCE_BLUE_U,value);}
//************************************
void RobotVisionWindows::StereoVision::SetSharpness(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_SHARPNESS,value);
	else CameraRight.set(CV_CAP_PROP_SHARPNESS,value);}
//************************************
void RobotVisionWindows::StereoVision::SetZoom(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_ZOOM,value);
	else CameraRight.set(CV_CAP_PROP_ZOOM,value);}
//************************************
void RobotVisionWindows::StereoVision::SetFocus(int CameraNumber,int value){
	if(CameraNumber == LeftCameraDeviceID) CameraLeft.set(CV_CAP_PROP_FOCUS,value);
	else CameraRight.set(CV_CAP_PROP_FOCUS,value);}
//************************************
int RobotVisionWindows::StereoVision::GetBrightness(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_BRIGHTNESS);
	else return (int)CameraRight.get(CV_CAP_PROP_BRIGHTNESS);}
//************************************
int RobotVisionWindows::StereoVision::GetContrast(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_CONTRAST);
	else return (int)CameraRight.get(CV_CAP_PROP_CONTRAST);}
//************************************
int RobotVisionWindows::StereoVision::GetSaturation(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_SATURATION);
	else return (int)CameraRight.get(CV_CAP_PROP_SATURATION);}
//************************************
int RobotVisionWindows::StereoVision::GetGain(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_GAIN);
	else return (int)CameraRight.get(CV_CAP_PROP_GAIN);}
//************************************
int RobotVisionWindows::StereoVision::GetExposure(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_EXPOSURE);
	else return (int)CameraRight.get(CV_CAP_PROP_EXPOSURE);}
//************************************
int RobotVisionWindows::StereoVision::GetWhiteBalance(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_WHITE_BALANCE_BLUE_U);
	else return (int)CameraRight.get(CV_CAP_PROP_WHITE_BALANCE_BLUE_U);}
//************************************
int RobotVisionWindows::StereoVision::GetSharpness(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_SHARPNESS);
	else return (int)CameraRight.get(CV_CAP_PROP_SHARPNESS);}
//************************************
int RobotVisionWindows::StereoVision::GetZoom(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_ZOOM);
	else return (int)CameraRight.get(CV_CAP_PROP_ZOOM);}
//************************************
int RobotVisionWindows::StereoVision::GetFocus(int CameraNumber){
	if(CameraNumber == LeftCameraDeviceID) return (int)CameraLeft.get(CV_CAP_PROP_FOCUS);
	else return (int)CameraRight.get(CV_CAP_PROP_FOCUS);}
//************************************
void RobotVisionWindows::StereoVision::SnapShot(void){
	string filenames;
	string datetime = msclr::interop::marshal_as< std::string >(DateTime::Now.Day.ToString() + "-" + DateTime::Now.Month.ToString() + "-" + DateTime::Now.Year.ToString() + "_" + DateTime::Now.Hour.ToString() + "-" + DateTime::Now.Minute.ToString() +  "-" + DateTime::Now.Second.ToString());
	Mat camImage_Right_snap;
	Mat camImage_Left_snap;
	CameraRight.set(CV_CAP_PROP_FRAME_WIDTH,1920);
	CameraRight.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
	CameraLeft.set(CV_CAP_PROP_FRAME_WIDTH,1920);
	CameraLeft.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
	CameraRight >> camImage_Right_snap;
	CameraLeft  >> camImage_Left_snap;
	filenames = "SnapShot/CameImage_" + datetime + "_left"  + ".png";
	imwrite( filenames, camImage_Right_snap );
	filenames = "SnapShot/CameImage_" + datetime + "_right" + ".png";
	imwrite( filenames, camImage_Left_snap );
	ProgramLog::write_log("SnapShot Taken");
	CameraRight.set(CV_CAP_PROP_FRAME_WIDTH,432);
	CameraRight.set(CV_CAP_PROP_FRAME_HEIGHT,240);
	CameraLeft.set(CV_CAP_PROP_FRAME_WIDTH,432);
	CameraLeft.set(CV_CAP_PROP_FRAME_HEIGHT,240);
}
//************************************
void RobotVisionWindows::StereoVision::SaveDisparity(void){
	string filenames;
	string datetime = msclr::interop::marshal_as< std::string >(DateTime::Now.Day.ToString() + "-" + DateTime::Now.Month.ToString() + "-" + DateTime::Now.Year.ToString() + "_" + DateTime::Now.Hour.ToString() + "-" + DateTime::Now.Minute.ToString() +  "-" + DateTime::Now.Second.ToString());
	filenames = "Disparity/CameImage_" + datetime + "_left"  + ".png";
	imwrite( filenames, MatCamImageRight );
	filenames = "Disparity/CameImage_" + datetime + "_right" + ".png";
	imwrite( filenames, MatCamImageLeft );
	filenames = "Disparity/Disparity_" + datetime + ".png";
	imwrite( filenames, MatDisparityMap );
	ProgramLog::write_log("Disparity Saved");
}
//************************************
bool RobotVisionWindows::StereoVision::VideoCaptureStart(void){
	string datetime = msclr::interop::marshal_as< std::string >(DateTime::Now.Day.ToString() + "-" + DateTime::Now.Month.ToString() + "-" + DateTime::Now.Year.ToString() + "_" + DateTime::Now.Hour.ToString() + "-" + DateTime::Now.Minute.ToString() +  "-" + DateTime::Now.Second.ToString());
	string capturefilename = "Capture/CamVideo" + datetime + "_left"  + ".avi";
	//VideoCapturing = outputVideo.open(capturefilename,-1,25,MatCamImageLeft.size(),true); 
	VideoCapturing = outputVideo.open(capturefilename,CV_FOURCC('I','Y','U','V'),25,MatCamImageLeft.size(),true); 
	if(VideoCapturing){
		ProgramLog::write_log("video Capture Created");return true;}
	else
		ProgramLog::write_log("con not create viedeo file");return false;
}
//************************************
bool RobotVisionWindows::StereoVision::VideoCaptureContinue(void){
	if(outputVideo.isOpened()){
		outputVideo << MatCamImageLeft; 
		return true;}
	else return false;
}
//************************************
void RobotVisionWindows::StereoVision::VideoCaptureStop(void){
	if(outputVideo.isOpened()){outputVideo.release();VideoCapturing = false;
	ProgramLog::write_log("Video Saved");}
}
//************************************
bool RobotVisionWindows::StereoVision::getVideoCaptureStatus(void){return VideoCapturing;}
//************************************
RobotVisionWindows::StereoVision::~StereoVision(void){
	outputVideo.release();	
	mx1.release();
	my1.release();
	mx2.release();
	my2.release();
	Q.release();
	MatCamImageRight.release();
	MatCamImageLeft.release();
	MatDisparityMap.release();
	MatDisparityMap3Channel.release();
	CameraRight.release();
	CameraLeft.release();
}
//************************************

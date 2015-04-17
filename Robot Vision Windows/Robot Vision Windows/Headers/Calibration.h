#pragma once
#include "../stdafx.h"

namespace RobotVisionWindows {


	class Calibration
	{
	private:

		bool CalibrationInProccess;
		Mat MatCamImageRight;
		Mat MatCamImageLeft;
		Mat MatDisparityMap;
		Mat MatDisparityMap3Channel;
		VideoCapture CameraRight;
		VideoCapture CameraLeft;
		Mat mx1;
		Mat my1;
		Mat mx2;
		Mat my2;
		Mat Q;

		int numBoards;
		int numCornersHor;
		int numCornersVer;
		int numSquares;
		float squareSize;
		cv::Size board_sz;

		Mat _M1,_M2,_D1,_D2,_R,_T,_E,_F,_R1, _R2, _P1, _P2, _Q;

		int successes;
		bool found_right;
		bool found_left;
		double t;
		double STC;

		Mat imageUndistorted_left,imageUndistorted_right;
		Mat frame_Right_Gray;
		Mat frame_Left_Gray;

		vector<vector<Point2f>> image_points_right;
		vector<vector<Point2f>> image_points_left;
		vector<vector<Point3f>> object_points;

		vector<Point2f> corners_left;
		vector<Point2f> corners_right;
		vector<Point3f> obj;

	public:
		//************************************
		Calibration(void){}
		//************************************
		~Calibration(void){
			mx1.release();
			my1.release();
			mx2.release();
			my2.release();
			Q.release();
			MatCamImageRight.release();
			MatCamImageLeft.release();
			MatDisparityMap.release();
			MatDisparityMap3Channel.release();
		}
		//************************************
		Mat getCamImageRight(void){return MatCamImageRight;}
		//************************************
		Mat getCamImageLeft(void){return MatCamImageLeft;}
		//************************************
		bool CalibrationIsInProccess(void){return CalibrationInProccess;}
		//************************************
		int getSampleNumber(void){return successes;}
		//************************************
		int getRequiredSample(void){return numBoards;}
		//************************************
		void CancelCalibratio(void){CalibrationInProccess=false;}
		//************************************
		void Initialize(int RightCameraDeviceID,int LeftCameraDeviceID){

			CameraRight.open(RightCameraDeviceID);
			CameraLeft.open(LeftCameraDeviceID);
			if(!(CameraRight.isOpened())){System::Windows::Forms::MessageBox::Show("Cannot Find The Right Camera","Camera Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);ProgramLog::write_log("(!)Error On Right Camera");}
			if(!(CameraLeft.isOpened())) {System::Windows::Forms::MessageBox::Show("Cannot Find The Left Camera","Camera Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);ProgramLog::write_log("(!)Error On Left Camera");}

			CalibrationInProccess = true;

			numBoards = 15;
			numCornersHor = 8;
			numCornersVer = 5;
			numSquares = numCornersHor * numCornersVer;
			squareSize = 3 ;
			board_sz = cv::Size(numCornersHor, numCornersVer);

			_M1 = Mat::eye(3, 3, CV_64F);
			_M2 = Mat::eye(3, 3, CV_64F);

			successes = 0;
			found_right = false;
			found_left  = false;
			t=0;
			STC=0;

			Mat mx1 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );
			Mat my1 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );
			Mat mx2 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );
			Mat my2 = Mat( MatCamImageRight.rows,MatCamImageRight.cols, CV_32F );

			for(int j=0;j<numSquares;j++)
				obj.push_back(Point3f(float(j/numCornersHor),float(j%numCornersHor), 0.0f));
		}
		//************************************
		std::pair<Mat,Mat> ClibrationDrawChessboard(void){


			CameraRight >> MatCamImageRight;
			CameraLeft >> MatCamImageLeft;
			
			cvtColor(MatCamImageRight, frame_Right_Gray, CV_BGR2GRAY);
			cvtColor(MatCamImageLeft , frame_Left_Gray , CV_BGR2GRAY);

			found_right = findChessboardCorners(MatCamImageRight, board_sz, corners_right, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS); 
			found_left  = findChessboardCorners(MatCamImageLeft , board_sz, corners_left , CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);

			if(found_right)
			{
			cornerSubPix(frame_Right_Gray, corners_right, cv::Size(11, 11), cv::Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
			drawChessboardCorners(MatCamImageRight, board_sz, corners_right, found_right);
			}
			if(found_left)
			{
			cornerSubPix(frame_Left_Gray, corners_left, cv::Size(11, 11), cv::Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
			drawChessboardCorners(MatCamImageLeft, board_sz, corners_left, found_left);
			}
			
			return std::pair<Mat,Mat>(MatCamImageRight,MatCamImageLeft);
		}
		//************************************
		bool SaveSnapShot(void){
			if(found_right!=0 && found_left!=0 ){
				image_points_right.push_back(corners_right);
				image_points_left.push_back(corners_left);
				object_points.push_back(obj);
				successes++;
				return true;
			}
			return false;
		}
		//************************************
		std::pair<double,double> StereoCameraClibration(void){
			Mat intrinsic_right = Mat(3, 3, CV_32FC1);
			Mat intrinsic_left = Mat(3, 3, CV_32FC1);
			Mat distCoeffs_right,distCoeffs_left;
			vector<Mat> rvecs_right,rvecs_left;
			vector<Mat> tvecs_right,tvecs_left;

			intrinsic_left.ptr<float>(0)[0] = 1;
			intrinsic_left.ptr<float>(1)[1] = 1;
			intrinsic_right.ptr<float>(0)[0] = 1;
			intrinsic_right.ptr<float>(1)[1] = 1;

			t = (double)getTickCount();
			try{
				STC = stereoCalibrate( object_points, image_points_right , image_points_left, _M1, _D1, _M2, _D2, MatCamImageRight.size(), _R, _T, _E, _F,
					TermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 100, 1e-5),
					//CV_CALIB_FIX_ASPECT_RATIO +
					//CV_CALIB_ZERO_TANGENT_DIST +
					//CV_CALIB_SAME_FOCAL_LENGTH +
					//CV_CALIB_FIX_K3);
					//CV_CALIB_FIX_ASPECT_RATIO +
					CV_CALIB_ZERO_TANGENT_DIST +
					CV_CALIB_SAME_FOCAL_LENGTH
					//CV_CALIB_RATIONAL_MODEL +
					//CV_CALIB_FIX_K3 + 
					//CV_CALIB_FIX_K4 + 
					//CV_CALIB_FIX_K5
					);
			}
			catch( cv::Exception& e ){
				const char* err_msg = e.what();
				MessageBox::Show("Calibration Faild","Calibration Error",MessageBoxButtons::OK,MessageBoxIcon::Error);
				CalibrationInProccess = false;
				return std::pair<double,double>(0,0);
				//cout << "exception caught: " << err_msg << std::endl;
			}

			//cout << "Camera Calibration Done in " << ((double)getTickCount() - t)/getTickFrequency()  << " Seconds and "<< STC << " RMS error." << endl;
			
			t = ((double)getTickCount() - t)/getTickFrequency();

			stereoRectify(_M1,_D1,_M2,_D2,MatCamImageRight.size(),_R,_T,_R1,_R2,_P1,_P2,_Q);

			FileStorage fs;
			fs = FileStorage("Matrix/stereoCalibrate_432x240.yml", FileStorage::WRITE); 
			if (fs.isOpened()){ 
				fs << "M1" << _M1; 
				fs << "D1" << _D1; 
				fs << "R1" << _R1; 
				fs << "P1" << _P1; 
				fs << "M2" << _M2; 
				fs << "D2" << _D2; 
				fs << "R2" << _R2; 
				fs << "P2" << _P2; 
				fs << "Q" << _Q; 
				//cout<< "Saved to stereoCalibrate_432x240.yml" << endl;
				fs.release();} 
			else{
				MessageBox::Show("Can not Save Calibration Matrix","Calibration Error",MessageBoxButtons::OK,MessageBoxIcon::Error);
				//cout<< "Can not Opent The file." << endl;
				fs.release();}

			initUndistortRectifyMap(_M1,_D1,_R1,_P1,MatCamImageRight.size(),CV_32FC1 ,mx1,my1);
			initUndistortRectifyMap(_M2,_D2,_R2,_P2,MatCamImageRight.size(),CV_32FC1 ,mx2,my2);

			fs = FileStorage("Matrix/stereoCalibrateUndistorted_432x240.yml", FileStorage::WRITE); 
			if (fs.isOpened()){ 
				fs << "MX1" << mx1; 
				fs << "MY1" << my1; 
				fs << "MX2" << mx2; 
				fs << "MY2" << my2;
				//cout<< "Saved to stereoCalibrateUndistorted_432x240.yml" << endl;
				fs.release();} 
			else{
				MessageBox::Show("Can not Save Undistortion Matrix","Calibration Error",MessageBoxButtons::OK,MessageBoxIcon::Error);
				//cout<< "Can not Opent The file." << endl;
				fs.release();}
			CalibrationInProccess = false;

			return std::pair<double,double>(t,STC);

		}
	};

}
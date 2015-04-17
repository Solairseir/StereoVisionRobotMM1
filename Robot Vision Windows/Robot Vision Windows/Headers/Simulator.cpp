#include "Simulator.h"


void RobotVisionWindows::Simulator::Initialize(int PictWidth,int PicHeight){
	PictureBoxWidth = PictWidth;
	PictureBoxHeight = PicHeight;
	start = cv::Point(0,0);
	goals.clear();
}
//************************************
bool RobotVisionWindows::Simulator::LoadMap(string MapFileAddress){

	Mat MatOpenMap = imread(MapFileAddress,1);
	if(MatOpenMap.empty()) return false;
	MatInputMap = Mat::zeros(MatOpenMap.rows * COEFFICIENT , MatOpenMap.cols * COEFFICIENT ,CV_8UC3);
	MatInputGrayScaleMap = Mat::zeros(MatOpenMap.rows * COEFFICIENT , MatOpenMap.cols * COEFFICIENT ,CV_8UC1);
	resize(MatOpenMap,MatInputMap,MatInputMap.size(),0,0,0);
	cvtColor(MatInputMap,MatInputGrayScaleMap,CV_BGR2GRAY);
	DrawGrid(MatInputMap);
	return true;
}
//************************************
void RobotVisionWindows::Simulator::DrawGrid(Mat Map){
	for(int i = 0 ; i<Map.cols;i=i+COEFFICIENT){line(Map,Point(i,0),Point(i,Map.rows),Scalar::all(150),1,8,0);}
	for(int i = 0 ; i<Map.rows;i=i+COEFFICIENT){line(Map,Point(0,i),Point(Map.cols,i),Scalar::all(150),1,8,0);}
}
//************************************
Mat RobotVisionWindows::Simulator::getMap(void){return MatInputMap;}
//************************************
Mat RobotVisionWindows::Simulator::getGrayScaleMap(void){return MatInputGrayScaleMap;}
//************************************
bool RobotVisionWindows::Simulator::getMapLoadedCorrectly(void){return MapLoadedCorrectly;}
//************************************
void RobotVisionWindows::Simulator::setMapLoadedCorrectly(bool input){MapLoadedCorrectly = input;}
//************************************
std::pair<float, float> RobotVisionWindows::Simulator::MapPicturBoxScale(void){
	return std::pair<float, float> ((float)MatInputMap.cols / (float)PictureBoxWidth , (float)MatInputMap.rows / (float)PictureBoxHeight);}
//************************************
void RobotVisionWindows::Simulator::MouseLeftClick(int picX,int picY){
	std::pair<float, float> MapPicturBoxScaleResult = MapPicturBoxScale();
	int x = int(Math::Round(MapPicturBoxScaleResult.first * picX));
	int y = int(Math::Round(MapPicturBoxScaleResult.second * picY));

	x -= (x % COEFFICIENT);x += COEFFICIENT/2;
	y -= (y % COEFFICIENT);y += COEFFICIENT/2;

	Point Clicked;Clicked.x = x;Clicked.y = y;

	if(MatInputMap.at<Vec3b>(y,x)[0] == 255 && MatInputMap.at<Vec3b>(y,x)[1] == 255 && MatInputMap.at<Vec3b>(y,x)[2] == 255){
		if(goalpositioninvector(Clicked) == -1){
			FillCell(MatInputMap,Clicked,'G');
			goals.push_back(Clicked);
		}}
	else if(goalpositioninvector(Clicked) != -1){
		if(goals.size() > 1){
			goals.erase (goals.begin()+goalpositioninvector(Clicked));
			FillCell(MatInputMap,Clicked,'W');
		}}

}
//************************************
void  RobotVisionWindows::Simulator::MouseMiddleClick(int picX,int picY){
	std::pair<float, float> MapPicturBoxScaleResult = MapPicturBoxScale();
	int x = int(Math::Round(MapPicturBoxScaleResult.first * picX));
	int y = int(Math::Round(MapPicturBoxScaleResult.second * picY));

	x -= (x % COEFFICIENT);x += COEFFICIENT/2;
	y -= (y % COEFFICIENT);y += COEFFICIENT/2;

	if(MatInputMap.at<Vec3b>(y,x)[0] == 255 && MatInputMap.at<Vec3b>(y,x)[1] == 255 && MatInputMap.at<Vec3b>(y,x)[2] == 255){
		if(start != cv::Point(0,0)) FillCell(MatInputMap,start,'W');
		start.x = x;
		start.y = y;
		FillCell(MatInputMap,start,'S');
	}
}
//************************************
void RobotVisionWindows::Simulator::MouseRightClick(int picX,int picY){
	std::pair<float, float> MapPicturBoxScaleResult = MapPicturBoxScale();
	int x = int(Math::Round(MapPicturBoxScaleResult.first * picX));
	int y = int(Math::Round(MapPicturBoxScaleResult.second * picY));

	x -= (x % COEFFICIENT);x += COEFFICIENT/2;
	y -= (y % COEFFICIENT);y += COEFFICIENT/2;

	Point Clicked;Clicked.x = x;Clicked.y = y;

	if(MatInputMap.at<Vec3b>(y,x)[0] == 255 && MatInputMap.at<Vec3b>(y,x)[1] == 255 && MatInputMap.at<Vec3b>(y,x)[2] == 255){
		FillCellGrayScale(MatInputGrayScaleMap,Clicked,'B');
		FillCell(MatInputMap,Clicked,'F');
	}
	else if(MatInputMap.at<Vec3b>(y,x)[0] == 80 && MatInputMap.at<Vec3b>(y,x)[1] == 80 && MatInputMap.at<Vec3b>(y,x)[2] == 80){
		FillCellGrayScale(MatInputGrayScaleMap,Clicked,'W');
		FillCell(MatInputMap,Clicked,'W');
	}
}
//************************************
void RobotVisionWindows::Simulator::FillCell(Mat MatToFill, cv::Point Cell,unsigned char CellMode){
	unsigned int Blue,Green,Red;
	switch (CellMode){
	case 'A' : {Blue=250;Green=190;Red=40 ;break;}
	case 'V' : {Blue=250;Green=125;Red=125;break;}
	case 'S' : {Blue=80 ;Green=255;Red=80 ;break;}
	case 'G' : {Blue=25 ;Green=25 ;Red=250;break;}
	case 'P' : {Blue=180;Green=180;Red=250;break;}
	case 'B' : {Blue=0  ;Green=0  ;Red=0  ;break;}
	case 'F' : {Blue=80 ;Green=80 ;Red=80 ;break;}
	case 'D' : {Blue=120;Green=120;Red=120;break;}
	case 'C' : {Blue=120;Green=120;Red=20;break;}
	case 'W' : {Blue=255;Green=255;Red=255;break;}}

	for(int i=-COEFFICIENT/2+1; i < COEFFICIENT/2 ; i++){
		for(int j=-COEFFICIENT/2+1; j < COEFFICIENT/2 ; j++){
			MatToFill.at<Vec3b>(Cell.y+i,Cell.x+j)[0] = Blue;MatToFill.at<Vec3b>(Cell.y+i,Cell.x+j)[1] = Green;MatToFill.at<Vec3b>(Cell.y+i,Cell.x+j)[2] = Red;}}
}
//************************************
void RobotVisionWindows::Simulator::FillCellGrayScale(Mat MatToFill, cv::Point Cell,unsigned char CellMode){
	unsigned char Color;
	switch (CellMode){
	case 'B' : {Color=0;break;}
	case 'W' : {Color=255;break;}}

	for(int i=-COEFFICIENT/2+1; i < COEFFICIENT/2 ; i++){
		for(int j=-COEFFICIENT/2+1; j < COEFFICIENT/2 ; j++){
			MatToFill.at<uchar>(Cell.y+i,Cell.x+j) = Color;}}
}
//************************************
int RobotVisionWindows::Simulator::goalpositioninvector(Point currentgoal){
	for(unsigned int i=0;i<goals.size();i++){if(currentgoal == goals[i])return i;}
	return -1;}
//************************************
cv::Point RobotVisionWindows::Simulator::getStart(void){return start;}
//************************************
vector<cv::Point> RobotVisionWindows::Simulator::getGoals(void){return goals;}
//************************************
void RobotVisionWindows::Simulator::DrawInitialPath(vector<vector<cv::Point>> Paths){
	MatInitialPathMap = MatInputMap.clone();
	for (unsigned int i = 0; i < Paths.size() ; i++){
		for (unsigned int j = 0; j < Paths[i].size() ; j++){
			FillCell(MatInitialPathMap, Paths[i][j],'C');
		}
	}
	for (unsigned int i = 0; i < goals.size() ; i++)
		FillCell(MatInitialPathMap, goals[i],'G');
	FillCell(MatInitialPathMap,start,'S');
}
//************************************
Mat RobotVisionWindows::Simulator::getInitialPathMap(void){return MatInitialPathMap;}
//************************************
Mat RobotVisionWindows::Simulator::ShowRobotPositionOnMap(cv::Point CurrentRobotPosition){
	Mat RobotCurrentPositionMap = MatInitialPathMap.clone();
	FillCell(RobotCurrentPositionMap, CurrentRobotPosition,'A');
	return RobotCurrentPositionMap;
}
//************************************
RobotVisionWindows::Simulator::Simulator(void){}
//************************************
RobotVisionWindows::Simulator::~Simulator(void){
	MatInputMap.release();
	goals.clear();
}
//************************************

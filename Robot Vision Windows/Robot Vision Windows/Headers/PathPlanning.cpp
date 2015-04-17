#include "PathPlanning.h"

//************************************
void RobotVisionWindows::PathPlanning::Initialize(Mat InputMap,cv::Point start,vector<cv::Point> goals){
	Goals.clear();
	Paths.clear();
	Start = start;
	Goals = goals;
	bool PathPlanningIsInProcess = false;
	MatRobotMap = InputMap.clone();
}
//************************************		
void RobotVisionWindows::PathPlanning::CalculateInitialPath(void){
	CurrentStart = Start;
	for (int goalpointsindex = 0; goalpointsindex < Goals.size(); goalpointsindex++){
		CurrentGoal = Goals[goalpointsindex];
		InitializeCurrentSearch();
		vector<cv::Point> PathPoints = FindCurrentPath();
		Paths.push_back(PathPoints);
		CurrentStart = CurrentGoal;
	}
	PathPlanningIsInProcess = true;
}
//************************************
bool RobotVisionWindows::PathPlanning::getPathPlanningStatus(void){return PathPlanningIsInProcess;}
//************************************
void RobotVisionWindows::PathPlanning::setPathPlanningStatus(bool pathplanningstatus){PathPlanningIsInProcess = pathplanningstatus;}
//************************************		
vector<vector<cv::Point>> RobotVisionWindows::PathPlanning::getPath(void){return Paths;}
//************************************
void RobotVisionWindows::PathPlanning::InitializeCurrentSearch(void){

	//cvtColor(MatRobotMap,CurrentSearchRobotMap,CV_BGR2GRAY);
	CurrentSearchRobotMap = MatRobotMap.clone();

	Heuristic = 10;

	ProcessedPoints.clear();
	AssignedList.clear();
	NeigboursForMinSuccessorList.clear();

	MapH = Mat::zeros(CurrentSearchRobotMap.rows/COEFFICIENT,CurrentSearchRobotMap.cols/COEFFICIENT, CV_16U);
	MapG = Mat::zeros(CurrentSearchRobotMap.rows/COEFFICIENT,CurrentSearchRobotMap.cols/COEFFICIENT, CV_16U);	
	MapRHS = Mat::zeros(CurrentSearchRobotMap.rows/COEFFICIENT,CurrentSearchRobotMap.cols/COEFFICIENT, CV_16U);
	MapK = Mat::zeros(CurrentSearchRobotMap.rows/COEFFICIENT,CurrentSearchRobotMap.cols/COEFFICIENT, CV_16UC2);
	MapVisited = Mat::zeros(CurrentSearchRobotMap.rows/COEFFICIENT,CurrentSearchRobotMap.cols/COEFFICIENT, CV_8U);	

	for(int i = COEFFICIENT/2 ; i < CurrentSearchRobotMap.rows -COEFFICIENT/2 ; i+=COEFFICIENT){
		for(int j = COEFFICIENT/2 ; j < CurrentSearchRobotMap.cols - COEFFICIENT/2; j+=COEFFICIENT){
			MapH.at<ushort>(i/COEFFICIENT,j/COEFFICIENT) = H(Point(j,i),CurrentStart);
			MapG.at<ushort>(i/COEFFICIENT,j/COEFFICIENT) = Infinit;
			MapRHS.at<ushort>(i/COEFFICIENT,j/COEFFICIENT) = Infinit;}}

	MapRHS.at<ushort>(CurrentGoal.y/COEFFICIENT,CurrentGoal.x/COEFFICIENT) = 0;

	ProcessedPoints.push_back(CurrentGoal);

	MapK.at<Vec2w>(CurrentGoal.y/COEFFICIENT,CurrentGoal.x/COEFFICIENT)[0] = H(CurrentStart,CurrentGoal);
	MapK.at<Vec2w>(CurrentGoal.y/COEFFICIENT,CurrentGoal.x/COEFFICIENT)[1] = 0;
}
//************************************
vector<cv::Point> RobotVisionWindows::PathPlanning::FindCurrentPath(void){
	vector<cv::Point> path;
	cv::Point u;
	std::pair<int,int> Kold;
	std::pair<int,int> Knew;
	u = ProcessedPoints[LowestPriorityOfProcessedPoints()];
	Kold.first = MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[0];
	Kold.second = MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[1];
	while (( !ProcessedPoints.empty() && (Kold < CalcKey(CurrentStart))) || !(MapRHS.at<ushort>(CurrentStart.y/COEFFICIENT,CurrentStart.x/COEFFICIENT) == MapG.at<ushort>(CurrentStart.y/COEFFICIENT,CurrentStart.x/COEFFICIENT))){
		u = ProcessedPoints[LowestPriorityOfProcessedPoints()];
		Kold.first = MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[0];
		Kold.second = MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[1];
		Knew = CalcKey(u);
		if (Kold < Knew){MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[0] = Knew.first;MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[1] = Knew.second;}
		else if( MapG.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT) > MapRHS.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT)){
			MapVisited.at<uchar>(u.y/COEFFICIENT,u.x/COEFFICIENT) = Infinit8U;
			CurrentSearchRobotMap.at<uchar>(u.y,u.x) = 123;
			MapG.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT) = MapRHS.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT);
			ProcessedPoints.erase( ProcessedPoints.begin() + IsProcessedPoints(u));
			AssignNeigbours(u);
			for(unsigned int i = 0;i<AssignedList.size();i++){
				if(AssignedList[i] != CurrentGoal && MapVisited.at<uchar>(AssignedList[i].y/COEFFICIENT,AssignedList[i].x/COEFFICIENT) == 0){
					unsigned int AssignedRHS_tmp = MapRHS.at<ushort>(AssignedList[i].y/COEFFICIENT,AssignedList[i].x/COEFFICIENT);
					MapRHS.at<ushort>(AssignedList[i].y/COEFFICIENT,AssignedList[i].x/COEFFICIENT) = min(AssignedRHS_tmp, c(AssignedList[i], u) + MapG.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT));}
				UpdateVertex(AssignedList[i]);}
			AssignedList.clear();}
		else{
			unsigned int Gold = MapG.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT);
			MapG.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT) = Infinit;
			if (u != CurrentGoal){MapRHS.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT) = MinimumSuccessor(u).second;}
			if(MapVisited.at<uchar>(u.y/COEFFICIENT,u.x/COEFFICIENT) == 0){UpdateVertex(u);}
			AssignNeigbours(u);
			for(unsigned int i = 0;i<AssignedList.size();i++){
				if(MapVisited.at<uchar>(AssignedList[i].y/COEFFICIENT,AssignedList[i].x/COEFFICIENT) == 0){
					if( MapRHS.at<ushort>(AssignedList[i].y/COEFFICIENT,AssignedList[i].x/COEFFICIENT) == Gold + c(AssignedList[i],u)){
						if(AssignedList[i] != CurrentGoal) {MapRHS.at<ushort>(AssignedList[i].y/COEFFICIENT,AssignedList[i].x/COEFFICIENT) = MinimumSuccessor(AssignedList[i]).second;}}}
				UpdateVertex(AssignedList[i]);}
			AssignedList.clear();}}
	if(MapVisited.at<uchar>(CurrentStart.y/COEFFICIENT,CurrentStart.x/COEFFICIENT) != 0){
		Point current = CurrentStart;
		path.push_back(current);
		while (current != CurrentGoal)	{current = MinimumSuccessor(current).first;path.push_back(current);}}
	return path;}
//*************************************
unsigned int RobotVisionWindows::PathPlanning::H(cv::Point s,cv::Point s_){
	unsigned int H_value = abs(s.x - s_.x ) + abs(s.y - s_.y );
	return H_value*Heuristic/COEFFICIENT;}
//************************************
unsigned int RobotVisionWindows::PathPlanning::c(cv::Point s,cv::Point s_){
	int cost = int(sqrt((double)((s.x - s_.x)*(s.x - s_.x)) + ((s.y - s_.y)*(s.y - s_.y))));
	return cost;
}
//************************************
int RobotVisionWindows::PathPlanning::LowestPriorityOfProcessedPoints(void){
	int index=0;
	pair<int,int> minimum_Value = pair<int,int>(Infinit,Infinit);
	for(unsigned int i = 0 ; i < ProcessedPoints.size() ; i++){
		if(MapK.at<Vec2w>(ProcessedPoints[i].y/COEFFICIENT,ProcessedPoints[i].x/COEFFICIENT)[0] < minimum_Value.first || ((MapK.at<Vec2w>(ProcessedPoints[i].y/COEFFICIENT,ProcessedPoints[i].x/COEFFICIENT)[0] == minimum_Value.first) && MapK.at<Vec2w>(ProcessedPoints[i].y/COEFFICIENT,ProcessedPoints[i].x/COEFFICIENT)[1] < minimum_Value.second)){
			minimum_Value.first = MapK.at<Vec2w>(ProcessedPoints[i].y/COEFFICIENT,ProcessedPoints[i].x/COEFFICIENT)[0];
			minimum_Value.second = MapK.at<Vec2w>(ProcessedPoints[i].y/COEFFICIENT,ProcessedPoints[i].x/COEFFICIENT)[1];
			index = i;}}
	return index;}
//*************************************
std::pair<int,int> RobotVisionWindows::PathPlanning::CalcKey(cv::Point s){
	int g = MapG.at<ushort>(s.y/COEFFICIENT,s.x/COEFFICIENT);
	int rhs = MapRHS.at<ushort>(s.y/COEFFICIENT,s.x/COEFFICIENT);
	int min = (g < rhs) ? g : rhs;
	return std::pair<int,int>((min + MapH.at<ushort>(s.y/COEFFICIENT,s.x/COEFFICIENT)), min);}
//*************************************
unsigned int RobotVisionWindows::PathPlanning::IsProcessedPoints(cv::Point s){
	for(unsigned int i = 0 ; i < ProcessedPoints.size(); i++){
		if(ProcessedPoints[i] == s) return i;}
	return 0;}
//*************************************
void RobotVisionWindows::PathPlanning::AssignNeigbours(cv::Point VisitingCell){
	Point North    (VisitingCell.x              , VisitingCell.y - COEFFICIENT);
	Point South    (VisitingCell.x              , VisitingCell.y + COEFFICIENT);
	Point East     (VisitingCell.x + COEFFICIENT, VisitingCell.y	     	  );
	Point West     (VisitingCell.x - COEFFICIENT, VisitingCell.y			  );
	Point NorthEast(VisitingCell.x + COEFFICIENT, VisitingCell.y - COEFFICIENT);
	Point NorthWest(VisitingCell.x - COEFFICIENT, VisitingCell.y - COEFFICIENT);
	Point SouthEast(VisitingCell.x + COEFFICIENT, VisitingCell.y + COEFFICIENT);
	Point SouthWest(VisitingCell.x - COEFFICIENT, VisitingCell.y + COEFFICIENT);
	/*A*/ if(North.y > 0)						  {if(CurrentSearchRobotMap.at<uchar>(North) !=0){AssignedList.push_back(North);}}
	/*B*/ if(South.y < CurrentSearchRobotMap.rows){if(CurrentSearchRobotMap.at<uchar>(South) !=0){AssignedList.push_back(South);}}
	/*C*/ if(East.x  < CurrentSearchRobotMap.cols){if(CurrentSearchRobotMap.at<uchar>(East)  !=0){AssignedList.push_back(East); }}
	/*D*/ if(West.x > 0 )						  {if(CurrentSearchRobotMap.at<uchar>(West)  !=0){AssignedList.push_back(West); }}
	/*E*/ if(NorthEast.y >				0		 	  && NorthEast.x < CurrentSearchRobotMap.cols){if(CurrentSearchRobotMap.at<uchar>(NorthEast) !=0 && CurrentSearchRobotMap.at<uchar>(North)  !=0 && CurrentSearchRobotMap.at<uchar>(East)  !=0){AssignedList.push_back(NorthEast);}}
	/*F*/ if(NorthWest.y >				0		 	  && NorthWest.x >				0		     ){if(CurrentSearchRobotMap.at<uchar>(NorthWest) !=0 && CurrentSearchRobotMap.at<uchar>(North)  !=0 && CurrentSearchRobotMap.at<uchar>(West)  !=0){AssignedList.push_back(NorthWest);}}
	/*G*/ if(SouthEast.y < CurrentSearchRobotMap.rows && SouthEast.x < CurrentSearchRobotMap.cols){if(CurrentSearchRobotMap.at<uchar>(SouthEast) !=0 && CurrentSearchRobotMap.at<uchar>(South)  !=0 && CurrentSearchRobotMap.at<uchar>(East)  !=0){AssignedList.push_back(SouthEast);}}
	/*H*/ if(SouthWest.y < CurrentSearchRobotMap.rows && SouthWest.x >				0		     ){if(CurrentSearchRobotMap.at<uchar>(SouthWest) !=0 && CurrentSearchRobotMap.at<uchar>(South)  !=0 && CurrentSearchRobotMap.at<uchar>(West)  !=0){AssignedList.push_back(SouthWest);}}
}
//*************************************
void RobotVisionWindows::PathPlanning::UpdateVertex(cv::Point u){
	bool diff =  MapG.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT) != MapRHS.at<ushort>(u.y/COEFFICIENT,u.x/COEFFICIENT);
	unsigned int exists = IsProcessedPoints(u);
	if (diff && exists){
		MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[0] = CalcKey(u).first;
		MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[1] = CalcKey(u).second;}
	else if (diff && ! exists){ProcessedPoints.push_back(u);
	MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[0] = CalcKey(u).first;
	MapK.at<Vec2w>(u.y/COEFFICIENT,u.x/COEFFICIENT)[1] = CalcKey(u).second;}
	else if ( ! diff && exists){ProcessedPoints.erase( ProcessedPoints.begin() + IsProcessedPoints(u));}}
//*************************************
std::pair<cv::Point,unsigned int> RobotVisionWindows::PathPlanning::MinimumSuccessor(cv::Point s){
	Point min_cell;
	unsigned int min_cost = Infinit;
	NeigboursForMinSuccessor(s);
	for(unsigned int i = 0;i<NeigboursForMinSuccessorList.size();i++){
		if(MapG.at<ushort>(NeigboursForMinSuccessorList[i].y/COEFFICIENT,NeigboursForMinSuccessorList[i].x/COEFFICIENT)   != Infinit){
			if (MapG.at<ushort>(NeigboursForMinSuccessorList[i].y/COEFFICIENT,NeigboursForMinSuccessorList[i].x/COEFFICIENT) + c(NeigboursForMinSuccessorList[i],s)  < min_cost){
				min_cell = NeigboursForMinSuccessorList[i];
				min_cost = MapG.at<ushort>(NeigboursForMinSuccessorList[i].y/COEFFICIENT,NeigboursForMinSuccessorList[i].x/COEFFICIENT) + c(NeigboursForMinSuccessorList[i],s) ;}
		}}
	NeigboursForMinSuccessorList.clear();
	return pair<Point,unsigned int>(min_cell, min_cost);}
//*************************************
void RobotVisionWindows::PathPlanning::NeigboursForMinSuccessor(cv::Point VisitingCell){
	Point North    (VisitingCell.x              , VisitingCell.y - COEFFICIENT);
	Point South    (VisitingCell.x              , VisitingCell.y + COEFFICIENT);
	Point East     (VisitingCell.x + COEFFICIENT, VisitingCell.y			  );
	Point West     (VisitingCell.x - COEFFICIENT, VisitingCell.y			  );
	Point NorthEast(VisitingCell.x + COEFFICIENT, VisitingCell.y - COEFFICIENT);
	Point NorthWest(VisitingCell.x - COEFFICIENT, VisitingCell.y - COEFFICIENT);
	Point SouthEast(VisitingCell.x + COEFFICIENT, VisitingCell.y + COEFFICIENT);
	Point SouthWest(VisitingCell.x - COEFFICIENT, VisitingCell.y + COEFFICIENT);
	/*A*/ if(North.y >              0            ){if(CurrentSearchRobotMap.at<uchar>(North)  !=0){NeigboursForMinSuccessorList.push_back(North);}}
	/*B*/ if(South.y < CurrentSearchRobotMap.rows){if(CurrentSearchRobotMap.at<uchar>(South)  !=0){NeigboursForMinSuccessorList.push_back(South);}}
	/*C*/ if(East.x  < CurrentSearchRobotMap.cols){if(CurrentSearchRobotMap.at<uchar>(East)   !=0){NeigboursForMinSuccessorList.push_back(East); }}
	/*D*/ if(West.x  >              0            ){if(CurrentSearchRobotMap.at<uchar>(West)   !=0){NeigboursForMinSuccessorList.push_back(West); }}
	/*E*/ if(NorthEast.y >          0                 && NorthEast.x < CurrentSearchRobotMap.cols){if(CurrentSearchRobotMap.at<uchar>(NorthEast)  !=0 && (CurrentSearchRobotMap.at<uchar>(North)  !=0) && (CurrentSearchRobotMap.at<uchar>(East)  !=0)){NeigboursForMinSuccessorList.push_back(NorthEast);}}
	/*F*/ if(NorthWest.y >			0                 && NorthWest.x >              0            ){if(CurrentSearchRobotMap.at<uchar>(NorthWest)  !=0 && (CurrentSearchRobotMap.at<uchar>(North)  !=0) && (CurrentSearchRobotMap.at<uchar>(West)  !=0)){NeigboursForMinSuccessorList.push_back(NorthWest);}}
	/*G*/ if(SouthEast.y < CurrentSearchRobotMap.rows && SouthEast.x < CurrentSearchRobotMap.cols){if(CurrentSearchRobotMap.at<uchar>(SouthEast)  !=0 && (CurrentSearchRobotMap.at<uchar>(South)  !=0) && (CurrentSearchRobotMap.at<uchar>(East)  !=0)){NeigboursForMinSuccessorList.push_back(SouthEast);}}
	/*H*/ if(SouthWest.y < CurrentSearchRobotMap.rows && SouthWest.x >              0            ){if(CurrentSearchRobotMap.at<uchar>(SouthWest)  !=0 && (CurrentSearchRobotMap.at<uchar>(South)  !=0) && (CurrentSearchRobotMap.at<uchar>(West)  !=0)){NeigboursForMinSuccessorList.push_back(SouthWest);}}
}
//*************************************	
std::pair<int,std::pair<int,int>> RobotVisionWindows::PathPlanning::FindNextRobotDirection(int PathIndex,int PathPointIntex){

	int NextRobotDirection = -1;

	cv::Point CurrentPoint = Paths[PathIndex][PathPointIntex];
	cv::Point NextPoint;

	if(PathPointIntex < Paths[PathIndex].size() - 1){      // CurrentPoint != Goal
		PathPointIntex++;
		NextPoint = Paths[PathIndex][PathPointIntex];}   // Currentpoint = NextPoint in this Path
	else if  (PathIndex < Paths.size() - 1) {              // CurrentPoint == Goal and This is not the Last Path
		PathIndex++;
		PathPointIntex = 1;
		NextPoint = Paths[PathIndex][PathPointIntex];} // CurrentPoint == Start of The next Path
	else{												  // CurentPoint == Goal and this is the last path
		PathIndex = -1;  PathPointIntex = -1;             // Tell The Software The Last Goal Reached
		NextRobotDirection = -1;
		NextPoint = CurrentPoint;}

	if (CurrentPoint.x == NextPoint.x && NextPoint.y  < CurrentPoint.y)NextRobotDirection = RobotNorthDegree; //North
	else if (CurrentPoint.x == NextPoint.x && NextPoint.y  > CurrentPoint.y)NextRobotDirection = RobotSouthDegree; //South
	else if (CurrentPoint.x  < NextPoint.x && NextPoint.y == CurrentPoint.y)NextRobotDirection = RobotEastDegree;  //East
	else if (CurrentPoint.x  > NextPoint.x && NextPoint.y == CurrentPoint.y)NextRobotDirection = RobotWestDegree;  //West
	else if (CurrentPoint.x  < NextPoint.x && NextPoint.y  < CurrentPoint.y)NextRobotDirection = RobotNorthEastDegree; //NorthEast
	else if (CurrentPoint.x  < NextPoint.x && NextPoint.y  > CurrentPoint.y)NextRobotDirection = RobotSouthEastDegree; //SouthEast
	else if (CurrentPoint.x  > NextPoint.x && NextPoint.y  < CurrentPoint.y)NextRobotDirection = RobotNorthWestDegree; //NorthWest
	else if (CurrentPoint.x  > NextPoint.x && NextPoint.y  > CurrentPoint.y)NextRobotDirection = RobotSouthWestDegree; //SouthWest

	return std::pair<int,std::pair<int,int>> (NextRobotDirection,std::pair<int,int>(PathIndex,PathPointIntex));
}
//*************************************
cv::Point RobotVisionWindows::PathPlanning::GetRoborCurrentPositionPoint(int PathIndex,int PathPointIntex){return Paths[PathIndex][PathPointIntex];} 
//*************************************
RobotVisionWindows::PathPlanning::PathPlanning(void){}
//************************************
RobotVisionWindows::PathPlanning::~PathPlanning(void){
}
//************************************

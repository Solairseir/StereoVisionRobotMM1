#pragma once
#include "../stdafx.h"

#ifndef Infinit
#define Infinit 0xFFFF
#endif

#ifndef Infinit8U
#define Infinit8U 255
#endif

namespace RobotVisionWindows {


	class PathPlanning
	{
	private:

		Mat MatRobotMap;
		bool PathPlanningIsInProcess;

		cv::Point Start;

		vector<cv::Point> Goals;
		vector<vector<cv::Point>> Paths;

		//************************************
		vector<cv::Point> ProcessedPoints;
		vector<cv::Point> AssignedList;
		vector<cv::Point> NeigboursForMinSuccessorList;

		Mat CurrentSearchRobotMap;
		cv::Point CurrentStart;
		cv::Point CurrentGoal;

		Mat MapG;
		Mat MapH;
		Mat MapRHS;
		Mat MapK;
		Mat MapVisited;

		int cStraight;
		int cTurn;
		int Heuristic;

		void InitializeCurrentSearch(void);
		vector<cv::Point> FindCurrentPath(void);
		unsigned int H(cv::Point s,cv::Point s_);
		unsigned int c(cv::Point s,cv::Point s_);
		int LowestPriorityOfProcessedPoints(void);
		std::pair<int,int> CalcKey(cv::Point s);
		unsigned int IsProcessedPoints(cv::Point s);
		void AssignNeigbours(cv::Point VisitingCell);
		void UpdateVertex(cv::Point u);
		std::pair<cv::Point,unsigned int> MinimumSuccessor(cv::Point s);
		void NeigboursForMinSuccessor(cv::Point VisitingCell);

		//************************************
		static const int RobotNorthDegree     =  0;
		static const int RobotSouthDegree     =  180;
		static const int RobotWestDegree      = -90;
		static const int RobotEastDegree      =  90;
		static const int RobotNorthWestDegree = -45;
		static const int RobotSouthEastDegree =  135;
		static const int RobotSouthWestDegree = -135;
		static const int RobotNorthEastDegree =  45;

	public:

		void Initialize(Mat Map,cv::Point start,vector<cv::Point> goals);
		bool getPathPlanningStatus(void);
		void setPathPlanningStatus(bool);
		void CalculateInitialPath(void);
		vector<vector<cv::Point>> getPath(void);
		std::pair<int,std::pair<int,int>> FindNextRobotDirection(int PathIndex,int PathPointIntex);
		cv::Point GetRoborCurrentPositionPoint(int PathIndex,int PathPointIntex);
		//************************************
		PathPlanning(void);
		~PathPlanning(void);
	};
}
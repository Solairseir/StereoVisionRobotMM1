#pragma once
#include "../stdafx.h"

namespace RobotVisionWindows {


	class Simulator
	{
	private:

		bool MapLoadedCorrectly;
		Mat MatInputMap;
		Mat MatInputGrayScaleMap;
		void DrawGrid(Mat Map);
		int PictureBoxWidth;
		int PictureBoxHeight;
		std::pair<float, float>  MapPicturBoxScale(void);
		cv::Point start;
		vector<cv::Point> goals;

		void FillCell(Mat MatToFill,cv::Point Cell,unsigned char CellMode);
		void FillCellGrayScale(Mat MatToFill, cv::Point Cell,unsigned char CellMode);
		int goalpositioninvector(cv::Point CurrentPoint);

		Mat MatInitialPathMap;

	public:

		void Initialize(int PictureBoxWidth,int PictureBoxHeight);
		bool LoadMap(string MapFileAddress);
		Mat getMap(void);
		Mat getGrayScaleMap(void);
		bool getMapLoadedCorrectly(void);
		void setMapLoadedCorrectly(bool input);
		void MouseLeftClick(int x,int y);
		void MouseMiddleClick(int x,int y);
		void MouseRightClick(int x,int y);

		cv::Point getStart(void);
		vector<cv::Point> getGoals(void);

		//************************************
		void DrawInitialPath(vector<vector<cv::Point>> Paths);
		Mat getInitialPathMap(void);
		Mat ShowRobotPositionOnMap(cv::Point CurrentRobotPosition);
		//************************************
		Simulator(void);
		~Simulator(void);
	};
}
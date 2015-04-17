#pragma once
#include "../stdafx.h"

namespace RobotVisionWindows {


	class StereoVision
	{
	private:
		int RightCameraDeviceID;
		int LeftCameraDeviceID;
		Mat MatCamImageRight;
		Mat MatCamImageLeft;
		Mat MatDisparityMap;
		Mat MatDisparityMap3Channel;
		bool RightCameraAvailable;
		bool LeftCameraAvailable;
		VideoCapture CameraRight;
		VideoCapture CameraLeft;
		VideoWriter outputVideo;	
		Mat mx1;
		Mat my1;
		Mat mx2;
		Mat my2;
		Mat Q;
		bool CalibrationMatrixLoaded;
		bool ProjectionMatrixLoaded;
		bool VideoCapturing;
		//************************************
		int ndisparities;
		int SADWindowSize;
		int newVal;
		int maxSpeckleSize;
		int MaxDiff;
		int dilateVal;
		int blurVal;
		//***********************************
		void LoadCamerasIDFromFile(System::String^ FilePath);
		void LoadCamerasConfigFromFile(System::String^ FilePath);
		void LoadStereoConfigFromFile(System::String^ FilePath);

	public:
		void Initialize(System::String^ FilePath);
		void InitializeCameras(void);
		void CaptureFramFromCAM(void);
		void LoadCalibrationMatrix(void);
		void UseCalibrationMatrix(void);
		void DisparityMapCalculation(void);

		Mat getCamImageRight(void);
		Mat getCamImageLeft(void);
		Mat getDisparityMap3Channel(void);

		bool IsRightCameraAvaiable(void);
		bool IsLeftCameraAvaiable(void);
		int getRightCameraDeviceID(void);
		int getLeftCameraDeviceID(void);

		void SetBrightness(int CameraNumber,int value);
		void SetContrast(int CameraNumber,int value);
		void SetSaturation(int CameraNumber,int value);
		void SetGain(int CameraNumber,int value);
		void SetExposure(int CameraNumber,int value);
		void SetWhiteBalance(int CameraNumber,int value);
		void SetSharpness(int CameraNumber,int value);
		void SetZoom(int CameraNumber,int value);
		void SetFocus(int CameraNumber,int value);

		int GetBrightness(int CameraNumber);
		int GetContrast(int CameraNumber);
		int GetSaturation(int CameraNumber);
		int GetGain(int CameraNumber);
		int GetExposure(int CameraNumber);
		int GetWhiteBalance(int CameraNumber);
		int GetSharpness(int CameraNumber);
		int GetZoom(int CameraNumber);
		int GetFocus(int CameraNumber);

		void SnapShot(void);
		void SaveDisparity(void);
		bool VideoCaptureStart(void);
		bool VideoCaptureContinue(void);
		void VideoCaptureStop(void);
		bool getVideoCaptureStatus(void);

		StereoVision(void);
		~StereoVision(void);
	};
}
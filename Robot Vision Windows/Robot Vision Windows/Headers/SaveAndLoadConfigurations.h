#pragma once
namespace RobotVisionWindows {

	public ref class SaveAndLoadConfigurations
	{
		System::String^ FilePath;

	public:

		int LeftCameraAngle;
		int RightCameraAngle;
		array<int>^ CamerasUpperTiltAngle;
		array<int>^ CamerasMiddleTiltAngle;
		array<int>^ CamerasBottomTiltAngle;
		array<int>^ CamerasPanAngle;
		int ServoSpeed;
		int RobotSpeed;
		int SamplingDistance;
		int AvoidanceDistance;
		System::String^ MotorPort;
		int MotorBaudRate;
		System::String^ SensorPort;
		int SensorBaudRate;
		System::String^ IMUPort;
		int IMUBaudRate;
		double MotorBatteryLow;
		double ServoBatteryLow;
		double NUCBatteryLow;
		//********************************
		void Initialize(System::String^ filepath){FilePath =  filepath;
		CamerasUpperTiltAngle = gcnew array<int>(4);
		CamerasMiddleTiltAngle = gcnew array<int>(4);
		CamerasBottomTiltAngle = gcnew array<int>(4);
		CamerasPanAngle = gcnew array<int>(4);
		
		}
		//********************************
		void SaveConfigs(void){
			try
			{
				array<System::String^,1>^ FileString = System::IO::File::ReadAllLines(FilePath);
				FileString[0] = "***Motors Configuration***";
				FileString[1] = "Left  Camera Angle : " + LeftCameraAngle.ToString();
				FileString[2] = "Right Camera Angle : " + RightCameraAngle.ToString();
				FileString[3] = "Cameras UTiltAngle : " + CamerasUpperTiltAngle[0].ToString();
				FileString[4] = "Cameras MTiltAngle : " + CamerasMiddleTiltAngle[0].ToString();
				FileString[5] = "Cameras BTiltAngle : " + CamerasBottomTiltAngle[0].ToString();
				FileString[6] = "Cameras Pan Angle  : " + CamerasPanAngle[0].ToString();
				//FileString[7] = "Servo Speed       : " + ServoSpeed.ToString();
				FileString[8] = "Robot Speed        : " + RobotSpeed.ToString();
				FileString[10] = "***Path Planning Configuration***";
				FileString[11]  = "Sampling Distance  : " + SamplingDistance.ToString();
				FileString[12] = "Avoidance Distance : " + AvoidanceDistance.ToString();

				FileString[60] = "***Arm Configuration [2]***";
				FileString[61] = "Cameras UTiltAngle : " + CamerasUpperTiltAngle[1].ToString();
				FileString[62] = "Cameras MTiltAngle : " + CamerasMiddleTiltAngle[1].ToString();
				FileString[63] = "Cameras BTiltAngle : " + CamerasBottomTiltAngle[1].ToString();
				FileString[64] = "Cameras Pan Angle  : " + CamerasPanAngle[1].ToString();

				FileString[66] = "***Arm Configuration [3]***";
				FileString[67] = "Cameras UTiltAngle : " + CamerasUpperTiltAngle[2].ToString();
				FileString[68] = "Cameras MTiltAngle : " + CamerasMiddleTiltAngle[2].ToString();
				FileString[69] = "Cameras BTiltAngle : " + CamerasBottomTiltAngle[2].ToString();
				FileString[70] = "Cameras Pan Angle  : " + CamerasPanAngle[2].ToString();

				FileString[72] = "***Arm Configuration [4]***";
				FileString[73] = "Cameras UTiltAngle : " + CamerasUpperTiltAngle[3].ToString();
				FileString[74] = "Cameras MTiltAngle : " + CamerasMiddleTiltAngle[3].ToString();
				FileString[75] = "Cameras BTiltAngle : " + CamerasBottomTiltAngle[3].ToString();
				FileString[76] = "Cameras Pan Angle  : " + CamerasPanAngle[3].ToString();

				System::IO::File::WriteAllLines(FilePath,FileString);
			}
			catch(...){}
		}
		//********************************
		void LoadConfigs(void){
			try
			{
				array<System::String^,1>^ FileString = System::IO::File::ReadAllLines(FilePath);

				LeftCameraAngle = int::Parse(FileString[1]->Substring(21));
				RightCameraAngle = int::Parse(FileString[2]->Substring(21));
				CamerasUpperTiltAngle[0] = int::Parse(FileString[3]->Substring(21));
				CamerasMiddleTiltAngle[0] = int::Parse(FileString[4]->Substring(21));
				CamerasBottomTiltAngle[0] = int::Parse(FileString[5]->Substring(21));
				CamerasPanAngle[0] = int::Parse(FileString[6]->Substring(21));
				ServoSpeed = int::Parse(FileString[7]->Substring(21));
				RobotSpeed = int::Parse(FileString[8]->Substring(21));

				SamplingDistance = int::Parse(FileString[11]->Substring(21));
				AvoidanceDistance = int::Parse(FileString[12]->Substring(21));

				MotorPort =  FileString[15]->Substring(21);
				MotorBaudRate = int::Parse(FileString[16]->Substring(21));
				SensorPort = FileString[17]->Substring(21);
				SensorBaudRate = int::Parse(FileString[18]->Substring(21));
				IMUPort = FileString[19]->Substring(21);
				IMUBaudRate = int::Parse(FileString[20]->Substring(21));

				MotorBatteryLow = double::Parse(FileString[56]->Substring(21));
				ServoBatteryLow = double::Parse(FileString[57]->Substring(21));
				NUCBatteryLow = double::Parse(FileString[58]->Substring(21));

				CamerasUpperTiltAngle[1] = int::Parse(FileString[61]->Substring(21));
				CamerasMiddleTiltAngle[1] = int::Parse(FileString[62]->Substring(21));
				CamerasBottomTiltAngle[1] = int::Parse(FileString[63]->Substring(21));
				CamerasPanAngle[1] = int::Parse(FileString[64]->Substring(21));

				CamerasUpperTiltAngle[2] = int::Parse(FileString[67]->Substring(21));
				CamerasMiddleTiltAngle[2] = int::Parse(FileString[68]->Substring(21));
				CamerasBottomTiltAngle[2] = int::Parse(FileString[69]->Substring(21));
				CamerasPanAngle[2] = int::Parse(FileString[70]->Substring(21));

				CamerasUpperTiltAngle[3] = int::Parse(FileString[73]->Substring(21));
				CamerasMiddleTiltAngle[3] = int::Parse(FileString[74]->Substring(21));
				CamerasBottomTiltAngle[3] = int::Parse(FileString[75]->Substring(21));
				CamerasPanAngle[3] = int::Parse(FileString[76]->Substring(21));

			}
			catch(...){}


		}
	};
}
#pragma once
#include "RobotControl.h"
#include "SensorCommunication.h"
#include "IMUCommunication.h"

namespace RobotVisionWindows {

	public ref class CommunicationHandler
	{
	private:

		RobotControl RobotCom;
		SensorCommunication SensorCom;
		IMUCommunication IMUCom;
		double LeftMotorCurrentPosition;
		double RightMotorCurrentPosition;
		double LeftMotorLastPosition;
		double RightMotorLastPosition;
		//********************************

	public:

		bool InitializeIMU(System::String^ Portname,int BuadRate){return IMUCom.Initialize(Portname,BuadRate);}
		//********************************
		bool InitializeSensors(System::String^ Portname,int BuadRate){return SensorCom.Initialize(Portname,BuadRate);}
		//********************************
		bool InitializeMotors(System::String^ Portname,int BuadRate){return RobotCom.Initialize(Portname,BuadRate);}
		//********************************
		bool CloseMotorsPort(){return RobotCom.ClosePort();}
		//********************************
		bool CloseSensorsPort(){return SensorCom.ClosePort();}
		//********************************
		bool CloseIMUPort(){return IMUCom.ClosePort();}
		//********************************
		bool MotorsPortIsOpen(){return RobotCom.PortIsOpen();}
		//********************************
		bool SensorsPortIsOpen(){return SensorCom.PortIsOpen();}
		//********************************
		bool IMUPortIsOpen(){return IMUCom.PortIsOpen();}
		//********************************
		System::String^ TurnOnMotors(void){return SensorCom.TurnOn12V();}
		//********************************
		System::String^ TurnOnServos(void){return SensorCom.TurnOn6V();}
		//********************************
		System::String^ TurnOffMotors(void){return SensorCom.TurnOff12V();}
		//********************************
		System::String^ TurnOffServos(void){return SensorCom.TurnOff6V();}
		//********************************
		System::String^ ResetEncodersPositions(void){return SensorCom.ResetEncoders();}
		//********************************
		float Humidity(void){return SensorCom.Humidity();}
		//********************************
		float Temperature(void){return SensorCom.Temperature();}
		//********************************
		double LeftEncoderPosition(void){return SensorCom.LeftPos();}
		//********************************
		double RightEncoderPosition(void){return SensorCom.RightPos();}
		//********************************
		float ServoBatteryVoltage(void){return SensorCom.Batt6V();}
		//********************************
		float MotorBatteryVoltage(void){return SensorCom.Batt12V();}
		//********************************
		float NUCBatteryVoltage(void){return SensorCom.BattNUCV();}
		//********************************
		float MotorBatteryCurrent(void){return SensorCom.Batt12Current();}
		//********************************
		float ServoBatteryCurrent(void){return SensorCom.Batt6Current();}
		//********************************
		float NUCBatteryCurrent(void){return SensorCom.BattNUCCurrent();}
		//********************************
		//void TurnOnMotors(int Sensornumbers){for(int i = 0; i < Sensornumbers;i++) RobotCom.TurnServoOn(i);RobotCom.BothMotorStop();}
		//********************************
		//void TurnOffMotors(int Sensornumbers){RobotCom.BothMotorStop();for(int i = 0; i < Sensornumbers;i++) RobotCom.TurnServoOff(i);}
		//********************************
		bool MoveForward(int LeftMotorSpeed,int RightMotorSpeed){return RobotCom.MoveForward(LeftMotorSpeed,RightMotorSpeed);}
		//********************************
		bool MoveBackward(int LeftMotorSpeed,int RightMotorSpeed){return RobotCom.MoveBackward(LeftMotorSpeed,RightMotorSpeed);}
		//********************************
		bool TurnLeft(int LeftMotorSpeed,int RightMotorSpeed){return RobotCom.TurnLeft(LeftMotorSpeed,RightMotorSpeed);}
		//********************************
		bool TurnRight(int LeftMotorSpeed,int RightMotorSpeed){return RobotCom.TurnRight(LeftMotorSpeed,RightMotorSpeed);}
		//********************************
		bool BothMotorStop(void){return RobotCom.BothMotorStop();}
		//********************************
		bool TurnLeftCameraServo(int TurnDegree,int TurnSpeed){return RobotCom.TurnServo(1, TurnDegree, TurnSpeed);}
		//********************************
		bool TurnRightCameraServo(int TurnDegree,int TurnSpeed){return RobotCom.TurnServo(2,  TurnDegree, TurnSpeed);}
		//********************************
		bool TurnUpperTiltServo(int TurnDegree,int TurnSpeed){return RobotCom.TurnServo(3, TurnDegree, TurnSpeed);}
		//********************************
		bool TurnMiddleTiltServo(int TurnDegree,int TurnSpeed){return RobotCom.TurnServo(4, TurnDegree, TurnSpeed);}
		//********************************
		bool TurnBottomTiltServo(int TurnDegree,int TurnSpeed){return RobotCom.TurnServo(5, TurnDegree, TurnSpeed);}
		//********************************
		bool TurnPanServo(int TurnDegree,int TurnSpeed){return RobotCom.TurnServo(6, TurnDegree, TurnSpeed);}
		//********************************
		std::pair<double,double> findRobotMovmentByEncoders(){
			std::pair<double, double> PositionDiffs;
			LeftMotorCurrentPosition = LeftEncoderPosition();
			RightMotorCurrentPosition  = RightEncoderPosition();
			PositionDiffs.first  = LeftMotorCurrentPosition - LeftMotorLastPosition;
			PositionDiffs.second = RightMotorCurrentPosition - RightMotorLastPosition;
			return PositionDiffs;
		}
		//********************************
		std::pair<int,std::pair<int,int>> ReadIMU(void){return IMUCom.ReadData();}
	};
}
#pragma once
#include "MotorCommunication.h"

namespace RobotVisionWindows {

	public ref class RobotControl
	{	
	private:

		MotorCommunication MotorCom;
		//********************************
		bool RightMotorForward(int RightMotorSpeed){
			return MotorCom.TurnServo(15, 0, int((RightMotorSpeed + 90)*44.44));
		}
		//********************************
		bool LeftMotorForward(int LeftMotorSpeed){
			return MotorCom.TurnServo(16, 0, int((LeftMotorSpeed + 90)*44.44));
		}
		//********************************
		bool RightMotorBackward(int RightMotorSpeed){
			return MotorCom.TurnServo(15, 0, int((90 - RightMotorSpeed)*44.44));
		}
		//********************************
		bool LeftMotorBackward(int LeftMotorSpeed){
			return MotorCom.TurnServo(16, 0, int((90 - LeftMotorSpeed)*44.44));
		}
		//********************************
		bool RighthMotorStop(void){
			return MotorCom.TurnServo(15, 0, int((90)*44.44));
		}
		//********************************
		bool LeftMotorStop(void){
			return MotorCom.TurnServo(16, 0, int((90)*44.44));
		}

	public:

		bool Initialize(System::String^ Portname,int BuadRate){
			return MotorCom.Initialize(Portname,BuadRate);
		}
		//********************************
		bool ClosePort(){
			return MotorCom.ClosePort();
		}
		//********************************
		bool PortIsOpen(){
			return MotorCom.PortIsOpen();
		}
		//********************************
		bool MoveForward(int LeftMotorSpeed,int RightMotorSpeed){
			if (!RightMotorForward(RightMotorSpeed) || !LeftMotorForward(LeftMotorSpeed))return false;
			else return true;
		}
		//********************************
		bool MoveBackward(int LeftMotorSpeed,int RightMotorSpeed){
			if (!RightMotorBackward(RightMotorSpeed) || !LeftMotorBackward(LeftMotorSpeed))return false;
			else return true;
		}
		//********************************
		bool TurnLeft(int LeftMotorSpeed,int RightMotorSpeed){
			if (!RightMotorForward(RightMotorSpeed) || !LeftMotorBackward(LeftMotorSpeed))return false;
			else return true;
		}
		//********************************
		bool TurnRight(int LeftMotorSpeed,int RightMotorSpeed){
			if (!RightMotorBackward(RightMotorSpeed) || !LeftMotorForward(LeftMotorSpeed))return false;
			else return true;
		}
		//********************************
		bool BothMotorStop(void){
			if (!RighthMotorStop() || !LeftMotorStop()) return false;
			else return true;
		}
		//********************************
		bool TurnServo(int channel,int TurnDegree,int TurnSpeed){ //1454
			return MotorCom.TurnServo(channel, TurnSpeed, int((TurnDegree)*8));//44.44
		}
		//********************************
		bool TurnServoOn(int channel){
			return MotorCom.ActivateServo(channel);
		}
		//********************************
		bool TurnServoOff(int channel){
			return MotorCom.DeactivateServo(channel);
		}
	};
}
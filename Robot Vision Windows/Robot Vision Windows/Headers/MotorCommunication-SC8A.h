#pragma once
#include "SerialPorts.h"

namespace RobotVisionWindows {

	public ref class MotorCommunication
	{
	private:
		SerialPorts ServoPort;
	public:
		bool Initialize(System::String^ Portname,int BuadRate){
			return ServoPort.PortOpen(Portname,BuadRate);
		}
		//********************************
		bool ClosePort(){
			return ServoPort.PortClose();
		}
		//********************************
		bool PortIsOpen(){
			return ServoPort.PortIsOpen();
		}
		//********************************
		bool ActivateServo(int ServoChannel){
			char data = 0xDF &  ((char)ServoChannel | 0xC0);
			array<unsigned char>^ buffer={data,1};
			return ServoPort.PortWrite(buffer,2);
		}
		//********************************
		bool DeactivateServo(int ServoChannel){
			char data = 0xDF &  ((char)ServoChannel | 0xC0);
			array<unsigned char>^ buffer={data,0};
			return ServoPort.PortWrite(buffer,2);
		}
		//********************************
		bool TurnServo(int ServoChannel,int ServoSpeed,int ServoDegree){
			char data0 = 0xFF  & ((char)ServoChannel | 0xE0);
			char data1 = (ServoDegree >> 6) & 0x7F;
			char data2 = ServoDegree & 0x3F;
			array<unsigned char>^ buffer={data0,data1,data2,(char)ServoSpeed};
			return ServoPort.PortWrite(buffer,4);
		}
		//********************************
	};

}
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
			//char data = 0xDF &  ((char)ServoChannel | 0xC0);
			//array<unsigned char>^ buffer={data,1};
			//return ServoPort.PortWrite(buffer,2);
			return true;
		}
		//********************************
		bool DeactivateServo(int ServoChannel){
			//char data = 0xDF &  ((char)ServoChannel | 0xC0);
			//array<unsigned char>^ buffer={data,0};
			//return ServoPort.PortWrite(buffer,2);
			return true;
		}
		//********************************
		bool TurnServo(int ServoChannel,int ServoSpeed,int ServoDegree){ // Angale 0 to 4095 , Speed 0 to 63
			char data1 = ((char)ServoChannel | 0x40);
			char data2 = (ServoDegree >> 6) & 0x3F;
			char data3 = ServoDegree & 0x3F;
			char data4 = ServoSpeed & 0x3F;
			array<unsigned char>^ buffer={data1,data2,data3,data4};
			return ServoPort.PortWrite(buffer,4);
		}
		//********************************
	};

}
#pragma once
#include "SerialPorts.h"

namespace RobotVisionWindows {

	public ref class IMUCommunication
	{
	private:
		SerialPorts IMUPort;
		float Yaw;
		float Pitch;
		float Roll;
	public:
		bool Initialize(System::String^ Portname,int BuadRate){
			return IMUPort.PortOpen(Portname,BuadRate);
		}
		//********************************
		bool ClosePort(){
			return IMUPort.PortClose();
		}
		//********************************
		bool PortIsOpen(){
			return IMUPort.PortIsOpen();
		}
		//********************************
		std::pair<int,std::pair<int,int>> ReadData(void){
			std::pair<int,std::pair<int,int>> Output;
			IMUPort.PortWriteLine("#f");
			System::String^ Message=IMUPort.PortRead();
			analyzeData(Message);
			Output.first = (int)Yaw;
			Output.second.first = (int)Pitch;
			Output.second.second = (int)Roll;
			return Output;
		}
		//********************************
		void analyzeData(System::String^ inputstr){
			try{
				if(!System::String::Compare(inputstr->Substring(0,5),"#YPR=",true)){

					inputstr = inputstr->Substring(5);
					int pos = inputstr->IndexOf(',');
					Yaw = float::Parse(inputstr->Substring(0,pos));
					Yaw +=90;
					inputstr = inputstr->Substring(pos+1);
					pos = inputstr->IndexOf(',');
					Pitch = float::Parse(inputstr->Substring(0,pos));
					inputstr = inputstr->Substring(pos+1);
					Roll = float::Parse(inputstr);}
			}
			catch(...){
				Yaw = 0;
				Pitch = 0;
				Roll = 0;}
		}
		//********************************
	};
}
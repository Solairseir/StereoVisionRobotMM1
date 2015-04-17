#pragma once
#include "SerialPorts.h"

namespace RobotVisionWindows {

	public ref class SensorCommunication
	{
	private:
		SerialPorts SensorPort;
	public:
		bool Initialize(System::String^ Portname,int BuadRate){
			return SensorPort.PortOpen(Portname,BuadRate);
		}
		//********************************
		bool ClosePort(){
			return SensorPort.PortClose();
		}
		//********************************
		bool PortIsOpen(){
			return SensorPort.PortIsOpen();
		}
		//********************************
		System::String^ TurnOn12V(void){
			char data = 'A';
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message=SensorPort.PortRead();
			return Message;
		}
		//********************************
		System::String^ TurnOn6V(void){
			char data = 'B';
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message=SensorPort.PortRead();
			return Message;
		}
		//********************************
		System::String^ TurnOff12V(void){
			char data = 'a';
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message=SensorPort.PortRead();
			return Message;
		}
		//********************************
		System::String^ TurnOff6V(void){
			char data = 'b';
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message=SensorPort.PortRead();
			return Message;
		}
		//********************************
		System::String^ ResetEncoders(void){
			char data = 'O';
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message=SensorPort.PortRead();
			return Message;
		}
		//********************************
		float Humidity(void){
			float humidity_percent=0;
			char data = 0x48; //H
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				float sensor_humidity_Value =  float::Parse(Message); // sensor_humidity_Value * (5/1023);
				if(sensor_humidity_Value!=0) 
					humidity_percent = float((-0.2033*sensor_humidity_Value) + 216.4);
				return humidity_percent;}
			else return NULL;
		}
		//********************************
		float Temperature(void){
			float temperature_value=0;
			char data = 0x54;//T
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				float sensor_temperature_Value =  float::Parse(Message);
				if(sensor_temperature_Value!=0) 
					temperature_value = float((0.003*sensor_temperature_Value*sensor_temperature_Value) - (2.0051*sensor_temperature_Value) + 359.53) ;
				return temperature_value;}
			else return NULL;
		}
		//********************************
		double LeftPos(void){
			double position_left_Value=0;
			char data = 0x52;//R
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				position_left_Value =  double::Parse(Message); 
				return position_left_Value;}
			else return NULL;
		}
		//********************************
		double RightPos(void){
			double position_right_Value=0;
			char data = 0x4C; //L
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				position_right_Value =  double::Parse(Message); 
				return -position_right_Value;}
			else return NULL;
		}
		//********************************
		float BattNUCCurrent(void){		
			char data = '1'; 
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				float BatteryNUC_Value =  float::Parse(Message);
				BatteryNUC_Value-=510;
				BatteryNUC_Value *= 0.0048828125; // (5/1024) 
				return BatteryNUC_Value;}
			else return NULL;
		}
		//********************************
		float Batt6Current(void){		
			char data = '2'; 
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				float Battery6v_Value =  float::Parse(Message);
				Battery6v_Value-=510;
				Battery6v_Value *= 0.0048828125; // (5/1024)
				return Battery6v_Value;}
			else return NULL;
		}
		//********************************
		float Batt12Current(void){		
			char data = '3'; 
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				float Battery12v_Value =  float::Parse(Message);
				Battery12v_Value-=510;
				Battery12v_Value *= 0.0048828125; // (5/1024) 
				return Battery12v_Value;}
			else return NULL;
		}

		//********************************
		float Batt6V(void){
			char data = '6';
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead(); 
			if(!System::String::IsNullOrEmpty(Message)){
				float Battery6v_Value =  float::Parse(Message);
				Battery6v_Value *= 0.013671875; // (5/1024) * 2.8;
				return Battery6v_Value;}
			else return NULL;
		}
		//********************************
		float Batt12V(void){
			char data = '7'; 
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				float Battery12v_Value =  float::Parse(Message);
				Battery12v_Value *= 0.013671875; // (5/1024) * 2.8;
				return Battery12v_Value;}
			else return NULL;
		}
		//********************************
		float BattNUCV(void){			
			char data = '8'; 
			array<unsigned char>^ buffer={data};
			SensorPort.PortWrite(buffer,1);
			System::String^ Message;
			Message=SensorPort.PortRead();
			if(!System::String::IsNullOrEmpty(Message)){
				float BatteryNUCv_Value =  float::Parse(Message);
				BatteryNUCv_Value *= 0.013671875; // (5/1024) * 2.8;
				return BatteryNUCv_Value;}
			else return NULL;
		}

	};
}
/*
1 = NUC  Battery Current / Blue
2 = 6V   Battery Current / Yellow
3 = 13V  Battery Current / Orange
H = Humidity             / White
T = Temperature 		  / White
6 = 6V   Battery Voltage / Brown
7 = 13V  Battery Voltage / Blue
8 = NUC  Battery Voltage / Purple
A = 13V  Battery Relay   / Yellow
B = 6V   Battery Relay   / Yellow
*/
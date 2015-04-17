#pragma once

namespace RobotVisionWindows {

	public ref class SerialPorts {

	private	:

		System::IO::Ports::SerialPort serialport;
		//********************************		
		bool PortList(System::String^ Portname){
			array<System::String^>^ serialPorts = nullptr;
			try{
				serialPorts = System::IO::Ports::SerialPort::GetPortNames();}
			catch (System::ComponentModel::Win32Exception^ ex){
				System::Windows::Forms::MessageBox::Show(ex->Message,"Port Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);return false;}
			for each(System::String^ port in serialPorts){
				if(System::String::Compare(port,Portname,true)==0) return true;}
			return false;
		}
		//********************************
	public:

		bool PortOpen(System::String^ Portname,int BuadRate){
			if(!PortList(Portname)){System::Windows::Forms::MessageBox::Show("The Port Does not Exist on This Computer","Port Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);}
			serialport.PortName = Portname;
			serialport.BaudRate = (int)BuadRate;
			serialport.DataBits = 8;
			serialport.ReadTimeout = 1000;
			serialport.WriteTimeout = 1000;		
			try{serialport.Open();return true;}
			catch(...){return false;}}
		//********************************
		bool PortOpenRetry(void){
			try{serialport.Open();return true;}
			catch(...){return false;}}
		//********************************
		bool PortClose(){
			try{serialport.Close();return true;}
			catch(...){return false;}}
		//********************************
		System::String^ PortRead(void){
			try{
				System::String^ message = serialport.ReadLine();
				return  message;}
			catch(...){return System::String::Empty;}
		}
		//********************************
		bool PortWrite(System::String^ Data){
			try{serialport.Write(Data);return true;}
			catch(...){return false;}}
		//********************************
		bool PortWrite(array<unsigned char>^ buffer,int size){
			try{serialport.Write(buffer,0,size);return true;}
			catch(...){return false;}}
		//********************************
		bool PortWriteLine(System::String^ Data){
			try{serialport.WriteLine(Data);return true;}
			catch(...){return false;}}
		//********************************
		bool PortIsOpen(void){
			try{ 
				if(serialport.IsOpen)return true;
				else return false;}
			catch(...){return false;}}
	};
}
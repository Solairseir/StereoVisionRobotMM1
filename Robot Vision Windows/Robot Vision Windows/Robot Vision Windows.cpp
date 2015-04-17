// Robot Vision Windows.cpp : main project file.
#pragma once
#include "MainForm.h"

using namespace RobotVisionWindows;

[STAThreadAttribute]
int main(array<System::String ^> ^args){

	//HANDLE hHandle = CreateMutex( NULL, TRUE,TEXT("Global\\{719967F0-DCC6-49b5-9C61-DE91175C3187}"));
	//if( ERROR_ALREADY_EXISTS == GetLastError() )
	//{
	//	MessageBox::Show("Another instance of this Application is already running","Run Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Error);
	//	return(1); // Exit program
	//}

	HWND hWnd = ::FindWindowEx(0, 0, 0, TEXT("Robot Control Panel"));
	if(hWnd != NULL){ShowWindow(hWnd,SW_SHOWNORMAL);// exit this instance
		return(1);	}

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew MainForm());

	//ReleaseMutex( hHandle ); // Explicitly release mutex
	//CloseHandle( hHandle ); // close handle before terminating
	return 0;
}

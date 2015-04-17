#include "ProgramLog.h"

std::ofstream programlog;

bool ProgramLog::program_log_open(){		
	std::string logname;
		logname = "log/ProgramLog-"+ msclr::interop::marshal_as< std::string >(System::DateTime::Now.Day.ToString())+ "-" +msclr::interop::marshal_as< std::string >(System::DateTime::Now.Month.ToString()) + "-" + msclr::interop::marshal_as< std::string >(System::DateTime::Now.Year.ToString()) +".txt";
		try{programlog.open(logname,std::ios_base::app);return true;}
		catch(...){return false;}}
//********************************
bool ProgramLog::write_log(std::string logstring){
	try{programlog << msclr::interop::marshal_as< std::string >(System::DateTime::Now.ToString()) << " : " << logstring << std::endl;return true;}
	catch(...){return false;}}
//********************************
bool ProgramLog::program_log_close(){	
	try{programlog.close();return true;}
	catch(...){return false;}}

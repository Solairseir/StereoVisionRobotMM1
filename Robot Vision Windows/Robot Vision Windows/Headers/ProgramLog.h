#pragma once
#include <fstream>
#include <msclr\marshal_cppstd.h> 

class ProgramLog{
public:
	static bool program_log_open();
	static bool write_log(std::string logstring);
	static bool program_log_close();
};
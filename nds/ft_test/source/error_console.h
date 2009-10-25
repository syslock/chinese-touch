#ifndef ERROR_CONSOLE_H
#define ERROR_CONSOLE_H

#include <exception>
#include <iostream>
#include <sstream>

#include "hanzi-trainer.h"
#include "screen.h"

#if DEBUG
#define INIT_LOG() ErrorConsole::init()
#define LOG(a) std::cout << a << std::endl
#else
#define INIT_LOG()
#define LOG(a)
#endif

#define ERROR(x) Error( x, __FILE__, __LINE__, __TIMESTAMP__ )
class Error : public std::exception, public std::string
{
public:
	std::string file;
	int line;
	std::string timestamp;
	std::string full_msg;
public:
	Error( const char* msg, const char* _file, int _line, const char* _timestamp ) 
		: std::string(msg), file(_file), line(_line), timestamp(_timestamp) {}
	Error( const std::string& msg, const char* _file, int _line, const char* _timestamp ) 
		: std::string(msg), file(_file), line(_line), timestamp(_timestamp) {}
	virtual ~Error() throw () {}
	virtual const char* what()
	{
		std::stringstream _full_msg;
		std::size_t right_slash_pos = this->file.rfind('/');
		std::string _file;
		if( right_slash_pos != this->file.npos 
			&& right_slash_pos < this->file.size()-1 )
		{
			_file = this->file.substr( right_slash_pos+1 );
		}
		_full_msg << *this << " (" << _file << ":" << this->line << ") [" << this->timestamp << "]";
		this->full_msg = _full_msg.str();
		return this->full_msg.c_str();
	}
};

class ErrorConsole
{
public:
    static void init( Screen=SCREEN_SUB );
};

#endif

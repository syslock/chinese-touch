#ifndef ERROR_CONSOLE_H
#define ERROR_CONSOLE_H

#include <exception>
#include <iostream>

#include "screen.h"

class Error : public std::exception, public std::string
{
public:
	Error( const char* msg ) : std::string(msg) {}
	Error( const std::string& msg ) : std::string(msg) {}
	virtual ~Error() throw () {}
	virtual const char* what()
	{
		return this->c_str();
	}
};

class ErrorConsole
{
public:
    static void init( Screen=SCREEN_SUB );
};

#endif

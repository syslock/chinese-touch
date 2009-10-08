#ifndef ERROR_CONSOLE_H
#define ERROR_CONSOLE_H

#include "screen.h"

class ErrorConsole
{
public:
    static void init( Screen=SCREEN_SUB );
public:
    static bool initialized;
};

#endif

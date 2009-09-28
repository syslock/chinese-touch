#ifndef ERROR_CONSOLE_H
#define ERROR_CONSOLE_H

typedef enum 
{
    SCREEN_MAIN,
    SCREEN_SUB
} Screen;

class ErrorConsole
{
public:
    static void init( Screen=SCREEN_SUB );
public:
    static bool initialized;
};

#endif

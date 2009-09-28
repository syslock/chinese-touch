#include <nds.h>
#include <iostream>

#include "error_console.h"

bool ErrorConsole::initialized = false;

void ErrorConsole::init( Screen screen )
{
    if( !ErrorConsole::initialized )
    {
        switch( screen )
        {
            case SCREEN_SUB: 
            {  
                consoleDemoInit();
                std::cout << "console intialized" << std::endl;
                break; 
            }
            case SCREEN_MAIN: 
            {
                consoleDemoInit(); 
                std::cout << "console intialized" << std::endl;
                std::cout << "warning: initializing error console on main is not implemented" << std::endl; 
                break;
            }
        }
    }
    ErrorConsole::initialized = true;
}

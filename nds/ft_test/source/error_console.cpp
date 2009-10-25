#include <nds.h>
#include <iostream>

#include "error_console.h"


void ErrorConsole::init( Screen screen )
{
	switch( screen )
	{
		case SCREEN_SUB: 
		{
			videoSetModeSub( MODE_5_2D );
			vramSetBankC( VRAM_C_SUB_BG );
			consoleDemoInit();
			//consoleSelect( consoleGetDefault() );
			LOG( "sub console intialized" );
			break; 
		}
		case SCREEN_MAIN: 
		{
			videoSetMode(MODE_5_2D | DISPLAY_SCREEN_BASE(2));
			vramSetBankB(VRAM_B_MAIN_BG);
			PrintConsole topScreen = *consoleInit( 0, 0, BgType_Text4bpp, BgSize_T_256x256, 4, 8, true, true );
			topScreen.fontBgMap = BG_MAP_RAM(4 + 64);
			consoleSelect(&topScreen);
			LOG( "main console intialized" );
			break;
		}
	}
}

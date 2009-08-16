#include "string.h"
#include "nds.h"
#include "math.h"

#include "drawing_pad.h"

DrawingPad::DrawingPad() : res_x(256), res_y(192)
{
    // set the mode for 2 text layers and two extended background layers
	videoSetModeSub(MODE_5_2D);
    vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	this->bg3 = bgInitSub(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);
	// lineare 15-bit-graupalette mit 256 indizes aufbauen:
	for( int i=0; i<256; i++ )
	{
	    int value = (int)( ((double)i)*(double)(1<<5)/256.0 );
	    BG_PALETTE_SUB[255-i] = /*(1 << 15) |*/ (value << 10) | (value << 5) | value;
	}
	
	this->clear();
}

void DrawingPad::clear()
{
    // 1. clear background buffer with background color
    u16* base_address = bgGetGfxPtr(this->bg3);
    memset( base_address, 0, 256*265 );
}

void DrawingPad::draw( int x, int y )
{
    const int width = 3;
    u8 buffer[width*width] = { 0x2f, 0x7f, 0x2f,
                               0x7f, 0xff, 0x7f,
                               0x2f, 0x7f, 0x2f };
    for( int row=0; row<width; row++ )
    {
        for( int pixel=0; pixel<width; pixel+=2 )
        {
            u16 value = 0x0000;
            if( pixel < width-1 )
            {
                value = (buffer[row*width+pixel+1] << 8)
                            + buffer[row*width+pixel];
            }
            else
            {
                value = buffer[row*width+pixel];
            }
            u16* bg_gfx_ptr = bgGetGfxPtr(this->bg3);
            u16* base_address = bg_gfx_ptr
                    + ( row + y /*- width/2*/ ) * this->res_x/2
                    + (u16)round( (double)pixel/2.0 + (double)x/2.0 ) /*- width/2/2*/;
            if( base_address < bg_gfx_ptr
                || base_address > bg_gfx_ptr+this->res_x*this->res_y-2 )
            {
                return;
            }
            *base_address |= value;
        }
    }
}

void DrawingPad::draw_line( int x1, int y1, int x2, int y2 )
{
    double xd = x2-x1;
    double yd = y2-y1;
    int steps = abs(xd) > abs(yd) ? abs(xd) : abs(yd);
    this->draw( x1, y1 );
    for( int i=1; i<=steps; i++ )
    {
        this->draw( x1+i*xd/steps, y1+i*yd/steps );
    }
}


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
    const int height = 3;
    const int width = 5;
    u8 buffer[width*height] = { 0x00, 0x07, 0x10, 0x07, 0x00,
                                0x00, 0x10, 0xef, 0x10, 0x00,
                                0x00, 0x07, 0x10, 0x07, 0x00 };
    for( int row=0; row<height; row++ )
    {
        for( int pixel=(x%2 ? 0 : 1); pixel<width-1; pixel+=2 )
        {
            u16* bg_gfx_ptr = bgGetGfxPtr(this->bg3);
            u16* base_address = bg_gfx_ptr
                    + ( row + y - height/2 ) * this->res_x/2
                    + pixel/2 + x/2 - (width-1)/2/2;
            if( base_address < bg_gfx_ptr
                || base_address > bg_gfx_ptr+this->res_x*this->res_y-2 )
            {
                return;
            }
            u16 ov = *base_address;
            u8 ov1 = ov & 0x00ff;
            u8 ov2 = (ov & 0xff00) >> 8;
            u8 nv1 = ov1 + buffer[row*width+pixel];
            u8 nv2 = ov2 + buffer[row*width+pixel+1];
            *base_address = ((nv1 >= ov1) ? nv1 : 0xff)
                         + (((nv2 >= ov2) ? nv2 : 0xff) << 8);
//            *base_address = nv1 + (nv2 << 8);
        }
    }
}

void DrawingPad::draw_line( int x1, int y1, int x2, int y2 )
{
    double xd = x2-x1;
    double yd = y2-y1;
    int steps = abs(xd) > abs(yd) ? abs(xd) : abs(yd);
    this->draw( x1, y1 );
    // große Striche durch Sensorfehler ignorieren:
    if( steps > 40 )
        return;
    for( int i=1; i<=steps; i++ )
    {
        this->draw( x1+i*xd/steps, y1+i*yd/steps );
    }
}


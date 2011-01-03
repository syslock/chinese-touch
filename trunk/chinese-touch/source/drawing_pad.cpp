#include "string.h"
#include "nds.h"
#include "math.h"
#include <iostream>

#include "drawing_pad.h"


Pen::Pen(int _width, int _height, u8* _buffer ) : width(_width), height(_height), buffer(_buffer)
{
}

int DrawingPad::MAX_ACCELERATION_FACTOR = 5;

DrawingPad::DrawingPad( RenderScreen& _render_screen ) : render_screen(_render_screen)
{
}

void DrawingPad::clear( int color )
{
	this->render_screen.clear( color );
}

Pen DrawingPad::small_pen(3,3, (u8[]){ 	0x06, 0x0a, 0x06, 
										0x0a, 0xff, 0x0a, 
										0x06, 0x0a, 0x06 } );

Pen DrawingPad::medium_pen(7,7, (u8[]){ 0x00, 0x00, 0x06, 0x0a, 0x06, 0x00, 0x00,
										0x00, 0x06, 0x0a, 0xff, 0x0a, 0x06, 0x00,
										0x06, 0x0a, 0xff, 0xff, 0xff, 0x0a, 0x06,
										0x0a, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a,
										0x06, 0x0a, 0xff, 0xff, 0xff, 0x0a, 0x06,
										0x00, 0x06, 0x0a, 0xff, 0x0a, 0x06, 0x00,
										0x00, 0x00, 0x06, 0x0a, 0x06, 0x00, 0x00 } );

Pen DrawingPad::large_pen(9,9, (u8[]){ 	0x00, 0x00, 0x00, 0x06, 0x0a, 0x06, 0x00, 0x00, 0x00,
										0x00, 0x06, 0x0a, 0x7f, 0xff, 0x7f, 0x0a, 0x06, 0x00,
										0x00, 0x0a, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0x0a, 0x00,
										0x06, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x06,
										0x0a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a,
										0x06, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x06,
										0x00, 0x0a, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0x0a, 0x00,
										0x00, 0x06, 0x0a, 0x7f, 0xff, 0x7f, 0x0a, 0x06, 0x00,
										0x00, 0x00, 0x00, 0x06, 0x0a, 0x06, 0x00, 0x00, 0x00 } );

void DrawingPad::draw( int x, int y, const Pen& pen, bool erase )
{
    for( int row=0; row<pen.height; row++ )
    {
        for( int pixel=(x%2 ? 0 : 1); pixel<pen.width-1; pixel+=2 )
        {
            u16* bg_gfx_ptr = this->render_screen.base_address;
            u16* base_address = bg_gfx_ptr
                    + ( row + y - pen.height/2 ) * this->render_screen.res_x/2
                    + pixel/2 + x/2 - (pen.width-1)/2/2;
            if( base_address < bg_gfx_ptr
                || base_address > bg_gfx_ptr+this->render_screen.res_x*this->render_screen.res_y-2 )
            {
                continue;
            }
            u16 ov = *base_address;
            u8 ov1 = ov & 0x00ff;
            u8 ov2 = (ov & 0xff00) >> 8;
			if( !erase )
			{
				u8 nv1 = ov1 + pen.buffer[row*pen.width+pixel];
				u8 nv2 = ov2 + pen.buffer[row*pen.width+pixel+1];
				*base_address = ((nv1 >= ov1) ? nv1 : 0xff)
							+ (((nv2 >= ov2) ? nv2 : 0xff) << 8);
			}
			else
			{
				u8 nv1 = ov1 - pen.buffer[row*pen.width+pixel];
				u8 nv2 = ov2 - pen.buffer[row*pen.width+pixel+1];
				*base_address = ((nv1 <= ov1) ? nv1 : 0x00)
							+ (((nv2 <= ov2) ? nv2 : 0x00) << 8);
			}
        }
    }
}

void DrawingPad::draw_line( int x1, int y1, int x2, int y2, const Pen& pen, bool erase )
{
    double xd = x2-x1;
    double yd = y2-y1;
    int steps = abs(xd) > abs(yd) ? abs(xd) : abs(yd);
    this->draw( x1, y1, pen, erase );
    // große Striche durch Sensorfehler ignorieren:
    if( steps > 40 )
        return;
    for( int i=1; i<=steps; i++ )
    {
		this->draw( x1+i*xd/steps, y1+i*yd/steps, pen, erase );
    }
}


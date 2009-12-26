#ifndef DRAWING_PAD_H
#define DRAWING_PAD_H

#include "freetype_renderer.h"
#include "text_button.h"

class DrawingPad
{
public:
    RenderScreen& render_screen;
public:
    DrawingPad( RenderScreen& _render_screen );
    void clear( int color=0 );
    void draw( int x, int y, u8* buffer, int widht, int height );
    void draw_point( int x, int y );
    void draw_line( int x1, int y1, int x2, int y2 );
};

#endif // DRAWING_PAD_H

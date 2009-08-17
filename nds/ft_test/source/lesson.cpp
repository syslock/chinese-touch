#include <nds.h>

#include "lesson.h"

void Word::render( FreetypeRenderer& ft )
{
    // 1. clear background buffer with background color
    u16* base_address = bgGetGfxPtr(ft.bg3);
    memset( base_address, 0, 256*265 );
    
    // 2. render hanzi in the faces suggested layout (e.g. fixed width)
    RenderStyle render_style;
    render_style.center_x = true;
    int top = 10;
    RenderRect rect = ft.render( this->hanzi, ft.han_face, 32, 0, top, &render_style );
    top += rect.height;
    
    // 3. render pinyin in variable width
    top += 10;
    rect = ft.render( this->pinyin, ft.han_face, 16, 0, top, &render_style );
    top += rect.height;
    
    // 4. render translation in variable width
    top += 10;
    rect = ft.render( this->translations["de"], ft.latin_face, 9, 0, top, &render_style );
    top += rect.height;
}


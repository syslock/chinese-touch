#ifndef FREETYPE_RENDERER_H
#define FREETYPE_RENDERER_H

#include <map>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "unicode.h"

typedef std::map<int,const char*> ErrorMap;
extern ErrorMap ft_errors;

class FreetypeRenderer
{
public:
    FreetypeRenderer( const std::string& han_font, 
                    const std::string& latin_font );
    ~FreetypeRenderer();
    void render( const std::string& text, FT_Face& face, int pixel_size, 
                int x, int y, bool center_x=false, bool center_y=false );
public:
    FT_Error error;
    FT_Face han_face, latin_face;
    FT_Library library;
    int dpi_x, dpi_y;
    int bg3;
};

#endif // FREETYPE_RENDERER_H

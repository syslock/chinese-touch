#include <iostream>

#include <nds.h>

#include "freetype_renderer.h"

#undef __FTERRORS_H__
#define FT_ERROR_START_LIST     ErrorMap ft_errors; void FT_Init_Errors(){
#define FT_ERRORDEF( e, v, s )  ft_errors[e]=s;
#define FT_ERROR_END_LIST       };

#include FT_ERRORS_H


FreetypeRenderer::FreetypeRenderer( const std::string& fontfile_name ) : dpi_x(100), 
    dpi_y(100)
{
    // FIXME: FreetypeRenderer sollte unabhängig vom Zielgerät funktionieren:
    // set the mode for 2 text layers and two extended background layers
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	this->bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);
	// lineare 15-bit-graupalette mit 256 indizes aufbauen:
	for( int i=0; i<256; i++ )
	{
	    int value = (int)( ((double)i)*(double)(1<<5)/256.0 );
	    BG_PALETTE[255-i] = /*(1 << 15) |*/ (value << 10) | (value << 5) | value;
	}

    FT_Init_Errors();
    std::cout << "ft_errors.size(): " << ft_errors.size() << std::endl;
    this->error = FT_Init_FreeType( &this->library );
    if( this->error )
    {
        std::cout << "error initializing freetype: " << ft_errors[this->error] 
                    << std::endl;
        return;
    }
    this->error = FT_New_Face( this->library, fontfile_name.c_str(), 0, &this->face );
    if( this->error )
    {
        std::cout << "error loading: " << fontfile_name << " (" 
                << ft_errors[this->error] << ")" << std::endl;
        return;
    }
#if 0
    // Select charmap
    this->error = FT_Select_Charmap( this->face, FT_ENCODING_UNICODE );
    if( this->error )
    {
        std::cout << "error loading unicode charmap: " << ft_errors[this->error]
                << std::endl;
        return;
    }
#endif   
}

FreetypeRenderer::~FreetypeRenderer()
{
    FT_Done_Face( this->face );
    FT_Done_FreeType( this->library );
}

void FreetypeRenderer::render_x_centered( const std::string& text, int pixel_size, int y )
{
    CharList char_list;
    if( !utf8_to_ucs4((unsigned char*)text.c_str(), char_list) )
    {
        std::cout << "error in utf-8 input (non fatal)" << std::endl;
    }
    int x = 128 - (char_list.size()/2) * pixel_size;
    this->render( char_list, pixel_size, x, y );
}

void FreetypeRenderer::render( const std::string& text, int pixel_size, int x, int y )
{
    CharList char_list;
    if( !utf8_to_ucs4((unsigned char*)text.c_str(), char_list) )
    {
        std::cout << "error in utf-8 input (non fatal)" << std::endl;
    }
    this->render( char_list, pixel_size, x, y );
}

void FreetypeRenderer::render( CharList& char_list, int pixel_size, int x, int y )
{
    FT_Error error;
    error = FT_Set_Char_Size( this->face, 0, pixel_size*64, this->dpi_x, this->dpi_y );
    if( error )
    {
        std::cout << "error setting pixel size: " << ft_errors[error] << std::endl;
        return;
    }
    FT_Vector pen;
    pen.x = x * 64;
    pen.y = -y * 64;
    int base_height = 0;
    for( CharList::iterator char_it=char_list.begin(); 
            char_it!=char_list.end() && pen.x/64<256; char_it++ )
    {
        // Load Char
        std::cout << "character code: " << *char_it << std::endl;
        //FT_UInt glyph_index = FT_Get_Name_Index(face, "a");
        FT_UInt glyph_index = FT_Get_Char_Index( this->face, *char_it );
        if( !glyph_index )
        {
            std::cout << "error translating character code: " << *char_it << std::endl;
            return;
        }
        FT_Set_Transform( this->face, 0, &pen );
        //std::cout << "glyph index: " << glyph_index << std::endl;
        error = FT_Load_Glyph(this->face, glyph_index, FT_LOAD_RENDER);
        if( error )
        {
            std::cout << "error loading glyph index: " << glyph_index << std::endl;
            std::cout << ft_errors[error] << std::endl;
            return;
        }
        char buffer[256];
        FT_Get_Glyph_Name( this->face, glyph_index, buffer, 256 );
        //std::cout << "glyph name: " << buffer << std::endl;
        
        FT_GlyphSlot& glyph = this->face->glyph;
        FT_Bitmap& bitmap = this->face->glyph->bitmap;
        if( !base_height ) base_height = bitmap.rows;
        //std::cout << "w/r: " << bitmap.width << "/" << bitmap.rows 
        //            << " t: " << glyph->bitmap_top << std::endl;
        if( !bitmap.buffer )
        {
            std::cout << "error: got no bitmap for current glyph" << std::endl;
            return;
        }
        for( int row=0; row<bitmap.rows; row++ )
        {
            // FIXME Korrektur an bitmap.width um -1, damit wir mit der
            // 16-Bit-Kopie nicht die Puffergrenze verletzen und falsche
            // Pixel kopieren. Allerdings kopieren wir so manchmal zu wenig.
            for( int pixel=0; pixel<bitmap.width-1; pixel+=2 )
            {
                u16 value = (bitmap.buffer[row*bitmap.pitch+pixel+1] << 8)
                            + bitmap.buffer[row*bitmap.pitch+pixel];
                u16* base_adress = bgGetGfxPtr(this->bg3) 
                        + (row+(base_height-glyph->bitmap_top))*256/2
                        + pixel/2 + glyph->bitmap_left/2;
                *base_adress = value;
            }
        }
        pen.x += glyph->advance.x;
    }
}


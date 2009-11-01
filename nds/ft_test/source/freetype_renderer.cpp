#include <iostream>

#include <nds.h>

#include "freetype_renderer.h"
#include "config.h"
#include "error_console.h"

#undef __FTERRORS_H__
#define FT_ERROR_START_LIST     ErrorMap ft_errors; void FT_Init_Errors(){
#define FT_ERRORDEF( e, v, s )  ft_errors[e]=s;
#define FT_ERROR_END_LIST       };

#include FT_ERRORS_H


FreetypeRenderer::FreetypeRenderer( const std::string& han_font, 
	const std::string& latin_font ) 
		: dpi_x(100), dpi_y(100)
{	
    FT_Init_Errors();
    LOG( "ft_errors.size(): " << ft_errors.size() );
    this->error = FT_Init_FreeType( &this->library );
    if( this->error )
    {
		std::stringstream msg;
		msg << "error initializing freetype: " << ft_errors[this->error];
        throw ERROR( msg.str() );
    }
    std::string _han_font = BASE_DIR + han_font;
    std::string _latin_font = BASE_DIR + latin_font;
    this->error = FT_New_Face( this->library, _han_font.c_str(), 0, &this->han_face );
    if( this->error )
    {
		std::stringstream msg;
        msg << "error loading chinese font: " << _han_font << " (" 
                << ft_errors[this->error] << ")";
		throw ERROR( msg.str() );
    }
    this->error = FT_New_Face( this->library, _latin_font.c_str(), 0, &this->latin_face );
    if( this->error )
    {
		std::stringstream msg;
        msg << "error loading latin font: " << _latin_font << " (" 
                << ft_errors[this->error] << ")";
        throw ERROR( msg.str() );
    }
#if 0
    // Select charmap
    this->error = FT_Select_Charmap( this->han_face, FT_ENCODING_UNICODE );
    if( this->error )
    {
		std::stringstream msg;
        msg << "error loading unicode charmap: " << ft_errors[this->error];
        throw ERROR( msg.str() );
    }
#endif   
}

FreetypeRenderer::~FreetypeRenderer()
{
    FT_Done_Face( this->han_face );
    FT_Done_Face( this->latin_face );
    FT_Done_FreeType( this->library );
}

void FreetypeRenderer::init_screen( Screen screen, RenderScreen& render_screen )
{
    // set the mode for 2 text layers and two extended background layers
	if( screen == SCREEN_MAIN )
	{
		videoSetMode(MODE_5_2D);
		vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
		render_screen.init( bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0) );
		render_screen.palette = BG_PALETTE;
	}
	else /*if( screen == SCREEN_SUB )*/
	{
		videoSetModeSub(MODE_5_2D);
		vramSetBankC(VRAM_C_SUB_BG_0x06200000);
		render_screen.init( bgInitSub(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0) );
		render_screen.palette = BG_PALETTE_SUB;
	}
	// lineare 15-bit-graupalette mit 256 indizes aufbauen:
	for( int i=0; i<256; i++ )
	{
	    int value = (int)( ((double)i)*(double)(1<<5)/256.0 );
	    render_screen.palette[255-i] = /*(1 << 15) |*/ (value << 10) | (value << 5) | value;
	}
}

void RenderScreen::clear( int color )
{
    // 1. clear background buffer with background color
    memset( this->base_address, color, this->res_x*this->res_y*1 );
}

void RenderScreenBuffer::render_to( RenderScreen& dest, int x, int y )
{
	// 16-bit-aligned to allow copying to vram:
	char* buffer = (char*)this->base_address;
	for( int row=0; row<this->res_y; row++ )
	{
		// FIXME: Optimierung durch zeilenweises dmaCopy?
		for( int pixel=0; pixel<this->res_x; pixel+=2 )
		{
			u16* base_address = dest.base_address
					+ (row+y)*dest.res_x/2
					+ pixel/2 + x/2;
			if( (base_address < dest.base_address)
				|| (base_address > (dest.base_address+dest.res_x*dest.res_y-2)) )
			{
				continue;
			}
			u16 value = 0;
			if( pixel < this->res_x-1 )
			{
				value = (buffer[row*this->res_x+pixel+1] << 8)
							+ buffer[row*this->res_x+pixel];
			}
			else
			{
				value = buffer[row*this->res_x+pixel];
			}
			*base_address |= value;
		}
	}
}


RenderCharList::~RenderCharList()
{
	for( RenderCharList::iterator rc_it = this->begin();
		rc_it != this->end(); rc_it++ )
	{
		if( *rc_it ) delete *rc_it;
	}
}


RenderRect FreetypeRenderer::render( const RenderScreen& render_screen, const std::string& text, FT_Face& face, 
            int pixel_size, int x, int y, RenderStyle* render_style, RenderCharList* render_char_list )
{
    // 1. unicode conversion
    UCCharList char_list;
    if( !utf8_to_ucs4((unsigned char*)text.c_str(), char_list) )
    {
        WARN( "error in utf-8 input (non fatal)" );
    }
	return this->render( render_screen, char_list, face, pixel_size, x, y, render_style, render_char_list );
}

RenderRect FreetypeRenderer::render( const RenderScreen& render_screen, UCCharList& input_char_list, FT_Face& face, 
            int pixel_size, int x, int y, RenderStyle* render_style, RenderCharList* render_char_list )
{
	// redirect uninitialized pointer to stack object with default configuration:
	RenderStyle default_render_style;
	if( !render_style ) render_style = &default_render_style;
	// redirect uninitialized pointer to stack object to ensure its destruction:
    RenderCharList stack_render_char_list;
	if( !render_char_list ) render_char_list = &stack_render_char_list;
    if( input_char_list.size()==0 ) return RenderRect(0,0,0,0);
    
    // 2. initialize Freetype
    FT_Error error;
    error = FT_Set_Char_Size( face, 0, pixel_size*64, this->dpi_x, this->dpi_y );
    if( error )
    {
        std::stringstream msg;
		msg << "error setting pixel size: " << ft_errors[error];
		throw ERROR( msg.str() );
    }
    
    // 3. compute preliminary character offsets and dimensions
    int line_height = pixel_size;
    FT_Vector pen;
    pen.x = x * 64;
    pen.y = -y * 64;
	UCCharList::iterator input_char_it=input_char_list.begin();
    for( ; input_char_it!=input_char_list.end(); input_char_it++ )
    {
		//std::cout << "#";
        // Load Char
        LOG( "character code: " << input_char_it->code_point );
        //FT_UInt glyph_index = FT_Get_Name_Index(face, "a");
        FT_UInt glyph_index = FT_Get_Char_Index( face, input_char_it->code_point );
        if( !glyph_index )
        {
			if( input_char_it->code_point==10 )
			{
				if( !render_style->linebreak )
				{
					// line finished
					// and stop rendering before line break:
					break;
				}
				else
				{
					// include line breaks
					RenderChar* render_char = new RenderChar( *input_char_it, glyph_index );
					render_char->x = pen.x/64;
					render_char->y = -pen.y/64;
					render_char_list->push_back( render_char );
					continue;
				}
			}
			else if( input_char_it->code_point==9 )
			{
				// include tabs
				RenderChar* render_char = new RenderChar( *input_char_it, glyph_index );
				render_char->x = pen.x/64;
				render_char->y = -pen.y/64;
				render_char_list->push_back( render_char );
				continue;
			}
			WARN(  "error translating character code: " << input_char_it->code_point );
			continue;
        }
        FT_Set_Transform( face, 0, &pen );
        LOG( "glyph index: " << glyph_index );
        error = FT_Load_Glyph( face, glyph_index, FT_LOAD_RENDER );
        if( error )
        {
			WARN( "error loading glyph index: " << glyph_index << "(" << ft_errors[error] << ")" );
			continue;
        }
        char buffer[1000]; buffer[0]=0;
        FT_Get_Glyph_Name( face, glyph_index, buffer, 1000 );
        LOG( "glyph name: " << buffer );
        
        RenderChar* render_char = new RenderChar( *input_char_it, glyph_index );
        render_char->x = pen.x/64;
        render_char->y = -pen.y/64;
		FT_GlyphSlot& glyph = face->glyph;
		FT_Bitmap& bitmap = face->glyph->bitmap;
		LOG( "w/r: " << bitmap.width << "/" << bitmap.rows << " t: " << glyph->bitmap_top );
		render_char->width = glyph->advance.x/64;
		render_char->height = bitmap.rows;
		if( !bitmap.buffer )
		{
			LOG( "got no bitmap for current glyph" );
		}
		if( bitmap.rows > line_height ) line_height = bitmap.rows;
		if( !render_style->linebreak 
			&& render_char->x+render_char->width > render_screen.res_x )
		{
			// clean up clipped character...
			delete render_char;
			// and stop rendering before line break:
			break;
		}
		pen.x += glyph->advance.x;
        render_char_list->push_back( render_char );
    }
	// erase all successfully processed input characters from input char list:
	input_char_list.erase( input_char_list.begin(), input_char_it );
	while( input_char_list.begin()!=input_char_list.end() 
		&& input_char_list.begin()->code_point==10 )
	{
		input_char_list.erase( input_char_list.begin() );
	}
	
    
    // 4. insert line breaks
    RenderCharList::iterator prev_whitespace_it = render_char_list->end();
    RenderCharList::iterator last_line_it = render_char_list->begin();
    int x_correction = 0;
    int y_correction = 0;
    int x_limit = render_screen.res_x;
    int line_count = 1;
    if( render_style->center_x )
    {
        x_limit -= x;
    }
	if( render_style->linebreak )
	{
		for( RenderCharList::iterator rchar_it=render_char_list->begin(); 
				rchar_it!=render_char_list->end(); rchar_it++ )
		{
			LOG( "c=" << (*rchar_it)->uc_char.code_point << " x=" << (*rchar_it)->x 
				<< " y=" << (*rchar_it)->y << " xc=" << x_correction 
				<< " yc=" << y_correction );
			(*rchar_it)->x += x_correction;
			(*rchar_it)->y += y_correction;
			if( (*rchar_it)->uc_char.code_point == 32
				|| (*rchar_it)->uc_char.code_point == 9 )
			{
				prev_whitespace_it = rchar_it;
			}
			if( (*rchar_it)->uc_char.code_point == 9 )
			{
				// insert dynamically sized tab space, based on pixel size and position:
				int tab_width = pixel_size * 8;
				x_correction += tab_width - ((*rchar_it)->x % tab_width);
			}
			if( (*rchar_it)->x+(*rchar_it)->width > render_screen.res_x 
				|| ( (*rchar_it)->uc_char.code_point == 10 
					&& (*rchar_it)->x > x /*prevent endless loop*/ ) )
			{
				if( (*rchar_it)->uc_char.code_point == 10 )
				{
					// prevent successive line breaks at this position:
					prev_whitespace_it = render_char_list->end();
				}
				// go back to previous white space if possible and adjust 
				// correction values for next line
				if( prev_whitespace_it != render_char_list->end() )
				{
					// re-correct already corrected chars in line since prev whitespace:
					RenderCharList::iterator reloc_char_it=prev_whitespace_it;
					reloc_char_it++;
					RenderCharList::iterator reloc_end_char_it=rchar_it;
					reloc_end_char_it++;
					for( ; reloc_char_it!=reloc_end_char_it; reloc_char_it++ )
					{
						(*reloc_char_it)->x -= x_correction;
						(*reloc_char_it)->y -= y_correction;
					}
					rchar_it = ++prev_whitespace_it;
					// prevent successive line breaks at this position:
					prev_whitespace_it = render_char_list->end();
				}
				else
				{
					(*rchar_it)->x -= x_correction;
					(*rchar_it)->y -= y_correction;
				}
				y_correction += line_height+1;
				x_correction = x-(*rchar_it)->x;
				RenderCharList::iterator prev_last_line_it = last_line_it;
				last_line_it = rchar_it;
				line_count++;
				rchar_it--;
				(*prev_last_line_it)->curr_line_end_char = *rchar_it;
			}
		}
	}
    (*last_line_it)->curr_line_end_char = *render_char_list->rbegin();

    if( render_style->center_x )
    {
        // 5. x-center every line
        x_correction = 0;
        for( RenderCharList::iterator rchar_it=render_char_list->begin();
                rchar_it!=render_char_list->end(); rchar_it++ )
        {
            if( (*rchar_it)->curr_line_end_char )
            {
                x_correction = ( render_screen.res_x - x 
                        - (*rchar_it)->curr_line_end_char->x
                        - (*rchar_it)->curr_line_end_char->width ) / 2;
            }
            (*rchar_it)->x += x_correction;
        }
    }
    if( render_style->center_y )
    {
        // 6. y-center all lines
        // TODO
    }

    // 7. render characters at final locations
    int max_x = 0;
    int max_y = 0;
    for( RenderCharList::iterator rchar_it=render_char_list->begin(); 
            rchar_it!=render_char_list->end(); rchar_it++ )
    {
		if( !(*rchar_it)->glyph_index )
			continue;
        int cur_rx = (*rchar_it)->x+(*rchar_it)->width-1;
        if( cur_rx > max_x ) max_x = cur_rx;
        int cur_by = (*rchar_it)->y+(*rchar_it)->height-1;
        if( cur_by > max_y ) max_y = cur_by;
        pen.x = (*rchar_it)->x*64;
        pen.y = (*rchar_it)->y*-64;
        FT_Set_Transform( face, 0, &pen );
        error = FT_Load_Glyph( face, (*rchar_it)->glyph_index, FT_LOAD_RENDER );
        if( error )
        {
            std::stringstream msg;
			msg << "error loading glyph index: " << (*rchar_it)->glyph_index 
				<< "(" << ft_errors[error];
			throw ERROR( msg.str() );
        }
        FT_GlyphSlot& glyph = face->glyph;
        FT_Bitmap& bitmap = face->glyph->bitmap;
		if( !render_screen.res_x || ! render_screen.res_y || !render_screen.base_address )
		{
			throw ERROR( "FreeTypeRenderer::render(): target buffer not initialized or of zero size" );
		}
        for( int row=0; bitmap.buffer && row<bitmap.rows; row++ )
        {
			int dest_y = row+(line_height-glyph->bitmap_top);
			if( dest_y < 0 || dest_y >= render_screen.res_y )
				continue;
            for( int pixel=0; pixel<bitmap.width; pixel+=2 )
            {
				int dest_x = pixel + glyph->bitmap_left;
				if( dest_x < 0 || dest_x > (render_screen.res_x-2) )
					continue;
                u16 value = 0;
                if( pixel < bitmap.width-1 )
                {
                    value = (bitmap.buffer[row*bitmap.pitch+pixel+1] << 8)
                                + bitmap.buffer[row*bitmap.pitch+pixel];
                }
                else
                {
                    value = bitmap.buffer[row*bitmap.pitch+pixel];
                }
                u16* bg_gfx_ptr = render_screen.base_address;
                u16* base_address = bg_gfx_ptr
                        + (row+(line_height-glyph->bitmap_top))*render_screen.res_x/2
                        + pixel/2 + glyph->bitmap_left/2;
                *base_address |= value;
            }
        }
    }
    int height = max_y-y;
    if( line_height > height ) height = line_height;
    return RenderRect( x, y, max_x-x, height );
}


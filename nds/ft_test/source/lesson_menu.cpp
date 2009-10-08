#include "lesson_menu.h"
#include "screen.h"

LessonMenu::LessonMenu (const std::string & han_font,
			const std::string & latin_font)
	: info_screen( han_font, latin_font, SCREEN_MAIN ),
		menu_screen( han_font, latin_font, SCREEN_SUB )
{
	RenderStyle render_style;
	render_style.center_x = true;
	render_style.center_y = true;
	info_screen.render( "你好Main！", info_screen.han_face, 32, 0, 0, &render_style );
	menu_screen.render( "你好Sub！", menu_screen.han_face, 32, 0, 0, &render_style );
	menu_screen.render( "(press & release to continue!)", menu_screen.latin_face, 10, 0, 50, &render_style );
}

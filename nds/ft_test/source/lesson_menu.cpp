#include "lesson_menu.h"
#include "screen.h"

LessonMenu::LessonMenu( FreetypeRenderer& ft )
{
	ft.init_screen( SCREEN_MAIN, this->info_screen );
	ft.clear_screen( this->info_screen );
	ft.init_screen( SCREEN_SUB, this->menu_screen );
	ft.clear_screen( this->menu_screen );
	RenderStyle render_style;
	render_style.center_x = true;
	render_style.center_y = true;
	ft.render( this->info_screen, "你好Main！", ft.han_face, 32, 0, 0, &render_style );
	ft.render( this->menu_screen, "你好Sub！", ft.han_face, 32, 0, 0, &render_style );
	ft.render( this->menu_screen, "(press & release to continue!)", ft.latin_face, 10, 0, 50, &render_style );
}

#ifndef LESSON_MENU_H
#define LESSON_MENU_H

#include "freetype_renderer.h"

class LessonMenu
{
public:
	FreetypeRenderer info_screen, menu_screen;
public:
	LessonMenu( const std::string& han_font, const std::string& latin_font );
};


#endif //LESSON_MENU_H
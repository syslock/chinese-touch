#ifndef LESSON_MENU_H
#define LESSON_MENU_H

#include "freetype_renderer.h"

class LessonMenu
{
public:
	RenderScreen info_screen, menu_screen;
public:
	LessonMenu( FreetypeRenderer& ft );
};


#endif //LESSON_MENU_H
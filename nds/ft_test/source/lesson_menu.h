#ifndef LESSON_MENU_H
#define LESSON_MENU_H

#include "freetype_renderer.h"
#include "lesson.h"

class LessonMenu
{
public:
	FreetypeRenderer& ft;
	Library& library;
	RenderScreen info_screen, menu_screen;
	u16* book_sprite_vram;
	u16* lesson_sprite_vram;
public:
	LessonMenu( FreetypeRenderer& _ft, Library& _library );
	~LessonMenu();
	void render();
};


#endif //LESSON_MENU_H
#ifndef LESSON_MENU_H
#define LESSON_MENU_H

#include "freetype_renderer.h"
#include "lesson.h"

class LessonMenuChoice
{
	public:
		std::string book_name;
		int lesson_num;
		enum ContentType
		{
			CONTENT_TYPE_NEW_WORDS,
			CONTENT_TYPE_GRAMMAR,
			CONTENT_TYPE_TEXT,
			CONTENT_TYPE_EXERCISES
		} content_type;
};

class LessonMenu
{
public:
	FreetypeRenderer& freetype_renderer;
	Library& library;
	RenderScreen info_screen, menu_screen;
	u16* book_sprite_vram;
	u16* lesson_sprite_vram;
	int y_offset;
public:
	LessonMenu( FreetypeRenderer& _freetype_renderer, Library& _library );
	~LessonMenu();
	void render( Screen screen );
	void run_for_user_choice( LessonMenuChoice& choice );
};


#endif //LESSON_MENU_H
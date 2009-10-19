#ifndef LESSON_MENU_H
#define LESSON_MENU_H

#include <map>

#include "freetype_renderer.h"
#include "lesson.h"
#include "config.h"

class LessonMenuChoice
{
	public:
		Book* book;
		Lesson* lesson;
		enum ContentType
		{
			CONTENT_TYPE_NONE,
			CONTENT_TYPE_NEW_WORDS,
			CONTENT_TYPE_GRAMMAR,
			CONTENT_TYPE_TEXT,
			CONTENT_TYPE_EXERCISES
		} content_type;
	public:
		LessonMenuChoice() : book(0), lesson(0), 
			content_type(CONTENT_TYPE_NONE) {}
};

class MenuEntry
{
	public:
		RenderScreenBuffer* text_surface;
		Book* book;
		Lesson* lesson;
		bool exploded;
		int top;
		int last_frame_rendered;
		static int BASE_HEIGHT;
		static int ACTIVE_HEIGHT;
		static int FONT_SIZE;
		static int TEXT_X_OFFSET;
	public:
		MenuEntry() : text_surface( new RenderScreenBuffer(200, MenuEntry::BASE_HEIGHT) ),
						book(0), lesson(0), exploded(false), top(0), last_frame_rendered(0) {}
		~MenuEntry()
		{
			delete this->text_surface;
		}
		void render_text( FreetypeRenderer& ft, const std::string& text );
};
class MenuList : public std::map<void*,MenuEntry*>
{
	public:
		~MenuList();
};

class LessonMenu
{
public:
	FreetypeRenderer& freetype_renderer;
	Library& library;
	Config& config;
	RenderScreen info_screen, menu_screen;
	MenuList menu_list;
	u16* book_sprite_vram;
	u16* lesson_sprite_vram;
	int y_offset;
	int v_y;
	void* active_list_id;
	int frame_count;
public:
	LessonMenu( FreetypeRenderer& _freetype_renderer, Library& _library, Config& _config );
	~LessonMenu();
	void render( Screen screen );
	void run_for_user_choice( LessonMenuChoice& choice );
	MenuList::iterator get_entry_by_pos( int x, int y );
};


#endif //LESSON_MENU_H
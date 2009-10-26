#ifndef NEW_WORDS_H
#define NEW_WORDS_H

#include "freetype_renderer.h"
#include "lesson_menu.h"
#include "drawing_pad.h"
#include "config.h"

class NewWordsViewer
{
	public:
		FreetypeRenderer& freetype_renderer;
		DrawingPad drawing_pad;
		RenderScreen word_view;
		Lesson& lesson;
		unsigned int word_index;
		Config& config;
	public:
		NewWordsViewer( FreetypeRenderer& _freetype_renderer, Lesson& _lesson, Config& _config );
		void render();
		void run_until_exit();
};

#endif // NEW_WORDS_H
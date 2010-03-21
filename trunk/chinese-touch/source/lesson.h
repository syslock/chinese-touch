#ifndef LESSON_H
#define LESSON_H

#include <list>
#include <vector>
#include <map>
#include <string>

#include "freetype_renderer.h"


/*! Stores which parts of dictionary entries shall be displayed on top screen. */
class NewWordRenderSettings
{
	public:
		bool render_foreign_word, render_pronuciation, render_translation;
		bool init_render_foreign_word, init_render_pronuciation, init_render_translation;
		bool restore_on_switch, clear_on_switch;
	public:
		NewWordRenderSettings() 
			: render_foreign_word(true), render_pronuciation(true), render_translation(true),
				init_render_foreign_word(true), init_render_pronuciation(true), init_render_translation(true),
				restore_on_switch(true), clear_on_switch(true) {}
		void toggle_foreign_word() { this->render_foreign_word = !this->render_foreign_word; }
		void toggle_pronunciation() { this->render_pronuciation = !this->render_pronuciation; }
		void toggle_translation() { this->render_translation = !this->render_translation; }
		void restore_init_settings()
		{
			this->render_foreign_word = this->init_render_foreign_word;
			this->render_pronuciation = this->init_render_pronuciation;
			this->render_translation = this->init_render_translation;
		}
		void restore_init_settings_if_needed() { if(this->restore_on_switch) this->restore_init_settings(); }
};


class Lesson;

/*! Basically a string with an additional title field and knowledge about the lesson it belongs to. */
class Text : public std::string
{
public:
	std::string title;
	Lesson* lesson;
public:
	Text( const std::string& _title, Lesson* _lesson ) : title(_title), lesson(_lesson) {}
};
//! An array of texts. \see Text
typedef std::vector<Text*> TextVector;


/*! A definition for a foreign language word for a specific native language. */
class Definition
{
public:
    std::string lang, //!< The native language this definition is written in.
		translation, //!< The translation of the foreign word into this native language.
		word_type, //!< A usally abreviated, short text giving the words type.
		comment, //!< An additional comment for this entry in native language.
		example; //!< One or few example sentences in the foreign language.
};
/*! A mapping of ISO language keys to Definition pointers. \see Definition */
typedef std::map<std::string,Definition*> Definitions;


/*! Difficulty rating levels. */
typedef enum
{
	RATING_NONE = 0, //!< no rating given by the user until now.
	RATING_IMPOSSIBLE, //!< very hard to read and/or write.
	RATING_HARD, //!< hard to read and/or write.
	RATING_MEDIUM, //!< medium to read and/or write.
	RATING_EASY, //!< easy to read and/or write.
	RATING_ANY, //!< any rating, including none
} Rating;


/*! A foreign language word and several associated properties like translations and so on. */
class NewWord
{
public:
    NewWord( const std::string& _hanzi, const std::string& _pinyin, 
            Lesson* _lesson ) 
        : hanzi(_hanzi), pinyin(_pinyin), lesson(_lesson),
        rating(RATING_NONE), id(0), duplicate_id(0), atime(0), file_id(0), file_offset(0) {};
    void render( FreetypeRenderer& ft, RenderScreen& render_screen, NewWordRenderSettings& render_settings );
public:
    std::string hanzi, //!< Foreign language word.
				pinyin; //!< Foreign language pronunciation.
	/*! Collection of definitions/translations in various native languages, 
		being meant for different native language learners. \see Definition */
    Definitions definitions; 
    Lesson* lesson; //!< Pointer to the lesson this word belongs to.
	Rating rating; //!< User defined difficulty rating.
	int id, //!< This words unique id within the sqlite database (0 if unassociated).
	 /*! This words per-lesson duplication count (0 for first occurrence within one 
		lesson, 1 for second and so on). */
		duplicate_id;
	time_t atime; //!< Last time this words dictionary entry was shown to the user.
	int file_id; //!< Database identifier of the dictionary file this word was read from
	int file_offset; //!< Number of the word entry within the dictionary file it was read from
};
/*! A container for pointers to NewWord instances. \see NewWord */
class NewWordList : public std::list<NewWord*>
{
public:
	virtual ~NewWordList();
	virtual void clear();
};


class Book;

/*! A limited subset of texts and dictionary entries within a book. */
class Lesson
{
public:
    Lesson( int _number, Book* _book ) : number(_number), book(_book) {};
	std::string find_config_file_by_extension( const std::string& extension );
    void parse_config( const std::string& lesson_file_name );
    void parse_dictionary_if_needed();
	void parse_text( const std::string& extension, TextVector& container );
public:
	TextVector lesson_texts; //!< An array of lesson texts. \see Text
	TextVector grammar_texts; //!< An array of the lessons grammar texts. \see Text
	TextVector exercises; //!< An array of the lessons exercises texts. \see Text
    std::string title,	//!< The lessons title.
				description; //!< The lessons short description.
    int number; //!< The number of this lesson within a book.
    Book* book; //!< A pointer to the book this lesson belongs to.
	int id; //!< This lessons unique id within the sqlite database (0 if unassociated).
	bool new_words_available, //!< True if this lesson has a dictionary file (and thus possibly words in the database)
		lesson_texts_available, //!< True if this lesson has a .text-file
		grammar_texts_available, //!< True if this lesson has a .grammar-file
		exercises_available; //!< True if this lesson has a .exercises-file
};


class Library;

/*! A Book is a collection of numbered lessons. \see Lesson */
class Book : public std::map<int,Lesson*>
{
public:
    Book( const std::string& _name, Library* _library ) : name(_name),
        library(_library) {}
    void parse_config( const std::string& book_conf_file_name );
	std::string get_full_path();
public:
    std::string name, //!< The name of the book is equal to its subdirectory name below /chinese-touch/books/.
		title, //!< The books title.
		description, //!< The books short description.
		author, //!< The books authors name.
		publisher, //!< The name of the books publisher.
		isbn; //!< The books ISBN code.
    int year; //!< The publication year of the book.
    Library* library; //!< A pointer to the library this book belongs to.
	int id; //!< This books unique id within the sqlite database (0 if unassociated).
};


//! A Library is a collection of books. \see Book
class Library : public std::map<std::string,Book*>
{
public:
    Library( bool _fat_initialized ) 
		: fat_initialized(_fat_initialized) {}
    void rescan();
	void find_words_by_characters( const std::string& characters, NewWordList& result, const std::string& extra_sql_cond="" );
	void find_words_by_context( const std::string& text, const UCCharList& search_list, 
		UCCharList::const_iterator pos, int max_range, NewWordList& result, const std::string& extra_sql_cond="" );
protected:
    bool fat_initialized;
};

#endif // LESSON_H

#include <time.h>
#include <iostream>

#include "config.h"

bool global_fat_initialized = false;

Config::Config()
 : previous_word(0), changed(false)
{
    this->prev_time = time(0);
}

void Config::save_position( Word* word )
{
    if( !word || (previous_word == word) )
    {
        return;
    }
    this->changed = true;
    this->data.config.current_word_number = word->number;
    this->data.config.current_lesson_number = word->lesson->number;
    const std::string& book_name = word->lesson->book->name;
    memcpy( this->data.config.current_book_name, 
        book_name.c_str(),
        book_name.length() < CONFIG_STRING_SIZE ? book_name.length() 
                                                : CONFIG_STRING_SIZE );
    this->data.config.current_book_name[CONFIG_STRING_SIZE-1] = 0;
    this->save();
}

void Config::save()
{
    time_t curr_time = time(0);
    if( curr_time > (this->prev_time + Config::AUTO_SAVE_PERIOD)
        && this->changed )
    {
        this->save_really();
        this->prev_time = curr_time;
     }
}

void Config::save_really()
{
    if( !global_fat_initialized ) 
        return;
    FILE* f = fopen( CONFIG_FILE_NAME, "w" );
    if( f )
    {
        std::cout << "writing: " << CONFIG_FILE_NAME << std::endl;
        fwrite( &this->data, sizeof(this->data), 1, f );
        fflush( f );
        fclose( f );
        this->changed = false;
    }
    else std::cout << "error opening: " << CONFIG_FILE_NAME << std::endl;
}

void Config::load()
{
    if( !global_fat_initialized ) return;
    FILE* f = fopen( CONFIG_FILE_NAME, "r" );
    if( f )
    {
        std::cout << "reading: " << CONFIG_FILE_NAME << std::endl;
        fread( &this->data, sizeof(this->data), 1, f );
        fclose( f );
    }
    else std::cout << "error opening: " << CONFIG_FILE_NAME << std::endl;
}


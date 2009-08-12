#include <nds.h>

#include "lesson.h"

void Word::render( FreetypeRenderer& ft )
{
    // 1. clear background buffer with background color
    u16* base_address = bgGetGfxPtr(ft.bg3);
    memset( base_address, 0, 256*265 );
    
    // 2. render hanzi in the faces suggested layout (e.g. fixed width)
    RenderStyle render_style;
    render_style.center_x = true;
    ft.render( this->hanzi, ft.han_face, 40, 0, 10, &render_style );
    
    // 3. render pinyin in variable width
    ft.render( this->pinyin, ft.han_face, 20, 0, 65, &render_style );
    
    // 4. render translation in variable width
    ft.render( this->translations["de"], ft.latin_face, 10, 10, 100, &render_style );
}

Lesson all_words_lesson("Alle Wörter");
void init_all_words_lesson()
{
    Word* word;
    word = new Word( "你好", "nǐhǎo" );
    word->translations["de"] = "Hallo, Guten Tag (Begrüßung)";
    all_words_lesson.push_back( word );
/*    word = new Word( "汉语", "hànyǔ" );
    word->translations["de"] = "Chinesisch, chinesische Sprache";
    all_words_lesson.push_back( word );
    word = new Word( "书法", "shūfǎ" );
    word->translations["de"] = "Kalligraphie";
    all_words_lesson.push_back( word );
    word = new Word( "图书馆", "túshūguǎn" );
    word->translations["de"] = "Bibliothek";
    all_words_lesson.push_back( word );
    word = new Word( "汉德词典", "hàndécídiǎn" );
    word->translations["de"] = "chinesisch-deutsches Wörterbuch";
    all_words_lesson.push_back( word );
    word = new Word( "医生", "yīshēng" );
    word->translations["de"] = "Arzt";
    all_words_lesson.push_back( word );*/
    word = new Word( "一", "yī" );
    word->translations["de"] = "eins";
    all_words_lesson.push_back( word );
/*    word = new Word( "二", "èr" );
    word->translations["de"] = "zwei";
    all_words_lesson.push_back( word );
    word = new Word( "三", "sān" );
    word->translations["de"] = "drei";
    all_words_lesson.push_back( word );
    word = new Word( "四", "sì" );
    word->translations["de"] = "vier";
    all_words_lesson.push_back( word );
    word = new Word( "五", "wǔ" );
    word->translations["de"] = "fünf";
    all_words_lesson.push_back( word );
    word = new Word( "六", "liù" );
    word->translations["de"] = "sechs";
    all_words_lesson.push_back( word );
    word = new Word( "七", "qī" );
    word->translations["de"] = "sieben";
    all_words_lesson.push_back( word );
    word = new Word( "八", "bā" );
    word->translations["de"] = "acht";
    all_words_lesson.push_back( word );
    word = new Word( "九", "jiǔ" );
    word->translations["de"] = "neun";
    all_words_lesson.push_back( word );
    word = new Word( "十", "shí" );
    word->translations["de"] = "zehn";
    all_words_lesson.push_back( word );*/
    word = new Word( "您好中文老师！", "nínhǎo zhōngwénlǎoshī" );
    word->translations["de"] = "Guten Tag Herr/Frau Chinesischlehrer(in) (höfliche Anrede)";
    all_words_lesson.push_back( word );
/*    word = new Word( "x", "x" );
    word->translations["de"] = "testestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestest";
    all_words_lesson.push_back( word );*/
}

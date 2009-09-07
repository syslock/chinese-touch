
#include <iostream>
#include "lesson.h"

Lesson all_words_lesson("Alle Wörter");
void init_all_words_lesson()
{
    int count = 0;
    Word* word;

    word = new Word( "汉语拼音", "Hànyǔ Pīnyīn", &all_words_lesson );
    word->translations["de"] = "die chinesisch-lateinische Pinyin-Umschrift ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "这", "zhè", &all_words_lesson );
    word->translations["de"] = "das, dies (hier) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "是", "shì", &all_words_lesson );
    word->translations["de"] = "sein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "爸爸", "bàba", &all_words_lesson );
    word->translations["de"] = "Papa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "那", "nà", &all_words_lesson );
    word->translations["de"] = "das, jenes (dort) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "妈妈", "māma", &all_words_lesson );
    word->translations["de"] = "Mama ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "姐姐", "jiějie", &all_words_lesson );
    word->translations["de"] = "ältere Schwester ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "和", "hé", &all_words_lesson );
    word->translations["de"] = "und (Objektkonkatenation) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "妹妹", "mèimei", &all_words_lesson );
    word->translations["de"] = "jüngere Schwester ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哥哥", "gēge", &all_words_lesson );
    word->translations["de"] = "älterer Bruder ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "弟弟", "dìdi", &all_words_lesson );
    word->translations["de"] = "jüngerer Bruder ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "爷爷", "yéye", &all_words_lesson );
    word->translations["de"] = "Opa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "奶奶", "nǎinai", &all_words_lesson );
    word->translations["de"] = "Oma ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "猫", "māo", &all_words_lesson );
    word->translations["de"] = "Katze ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "狗", "gǒu", &all_words_lesson );
    word->translations["de"] = "Hund ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "书", "shū", &all_words_lesson );
    word->translations["de"] = "Buch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "沙发", "shāfā", &all_words_lesson );
    word->translations["de"] = "Sofa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "收音机", "shōuyīnjī", &all_words_lesson );
    word->translations["de"] = "Radio ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "电话", "diànhuà", &all_words_lesson );
    word->translations["de"] = "Telefon ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "电视", "diànshì", &all_words_lesson );
    word->translations["de"] = "Fernseher ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "笔", "bǐ", &all_words_lesson );
    word->translations["de"] = "Pinsel ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谁", "shéi", &all_words_lesson );
    word->translations["de"] = "wer ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "王", "Wáng", &all_words_lesson );
    word->translations["de"] = "Familienname (König) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "先生", "xiānsheng", &all_words_lesson );
    word->translations["de"] = "Herr (Anrede) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "马", "Mǎ", &all_words_lesson );
    word->translations["de"] = "Familienname (Pferd) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "小姐", "xiǎojie", &all_words_lesson );
    word->translations["de"] = "Fräulein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "毛", "Máo", &all_words_lesson );
    word->translations["de"] = "Familienname (Haar, Borste) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "太太", "tàitai", &all_words_lesson );
    word->translations["de"] = "verheiratete Frau (Anrede) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "什么", "shénme", &all_words_lesson );
    word->translations["de"] = "was ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "图书馆", "túshūguǎn", &all_words_lesson );
    word->translations["de"] = "Bibliothek ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "教室", "jiàoshì", &all_words_lesson );
    word->translations["de"] = "Unterrichtsraum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "李", "Lǐ", &all_words_lesson );
    word->translations["de"] = "Familienname ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "老师", "lǎoshī", &all_words_lesson );
    word->translations["de"] = "Lehrer ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学生", "xuésheng", &all_words_lesson );
    word->translations["de"] = "Schüler, Student ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "的", "de", &all_words_lesson );
    word->translations["de"] = "(Attributpartikel), (nachstehend; nach dem Besitzer) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "历史", "lìshǐ", &all_words_lesson );
    word->translations["de"] = "Geschichte (Fach) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "地理", "dìlǐ", &all_words_lesson );
    word->translations["de"] = "Geographie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "英文", "yīngwén", &all_words_lesson );
    word->translations["de"] = "Englisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "词典", "cídiǎn", &all_words_lesson );
    word->translations["de"] = "Wörterbuch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "德文", "déwén", &all_words_lesson );
    word->translations["de"] = "Deutsch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日文", "rìwén", &all_words_lesson );
    word->translations["de"] = "Japanisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "系", "xì", &all_words_lesson );
    word->translations["de"] = "Seminar; Abteilung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中文", "zhōngwén", &all_words_lesson );
    word->translations["de"] = "Chinesisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "秘书", "mìshū", &all_words_lesson );
    word->translations["de"] = "Sektretär(in) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哦", "ó", &all_words_lesson );
    word->translations["de"] = "oh (Ausruf des Erstaunens) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "我", "wǒ", &all_words_lesson );
    word->translations["de"] = "ich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "你", "nǐ", &all_words_lesson );
    word->translations["de"] = "du, Sie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "您", "nín", &all_words_lesson );
    word->translations["de"] = "Sie (sehr höflich) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "他", "tā", &all_words_lesson );
    word->translations["de"] = "er ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "她", "tā", &all_words_lesson );
    word->translations["de"] = "sie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "它", "tā", &all_words_lesson );
    word->translations["de"] = "es ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "我们", "wǒmen", &all_words_lesson );
    word->translations["de"] = "wir ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "你们", "nǐmen", &all_words_lesson );
    word->translations["de"] = "ihr ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "他们", "tāmen", &all_words_lesson );
    word->translations["de"] = "sie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "她们", "tāmen", &all_words_lesson );
    word->translations["de"] = "sie (nur weibliche) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "它们", "tāmen", &all_words_lesson );
    word->translations["de"] = "sie (Dinge, Tiere) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "咱们", "zánmen", &all_words_lesson );
    word->translations["de"] = "wir ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "不", "bù", &all_words_lesson );
    word->translations["de"] = "nein, nicht ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "也", "yě", &all_words_lesson );
    word->translations["de"] = "auch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "都", "dōu", &all_words_lesson );
    word->translations["de"] = "beide,alle ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "好", "hǎo", &all_words_lesson );
    word->translations["de"] = "gut, geht gehen, (Begrüßung) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "天气", "tiānqì", &all_words_lesson );
    word->translations["de"] = "Wetter ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "很", "hěn", &all_words_lesson );
    word->translations["de"] = "sehr ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "真", "zhēn", &all_words_lesson );
    word->translations["de"] = "wahr, echt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "冷", "lěng", &all_words_lesson );
    word->translations["de"] = "kalt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "热", "rè", &all_words_lesson );
    word->translations["de"] = "warm ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "忙", "máng", &all_words_lesson );
    word->translations["de"] = "beschäftigt sein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吗", "ma", &all_words_lesson );
    word->translations["de"] = "(Fragepartikel) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "早", "zǎo", &all_words_lesson );
    word->translations["de"] = "früh, Guten Morgen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "可爱", "kě'ài", &all_words_lesson );
    word->translations["de"] = "liebenswert, niedlich, nett ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "同学", "tóngxué", &all_words_lesson );
    word->translations["de"] = "Kommilitone/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "们", "men", &all_words_lesson );
    word->translations["de"] = "(Pluralsuffix) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "努力", "nǔlì", &all_words_lesson );
    word->translations["de"] = "sich sehr anstrengen/ bemühen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "高", "gāo", &all_words_lesson );
    word->translations["de"] = "hoch, groß ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "矮", "ǎi", &all_words_lesson );
    word->translations["de"] = "niedrig, klein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "朋友", "péngyou", &all_words_lesson );
    word->translations["de"] = "Freund(in), Bekannte(r) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "休息", "xiūxi", &all_words_lesson );
    word->translations["de"] = "sich ausruhen, Pause machen, freihaben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "做", "zuò", &all_words_lesson );
    word->translations["de"] = "etw. machen, tun ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "练习", "liànxí", &all_words_lesson );
    word->translations["de"] = "Übung, Übungsaufgabe, etw. üben, einüben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学", "xué", &all_words_lesson );
    word->translations["de"] = "etw. lernen, studieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "生词", "shēngcí", &all_words_lesson );
    word->translations["de"] = "neue Vokabel ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "走", "zǒu", &all_words_lesson );
    word->translations["de"] = "gehen, weg-, fort-, losgehen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "再见", "zàijiàn", &all_words_lesson );
    word->translations["de"] = "Auf Wiedersehen! ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "工作", "gōngzuò", &all_words_lesson );
    word->translations["de"] = "Arbeit ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "教", "jiāo", &all_words_lesson );
    word->translations["de"] = "etw. unterrichten, lehren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "医生", "yīshēng", &all_words_lesson );
    word->translations["de"] = "Arzt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学习", "xuéxí", &all_words_lesson );
    word->translations["de"] = "lernen, studieren, etw. lernen, etw. studieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "俄文", "éwén", &all_words_lesson );
    word->translations["de"] = "Russisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "难", "nán", &all_words_lesson );
    word->translations["de"] = "schwierig, schwer (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "容易", "róngyì", &all_words_lesson );
    word->translations["de"] = "mühelos, leicht (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谈", "tán", &all_words_lesson );
    word->translations["de"] = "über etw. sprechen, etw. besprechen, sich über etw. unterhalten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "话", "huà", &all_words_lesson );
    word->translations["de"] = "Wort, Rede, Sprache ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谈话", "tán huà", &all_words_lesson );
    word->translations["de"] = "sich unterhalten, etw. besprechen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "看", "kàn", &all_words_lesson );
    word->translations["de"] = "sich etw. ansehen (Film etc.); etw. lesen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "看", "kān", &all_words_lesson );
    word->translations["de"] = "auf jemanden/etw. aufpassen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "报纸", "bàozhǐ", &all_words_lesson );
    word->translations["de"] = "Zeitung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "会", "huì", &all_words_lesson );
    word->translations["de"] = "etw. können, beherrschen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "妻子", "qīzi", &all_words_lesson );
    word->translations["de"] = "Ehefrau ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日本", "Rìběn", &all_words_lesson );
    word->translations["de"] = "Japan ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "人", "rén", &all_words_lesson );
    word->translations["de"] = "Mensch, Person ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日本人", "rìběnrén", &all_words_lesson );
    word->translations["de"] = "Japaner ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "孩子", "háizi", &all_words_lesson );
    word->translations["de"] = "Kind ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "饭", "fàn", &all_words_lesson );
    word->translations["de"] = "gekochter Reis; Essen, Mahl ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "做饭", "zuò fàn", &all_words_lesson );
    word->translations["de"] = "(Essen) kochen/zubereiten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "买", "mǎi", &all_words_lesson );
    word->translations["de"] = "kaufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "卖", "mài", &all_words_lesson );
    word->translations["de"] = "verkaufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "东西", "dōngxi", &all_words_lesson );
    word->translations["de"] = "Ding, Sache, Gegenstand ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "买东西", "mǎi dōngxi", &all_words_lesson );
    word->translations["de"] = "einkaufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "洗", "xǐ", &all_words_lesson );
    word->translations["de"] = "etw. waschen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "衣服", "yīfu", &all_words_lesson );
    word->translations["de"] = "Kleidung, Kleidungsstück ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "做衣服", "zuò yīfu", &all_words_lesson );
    word->translations["de"] = "nähen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "是的", "shìde", &all_words_lesson );
    word->translations["de"] = "ja, das stimmt; so ist es ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "睡觉", "shuì jiào", &all_words_lesson );
    word->translations["de"] = "schlafen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "那好", "nà hǎo", &all_words_lesson );
    word->translations["de"] = "dann ist es ja gut/in Ordnung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "回家", "huí jiā", &all_words_lesson );
    word->translations["de"] = "nach Hause gehen/kommen, heimkehren, heimgehen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "家", "jiā", &all_words_lesson );
    word->translations["de"] = "Familie, Heim, Zuhause ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "累", "lèi", &all_words_lesson );
    word->translations["de"] = "müde, erschöpft (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "饿", "è", &all_words_lesson );
    word->translations["de"] = "hungrig (sein), Hunger haben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吧", "ba", &all_words_lesson );
    word->translations["de"] = "(modale Satzpartikel) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "关", "guān", &all_words_lesson );
    word->translations["de"] = "etw. schließen (Fenster, Tür); etw. ausschalten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "关", "Guān", &all_words_lesson );
    word->translations["de"] = "Familienname ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "窗户", "chuānghu", &all_words_lesson );
    word->translations["de"] = "Fenster ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "户口", "hùkǒu", &all_words_lesson );
    word->translations["de"] = "Aufenthaltserlaubnis ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "户头", "hùtóu", &all_words_lesson );
    word->translations["de"] = "Bankkonto ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "喝", "hē", &all_words_lesson );
    word->translations["de"] = "trinken ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "茶", "chá", &all_words_lesson );
    word->translations["de"] = "Tee ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谢谢", "xièxie", &all_words_lesson );
    word->translations["de"] = "jm. danken, Danke! ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "好喝", "hǎohē", &all_words_lesson );
    word->translations["de"] = "schmecken (nur bei Getränken; wörtl: gut zu trinken sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中国", "Zhōngguó", &all_words_lesson );
    word->translations["de"] = "China ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "美国", "Měiguó", &all_words_lesson );
    word->translations["de"] = "USA, Amerika ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "德国", "Déguó", &all_words_lesson );
    word->translations["de"] = "Deutschland ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "丈夫", "zhàngfu", &all_words_lesson );
    word->translations["de"] = "Ehemann ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "爱人", "àiren", &all_words_lesson );
    word->translations["de"] = "Ehepartner ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "牙", "yá", &all_words_lesson );
    word->translations["de"] = "Zahn ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "万", "wàn", &all_words_lesson );
    word->translations["de"] = "10.000 ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "今天", "jīntiān", &all_words_lesson );
    word->translations["de"] = "der heutige Tag, heute ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "明天", "míngtiān", &all_words_lesson );
    word->translations["de"] = "der morgige Tag, morgen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "昨天", "zuótiān", &all_words_lesson );
    word->translations["de"] = "gestern ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "明白", "míngbai", &all_words_lesson );
    word->translations["de"] = "offensichtlich, verstehen, realisieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "有", "yǒu", &all_words_lesson );
    word->translations["de"] = "etw. haben, besitzen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "没", "méi", &all_words_lesson );
    word->translations["de"] = "nicht (haben), ''verneint ausschließlich das Verb 有 yǒu'' ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "课", "kè", &all_words_lesson );
    word->translations["de"] = "Unterricht, Lektion ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "上午", "shàngwǔ", &all_words_lesson );
    word->translations["de"] = "Vormittag, vormittags ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中午", "zhōngwǔ", &all_words_lesson );
    word->translations["de"] = "Mittag, mittags ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下午", "xiàwǔ", &all_words_lesson );
    word->translations["de"] = "Nachmittag, nachmittags ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "上", "shàng", &all_words_lesson );
    word->translations["de"] = "auf, über, höher; steigen, hoch gehen; erstes; '''vorheriges'''<nowiki>; etc...</nowiki> ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下", "xià", &all_words_lesson );
    word->translations["de"] = "unter, tiefer, herunter, absteigen; zweites; '''nächstes'''<nowiki>; etc...</nowiki> ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "空", "kòng", &all_words_lesson );
    word->translations["de"] = "freie Zeit, Muße, Lücke ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "事,事情", "shì, shìqing", &all_words_lesson );
    word->translations["de"] = "Vorhaben, Angelegenheit, Beschäftigung, Sache ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "一起", "yìqǐ", &all_words_lesson );
    word->translations["de"] = "zusammen, gemeinsam ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "房间", "fángjiān", &all_words_lesson );
    word->translations["de"] = "Zimmer, Raum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "小", "xiǎo", &all_words_lesson );
    word->translations["de"] = "klein (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "大", "dà", &all_words_lesson );
    word->translations["de"] = "groß (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "书架", "shūjià", &all_words_lesson );
    word->translations["de"] = "Bücherregal ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "木马", "mùmǎ", &all_words_lesson );
    word->translations["de"] = "Pferd (Sportgerät) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "地方", "dìfang", &all_words_lesson );
    word->translations["de"] = "Ort, Platz, Gegend ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "钱", "qián", &all_words_lesson );
    word->translations["de"] = "Geld ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "床", "chuáng", &all_words_lesson );
    word->translations["de"] = "Bett ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "零", "líng", &all_words_lesson );
    word->translations["de"] = "null ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "一", "yī", &all_words_lesson );
    word->translations["de"] = "eins ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "二", "èr", &all_words_lesson );
    word->translations["de"] = "zwei ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "三", "sān", &all_words_lesson );
    word->translations["de"] = "drei ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "四", "sì", &all_words_lesson );
    word->translations["de"] = "vier ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "五", "wǔ", &all_words_lesson );
    word->translations["de"] = "fünf ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "六", "liù", &all_words_lesson );
    word->translations["de"] = "sechs ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "七", "qī", &all_words_lesson );
    word->translations["de"] = "sieben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "八", "bā", &all_words_lesson );
    word->translations["de"] = "acht ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "九", "jiǔ", &all_words_lesson );
    word->translations["de"] = "neun ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "十", "shí", &all_words_lesson );
    word->translations["de"] = "zehn ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "年", "nián", &all_words_lesson );
    word->translations["de"] = "(Kalender-)Jahr ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "月", "yuè", &all_words_lesson );
    word->translations["de"] = "Monat; Mond ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日", "rì", &all_words_lesson );
    word->translations["de"] = "x'ter Monatstag (Schriftsprache); Sonne ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "号", "hào", &all_words_lesson );
    word->translations["de"] = "x'ter Monatstag (mündlich); Nummer ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "星期", "xīngqī", &all_words_lesson );
    word->translations["de"] = "Woche ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学期", "xuéqī", &all_words_lesson );
    word->translations["de"] = "Semester ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "天", "tiān", &all_words_lesson );
    word->translations["de"] = "Tag, Himmel ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "天安门", "Tiānānmén", &all_words_lesson );
    word->translations["de"] = "Platz des himmlischen Friedens ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "几", "jǐ", &all_words_lesson );
    word->translations["de"] = "wie viel(e) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "还", "hái", &all_words_lesson );
    word->translations["de"] = "noch, auch, außerdem, immer noch, doch noch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "书法", "shūfǎ", &all_words_lesson );
    word->translations["de"] = "Kalligrafie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "舞", "wǔ", &all_words_lesson );
    word->translations["de"] = "tanzen, schwingen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "百", "bǎi", &all_words_lesson );
    word->translations["de"] = "100 ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "个", "ge", &all_words_lesson );
    word->translations["de"] = "allg. Zählwort ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哪", "nǎ", &all_words_lesson );
    word->translations["de"] = "wie?, welche(s,r,...)?  (Fragepartikel) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "了", "le", &all_words_lesson );
    word->translations["de"] = "u.a. Perfektsuffix (vollendete Handlung) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "第", "dì", &all_words_lesson );
    word->translations["de"] = "(prefix before a number, for ordering numbers, e.g. \"first\", \"number two\", etc) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "售货员", "shòuhuòyuán", &all_words_lesson );
    word->translations["de"] = "Verkäufer/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "要", "yào", &all_words_lesson );
    word->translations["de"] = "etw. haben wollen, brauchen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "张", "zhāng", &all_words_lesson );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "张", "zhāng", &all_words_lesson );
    word->translations["de"] = "Zhang, chin. Familienname ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "地图", "dìtú", &all_words_lesson );
    word->translations["de"] = "Landkarte ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "多少", "duōshao", &all_words_lesson );
    word->translations["de"] = "wie viel, wie viele ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "付钱", "fùqián", &all_words_lesson );
    word->translations["de"] = "bezahlen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "两", "liǎng", &all_words_lesson );
    word->translations["de"] = "zwei ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "扇", "shàn", &all_words_lesson );
    word->translations["de"] = "(Fächer) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "桌子", "zhuōzi", &all_words_lesson );
    word->translations["de"] = "Tisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "把", "bǎ", &all_words_lesson );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "椅子", "yǐzi", &all_words_lesson );
    word->translations["de"] = "Stuhl ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "个", "gè/ge", &all_words_lesson );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "本", "běn", &all_words_lesson );
    word->translations["de"] = "(Band) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "台", "tái", &all_words_lesson );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "舒服", "shūfu", &all_words_lesson );
    word->translations["de"] = "bequem, behaglich, angenehm, komfortabel (sein), sich wohl fühlen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "只", "zhǐ", &all_words_lesson );
    word->translations["de"] = "nur, bloß, lediglich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "件", "jiàn", &all_words_lesson );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "玩具", "wánjù", &all_words_lesson );
    word->translations["de"] = "Spielzeug ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "座", "zuò", &all_words_lesson );
    word->translations["de"] = "(Sitz) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "楼", "lóu", &all_words_lesson );
    word->translations["de"] = "Gebäude ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "大学", "dàxué", &all_words_lesson );
    word->translations["de"] = "Hochschule, Universität ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "所", "suǒ", &all_words_lesson );
    word->translations["de"] = "(Ort) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "教学楼", "jiàoxuélóu", &all_words_lesson );
    word->translations["de"] = "Unterrichtsgebäude ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "我不太清楚", "wǒ bú tài qīngchu", &all_words_lesson );
    word->translations["de"] = "Ich bin mir nicht sicher; das weiß ich nicht so genau ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "百", "bǎi", &all_words_lesson );
    word->translations["de"] = "hundert ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "间", "jiān", &all_words_lesson );
    word->translations["de"] = "(Raum, zwischen) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "语法", "yǔfǎ", &all_words_lesson );
    word->translations["de"] = "Grammatik ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "杂志", "zázhì", &all_words_lesson );
    word->translations["de"] = "Zeitschrift, Magazin ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "画报", "huàbào", &all_words_lesson );
    word->translations["de"] = "Illustrierte ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "问", "wèn", &all_words_lesson );
    word->translations["de"] = "jemanden fragen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "位", "wèi", &all_words_lesson );
    word->translations["de"] = "(Platz) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "图书馆员", "túshūguǎnyuán", &all_words_lesson );
    word->translations["de"] = "Bibliothekar/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "找", "zhǎo", &all_words_lesson );
    word->translations["de"] = "suchen; zu jm. kommen; jn. aufsuchen, jn. zu sprechen wünschen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哪", "nǎ, něi", &all_words_lesson );
    word->translations["de"] = "welche/r/s ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "人民日报", "Rénmín Rìbào", &all_words_lesson );
    word->translations["de"] = "„Volkszeitung“ ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中央日报", "Zhōngyāng Rìbào", &all_words_lesson );
    word->translations["de"] = "„Zentralzeitung“ ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "只", "zhī", &all_words_lesson );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "一共", "yígòng", &all_words_lesson );
    word->translations["de"] = "insgesamt, alles zusammen genommen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "奇怪", "qíguài", &all_words_lesson );
    word->translations["de"] = "seltsam, merkwürdig, erstaunlich (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "对", "duì", &all_words_lesson );
    word->translations["de"] = "richtig, korrekt (sein), stimmen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉语", "hànyǔ", &all_words_lesson );
    word->translations["de"] = "die chinesische Sprache ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哪里", "nǎli", &all_words_lesson );
    word->translations["de"] = "ach woher denn!, aber nein! ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "几", "jǐ", &all_words_lesson );
    word->translations["de"] = "ein paar, einige ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "句子", "jùzi", &all_words_lesson );
    word->translations["de"] = "Satz ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "多", "duō", &all_words_lesson );
    word->translations["de"] = "viel, zahlreich (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "姓", "xìng", &all_words_lesson );
    word->translations["de"] = "(mit Familiennamen) heißen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "认识", "rènshi", &all_words_lesson );
    word->translations["de"] = "jn. kennen, kennenlernen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "又", "yòu", &all_words_lesson );
    word->translations["de"] = "noch dazu, ferner, außerdem; wieder ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "又...又", "yòu...yòu", &all_words_lesson );
    word->translations["de"] = "... und ..., sowohl ... als auch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "胖", "pàng", &all_words_lesson );
    word->translations["de"] = "dick, beleibt, korpulent (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "男", "nán", &all_words_lesson );
    word->translations["de"] = "männlich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "女", "nǚ", &all_words_lesson );
    word->translations["de"] = "weiblich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "瘦", "shòu", &all_words_lesson );
    word->translations["de"] = "schlank, mager (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "少", "shǎo", &all_words_lesson );
    word->translations["de"] = "wenig (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "厚", "hòu", &all_words_lesson );
    word->translations["de"] = "dick (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "就", "jiù", &all_words_lesson );
    word->translations["de"] = "nämlich, also, dann ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "去", "qù", &all_words_lesson );
    word->translations["de"] = "(hin)gehen, (hin)fahren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "去", "qù", &all_words_lesson );
    word->translations["de"] = "gehen/fahren nach/zu/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "食堂", "shítáng", &all_words_lesson );
    word->translations["de"] = "Kantine, Mensa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吃", "chī", &all_words_lesson );
    word->translations["de"] = "etw. essen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吃饭", "chīfàn", &all_words_lesson );
    word->translations["de"] = "essen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "好吃", "hǎo chī", &all_words_lesson );
    word->translations["de"] = "gut schmecken, lecker sein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "市场", "shìchǎng", &all_words_lesson );
    word->translations["de"] = "Markt, Marktplatz ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "水果", "shuǐguǒ", &all_words_lesson );
    word->translations["de"] = "Obst ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "公园", "gōngyuán", &all_words_lesson );
    word->translations["de"] = "Park ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "咖啡馆", "kāfēiguǎn", &all_words_lesson );
    word->translations["de"] = "Café, Caféteria ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "咖啡", "kāfēi", &all_words_lesson );
    word->translations["de"] = "Kaffee ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "进城", "jìn chéng", &all_words_lesson );
    word->translations["de"] = "in die Stadt gehen/fahren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "火车站", "huǒchēzhàn", &all_words_lesson );
    word->translations["de"] = "Bahnhof ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "站", "zhàn", &all_words_lesson );
    word->translations["de"] = "stehen; stehen bleiben; Haltestelle ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "接", "jiē", &all_words_lesson );
    word->translations["de"] = "jn. abholen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "俄国", "Éguó", &all_words_lesson );
    word->translations["de"] = "Russland ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "来", "lái", &all_words_lesson );
    word->translations["de"] = "kommen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "来", "lái", &all_words_lesson );
    word->translations["de"] = "kommen nach/in/zu ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "进", "jìn", &all_words_lesson );
    word->translations["de"] = "eintreten/hineingehen in, betreten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "上课", "shàng kè", &all_words_lesson );
    word->translations["de"] = "Unterricht haben/halten, mit dem Unterricht beginnen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "罢课", "bà kè", &all_words_lesson );
    word->translations["de"] = "den Unterreicht boykottieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "回", "huí", &all_words_lesson );
    word->translations["de"] = "zurückgehen, -kehren, -kommen nach ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "知道", "zhīdao", &all_words_lesson );
    word->translations["de"] = "etw. wissen, Kenntnis haben von; wissen, dass ..., ob ... etc. ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "时候", "shíhou", &all_words_lesson );
    word->translations["de"] = "Zeit, Zeitpunkt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "问", "wèn", &all_words_lesson );
    word->translations["de"] = "fragen, ob ..., wann ... etc. ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "门票", "ménpiào", &all_words_lesson );
    word->translations["de"] = "Eintrittskarte ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "说", "shuō", &all_words_lesson );
    word->translations["de"] = "eine Fremdsprache sprechen; sagen, sprechen, dass ... ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "为什么", "wèishénme", &all_words_lesson );
    word->translations["de"] = "warum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "对", "duì", &all_words_lesson );
    word->translations["de"] = "gegenüber, mit, zu, für ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "满意", "mǎnyì", &all_words_lesson );
    word->translations["de"] = "zufrieden (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "条件", "tiáojiàn", &all_words_lesson );
    word->translations["de"] = "Zustand, Verhältnisse ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "够", "gòu", &all_words_lesson );
    word->translations["de"] = "genug, genügend (sein), ausreichen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "太", "tài", &all_words_lesson );
    word->translations["de"] = "zu, allzu ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "新", "xīn", &all_words_lesson );
    word->translations["de"] = "neu (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "有的", "yǒude", &all_words_lesson );
    word->translations["de"] = "manche, einige ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "管", "guǎn", &all_words_lesson );
    word->translations["de"] = "sich kümmern um jn./etw. ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下课", "xià kè", &all_words_lesson );
    word->translations["de"] = "den Unterricht beenden ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "以后", "yǐhòu", &all_words_lesson );
    word->translations["de"] = "nach, danach, nachher ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "以前", "yǐqián", &all_words_lesson );
    word->translations["de"] = "vor, davor, ... ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "马上", "mǎshàng", &all_words_lesson );
    word->translations["de"] = "sofort, auf der Stelle ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "自己", "zìjǐ", &all_words_lesson );
    word->translations["de"] = "selbst; eigen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "呢", "ne", &all_words_lesson );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "总，总是", "zǒng, zǒngshi", &all_words_lesson );
    word->translations["de"] = "immer, stets ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "叫", "jiào", &all_words_lesson );
    word->translations["de"] = "heißen; jn./etw. rufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉堡", "Hànbǎo", &all_words_lesson );
    word->translations["de"] = "Hamburg ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "经济", "jīngjì", &all_words_lesson );
    word->translations["de"] = "Wirtschaft, Ökonomie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉学", "hànxué", &all_words_lesson );
    word->translations["de"] = "Sinologie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "每", "měi", &all_words_lesson );
    word->translations["de"] = "jede, jeder, jedes ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中午", "zhōngwǔ", &all_words_lesson );
    word->translations["de"] = "Mittag ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "行", "xíng", &all_words_lesson );
    word->translations["de"] = "möglich, erlaubt, geeignet sein; gehen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "行", "xíng", &all_words_lesson );
    word->translations["de"] = "das geht; das lässt sich machen; das ist in Ordnung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "时间", "shíjiān", &all_words_lesson );
    word->translations["de"] = "Zeit, Zeitraum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "花", "huā", &all_words_lesson );
    word->translations["de"] = "Zeit/Geld aufwenden, kosten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "贵", "guì", &all_words_lesson );
    word->translations["de"] = "teuer, kostspielig, wertvoll (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉德", "hàn-dé", &all_words_lesson );
    word->translations["de"] = "chinesisch-deutsch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "不谢", "bú xiè", &all_words_lesson );
    word->translations["de"] = "nichts zu danken ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下班", "xià bān", &all_words_lesson );
    word->translations["de"] = "Feierabend/Dienstschluss haben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

}

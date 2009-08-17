
#include <iostream>
#include "lesson.h"

Lesson all_words_lesson("Alle Wörter");
void init_all_words_lesson()
{
    int count = 0;
    Word* word;

    word = new Word( "汉语拼音", "Hànyǔ Pīnyīn" );
    word->translations["de"] = "die chinesisch-lateinische Pinyin-Umschrift ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "这", "zhè" );
    word->translations["de"] = "das, dies (hier) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "是", "shì" );
    word->translations["de"] = "sein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "爸爸", "bàba" );
    word->translations["de"] = "Papa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "那", "nà" );
    word->translations["de"] = "das, jenes (dort) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "妈妈", "māma" );
    word->translations["de"] = "Mama ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "姐姐", "jiějie" );
    word->translations["de"] = "ältere Schwester ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "和", "hé" );
    word->translations["de"] = "und (Objektkonkatenation) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "妹妹", "mèimei" );
    word->translations["de"] = "jüngere Schwester ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哥哥", "gēge" );
    word->translations["de"] = "älterer Bruder ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "弟弟", "dìdi" );
    word->translations["de"] = "jüngerer Bruder ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "爷爷", "yéye" );
    word->translations["de"] = "Opa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "奶奶", "nǎinai" );
    word->translations["de"] = "Oma ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "猫", "māo" );
    word->translations["de"] = "Katze ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "狗", "gǒu" );
    word->translations["de"] = "Hund ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "书", "shū" );
    word->translations["de"] = "Buch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "沙发", "shāfā" );
    word->translations["de"] = "Sofa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "收音机", "shōuyīnjī" );
    word->translations["de"] = "Radio ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "电话", "diànhuà" );
    word->translations["de"] = "Telefon ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "电视", "diànshì" );
    word->translations["de"] = "Fernseher ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "笔", "bǐ" );
    word->translations["de"] = "Pinsel ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谁", "shéi" );
    word->translations["de"] = "wer ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "王", "Wáng" );
    word->translations["de"] = "Familienname (König) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "先生", "xiānsheng" );
    word->translations["de"] = "Herr (Anrede) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "马", "Mǎ" );
    word->translations["de"] = "Familienname (Pferd) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "小姐", "xiǎojie" );
    word->translations["de"] = "Fräulein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "毛", "Máo" );
    word->translations["de"] = "Familienname (Haar, Borste) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "太太", "tàitai" );
    word->translations["de"] = "verheiratete Frau (Anrede) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "什么", "shénme" );
    word->translations["de"] = "was ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "图书馆", "túshūguǎn" );
    word->translations["de"] = "Bibliothek ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "教室", "jiàoshì" );
    word->translations["de"] = "Unterrichtsraum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "李", "Lǐ" );
    word->translations["de"] = "Familienname ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "老师", "lǎoshī" );
    word->translations["de"] = "Lehrer ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学生", "xuésheng" );
    word->translations["de"] = "Schüler, Student ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "的", "de" );
    word->translations["de"] = "(Attributpartikel), (nachstehend; nach dem Besitzer) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "历史", "lìshǐ" );
    word->translations["de"] = "Geschichte (Fach) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "地理", "dìlǐ" );
    word->translations["de"] = "Geographie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "英文", "yīngwén" );
    word->translations["de"] = "Englisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "词典", "cídiǎn" );
    word->translations["de"] = "Wörterbuch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "德文", "déwén" );
    word->translations["de"] = "Deutsch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日文", "rìwén" );
    word->translations["de"] = "Japanisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "系", "xì" );
    word->translations["de"] = "Seminar; Abteilung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中文", "zhōngwén" );
    word->translations["de"] = "Chinesisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "秘书", "mìshū" );
    word->translations["de"] = "Sektretär(in) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哦", "ó" );
    word->translations["de"] = "oh (Ausruf des Erstaunens) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "我", "wǒ" );
    word->translations["de"] = "ich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "你", "nǐ" );
    word->translations["de"] = "du, Sie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "您", "nín" );
    word->translations["de"] = "Sie (sehr höflich) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "他", "tā" );
    word->translations["de"] = "er ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "她", "tā" );
    word->translations["de"] = "sie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "它", "tā" );
    word->translations["de"] = "es ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "我们", "wǒmen" );
    word->translations["de"] = "wir ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "你们", "nǐmen" );
    word->translations["de"] = "ihr ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "他们", "tāmen" );
    word->translations["de"] = "sie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "她们", "tāmen" );
    word->translations["de"] = "sie (nur weibliche) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "它们", "tāmen" );
    word->translations["de"] = "sie (Dinge, Tiere) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "咱们", "zánmen" );
    word->translations["de"] = "wir ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "不", "bù" );
    word->translations["de"] = "nein, nicht ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "也", "yě" );
    word->translations["de"] = "auch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "都", "dōu" );
    word->translations["de"] = "beide,alle ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "好", "hǎo" );
    word->translations["de"] = "gut, geht gehen, (Begrüßung) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "天气", "tiānqì" );
    word->translations["de"] = "Wetter ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "很", "hěn" );
    word->translations["de"] = "sehr ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "真", "zhēn" );
    word->translations["de"] = "wahr, echt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "冷", "lěng" );
    word->translations["de"] = "kalt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "热", "rè" );
    word->translations["de"] = "warm ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "忙", "máng" );
    word->translations["de"] = "beschäftigt sein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吗", "ma" );
    word->translations["de"] = "(Fragepartikel) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "早", "zǎo" );
    word->translations["de"] = "früh, Guten Morgen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "可爱", "kě'ài" );
    word->translations["de"] = "liebenswert, niedlich, nett ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "同学", "tóngxué" );
    word->translations["de"] = "Kommilitone/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "们", "men" );
    word->translations["de"] = "(Pluralsuffix) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "努力", "nǔlì" );
    word->translations["de"] = "sich sehr anstrengen/ bemühen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "高", "gāo" );
    word->translations["de"] = "hoch, groß ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "矮", "ǎi" );
    word->translations["de"] = "niedrig, klein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "朋友", "péngyou" );
    word->translations["de"] = "Freund(in), Bekannte(r) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "休息", "xiūxi" );
    word->translations["de"] = "sich ausruhen, Pause machen, freihaben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "做", "zuò" );
    word->translations["de"] = "etw. machen, tun ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "练习", "liànxí" );
    word->translations["de"] = "Übung, Übungsaufgabe, etw. üben, einüben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学", "xué" );
    word->translations["de"] = "etw. lernen, studieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "生词", "shēngcí" );
    word->translations["de"] = "neue Vokabel ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "走", "zǒu" );
    word->translations["de"] = "gehen, weg-, fort-, losgehen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "再见", "zàijiàn" );
    word->translations["de"] = "Auf Wiedersehen! ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "工作", "gōngzuò" );
    word->translations["de"] = "Arbeit ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "教", "jiāo" );
    word->translations["de"] = "etw. unterrichten, lehren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "医生", "yīshēng" );
    word->translations["de"] = "Arzt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学习", "xuéxí" );
    word->translations["de"] = "lernen, studieren, etw. lernen, etw. studieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "俄文", "éwén" );
    word->translations["de"] = "Russisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "难", "nán" );
    word->translations["de"] = "schwierig, schwer (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "容易", "róngyì" );
    word->translations["de"] = "mühelos, leicht (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谈", "tán" );
    word->translations["de"] = "über etw. sprechen, etw. besprechen, sich über etw. unterhalten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "话", "huà" );
    word->translations["de"] = "Wort, Rede, Sprache ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谈话", "tán huà" );
    word->translations["de"] = "sich unterhalten, etw. besprechen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "看", "kàn" );
    word->translations["de"] = "sich etw. ansehen (Film etc.); etw. lesen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "看", "kān" );
    word->translations["de"] = "auf jemanden/etw. aufpassen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "报纸", "bàozhǐ" );
    word->translations["de"] = "Zeitung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "会", "huì" );
    word->translations["de"] = "etw. können, beherrschen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "妻子", "qīzi" );
    word->translations["de"] = "Ehefrau ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日本", "Rìběn" );
    word->translations["de"] = "Japan ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "人", "rén" );
    word->translations["de"] = "Mensch, Person ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日本人", "rìběnrén" );
    word->translations["de"] = "Japaner ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "孩子", "háizi" );
    word->translations["de"] = "Kind ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "饭", "fàn" );
    word->translations["de"] = "gekochter Reis; Essen, Mahl ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "做饭", "zuò fàn" );
    word->translations["de"] = "(Essen) kochen/zubereiten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "买", "mǎi" );
    word->translations["de"] = "kaufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "卖", "mài" );
    word->translations["de"] = "verkaufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "东西", "dōngxi" );
    word->translations["de"] = "Ding, Sache, Gegenstand ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "买东西", "mǎi dōngxi" );
    word->translations["de"] = "einkaufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "洗", "xǐ" );
    word->translations["de"] = "etw. waschen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "衣服", "yīfu" );
    word->translations["de"] = "Kleidung, Kleidungsstück ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "做衣服", "zuò yīfu" );
    word->translations["de"] = "nähen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "是的", "shìde" );
    word->translations["de"] = "ja, das stimmt; so ist es ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "睡觉", "shuì jiào" );
    word->translations["de"] = "schlafen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "那好", "nà hǎo" );
    word->translations["de"] = "dann ist es ja gut/in Ordnung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "回家", "huí jiā" );
    word->translations["de"] = "nach Hause gehen/kommen, heimkehren, heimgehen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "家", "jiā" );
    word->translations["de"] = "Familie, Heim, Zuhause ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "累", "lèi" );
    word->translations["de"] = "müde, erschöpft (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "饿", "è" );
    word->translations["de"] = "hungrig (sein), Hunger haben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吧", "ba" );
    word->translations["de"] = "(modale Satzpartikel) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "关", "guān" );
    word->translations["de"] = "etw. schließen (Fenster, Tür); etw. ausschalten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "关", "Guān" );
    word->translations["de"] = "Familienname ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "窗户", "chuānghu" );
    word->translations["de"] = "Fenster ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "户口", "hùkǒu" );
    word->translations["de"] = "Aufenthaltserlaubnis ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "户头", "hùtóu" );
    word->translations["de"] = "Bankkonto ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "喝", "hē" );
    word->translations["de"] = "trinken ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "茶", "chá" );
    word->translations["de"] = "Tee ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "谢谢", "xièxie" );
    word->translations["de"] = "jm. danken, Danke! ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "好喝", "hǎohē" );
    word->translations["de"] = "schmecken (nur bei Getränken; wörtl: gut zu trinken sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中国", "Zhōngguó" );
    word->translations["de"] = "China ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "美国", "Měiguó" );
    word->translations["de"] = "USA, Amerika ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "德国", "Déguó" );
    word->translations["de"] = "Deutschland ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "丈夫", "zhàngfu" );
    word->translations["de"] = "Ehemann ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "爱人", "àiren" );
    word->translations["de"] = "Ehepartner ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "牙", "yá" );
    word->translations["de"] = "Zahn ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "万", "wàn" );
    word->translations["de"] = "10.000 ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "今天", "jīntiān" );
    word->translations["de"] = "der heutige Tag, heute ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "明天", "míngtiān" );
    word->translations["de"] = "der morgige Tag, morgen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "昨天", "zuótiān" );
    word->translations["de"] = "gestern ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "明白", "míngbai" );
    word->translations["de"] = "offensichtlich, verstehen, realisieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "有", "yǒu" );
    word->translations["de"] = "etw. haben, besitzen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "没", "méi" );
    word->translations["de"] = "nicht (haben), ''verneint ausschließlich das Verb 有 yǒu'' ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "课", "kè" );
    word->translations["de"] = "Unterricht, Lektion ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "上午", "shàngwǔ" );
    word->translations["de"] = "Vormittag, vormittags ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中午", "zhōngwǔ" );
    word->translations["de"] = "Mittag, mittags ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下午", "xiàwǔ" );
    word->translations["de"] = "Nachmittag, nachmittags ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "上", "shàng" );
    word->translations["de"] = "auf, über, höher; steigen, hoch gehen; erstes; '''vorheriges'''<nowiki>; etc...</nowiki> ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下", "xià" );
    word->translations["de"] = "unter, tiefer, herunter, absteigen; zweites; '''nächstes'''<nowiki>; etc...</nowiki> ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "空", "kòng" );
    word->translations["de"] = "freie Zeit, Muße, Lücke ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "事,事情", "shì, shìqing" );
    word->translations["de"] = "Vorhaben, Angelegenheit, Beschäftigung, Sache ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "一起", "yìqǐ" );
    word->translations["de"] = "zusammen, gemeinsam ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "房间", "fángjiān" );
    word->translations["de"] = "Zimmer, Raum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "小", "xiǎo" );
    word->translations["de"] = "klein (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "大", "dà" );
    word->translations["de"] = "groß (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "书架", "shūjià" );
    word->translations["de"] = "Bücherregal ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "木马", "mùmǎ" );
    word->translations["de"] = "Pferd (Sportgerät) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "地方", "dìfang" );
    word->translations["de"] = "Ort, Platz, Gegend ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "钱", "qián" );
    word->translations["de"] = "Geld ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "床", "chuáng" );
    word->translations["de"] = "Bett ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "零", "líng" );
    word->translations["de"] = "null ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "一", "yī" );
    word->translations["de"] = "eins ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "二", "èr" );
    word->translations["de"] = "zwei ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "三", "sān" );
    word->translations["de"] = "drei ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "四", "sì" );
    word->translations["de"] = "vier ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "五", "wǔ" );
    word->translations["de"] = "fünf ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "六", "liù" );
    word->translations["de"] = "sechs ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "七", "qī" );
    word->translations["de"] = "sieben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "八", "bā" );
    word->translations["de"] = "acht ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "九", "jiǔ" );
    word->translations["de"] = "neun ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "十", "shí" );
    word->translations["de"] = "zehn ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "年", "nián" );
    word->translations["de"] = "(Kalender-)Jahr ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "月", "yuè" );
    word->translations["de"] = "Monat; Mond ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "日", "rì" );
    word->translations["de"] = "x'ter Monatstag (Schriftsprache); Sonne ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "号", "hào" );
    word->translations["de"] = "x'ter Monatstag (mündlich); Nummer ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "星期", "xīngqī" );
    word->translations["de"] = "Woche ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "学期", "xuéqī" );
    word->translations["de"] = "Semester ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "天", "tiān" );
    word->translations["de"] = "Tag, Himmel ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "天安门", "Tiānānmén" );
    word->translations["de"] = "Platz des himmlischen Friedens ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "几", "jǐ" );
    word->translations["de"] = "wie viel(e) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "还", "hái" );
    word->translations["de"] = "noch, auch, außerdem, immer noch, doch noch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "书法", "shūfǎ" );
    word->translations["de"] = "Kalligrafie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "舞", "wǔ" );
    word->translations["de"] = "tanzen, schwingen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "百", "bǎi" );
    word->translations["de"] = "100 ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "个", "ge" );
    word->translations["de"] = "allg. Zählwort ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哪", "nǎ" );
    word->translations["de"] = "wie?, welche(s,r,...)?  (Fragepartikel) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "了", "le" );
    word->translations["de"] = "u.a. Perfektsuffix (vollendete Handlung) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "第", "dì" );
    word->translations["de"] = "(prefix before a number, for ordering numbers, e.g. \"first\", \"number two\", etc) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "售货员", "shòuhuòyuán" );
    word->translations["de"] = "Verkäufer/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "要", "yào" );
    word->translations["de"] = "etw. haben wollen, brauchen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "张", "zhāng" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "张", "zhāng" );
    word->translations["de"] = "Zhang, chin. Familienname ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "地图", "dìtú" );
    word->translations["de"] = "Landkarte ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "多少", "duōshao" );
    word->translations["de"] = "wie viel, wie viele ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "付钱", "fùqián" );
    word->translations["de"] = "bezahlen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "两", "liǎng" );
    word->translations["de"] = "zwei ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "扇", "shàn" );
    word->translations["de"] = "(Fächer) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "桌子", "zhuōzi" );
    word->translations["de"] = "Tisch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "把", "bǎ" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "椅子", "yǐzi" );
    word->translations["de"] = "Stuhl ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "个", "gè/ge" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "本", "běn" );
    word->translations["de"] = "(Band) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "台", "tái" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "舒服", "shūfu" );
    word->translations["de"] = "bequem, behaglich, angenehm, komfortabel (sein), sich wohl fühlen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "只", "zhǐ" );
    word->translations["de"] = "nur, bloß, lediglich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "件", "jiàn" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "玩具", "wánjù" );
    word->translations["de"] = "Spielzeug ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "座", "zuò" );
    word->translations["de"] = "(Sitz) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "楼", "lóu" );
    word->translations["de"] = "Gebäude ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "大学", "dàxué" );
    word->translations["de"] = "Hochschule, Universität ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "所", "suǒ" );
    word->translations["de"] = "(Ort) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "教学楼", "jiàoxuélóu" );
    word->translations["de"] = "Unterrichtsgebäude ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "我不太清楚", "wǒ bú tài qīngchu" );
    word->translations["de"] = "Ich bin mir nicht sicher; das weiß ich nicht so genau ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "百", "bǎi" );
    word->translations["de"] = "hundert ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "间", "jiān" );
    word->translations["de"] = "(Raum, zwischen) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "语法", "yǔfǎ" );
    word->translations["de"] = "Grammatik ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "杂志", "zázhì" );
    word->translations["de"] = "Zeitschrift, Magazin ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "画报", "huàbào" );
    word->translations["de"] = "Illustrierte ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "问", "wèn" );
    word->translations["de"] = "jemanden fragen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "位", "wèi" );
    word->translations["de"] = "(Platz) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "图书馆员", "túshūguǎnyuán" );
    word->translations["de"] = "Bibliothekar/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "找", "zhǎo" );
    word->translations["de"] = "suchen; zu jm. kommen; jn. aufsuchen, jn. zu sprechen wünschen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哪", "nǎ, něi" );
    word->translations["de"] = "welche/r/s ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "人民日报", "Rénmín Rìbào" );
    word->translations["de"] = "„Volkszeitung“ ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中央日报", "Zhōngyāng Rìbào" );
    word->translations["de"] = "„Zentralzeitung“ ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "只", "zhī" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "一共", "yígòng" );
    word->translations["de"] = "insgesamt, alles zusammen genommen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "奇怪", "qíguài" );
    word->translations["de"] = "seltsam, merkwürdig, erstaunlich (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "对", "duì" );
    word->translations["de"] = "richtig, korrekt (sein), stimmen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉语", "hànyǔ" );
    word->translations["de"] = "die chinesische Sprache ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "哪里", "nǎli" );
    word->translations["de"] = "ach woher denn!, aber nein! ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "几", "jǐ" );
    word->translations["de"] = "ein paar, einige ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "句子", "jùzi" );
    word->translations["de"] = "Satz ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "多", "duō" );
    word->translations["de"] = "viel, zahlreich (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "姓", "xìng" );
    word->translations["de"] = "(mit Familiennamen) heißen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "认识", "rènshi" );
    word->translations["de"] = "jn. kennen, kennenlernen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "又", "yòu" );
    word->translations["de"] = "noch dazu, ferner, außerdem; wieder ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "又...又", "yòu...yòu" );
    word->translations["de"] = "... und ..., sowohl ... als auch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "胖", "pàng" );
    word->translations["de"] = "dick, beleibt, korpulent (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "男", "nán" );
    word->translations["de"] = "männlich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "女", "nǚ" );
    word->translations["de"] = "weiblich ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "瘦", "shòu" );
    word->translations["de"] = "schlank, mager (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "少", "shǎo" );
    word->translations["de"] = "wenig (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "厚", "hòu" );
    word->translations["de"] = "dick (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "就", "jiù" );
    word->translations["de"] = "nämlich, also, dann ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "去", "qù" );
    word->translations["de"] = "(hin)gehen, (hin)fahren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "去", "qù" );
    word->translations["de"] = "gehen/fahren nach/zu/in ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "食堂", "shítáng" );
    word->translations["de"] = "Kantine, Mensa ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吃", "chī" );
    word->translations["de"] = "etw. essen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "吃饭", "chīfàn" );
    word->translations["de"] = "essen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "好吃", "hǎo chī" );
    word->translations["de"] = "gut schmecken, lecker sein ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "市场", "shìchǎng" );
    word->translations["de"] = "Markt, Marktplatz ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "水果", "shuǐguǒ" );
    word->translations["de"] = "Obst ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "公园", "gōngyuán" );
    word->translations["de"] = "Park ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "咖啡馆", "kāfēiguǎn" );
    word->translations["de"] = "Café, Caféteria ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "咖啡", "kāfēi" );
    word->translations["de"] = "Kaffee ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "进城", "jìn chéng" );
    word->translations["de"] = "in die Stadt gehen/fahren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "火车站", "huǒchēzhàn" );
    word->translations["de"] = "Bahnhof ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "站", "zhàn" );
    word->translations["de"] = "stehen; stehen bleiben; Haltestelle ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "接", "jiē" );
    word->translations["de"] = "jn. abholen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "俄国", "Éguó" );
    word->translations["de"] = "Russland ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "来", "lái" );
    word->translations["de"] = "kommen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "来", "lái" );
    word->translations["de"] = "kommen nach/in/zu ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "进", "jìn" );
    word->translations["de"] = "eintreten/hineingehen in, betreten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "上课", "shàng kè" );
    word->translations["de"] = "Unterricht haben/halten, mit dem Unterricht beginnen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "罢课", "bà kè" );
    word->translations["de"] = "den Unterreicht boykottieren ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "回", "huí" );
    word->translations["de"] = "zurückgehen, -kehren, -kommen nach ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "知道", "zhīdao" );
    word->translations["de"] = "etw. wissen, Kenntnis haben von; wissen, dass ..., ob ... etc. ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "时候", "shíhou" );
    word->translations["de"] = "Zeit, Zeitpunkt ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "问", "wèn" );
    word->translations["de"] = "fragen, ob ..., wann ... etc. ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "门票", "ménpiào" );
    word->translations["de"] = "Eintrittskarte ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "说", "shuō" );
    word->translations["de"] = "eine Fremdsprache sprechen; sagen, sprechen, dass ... ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "为什么", "wèishénme" );
    word->translations["de"] = "warum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "对", "duì" );
    word->translations["de"] = "gegenüber, mit, zu, für ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "满意", "mǎnyì" );
    word->translations["de"] = "zufrieden (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "条件", "tiáojiàn" );
    word->translations["de"] = "Zustand, Verhältnisse ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "够", "gòu" );
    word->translations["de"] = "genug, genügend (sein), ausreichen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "太", "tài" );
    word->translations["de"] = "zu, allzu ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "新", "xīn" );
    word->translations["de"] = "neu (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "有的", "yǒude" );
    word->translations["de"] = "manche, einige ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "管", "guǎn" );
    word->translations["de"] = "sich kümmern um jn./etw. ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下课", "xià kè" );
    word->translations["de"] = "den Unterricht beenden ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "以后", "yǐhòu" );
    word->translations["de"] = "nach, danach, nachher ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "以前", "yǐqián" );
    word->translations["de"] = "vor, davor, ... ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "马上", "mǎshàng" );
    word->translations["de"] = "sofort, auf der Stelle ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "自己", "zìjǐ" );
    word->translations["de"] = "selbst; eigen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "呢", "ne" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "总，总是", "zǒng, zǒngshi" );
    word->translations["de"] = "immer, stets ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "叫", "jiào" );
    word->translations["de"] = "heißen; jn./etw. rufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉堡", "Hànbǎo" );
    word->translations["de"] = "Hamburg ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "经济", "jīngjì" );
    word->translations["de"] = "Wirtschaft, Ökonomie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉学", "hànxué" );
    word->translations["de"] = "Sinologie ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "每", "měi" );
    word->translations["de"] = "jede, jeder, jedes ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "中午", "zhōngwǔ" );
    word->translations["de"] = "Mittag ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "行", "xíng" );
    word->translations["de"] = "möglich, erlaubt, geeignet sein; gehen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "行", "xíng" );
    word->translations["de"] = "das geht; das lässt sich machen; das ist in Ordnung ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "时间", "shíjiān" );
    word->translations["de"] = "Zeit, Zeitraum ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "花", "huā" );
    word->translations["de"] = "Zeit/Geld aufwenden, kosten ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "贵", "guì" );
    word->translations["de"] = "teuer, kostspielig, wertvoll (sein) ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "汉德", "hàn-dé" );
    word->translations["de"] = "chinesisch-deutsch ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "不谢", "bú xiè" );
    word->translations["de"] = "nichts zu danken ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "下班", "xià bān" );
    word->translations["de"] = "Feierabend/Dienstschluss haben ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "酒馆", "jiǔguǎn" );
    word->translations["de"] = "Wirtshaus, Gasthaus, Kneipe ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "买菜", "mǎi cài" );
    word->translations["de"] = "Lebensmittel einkaufen ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "喜欢", "xǐhuān" );
    word->translations["de"] = "etw./jn. mögen, gern haben, Gefallen haben an; etw. gern tun ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;

    word = new Word( "意思", "yìsi" );
    word->translations["de"] = "Bedeutung, Sinn ";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;
}

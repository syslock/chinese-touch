
#include "lesson.h"

Lesson all_words_lesson("Alle Wörter");
void init_all_words_lesson()
{
    Word* word;

    word = new Word( "汉语拼音", "Hànyǔ Pīnyīn" );
    word->translations["de"] = "die chinesisch-lateinische Pinyin-Umschrift ";
    all_words_lesson.push_back( word );

    word = new Word( "这", "zhè" );
    word->translations["de"] = "das, dies (hier) ";
    all_words_lesson.push_back( word );

    word = new Word( "是", "shì" );
    word->translations["de"] = "sein ";
    all_words_lesson.push_back( word );

    word = new Word( "爸爸", "bàba" );
    word->translations["de"] = "Papa ";
    all_words_lesson.push_back( word );

    word = new Word( "那", "nà" );
    word->translations["de"] = "das, jenes (dort) ";
    all_words_lesson.push_back( word );

    word = new Word( "妈妈", "māma" );
    word->translations["de"] = "Mama ";
    all_words_lesson.push_back( word );

    word = new Word( "姐姐", "jiějie" );
    word->translations["de"] = "ältere Schwester ";
    all_words_lesson.push_back( word );

    word = new Word( "和", "hé" );
    word->translations["de"] = "und (Objektkonkatenation) ";
    all_words_lesson.push_back( word );

    word = new Word( "妹妹", "mèimei" );
    word->translations["de"] = "jüngere Schwester ";
    all_words_lesson.push_back( word );

    word = new Word( "哥哥", "gēge" );
    word->translations["de"] = "älterer Bruder ";
    all_words_lesson.push_back( word );

    word = new Word( "弟弟", "dìdi" );
    word->translations["de"] = "jüngerer Bruder ";
    all_words_lesson.push_back( word );

    word = new Word( "爷爷", "yéye" );
    word->translations["de"] = "Opa ";
    all_words_lesson.push_back( word );

    word = new Word( "奶奶", "nǎinai" );
    word->translations["de"] = "Oma ";
    all_words_lesson.push_back( word );

    word = new Word( "猫", "māo" );
    word->translations["de"] = "Katze ";
    all_words_lesson.push_back( word );

    word = new Word( "狗", "gǒu" );
    word->translations["de"] = "Hund ";
    all_words_lesson.push_back( word );

    word = new Word( "书", "shū" );
    word->translations["de"] = "Buch ";
    all_words_lesson.push_back( word );

    word = new Word( "沙发", "shāfā" );
    word->translations["de"] = "Sofa ";
    all_words_lesson.push_back( word );

    word = new Word( "收音机", "shōuyīnjī" );
    word->translations["de"] = "Radio ";
    all_words_lesson.push_back( word );

    word = new Word( "电话", "diànhuà" );
    word->translations["de"] = "Telefon ";
    all_words_lesson.push_back( word );

    word = new Word( "电视", "diànshì" );
    word->translations["de"] = "Fernseher ";
    all_words_lesson.push_back( word );

    word = new Word( "笔", "bǐ" );
    word->translations["de"] = "Pinsel ";
    all_words_lesson.push_back( word );

    word = new Word( "谁", "shéi" );
    word->translations["de"] = "wer ";
    all_words_lesson.push_back( word );

    word = new Word( "王", "Wáng" );
    word->translations["de"] = "Familienname (König) ";
    all_words_lesson.push_back( word );

    word = new Word( "先生", "xiānsheng" );
    word->translations["de"] = "Herr (Anrede) ";
    all_words_lesson.push_back( word );

    word = new Word( "马", "Mǎ" );
    word->translations["de"] = "Familienname (Pferd) ";
    all_words_lesson.push_back( word );

    word = new Word( "小姐", "xiǎojie" );
    word->translations["de"] = "Fräulein ";
    all_words_lesson.push_back( word );

    word = new Word( "毛", "Máo" );
    word->translations["de"] = "Familienname (Haar, Borste) ";
    all_words_lesson.push_back( word );

    word = new Word( "太太", "tàitai" );
    word->translations["de"] = "verheiratete Frau (Anrede) ";
    all_words_lesson.push_back( word );

    word = new Word( "什么", "shénme" );
    word->translations["de"] = "was ";
    all_words_lesson.push_back( word );

    word = new Word( "图书馆", "túshūguǎn" );
    word->translations["de"] = "Bibliothek ";
    all_words_lesson.push_back( word );

    word = new Word( "教室", "jiàoshì" );
    word->translations["de"] = "Unterrichtsraum ";
    all_words_lesson.push_back( word );

    word = new Word( "李", "Lǐ" );
    word->translations["de"] = "Familienname ";
    all_words_lesson.push_back( word );

    word = new Word( "老师", "lǎoshī" );
    word->translations["de"] = "Lehrer ";
    all_words_lesson.push_back( word );

    word = new Word( "学生", "xuésheng" );
    word->translations["de"] = "Schüler, Student ";
    all_words_lesson.push_back( word );

    word = new Word( "的", "de" );
    word->translations["de"] = "(Attributpartikel), (nachstehend; nach dem Besitzer) ";
    all_words_lesson.push_back( word );

    word = new Word( "历史", "lìshǐ" );
    word->translations["de"] = "Geschichte (Fach) ";
    all_words_lesson.push_back( word );

    word = new Word( "地理", "dìlǐ" );
    word->translations["de"] = "Geographie ";
    all_words_lesson.push_back( word );

    word = new Word( "英文", "yīngwén" );
    word->translations["de"] = "Englisch ";
    all_words_lesson.push_back( word );

    word = new Word( "词典", "cídiǎn" );
    word->translations["de"] = "Wörterbuch ";
    all_words_lesson.push_back( word );

    word = new Word( "德文", "déwén" );
    word->translations["de"] = "Deutsch ";
    all_words_lesson.push_back( word );

    word = new Word( "日文", "rìwén" );
    word->translations["de"] = "Japanisch ";
    all_words_lesson.push_back( word );

    word = new Word( "系", "xì" );
    word->translations["de"] = "Seminar; Abteilung ";
    all_words_lesson.push_back( word );

    word = new Word( "中文", "zhōngwén" );
    word->translations["de"] = "Chinesisch ";
    all_words_lesson.push_back( word );

    word = new Word( "秘书", "mìshū" );
    word->translations["de"] = "Sektretär(in) ";
    all_words_lesson.push_back( word );

    word = new Word( "哦", "ó" );
    word->translations["de"] = "oh (Ausruf des Erstaunens) ";
    all_words_lesson.push_back( word );

    word = new Word( "我", "wǒ" );
    word->translations["de"] = "ich ";
    all_words_lesson.push_back( word );

    word = new Word( "你", "nǐ" );
    word->translations["de"] = "du, Sie ";
    all_words_lesson.push_back( word );

    word = new Word( "您", "nín" );
    word->translations["de"] = "Sie (sehr höflich) ";
    all_words_lesson.push_back( word );

    word = new Word( "他", "tā" );
    word->translations["de"] = "er ";
    all_words_lesson.push_back( word );

    word = new Word( "她", "tā" );
    word->translations["de"] = "sie ";
    all_words_lesson.push_back( word );

    word = new Word( "它", "tā" );
    word->translations["de"] = "es ";
    all_words_lesson.push_back( word );

    word = new Word( "我们", "wǒmen" );
    word->translations["de"] = "wir ";
    all_words_lesson.push_back( word );

    word = new Word( "你们", "nǐmen" );
    word->translations["de"] = "ihr ";
    all_words_lesson.push_back( word );

    word = new Word( "他们", "tāmen" );
    word->translations["de"] = "sie ";
    all_words_lesson.push_back( word );

    word = new Word( "她们", "tāmen" );
    word->translations["de"] = "sie (nur weibliche) ";
    all_words_lesson.push_back( word );

    word = new Word( "它们", "tāmen" );
    word->translations["de"] = "sie (Dinge, Tiere) ";
    all_words_lesson.push_back( word );

    word = new Word( "咱们", "zánmen" );
    word->translations["de"] = "wir ";
    all_words_lesson.push_back( word );

    word = new Word( "不", "bù" );
    word->translations["de"] = "nein, nicht ";
    all_words_lesson.push_back( word );

    word = new Word( "也", "yě" );
    word->translations["de"] = "auch ";
    all_words_lesson.push_back( word );

    word = new Word( "都", "dōu" );
    word->translations["de"] = "beide,alle ";
    all_words_lesson.push_back( word );

    word = new Word( "好", "hǎo" );
    word->translations["de"] = "gut, geht gehen, (Begrüßung) ";
    all_words_lesson.push_back( word );

    word = new Word( "天气", "tiānqì" );
    word->translations["de"] = "Wetter ";
    all_words_lesson.push_back( word );

    word = new Word( "很", "hěn" );
    word->translations["de"] = "sehr ";
    all_words_lesson.push_back( word );

    word = new Word( "真", "zhēn" );
    word->translations["de"] = "wahr, echt ";
    all_words_lesson.push_back( word );

    word = new Word( "冷", "lěng" );
    word->translations["de"] = "kalt ";
    all_words_lesson.push_back( word );

    word = new Word( "热", "rè" );
    word->translations["de"] = "warm ";
    all_words_lesson.push_back( word );

    word = new Word( "忙", "máng" );
    word->translations["de"] = "beschäftigt sein ";
    all_words_lesson.push_back( word );

    word = new Word( "吗", "ma" );
    word->translations["de"] = "(Fragepartikel) ";
    all_words_lesson.push_back( word );

    word = new Word( "早", "zǎo" );
    word->translations["de"] = "früh, Guten Morgen ";
    all_words_lesson.push_back( word );

    word = new Word( "可爱", "kě'ài" );
    word->translations["de"] = "liebenswert, niedlich, nett ";
    all_words_lesson.push_back( word );

    word = new Word( "同学", "tóngxué" );
    word->translations["de"] = "Kommilitone/in ";
    all_words_lesson.push_back( word );

    word = new Word( "们", "men" );
    word->translations["de"] = "(Pluralsuffix) ";
    all_words_lesson.push_back( word );

    word = new Word( "努力", "nǔlì" );
    word->translations["de"] = "sich sehr anstrengen/ bemühen ";
    all_words_lesson.push_back( word );

    word = new Word( "高", "gāo" );
    word->translations["de"] = "hoch, groß ";
    all_words_lesson.push_back( word );

    word = new Word( "矮", "ǎi" );
    word->translations["de"] = "niedrig, klein ";
    all_words_lesson.push_back( word );

    word = new Word( "朋友", "péngyou" );
    word->translations["de"] = "Freund(in), Bekannte(r) ";
    all_words_lesson.push_back( word );

    word = new Word( "休息", "xiūxi" );
    word->translations["de"] = "sich ausruhen, Pause machen, freihaben ";
    all_words_lesson.push_back( word );

    word = new Word( "做", "zuò" );
    word->translations["de"] = "etw. machen, tun ";
    all_words_lesson.push_back( word );

    word = new Word( "练习", "liànxí" );
    word->translations["de"] = "Übung, Übungsaufgabe, etw. üben, einüben ";
    all_words_lesson.push_back( word );

    word = new Word( "学", "xué" );
    word->translations["de"] = "etw. lernen, studieren ";
    all_words_lesson.push_back( word );

    word = new Word( "生词", "shēngcí" );
    word->translations["de"] = "neue Vokabel ";
    all_words_lesson.push_back( word );

    word = new Word( "走", "zǒu" );
    word->translations["de"] = "gehen, weg-, fort-, losgehen ";
    all_words_lesson.push_back( word );

    word = new Word( "再见", "zàijiàn" );
    word->translations["de"] = "Auf Wiedersehen! ";
    all_words_lesson.push_back( word );

    word = new Word( "工作", "gōngzuò" );
    word->translations["de"] = "Arbeit ";
    all_words_lesson.push_back( word );

    word = new Word( "教", "jiāo" );
    word->translations["de"] = "etw. unterrichten, lehren ";
    all_words_lesson.push_back( word );

    word = new Word( "医生", "yīshēng" );
    word->translations["de"] = "Arzt ";
    all_words_lesson.push_back( word );

    word = new Word( "学习", "xuéxí" );
    word->translations["de"] = "lernen, studieren, etw. lernen, etw. studieren ";
    all_words_lesson.push_back( word );

    word = new Word( "俄文", "éwén" );
    word->translations["de"] = "Russisch ";
    all_words_lesson.push_back( word );

    word = new Word( "难", "nán" );
    word->translations["de"] = "schwierig, schwer (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "容易", "róngyì" );
    word->translations["de"] = "mühelos, leicht (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "谈", "tán" );
    word->translations["de"] = "über etw. sprechen, etw. besprechen, sich über etw. unterhalten ";
    all_words_lesson.push_back( word );

    word = new Word( "话", "huà" );
    word->translations["de"] = "Wort, Rede, Sprache ";
    all_words_lesson.push_back( word );

    word = new Word( "谈话", "tán huà" );
    word->translations["de"] = "sich unterhalten, etw. besprechen ";
    all_words_lesson.push_back( word );

    word = new Word( "看", "kàn" );
    word->translations["de"] = "sich etw. ansehen (Film etc.); etw. lesen ";
    all_words_lesson.push_back( word );

    word = new Word( "看", "kān" );
    word->translations["de"] = "auf jemanden/etw. aufpassen ";
    all_words_lesson.push_back( word );

    word = new Word( "报纸", "bàozhǐ" );
    word->translations["de"] = "Zeitung ";
    all_words_lesson.push_back( word );

    word = new Word( "会", "huì" );
    word->translations["de"] = "etw. können, beherrschen ";
    all_words_lesson.push_back( word );

    word = new Word( "妻子", "qīzi" );
    word->translations["de"] = "Ehefrau ";
    all_words_lesson.push_back( word );

    word = new Word( "日本", "Rìběn" );
    word->translations["de"] = "Japan ";
    all_words_lesson.push_back( word );

    word = new Word( "人", "rén" );
    word->translations["de"] = "Mensch, Person ";
    all_words_lesson.push_back( word );

    word = new Word( "日本人", "rìběnrén" );
    word->translations["de"] = "Japaner ";
    all_words_lesson.push_back( word );

    word = new Word( "孩子", "háizi" );
    word->translations["de"] = "Kind ";
    all_words_lesson.push_back( word );

    word = new Word( "饭", "fàn" );
    word->translations["de"] = "gekochter Reis; Essen, Mahl ";
    all_words_lesson.push_back( word );

    word = new Word( "做饭", "zuò fàn" );
    word->translations["de"] = "(Essen) kochen/zubereiten ";
    all_words_lesson.push_back( word );

    word = new Word( "买", "mǎi" );
    word->translations["de"] = "kaufen ";
    all_words_lesson.push_back( word );

    word = new Word( "卖", "mài" );
    word->translations["de"] = "verkaufen ";
    all_words_lesson.push_back( word );

    word = new Word( "东西", "dōngxi" );
    word->translations["de"] = "Ding, Sache, Gegenstand ";
    all_words_lesson.push_back( word );

    word = new Word( "买东西", "mǎi dōngxi" );
    word->translations["de"] = "einkaufen ";
    all_words_lesson.push_back( word );

    word = new Word( "洗", "xǐ" );
    word->translations["de"] = "etw. waschen ";
    all_words_lesson.push_back( word );

    word = new Word( "衣服", "yīfu" );
    word->translations["de"] = "Kleidung, Kleidungsstück ";
    all_words_lesson.push_back( word );

    word = new Word( "做衣服", "zuò yīfu" );
    word->translations["de"] = "nähen ";
    all_words_lesson.push_back( word );

    word = new Word( "是的", "shìde" );
    word->translations["de"] = "ja, das stimmt; so ist es ";
    all_words_lesson.push_back( word );

    word = new Word( "睡觉", "shuì jiào" );
    word->translations["de"] = "schlafen ";
    all_words_lesson.push_back( word );

    word = new Word( "那好", "nà hǎo" );
    word->translations["de"] = "dann ist es ja gut/in Ordnung ";
    all_words_lesson.push_back( word );

    word = new Word( "回家", "huí jiā" );
    word->translations["de"] = "nach Hause gehen/kommen, heimkehren, heimgehen ";
    all_words_lesson.push_back( word );

    word = new Word( "家", "jiā" );
    word->translations["de"] = "Familie, Heim, Zuhause ";
    all_words_lesson.push_back( word );

    word = new Word( "累", "lèi" );
    word->translations["de"] = "müde, erschöpft (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "饿", "è" );
    word->translations["de"] = "hungrig (sein), Hunger haben ";
    all_words_lesson.push_back( word );

    word = new Word( "吧", "ba" );
    word->translations["de"] = "(modale Satzpartikel) ";
    all_words_lesson.push_back( word );

    word = new Word( "关", "guān" );
    word->translations["de"] = "etw. schließen (Fenster, Tür); etw. ausschalten ";
    all_words_lesson.push_back( word );

    word = new Word( "关", "Guān" );
    word->translations["de"] = "Familienname ";
    all_words_lesson.push_back( word );

    word = new Word( "窗户", "chuānghu" );
    word->translations["de"] = "Fenster ";
    all_words_lesson.push_back( word );

    word = new Word( "户口", "hùkǒu" );
    word->translations["de"] = "Aufenthaltserlaubnis ";
    all_words_lesson.push_back( word );

    word = new Word( "户头", "hùtóu" );
    word->translations["de"] = "Bankkonto ";
    all_words_lesson.push_back( word );

    word = new Word( "喝", "hē" );
    word->translations["de"] = "trinken ";
    all_words_lesson.push_back( word );

    word = new Word( "茶", "chá" );
    word->translations["de"] = "Tee ";
    all_words_lesson.push_back( word );

    word = new Word( "谢谢", "xièxie" );
    word->translations["de"] = "jm. danken, Danke! ";
    all_words_lesson.push_back( word );

    word = new Word( "好喝", "hǎohē" );
    word->translations["de"] = "schmecken (nur bei Getränken; wörtl: gut zu trinken sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "中国", "Zhōngguó" );
    word->translations["de"] = "China ";
    all_words_lesson.push_back( word );

    word = new Word( "美国", "Měiguó" );
    word->translations["de"] = "USA, Amerika ";
    all_words_lesson.push_back( word );

    word = new Word( "德国", "Déguó" );
    word->translations["de"] = "Deutschland ";
    all_words_lesson.push_back( word );

    word = new Word( "丈夫", "zhàngfu" );
    word->translations["de"] = "Ehemann ";
    all_words_lesson.push_back( word );

    word = new Word( "爱人", "àiren" );
    word->translations["de"] = "Ehepartner ";
    all_words_lesson.push_back( word );

    word = new Word( "牙", "yá" );
    word->translations["de"] = "Zahn ";
    all_words_lesson.push_back( word );

    word = new Word( "万", "wàn" );
    word->translations["de"] = "10.000 ";
    all_words_lesson.push_back( word );

    word = new Word( "今天", "jīntiān" );
    word->translations["de"] = "der heutige Tag, heute ";
    all_words_lesson.push_back( word );

    word = new Word( "明天", "míngtiān" );
    word->translations["de"] = "der morgige Tag, morgen ";
    all_words_lesson.push_back( word );

    word = new Word( "昨天", "zuótiān" );
    word->translations["de"] = "gestern ";
    all_words_lesson.push_back( word );

    word = new Word( "明白", "míngbai" );
    word->translations["de"] = "offensichtlich, verstehen, realisieren ";
    all_words_lesson.push_back( word );

    word = new Word( "有", "yǒu" );
    word->translations["de"] = "etw. haben, besitzen ";
    all_words_lesson.push_back( word );

    word = new Word( "没", "méi" );
    word->translations["de"] = "nicht (haben), ''verneint ausschließlich das Verb 有 yǒu'' ";
    all_words_lesson.push_back( word );

    word = new Word( "课", "kè" );
    word->translations["de"] = "Unterricht, Lektion ";
    all_words_lesson.push_back( word );

    word = new Word( "上午", "shàngwǔ" );
    word->translations["de"] = "Vormittag, vormittags ";
    all_words_lesson.push_back( word );

    word = new Word( "中午", "zhōngwǔ" );
    word->translations["de"] = "Mittag, mittags ";
    all_words_lesson.push_back( word );

    word = new Word( "下午", "xiàwǔ" );
    word->translations["de"] = "Nachmittag, nachmittags ";
    all_words_lesson.push_back( word );

    word = new Word( "上", "shàng" );
    word->translations["de"] = "auf, über, höher; steigen, hoch gehen; erstes; '''vorheriges'''<nowiki>; etc...</nowiki> ";
    all_words_lesson.push_back( word );

    word = new Word( "下", "xià" );
    word->translations["de"] = "unter, tiefer, herunter, absteigen; zweites; '''nächstes'''<nowiki>; etc...</nowiki> ";
    all_words_lesson.push_back( word );

    word = new Word( "空", "kòng" );
    word->translations["de"] = "freie Zeit, Muße, Lücke ";
    all_words_lesson.push_back( word );

    word = new Word( "事,事情", "shì, shìqing" );
    word->translations["de"] = "Vorhaben, Angelegenheit, Beschäftigung, Sache ";
    all_words_lesson.push_back( word );

    word = new Word( "一起", "yìqǐ" );
    word->translations["de"] = "zusammen, gemeinsam ";
    all_words_lesson.push_back( word );

    word = new Word( "房间", "fángjiān" );
    word->translations["de"] = "Zimmer, Raum ";
    all_words_lesson.push_back( word );

    word = new Word( "小", "xiǎo" );
    word->translations["de"] = "klein (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "大", "dà" );
    word->translations["de"] = "groß (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "书架", "shūjià" );
    word->translations["de"] = "Bücherregal ";
    all_words_lesson.push_back( word );

    word = new Word( "木马", "mùmǎ" );
    word->translations["de"] = "Pferd (Sportgerät) ";
    all_words_lesson.push_back( word );

    word = new Word( "地方", "dìfang" );
    word->translations["de"] = "Ort, Platz, Gegend ";
    all_words_lesson.push_back( word );

    word = new Word( "钱", "qián" );
    word->translations["de"] = "Geld ";
    all_words_lesson.push_back( word );

    word = new Word( "床", "chuáng" );
    word->translations["de"] = "Bett ";
    all_words_lesson.push_back( word );

    word = new Word( "零", "líng" );
    word->translations["de"] = "null ";
    all_words_lesson.push_back( word );

    word = new Word( "一", "yī" );
    word->translations["de"] = "eins ";
    all_words_lesson.push_back( word );

    word = new Word( "二", "èr" );
    word->translations["de"] = "zwei ";
    all_words_lesson.push_back( word );

    word = new Word( "三", "sān" );
    word->translations["de"] = "drei ";
    all_words_lesson.push_back( word );

    word = new Word( "四", "sì" );
    word->translations["de"] = "vier ";
    all_words_lesson.push_back( word );

    word = new Word( "五", "wǔ" );
    word->translations["de"] = "fünf ";
    all_words_lesson.push_back( word );

    word = new Word( "六", "liù" );
    word->translations["de"] = "sechs ";
    all_words_lesson.push_back( word );

    word = new Word( "七", "qī" );
    word->translations["de"] = "sieben ";
    all_words_lesson.push_back( word );

    word = new Word( "八", "bā" );
    word->translations["de"] = "acht ";
    all_words_lesson.push_back( word );

    word = new Word( "九", "jiǔ" );
    word->translations["de"] = "neun ";
    all_words_lesson.push_back( word );

    word = new Word( "十", "shí" );
    word->translations["de"] = "zehn ";
    all_words_lesson.push_back( word );

    word = new Word( "年", "nián" );
    word->translations["de"] = "(Kalender-)Jahr ";
    all_words_lesson.push_back( word );

    word = new Word( "月", "yuè" );
    word->translations["de"] = "Monat; Mond ";
    all_words_lesson.push_back( word );

    word = new Word( "日", "rì" );
    word->translations["de"] = "x'ter Monatstag (Schriftsprache); Sonne ";
    all_words_lesson.push_back( word );

    word = new Word( "号", "hào" );
    word->translations["de"] = "x'ter Monatstag (mündlich); Nummer ";
    all_words_lesson.push_back( word );

    word = new Word( "星期", "xīngqī" );
    word->translations["de"] = "Woche ";
    all_words_lesson.push_back( word );

    word = new Word( "学期", "xuéqī" );
    word->translations["de"] = "Semester ";
    all_words_lesson.push_back( word );

    word = new Word( "天", "tiān" );
    word->translations["de"] = "Tag, Himmel ";
    all_words_lesson.push_back( word );

    word = new Word( "天安门", "Tiānānmén" );
    word->translations["de"] = "Platz des himmlischen Friedens ";
    all_words_lesson.push_back( word );

    word = new Word( "几", "jǐ" );
    word->translations["de"] = "wie viel(e) ";
    all_words_lesson.push_back( word );

    word = new Word( "还", "hái" );
    word->translations["de"] = "noch, auch, außerdem, immer noch, doch noch ";
    all_words_lesson.push_back( word );

    word = new Word( "书法", "shūfǎ" );
    word->translations["de"] = "Kalligrafie ";
    all_words_lesson.push_back( word );

    word = new Word( "舞", "wǔ" );
    word->translations["de"] = "tanzen, schwingen ";
    all_words_lesson.push_back( word );

    word = new Word( "百", "bǎi" );
    word->translations["de"] = "100 ";
    all_words_lesson.push_back( word );

    word = new Word( "个", "ge" );
    word->translations["de"] = "allg. Zählwort ";
    all_words_lesson.push_back( word );

    word = new Word( "哪", "nǎ" );
    word->translations["de"] = "wie?, welche(s,r,...)?  (Fragepartikel) ";
    all_words_lesson.push_back( word );

    word = new Word( "了", "le" );
    word->translations["de"] = "u.a. Perfektsuffix (vollendete Handlung) ";
    all_words_lesson.push_back( word );

    word = new Word( "第", "dì" );
    word->translations["de"] = "(prefix before a number, for ordering numbers, e.g. \"first\", \"number two\", etc) ";
    all_words_lesson.push_back( word );

    word = new Word( "售货员", "shòuhuòyuán" );
    word->translations["de"] = "Verkäufer/in ";
    all_words_lesson.push_back( word );

    word = new Word( "要", "yào" );
    word->translations["de"] = "etw. haben wollen, brauchen ";
    all_words_lesson.push_back( word );

    word = new Word( "张", "zhāng" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "张", "zhāng" );
    word->translations["de"] = "Zhang, chin. Familienname ";
    all_words_lesson.push_back( word );

    word = new Word( "地图", "dìtú" );
    word->translations["de"] = "Landkarte ";
    all_words_lesson.push_back( word );

    word = new Word( "多少", "duōshao" );
    word->translations["de"] = "wie viel, wie viele ";
    all_words_lesson.push_back( word );

    word = new Word( "付钱", "fùqián" );
    word->translations["de"] = "bezahlen ";
    all_words_lesson.push_back( word );

    word = new Word( "两", "liǎng" );
    word->translations["de"] = "zwei ";
    all_words_lesson.push_back( word );

    word = new Word( "扇", "shàn" );
    word->translations["de"] = "(Fächer) ";
    all_words_lesson.push_back( word );

    word = new Word( "桌子", "zhuōzi" );
    word->translations["de"] = "Tisch ";
    all_words_lesson.push_back( word );

    word = new Word( "把", "bǎ" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "椅子", "yǐzi" );
    word->translations["de"] = "Stuhl ";
    all_words_lesson.push_back( word );

    word = new Word( "个", "gè/ge" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "本", "běn" );
    word->translations["de"] = "(Band) ";
    all_words_lesson.push_back( word );

    word = new Word( "台", "tái" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "舒服", "shūfu" );
    word->translations["de"] = "bequem, behaglich, angenehm, komfortabel (sein), sich wohl fühlen ";
    all_words_lesson.push_back( word );

    word = new Word( "只", "zhǐ" );
    word->translations["de"] = "nur, bloß, lediglich ";
    all_words_lesson.push_back( word );

    word = new Word( "件", "jiàn" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "玩具", "wánjù" );
    word->translations["de"] = "Spielzeug ";
    all_words_lesson.push_back( word );

    word = new Word( "座", "zuò" );
    word->translations["de"] = "(Sitz) ";
    all_words_lesson.push_back( word );

    word = new Word( "楼", "lóu" );
    word->translations["de"] = "Gebäude ";
    all_words_lesson.push_back( word );

    word = new Word( "大学", "dàxué" );
    word->translations["de"] = "Hochschule, Universität ";
    all_words_lesson.push_back( word );

    word = new Word( "所", "suǒ" );
    word->translations["de"] = "(Ort) ";
    all_words_lesson.push_back( word );

    word = new Word( "教学楼", "jiàoxuélóu" );
    word->translations["de"] = "Unterrichtsgebäude ";
    all_words_lesson.push_back( word );

    word = new Word( "我不太清楚", "wǒ bú tài qīngchu" );
    word->translations["de"] = "Ich bin mir nicht sicher; das weiß ich nicht so genau ";
    all_words_lesson.push_back( word );

    word = new Word( "百", "bǎi" );
    word->translations["de"] = "hundert ";
    all_words_lesson.push_back( word );

    word = new Word( "间", "jiān" );
    word->translations["de"] = "(Raum, zwischen) ";
    all_words_lesson.push_back( word );

    word = new Word( "语法", "yǔfǎ" );
    word->translations["de"] = "Grammatik ";
    all_words_lesson.push_back( word );

    word = new Word( "杂志", "zázhì" );
    word->translations["de"] = "Zeitschrift, Magazin ";
    all_words_lesson.push_back( word );

    word = new Word( "画报", "huàbào" );
    word->translations["de"] = "Illustrierte ";
    all_words_lesson.push_back( word );

    word = new Word( "问", "wèn" );
    word->translations["de"] = "jemanden fragen ";
    all_words_lesson.push_back( word );

    word = new Word( "位", "wèi" );
    word->translations["de"] = "(Platz) ";
    all_words_lesson.push_back( word );

    word = new Word( "图书馆员", "túshūguǎnyuán" );
    word->translations["de"] = "Bibliothekar/in ";
    all_words_lesson.push_back( word );

    word = new Word( "找", "zhǎo" );
    word->translations["de"] = "suchen; zu jm. kommen; jn. aufsuchen, jn. zu sprechen wünschen ";
    all_words_lesson.push_back( word );

    word = new Word( "哪", "nǎ, něi" );
    word->translations["de"] = "welche/r/s ";
    all_words_lesson.push_back( word );

    word = new Word( "人民日报", "Rénmín Rìbào" );
    word->translations["de"] = "„Volkszeitung“ ";
    all_words_lesson.push_back( word );

    word = new Word( "中央日报", "Zhōngyāng Rìbào" );
    word->translations["de"] = "„Zentralzeitung“ ";
    all_words_lesson.push_back( word );

    word = new Word( "只", "zhī" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "一共", "yígòng" );
    word->translations["de"] = "insgesamt, alles zusammen genommen ";
    all_words_lesson.push_back( word );

    word = new Word( "奇怪", "qíguài" );
    word->translations["de"] = "seltsam, merkwürdig, erstaunlich (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "对", "duì" );
    word->translations["de"] = "richtig, korrekt (sein), stimmen ";
    all_words_lesson.push_back( word );

    word = new Word( "汉语", "hànyǔ" );
    word->translations["de"] = "die chinesische Sprache ";
    all_words_lesson.push_back( word );

    word = new Word( "哪里", "nǎli" );
    word->translations["de"] = "ach woher denn!, aber nein! ";
    all_words_lesson.push_back( word );

    word = new Word( "几", "jǐ" );
    word->translations["de"] = "ein paar, einige ";
    all_words_lesson.push_back( word );

    word = new Word( "句子", "jùzi" );
    word->translations["de"] = "Satz ";
    all_words_lesson.push_back( word );

    word = new Word( "多", "duō" );
    word->translations["de"] = "viel, zahlreich (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "姓", "xìng" );
    word->translations["de"] = "(mit Familiennamen) heißen ";
    all_words_lesson.push_back( word );

    word = new Word( "认识", "rènshi" );
    word->translations["de"] = "jn. kennen, kennenlernen ";
    all_words_lesson.push_back( word );

    word = new Word( "又", "yòu" );
    word->translations["de"] = "noch dazu, ferner, außerdem; wieder ";
    all_words_lesson.push_back( word );

    word = new Word( "又...又", "yòu...yòu" );
    word->translations["de"] = "... und ..., sowohl ... als auch ";
    all_words_lesson.push_back( word );

    word = new Word( "胖", "pàng" );
    word->translations["de"] = "dick, beleibt, korpulent (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "男", "nán" );
    word->translations["de"] = "männlich ";
    all_words_lesson.push_back( word );

    word = new Word( "女", "nǚ" );
    word->translations["de"] = "weiblich ";
    all_words_lesson.push_back( word );

    word = new Word( "瘦", "shòu" );
    word->translations["de"] = "schlank, mager (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "少", "shǎo" );
    word->translations["de"] = "wenig (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "厚", "hòu" );
    word->translations["de"] = "dick (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "就", "jiù" );
    word->translations["de"] = "nämlich, also, dann ";
    all_words_lesson.push_back( word );

    word = new Word( "去", "qù" );
    word->translations["de"] = "(hin)gehen, (hin)fahren ";
    all_words_lesson.push_back( word );

    word = new Word( "去", "qù" );
    word->translations["de"] = "gehen/fahren nach/zu/in ";
    all_words_lesson.push_back( word );

    word = new Word( "食堂", "shítáng" );
    word->translations["de"] = "Kantine, Mensa ";
    all_words_lesson.push_back( word );

    word = new Word( "吃", "chī" );
    word->translations["de"] = "etw. essen ";
    all_words_lesson.push_back( word );

    word = new Word( "吃饭", "chīfàn" );
    word->translations["de"] = "essen ";
    all_words_lesson.push_back( word );

    word = new Word( "好吃", "hǎo chī" );
    word->translations["de"] = "gut schmecken, lecker sein ";
    all_words_lesson.push_back( word );

    word = new Word( "市场", "shìchǎng" );
    word->translations["de"] = "Markt, Marktplatz ";
    all_words_lesson.push_back( word );

    word = new Word( "水果", "shuǐguǒ" );
    word->translations["de"] = "Obst ";
    all_words_lesson.push_back( word );

    word = new Word( "公园", "gōngyuán" );
    word->translations["de"] = "Park ";
    all_words_lesson.push_back( word );

    word = new Word( "咖啡馆", "kāfēiguǎn" );
    word->translations["de"] = "Café, Caféteria ";
    all_words_lesson.push_back( word );

    word = new Word( "咖啡", "kāfēi" );
    word->translations["de"] = "Kaffee ";
    all_words_lesson.push_back( word );

    word = new Word( "进城", "jìn chéng" );
    word->translations["de"] = "in die Stadt gehen/fahren ";
    all_words_lesson.push_back( word );

    word = new Word( "火车站", "huǒchēzhàn" );
    word->translations["de"] = "Bahnhof ";
    all_words_lesson.push_back( word );

    word = new Word( "站", "zhàn" );
    word->translations["de"] = "stehen; stehen bleiben; Haltestelle ";
    all_words_lesson.push_back( word );

    word = new Word( "接", "jiē" );
    word->translations["de"] = "jn. abholen ";
    all_words_lesson.push_back( word );

    word = new Word( "俄国", "Éguó" );
    word->translations["de"] = "Russland ";
    all_words_lesson.push_back( word );

    word = new Word( "来", "lái" );
    word->translations["de"] = "kommen ";
    all_words_lesson.push_back( word );

    word = new Word( "来", "lái" );
    word->translations["de"] = "kommen nach/in/zu ";
    all_words_lesson.push_back( word );

    word = new Word( "进", "jìn" );
    word->translations["de"] = "eintreten/hineingehen in, betreten ";
    all_words_lesson.push_back( word );

    word = new Word( "上课", "shàng kè" );
    word->translations["de"] = "Unterricht haben/halten, mit dem Unterricht beginnen ";
    all_words_lesson.push_back( word );

    word = new Word( "罢课", "bà kè" );
    word->translations["de"] = "den Unterreicht boykottieren ";
    all_words_lesson.push_back( word );

    word = new Word( "回", "huí" );
    word->translations["de"] = "zurückgehen, -kehren, -kommen nach ";
    all_words_lesson.push_back( word );

    word = new Word( "知道", "zhīdao" );
    word->translations["de"] = "etw. wissen, Kenntnis haben von; wissen, dass ..., ob ... etc. ";
    all_words_lesson.push_back( word );

    word = new Word( "时候", "shíhou" );
    word->translations["de"] = "Zeit, Zeitpunkt ";
    all_words_lesson.push_back( word );

    word = new Word( "问", "wèn" );
    word->translations["de"] = "fragen, ob ..., wann ... etc. ";
    all_words_lesson.push_back( word );

    word = new Word( "门票", "ménpiào" );
    word->translations["de"] = "Eintrittskarte ";
    all_words_lesson.push_back( word );

    word = new Word( "说", "shuō" );
    word->translations["de"] = "eine Fremdsprache sprechen; sagen, sprechen, dass ... ";
    all_words_lesson.push_back( word );

    word = new Word( "为什么", "wèishénme" );
    word->translations["de"] = "warum ";
    all_words_lesson.push_back( word );

    word = new Word( "对", "duì" );
    word->translations["de"] = "gegenüber, mit, zu, für ";
    all_words_lesson.push_back( word );

    word = new Word( "满意", "mǎnyì" );
    word->translations["de"] = "zufrieden (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "条件", "tiáojiàn" );
    word->translations["de"] = "Zustand, Verhältnisse ";
    all_words_lesson.push_back( word );

    word = new Word( "够", "gòu" );
    word->translations["de"] = "genug, genügend (sein), ausreichen ";
    all_words_lesson.push_back( word );

    word = new Word( "太", "tài" );
    word->translations["de"] = "zu, allzu ";
    all_words_lesson.push_back( word );

    word = new Word( "新", "xīn" );
    word->translations["de"] = "neu (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "有的", "yǒude" );
    word->translations["de"] = "manche, einige ";
    all_words_lesson.push_back( word );

    word = new Word( "管", "guǎn" );
    word->translations["de"] = "sich kümmern um jn./etw. ";
    all_words_lesson.push_back( word );

    word = new Word( "下课", "xià kè" );
    word->translations["de"] = "den Unterricht beenden ";
    all_words_lesson.push_back( word );

    word = new Word( "以后", "yǐhòu" );
    word->translations["de"] = "nach, danach, nachher ";
    all_words_lesson.push_back( word );

    word = new Word( "以前", "yǐqián" );
    word->translations["de"] = "vor, davor, ... ";
    all_words_lesson.push_back( word );

    word = new Word( "马上", "mǎshàng" );
    word->translations["de"] = "sofort, auf der Stelle ";
    all_words_lesson.push_back( word );

    word = new Word( "自己", "zìjǐ" );
    word->translations["de"] = "selbst; eigen ";
    all_words_lesson.push_back( word );

    word = new Word( "呢", "ne" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "总，总是", "zǒng, zǒngshi" );
    word->translations["de"] = "immer, stets ";
    all_words_lesson.push_back( word );

    word = new Word( "叫", "jiào" );
    word->translations["de"] = "heißen; jn./etw. rufen ";
    all_words_lesson.push_back( word );

    word = new Word( "汉堡", "Hànbǎo" );
    word->translations["de"] = "Hamburg ";
    all_words_lesson.push_back( word );

    word = new Word( "经济", "jīngjì" );
    word->translations["de"] = "Wirtschaft, Ökonomie ";
    all_words_lesson.push_back( word );

    word = new Word( "汉学", "hànxué" );
    word->translations["de"] = "Sinologie ";
    all_words_lesson.push_back( word );

    word = new Word( "每", "měi" );
    word->translations["de"] = "jede, jeder, jedes ";
    all_words_lesson.push_back( word );

    word = new Word( "中午", "zhōngwǔ" );
    word->translations["de"] = "Mittag ";
    all_words_lesson.push_back( word );

    word = new Word( "行", "xíng" );
    word->translations["de"] = "möglich, erlaubt, geeignet sein; gehen ";
    all_words_lesson.push_back( word );

    word = new Word( "行", "xíng" );
    word->translations["de"] = "das geht; das lässt sich machen; das ist in Ordnung ";
    all_words_lesson.push_back( word );

    word = new Word( "时间", "shíjiān" );
    word->translations["de"] = "Zeit, Zeitraum ";
    all_words_lesson.push_back( word );

    word = new Word( "花", "huā" );
    word->translations["de"] = "Zeit/Geld aufwenden, kosten ";
    all_words_lesson.push_back( word );

    word = new Word( "贵", "guì" );
    word->translations["de"] = "teuer, kostspielig, wertvoll (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "汉德", "hàn-dé" );
    word->translations["de"] = "chinesisch-deutsch ";
    all_words_lesson.push_back( word );

    word = new Word( "不谢", "bú xiè" );
    word->translations["de"] = "nichts zu danken ";
    all_words_lesson.push_back( word );

    word = new Word( "下班", "xià bān" );
    word->translations["de"] = "Feierabend/Dienstschluss haben ";
    all_words_lesson.push_back( word );

    word = new Word( "酒馆", "jiǔguǎn" );
    word->translations["de"] = "Wirtshaus, Gasthaus, Kneipe ";
    all_words_lesson.push_back( word );

    word = new Word( "买菜", "mǎi cài" );
    word->translations["de"] = "Lebensmittel einkaufen ";
    all_words_lesson.push_back( word );

    word = new Word( "喜欢", "xǐhuān" );
    word->translations["de"] = "etw./jn. mögen, gern haben, Gefallen haben an; etw. gern tun ";
    all_words_lesson.push_back( word );

    word = new Word( "意思", "yìsi" );
    word->translations["de"] = "Bedeutung, Sinn ";
    all_words_lesson.push_back( word );

    word = new Word( "有意思", "yǒu yìsi" );
    word->translations["de"] = "interessant, amüsant sein; Sinn haben ";
    all_words_lesson.push_back( word );

    word = new Word( "一点儿", "yìdiǎnr" );
    word->translations["de"] = "ein bisschen, ein wenig, etwas ";
    all_words_lesson.push_back( word );

    word = new Word( "作业", "zuòyè" );
    word->translations["de"] = "Schul-, Hausaufgaben ";
    all_words_lesson.push_back( word );

    word = new Word( "毕业", "bìyè" );
    word->translations["de"] = "das Studium abschließen ";
    all_words_lesson.push_back( word );

    word = new Word( "没意思", "méi yìsi" );
    word->translations["de"] = "uninteressant, langweilig, sinnlos (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "先", "xiān" );
    word->translations["de"] = "zuerst, zunächst ";
    all_words_lesson.push_back( word );

    word = new Word( "课文", "kèwén" );
    word->translations["de"] = "(Schulbuch-, Lehrbuch-) Text ";
    all_words_lesson.push_back( word );

    word = new Word( "篇", "piān" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "人口", "rénkǒu" );
    word->translations["de"] = "Bevölkerung ";
    all_words_lesson.push_back( word );

    word = new Word( "懂", "dǒng" );
    word->translations["de"] = "etw. verstehen, begreifen ";
    all_words_lesson.push_back( word );

    word = new Word( "怎么样", "zěnmeyàng" );
    word->translations["de"] = "wie, auf welche Weise?; wie wäre es, wenn?; was hältst du davon? ";
    all_words_lesson.push_back( word );

    word = new Word( "身体", "shēntǐ" );
    word->translations["de"] = "Leib, Körper ";
    all_words_lesson.push_back( word );

    word = new Word( "伯父", "bófù" );
    word->translations["de"] = "Onkel (älterer Bruder des Vaters); Anrede gegenüber älteren Herren ";
    all_words_lesson.push_back( word );

    word = new Word( "了", "le" );
    word->translations["de"] = "modale Satzpartikel ";
    all_words_lesson.push_back( word );

    word = new Word( "头", "tóu" );
    word->translations["de"] = "Kopf ";
    all_words_lesson.push_back( word );

    word = new Word( "疼", "téng" );
    word->translations["de"] = "weh tun, schmerzen ";
    all_words_lesson.push_back( word );

    word = new Word( "认真", "rènzhēn" );
    word->translations["de"] = "gewissenhaft, fleißig und sorgfältig, ernsthaft (sein); etw. ernst nehmen ";
    all_words_lesson.push_back( word );

    word = new Word( "进步", "jìnbù" );
    word->translations["de"] = "Fortschritt ";
    all_words_lesson.push_back( word );

    word = new Word( "快", "kuài" );
    word->translations["de"] = "schnell, rasch (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "慢", "màn" );
    word->translations["de"] = "langsam (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "没关系", "méi guānxi" );
    word->translations["de"] = "das macht nichts, ist nicht so schlimm; keine Ursache (sich zu entschuldigen) ";
    all_words_lesson.push_back( word );

    word = new Word( "说话", "shuō huà" );
    word->translations["de"] = "reden, sprechen ";
    all_words_lesson.push_back( word );

    word = new Word( "在", "zài" );
    word->translations["de"] = "da sein, anwesend sein; (an einem Ort) sein, sich befinden in... ";
    all_words_lesson.push_back( word );

    word = new Word( "在", "zài" );
    word->translations["de"] = "gerade (dabei) ";
    all_words_lesson.push_back( word );

    word = new Word( "正在", "zhèngzài" );
    word->translations["de"] = "gerade (dabei) ";
    all_words_lesson.push_back( word );

    word = new Word( "等", "děng" );
    word->translations["de"] = "auf jn./etw. warten ";
    all_words_lesson.push_back( word );

    word = new Word( "汉字", "hànzì" );
    word->translations["de"] = "chinesische Schriftzeichen ";
    all_words_lesson.push_back( word );

    word = new Word( "字", "zì" );
    word->translations["de"] = "Schriftzeichen ";
    all_words_lesson.push_back( word );

    word = new Word( "敲", "qiāo" );
    word->translations["de"] = "an/auf etw. klopfen, schlagen ";
    all_words_lesson.push_back( word );

    word = new Word( "门", "mén" );
    word->translations["de"] = "Tür ";
    all_words_lesson.push_back( word );

    word = new Word( "儿子", "érzi" );
    word->translations["de"] = "Sohn ";
    all_words_lesson.push_back( word );

    word = new Word( "开", "kāi" );
    word->translations["de"] = "etw. öffnen; etw. an-, einschalten ";
    all_words_lesson.push_back( word );

    word = new Word( "伯母", "bómǔ" );
    word->translations["de"] = "Tante (Frau des älteren Bruders des Vaters) ";
    all_words_lesson.push_back( word );

    word = new Word( "请进", "qǐng jìn" );
    word->translations["de"] = "bitte komm herein; treten Sie bitte ein ";
    all_words_lesson.push_back( word );

    word = new Word( "请坐", "qǐng zuò" );
    word->translations["de"] = "setz dich doch; bitte nehmen Sie Platz ";
    all_words_lesson.push_back( word );

    word = new Word( "洗澡", "xǐ zǎo" );
    word->translations["de"] = "baden, ein Bad nehmen ";
    all_words_lesson.push_back( word );

    word = new Word( "上班", "shàng bān" );
    word->translations["de"] = "zur Arbeit gehen, mit der Arbeit anfangen, bei der Arbeit sein ";
    all_words_lesson.push_back( word );

    word = new Word( "晚上", "wǎnshang" );
    word->translations["de"] = "Abend, abends ";
    all_words_lesson.push_back( word );

    word = new Word( "再", "zài" );
    word->translations["de"] = "wieder, noch einmal ";
    all_words_lesson.push_back( word );

    word = new Word( "女儿", "nǚ'ér" );
    word->translations["de"] = "Tochter ";
    all_words_lesson.push_back( word );

    word = new Word( "哎哟", "āiyō" );
    word->translations["de"] = "o je, ach ";
    all_words_lesson.push_back( word );

    word = new Word( "湿", "shī" );
    word->translations["de"] = "nass, durchnässt, feucht (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "雨", "yǔ" );
    word->translations["de"] = "Regen ";
    all_words_lesson.push_back( word );

    word = new Word( "车", "chē" );
    word->translations["de"] = "Fahrzeug, Wagen, ''hier:'' Bus ";
    all_words_lesson.push_back( word );

    word = new Word( "汽车", "qìchē" );
    word->translations["de"] = "Automobil ";
    all_words_lesson.push_back( word );

    word = new Word( "辆", "liàng" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "特别", "tèbié" );
    word->translations["de"] = "besonders, ungemein; sonderbar (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "换", "huàn" );
    word->translations["de"] = "etw. wechseln, tauschen ";
    all_words_lesson.push_back( word );

    word = new Word( "厨房", "chúfáng" );
    word->translations["de"] = "Küche ";
    all_words_lesson.push_back( word );

    word = new Word( "快（...了）", "kuài" );
    word->translations["de"] = "bald, gleich ";
    all_words_lesson.push_back( word );

    word = new Word( "然后", "ránhòu" );
    word->translations["de"] = "dann, danach, nachher, anschließend ";
    all_words_lesson.push_back( word );

    word = new Word( "冬天", "dōngtiān" );
    word->translations["de"] = "Winter ";
    all_words_lesson.push_back( word );

    word = new Word( "到", "dào" );
    word->translations["de"] = "ankommen, eintreffen (in) ";
    all_words_lesson.push_back( word );

    word = new Word( "凉", "liáng" );
    word->translations["de"] = "kühl, kalt (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "暖气", "nuǎnqì" );
    word->translations["de"] = "(Zentral-)Heizung ";
    all_words_lesson.push_back( word );

    word = new Word( "就", "jiù" );
    word->translations["de"] = "gleich, sofort ";
    all_words_lesson.push_back( word );

    word = new Word( "常常,常", "chángcháng" );
    word->translations["de"] = "oft, häufig ";
    all_words_lesson.push_back( word );

    word = new Word( "好看", "hǎo kàn" );
    word->translations["de"] = "gut aussehend, hübsch (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "以前", "yǐqián" );
    word->translations["de"] = "früher; vor, vorher, bevor ";
    all_words_lesson.push_back( word );

    word = new Word( "现在", "xiànzài" );
    word->translations["de"] = "jetzt, zur Zeit, gegenwärtig ";
    all_words_lesson.push_back( word );

    word = new Word( "坏", "huài" );
    word->translations["de"] = "schlecht, defekt, kaputt gegangen (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "响", "xiǎng" );
    word->translations["de"] = "ertönen, klingeln; spielen (Radio etc.) ";
    all_words_lesson.push_back( word );

    word = new Word( "毛病", "máobìng" );
    word->translations["de"] = "Defekt, Schaden, Mangel ";
    all_words_lesson.push_back( word );

    word = new Word( "自行车", "zìxíngchē" );
    word->translations["de"] = "Fahrrad ";
    all_words_lesson.push_back( word );

    word = new Word( "修理", "xiūlǐ" );
    word->translations["de"] = "reparieren ";
    all_words_lesson.push_back( word );

    word = new Word( "有一天", "yǒu yì tiān" );
    word->translations["de"] = "eines Tages ";
    all_words_lesson.push_back( word );

    word = new Word( "忽然", "hūrán" );
    word->translations["de"] = "unerwartet, plötzlich, auf einmal ";
    all_words_lesson.push_back( word );

    word = new Word( "有人", "yǒu rén" );
    word->translations["de"] = "jemand ";
    all_words_lesson.push_back( word );

    word = new Word( "年轻", "niánqīng" );
    word->translations["de"] = "jung, jugentlich (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "轻视", "qīngshì" );
    word->translations["de"] = "unterschätzen ";
    all_words_lesson.push_back( word );

    word = new Word( "对不起", "duìbuqǐ" );
    word->translations["de"] = "Entschuldigung!; Es tut mir leid! ";
    all_words_lesson.push_back( word );

    word = new Word( "从前", "cóngqián" );
    word->translations["de"] = "früher, ehemals, einst ";
    all_words_lesson.push_back( word );

    word = new Word( "小", "Xiǎo" );
    word->translations["de"] = "''Anredeform'' ";
    all_words_lesson.push_back( word );

    word = new Word( "好久不见了", "hǎo jiǔ bú jiàn le" );
    word->translations["de"] = "Lange nicht gesehen! ";
    all_words_lesson.push_back( word );

    word = new Word( "上学", "shàng xué" );
    word->translations["de"] = "zur Schule gehen, die Schule besuchen ";
    all_words_lesson.push_back( word );

    word = new Word( "那么", "nàme" );
    word->translations["de"] = "so, derartig, dermaßen ";
    all_words_lesson.push_back( word );

    word = new Word( "这么", "zhème" );
    word->translations["de"] = "so, derartig, dermaßen ";
    all_words_lesson.push_back( word );

    word = new Word( "完全", "wánquán" );
    word->translations["de"] = "ganz, völlig, vollkommen ";
    all_words_lesson.push_back( word );

    word = new Word( "老", "lǎo" );
    word->translations["de"] = "alt, betagt (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "老", "Lǎo" );
    word->translations["de"] = "''Anredeform'' ";
    all_words_lesson.push_back( word );

    word = new Word( "有时候", "yǒu shíhou" );
    word->translations["de"] = "manchmal, gelegentlich, hin und wieder ";
    all_words_lesson.push_back( word );

    word = new Word( "看", "kàn" );
    word->translations["de"] = "jn. besuchen (gehen) ";
    all_words_lesson.push_back( word );

    word = new Word( "结婚", "jié hūn" );
    word->translations["de"] = "heiraten, sich verheiraten ";
    all_words_lesson.push_back( word );

    word = new Word( "早", "zǎo" );
    word->translations["de"] = "längst, schon lange ";
    all_words_lesson.push_back( word );

    word = new Word( "大小", "dàxiǎo" );
    word->translations["de"] = "Größe, Ausmaß ";
    all_words_lesson.push_back( word );

    word = new Word( "轻重", "qīngzhòng" );
    word->translations["de"] = "Gewicht ";
    all_words_lesson.push_back( word );

    word = new Word( "重量", "zhòngliàng" );
    word->translations["de"] = "Gewicht ";
    all_words_lesson.push_back( word );

    word = new Word( "这儿", "zhèr" );
    word->translations["de"] = "hier ";
    all_words_lesson.push_back( word );

    word = new Word( "这里", "zhèlǐ" );
    word->translations["de"] = "hier ";
    all_words_lesson.push_back( word );

    word = new Word( "那儿", "nàr" );
    word->translations["de"] = "dort ";
    all_words_lesson.push_back( word );

    word = new Word( "那里", "nàlǐ" );
    word->translations["de"] = "dort ";
    all_words_lesson.push_back( word );

    word = new Word( "哪儿", "nǎr" );
    word->translations["de"] = "wo ";
    all_words_lesson.push_back( word );

    word = new Word( "哪里", "nǎlǐ" );
    word->translations["de"] = "wo ";
    all_words_lesson.push_back( word );

    word = new Word( "刘", "Liú" );
    word->translations["de"] = "Liu ";
    all_words_lesson.push_back( word );

    word = new Word( "一会儿", "yíhuìr" );
    word->translations["de"] = "ein Moment, ein Augenblick, eine kurze Weile ";
    all_words_lesson.push_back( word );

    word = new Word( "出门", "chū mén" );
    word->translations["de"] = "aus der Tür / aus dem Haus gehen ";
    all_words_lesson.push_back( word );

    word = new Word( "姑娘", "gūniang" );
    word->translations["de"] = "Mädchen, junge (unverheiratete Frau) ";
    all_words_lesson.push_back( word );

    word = new Word( "办公室", "bàngōngshì" );
    word->translations["de"] = "Büro ";
    all_words_lesson.push_back( word );

    word = new Word( "人们", "rénmen" );
    word->translations["de"] = "Leute; die Leute, man ";
    all_words_lesson.push_back( word );

    word = new Word( "毛衣", "máoyī" );
    word->translations["de"] = "(Woll-)Pullover ";
    all_words_lesson.push_back( word );

    word = new Word( "便宜", "piányi" );
    word->translations["de"] = "preisgünstig, billig (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "但是", "dànshì" );
    word->translations["de"] = "aber, jedoch ";
    all_words_lesson.push_back( word );

    word = new Word( "渴", "kě" );
    word->translations["de"] = "durstig (sein), Durst haben ";
    all_words_lesson.push_back( word );

    word = new Word( "商店", "shāngdiàn" );
    word->translations["de"] = "Laden, Geschäft ";
    all_words_lesson.push_back( word );

    word = new Word( "家", "jiā" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "书包", "shūbāo" );
    word->translations["de"] = "Schulmappe, Büchertasche ";
    all_words_lesson.push_back( word );

    word = new Word( "里", "lǐ" );
    word->translations["de"] = "innen, drinnen, in ";
    all_words_lesson.push_back( word );

    word = new Word( "外", "wài" );
    word->translations["de"] = "außen, draußen, außerhalb ";
    all_words_lesson.push_back( word );

    word = new Word( "上", "shàng" );
    word->translations["de"] = "oben, auf, über; in ";
    all_words_lesson.push_back( word );

    word = new Word( "下", "xià" );
    word->translations["de"] = "unter, unten ";
    all_words_lesson.push_back( word );

    word = new Word( "前", "qián" );
    word->translations["de"] = "vorn, vor ";
    all_words_lesson.push_back( word );

    word = new Word( "后", "hòu" );
    word->translations["de"] = "hinten, hinter ";
    all_words_lesson.push_back( word );

    word = new Word( "左", "zuǒ" );
    word->translations["de"] = "links ";
    all_words_lesson.push_back( word );

    word = new Word( "右", "yòu" );
    word->translations["de"] = "rechts ";
    all_words_lesson.push_back( word );

    word = new Word( "面", "mian" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "边", "bian" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "头", "tou" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "玩儿", "wànr" );
    word->translations["de"] = "spielen, sich vergnügen, sich die Zeit vertreiben; mit etw. spielen ";
    all_words_lesson.push_back( word );

    word = new Word( "汽车", "qìchē" );
    word->translations["de"] = "Auto ";
    all_words_lesson.push_back( word );

    word = new Word( "没了", "méi le" );
    word->translations["de"] = "weg, verschwunden sein ";
    all_words_lesson.push_back( word );

    word = new Word( "乱", "luàn" );
    word->translations["de"] = "durcheinander, unordentlich (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "乱七八糟", "luànqībāzāo" );
    word->translations["de"] = "großes Durcheinander, Riesenchaos ";
    all_words_lesson.push_back( word );

    word = new Word( "收拾", "shōushi" );
    word->translations["de"] = "''Zimmer'' aufräumen, ''Koffer'' packen ";
    all_words_lesson.push_back( word );

    word = new Word( "外国", "wàiguó" );
    word->translations["de"] = "Ausland ";
    all_words_lesson.push_back( word );

    word = new Word( "人民大学", "Rénmín Dàxué" );
    word->translations["de"] = "Volksuniversität (in Peking) ";
    all_words_lesson.push_back( word );

    word = new Word( "办公楼", "bàngōnglóu" );
    word->translations["de"] = "Verwaltungs-, Bürogebäude ";
    all_words_lesson.push_back( word );

    word = new Word( "条", "tiáo" );
    word->translations["de"] = "''Streifen'' ";
    all_words_lesson.push_back( word );

    word = new Word( "路", "lù" );
    word->translations["de"] = "Straße, Weg ";
    all_words_lesson.push_back( word );

    word = new Word( "邮局", "yóujú" );
    word->translations["de"] = "Postamt ";
    all_words_lesson.push_back( word );

    word = new Word( "雪", "xuě" );
    word->translations["de"] = "Schnee ";
    all_words_lesson.push_back( word );

    word = new Word( "下雪", "xiàxuě" );
    word->translations["de"] = "schneien ";
    all_words_lesson.push_back( word );

    word = new Word( "宿舍", "sùshè" );
    word->translations["de"] = "Wohnheim ";
    all_words_lesson.push_back( word );

    word = new Word( "点", "diǎn" );
    word->translations["de"] = "... Uhr ";
    all_words_lesson.push_back( word );

    word = new Word( "刻", "kè" );
    word->translations["de"] = "viertel vor .../nach ... ";
    all_words_lesson.push_back( word );

    word = new Word( "半", "bàn" );
    word->translations["de"] = "halb (vor/nach) ...; ... einhalb ";
    all_words_lesson.push_back( word );

    word = new Word( "分", "fēn" );
    word->translations["de"] = "x Minuten vor/nach ... ";
    all_words_lesson.push_back( word );

    word = new Word( "差", "chà" );
    word->translations["de"] = "fehlen; ... vor ... ";
    all_words_lesson.push_back( word );

    word = new Word( "钟", "zhōng" );
    word->translations["de"] = "... Uhr ";
    all_words_lesson.push_back( word );

    word = new Word( "时", "shí" );
    word->translations["de"] = "... Uhr ";
    all_words_lesson.push_back( word );

    word = new Word( "(手)表", "(shǒu)biǎo" );
    word->translations["de"] = "(Armband-)Uhr ";
    all_words_lesson.push_back( word );

    word = new Word( "新闻", "xīnwén" );
    word->translations["de"] = "Nachrichten, Neuigkeiten ";
    all_words_lesson.push_back( word );

    word = new Word( "部", "bù" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "电影", "diànyǐng" );
    word->translations["de"] = "Film ";
    all_words_lesson.push_back( word );

    word = new Word( "开始", "kāishǐ" );
    word->translations["de"] = "anfangen ";
    all_words_lesson.push_back( word );

    word = new Word( "开始", "kāishǐ" );
    word->translations["de"] = "beginnen etwas zu tun ";
    all_words_lesson.push_back( word );

    word = new Word( "晚", "wǎn" );
    word->translations["de"] = "spät (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "夜里", "yèli" );
    word->translations["de"] = "in der Nacht, nachts ";
    all_words_lesson.push_back( word );

    word = new Word( "早上", "zǎoshang" );
    word->translations["de"] = "der Morgen, morgens ";
    all_words_lesson.push_back( word );

    word = new Word( "起床", "qǐ chuáng" );
    word->translations["de"] = "aufstehen (das Bett verlassen) ";
    all_words_lesson.push_back( word );

    word = new Word( "早饭", "zǎofàn" );
    word->translations["de"] = "Frühstück ";
    all_words_lesson.push_back( word );

    word = new Word( "学校", "xuéxiào" );
    word->translations["de"] = "Schule; Oberbegriff für alle Bildungsanstalten ";
    all_words_lesson.push_back( word );

    word = new Word( "中饭", "zhōngfàn" );
    word->translations["de"] = "Mittagessen ";
    all_words_lesson.push_back( word );

    word = new Word( "晚饭", "wǎnfàn" );
    word->translations["de"] = "Abendessen ";
    all_words_lesson.push_back( word );

    word = new Word( "和", "hé" );
    word->translations["de"] = "mit ";
    all_words_lesson.push_back( word );

    word = new Word( "在", "zài" );
    word->translations["de"] = "in, an, auf etc. ";
    all_words_lesson.push_back( word );

    word = new Word( "从", "cóng" );
    word->translations["de"] = "von ... (aus) ";
    all_words_lesson.push_back( word );

    word = new Word( "到", "dào" );
    word->translations["de"] = "nach, zu, bis ";
    all_words_lesson.push_back( word );

    word = new Word( "从...到", "cóng ... dào" );
    word->translations["de"] = "von ... bis ";
    all_words_lesson.push_back( word );

    word = new Word( "邮票", "yóupiaò" );
    word->translations["de"] = "Briefmarke ";
    all_words_lesson.push_back( word );

    word = new Word( "旁边", "pángbiān" );
    word->translations["de"] = "neben, an der Seite ";
    all_words_lesson.push_back( word );

    word = new Word( "电影院", "diànyǐngyuàn" );
    word->translations["de"] = "Kino ";
    all_words_lesson.push_back( word );

    word = new Word( "放电影", "fàng diànyǐng" );
    word->translations["de"] = "einen Film zeigen, vorführen ";
    all_words_lesson.push_back( word );

    word = new Word( "整", "zhěng" );
    word->translations["de"] = "ganz, voll, (Uhrzeit:) Punkt ... ";
    all_words_lesson.push_back( word );

    word = new Word( "医院", "yīyuàn" );
    word->translations["de"] = "Krankenhaus ";
    all_words_lesson.push_back( word );

    word = new Word( "从早到晚", "cóng zǎo dào wǎn" );
    word->translations["de"] = "von morgens bis abends ";
    all_words_lesson.push_back( word );

    word = new Word( "管家", "guǎn jiā" );
    word->translations["de"] = "sich um Famile und Haushalt kümmern ";
    all_words_lesson.push_back( word );

    word = new Word( "...见", "jiàn" );
    word->translations["de"] = "Bis ... später, zum Abend, morgen! ";
    all_words_lesson.push_back( word );

    word = new Word( "旅游", "lǚyóu" );
    word->translations["de"] = "reisen, eine Urlaubsreise machen ";
    all_words_lesson.push_back( word );

    word = new Word( "另", "lìng" );
    word->translations["de"] = "der/die/das andere ";
    all_words_lesson.push_back( word );

    word = new Word( "一些", "yìxiē" );
    word->translations["de"] = "ein paar, einige ";
    all_words_lesson.push_back( word );

    word = new Word( "北京", "Běijīng" );
    word->translations["de"] = "Peking ";
    all_words_lesson.push_back( word );

    word = new Word( "漂亮", "piàoliang" );
    word->translations["de"] = "hübsch, schön, gutaussehend (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "不好意思", "bù hǎo yìsi" );
    word->translations["de"] = "verlegen, schüchtern, beschämt (sein) sich genieren/schämen, etw. zu tun ";
    all_words_lesson.push_back( word );

    word = new Word( "脸", "liǎn" );
    word->translations["de"] = "Gesicht ";
    all_words_lesson.push_back( word );

    word = new Word( "红", "hóng" );
    word->translations["de"] = "rot (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "怎么", "zěnme" );
    word->translations["de"] = "wie, auf welche Weise ";
    all_words_lesson.push_back( word );

    word = new Word( "坐", "zuò" );
    word->translations["de"] = "sitzen, sich setzen; fahren in/mit ";
    all_words_lesson.push_back( word );

    word = new Word( "坐", "zuò" );
    word->translations["de"] = "mit ... ''fahren: Bus, Flugzeug etc.'' ";
    all_words_lesson.push_back( word );

    word = new Word( "火车", "huǒchē" );
    word->translations["de"] = "Zug, Eisenbahn ";
    all_words_lesson.push_back( word );

    word = new Word( "飞机", "fēijī" );
    word->translations["de"] = "Flugzeug ";
    all_words_lesson.push_back( word );

    word = new Word( "柏林", "Bólín" );
    word->translations["de"] = "Berlin ";
    all_words_lesson.push_back( word );

    word = new Word( "要", "yào" );
    word->translations["de"] = "brauchen, benötigen, erfordern ";
    all_words_lesson.push_back( word );

    word = new Word( "上", "shàng" );
    word->translations["de"] = "einsteigen in ... ";
    all_words_lesson.push_back( word );

    word = new Word( "下", "xià" );
    word->translations["de"] = "aussteigen aus ... ";
    all_words_lesson.push_back( word );

    word = new Word( "开", "kāi" );
    word->translations["de"] = "fahren, lenken ";
    all_words_lesson.push_back( word );

    word = new Word( "开", "kāi" );
    word->translations["de"] = "mit ''dem Auto'' ";
    all_words_lesson.push_back( word );

    word = new Word( "骑", "qí" );
    word->translations["de"] = "fahren (''Rad, Moped''); reiten (''Pferd'') ";
    all_words_lesson.push_back( word );

    word = new Word( "骑", "qí" );
    word->translations["de"] = "mit ''dem Rad, dem Pferd'' ";
    all_words_lesson.push_back( word );

    word = new Word( "笔", "bǐ" );
    word->translations["de"] = "Schreibgerät, Stift ";
    all_words_lesson.push_back( word );

    word = new Word( "枝", "zhī" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "圆珠笔", "yuánzhūbǐ" );
    word->translations["de"] = "Kugelschreiber ";
    all_words_lesson.push_back( word );

    word = new Word( "用", "yòng" );
    word->translations["de"] = "etw. benutzen, gebrauchen ";
    all_words_lesson.push_back( word );

    word = new Word( "用", "yòng" );
    word->translations["de"] = "mit, mittels; auf ... (''Sprache'') ";
    all_words_lesson.push_back( word );

    word = new Word( "写", "xiě" );
    word->translations["de"] = "etw. schreiben ";
    all_words_lesson.push_back( word );

    word = new Word( "写字", "xiě zì" );
    word->translations["de"] = "schreiben ";
    all_words_lesson.push_back( word );

    word = new Word( "手", "shǒu" );
    word->translations["de"] = "Hand ";
    all_words_lesson.push_back( word );

    word = new Word( "双", "shuāng" );
    word->translations["de"] = "Paar ";
    all_words_lesson.push_back( word );

    word = new Word( "非常", "fēicháng" );
    word->translations["de"] = "außergewöhnlich, äußerst ";
    all_words_lesson.push_back( word );

    word = new Word( "毛笔", "máobǐ" );
    word->translations["de"] = "(Schreib-)Pinsel ";
    all_words_lesson.push_back( word );

    word = new Word( "是", "shì, shi" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "听说", "tīngshuō" );
    word->translations["de"] = "ich/wir habe/n gehört ..., vom Hörensagen wissen, dass ... ";
    all_words_lesson.push_back( word );

    word = new Word( "回来", "huílái" );
    word->translations["de"] = "zurückkommen, zurück sein ";
    all_words_lesson.push_back( word );

    word = new Word( "上海", "Shànghǎi" );
    word->translations["de"] = "Shanghai ";
    all_words_lesson.push_back( word );

    word = new Word( "天津", "Tiānjīn" );
    word->translations["de"] = "Tianjin ";
    all_words_lesson.push_back( word );

    word = new Word( "走路", "zǒu lù" );
    word->translations["de"] = "zu Fuß gehen ";
    all_words_lesson.push_back( word );

    word = new Word( "走路", "zǒu lù" );
    word->translations["de"] = "zu Fuß ";
    all_words_lesson.push_back( word );

    word = new Word( "时代", "shídài" );
    word->translations["de"] = "die Zeiten, Zeit, Epoche ";
    all_words_lesson.push_back( word );

    word = new Word( "变", "biàn" );
    word->translations["de"] = "sich ändern/verändern, sich wandeln ";
    all_words_lesson.push_back( word );

    word = new Word( "生活", "shēnghuó" );
    word->translations["de"] = "Leben, leben ";
    all_words_lesson.push_back( word );

    word = new Word( "操场", "cāochǎng" );
    word->translations["de"] = "Sportplatz ";
    all_words_lesson.push_back( word );

    word = new Word( "锻炼身体", "duànliàn shēntǐ" );
    word->translations["de"] = "Sport treiben, trainieren, sich Bewegung verschaffen ";
    all_words_lesson.push_back( word );

    word = new Word( "经理", "jīnglǐ" );
    word->translations["de"] = "Manager/in, Direktor/in ";
    all_words_lesson.push_back( word );

    word = new Word( "广州", "Guǎngzhōu" );
    word->translations["de"] = "Guangzhou, Kanton ";
    all_words_lesson.push_back( word );

    word = new Word( "订", "dìng" );
    word->translations["de"] = "etw. buchen, etw. abonnieren ";
    all_words_lesson.push_back( word );

    word = new Word( "票", "piào" );
    word->translations["de"] = "Ticket, Marke, Schein ";
    all_words_lesson.push_back( word );

    word = new Word( "起飞", "qǐfēi" );
    word->translations["de"] = "starten, abheben ";
    all_words_lesson.push_back( word );

    word = new Word( "开", "kāi" );
    word->translations["de"] = "abfahren (Zug) ";
    all_words_lesson.push_back( word );

    word = new Word( "公司", "gōngsī" );
    word->translations["de"] = "Firma, Unternehmen ";
    all_words_lesson.push_back( word );

    word = new Word( "请问", "qǐng wèn" );
    word->translations["de"] = "Gestatten Sie mir die Frage, ... ";
    all_words_lesson.push_back( word );

    word = new Word( "度假", "dù jià" );
    word->translations["de"] = "Urlaub machen, in den Urlaub fahren ";
    all_words_lesson.push_back( word );

    word = new Word( "病", "bìng" );
    word->translations["de"] = "erkranken; Krankheit ";
    all_words_lesson.push_back( word );

    word = new Word( "疼", "téng" );
    word->translations["de"] = "Schmerz ";
    all_words_lesson.push_back( word );

    word = new Word( "疗", "liáo" );
    word->translations["de"] = "heilen ";
    all_words_lesson.push_back( word );

    word = new Word( "了", "liǎo" );
    word->translations["de"] = "beenden ";
    all_words_lesson.push_back( word );

    word = new Word( "问题", "wèntí" );
    word->translations["de"] = "Frage, Problem ";
    all_words_lesson.push_back( word );

    word = new Word( "回答", "huídá" );
    word->translations["de"] = "Antwort; etw. beantworten ";
    all_words_lesson.push_back( word );

    word = new Word( "回答", "huídá" );
    word->translations["de"] = "antworten, dass... ";
    all_words_lesson.push_back( word );

    word = new Word( "啊", "a/ā" );
    word->translations["de"] = "ah, ach ";
    all_words_lesson.push_back( word );

    word = new Word( "昨天", "zuótiān" );
    word->translations["de"] = "der gestrige Tag, gestern ";
    all_words_lesson.push_back( word );

    word = new Word( "网球", "wǎngqiú" );
    word->translations["de"] = "Tennis ";
    all_words_lesson.push_back( word );

    word = new Word( "打", "dǎ" );
    word->translations["de"] = "''Tennis etc.'' spielen; jn. schlagen ";
    all_words_lesson.push_back( word );

    word = new Word( "词", "cí" );
    word->translations["de"] = "Wort ";
    all_words_lesson.push_back( word );

    word = new Word( "所以", "suǒyǐ" );
    word->translations["de"] = "deshalb, deswegen, darum ";
    all_words_lesson.push_back( word );

    word = new Word( "念", "niàn" );
    word->translations["de"] = "etw. vorlesen, laut lesen ";
    all_words_lesson.push_back( word );

    word = new Word( "过", "guò" );
    word->translations["de"] = "verbringen, absolvieren ";
    all_words_lesson.push_back( word );

    word = new Word( "念珠", "niànzhū" );
    word->translations["de"] = "Gebetskette, Rosenkranz ";
    all_words_lesson.push_back( word );

    word = new Word( "想念", "xiǎngniàn" );
    word->translations["de"] = "an jn. denken, vermissen ";
    all_words_lesson.push_back( word );

    word = new Word( "查词典", "chá cídiǎn" );
    word->translations["de"] = "im Wörterbuch nachschlagen/-sehen ";
    all_words_lesson.push_back( word );

    word = new Word( "办法", "bànfǎ" );
    word->translations["de"] = "Methode, Mittel, Weg ";
    all_words_lesson.push_back( word );

    word = new Word( "没办法", "méi bànfǎ" );
    word->translations["de"] = "Da kann man nichts machen. ";
    all_words_lesson.push_back( word );

    word = new Word( "有办法", "yǒu bànfǎ" );
    word->translations["de"] = "einen (Aus-)Weg wissen, Mittel und Wege finden ";
    all_words_lesson.push_back( word );

    word = new Word( "念书", "niàn shū" );
    word->translations["de"] = "lesen, lernen, studieren ";
    all_words_lesson.push_back( word );

    word = new Word( "了", "le" );
    word->translations["de"] = "''Verbalpartikel: Aspekt der Vollendung'' ";
    all_words_lesson.push_back( word );

    word = new Word( "可怜", "kělián" );
    word->translations["de"] = "mitleiderregend, kläglich (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "可怜", "kělián" );
    word->translations["de"] = "jn. bemitleiden, Mitleid haben mit jm. ";
    all_words_lesson.push_back( word );

    word = new Word( "后来", "hòulái" );
    word->translations["de"] = "später, dann, danach ";
    all_words_lesson.push_back( word );

    word = new Word( "棵", "kē" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "白菜", "báicài" );
    word->translations["de"] = "Chinakohl ";
    all_words_lesson.push_back( word );

    word = new Word( "斤", "jīn" );
    word->translations["de"] = "Pfund ";
    all_words_lesson.push_back( word );

    word = new Word( "土豆", "tǔdòu" );
    word->translations["de"] = "Kartoffeln ";
    all_words_lesson.push_back( word );

    word = new Word( "卖", "mài" );
    word->translations["de"] = "etw. verkaufen ";
    all_words_lesson.push_back( word );

    word = new Word( "鱼", "yú" );
    word->translations["de"] = "Fisch ";
    all_words_lesson.push_back( word );

    word = new Word( "新鲜", "xīnxiān" );
    word->translations["de"] = "frisch (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "鸡", "jī" );
    word->translations["de"] = "Huhn ";
    all_words_lesson.push_back( word );

    word = new Word( "车站", "chēzhàn" );
    word->translations["de"] = "(Bus-)Haltestelle ";
    all_words_lesson.push_back( word );

    word = new Word( "公共汽车", "gōnggòngqìchē" );
    word->translations["de"] = "Bus, Omnibus ";
    all_words_lesson.push_back( word );

    word = new Word( "麻烦", "máfàn(fan)" );
    word->translations["de"] = "umständlich, lästig, unangenehm (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "麻烦", "máfàn(fan)" );
    word->translations["de"] = "jn. belästigen, stören ";
    all_words_lesson.push_back( word );

    word = new Word( "方便", "fāngbiàn" );
    word->translations["de"] = "bequem, angenehm, günstig (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "门口", "ménkǒu" );
    word->translations["de"] = "Eingang ";
    all_words_lesson.push_back( word );

    word = new Word( "生气", "shēng qì" );
    word->translations["de"] = "wütend, ärgerlich, böse sein ";
    all_words_lesson.push_back( word );

    word = new Word( "要紧", "yàojǐn" );
    word->translations["de"] = "wichtig, dringlich (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "聊天", "liáo tiān" );
    word->translations["de"] = "sich unterhalten, plaudern ";
    all_words_lesson.push_back( word );

    word = new Word( "饭馆", "fànguǎn" );
    word->translations["de"] = "Restaurant ";
    all_words_lesson.push_back( word );

    word = new Word( "跳舞", "tiào wǔ" );
    word->translations["de"] = "tanzen ";
    all_words_lesson.push_back( word );

    word = new Word( "高兴", "gāoxìng" );
    word->translations["de"] = "froh, fröhlich, glücklich (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "听", "tīng" );
    word->translations["de"] = "etw. hören, anhören ";
    all_words_lesson.push_back( word );

    word = new Word( "前天", "qiántiān" );
    word->translations["de"] = "vorgestern ";
    all_words_lesson.push_back( word );

    word = new Word( "觉得", "juéde" );
    word->translations["de"] = "sich ... fühlen ";
    all_words_lesson.push_back( word );

    word = new Word( "觉得", "juéde" );
    word->translations["de"] = "meinen, finden ";
    all_words_lesson.push_back( word );

    word = new Word( "拿", "ná" );
    word->translations["de"] = "etw. holen, nehmen, halten ";
    all_words_lesson.push_back( word );

    word = new Word( "讲义", "jiǎnyì" );
    word->translations["de"] = "Unterrichtskopien ";
    all_words_lesson.push_back( word );

    word = new Word( "份", "fèn" );
    word->translations["de"] = "Satz, Ausgabe ";
    all_words_lesson.push_back( word );

    word = new Word( "这几天", "zhè jǐ tiān" );
    word->translations["de"] = "in diesen Tagen, in letzter Zeit ";
    all_words_lesson.push_back( word );

    word = new Word( "别的", "biéde" );
    word->translations["de"] = "anderes ";
    all_words_lesson.push_back( word );

    word = new Word( "周末", "zhōumò" );
    word->translations["de"] = "Wochenende ";
    all_words_lesson.push_back( word );

    word = new Word( "一定", "yídìng" );
    word->translations["de"] = "sicher, bestimmt, unbedingt ";
    all_words_lesson.push_back( word );

    word = new Word( "其他", "qítā" );
    word->translations["de"] = "andere/r/s, die übrigen, das übrige ";
    all_words_lesson.push_back( word );

    word = new Word( "举", "jǔ" );
    word->translations["de"] = "etw. heben, erheben ";
    all_words_lesson.push_back( word );

    word = new Word( "用法", "yòngfǎ" );
    word->translations["de"] = "Gebrauch, Anwendung(smöglichkeit) ";
    all_words_lesson.push_back( word );

    word = new Word( "动词", "dòngcí" );
    word->translations["de"] = "Verb ";
    all_words_lesson.push_back( word );

    word = new Word( "复杂", "fùzá" );
    word->translations["de"] = "kompliziert (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "糊涂", "hútu" );
    word->translations["de"] = "konfus, wirr, durcheinander, unklar (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "已经", "yǐjīng" );
    word->translations["de"] = "schon, bereits ";
    all_words_lesson.push_back( word );

    word = new Word( "关于", "guānyú" );
    word->translations["de"] = "über ..., zu ''ein/em Thema''<nowiki>; bezüglich</nowiki> ";
    all_words_lesson.push_back( word );

    word = new Word( "放心", "fàng xīn" );
    word->translations["de"] = "sich keine Sorgen machen, ruhig sein ";
    all_words_lesson.push_back( word );

    word = new Word( "会", "huì" );
    word->translations["de"] = "können, zu tun verstehen; möglich sein ";
    all_words_lesson.push_back( word );

    word = new Word( "能", "néng" );
    word->translations["de"] = "können, in der Lage sein, dürfen ";
    all_words_lesson.push_back( word );

    word = new Word( "熊", "xióng" );
    word->translations["de"] = "Bär ";
    all_words_lesson.push_back( word );

    word = new Word( "可以", "kěyǐ" );
    word->translations["de"] = "können, dürfen, erlaubt sein ";
    all_words_lesson.push_back( word );

    word = new Word( "得", "děi" );
    word->translations["de"] = "müssen ";
    all_words_lesson.push_back( word );

    word = new Word( "必须", "bìxū" );
    word->translations["de"] = "müssen ";
    all_words_lesson.push_back( word );

    word = new Word( "不必", "búbì" );
    word->translations["de"] = "nicht müssen, nicht brauchen ";
    all_words_lesson.push_back( word );

    word = new Word( "游泳", "yóuyǒng" );
    word->translations["de"] = "schwimmen ";
    all_words_lesson.push_back( word );

    word = new Word( "划船", "huá chuán" );
    word->translations["de"] = "(ein Boot) rudern ";
    all_words_lesson.push_back( word );

    word = new Word( "怕", "pà" );
    word->translations["de"] = "etw./jn. fürchten; Angst haben etw. zu tun ";
    all_words_lesson.push_back( word );

    word = new Word( "水", "shuǐ" );
    word->translations["de"] = "Wasser ";
    all_words_lesson.push_back( word );

    word = new Word( "黑", "hēi" );
    word->translations["de"] = "schwarz, dunkel, finster (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "下", "xià" );
    word->translations["de"] = "fallen ";
    all_words_lesson.push_back( word );

    word = new Word( "带", "dài" );
    word->translations["de"] = "etw. bei/mit sich tragen, mitbringen ";
    all_words_lesson.push_back( word );

    word = new Word( "雨伞", "yǔsǎn" );
    word->translations["de"] = "Regenschirm ";
    all_words_lesson.push_back( word );

    word = new Word( "听课", "tīng kè" );
    word->translations["de"] = "hospitieren, am Unterricht teilnehmen; eine Vorlesung hören ";
    all_words_lesson.push_back( word );

    word = new Word( "打算", "dǎsuàn" );
    word->translations["de"] = "vorhaben, planen zu tun ";
    all_words_lesson.push_back( word );

    word = new Word( "打算", "dǎsuàn" );
    word->translations["de"] = "Absicht, Vorhaben ";
    all_words_lesson.push_back( word );

    word = new Word( "实习", "shíxí" );
    word->translations["de"] = "ein Praktikum machen, Praktikum ";
    all_words_lesson.push_back( word );

    word = new Word( "故事", "gùshi" );
    word->translations["de"] = "Geschichte, Erzählung ";
    all_words_lesson.push_back( word );

    word = new Word( "当", "dāng" );
    word->translations["de"] = "als ... tätig sein ";
    all_words_lesson.push_back( word );

    word = new Word( "生", "shēng" );
    word->translations["de"] = "(er)zeugen, produzieren, gebären ";
    all_words_lesson.push_back( word );

    word = new Word( "抽烟", "chōu yān" );
    word->translations["de"] = "rauchen ";
    all_words_lesson.push_back( word );

    word = new Word( "酒", "jiǔ" );
    word->translations["de"] = "Alkohol, alkoholische Getränke ";
    all_words_lesson.push_back( word );

    word = new Word( "武术", "wǔshù" );
    word->translations["de"] = "Kampfkunst ";
    all_words_lesson.push_back( word );

    word = new Word( "太极", "Tàijí" );
    word->translations["de"] = "Taiji (Daoismus: Prinzip der Einheit von Yin und Yang, Licht und Schatten am Gipfel des Berges) ";
    all_words_lesson.push_back( word );

    word = new Word( "阴阳", "Yīn Yáng" );
    word->translations["de"] = "Yin und Yang (Daoismus: Berg der einseitig von der Sonne beschienen wird und jenseitig im Schatten liegt) ";
    all_words_lesson.push_back( word );

    word = new Word( "太极拳", "Tàijíquán" );
    word->translations["de"] = "Taijiquan, meditatives Schattenboxen ";
    all_words_lesson.push_back( word );

    word = new Word( "太极图", "Tàijì tú" );
    word->translations["de"] = "Taiji-Symbol, Monade ";
    all_words_lesson.push_back( word );

    word = new Word( "气", "Qì" );
    word->translations["de"] = "Gas, Luft, Atem; Qi ";
    all_words_lesson.push_back( word );

    word = new Word( "道教", "Dàojiào" );
    word->translations["de"] = "Daoismus, \"Lehre des Weges\" ";
    all_words_lesson.push_back( word );

    word = new Word( "道", "dào" );
    word->translations["de"] = "Weg, Pfad; sprechen; Dao (Ursprung und alles durchdringendes Prinzip des Universums, Quelle von Yin und Yang) ";
    all_words_lesson.push_back( word );

    word = new Word( "万物", "wànwù" );
    word->translations["de"] = "Alles auf der Welt, \"Zehntausend Dinge\" ";
    all_words_lesson.push_back( word );

    word = new Word( "老子", "Lǎozi" );
    word->translations["de"] = "Laozi (Laotse), legendärer chinesischer Philosoph, der im 6. Jahrhundert v. Chr. gelebt haben soll, Begründer des Daoismus ";
    all_words_lesson.push_back( word );

    word = new Word( "道德经", "Dàodéjīng" );
    word->translations["de"] = " ";
    all_words_lesson.push_back( word );

    word = new Word( "想", "xiǎng" );
    word->translations["de"] = "wollen, mögen, wünschen ";
    all_words_lesson.push_back( word );

    word = new Word( "要", "yào" );
    word->translations["de"] = "wollen, sollen ";
    all_words_lesson.push_back( word );

    word = new Word( "不用", "búyòng" );
    word->translations["de"] = "nicht zu tun brauchen ";
    all_words_lesson.push_back( word );

    word = new Word( "愿意", "yuànyì" );
    word->translations["de"] = "bereit/willig sein; gern tun, mögen ";
    all_words_lesson.push_back( word );

    word = new Word( "留学", "liúxué" );
    word->translations["de"] = "im Ausland studieren ";
    all_words_lesson.push_back( word );

    word = new Word( "外办", "wàibàn" );
    word->translations["de"] = "Büro für Auswärtiges ";
    all_words_lesson.push_back( word );

    word = new Word( "主任", "zhǔrèn" );
    word->translations["de"] = "Leiter/in, Direktor/in ";
    all_words_lesson.push_back( word );

    word = new Word( "办", "bàn" );
    word->translations["de"] = "etw. erledigen, ausführen ";
    all_words_lesson.push_back( word );

    word = new Word( "手续", "shǒuxù" );
    word->translations["de"] = "Formalitäten ";
    all_words_lesson.push_back( word );

    word = new Word( "重要", "zhòngyào" );
    word->translations["de"] = "wichtig, bedeutend (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "留学生", "liúxuéshēng" );
    word->translations["de"] = "im Ausland Studierende/r ";
    all_words_lesson.push_back( word );

    word = new Word( "宿舍", "sùshè" );
    word->translations["de"] = "Wohnheim ";
    all_words_lesson.push_back( word );

    word = new Word( "服务台", "fúwùtái" );
    word->translations["de"] = "Rezeption, Etagendienst ";
    all_words_lesson.push_back( word );

    word = new Word( "行李", "xíngli" );
    word->translations["de"] = "Gepäck ";
    all_words_lesson.push_back( word );

    word = new Word( "名字", "míngzi" );
    word->translations["de"] = "Name ''(von Personen, Filmen, etc)'' ";
    all_words_lesson.push_back( word );

    word = new Word( "楼上", "lóushàng" );
    word->translations["de"] = "obere Etage/n, eine Treppe höher ";
    all_words_lesson.push_back( word );

    word = new Word( "住", "zhù" );
    word->translations["de"] = "wohnen; etw. bewohnen, wohnen in ";
    all_words_lesson.push_back( word );

    word = new Word( "同屋", "tóngwū" );
    word->translations["de"] = "Mitbewohner/in ";
    all_words_lesson.push_back( word );

    word = new Word( "这样", "zhè(i)yàng" );
    word->translations["de"] = "so, solcherart, auf diese Weise ";
    all_words_lesson.push_back( word );

    word = new Word( "不用谢", "búyòng xiè" );
    word->translations["de"] = "Nichts zu danken! ";
    all_words_lesson.push_back( word );

    word = new Word( "办事", "bàn shì" );
    word->translations["de"] = "etw. tun, erledigen ";
    all_words_lesson.push_back( word );

    word = new Word( "楼下", "lóuxià" );
    word->translations["de"] = "eine/ein paar Etagen tiefer, unten im Haus ";
    all_words_lesson.push_back( word );

    word = new Word( "地", "de" );
    word->translations["de"] = "''Adverbialpartikel'' ";
    all_words_lesson.push_back( word );

    word = new Word( "站", "zhàn" );
    word->translations["de"] = "＋在 stehen an, bei, ''Lokalobjekt'' ";
    all_words_lesson.push_back( word );

    word = new Word( "十字路口", "shízìlùkǒu" );
    word->translations["de"] = "(Straßen-)Kreuzung ";
    all_words_lesson.push_back( word );

    word = new Word( "马路", "mǎlù" );
    word->translations["de"] = "Straße ";
    all_words_lesson.push_back( word );

    word = new Word( "过马路", "guò mǎlù" );
    word->translations["de"] = "die Straße überqueren ";
    all_words_lesson.push_back( word );

    word = new Word( "过去", "guòqu" );
    word->translations["de"] = "hinüber-, vorbeigehen, überqueren ";
    all_words_lesson.push_back( word );

    word = new Word( "声", "shēng" );
    word->translations["de"] = "Geräusch, Laut, Ton; Stimme ";
    all_words_lesson.push_back( word );

    word = new Word( "小心", "xiǎxīn" );
    word->translations["de"] = "vorsichtig sorgfältig (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "随便", "suíbiàn" );
    word->translations["de"] = "ungezwungen (sein), nach Belieben; unbesonnen, unüberlegt (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "跑", "pǎo" );
    word->translations["de"] = "laufen, rennen; gehen, fahren nach ";
    all_words_lesson.push_back( word );

    word = new Word( "听话", "tīng huà" );
    word->translations["de"] = "auf jn. hören, hm. gehorchen, folgsam (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "忘", "wàng" );
    word->translations["de"] = "etw. vergessen, vergessen etw. zu tun ";
    all_words_lesson.push_back( word );

    word = new Word( "危险", "wēixiǎn" );
    word->translations["de"] = "gefährlich (sein); Gefahr ";
    all_words_lesson.push_back( word );

    word = new Word( "灯", "dēng" );
    word->translations["de"] = "Lampe ";
    all_words_lesson.push_back( word );

    word = new Word( "盏", "zhǎn" );
    word->translations["de"] = "(kleine Tasse?) ";
    all_words_lesson.push_back( word );

    word = new Word( "绿", "lǜ" );
    word->translations["de"] = "grün (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "老大", "lǎodà" );
    word->translations["de"] = "der/die Älteste in einer Geschwisterreihe ";
    all_words_lesson.push_back( word );

    word = new Word( "考试", "kǎoshì" );
    word->translations["de"] = "Prüfung haben/abhalten, einen Test schreiben; Prüfung, Test ";
    all_words_lesson.push_back( word );

    word = new Word( "门", "mén" );
    word->translations["de"] = "(Tor) ";
    all_words_lesson.push_back( word );

    word = new Word( "因为", "yīnwèi" );
    word->translations["de"] = "weil, da ";
    all_words_lesson.push_back( word );

    word = new Word( "电梯", "diàntī" );
    word->translations["de"] = "Fahrstuhl ";
    all_words_lesson.push_back( word );

    word = new Word( "大衣", "dàyī" );
    word->translations["de"] = "Mantel ";
    all_words_lesson.push_back( word );

    word = new Word( "薄", "báo, bó" );
    word->translations["de"] = "dünn (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "边", "biān" );
    word->translations["de"] = "Seite, Rand, Kante ";
    all_words_lesson.push_back( word );

    word = new Word( "北大", "Běidà" );
    word->translations["de"] = "Peking-Universität ";
    all_words_lesson.push_back( word );

    word = new Word( "城里", "chénglǐ" );
    word->translations["de"] = "Innenstadt, in der Stadt ";
    all_words_lesson.push_back( word );

    word = new Word( "同事", "tóngshì" );
    word->translations["de"] = "Arbeitskollege, -kollegin ";
    all_words_lesson.push_back( word );

    word = new Word( "可是", "kěshì" );
    word->translations["de"] = "aber ";
    all_words_lesson.push_back( word );

    word = new Word( "一般", "yìbān" );
    word->translations["de"] = "gewöhnlich, üblich, normalerwese; mittelmäßig, nichts Besonderes (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "附近", "fùjìn" );
    word->translations["de"] = "in der Nähe, nahebei ";
    all_words_lesson.push_back( word );

    word = new Word( "看见", "kànjiàn" );
    word->translations["de"] = "jn./etw. sehen, erblicken ";
    all_words_lesson.push_back( word );

    word = new Word( "父亲", "fùqīn(qin)" );
    word->translations["de"] = "Vater ";
    all_words_lesson.push_back( word );

    word = new Word( "见面", "jiànmiàn" );
    word->translations["de"] = "sich treffen, sich sehen ";
    all_words_lesson.push_back( word );

    word = new Word( "母亲", "mǔqīn(qin)" );
    word->translations["de"] = "Mutter ";
    all_words_lesson.push_back( word );

    word = new Word( "干", "gàn" );
    word->translations["de"] = "etw. tun, machen ";
    all_words_lesson.push_back( word );

    word = new Word( "重", "zhòng" );
    word->translations["de"] = "schwer, gewichtig (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "父母", "fùmǔ" );
    word->translations["de"] = "Eltern ";
    all_words_lesson.push_back( word );

    word = new Word( "猜", "cāi" );
    word->translations["de"] = "vermuten, raten, (dass ...) ";
    all_words_lesson.push_back( word );

    word = new Word( "长大", "zhǎngdà" );
    word->translations["de"] = "aufwachsen, heranwachsen ";
    all_words_lesson.push_back( word );

    word = new Word( "黑板", "hēibǎn" );
    word->translations["de"] = "Wandtafel ";
    all_words_lesson.push_back( word );

    word = new Word( "美", "měi" );
    word->translations["de"] = "schön, hübsch (sein) ";
    all_words_lesson.push_back( word );

    word = new Word( "草书", "cǎoshū" );
    word->translations["de"] = "kursorische Schnellschrift, Grasschrift ";
    all_words_lesson.push_back( word );

    word = new Word( "可惜", "kěxī" );
    word->translations["de"] = "leider, bedauerlich; schade, (dass ...) ";
    all_words_lesson.push_back( word );

    word = new Word( "擦", "cā" );
    word->translations["de"] = "etw. reiben, (ab-, trocken-)wischen ";
    all_words_lesson.push_back( word );

}

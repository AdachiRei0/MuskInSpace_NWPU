#ifndef HELP_HPP
#define HELP_HPP

#include "../config.hpp"
#include "../platform/platform.hpp"

bool ShowHelp(){
    cls_printf("\n\n\n\t======== HELP ========\n"
               "\tWelcome to Musk In Space!\n\n"
               "\tGame Instructions:\n"
               "\t1. Use the UP arrow key to accelerate upwards.\n"
               "\t2. Use the DOWN arrow key to maintain a constant speed.\n"
               "\t3. Use the RIGHT arrow key to perform a backflip.\n"
               "\t4. Avoid space debris and navigate your spaceship safely back to the atmosphere.\n\n"
               "\tObjective:\n"
               "\tSuccessfully return to the atmosphere while avoiding obstacles.\n\n"
               "\tGood luck, and may the stars guide you home!\n"
               "\t======= MUSIC =======\n"
               "\t1.\n"
                "\tbgm in main menu: (no name)\n"
                "\tsource:https://www.bilibili.com/video/BV1Bs411C7Lh?spm_id_from=333.788.videopod.episodes&vd_source=04b014652439b6a198699f29431abe4f&p=21\n"
                "\t2.\n"
                "\tbgm in game: 《封印都市》\n"
                "\tsource:アニメ「planetarian」Original SoundTrack / MELL;佐咲紗花;Lia;Ceui;北沢綾香、音樂:Charles Crozat Converse、折戸伸治、竹下智博、どんまる、宮沢賢\t治、水月陵、折戸伸治、須原杏、雨宮麻未子、三品芽生、しょうゆ、森藤晶司 (2disc)[161026][-]\n"
                "\t3.\n"
                "\tbgm in origin:《Seraph of the End - Prologue》\n"
                "\tsource:TVアニメ『終わりのセラフ』オリジナルサウンドトラック\\キーボードフェースローラーと三人の仲間たち / 音樂：澤野弘之;小林未郁&mpi;和田貴史;橘麻美\t;白石めぐみ、Gemie;Yosh(Survive Said The Prophet) (2disc)[150715]\n");
//    GetchAfterFlush();
    PF__getch();
    return true;
}

#endif
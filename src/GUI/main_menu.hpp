#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "../platform/platform.hpp"
#include "../config.hpp"
#include "../tools.hpp"

menu_t ShowMenu(){
    char cursor1[] = "  ";
    char cursor2[] = "  ";
    char cursor3[] = "  ";
    char cursor4[] = "  ";
    char cursor5[] = "  ";
    menu_t choice = START_GAME;
    char ch;
    while (true) {
        cursor1[0] = (choice == START_GAME) ? '=' : ' ';
        cursor1[1] = (choice == START_GAME) ? '>' : ' ';
        cursor2[0] = (choice == HELP) ? '=' : ' ';
        cursor2[1] = (choice == HELP ) ? '>' : ' ';
        cursor3[0] = (choice == SCOREBOARD) ? '=' : ' ';
        cursor3[1] = (choice == SCOREBOARD) ? '>' : ' ';
        cursor4[0] = (choice == SETTINGS) ? '=' : ' ';
        cursor4[1] = (choice == SETTINGS) ? '>' : ' ';
        cursor5[0] = (choice == EXIT) ? '=' : ' ';
        cursor5[1] = (choice == EXIT) ? '>' : ' ';
        cls_printf("\n\n\n         .         .            .\n"
                "          .      .   .       .\n"
                "            .               .\n"             
                "       .          .     .           .\n"
                "                .    .        .        .\n" 
                "    .        *           .        .          .\n"
                "          .    .     *     .            .\n"
                "       .               .       *     .      .\n"
                "    .     .   .          .        .       .\n"
                "        .         .     *    .      *    .\n"
                "      .      .    .           .   .    .\n"
            "\n\t======== MAIN MENU ========\n"
               "\t%s 1. Start Game\n"
               "\t%s 2. Help\n"
               "\t%s 3. Scoreboard\n"
               "\t%s 4. Settings\n"
               "\t%s 5. Exit\n"
               "\t===========================\n"
               "\tPlease use UP/DOWN arrow keys to move,\n",
               cursor1, cursor2, cursor3, cursor4, cursor5);
        ch = PF_getch();
        if (ch == KEY_UP) {
            choice--;
            if (choice < 1) choice = 5;
        } else if (ch == KEY_DOWN) {
            choice++;
            if (choice > 5) choice = 1;
        } else if (ch == '\r' || ch == '\n') {
            break;
        }
        PF_Sleep(SLEEP_TIME);
        PF_system_cls();
    }
    return choice;
}

#endif
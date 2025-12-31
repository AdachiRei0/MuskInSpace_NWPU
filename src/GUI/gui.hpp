#ifndef GUI_HPP
#define GUI_HPP

#include "../game.hpp"
#include "boot.hpp"
#include "help.hpp"
#include "main_menu.hpp"
#include "plot.hpp"
#include "scoreboard.hpp"
#include "settings.hpp"

void CallStartMenu();
void ShowBootLogo(int);
void ShowBootBG(int);
void ShowPlot();
void GetchAfterFlush();
menu_t ShowMenu();
menu_t EnterMainMenu();
menu_t EnterStartGame();
menu_t EnterHelp();
menu_t EnterScoreboard();
menu_t EnterSettings();
menu_t EnterExit();
void GoodBye();

menu_t (*MenuFunctions[])() = {
    EnterMainMenu,
    EnterStartGame,
    EnterHelp,
    EnterScoreboard,
    EnterSettings,
    EnterExit
}; 

void CallStartMenu(){
    PF_SetConsoleOutputCP(65001);
    SetConsoleFullscreen();
    HideCursor();
    PF_system_cls();
    ShowBootLogo(WORDS_MOVE_TIME);
    PF_system_cls();
    ShowBootBG(WORDS_MOVE_TIME);
    PF_system_cls();
    return;
}

menu_t EnterMainMenu(){
    PF_MusicPlay("../music/mainmenu.wav");    // play music
    menu_t choice = ShowMenu();
    return choice;
}
menu_t EnterStartGame(){
    PF_MusicPlay("../music/startgame.wav");   // play music
    bool restart = false;
    ShowPlot();         // show plot
    PF_system_cls();
    restart = system();
    return restart ? START_GAME : MAIN_MENU;
}
menu_t EnterHelp(){
    bool reback = false;
    while (true) {
    reback = ShowHelp();
    if (reback == true){
        break;
    }
    }
    return MAIN_MENU;
}
menu_t EnterScoreboard(){
    bool reback = false;
    while (true) {
    reback = ShowEnterScoreboard();
    if (reback == true){
        break;
    }
    }
    return MAIN_MENU;
}
menu_t EnterSettings(){
    bool reback = false;
    while (true) {
    reback = ShowSettings();
    if (reback == true){
        break;
    }
    }
    return MAIN_MENU;
}
menu_t EnterExit(){
    return 0;
}

void GoodBye(){
    cls_printf("\n\n\n\tThank you for playing MUSK IN SPACE!\n\n\n");
    Sleep(THANK_TIME);
    PF_system_cls();
    return;
}

#endif
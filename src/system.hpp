#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "game.hpp"

int system() {
    player P;
    screen Screen;
    timer Timer;
     
    Setup(&P, &Screen, &Timer);      // init game
    while ((!gameOver) && (!gameWin)) {
        Draw(&P, &Screen);   // draw screen
        Input(&P);  // process player's input
        Logic(&P, &Screen);  // flesh and judge game condition
        AutoSleep(&Timer);  // automately judge time whether if need to sleep
    }
    End(&P);       // process after game over
    
    return 0;
}

#endif
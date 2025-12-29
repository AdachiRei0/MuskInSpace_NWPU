#ifndef GAME_HPP
#define GAME_HPP

#include "config.hpp"
#include "screen.hpp"
#include "player.hpp"
#include "timer.hpp"
#include "platform/platform.hpp"
#include "tools.hpp"

IMPORT_SCREEN_HPP
IMPORT_PLAYER_HPP
IMPORT_TIMER_HPP


void Setup(player*, screen*, timer*);
void GenerateObstacle();
void Draw(player*, screen*);
void Input(player*);
void Logic(player*, screen*);
void AutoSleep(timer*);
void HideCursor();
void SetConsoleFullscreen();
bool End(player*);


void Setup(player *P, screen *Screen, timer *Timer){
    gameOver = FALSE;
    gameWin = FALSE;
    P->PlayerInit(&P->mem);
    Screen->ScreenInit(&Screen->mem);
    Timer->TimerInit(&Timer->mem);
    printf("Generating Space Debris......\n");

    // generate random obstacle file
    GenerateObstacle();
    PF_system_cls();
//    Sleep(READY_TIME);
    return;
}

// generate random obstacle file
void GenerateObstacle(){;
    FILE *fp;
    int buffer[BOUND] = {F_SPACE};
    if((fp = fopen("../data/random_data.txt", "w+")) == NULL){
        printf("file open error!\n");
        return;
    }
    srand((unsigned)time(NULL));
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        buffer[i] = F_SPACE;
    }
    for(int i = WIDTH * HEIGHT; i < MAP_BOUND; i++){
        buffer[i] = !(rand()%F);
    }
    for(int i = MAP_BOUND; i < MAP_BOUND + WIDTH; i++){
        buffer[i] = F_END;      // end flag
    }
    for(int i = MAP_BOUND + WIDTH; i < BOUND; i++){
        buffer[i] = F_SPACE;
    }
    for(int i = 0; i < BOUND; i++){
        fprintf(fp, "%d", buffer[i]);
    }
    if(fclose(fp) != 0){
        printf("file close error!\n");
        return;
    }
    return;
};

void Draw(player *P, screen *Screen){
    int i = 0, j = 0, k = 0;
    Screen->FlashObstacle(&Screen->mem);        // flash obstacle from file
    PF_system_cls();          // clean screen
    Screen->FillScreen(&Screen->mem, (int)P->mem.y);
    Screen->ScreenDisplay(&Screen->mem);
    printf("\nAvoid those space debris!!!\n");        
    printf("%d km away from the atmosphere\n",WIN_CONDITION - P->mem.score);        // display score and usage
    printf("pos = %d\n", Screen->mem.obstacle_pos);         // debug info
    printf("press W or up-direction key to jump, X to quit\n");
    return;
}

void Input(player *P){
    if (PF__kbhit()){
        switch (PF__getch())
        {
        case 'w':
        case 'W':
        case KEY_UP:        // up-direction key
            if (P->mem.movement != JUMP){
                P->mem.movement = JUMP;
            }
            break;
        case 'S':
        case 's':
        case KEY_DOWN:    // down-direction key
            if (P->mem.movement != STOP){
                P->mem.movement = STOP;
            }    
            break;
        }
    }
    return;
}

void Logic(player *P, screen *Screen){
    double prevY = P->mem.y;
    double prevV = P->mem.v;
    double newY, newV;

    if (P->mem.movement == JUMP){       // flash player's speed
        newV = prevV + GA + JA;
        P->mem.movement = NONS;
    } else if (P->mem.movement == STOP){
        newV = INITIAL_SPEED;
        P->mem.movement = NONS;
    } else {
        newV = prevV + GA;
    }

    newY = prevY + newV;        // flash player's height

    P->mem.v = newV;
    P->mem.y = newY;

    if(P->mem.y <= 0 || P->mem.y >= HEIGHT || Screen->mem.obstacle_hashtable[(int)P->mem.y][INITIAL_WIDTH] == '1'){
        gameOver = TRUE;
        gameWin = FALSE;
    }

    if(P->mem.score >= WIN_CONDITION){
        gameOver = FALSE;
        gameWin = TRUE;
    }

    P->mem.score++;
    return;
}

void AutoSleep(timer *Timer){
    Timer->FlashRTS(&Timer->mem);         // flash Real Time Stemp
    if(Timer->GetTimeGap(&Timer->mem) < 0){   // if program time is less than real time, sleep to wait program time
        PF_Sleep(SLEEP_TIME); // control game pace
        Timer->mem.PTS += SLEEP_TIME;    // flash Program Time Stemp
    }
    return;
}

bool End(player *P){
    char key = 0;       // get player's pressed key
    P->mem.score--;         // descend score because of death
    if(gameOver){
        printf("\ngame over! score: %d\n", P->mem.score);
    } else if(gameWin) {
        printf("\nyou are win!\n");
    }
    printf("press 'q' to quit, \nand 'r' to return start menu...");
    while((key = PF_getch()) != 'q'){
        if(key == 'r'){
//            SetConsoleFullscreen();
            PF_system_cls();
//            main();
            return true;
        }
        continue;
    }
    return false;
}

#endif
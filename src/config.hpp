#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tools.hpp"

#define WIDTH 120       // width of screen
#define HEIGHT 40       // height of screen
#define INITIAL_WIDTH 60    // initial position of player
#define INITIAL_HEIGHT 20   // initial height of player
#define INITIAL_SCORE 0     // initial score
#define INITIAL_SPEED 0     // initial speed
#define INITIAL_H 20        // initial height of player
#define WIN_CONDITION 1000      // score to win
#define READY_TIME 5000     // time before game starts
#define WORDS_MOVE_TIME 400     // time of words moving
#define F 2000       // frequency of obstacle appearance
#define BOUND 150000    // boundary of obstacle file
#define MAP_BOUND ((WIDTH + 1) * WIN_CONDITION)    // boundary of obstacle file
#define SLEEP_TIME 5    // time of each frame
#define PRESS_TIME 100      // time of pressing key
#define TRUE 1          // boolean values
#define FALSE 0
#define F_SPACE 0           // types of obstacle file
#define F_OBSTACLE 1
#define F_END 2
#define B_SPACE '0'      // types of obstacle in hashtable
#define B_OBSTACLE '1'
#define B_END '2'
#define NONS 0      // conditions of player's movement
#define JUMP 1
#define STOP 2
#define GA 0.005    // gravitational acceleration
#define JA -0.05        // jump acceleration

int gameOver = FALSE;       // global game condition
int gameWin = FALSE;

#endif
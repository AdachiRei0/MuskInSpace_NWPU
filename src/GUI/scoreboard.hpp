#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#define RANK "../data/rank.txt"
#define BOARD "../data/scoreboard.txt"
#define NUM "../data/num.txt"
#define RANK_ENTRY "%s %d %d %d %d %d %d"
#define S_BUFFER_ENTRY(i) buffer[i]->name, &buffer[i]->time.y, &buffer[i]->time.m, &buffer[i]->time.d, &buffer[i]->time.h, &buffer[i]->time.min, &buffer[i]->score
#define P_BUFFER_ENTRY(i) buffer[i]->name, buffer[i]->time.y, buffer[i]->time.m, buffer[i]->time.d, buffer[i]->time.h, buffer[i]->time.min, buffer[i]->score
#define RANK_BOUND 300
#define SHOW_BOUND 30

#include "../platform/platform.hpp"
#include "../tools.hpp"

typedef struct 
{
    char name[16];
    struct {int y; int m; int d; int h; int min;} time;
    int score;
} Rank;

void RankSwap(Rank *a, Rank *b){;}

int RankSort(){
    int num = 0;
    FILE *rank;
    FILE *board;
    FILE *num_file;
    Rank *buffer[300];
    if ((rank = fopen(RANK, "r")) == NULL) {
        cls_printf("\n\n\n\tCan't open Scorebroard!\nrank.txt");
        PF_Sleep(ERROR_TIME);
        goto done;
    } 


    if ((num_file = fopen(NUM, "r")) == NULL){
        cls_printf("\n\n\n\tCan't open Scorebroard!\nnum.txt");
        PF_Sleep(ERROR_TIME);
        goto done;
    }
    if (fscanf(num_file, "%d", &num) == 0){
        cls_printf("\n\n\n\tCan't read data!");
        PF_Sleep(ERROR_TIME);
        goto done;
    }
    if (fclose(num_file)){
        cls_printf("\n\n\n\tCan't close Scoreboard!");
        PF_Sleep(ERROR_TIME);
        goto done;
    }


    if (num == 0){
        cls_printf("\n\n\n\tNone winned yet!");
        PF_Sleep(ERROR_TIME);
        goto done;
    } else {
        int i = 0, j = 0, k = 0, pos = 0;
        Rank *tmp = NULL;
        for (i = 0; i < MIN(RANK_BOUND, num); i++){
            buffer[i] = (Rank*)malloc(sizeof(Rank));
                if (buffer[i] == NULL) {
                cls_printf("\n\n\n\t内存分配失败!");
                PF_Sleep(ERROR_TIME);
                goto free;
            }
            fscanf(rank, RANK_ENTRY, S_BUFFER_ENTRY(i));
        }

        if ((board = fopen(BOARD, "w")) == NULL){
            cls_printf("\n\n\n\tCan't open Scorebroard!\nboard.txt");
            PF_Sleep(ERROR_TIME);
            goto free;
        }

        for (j = 0; j < MIN(SHOW_BOUND, num); j++) {
            pos = j;
            for (k = pos; k < MIN(SHOW_BOUND, num); k++){
                if (buffer[k]->score > buffer[pos]->score){
                    pos = k;
                }
            }
            tmp = buffer[pos];
            buffer[pos] = buffer[j];
            buffer[j] = tmp;
        }

        for (j = 0; j < MIN(SHOW_BOUND, num); j++){
            fprintf(board, "  " RANK_ENTRY " \n", P_BUFFER_ENTRY(j));
        }

        if (fclose(board)) {
            cls_printf("\n\n\n\tCan't close Scoreboard!");
            PF_Sleep(ERROR_TIME);
            goto free;
        }
        free:
        for (i = 0; i < MIN(RANK_BOUND, num); i++) {
            free(buffer[i]);
        }
    }

    if (fclose(rank)) {
        cls_printf("\n\n\n\tCan't close Scoreboard!");
        PF_Sleep(ERROR_TIME);
        goto done;
    }

    done:
    return MIN(SHOW_BOUND, num);
}

bool ShowEnterScoreboard(){
    PF_system_cls();
    FILE *board;
    Rank tmp;
    int bound = RankSort();     // bound of num of showed entrys
    int i = 0;
    if ((board = fopen(BOARD, "r")) == NULL) {
        cls_printf("\n\n\n\tCan't open Scorebroard!\nboard.txt");
        PF_Sleep(ERROR_TIME);
        goto done;
    }
    printf("\n\n\n%16s|%16s|%7s\n", "name", "win time", "scores" );
    for (i = 0; i < bound; i++){
        fscanf(board, "%s%d%d%d%d%d%d", tmp.name, &tmp.time.y, &tmp.time.m, &tmp.time.d, &tmp.time.h, &tmp.time.min, &tmp.score);
        printf("%16s %4d %2d %2d %2d %2d %7d" "\n", tmp.name, tmp.time.y, tmp.time.m, tmp.time.d, tmp.time.h, tmp.time.min, tmp.score);
    }
    if (fclose(board)) {
        cls_printf("\n\n\n\tCan't close Scoreboard!");
        PF_Sleep(ERROR_TIME);
        goto done;
    }
    done:
    PF__getch();
    return true;
}

#endif
#ifndef PLAYER_HPP
#define PLAYER_HPP

#define IMPORT_PLAYER_HPP \
typedef struct\
{\
    int score;\
    int extra_score;\
    double y;      \
    double v;      \
    double a;      \
    int movement;\
} player_mem;\
\
\
void _PlayerInit(player_mem *P){\
    P->score = INITIAL_SCORE;\
    P->extra_score = INITIAL_EXTRA_SCORE;\
    P->y = INITIAL_H;\
    P->v = INITIAL_SPEED;\
    P->a = GA;\
    P->movement = NONS;\
    return;\
}\
\
typedef struct \
{\
    player_mem mem;\
    void (*PlayerInit)(player_mem*) = _PlayerInit;\
} player;

#endif
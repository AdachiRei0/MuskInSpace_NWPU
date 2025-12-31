#ifndef SCREEN_HPP
#define SCREEN_HPP

#define IMPORT_SCREEN_HPP \
typedef struct      \
{\
    char buffer[HEIGHT][WIDTH+1];       \
    char bound[WIDTH+1];                \
    char space[WIDTH+1];        \
    char player_height[WIDTH+1];    \
    char swap_player_height[WIDTH+1];\
\
    char obstacle_hashtable[HEIGHT][WIDTH];     \
    unsigned int obstacle_pos;                  \
} screen_mem;\
\
\
void _ScreenInit(screen_mem *Screen){\
    memset(Screen->buffer, 0, sizeof(Screen->buffer));\
    memset(Screen->obstacle_hashtable, 0, sizeof(Screen->obstacle_hashtable));\
    Screen->obstacle_pos = 0;\
    for (int i = 0; i < WIDTH; i++){\
        Screen->bound[i] = '-';\
        Screen->player_height[i] = ' ';\
        Screen->swap_player_height[i] = ' ';\
        Screen->space[i] = ' ';\
    }\
\
    Screen->bound[WIDTH] = '\n';\
    Screen->player_height[WIDTH] = '\n';\
    Screen->swap_player_height[WIDTH] = '\n';\
    Screen->space[WIDTH] = '\n';\
\
    Screen->player_height[INITIAL_WIDTH] = 'P';\
    Screen->swap_player_height[INITIAL_WIDTH] = '_';\
    return;\
}\
\
void _FillScreen(screen_mem *Screen, int height){\
    memcpy(Screen->buffer[0], Screen->bound, WIDTH + 1);\
    memcpy(Screen->buffer[HEIGHT-1], Screen->bound, WIDTH + 1);\
    for(int i = 1; i < HEIGHT - 1; i++){\
        memcpy(Screen->buffer[i], Screen->space, WIDTH + 1);\
    }\
\
    if (swaptimer) {\
        memcpy(Screen->buffer[height], Screen->swap_player_height, WIDTH + 1);\
    } else {\
    memcpy(Screen->buffer[height], Screen->player_height, WIDTH + 1);\
    }\
\
    Screen->buffer[HEIGHT-1][WIDTH] = '\0';\
\
    for(int i = 0; i < HEIGHT; i++){\
        for(int j = 0; j < WIDTH; j++){\
            if(Screen->obstacle_hashtable[i][j] == B_OBSTACLE){\
                Screen->buffer[i][j] = 'O';\
            } else if(Screen->obstacle_hashtable[i][j] == B_END){\
                Screen->buffer[i][j] = '=';\
            }\
        }\
    }\
    return;\
}\
\
void _ScreenDisplay(screen_mem *Screen){\
    fputs((const char *)Screen->buffer, stdout);     \
    return;\
}\
\
void _FlashObstacle(screen_mem *Screen){\
    FILE *fp;\
    if((fp = fopen("../data/random_data.txt", "r")) == NULL){\
        printf("file open error!\n");\
        return;\
    }\
    fseek(fp, Screen->obstacle_pos, SEEK_SET);\
    for(int i = 0; i < HEIGHT * WIDTH; i++){\
        char ch = fgetc(fp);\
        if(ch == EOF){\
            printf("reached EOF, reset obstacle file pointer\n");\
            while((ch = PF_getch()) != 'q'){\
                continue;\
            }\
            exit(1);\
        }\
        Screen->obstacle_hashtable[i / WIDTH][i % WIDTH] = ch;\
        if(i == WIDTH){\
            Screen->obstacle_pos = ftell(fp);\
        }\
    }\
    if(fclose(fp) != 0){\
        printf("file close error!\n");\
        return;\
    }\
    return;\
}\
\
typedef struct\
{\
    screen_mem mem;\
    void (*ScreenInit)(screen_mem*) = _ScreenInit;\
    void (*FillScreen)(screen_mem*, int) = _FillScreen;\
    void (*ScreenDisplay)(screen_mem*) = _ScreenDisplay;\
    void (*FlashObstacle)(screen_mem*) = _FlashObstacle;\
} screen;

#endif
#ifndef TIMER_HPP
#define TIMER_HPP

#define IMPORT_TIMER_HPP \
typedef struct\
{\
    long PTS;\
    long RTS;\
    clock_t STS;\
} timer_mem;\
\
long _GetTimeGap(timer_mem *Timer){\
    return Timer->PTS - Timer->RTS;\
}\
\
void _FlashRTS(timer_mem *Timer){\
    clock_t end = clock();\
    double cpu_time_used = ((double)(end - Timer->STS)) / CLOCKS_PER_SEC;\
    Timer->RTS = (long)(cpu_time_used * 1000);\
    return;\
}\
\
void _TimerInit(timer_mem *Timer){\
    Timer->STS = clock();\
    Timer->PTS = 0;\
    Timer->RTS = 0;\
    return;\
}\
\
typedef struct\
{\
    timer_mem mem;\
    void (*TimerInit)(timer_mem*) = _TimerInit;\
    void (*FlashRTS)(timer_mem*) = _FlashRTS;\
    long (*GetTimeGap)(timer_mem*) = _GetTimeGap;\
} timer;\

#endif
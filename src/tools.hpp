#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "config.hpp"
#include "platform/platform.hpp"

// flash input buffer
void FlashBuffer(int max_char = 1000){
    int i, j, k;
    // dont forget to write the function body
    return;
}

// just printf(afer cls)
void cls_printf(const char* format, ...){
    PF_system_cls();
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    return;
}

// flush input buffer and wait for a key press
void GetchAfterFlush(){
    FlashBuffer();
    PF_Sleep(WORDS_MOVE_TIME);
    PF_getch();
    return;
}

#endif
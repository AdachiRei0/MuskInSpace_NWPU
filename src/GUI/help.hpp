#ifndef HELP_HPP
#define HELP_HPP

#include "../config.hpp"
#include "../platform/platform.hpp"

bool ShowHelp(){
    cls_printf("\n\n\n\t======== HELP ========\n"
               "\tWelcome to Musk In Space!\n\n"
               "\tGame Instructions:\n"
               "\t1. Use the UP arrow key to accelerate upwards.\n"
               "\t2. Use the DOWN arrow key to maintain a constant speed.\n"
               "\t3. Use the RIGHT arrow key to perform a backflip.\n"
               "\t4. Avoid space debris and navigate your spaceship safely back to the atmosphere.\n\n"
               "\tObjective:\n"
               "\tSuccessfully return to the atmosphere while avoiding obstacles.\n\n"
               "\tGood luck, and may the stars guide you home!\n"
               "\t=====================\n\n\n");
//    GetchAfterFlush();
    PF__getch();
    return true;
}

#endif
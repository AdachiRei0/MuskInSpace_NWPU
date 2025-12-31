#ifndef BOOT_HPP
#define BOOT_HPP
#include "../platform/platform.hpp"
#include "../config.hpp"

void ShowBootLogo(int move_time){
    for(int i = 1; i <= 16; i++){
        switch(i){
            case 16: printf("\t        ███╗   ███╗██╗   ██╗███████╗██╗  ██╗    ██╗███╗   ██╗\n");
            case 15: printf("\t        ████╗ ████║██║   ██║██╔════╝██║ ██╔╝    ██║████╗  ██║\n");
            case 14: printf("\t        ██╔████╔██║██║   ██║███████╗█████╔╝     ██║██╔██╗ ██║\n");
            case 13: printf("\t        ██║╚██╔╝██║██║   ██║╚════██║██╔═██╗     ██║██║╚██╗██║\n");
            case 12: printf("\t        ██║ ╚═╝ ██║╚██████╔╝███████║██║  ██╗    ██║██║ ╚████║\n");
            case 11: printf("\t        ╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚═╝╚═╝  ╚═══╝\n\n");
            case 10: printf("\t        ███████╗██████╗  █████╗  ██████╗███████╗\n");
            case 9 : printf("\t        ██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝\n");
            case 8 : printf("\t        ███████╗██████╔╝███████║██║     █████╗  \n");
            case 7 : printf("\t        ╚════██║██╔═══╝ ██╔══██║██║     ██╔══╝  \n");
            case 6 : printf("\t        ███████║██║     ██║  ██║╚██████╗███████╗\n");
            case 5 : printf("\t        ╚══════╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝\n\n");
            case 4 : printf("\t        ╔════════════════════════════════════════════╗\n");
            case 3 : printf("\t        ║           SYSTEMS INITIALIZING...          ║\n");
            case 2 : printf("\t        ║     LAUNCH SEQUENCE: T-MINUS 10...9...8... ║\n");
            case 1 : printf("\t        ╚════════════════════════════════════════════╝\n");
            PF_Sleep(move_time);
            if(i != 16){
                PF_system_cls();
            }
        }
        if (PF__kbhit() && PF__getch() == KEY_ENTER) {
            return;
        }
    }
    PF_getch();
    return;
}

void ShowBootBG(int move_time){
for(int i = 1; i <= 134; i++){
        switch(i){
            case   1: printf("\t        ███╗   ███╗██╗   ██╗███████╗██╗  ██╗    ██╗███╗   ██╗\n");
            case   2: printf("\t        ████╗ ████║██║   ██║██╔════╝██║ ██╔╝    ██║████╗  ██║\n");
            case   3: printf("\t        ██╔████╔██║██║   ██║███████╗█████╔╝     ██║██╔██╗ ██║\n");
            case   4: printf("\t        ██║╚██╔╝██║██║   ██║╚════██║██╔═██╗     ██║██║╚██╗██║\n");
            case   5: printf("\t        ██║ ╚═╝ ██║╚██████╔╝███████║██║  ██╗    ██║██║ ╚████║\n");
            case   6: printf("\t        ╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚═╝╚═╝  ╚═══╝\n\n");
            case   7: printf("\t        ███████╗██████╗  █████╗  ██████╗███████╗\n");
            case   8: printf("\t        ██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝\n");
            case   9: printf("\t        ███████╗██████╔╝███████║██║     █████╗  \n");
            case  10: printf("\t        ╚════██║██╔═══╝ ██╔══██║██║     ██╔══╝  \n");
            case  11: printf("\t        ███████║██║     ██║  ██║╚██████╗███████╗\n");
            case  12: printf("\t        ╚══════╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝\n\n");
            case  13: printf("\t        ╔════════════════════════════════════════════╗\n");
            case  14: printf("\t        ║           SYSTEMS INITIALIZING...          ║\n");
            case  15: printf("\t        ║     LAUNCH SEQUENCE: T-MINUS 10...9...8... ║\n");
            case  16: printf("\t        ╚════════════════════════════════════════════╝\n");
            case  17: printf("\n"); 
            case  18: printf("\n"); 
            case  19: printf("\n"); 
            case  20: printf("\n"); 
            case  21: printf("\n"); 
            case  22: printf("\n"); 
            case  23: printf("\n"); 
            case  24: printf("\n"); 
            case  25: printf("\n"); 
            case  26: printf("\n"); 
            case  27: printf("\n"); 
            case  28: printf("\n"); 
            case  29: printf("\n"); 
            case  30: printf("\n"); 
            case  31: printf("\n"); 
            case  32: printf("\n"); 
            case  33: printf("\n"); 
            case  34: printf("\n"); 
            case  35: printf("\n"); 
            case  36: printf("\n"); 
            case  37: printf("\n"); 
            case  38: printf("\n"); 
            case  39: printf("\n"); 
            case  40: printf("\n"); 
            case  41: printf("\n"); if(i ==  1){break;}
            case  42: printf("\n"); if(i ==  2){break;}
            case  43: printf("\n"); if(i ==  3){break;}
            case  44: printf("\n"); if(i ==  4){break;}
            case  45: printf("\n"); if(i ==  5){break;}
            case  46: printf("\n"); if(i ==  6){break;}
            case  47: printf("\n"); if(i ==  7){break;}
            case  48: printf("\n"); if(i ==  8){break;}
            case  49: printf("\n"); if(i ==  9){break;}
            case  50: printf("\n"); if(i == 10){break;}
            case  51: printf("\n"); if(i == 11){break;}
            case  52: printf("\n"); if(i == 12){break;}
            case  53: printf("\n"); if(i == 13){break;}
            case  54: printf("\n"); if(i == 14){break;}
            case  55: printf("\n"); if(i == 15){break;}
            case  56: printf("\n"); if(i == 16){break;}
            case  57: printf("                                             ^\n");if(i == 17){break;}
            case  58: printf("                                            / \\\n");if(i == 18){break;}
            case  59: printf("                                           /   \\\n");if(i == 19){break;}
            case  60: printf("                                          /     \\\n");if(i == 20){break;}
            case  61: printf("                                         /       \\\n"); if(i == 21){break;}
            case  62: printf("                                        /_________\\\n"); if(i == 22){break;}
            case  63: printf("                                       |           |\n"); if(i == 23){break;}
            case  64: printf("                                       |           |\n"); if(i == 24){break;}
            case  65: printf("                                       |           |\n"); if(i == 25){break;}
            case  66: printf("                                       |GAME NAME :|\n"); if(i == 26){break;}
            case  67: printf("                                       |  MUSK IN  |\n"); if(i == 27){break;}
            case  68: printf("                                       |  SPACE    |\n"); if(i == 28){break;}
            case  69: printf("                                       |           |\n"); if(i == 29){break;}
            case  70: printf("                                       |           |\n"); if(i == 30){break;}
            case  71: printf("                                       |           |\n"); if(i == 31){break;}
            case  72: printf("                                      /|           |\\\n"); if(i == 32){break;}
            case  73: printf("                                     / |           | \\\n"); if(i == 33){break;}
            case  74: printf("                                    |  |           |  |\n"); if(i == 34){break;}
            case  75: printf("                                    |  |           |  |\n"); if(i == 35){break;}
            case  76: printf("                                    |  |           |  |\n"); if(i == 36){break;}
            case  77: printf("                                    |  |           |  |\n"); if(i == 37){break;}
            case  78: printf("                                    |  |  AUTHON : |  |\n"); if(i == 38){break;}
            case  79: printf("                                    |  |  AMBITION |  |\n"); if(i == 39){break;}
            case  80: printf("                                    |  |           |  |\n"); if(i == 40){break;}
            case  81: printf("                                    |  |           |  |\n"); if(i == 41){break;}
            case  82: printf("                                    |  |           |  |\n"); if(i == 42){break;}
            case  83: printf("                                    |  |           |  |\n"); if(i == 43){break;}
            case  84: printf("                                   /|  |           |  |\\\n"); if(i == 44){break;}
            case  85: printf("                                  / |  |           |  | \\\n"); if(i == 45){break;}
            case  86: printf("                                |   |  |           |  |   |\n"); if(i == 46){break;}
            case  87: printf("                                |   |  |           |  |   |\n"); if(i == 47){break;}
            case  88: printf("                                |   |  |           |  |   |\n"); if(i == 48){break;}
            case  89: printf("                                |   |  |  ADRESS : |  |   |\n"); if(i == 49){break;}
            case  90: printf("                                |   |  |  NWPU, CN |  |   |\n"); if(i == 50){break;}
            case  91: printf("                                |   |  |           |  |   |\n"); if(i == 51){break;}
            case  92: printf("                                |   |  |           |  |   |\n"); if(i == 52){break;}
            case  93: printf("                                |   |  |           |  |   |\n"); if(i == 53){break;}
            case  94: printf("                                |   |  |           |  |   |\n"); if(i == 54){break;}
            case  95: printf("                               /|   |  |           |  |   |\\\n"); if(i == 55){break;}
            case  96: printf("                              / |   |  |           |  |   | \\\n"); if(i == 56){break;}
            case  97: printf("                     ________/  |   |  |           |  |   |  \\________\n"); if(i == 57){break;}
            case  98: printf("                   |            |   |  |           |  |   |            |\n"); if(i == 58){break;}
            case  99: printf("                   |   CLASS :  |   |  |           |  |   |  STU-ID :  |\n"); if(i == 59){break;}
            case 100: printf("                   |  DL062528  |   |  |           |  |   |2025302525  |\n"); if(i == 60){break;}
            case 101: printf("                   |____________|   |  |           |  |   |____________|\n"); if(i == 61){break;}
            case 102: printf("                         \\          |  |           |  |          /\n"); if(i == 62){break;}
            case 103: printf("                          \\         |  |           |  |         /\n"); if(i == 63){break;}
            case 104: printf("                           \\        |  |           |  |        /\n"); if(i == 64){break;}
            case 105: printf("                            \\       |  |           |  |       /\n"); if(i == 65){break;}
            case 106: printf("                             \\      |  |           |  |      /\n"); if(i == 66){break;}
            case 107: printf("                              \\     |  |           |  |     /\n"); if(i == 67){break;}
            case 108: printf("                               \\    |  |           |  |    /\n"); if(i == 68){break;}
            case 109: printf("                                \\   |  |           |  |   /\n"); if(i == 69){break;}
            case 110: printf("                                 \\  |  |           |  |  /\n"); if(i == 70){break;}
            case 111: printf("                                  \\ |  |           |  | /\n"); if(i == 71){break;}
            case 112: printf("                                   \\|  |           |  |/\n"); if(i == 72){break;}
            case 113: printf("                                    \\  |           |  /\n"); if(i == 73){break;}
            case 114: printf("                                     \\ |           | /\n"); if(i == 74){break;}
            case 115: printf("                                      \\|           |/\n"); if(i == 75){break;}
            case 116: printf("                                       \\           /\n"); if(i == 76){break;}
            case 117: printf("                                        \\_________/\n"); if(i == 77){break;}
            case 118: printf("                                       /|\\        /|\\\n"); if(i == 78){break;}
            case 119: printf("                                      //|\\\\      //|\\\\\n"); if(i == 79){break;}
            case 120: printf("                                     ///|\\\\\\    ///|\\\\\\\n"); if(i == 80){break;}
            case 121: printf("                                    ////|\\\\\\\\  ////|\\\\\\\\\n"); if(i == 81){break;}
            case 122: printf("                                   /////|\\\\\\\\\\/////|\\\\\\\\\\\n"); if(i == 82){break;}
            case 123: printf("                                  //////|\\\\\\\\\\//////|\\\\\\\\\\\n"); if(i == 83){break;}
            case 124: printf("                                 ///////|\\\\\\\\\\///////|\\\\\\\\\\\n"); if(i == 84){break;}
            case 125: printf("                                ////////|\\\\\\\\\\////////|\\\\\\\\\\\n"); if(i == 85){break;}
            case 126: printf("                               /////////|\\\\\\\\\\/////////|\\\\\\\\\\\n"); if(i == 86){break;}
            case 127: printf("                              //////////|\\\\\\\\\\//////////|\\\\\\\\\\\n"); if(i == 87){break;}
            case 128: printf("                             ///////////|\\\\\\\\\\///////////|\\\\\\\\\\\n"); if(i == 88){break;}
            case 129: printf("                            ////////////|\\\\\\\\\\////////////|\\\\\\\\\\\n"); if(i == 89){break;}
            case 130: printf("                           /////////////|\\\\\\\\\\/////////////|\\\\\\\\\\\n"); if(i == 90){break;}
            case 131: printf("                          //////////////|\\\\\\\\\\//////////////|\\\\\\\\\\\n"); if(i == 91){break;}
            case 132: printf("                         ///////////////|\\\\\\\\\\///////////////|\\\\\\\\\\\n"); if(i == 92){break;}
            case 133: printf("                        ////////////////|\\\\\\\\\\////////////////|\\\\\\\\\\\n"); if(i == 93){break;}
            case 134: printf("\n\n"); if(i == 94){break;}
        }
        PF_Sleep(move_time / 5);
        PF_system_cls();
        if (PF__kbhit() && PF__getch() == KEY_ENTER) {
            break;
        }
    }
    return;
}

#endif
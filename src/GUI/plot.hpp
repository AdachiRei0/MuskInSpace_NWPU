#ifndef PLOT_HPP
#define PLOT_HPP
#include "../tools.hpp"

void ShowPlot(){
    printf("\n\n\n\tYou are Musk. "
        "\n\tIn 2030, your starship project is successful, "
        "\n\tand you are on your luxurious spaceship to inspect space. "
        "\n\tUnfortunately, your spaceship encounters some malfunctions, "
        "\n\tand you have to return without relying on the main power of the spaceship. "
        "\n\tWhat's even more ironic is that in the space from outer space to the top of the atmosphere, "
        "\n\tthere is a lot of space debris that you previously discarded recklessly, "
        "\n\tand now they have become your trouble. "
        "\n\tHowever, you can still control your spaceship's buffer jet, "
        "\n\twhich was originally used to dock with your starship. "
        "\n\t Try to rely on it to return to the atmosphere! \n\n\n"
);
    GetchAfterFlush();
    PF_system_cls();
    printf("\n\n\n\tPress the up arrow key to accelerate upwards, "
        "\n\tpress the down arrow key to force a constant speed, "
        "\n\tand press the right arrow key to do a backflip! \n\n\n");
    GetchAfterFlush();
    PF_system_cls();
    printf("\n\n\n\tYou are currently %d km away from the safe atmosphere. "
        "\n\tGood luck!!!\n\n\n", WIN_CONDITION);
    GetchAfterFlush();
    PF_system_cls();
    return;
}

#endif
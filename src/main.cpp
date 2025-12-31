#include "system.hpp"
#include "GUI/gui.hpp"

int main() {
    CallStartMenu();    // start menu
    menu_t menu = EnterMainMenu();         // show main menu
    while (true) {
        if (menu == EXIT) {
            PF_system_cls();    // clear screen
            break;
        } else {
            PF_system_cls();    // clear screen
            menu = MenuFunctions[menu]();   // call corresponding function
        }
    }
    GoodBye();
    return 0;
}
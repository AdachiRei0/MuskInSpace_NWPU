#ifndef WINDOWS_HPP
#define WINDOWS_HPP

#include "../../config.hpp"
#include <windows.h>
#include <conio.h>

#define KEY_UP 72       // up-direction key
#define KEY_DOWN 80     // down-direction key
#define KEY_RIGHT 77    // right-direction key
#define KEY_LEFT 75     // left-direction key
#define KEY_ENTER 13    // enter key

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
    return;
}

void SetConsoleFullscreen() {
    // get console window
    HWND hwnd = GetConsoleWindow();
    SetFocus(hwnd);
    
    // simulate Alt+Enter key
    keybd_event(VK_MENU, 0, 0, 0);  // press Alt
    keybd_event(VK_RETURN, 0, 0, 0); // press Enter
    Sleep(PRESS_TIME);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0); // lease Enter
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0); // lease Alt
    keybd_event(VK_SHIFT, 0, 0, 0); // press Shift
    Sleep(PRESS_TIME);
    keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0); // lease Shift
    return;             
}

int PF__kbhit() {
    return _kbhit();
}

int PF__getch() {
    return _getch();
}

void PF_Sleep(int ms) {
    Sleep(ms);
}

int PF_getch() {
    return getch();
}

BOOL PF_SetConsoleOutputCP(UINT wCodePageID) {
    return SetConsoleOutputCP(wCodePageID);
}

void PF_system_cls() {
    system("cls");
}

#endif
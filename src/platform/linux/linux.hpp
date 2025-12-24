#ifndef LINUX_HPP
#define LINUX_HPP

#include "../../config.hpp"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <chrono>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define KEY_UP (256 + 1)       // up-direction key
#define KEY_DOWN (256 + 2)     // down-direction key

static struct termios original_termios;
static bool is_terminal_raw_mode = false;

void set_terminal_raw_mode() {
    if (is_terminal_raw_mode) return;
    
    tcgetattr(STDIN_FILENO, &original_termios);
    
    struct termios raw = original_termios;
    raw.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ISIG);
    raw.c_iflag &= ~(IXON | ICRNL);
    raw.c_oflag &= ~(OPOST);
    raw.c_cc[VMIN] = 0;  // 最小读取字符数
    raw.c_cc[VTIME] = 0; // 读取超时（0=不阻塞）
    
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    is_terminal_raw_mode = true;
}

void restore_terminal_mode() {
    if (is_terminal_raw_mode) {
        tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
        is_terminal_raw_mode = false;
    }
}

void init_terminal() {
    set_terminal_raw_mode();
    
    // 确保程序退出时恢复终端
    atexit(restore_terminal_mode);
}

//=======================以上为终端设置===========================//

void HideCursor(){
     std::cout << "\033[?25l" << std::flush;
}

void SetConsoleFullscreen(){
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);  // 禁用行缓冲和回显
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    
    // 设置非阻塞输入
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}


int PF__kbhit() {
    if (!is_terminal_raw_mode) {
        set_terminal_raw_mode();
    }
    
    struct timeval tv = {0, 0};
    fd_set fds;
    
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    
    // 非阻塞检查标准输入是否有数据
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

int PF__getch() {
    if (!is_terminal_raw_mode) {
        set_terminal_raw_mode();
    }
    
    char ch;
    int result = read(STDIN_FILENO, &ch, 1);
    
    if (result < 0) {
        return EOF;
    }
    
    return static_cast<unsigned char>(ch);
}

void PF_Sleep(unsigned int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int PF_getch() {
    return PF__getch();
}

int PF_SetConsoleOutputCP(unsigned int wCodePageID) {
    // Linux 下不需要设置代码页，直接返回成功
    return 1;
}

void PF_system_cls() {
    std::cout << "\033[2J\033[H" << std::flush; // ANSI 转义序列清屏并移动光标到左上角
}

#endif
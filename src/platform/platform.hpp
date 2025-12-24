#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#ifdef _WIN32
    #include "windows/windows.hpp"
#elif __linux__
    #include "linux/linux.hpp"
#elif __APPLE__
    #include "macos/macos.hpp"
#else
    #error "Unsupported platform"
#endif                

#endif
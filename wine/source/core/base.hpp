#ifndef BASE_H
#define BASE_H

#include <windows.h>

namespace wine::core {
    int init(HMODULE hDll); // Initialize all
    void destroy(); // Destroy all
    void start(); // Start cheat
    void stop(); // Stop cheat
}

#endif //BASE_H

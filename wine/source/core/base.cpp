#include "base.h"

volatile bool isStoped = true; // True if cheat stoped

int wine::core::init(const HMODULE hDll) {
    if(!hDll) return 1;

    return 0;
}

void wine::core::destroy() {
}

void wine::core::start() {
    isStoped = false;
    while (!isStoped) { // Game Loop

    }
}

void wine::core::stop() {
    isStoped = true;
}

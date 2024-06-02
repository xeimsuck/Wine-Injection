#include <windows.h>

#include "core/base.hpp"

// Launch cheat
static void laucnh(const HMODULE hDll) {
    if(wine::core::init(hDll)) wine::core::start();
    else wine::core::destroy();
}

// Stop cheat
static void end() {
    wine::core::stop();
    wine::core::destroy();
}

BOOL WINAPI DllMain(HMODULE hDll, const DWORD reason, LPVOID) {
    switch(reason){
        case DLL_PROCESS_ATTACH:
            CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(laucnh),
                hDll, NULL, nullptr);
            break;
        case DLL_PROCESS_DETACH:
            end();
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
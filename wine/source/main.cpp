#include <windows.h>

// Launch cheat
static void Start(HMODULE hDll) {

}

// Stop cheat
static void Stop() {

}

BOOL WINAPI DllMain(HMODULE hDll, const DWORD reason, LPVOID) {
    switch(reason){
        case DLL_PROCESS_ATTACH:
            CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Start),
                hDll, NULL, nullptr);
            break;
        case DLL_PROCESS_DETACH:
            Stop();
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
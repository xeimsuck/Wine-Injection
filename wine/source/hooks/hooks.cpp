#include "hooks.hpp"
#include <MinHook.h>

int wine::hooks::initHooks() {
    MH_Initialize();
    if(createHookSwapBuffers()!=MH_OK) return 1;
    return 0;
}

void wine::hooks::destroyHooks() {
    removeHookSwapBuffers();
    MH_Uninitialize();
}

#include "hooks.h"
#include <MinHook.h>

int wine::hooks::initHooks() {
    MH_Initialize();
    return 0;
}

void wine::hooks::destroyHooks() {

}

#include "base.hpp"

#include "binds.hpp"
#include "../gui/gui.hpp"
#include "../memory/data.hpp"
#include "../memory/game/ac_client.exe.hpp"
#include "../hooks/hooks.hpp"

using namespace wine::mem;
using namespace wine::hooks;

namespace wine::core {
     int initMem(HMODULE _hDll);
}

static volatile bool isStoped = true; // true if cheat stoped


int wine::core::init(const HMODULE hDll) {
    // initialize modules
    if(initMem(hDll)) return 1;
    if(initHooks()) return 1;

    return 0;
}

void wine::core::destroy() {
    //destroy modules
    destroyHooks();
}

void wine::core::start() {
    isStoped = false;
    enableHookSwapBuffers();
    while (!isStoped) { // Game Loop
        inspectBinds();
    }
}

void wine::core::stop() {
    disableHookSwapBuffers();
    isStoped = true;
}


int wine::core::initMem(const HMODULE _hDll) {
    using namespace data;

    if(!_hDll) return 1;
    stuff::hDll = _hDll;

    stuff::hACClient = GetModuleHandleW(L"ac_client.exe");
    if(!stuff::hACClient) return 1;
    const auto castedACClient = reinterpret_cast<UINT_PTR>(stuff::hACClient);

    stuff::pPlayer = *reinterpret_cast<UINT_PTR*>(castedACClient + ac_client::global::pPlayer);
    stuff::pEntityList = reinterpret_cast<UINT_PTR*>(ac_client::global::pEntityPointerList);
    stuff::pEntityListSize = reinterpret_cast<int*>(castedACClient + ac_client::global::iEntityPointerListSize);

    return 0;
}


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
    using namespace data::stuff;
    using namespace ac_client::global;

    if(!_hDll) return 1;
    hDll = _hDll;

    hACClient = GetModuleHandleW(L"ac_client.exe");
    if(!hACClient) return 1;
    const auto castedACClient = reinterpret_cast<UINT_PTR>(hACClient);

    pPointerToPlayer = castedACClient + pPlayerPointer;
    pVectorOfEntityList = reinterpret_cast<std::vector<UINT_PTR>*>(castedACClient+vEntityPointersList);

    return 0;
}


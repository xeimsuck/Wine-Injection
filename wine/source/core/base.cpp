#include "base.hpp"

#include <thread>
#include "binds.hpp"
#include "../gui/gui.hpp"
#include "../hacks/hacks.hpp"
#include "../memory/data.hpp"
#include "../memory/game/ac_client.exe.hpp"
#include "../hooks/hooks.hpp"

using namespace std::chrono_literals;
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
    enableHookDamageEntity();
    while (!isStoped) { // Game Loop
        inspectBinds();
        if(data::hacks::aimbot::isAimBot) data::hacks::aimbot::target = hacks::findAimbotTarget();
    }
}

void wine::core::stop() {
    disableHookSwapBuffers();
    isStoped = true;
}


int wine::core::initMem(const HMODULE _hDll) {
    using namespace data;

    // Init Stuff
    if(!_hDll) return 1;
    stuff::hDll = _hDll;

    stuff::hACClient = GetModuleHandleW(L"ac_client.exe");
    if(!stuff::hACClient) return 1;
    const auto castedACClient = reinterpret_cast<UINT_PTR>(stuff::hACClient);

    stuff::player = *reinterpret_cast<UINT_PTR*>(castedACClient + ac_client::global::pPlayer);
    stuff::pEntityList = reinterpret_cast<UINT_PTR*>(castedACClient + ac_client::global::pEntityPointerList);
    stuff::pEntityListSize = reinterpret_cast<int*>(castedACClient + ac_client::global::iEntityPointerListSize);

    stuff::matView = reinterpret_cast<glm::mat4*>(castedACClient + ac_client::global::mViewMatrix);

    return 0;
}


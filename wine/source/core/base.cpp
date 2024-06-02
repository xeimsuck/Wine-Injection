#include "base.hpp"
#include "../memory/data.hpp"
#include "../hooks/hooks.hpp"

using namespace wine::mem;
using namespace wine::hooks;

static volatile bool isStoped = true; // true if cheat stoped

int wine::core::init(const HMODULE hDll) {
    // fill memory
    if(!hDll) return 1;
    data::stuff::hDll = hDll;
    data::stuff::hACClient = GetModuleHandleW(L"ac_client.exe");
    if(data::stuff::hACClient) return 1;

    // initialize modules
    if(initHooks()) return 1;

    return 0;
}

void wine::core::destroy() {
    //destroy modules
    destroyHooks();
}

void wine::core::start() {
    isStoped = false;
    while (!isStoped) { // Game Loop

    }
}

void wine::core::stop() {
    isStoped = true;
}

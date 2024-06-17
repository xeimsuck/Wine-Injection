#include "binds.hpp"
#include "../memory/data.hpp"

using namespace wine::mem::data::binds;
using namespace wine::mem::data::gui;
using namespace wine::mem::data::hacks;

void wine::core::inspectBinds() {
    if(static_cast<byte>(GetAsyncKeyState(bindKeyOpenMenu))) isMenuOpened = !isMenuOpened;
    if(static_cast<byte>(GetAsyncKeyState(bindKeyESP))) esp::isESP = !esp::isESP;
    if(static_cast<byte>(GetAsyncKeyState(bindKeyAimBot))) aimbot::isAimBot = !aimbot::isAimBot;
    if(static_cast<byte>(GetAsyncKeyState(bindKeyGodMode))) isGodMode = !isGodMode;
}

void wine::core::loadBinds(const std::string& path) {
    //load binds from file
}
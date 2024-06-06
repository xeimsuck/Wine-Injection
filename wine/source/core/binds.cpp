#include "binds.h"
#include "../memory/data.hpp"

using namespace wine::mem::data::binds;
using namespace wine::mem::data::gui;

void wine::core::inspectBinds() {
    if(static_cast<byte>(GetAsyncKeyState(bindKeyOpenMenu))) isMenuOpened = !isMenuOpened;
}

void wine::core::loadBinds(const std::string& path) {
    //load binds from file
}
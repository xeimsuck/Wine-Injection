#include "gui.hpp"
#include <GL/glew.h>
#include "../core/base.hpp"
#include "../memory/data.hpp"

using namespace wine::mem::data::gui;

static void drawMenu() {
    // Draw menu
}

int wine::gui::initGUI() {
    if(glewInit()) return 1;
    isGUIInited = true;
    return 0;
}

void wine::gui::destroyGUI() {
}

void wine::gui::draw() {
    if(!isGUIInited) {
        if(initGUI()) return;
    }
    if(isMenuOpened) drawMenu();
}

#include "gui.h"
#include <GL/glew.h>
#include "../core/base.hpp"
#include "../memory/data.hpp"

using namespace wine::mem::data::gui;

static void drawMenu() {
    // Draw menu
}

int wine::gui::initGUI() {
    // по нулям бро
    return 0;
}

void wine::gui::destroyGUI() {
}

void wine::gui::draw() {
    if(isMenuOpened) drawMenu();
}

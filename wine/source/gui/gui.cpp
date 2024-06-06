#include "gui.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../core/base.hpp"
#include "../memory/data.hpp"

static void drawMenu() {
    // Draw menu
}

int wine::gui::initGUI() {
    // по нулям бро
    return 0;
}

void wine::gui::destroyGUI() {
    glfwTerminate();
}

void wine::gui::draw() {
    if(wine::mem::data::gui::isMenuOpened) drawMenu();
}

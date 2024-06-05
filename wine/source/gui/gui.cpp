#include "gui.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <windows.h>

static void drawMenu() {
    // Draw menu
}

int wine::gui::initGUI() {
    // GLFW initialization
    if(!glfwInit()) return 1;

    // GLEW initialization
    if(glewInit()) return 1;

    return 0;
}

void wine::gui::destroyGUI() {
    glfwTerminate();
}

void wine::gui::draw() {
    drawMenu();
}

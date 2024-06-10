#include "gui.hpp"

#include <windows.h>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_win32.h>
#include <GL/glew.h>

#include "shader.hpp"
#include "../core/base.hpp"
#include "../memory/data.hpp"
#include "../shaders/shadersESP.h"


using namespace wine::mem::data::gui;
using namespace wine::mem::data::hacks;

static wine::gui::shader* shaderESP;

namespace wine::gui {
    static void drawMenu();
    static void drawESP();
    static void drawESPBoxes();
    static void drawESPName();
}

int wine::gui::initGUI() {
    // GLEW Initialize
    if(glewInit()) return 1;

    // Shaders Initialization
    shaderESP = new shader;
    if(shaderESP->createVertexShader(wine::shaders::sourceVertexShaderESP)) return 1;
    if(shaderESP->createFragmentShader(wine::shaders::sourceFragmentShaderESP)) return 1;
    if(shaderESP->linkProgram()) return 1;

    // ImGui Initialize
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    ImGui::StyleColorsDark();
    ImGui_ImplWin32_InitForOpenGL(WindowFromDC(wglGetCurrentDC()));
    ImGui_ImplOpenGL3_Init("#version 330");

    isGUIInited = true;
    return 0;
}

void wine::gui::destroyGUI() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    delete shaderESP;
}

void wine::gui::draw() {
    if(!isGUIInited) {
        if(initGUI()) throw;
    }

    if(isESP) drawESP();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    if(isMenuOpened) drawMenu();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

static void wine::gui::drawMenu() {
    // Main Window
    ImGui::Begin("WINE");
    ImGui::End();
}

void wine::gui::drawESP() {
    if(isESPBoxes) drawESPBoxes();
    if(isESPName) drawESPName();
}

void wine::gui::drawESPBoxes() {

}

void wine::gui::drawESPName() {

}



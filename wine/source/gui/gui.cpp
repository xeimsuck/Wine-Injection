#include "gui.hpp"

#include <windows.h>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_win32.h>
#include <GL/glew.h>

#include "../core/base.hpp"
#include "../memory/data.hpp"


using namespace wine::mem::data::gui;

static void drawMenu() {
    // Draw menu
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("WINE");
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

int wine::gui::initGUI() {
    // GLEW Initialize
    if(glewInit()) return 1;

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
}

void wine::gui::draw() {
    if(!isGUIInited) {
        if(initGUI()) return;
    }
    if(isMenuOpened) drawMenu();
}

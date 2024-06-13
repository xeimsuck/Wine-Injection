#include "gui.hpp"

#include <windows.h>

#include <GL/glew.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_win32.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.hpp"
#include "../core/base.hpp"
#include "../hacks/hacks.hpp"
#include "../memory/data.hpp"
#include "../memory/game/ac_client.exe.hpp"
#include "../shaders/shadersESP.h"


using namespace wine::mem::data::gui;
using namespace wine::mem::data::hacks;

static wine::gui::shader* shaderESPLine = nullptr, *shaderESPBox = nullptr;
GLuint shaderESPVAO, shaderESPVBO;
glm::vec3 shaderESPBuffer{};

namespace wine::gui {
    static void drawMenu();
    static void drawESP();
    static void drawESPLine();
    static void drawESPBox();
    static void drawESPName();
}

int wine::gui::initGUI() {
    // GLEW Initialize
    if(glewInit()) return 1;

    // Shaders Initialization
    //// Line Shader
    shaderESPLine = new shader;
    if(shaderESPLine->createShader(GL_VERTEX_SHADER, shaders::sourceVertexShaderESP)) return 1;
    if(shaderESPLine->createShader(GL_GEOMETRY_SHADER, shaders::sourceGeometryShaderESPLine)) return 1;
    if(shaderESPLine->createShader(GL_FRAGMENT_SHADER, shaders::sourceFragmentShaderESP)) return 1;
    if(shaderESPLine->linkProgram()) return 1;

    //// Box Shader
    shaderESPBox = new shader;
    if(shaderESPBox->createShader(GL_VERTEX_SHADER, shaders::sourceVertexShaderESP)) return 1;
    if(shaderESPBox->createShader(GL_GEOMETRY_SHADER, shaders::sourceGeometryShaderESPBoxes)) return 1;
    if(shaderESPBox->createShader(GL_FRAGMENT_SHADER, shaders::sourceFragmentShaderESP)) return 1;
    if(shaderESPBox->linkProgram()) return 1;

    // VAO
    GLint prevVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &prevVAO);

    glGenVertexArrays(1, &shaderESPVAO);
    glGenBuffers(1, &shaderESPVBO);

    glBindVertexArray(shaderESPVAO);
    glBindBuffer(GL_ARRAY_BUFFER, shaderESPVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(shaderESPBuffer), &shaderESPBuffer, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(prevVAO);


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

    delete shaderESPLine;
}

void wine::gui::draw() {
    if(!isGUIInited) {
        if(initGUI()) throw;
    }

    if(esp::isESP) drawESP();

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
    ImGui::Checkbox("ESP", &esp::isESP);
    if(esp::isESP) {
        ImGui::Checkbox("ESP Lines", &esp::isESPLines);
        ImGui::Checkbox("ESP Boxes", &esp::isESPBoxes);
        ImGui::Checkbox("ESP Names", &esp::isESPNames);
        ImGui::ColorPicker3("ESP Color", &esp::colorESP.r);
    }
    ImGui::End();
}

void wine::gui::drawESP() {
    const UINT entityList = *mem::data::stuff::pEntityList;

    GLint prevVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &prevVAO);

    glClear(GL_DEPTH_BUFFER_BIT);

    glBindVertexArray(shaderESPVAO);

    for(int i = 0; i < *mem::data::stuff::pEntityListSize; ++i) {
        const UINT entityAddress = *reinterpret_cast<UINT*>(entityList+sizeof(UINT_PTR)*i);
        if(!hacks::isAlive(entityAddress)) continue;

        glBindBuffer(GL_ARRAY_BUFFER, shaderESPVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(shaderESPBuffer),
                        reinterpret_cast<void*>(entityAddress+mem::ac_client::entity::fPositionX));
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        if(esp::isESPLines) drawESPLine();
        if(esp::isESPBoxes) drawESPBox();
        if(esp::isESPNames) drawESPName();
    }

    glBindVertexArray(prevVAO);
}

void wine::gui::drawESPLine() {
    GLint prevShader;
    glGetIntegerv(GL_CURRENT_PROGRAM, &prevShader);

    shaderESPLine->useProgram();
    glUniformMatrix4fv(glGetUniformLocation(static_cast<GLuint>(*shaderESPLine), "view"),
                    1, GL_FALSE, glm::value_ptr(*mem::data::stuff::matView));
    glUniform3fv(glGetUniformLocation(static_cast<GLuint>(*shaderESPLine), "esp_color"),
                    1, glm::value_ptr(esp::colorESP));
    glDrawArrays(GL_POINTS, 0, 1);

    glUseProgram(prevShader);
}

void wine::gui::drawESPBox() {
    GLint prevShader;
    glGetIntegerv(GL_CURRENT_PROGRAM, &prevShader);

    shaderESPBox->useProgram();
    glUniformMatrix4fv(glGetUniformLocation(static_cast<GLuint>(*shaderESPBox), "view"),
                    1, GL_FALSE, glm::value_ptr(*mem::data::stuff::matView));
    glUniform3fv(glGetUniformLocation(static_cast<GLuint>(*shaderESPBox), "esp_color"),
                    1, glm::value_ptr(esp::colorESP));
    glDrawArrays(GL_POINTS, 0, 1);

    glUseProgram(prevShader);
}

void wine::gui::drawESPName() {

}



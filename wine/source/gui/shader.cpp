#include "shader.hpp"
#include <GL/glew.h>

#include "../core/base.hpp"
#include "../shaders/shadersESP.h"

wine::gui::shader::shader() {
    shaderProgram = glCreateProgram();
}

wine::gui::shader::~shader() {
    glDeleteProgram(shaderProgram);
}

int wine::gui::shader::createVertexShader(const char* const source) {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &source, nullptr);
    glCompileShader(vertexShader);

    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    return !success;
}

int wine::gui::shader::createFragmentShader(const char* const source) {
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &source, nullptr);
    glCompileShader(fragmentShader);

    GLint success;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    return !success;
}

unsigned int wine::gui::shader::getProgram() {
    return shaderProgram;
}


int wine::gui::shader::linkProgram() {
    if(vertexShader) glAttachShader(shaderProgram, vertexShader);
    if(fragmentShader) glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    GLchar infoLog[512];
    if(!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        MessageBoxA(nullptr, infoLog, "link", MB_OK);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return 0;
}

int wine::gui::shader::useProgram() {
    glUseProgram(shaderProgram);
    return 0;
}

wine::gui::shader::operator unsigned() {
    return getProgram();
}





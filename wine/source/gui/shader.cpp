#include "shader.hpp"

#include <GL/glew.h>

#include "../core/base.hpp"

wine::gui::shader::shader() {
    shaderProgram = glCreateProgram();
}

wine::gui::shader::~shader() {
    glDeleteProgram(shaderProgram);
}

int wine::gui::shader::createShader(const unsigned type, const char* const source) {
    const GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    GLchar infoLog[512];
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        MessageBoxA(nullptr, infoLog, "shader::createShader Error", MB_OK);
        return 1;
    }

    switch (type) {
        case GL_VERTEX_SHADER:
            vertexShader = shader;
            break;
        case GL_GEOMETRY_SHADER:
            geometryShader = shader;
            break;
        case GL_FRAGMENT_SHADER:
            fragmentShader = shader;
            break;
        default: return 1;
    }

    return 0;
}


unsigned int wine::gui::shader::getProgram() {
    return shaderProgram;
}

int wine::gui::shader::linkProgram() {
    if(vertexShader) glAttachShader(shaderProgram, vertexShader);
    if(geometryShader) glAttachShader(shaderProgram, geometryShader);
    if(fragmentShader) glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    GLchar infoLog[512];
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        MessageBoxA(nullptr, infoLog, "Link Shader Program Error", MB_OK);
        return 1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(geometryShader);
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





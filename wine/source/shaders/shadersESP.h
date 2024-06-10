#ifndef SHADERSESP_H
#define SHADERSESP_H

namespace wine::shaders {
    constexpr char sourceVertexShaderESP[] =
        R"(
        #version 330 core

        uniform vec4 position;
        uniform mat4 view;

        void main() {
            gl_Position = view * position;
        }
        )";
    constexpr char sourceFragmentShaderESP[] =
        R"(
        #version 330 core

        out vec4 color;

        void main() {
            color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
        }
        )";
}

#endif //SHADERSESP_H

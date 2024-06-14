#ifndef SHADERESPLINE_HPP
#define SHADERESPLINE_HPP

namespace wine::shaders {
    constexpr char sourceVertexShaderESPLine[] =
       R"(
        #version 330 core

        layout (location = 0) in vec3 position;

        uniform mat4 view;

        void main() {
            gl_Position = view * vec4(position, 1.0f);
        }
        )";
    constexpr char sourceFragmentShaderESPLine[] =
        R"(
        #version 330 core

        uniform vec3 esp_color;

        out vec4 color;

        void main() {
            color = vec4(esp_color/255, 1.0f);
        }
        )";
    constexpr char sourceGeometryShaderESPLine[] =
        R"(
        #version 330 core
        layout (points) in;
        layout (line_strip, max_vertices = 2) out;

        void main() {
            gl_Position = gl_in[0].gl_Position;
            EmitVertex();

            gl_Position = vec4(0.0f, -1.0f, 0.0f, 1.0f);
            EmitVertex();

            EndPrimitive();
        }
        )";
}

#endif //SHADERESPLINE_HPP

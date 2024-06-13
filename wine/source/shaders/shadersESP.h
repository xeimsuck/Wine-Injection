#ifndef SHADERSESP_H
#define SHADERSESP_H

namespace wine::shaders {
    constexpr char sourceVertexShaderESP[] =
        R"(
        #version 330 core

        layout (location = 0) in vec3 position;

        uniform mat4 view;

        void main() {
            gl_Position = view * vec4(position, 1.0f);
        }
        )";
    constexpr char sourceFragmentShaderESP[] =
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
    constexpr char sourceGeometryShaderESPBoxes[] =
        R"(
        #version 330 core
        layout (points) in;
        layout (line_strip, max_vertices = 5) out;

        void main() {
            gl_Position = gl_in[0].gl_Position+vec4(1.5f, 0.0f, 0.0f, 0.0f);  // Right-Bottom
            EmitVertex();

            gl_Position = gl_in[0].gl_Position+vec4(-1.5f, 0.0f, 0.0f, 0.0f); // Left-Bottom
            EmitVertex();

            gl_Position = gl_in[0].gl_Position+vec4(-1.5f, 8.0f, 0.0f, 0.0f); // Left-Top
            EmitVertex();

            gl_Position = gl_in[0].gl_Position+vec4(1.5f, 8.0f, 0.0f, 0.0f); // Right-Top
            EmitVertex();

            gl_Position = gl_in[0].gl_Position+vec4(1.5f, 0.0f, 0.0f, 0.0f); // Right-Bottom
            EmitVertex();

            EndPrimitive();
        }
        )";
}

#endif //SHADERSESP_H

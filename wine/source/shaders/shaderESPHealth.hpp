#ifndef SHADERESPHEALTH_HPP
#define SHADERESPHEALTH_HPP

namespace wine::shaders {
    constexpr char sourceVertexShaderESPHealth[] =
       R"(
        #version 330 core

        layout (location = 0) in vec3 position;

        uniform mat4 view;

        void main() {
            gl_Position = view * vec4(position, 1.0f);
        }
        )";
    constexpr char sourceFragmentShaderESPHealth[] =
        R"(
        #version 330 core

        uniform vec3 esp_color;

        out vec4 color;

        uniform int health;

        void main() {
            color = vec4(1-0.01*health, 0.01*health, 0.0f, 0.5f);
        }
        )";
    constexpr char sourceGeometryShaderESPHealth[] =
    R"(
        #version 330 core
        layout (points) in;
        layout (triangle_strip, max_vertices = 4) out;

        uniform int health;

        void main() {
            gl_Position = gl_in[0].gl_Position+vec4(1.7f, 0.0f, 0.0f, 0.0f); // Left-Bottom
            EmitVertex();

            gl_Position = gl_in[0].gl_Position+vec4(1.7f, 0.1*health, 0.0f, 0.0f); // Left-Top
            EmitVertex();

            gl_Position = gl_in[0].gl_Position+vec4(2.0f, 0.0f, 0.0f, 0.0f);  // Right-Bottom
            EmitVertex();

            gl_Position = gl_in[0].gl_Position+vec4(2.0f, 0.1*health, 0.0f, 0.0f); // Right-Top
            EmitVertex();

            EndPrimitive();
        }
        )";
}


#endif //SHADERESPHEALTH_HPP

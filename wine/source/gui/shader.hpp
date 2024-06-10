#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace wine::gui {
    class shader {
    public:
        shader();
        ~shader();
        int createVertexShader(const char* source);
        int createFragmentShader(const char* source);
        int linkProgram();
        int useProgram();
    private:
        unsigned int vertexShader = 0;
        unsigned int fragmentShader = 0;
        unsigned int shaderProgram = 0;
    };
}

#endif //SHADER_H

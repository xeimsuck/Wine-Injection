#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace wine::gui {
    class shader {
    public:
        shader();
        ~shader();
        int createShader(unsigned type, const char* source);
        unsigned int getProgram();
        int linkProgram();
        int useProgram();

        explicit operator unsigned();
    private:
        unsigned int vertexShader = 0;
        unsigned int fragmentShader = 0;
        unsigned int geometryShader = 0;
        unsigned int shaderProgram = 0;
    };
}

#endif //SHADER_H

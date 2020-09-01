#ifndef CUBE_H
#define CUBE_H
#include "Shape.h"

class Cube: public Shape {
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors();
    public:
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY);
};

#endif

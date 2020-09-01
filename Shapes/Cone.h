#ifndef CONE_H
#define CONE_H
#include "Shape.h"

class Cone: public Shape {
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors();
    public:
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY);
};

#endif

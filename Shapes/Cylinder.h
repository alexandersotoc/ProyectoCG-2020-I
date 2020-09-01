#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape.h"

class Cylinder: public Shape {
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors();
    public:
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY);
};

#endif

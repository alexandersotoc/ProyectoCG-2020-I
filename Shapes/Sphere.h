#ifndef SPHERE_H
#define SPHERE_H
#include "Shape.h"

class Sphere: public Shape {
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors();
    public:
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY);
};

#endif

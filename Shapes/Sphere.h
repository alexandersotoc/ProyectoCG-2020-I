#ifndef SPHERE_H
#define SPHERE_H
#include "Shape.h"

#define PI 3.141592

class Sphere: public Shape {
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors();
        float radio = 0.5;
        float FinalTeta=PI;
        float FinalPhi=2*PI;
    public:
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY, QVector<GLenum> modes);
};

#endif

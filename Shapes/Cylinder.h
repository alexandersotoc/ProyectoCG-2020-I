#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape.h"

class Cylinder: public Shape {
    public:
        Cylinder();
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY, GLenum mode);
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors();
        float cylinder_height;
        float cylinder_radius;
};

#endif

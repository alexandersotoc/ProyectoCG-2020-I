#ifndef CONE_H
#define CONE_H
#include "Shape.h"

class Cone: public Shape {
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors();
        void drawSideCone(float centerX, float centerY, float centerZ, float radius, int numberOfSides,
                          float height, int segmentsY);
        void drawBaseCone(float centerX, float centerY, float centerZ, float radius, int numberOfSides);

    public:
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY, GLenum mode);
};

#endif

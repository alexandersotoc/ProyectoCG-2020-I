#ifndef CUBE_H
#define CUBE_H
#include "Shape.h"

class Cube: public Shape {
    private:
        void setVertices(int segmentsX, int segmentsY);
        void setColors(bool color);
        void drawFace(QVector3D p1, QVector3D p2, QVector3D p3, QVector3D p4,
            int segmentsX, int segmentsY);
        void addTriangles(QVector<QVector3D> line1, QVector<QVector3D> line2);
        QVector<QVector3D> pointControl(QVector3D initialPoint, QVector3D finalPoint,
            int segments);
    public:
        void toString();
        void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY, QVector<GLenum> modes,
                  bool color);
};

#endif

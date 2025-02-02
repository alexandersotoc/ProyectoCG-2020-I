#ifndef SHAPE_H
#define SHAPE_H
#include <QVector3D>
#include <QVector>
#include <QOpenGLShaderProgram>

class Shape {
    protected:
        int segmentsX;
        int segmentsY;
        QVector<QVector3D> vertices;
        QVector<QVector3D> colors;
        void solidColor();
    private:
        virtual void setVertices(int segmentsX, int segmentsY) = 0;
        virtual void setColors(bool color) = 0;
    public:
        static Shape *chooseShape(int choice);
        virtual void toString() = 0;
        virtual void draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY, QVector<GLenum> modes,
                          bool color) = 0;
};

#endif

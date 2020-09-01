#include <QDebug>
#include <QVector3D>
#include <math.h>

#include "Cylinder.h"

#define PI 3.14159265358979323846

using namespace std;

void Cylinder::toString() {
    qDebug() << "Cone shape was selected \n";
}

void Cylinder::setVertices(int segX, int segY) {

}

void Cylinder::setColors() {

}

void Cylinder::draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY) {

}

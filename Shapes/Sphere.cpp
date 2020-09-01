#include <QDebug>
#include <QVector3D>
#include <math.h>

#include "Sphere.h"

#define PI 3.14159265358979323846

using namespace std;

void Sphere::toString() {
    qDebug() << "Cone shape was selected \n";
}

void Sphere::setVertices(int segX, int segY) {

}

void Sphere::setColors() {

}

void Sphere::draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY) {

}

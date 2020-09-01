#include <QDebug>
#include <QVector3D>
#include <math.h>

#include "Cone.h"

#define PI 3.14159265358979323846

using namespace std;

void Cone::toString() {
    qDebug() << "Cone shape was selected \n";
}

void Cone::setVertices(int segX, int segY) {

}

void Cone::setColors() {

}

void Cone::draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY) {

}

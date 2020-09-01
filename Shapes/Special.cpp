#include <QDebug>
#include <QVector3D>
#include <math.h>

#include "Shape.h"
#include "Special.h"

#define PI 3.14159265358979323846

using namespace std; 

void Special::toString() {
    qDebug() << "Special shape was selected \n";
}

void Special::setVertices(int segX, int segY) {
    int i, j, k;
    double s, t, x, y, z, twopi;    
    twopi = 2 * PI;
    segmentsX = segX;
    segmentsY = segY;
    for (i = 0; i < segX; i++) {
        for (j = 0; j <= segY; j++) {
            for (k = 1; k >= 0; k--) {
                s = (i + k) % segX + 0.5;
                t = j % segY;

                x = (1+.1*cos(s*twopi/segX))*cos(t*twopi/segY);
                y = (1+.1*cos(s*twopi/segX))*sin(t*twopi/segY);
                z = .1 * sin(s * twopi / segX);
                vertices.push_back(QVector3D(x, y, z));
         }
      }
   }
}

void Special::setColors() {
    int cantidadDePuntos = segmentsX  * (segmentsY + 1) * 2;

    for (int i = 0; i < cantidadDePuntos; i++) {
        colors.push_back(QVector3D(generateRandomNumber(), generateRandomNumber(), generateRandomNumber()));
    }
}

void Special::draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY) {
    setVertices(segmentsX, segmentsY);
    setColors();

    shaderProgram->setAttributeArray("vertex", vertices.constData());
    shaderProgram->enableAttributeArray("vertex");

    shaderProgram->setAttributeArray("color", colors.constData());
    shaderProgram->enableAttributeArray("color");

    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices.size());
    glShadeModel(GL_FLAT);
}

double Special::generateRandomNumber()
{
    return ((double) rand() / (RAND_MAX));
}

#include <QDebug>
#include <QVector3D>
#include <math.h>

#include "Cylinder.h"

#define PI 3.14159265358979323846

using namespace std;

Cylinder::Cylinder(){
    cylinder_height = 1.0f;
    cylinder_radius = 0.5f;
}

void Cylinder::toString() {
    qDebug() << "Cone shape was selected \n";
}

void Cylinder::setVertices(int segX, int segY) {
    // Vertices Cara Abajo
    for (int i = 0; i < segX ; i++ ) {
        float u = i/(float)segX;

        float x = cylinder_radius*cos(2*PI*u);
        float z = cylinder_radius*sin(2*PI*u);

        float y_start = 0.0f;

        vertices.append(QVector3D(x,y_start, z));
    }
    // Vertices Cara Arriba
    for (int i = 0; i < segX ; i++ ) {
        float u = i/(float)segX;

        float x = cylinder_radius*cos(2*PI*u);
        float z = cylinder_radius*sin(2*PI*u);

        float y_finish = 1.0f;

        vertices.append(QVector3D(x,y_finish, z));
    }

    // Vertices Lados
    float y_incrementent = cylinder_height / (float)segY;

    QVector3D lastBottomLeft;
    QVector3D lastBottomRight;
    for(int i = 0; i < segX ; i++){

        if(i == segX -1){
            lastBottomLeft = vertices[i];
            lastBottomRight = vertices[0];
        }
        else{
            lastBottomLeft = vertices[i];
            lastBottomRight = vertices[i+1];
        }

        for (int j = 0; j < segY ; j++ ) {

           QVector3D nextBottomLeft = QVector3D(lastBottomLeft.x(), lastBottomLeft.y() + y_incrementent, lastBottomLeft.z());
           QVector3D nextBottomRight = QVector3D(lastBottomRight.x(), lastBottomRight.y() + y_incrementent, lastBottomRight.z());

           vertices.append(lastBottomLeft);
           vertices.append(lastBottomRight);
           vertices.append(nextBottomLeft);
           vertices.append(lastBottomRight);
           vertices.append(nextBottomLeft);
           vertices.append(nextBottomRight);

           lastBottomLeft = nextBottomLeft;
           lastBottomRight = nextBottomRight;
        }
    }
}

void Cylinder::setColors() {
  float r = 1.0, g = 0.0, b = 0.0;
  for (int i = 0; i < vertices.size() ; i++ ) {
      if(i%3 == 0){
          r = (rand()%256/255.0f);
          g = (rand()%256/255.0f);
          b = (rand()%256/255.0f);
      }
      colors.append(QVector3D(r,g,b));
  }
}

void Cylinder::draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY, GLenum mode) {
    glPolygonMode(GL_FRONT_AND_BACK, mode);
    setVertices(segmentsX, segmentsY);
    setColors();
    shaderProgram->setAttributeArray("vertex",vertices.constData());
    shaderProgram->enableAttributeArray("vertex");

    shaderProgram->setAttributeArray("color", colors.constData());
    shaderProgram->enableAttributeArray("color");

    glDrawArrays(GL_TRIANGLE_FAN, 0, segmentsX);
    glDrawArrays(GL_TRIANGLE_FAN, segmentsX , segmentsX);
    glDrawArrays(GL_TRIANGLES, 2*segmentsX  , vertices.size() - 2*segmentsX);

}

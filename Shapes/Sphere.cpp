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
    float x1, y1 , z1=0;
    float x2, y2 , z2=0;
    float x3, y3 , z3=0;
    float x4, y4 , z4=0;


    float increRad1 =(float)(PI/segX);
    float increRad2 =(float)(PI/segY);
    float phi;
    float teta;



    for (teta=0; teta<FinalTeta; teta+=increRad1){
        for (phi =0; phi<FinalPhi; phi+=increRad2){


            x1=radio*((float)sin(teta))*((float)sin(phi));
            y1=radio*((float)cos(teta));
            z1=radio*((float)sin(teta))*((float)cos(phi));


            x2=radio*((float)sin(teta+increRad1))*((float)sin(phi));
            y2=radio*((float)cos(teta+increRad1));
            z2=radio*((float)sin(teta+increRad1))*((float)cos(phi));


            x3=radio*((float)sin(teta+increRad1))*((float)sin(phi+increRad2));
            y3=radio*((float)cos(teta+increRad1));
            z3=radio*((float)sin(teta+increRad1))*((float)cos(phi+increRad2));


            x4=radio*((float)sin(teta))*((float)sin(phi+increRad2));
            y4=radio*((float)cos(teta));
            z4=radio*((float)sin(teta))*((float)cos(phi+increRad2));

            vertices << QVector3D(x1, y1, z1);
            vertices << QVector3D(x2, y2, z2);
            vertices << QVector3D(x3, y3, z3);
            vertices << QVector3D(x1, y1, z1);
            vertices << QVector3D(x3, y3, z3);
            vertices << QVector3D(x4, y4, z4);

        }
    }

}

void Sphere::setColors() {

    float r = 1.0 , g = 0.0 , b = 0.0;

    for (int i=0; i<vertices.length(); i++){

        if(i%3==0){
            r = (rand()%256)/255.0f;
            g = (rand()%256)/255.0f;
            b = (rand()%256)/255.0f;
        }
        colors << QVector3D(r, g, b);
    }

}

void Sphere::draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY) {
    setVertices(segmentsX, segmentsY);
    setColors();

    shaderProgram->setAttributeArray("vertex", vertices.constData());
    shaderProgram->enableAttributeArray("vertex");

    shaderProgram->setAttributeArray("color", colors.constData());
    shaderProgram->enableAttributeArray("color");

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    glShadeModel(GL_FLAT);
}

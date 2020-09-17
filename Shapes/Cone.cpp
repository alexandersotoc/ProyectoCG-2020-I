#include <QDebug>
#include <QVector3D>
#include <math.h>

#include "Cone.h"

#define PI 3.14159265358979323846

using namespace std;

void Cone::toString()
{
    qDebug() << "Cone shape was selected \n";
}

void Cone::setVertices(int segX, int segY)
{
    drawSideCone( 0.0f, 2.0f, 0.0f,  1.5f,  segX, 2.5f, segY);
    drawBaseCone(0.0f, -0.5f, 0.0f,  1.5f,  segX);
}

void Cone::setColors()
{
    float r, g, b;
    srand(6667);

    for (int i = 0; i < vertices.size(); i++)
    {
        if (i % 3 == 0)
        {
            r = (rand() % 256) / 255.0f;
            g = (rand() % 256) / 255.0f;
            b = (rand() % 256) / 255.0f;
        }

        colors.push_back(QVector3D(r, g, b));
    }
}

void Cone::draw(QOpenGLShaderProgram *shaderProgram, int segmentsX, int segmentsY)
{
    setVertices(segmentsX, segmentsY);
    setColors();

    shaderProgram->setAttributeArray("vertex", vertices.constData());
    shaderProgram->enableAttributeArray("vertex");

    shaderProgram->setAttributeArray("color", colors.constData());
    shaderProgram->enableAttributeArray("color");

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

void Cone::drawSideCone(float centerX, float centerY, float centerZ, float radius, int numberOfSides,
                                  float height, int segmentsY)
{

    float twicePi = 2.0f * 3.141592f;
    int numberOfVertices = (numberOfSides)*3;

    float verticesX[numberOfVertices];
    float verticesY[numberOfVertices];
    float verticesZ[numberOfVertices];

    float firstX;
    float firstY;
    float firstZ;

    int position = 0;

    for (int i = 0; i < numberOfSides; i++) {
        verticesX[position] = centerX + (radius * cos(i * twicePi / numberOfSides));
        verticesY[position] = centerY - height ;
        verticesZ[position] = centerZ + (radius * sin(i * twicePi / numberOfSides));

        if(i == 0){
            firstX = centerX + (radius * cos(i * twicePi / numberOfSides));
            firstY = centerY - height;
            firstZ = centerZ + (radius * sin(i * twicePi / numberOfSides));
            position++;
            verticesX[position] = centerX;
            verticesY[position] = centerY;
            verticesZ[position] = centerZ;
        }else{
            position++;
            verticesX[position] = centerX + (radius * cos(i * twicePi / numberOfSides));
            verticesY[position] = centerY - height ;
            verticesZ[position] = centerZ + (radius * sin(i * twicePi / numberOfSides));
            position++;
            verticesX[position] = centerX;
            verticesY[position] = centerY;
            verticesZ[position] = centerZ;
        }

        if(i==numberOfSides-1){
            position++;
            verticesX[position] = firstX;
            verticesY[position] = firstY;
            verticesZ[position] = firstZ;
        }

        position++;
    }

    for(int i=0; i<numberOfVertices; i+=3){
        int stepSegment = segmentsY;

        QVector3D left = QVector3D(verticesX[i], verticesY[i], verticesZ[i]);
        QVector3D medium = QVector3D(verticesX[i+1], verticesY[i+1], verticesZ[i+1]);
        QVector3D right = QVector3D(verticesX[i+2], verticesY[i+2], verticesZ[i+2]);

        QVector3D leftPoint = QVector3D(medium.x(), medium.y(), medium.z());
        QVector3D rightPoint = QVector3D(medium.x(), medium.y(), medium.z());

        QVector3D lastLeftPoint;
        QVector3D lastRightPoint;

        for(int j = 2; j <= segmentsY;j++){
            leftPoint.setX((left.x() -leftPoint.x())/stepSegment + leftPoint.x());
            rightPoint.setX((right.x() - rightPoint.x())/stepSegment + rightPoint.x());

            leftPoint.setY((left.y() -leftPoint.y())/stepSegment + leftPoint.y());
            rightPoint.setY((right.y() -rightPoint.y())/stepSegment + rightPoint.y());

            leftPoint.setZ((left.z() -leftPoint.z())/stepSegment + leftPoint.z());
            rightPoint.setZ((right.z() -rightPoint.z())/stepSegment + rightPoint.z());

            stepSegment--;

            if(j<3){
                vertices.push_back(medium);
                vertices.push_back(leftPoint);
                vertices.push_back(rightPoint);
            }else{

                vertices.push_back(lastLeftPoint);
                vertices.push_back(lastRightPoint);
                vertices.push_back(rightPoint);
                vertices.push_back(lastLeftPoint);
                vertices.push_back(leftPoint);
                vertices.push_back(rightPoint);

                if(j==segmentsY){
                    vertices.push_back(leftPoint);
                    vertices.push_back(rightPoint);
                    vertices.push_back(right);
                    vertices.push_back(leftPoint);
                    vertices.push_back(left);
                    vertices.push_back(right);
                }
            }

            lastLeftPoint.setX(leftPoint.x());
            lastLeftPoint.setY(leftPoint.y());
            lastLeftPoint.setZ(leftPoint.z());

            lastRightPoint.setX(rightPoint.x());
            lastRightPoint.setY(rightPoint.y());
            lastRightPoint.setZ(rightPoint.z());
        }
    }
}

void Cone::drawBaseCone(float centerX, float centerY, float centerZ, float radius, int numberOfSides)
{
    float twicePi = 2.0f * 3.141592f;
    int numberOfVertices = (numberOfSides)*3  ; // points + one center point.

    float verticesX[numberOfVertices];
    float verticesY[numberOfVertices];
    float verticesZ[numberOfVertices];

    float firstX;
    float firstY;
    float firstZ;

    int position = 0;

    for (int i = 0; i < numberOfSides; i++) {
        verticesX[position] = centerX + (radius * cos(i * twicePi / numberOfSides));
        verticesY[position] = centerY ;
        verticesZ[position] = centerZ + (radius * sin(i * twicePi / numberOfSides));

        if(i == 0){
            firstX = centerX + (radius * cos(i * twicePi / numberOfSides));
            firstY = centerY;
            firstZ = centerZ + (radius * sin(i * twicePi / numberOfSides));
            position++;
            verticesX[position] = centerX;
            verticesY[position] = centerY;
            verticesZ[position] = centerZ;
        }else{
            position++;
            verticesX[position] = centerX + (radius * cos(i * twicePi / numberOfSides));
            verticesY[position] = centerY ;
            verticesZ[position] = centerZ + (radius * sin(i * twicePi / numberOfSides));
            position++;
            verticesX[position] = centerX;
            verticesY[position] = centerY;
            verticesZ[position] = centerZ;
        }

        if(i==numberOfSides-1){
            position++;
            verticesX[position] = firstX;
            verticesY[position] = firstY;
            verticesZ[position] = firstZ;
        }

        position++;
    }

    for (int i = 0; i < numberOfVertices; i++) {
        vertices.push_back(QVector3D(verticesX[i], verticesY[i], verticesZ[i]));
    }
}

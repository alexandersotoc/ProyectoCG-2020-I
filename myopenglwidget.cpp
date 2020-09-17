#include "myopenglwidget.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>       /* time */
#include <iostream>
#include "Shapes/Shape.h" 
#define PI 3.14159265358979323846

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{
    alpha = 0;
    beta =  0;
    zeta =  0;
    distance = 6;
    segmentsX = 10;
    segmentsY = 10;
    currentShape = 1;
}

void MyOpenGLWidget::setDistance(int value)
{
    if(value>=100){
        distance = 6 - (value * 1.0f / 100);
    }else{
        distance = 6 + (value * 1.0f / 100);
    }

    update();
}

void MyOpenGLWidget::drawSphere()
{
}

void MyOpenGLWidget::rotateX(int rX)
{
    alpha = rX;
    update();
}

void MyOpenGLWidget::rotateY(int rY)
{
    beta = rY;
    update();
}

void MyOpenGLWidget::rotateZ(int rZ)
{
    zeta = rZ;
    update();
}

void MyOpenGLWidget::setSegmentsX(int _segmentsX)
{
    segmentsX = _segmentsX;
    update();
}

void MyOpenGLWidget::setSegmentsY(int _segmentsY)
{
    segmentsY = _segmentsY;
    update();
}

void MyOpenGLWidget::setCurrentShape(int _currentShape)
{
    currentShape = _currentShape;
    update();
}

void MyOpenGLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glClearColor(0, 0, 0, 1);

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragmentShader.fsh");
    shaderProgram.link();
    
    srand (time(NULL));
}

void MyOpenGLWidget::paintGL()
{

    Shape *chosenShape = Shape::chooseShape(currentShape);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

    QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 1, 0, 0);
    cameraTransformation.rotate(beta,  0, 1, 0);
    cameraTransformation.rotate(zeta,  0, 0, 1);

    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

    vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

    //! [3]
    shaderProgram.bind();

    shaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix);

    chosenShape->draw(&shaderProgram, segmentsX, segmentsY);

    shaderProgram.disableAttributeArray("vertex");

    shaderProgram.disableAttributeArray("color");

    shaderProgram.release();
}

void MyOpenGLWidget::resizeGL(int width, int height)
{
    if (height == 0)
    {
        height = 1;
    }

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);

    glViewport(0, 0, width, height);
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();

    event->accept();
}

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton)
    {
        alpha -= deltaX;
        while (alpha < 0)
        {
            alpha += 360;
        }
        while (alpha >= 360)
        {
            alpha -= 360;
        }

        beta -= deltaY;
        if (beta < -90)
        {
            beta = -90;
        }
        if (beta > 90)
        {
            beta = 90;
        }

        update();
    }

    lastMousePosition = event->pos();

    event->accept();
}

void MyOpenGLWidget::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    if (event->orientation() == Qt::Vertical)
    {
        if (delta < 0)
        {
            distance *= 1.1;
        }
        else if (delta > 0)
        {
            distance *= 0.9;
        }

        update();
    }

    event->accept();
}

void MyOpenGLWidget::qColorToRGB(const QColor &C, float &r, float &g, float &b) const
{
    r = normalize_0_1(C.red(), RGB_MIN, RGB_MAX);
    g = normalize_0_1(C.green(), RGB_MIN, RGB_MAX);
    b = normalize_0_1(C.blue(), RGB_MIN, RGB_MAX);
}

float MyOpenGLWidget::normalize_0_1(float val, float min, float max) const
{
    return (val - min) / (max - min);
}
double MyOpenGLWidget::generateRandomNumber()
{
    return ((double) rand() / (RAND_MAX));
}

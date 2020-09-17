#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QColor>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

#define RGB_MIN 0
#define RGB_MAX 255

class MyOpenGLWidget: public QOpenGLWidget
{
    Q_OBJECT
public:
    MyOpenGLWidget(QWidget *parent = nullptr);
    void setDistance(int value);
    void drawSphere();
    void setSegmentsX(int _segmentsX);
    void setSegmentsY(int _segmentsY);
    void setCurrentShape(int _currentShape);
    void rotateX(int rX);
    void rotateY(int rY);
    void rotateZ(int rZ);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
private:
    void qColorToRGB(const QColor &C, float &r, float &g, float &b) const;
    float normalize_0_1(float val, float min, float max) const;
    double generateRandomNumber();
    QMatrix4x4 pMatrix;
    QOpenGLShaderProgram shaderProgram;

    int currentShape;

    int segmentsX;
    int segmentsY;

    double alpha;
    double beta;
    double zeta;
    double distance;
    QPoint lastMousePosition;

};

#endif // MYOPENGLWIDGET_H

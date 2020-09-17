#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chkWire_stateChanged(int arg1)
{
    qDebug() << "Wire selected "<<arg1;
    ui->openGLWidget->setMode(GL_LINE);
}

void MainWindow::on_chkSmooth_stateChanged(int arg1)
{
    qDebug() << "Smooth selected "<<arg1;
}

void MainWindow::on_chkFill_stateChanged(int arg1)
{
    qDebug() << "Fill selected "<<arg1;
    ui->openGLWidget->setMode(GL_FILL);
}

void MainWindow::on_chkNormal_stateChanged(int arg1)
{
    qDebug() << "Normal selected "<<arg1;
    ui->openGLWidget->setMode(GL_POINT);
}

void MainWindow::on_chkStipple_stateChanged(int arg1)
{
    qDebug() << "Stipple selected "<<arg1;
    ui->openGLWidget->setMode(GL_POLYGON_STIPPLE);
}

void MainWindow::on_btnCube_clicked()
{
    qDebug() << "Cube";
    ui->openGLWidget->setCurrentShape(1);
}

void MainWindow::on_btnCylinder_clicked()
{
    qDebug() << "cylinder";
    ui->openGLWidget->setCurrentShape(2);
}

void MainWindow::on_btnCone_clicked()
{
    qDebug() << "cone";
    ui->openGLWidget->setCurrentShape(3);
}

void MainWindow::on_btnSphere_clicked()
{
    qDebug() << "sphere";
    ui->openGLWidget->setCurrentShape(4);
}

void MainWindow::on_btnSpecial_clicked()
{
    qDebug() << "special";
    ui->openGLWidget->setCurrentShape(5);
}

void MainWindow::on_sldSegmentsX_valueChanged(int value)
{
    ui->openGLWidget->setSegmentsX(value);
    QString s = QString::number(value);
    ui->lblSegmentsX->setText(s);
}

void MainWindow::on_sldSegmentsY_valueChanged(int value)
{
    ui->openGLWidget->setSegmentsY(value);
    QString s = QString::number(value);
    ui->lblSegmentsY->setText(s);
}

void MainWindow::on_sldRotateX_valueChanged(int value)
{
    ui->openGLWidget->rotateX(value);
    QString s = QString::number(value);
    ui->lblRotateX->setText(s);
}

void MainWindow::on_sldRotateY_valueChanged(int value)
{
    ui->openGLWidget->rotateY(value);
    QString s = QString::number(value);
    ui->lblRotateY->setText(s);
}

void MainWindow::on_sldRotateZ_valueChanged(int value)
{
    ui->openGLWidget->rotateZ(value);
    QString s = QString::number(value);
    ui->lblRotateZ->setText(s);
}

void MainWindow::on_sldScale_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->openGLWidget->setDistance(value);
    ui->lblScale->setText(s);
}



void MainWindow::on_chkColor_stateChanged(int arg1)
{
    ui->openGLWidget->setColor(arg1==2?true:false);
}

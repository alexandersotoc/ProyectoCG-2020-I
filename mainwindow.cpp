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
}

void MainWindow::on_chkSmooth_stateChanged(int arg1)
{
    qDebug() << "Smooth selected "<<arg1;
}

void MainWindow::on_chkFill_stateChanged(int arg1)
{
    qDebug() << "Fill selected "<<arg1;
}

void MainWindow::on_chkNormal_stateChanged(int arg1)
{
    qDebug() << "Normal selected "<<arg1;
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

void MainWindow::on_sldSegmentsX_sliderMoved(int position)
{
     qDebug() << "segmentsX position: "<<position;
     ui->openGLWidget->setSegmentsX(position);
}

void MainWindow::on_sldSegmentsY_sliderMoved(int position)
{
     qDebug() << "segmentsY position: "<<position;
     ui->openGLWidget->setSegmentsY(position);
}

void MainWindow::on_sldRotateX_sliderMoved(int position)
{
    qDebug() << "rotateX position: "<<position;
}

void MainWindow::on_sldRotateY_sliderMoved(int position)
{
    qDebug() << "rotateY position: "<<position;
}

void MainWindow::on_sldRotateZ_sliderMoved(int position)
{
    qDebug() << "rotateZ position: "<<position;
}

void MainWindow::on_sldScale_sliderMoved(int position)
{
    qDebug() << "scale position: "<<position;
    QString s = QString::number(position);
    ui->openGLWidget->setDistance(position);
    ui->lblScale->setText(s);
}

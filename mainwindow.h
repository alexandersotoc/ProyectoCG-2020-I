#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_chkWire_stateChanged(int arg1);

    void on_btnCube_clicked();

    void on_btnCylinder_clicked();

    void on_btnCone_clicked();

    void on_btnSphere_clicked();

    void on_btnSpecial_clicked();

    void on_chkSmooth_stateChanged(int arg1);

    void on_chkFill_stateChanged(int arg1);

    void on_chkNormal_stateChanged(int arg1);

    void on_sldSegmentsX_valueChanged(int value);

    void on_sldSegmentsY_valueChanged(int value);

    void on_sldRotateX_valueChanged(int value);

    void on_sldRotateY_valueChanged(int value);

    void on_sldRotateZ_valueChanged(int value);

    void on_sldScale_valueChanged(int value);

    void on_chkStipple_stateChanged(int arg1);

    void on_chkColor_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QFileDialog>
#include <QDoubleSpinBox>
#include <QMessageBox>
#include <QMainWindow>

#include "logic/facade.h"

#include "qtscenedrawer.h"
#include "normalizationdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setProjection();
    void setTransform();

private:
    Ui::MainWindow *ui;

    Facade facade;
    QtSceneDrawer drawer;

    NormalizationDialog::Result normalization;

    void selectFile();
    void loadFile();
    void showError(QString message);
    void updateEnabled();
    void setPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z, const obj3d::Point& point);
    obj3d::Point getPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z);
    void openNormilizationDialog();
    void updateUi();
};
#endif // MAINWINDOW_H

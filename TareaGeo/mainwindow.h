#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figurasGeo.h"
#include <QDesktopWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openPolygonWindow();

private:
    Ui::MainWindow *ui;
    PolygonDialog *myPolygonWindow;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(openPolygonWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPolygonWindow()
{
    myPolygonWindow = new PolygonDialog();
    myPolygonWindow->show();
    myPolygonWindow->setWindowTitle("Manejo de Transformaciones");
    QRect rec = QApplication::desktop()->screenGeometry();
    float height = rec.height();
    float width = rec.width();
    myPolygonWindow->move(0, height/2 - myPolygonWindow->geometry().height()/2);
}

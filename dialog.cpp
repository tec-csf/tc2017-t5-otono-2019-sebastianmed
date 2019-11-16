#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//BOTON PARA POLIGONOS
void Dialog::on_pushButton_clicked()
{
    Poligonos poligonos;
    poligonos.setModal(true);
    poligonos.exec();
}

//BOTON PARA ARCO
void Dialog::on_pushButton_2_clicked()
{
    Arcos arcos;
    arcos.setModal(true);
    arcos.exec();
}

//BOTON PARA CUBO
void Dialog::on_pushButton_3_clicked()
{
    Cubo cubo;
    cubo.setModal(true);
    cubo.exec();
}

//BOTON PARA PRISMA REC
void Dialog::on_pushButton_4_clicked()
{
    PrismaRec prismaRectangular;
    prismaRectangular.setModal(true);
    prismaRectangular.exec();
}

//BOTON PARA PRISMA TRI
void Dialog::on_pushButton_5_clicked()
{
    PrismaTri prismaTriangular;
    prismaTriangular.setModal(true);
    prismaTriangular.exec();
}

//BOTON PARA CONO
void Dialog::on_pushButton_6_clicked()
{
    Cono cono;
    cono.setModal(true);
    cono.exec();
}

#include "p_triangular.h"
#include "ui_prismatri.h"
#include <math.h>

//CONSTRUCTOR GENERAL DEL PRISMA TRIANGULAR
PrismaTri::PrismaTri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaTri)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 550.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

PrismaTri::~PrismaTri()
{
    delete ui;
}

//METODO PARA DIBUJAR EL PRISMA
void dibujarPrismaTri(QPainter & painter){

    int medida = 40;
    int medida2 = medida*2;
    int medida3 = 95;

    int x1 = 0;
    int y1 = -medida2;
    int x2 = -medida;
    int y2 = -medida3;
    int x3 = medida;
    int y3 = -medida3;
    int _x1 = 0;
    int _y1 = -medida2+medida2;
    int _x2 = -medida;
    int _y2 = -medida3+medida2;
    int _x3 = medida;
    int _y3 = -medida3+medida2;

    painter.drawLine(x1,y1,x2,y2);
    painter.drawLine(x1,y1,x3,y3);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(_x1,_y1,_x2,_y2);
    painter.drawLine(_x1,_y1,_x3,_y3);
    painter.drawLine(_x2,_y2,_x3,_y3);
    painter.drawLine(x1,y1,_x1,_y1);
    painter.drawLine(x2,y2,_x2,_y2);
    painter.drawLine(_x3,_y3,x3,y3);

}

//METODO PARA DIBUJAR EL PRISMA
void PrismaTri::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::red);
    pointPen.setWidth(1);
    painter.setPen(pointPen);


    if(dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujarPrismaTri(painter);
        }

    }

}

//BOTON DE DIBUJAR
void PrismaTri::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}


//BOTON DE TRASLADAR EL PRISMA
void PrismaTri::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();
    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

//BOTON PARA ROTAR EL PRISMA
void PrismaTri::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

//BOTON PARA QUITAR ZOOM
void PrismaTri::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

//BOTON PARA AUMENTAR EL ZOOM
void PrismaTri::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

//BOTON PARA REFLEJAR EL PRISMA EN LA HORIZONTAL
void PrismaTri::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

//BOTON PARA REFLEJAR EL PRISMA EN LA VERTICAL
void PrismaTri::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}

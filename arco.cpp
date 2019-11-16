#include "arco.h"
#include "ui_arcos.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

//CONSTRUCTOR GENERAL DEL ARCO
Arcos::Arcos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arcos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 550.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Arcos::~Arcos()
{
    delete ui;
}

//METODO PARA CREAR EL CIRCULO POR MEDIO DE OCTETOS DE LA CIRCUNFERENCIA.
void puntosCirculo(int & x, int & y, int & angulo, QPainter & painter) {

    int oct = (angulo - (angulo % 45)) / 45;
    double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
    double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

    if (oct > 0 || (oct == 0 && y > limit1))
        painter.drawPoint(x,-y);
    if (oct > 1 || (oct == 1 && y <= limit2))
        painter.drawPoint(y,-x);
    if (oct > 2 || (oct == 2 && y > limit1))
        painter.drawPoint(y,x);
    if (oct > 3 || (oct == 3 && y <= limit2))
        painter.drawPoint(x,y);
    if (oct > 4 || (oct == 4 && y > limit1))
        painter.drawPoint(-x,y);
    if (oct > 5 || (oct == 5 && y <= limit2))
        painter.drawPoint(-y,x);
    if (oct > 6 || (oct == 6 && y > limit1))
        painter.drawPoint(-y,-x);
    if (oct > 7 || (oct == 7 && y <= limit2))
        painter.drawPoint(-x,-y);

}

//METODO PARA CREAR EL ARCO
void dibujarArco(int angulo, int radio, QPainter & painter) {

    int x = 0;
    int y = radio;
    double p = 5.0/4.0-y;

    puntosCirculo(x, y, angulo, painter);

    while(y > x) {
        if(p < 0) {
            p += 2.0 * x + 3.0;
        }
        else {
            p += 2.0 * (x - y) + 5.0;
            y--;
        }

        x++;

        puntosCirculo(x, y, angulo, painter);

    }

}

//METODO PARA DIBUJAR EL ARCO
void Arcos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::red);
    pointPen.setWidth(1);
    painter.setPen(pointPen);

    if (dibuja) {

        QString radioStr = ui->boxRadio->toPlainText();
        QString anguloStr = ui->boxAngulo->toPlainText();

        int angulo = anguloStr.toInt();
        int radio = radioStr.toInt();

        if (!radioStr.isEmpty() && !anguloStr.isEmpty()) {

            for(int i=0; i<vecTrans.size(); ++i) {
                painter.setTransform(vecTrans[i],true);
                dibujarArco(angulo, radio,  painter);

            }

        }

    }

}

//BOTON PARA DIBUJAR
void Arcos::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}

//BOTON PARA TRASLADAR
void Arcos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

//BOTON PARA ROTAR
void Arcos::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

//BOTON PARA AUMENTAR ZOOM
void Arcos::on_pushButton_4_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

//BOTON PARA QUITAR EL ZOOM
void Arcos::on_pushButton_5_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

//BOTON PARA REFLEJAR EN LA VERTICAL
void Arcos::on_pushButton_6_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}

//BOTON PARA REFLEJAR EN LA HORIZONTAL
void Arcos::on_pushButton_7_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

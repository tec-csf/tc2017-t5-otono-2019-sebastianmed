#include "poligono.h"
#include "ui_poligonos.h"
#include <QMessageBox>
#include <math.h>
#include <QPainter>
#include <QLabel>

//CONSTRUCTOR GENERAL DEL POLIGONO
Poligonos::Poligonos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligonos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 550.0;
    yCentro = 300.0;
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);

}

Poligonos::~Poligonos()
{
    delete ui;
}

//METODO QUE CREAR EL POLIGONO
void dibujarPoligono(int lados, QPainter & painter) {

    double radio = 100;
    double angulo = (double)360.0/(double)lados;

    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;

    for(a = 1; a <= lados; a++) {
        xi = (radio * cos(angulo*a));
        yi = (radio * sin(angulo*a));

        xf = (radio * cos(angulo*(a+1)));
        yf = (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
    }

}

//METODO PARA DIBUJAR EL POLIGONO
void Poligonos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::red);
    pointPen.setWidth(1);
    painter.setPen(pointPen);
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));

    if (dibuja) {

        QString ladosStr = ui->boxXfin->toPlainText();

        if (!ladosStr.isEmpty()) {

            int lados = ladosStr.toInt();

            for(int i=0; i<vecTrans.size(); ++i) {
                painter.setTransform(vecTrans[i],true);
                dibujarPoligono(lados, painter);
            }

        }

    }

}

//BOTON PARA DIBUJAR EL POLIGONO
void Poligonos::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}

//BOTON PARA TRANSLADAR EL POLIGONO
void Poligonos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

//BOTON PARA ROTAR EL POLIGONO
void Poligonos::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

//BOTON PARA QUITAR EL ZOOM
void Poligonos::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

//BOTON PARA AUMENTAR EL ZOOM
void Poligonos::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

//BOTON PARA REFLEJAR EL POLIGONO EN LA HORIZONTAL
void Poligonos::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

//BOTON PARA REFLEJAR EL POLIGONO EN LA VERTICAL
void Poligonos::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}

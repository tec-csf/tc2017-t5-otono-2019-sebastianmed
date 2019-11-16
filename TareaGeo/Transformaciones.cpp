#include "Transformaciones.h"
#include "ui_Transformaciones.h"

Shower::Shower(QWidget *parent) : QDialog(parent), ui(new Ui::Shower)
{
    startingAngle = (float) 0;
    centered = false;
    ui->setupUi(this);
}


Shower::~Shower()
{
    delete ui;
}

void Shower::draw(QVector<QTransform> vector, QPolygon _poly, std::string _figure, int _size, int _sides, PolygonDialog* _parent)
{
    par = _parent;
    transforms = vector;
    figure = _figure;
    size = _size;
    sides = _sides;
    poly = _poly;
    if(!centered)
    {
        QTransform trans = QTransform();
        trans.translate(centerX, centerY);
        transforms.push_front(trans);
    }
    update();
}


void Shower::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    centerX = 450;
    centerY = 300;
    QPen linePen;
    linePen.setWidth(2);
    linePen.setColor(Qt::black);
    painter.setPen(linePen);

    if(figure == "Polígono")
    {
        for(int i = 0; i < transforms.size(); i++)
        {
            painter.setTransform(transforms[i], true);
            painter.drawPolygon(poly);
        }
    }
    else if(figure == "Cubo")
    {
        for(int i = 0; i < transforms.size(); i++)
        {
            painter.setTransform(transforms[i], true);
            painter.drawLine(poly[0], poly[1]);
            painter.drawLine(poly[1], poly[3]);
            painter.drawLine(poly[2], poly[3]);
            painter.drawLine(poly[0], poly[2]);

            painter.drawLine(poly[4], poly[5]);
            painter.drawLine(poly[5], poly[7]);
            painter.drawLine(poly[6], poly[7]);
            painter.drawLine(poly[4], poly[6]);

            painter.drawLine(poly[0], poly[4]);
            painter.drawLine(poly[1], poly[5]);
            painter.drawLine(poly[2], poly[6]);
            painter.drawLine(poly[3], poly[7]);
        }
    }
    else if(figure == "Cono")
    {
        float width = poly[4].x();
        float height = poly[4].y();
        int startX = poly[3].x();
        int startY = poly[3].y();
        QRectF rect(QPoint(poly[1].x(), poly[1].y() - height/2), QSize(width, height));
        for(int i = 0; i < transforms.size(); i++)
        {
            painter.setTransform(transforms[i], true);
            painter.drawEllipse(rect);
            painter.drawLine(poly[0], poly[1]);
            painter.drawLine(poly[0], poly[2]);
        }
    }
    else if(figure == "Arco")
    {
        float size = poly[1].x();
        float rad = poly[1].y() * 16;
        QRectF rect(QPoint(-size/2, -size/2), QSize(size, size));
        int startAngle = 0 * 16;
        for(int i = 0; i < transforms.size(); i++)
        {
            painter.setTransform(transforms[i], true);
            painter.drawArc(rect, startAngle, rad);
        }
    }
    else if(figure == "Prisma Triangular")
    {
        for(int i = 0; i < transforms.size(); i++)
        {
            painter.setTransform(transforms[i], true);
            painter.drawLine(poly[0], poly[2]);
            painter.drawLine(poly[0], poly[1]);
            painter.drawLine(poly[1], poly[2]);
            painter.drawLine(poly[0], poly[3]);
            painter.drawLine(poly[3], poly[4]);
            painter.drawLine(poly[3], poly[5]);
            painter.drawLine(poly[4], poly[5]);
            painter.drawLine(poly[1], poly[4]);
            painter.drawLine(poly[2], poly[5]);
        }
    }
    else if(figure == "Prisma Rectangular")
    {
        for(int i = 0; i < transforms.size(); i++)
        {
            painter.setTransform(transforms[i], true);
            painter.drawLine(poly[0], poly[1]);
            painter.drawLine(poly[0], poly[2]);
            painter.drawLine(poly[1], poly[3]);
            painter.drawLine(poly[2], poly[3]);

            painter.drawLine(poly[4], poly[5]);
            painter.drawLine(poly[4], poly[6]);
            painter.drawLine(poly[5], poly[7]);
            painter.drawLine(poly[6], poly[7]);

            painter.drawLine(poly[0], poly[4]);
            painter.drawLine(poly[1], poly[5]);
            painter.drawLine(poly[2], poly[6]);
            painter.drawLine(poly[3], poly[7]);
        }
    }
}

void Shower::closeEvent(QCloseEvent *)
{
    par->setCentered(false);
    par->resetTransforms();
}

void Shower::setCentered(bool _centered)
{
    centered = _centered;
}

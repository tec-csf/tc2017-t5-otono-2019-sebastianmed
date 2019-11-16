#include "figurasGeo.h"
#include "ui_figurasGeo.h"
#define PI (3.141592653589793)
PolygonDialog::PolygonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PolygonDialog)
{
    startingAngle = (float) 0;
    centered = false;
    ui->setupUi(this);
    connect(ui->updatePoly, SIGNAL(clicked()), this, SLOT(repaintWindow()));
    connect(ui->translateButton, SIGNAL(clicked()), this, SLOT(translate()));
    connect(ui->rotateButton, SIGNAL(clicked()), this, SLOT(rotate()));
    connect(ui->scaleButton, SIGNAL(clicked()), this, SLOT(scale()));
    connect(ui->reflectionXButton, SIGNAL(clicked()), this, SLOT(reflectX()));
    connect(ui->reflectionYButton, SIGNAL(clicked()), this, SLOT(reflectY()));
    connect(ui->clearTransformsButton, SIGNAL(clicked()), this, SLOT(clearVisualizator()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(updateValues(const QString&)));
    currentFigure = ui->comboBox->currentText().toStdString();
    updateValues( ui->comboBox->currentText());
    createPolygon();
}

PolygonDialog::~PolygonDialog()
{
    delete ui;
}

void PolygonDialog::repaintWindow()
{
    if(!centered)
    {
        shower = new Shower(this);
        shower->setWindowTitle("Visualizador");
        shower->move(width()+10 , height() - height()/1.5);
        QRect rec = QApplication::desktop()->screenGeometry();
        float h = rec.height();
        float w = rec.width();
        shower->setFixedSize((w-30) - width()+10, h-(h/4));
        shower->show();
        centered = true;
    }
    createPolygon();
    shower->draw(transforms, poly, currentFigure, size, sides, this);

}

void PolygonDialog::translate()
{
        if(!centered)
        {
            QMessageBox err;
            err.critical(0,"Error","Primero haz click en Iniciar Visualización");
            err.setFixedSize(900,500);
        }
        else
        {
            float dx = ui->translateX->text().toFloat();
            float dy = ui->translateY->text().toFloat();
            QTransform trans = QTransform();
            trans.translate(dx, dy);
            transforms.push_back(trans);
            shower->draw(transforms, poly, currentFigure, size, sides, this);
        }
}

void PolygonDialog::rotate()
{
    if(!centered)
    {
        QMessageBox err;
        err.critical(0,"Error","Primero haz click en Iniciar Visualización");
        err.setFixedSize(400,200);
    }
    else
    {
        float angle = ui->rotationAngle->text().toFloat();
        QTransform rot = QTransform();
        rot.rotate(angle);
        transforms.push_back(rot);
        shower->draw(transforms, poly, currentFigure, size, sides, this);
    }
}

void PolygonDialog::scale()
{
    if(!centered)
    {
        QMessageBox err;
        err.critical(0,"Error","Primero haz click en Iniciar Visualización");
        err.setFixedSize(400,200);
    }
    else
    {
        float scaleX = ui->scaleX->text().toFloat();
        float scaleY = ui->scaleY->text().toFloat();
        QTransform scale = QTransform();
        scale.scale(scaleX, scaleY);
        transforms.push_back(scale);
        shower->draw(transforms, poly, currentFigure, size, sides, this);
    }
}

void PolygonDialog::reflectX()
{
    if(!centered)
    {
        QMessageBox err;
        err.critical(0,"Error","Primero haz click en Iniciar Visualización");
        err.setFixedSize(400,200);
    }
    else
    {
        QTransform scale = QTransform();
        scale.scale(1, -1);
        transforms.push_back(scale);
        shower->draw(transforms, poly, currentFigure, size, sides, this);
    }
}

void PolygonDialog::reflectY()
{
    if(!centered)
    {
        QMessageBox err;
        err.critical(0,"Error","Primero haz click en Iniciar Visualización");
        err.setFixedSize(400,200);
    }
    else
    {
        QTransform scale = QTransform();
        scale.scale(-1, 1);
        transforms.push_back(scale);
        shower->draw(transforms, poly, currentFigure, size, sides, this);
    }
}

void PolygonDialog::updateValues(const QString& choice)
{
    if(choice == "Polígono")
    {
        ui->prismSize->setEnabled(false);
        ui->arcSize->setEnabled(false);
        ui->radius->setEnabled(false);
        ui->sides->setEnabled(true);
        ui->size->setEnabled(true);

        ui->configArco1->setEnabled(false);
        ui->configArco2->setEnabled(false);
        ui->configPoligono1->setEnabled(true);
        ui->configPoligono2->setEnabled(true);
        ui->configPrismas->setEnabled(false);

        ui->configArco3->setEnabled(false);
        ui->confingPoligono3->setEnabled(true);
        ui->configPrismas1->setEnabled(false);
    }
    else if(choice == "Arco")
    {
        ui->size->setEnabled(false);
        ui->prismSize->setEnabled(false);
        ui->sides->setEnabled(false);
        ui->arcSize->setEnabled(true);
        ui->radius->setEnabled(true);

        ui->configArco1->setEnabled(true);
        ui->configArco2->setEnabled(true);
        ui->configPoligono1->setEnabled(false);
        ui->configPoligono2->setEnabled(false);
        ui->configPrismas->setEnabled(false);

        ui->configArco3->setEnabled(true);
        ui->confingPoligono3->setEnabled(false);
        ui->configPrismas1->setEnabled(false);
    }
    else if(choice == "Cubo")
    {
        ui->size->setEnabled(false);
        ui->prismSize->setEnabled(true);
        ui->sides->setEnabled(false);
        ui->arcSize->setEnabled(false);
        ui->radius->setEnabled(false);

        ui->configArco1->setEnabled(false);
        ui->configArco2->setEnabled(false);
        ui->configPoligono1->setEnabled(false);
        ui->configPoligono2->setEnabled(false);
        ui->configPrismas->setEnabled(true);

        ui->configArco3->setEnabled(false);
        ui->confingPoligono3->setEnabled(false);
        ui->configPrismas1->setEnabled(true);
    }
    else if(choice == "Cono")
    {
        ui->size->setEnabled(false);
        ui->prismSize->setEnabled(true);
        ui->sides->setEnabled(false);
        ui->arcSize->setEnabled(false);
        ui->radius->setEnabled(false);

        ui->configArco1->setEnabled(false);
        ui->configArco2->setEnabled(false);
        ui->configPoligono1->setEnabled(false);
        ui->configPoligono2->setEnabled(false);
        ui->configPrismas->setEnabled(true);

        ui->configArco3->setEnabled(false);
        ui->confingPoligono3->setEnabled(false);
        ui->configPrismas1->setEnabled(true);
    }
    else if(choice == "Prisma Triangular")
    {
        ui->size->setEnabled(false);
        ui->prismSize->setEnabled(true);
        ui->sides->setEnabled(false);
        ui->arcSize->setEnabled(false);
        ui->radius->setEnabled(false);

        ui->configArco1->setEnabled(false);
        ui->configArco2->setEnabled(false);
        ui->configPoligono1->setEnabled(false);
        ui->configPoligono2->setEnabled(false);
        ui->configPrismas->setEnabled(true);

        ui->configArco3->setEnabled(false);
        ui->confingPoligono3->setEnabled(false);
        ui->configPrismas1->setEnabled(true);
    }
    else if(choice == "Prisma Rectangular")
    {
        ui->size->setEnabled(false);
        ui->prismSize->setEnabled(true);
        ui->sides->setEnabled(false);
        ui->arcSize->setEnabled(false);
        ui->radius->setEnabled(false);

        ui->configArco1->setEnabled(false);
        ui->configArco2->setEnabled(false);
        ui->configPoligono1->setEnabled(false);
        ui->configPoligono2->setEnabled(false);
        ui->configPrismas->setEnabled(true);

        ui->configArco3->setEnabled(false);
        ui->confingPoligono3->setEnabled(false);
        ui->configPrismas1->setEnabled(true);
    }
    if(centered)
    {
        poly.clear();
        resetTransforms();
        currentFigure = choice.toStdString();
        createPolygon();
        shower->draw(transforms, poly, currentFigure, size, sides, this);
    }
}

void PolygonDialog::clearVisualizator()
{
    if(centered)
    {
        transforms.clear();
        shower->draw(transforms, poly, currentFigure, size, sides, this);
    }
}

void PolygonDialog::createPolygon()
{
     poly.clear();
    std::string choice = ui->comboBox->currentText().toStdString();
    QString s = ui->comboBox->currentText();
    if(choice == "Polígono")
    {
        currentFigure = "Polígono";
        if(!ui->sides->text().isNull() && !ui->size->text().isNull())
        {
            size = ui->size->text().toInt();
            sides = ui->sides->text().toInt();
            float angle = (float)360.0 / (float)sides;
            val = PI / (float)180;
            angle *= val;
            startingAngle *= val;
            for(int i = 0; i<sides; i++)
            {
                float xi = (size * cos(startingAngle));
                float yi = (size * sin(startingAngle));
                QPoint start(xi,yi);
                poly << start;
                startingAngle += angle;
            }
        }
        else
        {
            QMessageBox err;
            err.critical(0,"Error","Valores no configurados");
            err.setFixedSize(400,200);
        }
    }
    else if(choice == "Arco")
    {
        currentFigure = "Arco";
        QPoint p(0,0);
        QPoint rad(ui->arcSize->text().toFloat(), ui->radius->text().toFloat());
        poly << p << rad;
    }
    else if(choice == "Cubo")
    {
        currentFigure = "Cubo";
        float size = ui->prismSize->text().toFloat();
        QPoint p1(-size,size);
        QPoint p2(size, size);
        QPoint p3(-size, -size);
        QPoint p4(size, -size);
        float distProp = (p1.x()-p2.x())/2;
        QPoint p5(-size+distProp,size-distProp);
        QPoint p6(size+distProp, size-distProp);
        QPoint p7(-size+distProp, -size-distProp);
        QPoint p8(size+distProp, -size-distProp);
        poly << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8;
    }
    else if(choice == "Cono")
    {
        currentFigure = "Cono";
        float size = ui->prismSize->text().toFloat();
        QPoint vert(0,size);
        QPoint left(-size,0);
        QPoint right(size,0);
        QPoint start(-size,0);
        QPoint wh(size*2,size/2);
        poly << vert << left << right << start << wh;

    }
    else if(choice == "Prisma Triangular")
    {
        currentFigure = "Prisma Triangular";
        float size = ui->prismSize->text().toFloat();
        QPoint p1(0, size*2 - size);
        QPoint p2(-size, size*3 - size);
        QPoint p3(size, size*3 - size);
        QPoint p4(0,-size);
        QPoint p5(-size,size - size);
        QPoint p6(size,size - size);
        poly << p1 << p2 << p3 << p4 << p5 << p6;

    }
    else if(choice == "Prisma Rectangular")
    {
        currentFigure = "Prisma Rectangular";
        float size = ui->prismSize->text().toFloat();
        QPoint p0(-size,-2*size);
        QPoint p1(2*size-size,-2*size);
        QPoint p2(-size,4*size-2*size);
        QPoint p3(2*size-size,4*size-2*size);

        QPoint p4(-1.5*size-size,-1.5*size-2*size);
        QPoint p5(0.5*size-size,-1.5*size-2*size);
        QPoint p6(-1.5*size-size,2.5*size-2*size);
        QPoint p7(0.5*size-size,2.5*size-2*size);
        poly << p0 << p1 << p2 << p3 << p4 << p5 << p6 << p7;
    }
}

void PolygonDialog::closeEvent(QCloseEvent *)
{
    setCentered(false);
}

void PolygonDialog::setCentered(bool _centered)
{
    centered = _centered;
}

void PolygonDialog::resetTransforms()
{
    transforms.clear();
}

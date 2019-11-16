#ifndef Transformaciones_H
#define Transformaciones_H

#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QDebug>
#include "math.h"
#include <QMessageBox>
#include <iostream>
class PolygonDialog;

namespace Ui {
class Shower;
}

class Shower : public QDialog
{
    Q_OBJECT

public:
    explicit Shower(QWidget *_parent = 0);
    ~Shower();
    void draw(QVector<QTransform> vector, QPolygon _poly, std::string _figure, int _size, int _sides, PolygonDialog* _parent);

private:
    PolygonDialog *par;
    Ui::Shower *ui;
    QVector<QTransform> transforms;
    QPolygon poly;
    int centerX;
    int centerY;
    int size;
    float startingAngle;
    int sides;
    bool centered;
    float val;
    std::string figure;

protected:
    void paintEvent(QPaintEvent* e);
    void closeEvent(QCloseEvent *);
    void setCentered(bool _centered);
};
#include "figurasGeo.h"
#endif // Transformaciones.h

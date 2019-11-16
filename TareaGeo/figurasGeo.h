#ifndef POLYGONDIALOG_H
#define POLYGONDIALOG_H

#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QDebug>
#include "math.h"
#include <QMessageBox>
#include "Transformaciones.h"
#include <iostream>
#include <QDesktopWidget>

namespace Ui {
class PolygonDialog;
}

class PolygonDialog : public QDialog
{
    Q_OBJECT

public:
    Shower* shower;
    explicit PolygonDialog(QWidget *parent = 0);
    ~PolygonDialog();
    void setCentered(bool _centered);
    void resetTransforms();

private:
    Ui::PolygonDialog *ui;
    QPolygon poly;
    int centerX;
    int centerY;
    int size;
    float startingAngle;
    int sides;
    bool centered;
    float val;
    QVector<QTransform> transforms;
    std::string currentFigure;

protected:
    void createPolygon();
    void closeEvent(QCloseEvent *);

public slots:
    void repaintWindow();
    void translate();
    void rotate();
    void scale();
    void reflectX();
    void reflectY();
    void updateValues(const QString& choice);
    void clearVisualizator();
};

#endif // POLYGONDIALOG_H

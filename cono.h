#ifndef CONO_H
#define CONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "transformaciones.h"

namespace Ui {
class Cono;
}

class Cono : public QDialog
{
    Q_OBJECT

public:
    explicit Cono(QWidget *parent = 0);
    ~Cono();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::Cono *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;
};

#endif // CONO_H

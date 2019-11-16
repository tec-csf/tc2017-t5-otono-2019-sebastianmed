#ifndef ARCOS_H
#define ARCOS_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "transformaciones.h"

namespace Ui {
class Arcos;
}

class Arcos : public QDialog
{
    Q_OBJECT

public:
    explicit Arcos(QWidget *parent = 0);
    ~Arcos();

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
    Ui::Arcos *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;

};

#endif // ARCOS_H

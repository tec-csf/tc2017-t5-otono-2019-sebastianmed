#ifndef PRISMAREC_H
#define PRISMAREC_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "transformaciones.h"

namespace Ui {
class PrismaRec;
}

class PrismaRec : public QDialog
{
    Q_OBJECT

public:
    explicit PrismaRec(QWidget *parent = 0);
    ~PrismaRec();

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
    Ui::PrismaRec *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;

};

#endif // PRISMAREC_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "poligono.h"
#include "arco.h"
#include "cubo.h"
#include "p_rectangular.h"
#include "p_triangular.h"
#include "cono.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Dialog *ui;
    //permite multiples ventanas de poligonos
    //Poligonos *poligonos;

};

#endif // DIALOG_H

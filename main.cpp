#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}


//Parte del código sacado de: https://github.com/yocoHM/GeometriaComputacional con las modificaciones necesarias para este proyecto.

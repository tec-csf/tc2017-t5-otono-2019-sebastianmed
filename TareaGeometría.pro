
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TareaGeometría
TEMPLATE = app


SOURCES += main.cpp\
    arco.cpp \
        dialog.cpp \
    p_rectangular.cpp \
    p_triangular.cpp \
    cubo.cpp \
    cono.cpp \
    poligono.cpp \
    transformaciones.cpp

HEADERS  += dialog.h \
    arco.h \
    cubo.h \
    p_rectangular.h \
    p_triangular.h \
    poligono.h \
    cono.h \
    transformaciones.h

FORMS    += dialog.ui \
    arco.ui \
    cubo.ui \
    p_rectangular.ui \
    p_triangular.ui \
    poligono.ui \
    cono.ui

CONFIG-=app_bundle

DISTFILES +=

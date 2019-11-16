QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TareaGeo
TEMPLATE = app


SOURCES += main.cpp\
    Transformaciones.cpp \
    figurasGeo.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    Transformaciones.h \
    figurasGeo.h

FORMS    += \
    figurasGeo.ui \
    mainwindow.ui \
    Transformaciones.ui



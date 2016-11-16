#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T12:06:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = GeneticPlotter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

RC_FILE = iconka.rc #файл устанавливающий иконку, версию, создателя...

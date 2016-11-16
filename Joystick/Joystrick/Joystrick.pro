#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T14:49:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Joystrick
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L D:/libs/SDL-1.2.15/lib -lSDL
INCLUDEPATH += D:/libs/SDL-1.2.15/include/SDL

#LIBS +=-lSDL
#LIBS += -LC:/Qt/SDL-1.2.14/lib
#LIBS += -lmingw32
#LIBS += -llibSDL
#LIBS += -luser32 -lgdi32 -lwinmm -ldxguid


#DEFINES += _WIN32 WIN32

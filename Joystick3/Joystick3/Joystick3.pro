QT += core
QT -= gui

CONFIG += c++11

TARGET = Joystick3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

LIBS += -L D:/libs/SDL-1.2.15/lib -lSDL
INCLUDEPATH += D:/libs/SDL-1.2.15/include/SDL

LIBS += -lmingw32
LIBS += -llibSDL
LIBS += -luser32 -lgdi32 -lwinmm -ldxguid

#DEFINES += _WIN32 WIN32

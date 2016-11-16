TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -L D:/libs/SDL-1.2.15/lib -lSDL
INCLUDEPATH += D:/libs/SDL-1.2.15/include/SDL

LIBS += -lmingw32
LIBS += -llibSDL
LIBS += -luser32 -lgdi32 -lwinmm -ldxguid

DEFINES += _WIN32 WIN32

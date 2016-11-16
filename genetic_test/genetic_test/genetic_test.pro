TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += -LD:\libs\SFML-2.0_MinGW\lib



CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += D:\libs\SFML-2.0_MinGW\include
DEPENDPATH += D:\libs\SFML-2.0_MinGW\include

include(deployment.pri)
qtcAddDeployment()



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../libs/ -lopengl32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../libs/ -lopengl32
else:unix: LIBS += -L$$PWD/../../../libs/ -lopengl32

INCLUDEPATH += $$PWD/../../../libs
DEPENDPATH += $$PWD/../../../libs

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../libs/ -lglu32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../libs/ -lglu32
else:unix: LIBS += -L$$PWD/../../../libs/ -lglu32

INCLUDEPATH += $$PWD/../../../libs
DEPENDPATH += $$PWD/../../../libs

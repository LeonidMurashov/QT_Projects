TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH += C:\\OpenCV-3.0.0\\opencv\\build\\include
LIBS += -LC:\\OpenCV-3.0.0\\mybuild\\lib\\Debug \
 -lopencv_imgcodecs300d \
 -lopencv_imgproc300d \
 -lopencv_ml300d \
 -lopencv_objdetect300d \
 -lopencv_photo300d \
 -lopencv_shape300d \
 -lopencv_stitching300d \
 -lopencv_superres300d \
 -lopencv_ts300d \
 -lopencv_video300d \
 -lopencv_videoio300d \
 -lopencv_videostab300d \
 -lopencv_calib3d300d \
 -lopencv_core300d \
 -lopencv_features2d300d \
 -lopencv_flann300d \
 -lopencv_hal300d \
 -lopencv_highgui300d



LIBS += -LD:\libs\SFML-2.2\lib



CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += D:\libs\SFML-2.2\include
DEPENDPATH += D:\libs\SFML-2.2\include


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


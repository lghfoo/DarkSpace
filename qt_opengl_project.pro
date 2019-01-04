QT += core gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    spacelib/spacewindow.cpp \
    spacelib/vertex3d.cpp \
    spacelib/spaceobject.cpp \
    spacelib/line3d.cpp \
    spacelib/space3d.cpp \
    game_dark_space/darkspace.cpp \
    spacelib/shader.cpp \
    spacelib/camera3d.cpp \
    spacelib/transform3d.cpp \
    spacelib/input.cpp \
    spacelib/polygon3d.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    spacelib/spacewindow.h \
    spacelib/vertex3d.h \
    spacelib/spaceobject.h \
    spacelib/util.h \
    spacelib/line3d.h \
    spacelib/spacemesh.h \
    spacelib/space3d.h \
    game_dark_space/darkspace.h \
    spacelib/shader.h \
    spacelib/camera3d.h \
    spacelib/transform3d.h \
    spacelib/input.h \
    spacelib/polygon3d.h

DISTFILES += \
    space_shaders/simple_fragment_shader.fsh \
    space_shaders/simple_vertex_shader.vsh

RESOURCES += \
    resources.qrc

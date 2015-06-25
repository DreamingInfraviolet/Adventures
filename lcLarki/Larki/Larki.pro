#-------------------------------------------------
#
# Project created by QtCreator 2015-05-27T18:48:01
#
#-------------------------------------------------

QT       += core gui opengl
QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Larki
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    world.cpp \
    canvas.cpp \
    layer.cpp \
    camera.cpp \
    matrixd.cpp \
    image.cpp \
    imagegpu.cpp \
    shaderprogram.cpp \
    io.cpp \
    mainshader.cpp \
    vertex.cpp \
    cursor.cpp \
    tile.cpp \
    rectangle.cpp \
    pixelargb.cpp \
    virtualtilegrid.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    world.h \
    canvas.h \
    layer.h \
    camera.h \
    matrixd.h \
    image.h \
    imagegpu.h \
    shaderprogram.h \
    io.h \
    mainshader.h \
    vertex.h \
    cursor.h \
    tile.h \
    rectangle.h \
    pixelargb.h \
    virtualtilegrid.h

FORMS    += mainwindow.ui

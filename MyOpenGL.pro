#-------------------------------------------------
#
# Project created by QtCreator 2013-09-25T09:11:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyOpenGL
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        window.cpp \
    myglwidget.cpp \
    Graphicobject.cpp\
    Edge.cpp\
    Vertex.cpp\
    Triangle.cpp

HEADERS  += window.h \
    myglwidget.h \
    Graphicobject.h \
    Edge.h \
    Vertex.h \
    Triangle.h 

FORMS    += window.ui

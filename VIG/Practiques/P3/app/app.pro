#-------------------------------------------------
#
# Project created by QtCreator 2010-09-29T17:51:16
#
#-------------------------------------------------

QT       += opengl

TARGET = PracticaVIG
TEMPLATE = app

INCLUDEPATH += ../widget ../materialwidget ../lightwidget/
LIBS += ../widget/libglwidgetplugin.so
LIBS += ../materialwidget/libmaterialwidget.so ../colorwidget/libcolorwidget.so
LIBS += ../lightwidget/liblightwidget.so

SOURCES += main.cpp\
        principal.cpp

HEADERS  += principal.h

FORMS    += principal.ui

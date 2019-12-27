
CONFIG += designer \
    plugin
TARGET = $$qtLibraryTarget(lightwidget)

TEMPLATE = lib

INCLUDEPATH +=  ../colorwidget
HEADERS = lightwidgetplugin.h lightwidget.h
SOURCES = lightwidgetplugin.cpp lightwidget.cpp
LIBS += -L.

target.path = ~/.designer/plugins/designer
INSTALLS += target

FORMS += lightwidget.ui

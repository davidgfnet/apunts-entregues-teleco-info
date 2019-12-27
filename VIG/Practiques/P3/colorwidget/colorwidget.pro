
CONFIG += designer \
    plugin
TARGET = $$qtLibraryTarget(colorwidget)

TEMPLATE = lib

HEADERS = colorwidgetplugin.h colorwidget.h
SOURCES = colorwidgetplugin.cpp colorwidget.cpp
LIBS += -L.

target.path = ~/.designer/plugins/designer
INSTALLS += target

FORMS += colorwidget.ui

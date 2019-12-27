
CONFIG += designer \
    plugin
TARGET = $$qtLibraryTarget(materialwidget)

TEMPLATE = lib

INCLUDEPATH +=  ../colorwidget
HEADERS = materialwidgetplugin.h materialwidget.h
SOURCES = materialwidgetplugin.cpp materialwidget.cpp
LIBS += -L.

target.path = ~/.designer/plugins/designer
INSTALLS += target

FORMS += materialwidget.ui

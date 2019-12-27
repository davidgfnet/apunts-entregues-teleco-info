
CONFIG+=designer plugin release
TEMPLATE=lib
HEADERS += CustomLabel.h CustomLabelPlugin.h
SOURCES += CustomLabel.cpp CustomLabelPlugin.cpp
target.path = ~/.designer/plugins/designer
INSTALLS += target
INCLUDEPATH += ./../

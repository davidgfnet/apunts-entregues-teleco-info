
#include <QtCore/QtPlugin>
#include "CustomLabel.h"
#include "CustomLabelPlugin.h"

CustomLabelPlugin::CustomLabelPlugin(QObject *parent) 
		   : QObject(parent) {
    m_initialized = false;
}

void CustomLabelPlugin::initialize(QDesignerFormEditorInterface* /* core */) {
    if (m_initialized)
        return;

    m_initialized = true;
}

bool CustomLabelPlugin::isInitialized() const {
    return m_initialized;
}

QWidget *CustomLabelPlugin::createWidget(QWidget *parent) {
    return new CustomLabel(QString("Escriba texto aquí"),parent);
}

QString CustomLabelPlugin::name() const {
    return QLatin1String("CustomLabel");
}

QString CustomLabelPlugin::group() const {
    return QLatin1String("Mis widgets");
}

QIcon CustomLabelPlugin::icon() const {
    return QIcon();
}

QString CustomLabelPlugin::toolTip() const {
    return QString("Crea un label capaz de añadir ciertos carácteres");
}

QString CustomLabelPlugin::whatsThis() const {
    return QString("Crea un label capaz de añadir ciertos carácteres");
}

bool CustomLabelPlugin::isContainer() const {
    return false;
}

QString CustomLabelPlugin::domXml() const {
    return QLatin1String("<widget class=\"CustomLabel\" name=\"aLabel\">\n</widget>\n");
}

QString CustomLabelPlugin::includeFile() const {
    return QLatin1String("CustomLabel.h");
}

Q_EXPORT_PLUGIN2(CustomLabelPlugin, CustomLabelPlugin)


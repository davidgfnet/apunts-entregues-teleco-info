
#include "materialwidgetplugin.h"
#include "materialwidget.h"

#include <QtCore/QtPlugin>

MaterialWidgetPlugin::MaterialWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MaterialWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MaterialWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MaterialWidgetPlugin::createWidget(QWidget *parent)
{
    return new MaterialWidget(parent);
}

QString MaterialWidgetPlugin::name() const
{
    return QLatin1String("MaterialWidget");
}

QString MaterialWidgetPlugin::group() const
{
    return QLatin1String("Els Meus Widgets");
}

QIcon MaterialWidgetPlugin::icon() const
{
    return QIcon();
}

QString MaterialWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MaterialWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MaterialWidgetPlugin::isContainer() const
{
    return false;
}

QString MaterialWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MaterialWidget\" name=\"MaterialWidget\">\n</widget>\n");
}

QString MaterialWidgetPlugin::includeFile() const
{
    return QLatin1String("materialwidget.h");
}

Q_EXPORT_PLUGIN2(MaterialWidgetPlugin, MaterialWidgetPlugin)

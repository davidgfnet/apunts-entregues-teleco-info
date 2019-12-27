
#include "lightwidgetplugin.h"
#include "lightwidget.h"

#include <QtCore/QtPlugin>

LightWidgetPlugin::LightWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void LightWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LightWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *LightWidgetPlugin::createWidget(QWidget *parent)
{
    return new LightWidget(parent);
}

QString LightWidgetPlugin::name() const
{
    return QLatin1String("LightWidget");
}

QString LightWidgetPlugin::group() const
{
    return QLatin1String("Els Meus Widgets");
}

QIcon LightWidgetPlugin::icon() const
{
    return QIcon();
}

QString LightWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString LightWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool LightWidgetPlugin::isContainer() const
{
    return false;
}

QString LightWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"LightWidget\" name=\"LightWidget\">\n</widget>\n");
}

QString LightWidgetPlugin::includeFile() const
{
    return QLatin1String("lightwidget.h");
}

Q_EXPORT_PLUGIN2(LightWidgetPlugin, LightWidgetPlugin)

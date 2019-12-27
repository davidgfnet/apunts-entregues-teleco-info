
#include "colorwidgetplugin.h"
#include "colorwidget.h"

#include <QtCore/QtPlugin>

ColorWidgetPlugin::ColorWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ColorWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ColorWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ColorWidgetPlugin::createWidget(QWidget *parent)
{
    return new ColorWidget(parent);
}

QString ColorWidgetPlugin::name() const
{
    return QLatin1String("ColorWidget");
}

QString ColorWidgetPlugin::group() const
{
    return QLatin1String("Els Meus Widgets");
}

QIcon ColorWidgetPlugin::icon() const
{
    return QIcon();
}

QString ColorWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ColorWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ColorWidgetPlugin::isContainer() const
{
    return false;
}

QString ColorWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"ColorWidget\" name=\"ColorWidget\">\n</widget>\n");
}

QString ColorWidgetPlugin::includeFile() const
{
    return QLatin1String("colorwidget.h");
}

Q_EXPORT_PLUGIN2(ColorWidgetPlugin, ColorWidgetPlugin)

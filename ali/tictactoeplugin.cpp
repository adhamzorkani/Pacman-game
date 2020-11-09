#include "tictactoe.h"
#include "tictactoeplugin.h"

#include <QtPlugin>

TICTACTOEPlugin::TICTACTOEPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TICTACTOEPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TICTACTOEPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TICTACTOEPlugin::createWidget(QWidget *parent)
{
    return new TICTACTOE(parent);
}

QString TICTACTOEPlugin::name() const
{
    return QLatin1String("TICTACTOE");
}

QString TICTACTOEPlugin::group() const
{
    return QLatin1String("");
}

QIcon TICTACTOEPlugin::icon() const
{
    return QIcon();
}

QString TICTACTOEPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TICTACTOEPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TICTACTOEPlugin::isContainer() const
{
    return false;
}

QString TICTACTOEPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TICTACTOE\" name=\"tICTACTOE\">\n</widget>\n");
}

QString TICTACTOEPlugin::includeFile() const
{
    return QLatin1String("tictactoe.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(tictactoeplugin, TICTACTOEPlugin)
#endif // QT_VERSION < 0x050000

#include "tcdesignercomponent.h"

#include "actionboxplugin.h"
#include "actionlabelplugin.h"
#include "actiongroupplugin.h"
#include "actionpanelplugin.h"
#include "colorgridplugin.h"
#include "tcdateeditplugin.h"

#include <QtPlugin>

TcDesignerWidgets::TcDesignerWidgets(QObject *parent)
    : QObject(parent)
{
    m_plugins.append(new ActionBoxPlugin(this));
    m_plugins.append(new ActionLabelPlugin(this));
    m_plugins.append(new ActionGroupPlugin(this));
    m_plugins.append(new ActionPanelPlugin(this));
    m_plugins.append(new ColorGridPlugin(this));
    m_plugins.append(new TcDateEditPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> TcDesignerWidgets::customWidgets() const
{
    return m_plugins;
}

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
Q_EXPORT_PLUGIN(TcDesignerWidgets)
#endif

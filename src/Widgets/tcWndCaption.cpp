#include "tcWndCaption.h"

#include <QMainWindow>
#include <QStyleOption>
#include <QPainter>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QMouseEvent>

#include <QDebug>

TcWndCaption::TcWndCaption(QWidget* parent, const QString& title, const QIcon& icon)
    : QWidget(parent)
{
    m_parentForm = parent;
    if ( m_parentForm != nullptr )
    {
        m_parentForm->setStyleSheet(QString(m_parentForm->metaObject()->className())
                                    + "#"
                                    + m_parentForm->objectName()
                                    + "{border: 1px solid #4a8fda}");
        if ( m_parentForm->layout() != nullptr )
        {
            m_parentForm->layout()->setContentsMargins(1,1,1,1);
            m_parentForm->layout()->setSpacing(0);
        }
    }

    setObjectName("wndCaption");
    setStyleSheet("TcWndCaption#wndCaption{ background-color: rgb(85, 170, 255); }");

    const int FIXED_HEIGHT = 24;
    setMinimumHeight(FIXED_HEIGHT);
    setMaximumHeight(FIXED_HEIGHT);

    setContentsMargins(8,0,0,0);
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->setContentsMargins(0,0,0,0);
    setLayout(hLayout);

    m_titleLabel = new QLabel(this);
    QFont font = m_titleLabel->font();
    font.setFamily("微软雅黑");
    font.setPointSize(11);
    m_titleLabel->setFont(font);
    m_titleLabel->setStyleSheet("color:white;");

    m_titleLabel->setText(title);
    hLayout->addWidget(m_titleLabel);

    QSpacerItem* spacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed);
    hLayout->addSpacerItem(spacer);

    m_bnClose = new QToolButton(this);
    m_bnClose->setMinimumSize(FIXED_HEIGHT, FIXED_HEIGHT);
    m_bnClose->setMaximumSize(FIXED_HEIGHT, FIXED_HEIGHT);
    m_bnClose->setStyleSheet("QToolButton{border: 0px}"
                             "QToolButton:hover{border: 0px solid;background-color:rgb(212,64,39);}");
    m_bnClose->setIcon(icon);
    if ( parent != nullptr )
    {
        connect(m_bnClose, &QToolButton::clicked, parent, &QWidget::close);
    }
    hLayout->addWidget(m_bnClose);

    installEventFilter(this);
}

bool TcWndCaption::eventFilter(QObject* target, QEvent* event)
{
    if ( target == this )
    {
        static bool     pressed = false;
        static QPoint   pressedPos;
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                if ( m_parentForm != nullptr )
                {
                    pressed = true;
                    pressedPos = mouseEvent->globalPos() - m_parentForm->pos();
                    return true;
                }
            }
        }else
        if ( event->type() == QEvent::MouseButtonRelease )
        {
            pressed = false;
        }else
        if ( pressed && event->type() == QEvent::MouseMove )
        {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            if ( m_parentForm != nullptr )
            {
                m_parentForm->move(mouseEvent->globalPos() - pressedPos);
            }
            return true;
        }
    }
    return QWidget::eventFilter(target, event);
}

void TcWndCaption::paintEvent(QPaintEvent*)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

#include "tcShadowDialog.h"
#include "ui_tcShadowDialog.h"

#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPainter>
#include <qt_windows.h>
#include <windowsx.h>

#include <QDebug>

TcShadowDialog::TcShadowDialog(QWidget* parent)//, const QPixmap& pixmap, const QString& caption)
    : QDialog(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint)
    , ui(new Ui::TcShadowDialog)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground, true);

    ui->wndCaption->installEventFilter(this);
}

TcShadowDialog::~TcShadowDialog()
{
    delete ui;
}

bool TcShadowDialog::eventFilter(QObject* target, QEvent* event)
{
    if ( target == ui->wndCaption )
    {
        static bool   mousePressed = false;
        static QPoint mousePressedPos;
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                mousePressed = true;
                mousePressedPos = mouseEvent->globalPos() - pos();
                return true;
            }
        }else
        if ( event->type() == QEvent::MouseButtonRelease )
        {
            mousePressed = false;
        }else
        if ( mousePressed && event->type() == QEvent::MouseMove )
        {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            move(mouseEvent->globalPos() - mousePressedPos);
            return true;
        }
    }
    return QDialog::eventFilter(target, event);
}

void TcShadowDialog::paintShadow(QWidget* widget, int shadowWidth)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRoundedRect(shadowWidth, shadowWidth, widget->width()-shadowWidth*2, widget->height()-shadowWidth*2,
                        shadowWidth, shadowWidth);

    QPainter painter(widget);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<shadowWidth; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRoundedRect(shadowWidth-i,
                            shadowWidth-i,
                            widget->width()-(shadowWidth-i)*2,
                            widget->height()-(shadowWidth-i)*2,
                            shadowWidth, shadowWidth);
        color.setAlpha((shadowWidth*16) / (i+1)); //- qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

bool TcShadowDialog::resizeEvent(const QByteArray&, void* msg, long* result, const QRect& wndRect)
{
    bool ret = false;
    MSG* message = (MSG*) msg;
    switch(message->message)
    {
    case WM_NCHITTEST:
        int xPos = GET_X_LPARAM(message->lParam) - wndRect.x();
        int yPos = GET_Y_LPARAM(message->lParam) - wndRect.y();
//        if ( childAt(xPos, yPos) == nullptr )
//        {
//            // 移动
//            *result = HTCAPTION;
//        }else
//        {
//            return false;
//        }
        ret = true;
        if ( abs(xPos) <= 5 && abs(yPos) <= 5 )
        {
            *result = HTTOPLEFT;
        }else
        if ( abs(xPos-wndRect.width()) <= 5 && abs(yPos) <= 5 )
        {
            *result = HTTOPRIGHT;
        }else
        if ( abs(xPos) <= 5 && abs(yPos-wndRect.height()) <= 5 )
        {
            *result = HTBOTTOMLEFT;
        }else
        if ( abs(xPos-wndRect.width()) <= 5 && abs(yPos-wndRect.height()) <= 5 )
        {
            *result = HTBOTTOMRIGHT;
        }else
        if ( abs(xPos) <= 3 )
        {
            *result = HTLEFT;
        }else
        if ( abs(xPos-wndRect.width()) <= 3 )
        {
            *result = HTRIGHT;
        }else
        if ( abs(yPos) <= 3 )
        {
            *result = HTTOP;
        }else
        if ( abs(yPos-wndRect.height()) <= 3 )
        {
            *result = HTBOTTOM;
        }else
        {
            ret = false;
        }
    }
    return ret;
}

QVBoxLayout* TcShadowDialog::clientLayout()
{
    return ui->DialogLayout;
}

void TcShadowDialog::initClient(QWidget* widget)
{
    widget->setParent(ui->DialogWidget);
    ui->DialogLayout->addWidget(widget);

    setIcon(windowIcon().pixmap(ui->edIcon->size()));
    setCaption(windowTitle());

    move((qApp->desktop()->availableGeometry().bottomRight()
          - QPoint(geometry().size().width(), geometry().size().height())) /2);
}

void TcShadowDialog::setIcon(const QPixmap& pixmap)
{
    ui->edIcon->setPixmap(pixmap);
    QMargins margins = ui->wndCaptionLayout->contentsMargins();
    if ( ! pixmap.isNull() )
    {
        margins.setLeft(1);
        ui->edIcon->setVisible(true);
    }else
    {
        margins.setLeft(9);
        ui->edIcon->setVisible(false);
    }
    ui->wndCaptionLayout->setContentsMargins(margins);
}

void TcShadowDialog::setCaption(const QString& caption)
{
    ui->edCaption->setText(caption);
}

void TcShadowDialog::paintEvent(QPaintEvent*)
{
    if ( m_shadowWidth >0 )
    {
        paintShadow(this, m_shadowWidth);
    }
}

bool TcShadowDialog::nativeEvent(const QByteArray& eventType, void* msg, long* result)
{
    return m_frameResize ? resizeEvent(eventType, msg, result, geometry()) : false;
}

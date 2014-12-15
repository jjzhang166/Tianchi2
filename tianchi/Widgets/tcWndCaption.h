/// ********************************************************************************************************************
/// @copyright Tianchi C++ source library for Qt5 (天池共享源码库)\n
/// 天池共享源码库开发组(www.qtcn.org)\n
/// @license 授权协议：请阅读天池共享源码库附带的授权协议(LICENSE.LGPLv2.1)\n
/// ********************************************************************************************************************
/// @file tcWndCaption.h
/// @brief 自绘窗口的可移动标题
/// @version 1.0
/// @date 2014.12.12
/// @author 圣域天子(Jonix@qtcn.org)
///
/// ====================================================================================================================

#pragma once
#ifndef TIANCHI_TCWNDCAPTION_H
#define TIANCHI_TCWNDCAPTION_H

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

#include <QWidget>
#include <QLabel>
#include <QToolButton>

/// @code
///    // 在窗口的构造函数中使用
///    ui->formLayout->insertWidget(0, new TcWndCaption(this, "我是可移动的自绘标题"));
/// @endcode
class TIANCHI_API TcWndCaption : public QWidget
{
    Q_OBJECT
public:
    explicit TcWndCaption(QWidget *parent, const QString& title, const QIcon& icon=QIcon());

    inline void setWndTitle(const QString& title) { m_titleLabel->setText(title); }
    inline void setCloseIcon(const QIcon& icon) { m_bnClose->setIcon(icon); }

signals:
    void closeForm();
    void formMoveTo(const QPoint& newPos);

private:
    QWidget*        m_parentForm;
    QLabel*         m_titleLabel;
    QToolButton*    m_bnClose;

    virtual bool eventFilter(QObject *target, QEvent *event) override;
    virtual void paintEvent(QPaintEvent*) override;
};

#endif // TIANCHI_TCWNDCAPTION_H

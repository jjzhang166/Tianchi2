// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：允许为空的日期选择控件
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2013.04.10   圣域天子    建立
//
// ==========================================================================
/// @file tcDateEdit.h 允许输入为空的日期选择插件
// ==========================================================================
#ifndef TIANCHI_TCDATEEDIT_H
#define TIANCHI_TCDATEEDIT_H

#include <QDate>
#include <QComboBox>
#include <QCalendarWidget>
#include <QDebug>

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

/// @brief 可以输入或显示为空的日期选择控件
/// @author 圣域天子 Jonix@qtcn.org
/// @date 2013-04-10
class TIANCHI_API TcDateEdit : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(QDate date READ date WRITE setDate RESET unsetDate)
Q_SIGNALS:
    void dateChanged(const QDate& date);

protected slots:
    void setMinimumDate(const QDate& adate);
    void setMaximumDate(const QDate& adate);
    void calendarClicked(QDate);
    void textChanged(const QString& text);

private:
    QCalendarWidget* m_calendar;

    QString DateText(const QString& s);

protected:
    void focusInEvent(QFocusEvent *e);
    void mousePressEvent(QMouseEvent *e);

public:
    TcDateEdit(QWidget *parent = 0);
    virtual ~TcDateEdit();

    QDate date() const;
    void setDate(QDate value);
    void unsetDate();

    inline void setDate(QDateTime value) { setDate(value.date()); }

    inline bool isEmpty() const { return currentText().trimmed().isEmpty(); }

    qint64 toUtcMSecsSinceEpoch();     // 时间截(兼容Java)
    qint64 toUtcLastMSecsSinceEpoch(); // 23:59:59 的时间截
};

#endif // TIANCHI_TCDATEEDIT_H


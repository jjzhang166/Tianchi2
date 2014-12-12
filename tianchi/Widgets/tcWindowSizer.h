#ifndef FSWWINDOWSIZER_H
#define FSWWINDOWSIZER_H

#include <QWidget>
#include <QCursor>

class TcWindowSizer : public QObject
{
public:
    TcWindowSizer(QWidget* parent);

    void setBorderWidth(int width);

private:
    int m_borderWidth = 8;

    QWidget*    m_widget;
    QCursor     m_widgetCursor;

    bool eventFilter(QObject* target, QEvent* event);
};

#endif // FSWWINDOWSIZER_H

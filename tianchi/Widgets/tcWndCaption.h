#ifndef TIANCHI_TCWNDCAPTION_H
#define TIANCHI_TCWNDCAPTION_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

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

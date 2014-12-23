#include "tcHttp.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QTimer>

#include <iostream>
using namespace std;

TcHttp::TcHttp(int timeout)
{
    m_timeout = timeout;
}

QByteArray TcHttp::get(const QString& url)
{
    QNetworkAccessManager   nam;
    connect(&nam, SIGNAL(finished(QNetworkReply*)),this, SLOT(finishedSlot(QNetworkReply*)));
#if !defined(QT_STATIC)
    // 静态编译没有这个信号 ?
    connect(&nam, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),this, SLOT(sslErrorsSlot(QNetworkReply*,QList<QSslError>)));
#endif
    m_finished = false;
    m_finishedBytes.clear();
    QNetworkReply* reply = nam.get(QNetworkRequest(QUrl(url)));
    int index = 1500;
    while(! m_finished  && --index >0)
    {
        QEventLoop eventloop;
        QTimer::singleShot(10, &eventloop, SLOT(quit()));
        eventloop.exec();
    }
    reply->deleteLater();

    return m_finishedBytes;
}

QByteArray TcHttp::post(const QString& url, const QByteArray& content)
{
    QNetworkAccessManager   nam;
    connect(&nam, SIGNAL(finished(QNetworkReply*)),this, SLOT(finishedSlot(QNetworkReply*)));

    m_finished = false;
    m_finishedBytes.clear();

    QNetworkRequest req;
    req.setUrl(QUrl(url));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    req.setHeader(QNetworkRequest::ContentLengthHeader, content.length());
    QNetworkReply* reply = nam.post(req, content);
    int index = timeout();
    while(! m_finished  && --index >0)
    {
        QEventLoop eventloop;
        QTimer::singleShot(10, &eventloop, SLOT(quit()));
        eventloop.exec();
    }
    reply->deleteLater();

    return m_finishedBytes;
}

void TcHttp::finishedSlot(QNetworkReply* reply)
{
    m_finishedBytes = reply->readAll();
    m_finished = true;
}

void TcHttp::sslErrorsSlot(QNetworkReply* reply, const QList<QSslError>& errors)
{
    Q_UNUSED(reply)
    Q_UNUSED(errors)
    m_finishedBytes.clear();
    m_finished = true;
}


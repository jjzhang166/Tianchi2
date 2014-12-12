// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：http/https 请求由异步转为同步，即堵塞等待
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2014.12.12  圣域天子     原创
//
// ==========================================================================
/// @file tcHttp.h http/https 请求由异步转为同步，即堵塞等待
///
#pragma once

#ifndef TIANCHI_TCHTTP_H
#define TIANCHI_TCHTTP_H

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

#include <QByteArray>
#include <QNetworkReply>
#include <QSslError>

class TIANCHI_API TcHttp : public QObject
{
    Q_OBJECT
public:
    /// @brief 使用 get 方式进行请求
    /// @param url 地址以及参数，支持 http/https
    QByteArray get(const QString& url);
    /// @brief 使用 post 方式进行请求
    /// @param url 地址
    /// @param content 参数表
    QByteArray post(const QString& url, const QByteArray& content);

    inline int timeout() const { return m_timeout; }
    inline void setTimeout(int value) { m_timeout = value; }

protected:
    bool        m_finished = false;
    QByteArray  m_finishedBytes;

    int         m_timeout = 30000;

private slots:
    void finishedSlot(QNetworkReply*);
    void sslErrorsSlot(QNetworkReply* reply, const QList<QSslError>& errors);
};

#endif // TIANCHI_TCHTTP_H


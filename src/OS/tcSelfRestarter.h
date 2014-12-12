// **************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明： 实现程序退出自动重启
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2014.12.12  渡世白玉     摘自 Qt5.3.2 / Qt-Install-Framework
// ==========================================================================
/// @file tcSelfRestarter.h 汉语相关处理

#pragma once
#ifndef TIANCHI_TCSELFRESTARTER_H
#define TIANCHI_TCSELFRESTARTER_H

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

#include <QGlobal.h>

/// @brief 实现程序退出自动重启
/// @author 渡世白玉 dushibaiyu@yahoo.com
class TIANCHI_API TcSelfRestarter
{
public:
    /// @brief 构造函数，传入当前程序启动的参数。
    TcSelfRestarter(int argc, char *argv[]);
    /// @note 如果设置为自动重启，则此析构函数执行时，就会自动按照当前参数启动当前实例
    ~TcSelfRestarter();

    /// @brief 返回是否自动重启
    static bool restartOnQuit();
    /// @brief 设置是否自动重启
    static void setRestartOnQuit(bool restart);

private:
    Q_DISABLE_COPY(TcSelfRestarter)
    class Private;
    Private *d;
};

#endif // TIANCHI_TCSELFRESTARTER_H

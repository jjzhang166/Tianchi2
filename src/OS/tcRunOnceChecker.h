// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：检查是否当前程序是第一次启动
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2012.12.12  渡世白玉     摘自 Qt5.3.2 / Qt-Install-Framework
// ==========================================================================
/// @file tcRunOnceChecker.h 检查是否当前程序是第一次启动

#pragma once
#ifndef TIANCHI_TCRUNONCECHECKER_H
#define TIANCHI_TCRUNONCECHECKER_H

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

#include <QString>

/// @brief 检查是否当前程序是第一次启动
/// @author 渡世白玉 dushibaiyu@yahoo.com
class TIANCHI_API TcRunOnceChecker
{
public:
    /// @brief 检查模式
    enum Dependencies
    {
        ProcessList, ///> 检查运行程序列表是否有其他实例
        Lockfile,    ///> 检查文件是否被锁定
        Both         ///> 两者全部检查
    };

    /// @brief 构造函数
    /// @param filename 要检查的是否锁定的文件
    explicit TcRunOnceChecker(const QString& filename = QString());
    ~TcRunOnceChecker();

    /// @brief 检查函数，根据检查选项，返回检查结果。
    /// @param depends 检查选项
    bool isRunning(Dependencies depends);

private:
    Q_DISABLE_COPY(TcRunOnceChecker)
    class Private;
    Private *d;
};

#endif // TIANCHI_TCRUNONCECHECKER_H

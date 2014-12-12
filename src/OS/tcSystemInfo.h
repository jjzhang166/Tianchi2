// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：磁盘信息等系统功能
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2012.12.12  渡世白玉     摘自 Qt5.3.2 / Qt-Install-Framework
// ==========================================================================
/// @file tcSystemInfo.h 检查是否当前程序是第一次启动
///
#pragma once
#ifndef TIANCHI_TCSYSTEMINFO_H
#define TIANCHI_TCSYSTEMINFO_H

#include <QString>
#include <QList>
#include <QDebug>

#include <qt_windows.h>

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

class TcRunInfo;
/// @brief 磁盘信息等系统功能
/// @author 渡世白玉 dushibaiyu@yahoo.com
class TIANCHI_API TcVolumeInfo
{
public:
    TcVolumeInfo();
    /// @brief 路径获取路径所在的分区信息
    static TcVolumeInfo fromPath(const QString &path);

    /// @brief 挂载的路径，Windows 下为盘符，即C:/
    inline QString mountPath() const { return m_mountPath; }

    /// @brief 文件系统类型，在 Windows 下可能无效
    inline QString fileSystemType() const { return m_fileSystemType; }

    /// @brief 分区描述符,(好像是分区的ID一类的，非盘符)
    inline QString volumeDescriptor() const { return m_volumeDescriptor; }

    /// @brief 返回分区大小,单位字节
    inline quint64 size() const { return m_size; }

    /// @brief 返回可用空间，单位字节
    inline quint64 availableSize() const { return m_availableSize; }

    inline bool operator==(const TcVolumeInfo &other) const
        { return m_volumeDescriptor == other.m_volumeDescriptor; }

private:
    QString m_mountPath;
    QString m_fileSystemType;
    QString m_volumeDescriptor;

    quint64 m_size;
    quint64 m_availableSize;

    friend class TcRunInfo;
};
QDebug operator<<(QDebug dbg, TcVolumeInfo volume);

class TcProcessInfo
{
public:
    inline quint32 id() const { return m_id; }
    inline QString name() const { return m_name; }

private:
    quint32 m_id;
    QString m_name;

    friend class TcRunInfo;
};
QDebug operator<<(QDebug dbg, TcProcessInfo process);

class TIANCHI_API TcRunInfo
{
public:
    /// @brief 当前系统的内存大小
    static quint64  installedMemory();
    /// @brief 当前系统的分区信息
    static QList<TcVolumeInfo>  mountedVolumes();
    /// @brief 正在运行的进程列表
    static QList<TcProcessInfo>  runningProcesses();
    /// @brief 强制杀死一个进程，返回结果
    /// @note linux和mac未实现
    static bool  killProcess(const TcProcessInfo &process, int msecs = 30000);
    /// @brief 检查路径是不是在本地磁盘上
    /// @note linux和mac未实现
    static bool  pathIsOnLocalDevice(const QString &path);

private:
  #if defined(Q_OS_WIN)
    static TcVolumeInfo updateVolumeSizeInformation(const TcVolumeInfo &info);
    static QList<TcVolumeInfo> networkVolumeInfosFromMountPoints();
    static QList<TcVolumeInfo> localVolumeInfosFromMountPoints(PTCHAR volumeGUID);
  #endif // Q_OS_WIN
};

#endif // TIANCHI_TCSYSTEMINFO_H

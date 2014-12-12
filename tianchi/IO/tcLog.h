// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：简单的 Log 输出类
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2013.04.10   圣域天子    建立
//
// ==========================================================================
/// @file LogTiny.h 简单的 Log 输出类
// ==========================================================================
#ifndef TIANCHI_TCLOG_H
#define TIANCHI_TCLOG_H

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

#include <QString>

/// @brief 简单的文本文件输出日志。
/// @author 圣域天子 Jonix@qtcn.org
/// @date 2013-04-10
class TIANCHI_API TcLog
{
public:
    /// @brief 指定全路径的执行文件名，自动设置与执行文件同目录、同名，且后缀为 .log 的日志文件。
    /// @param [in] AppFile 执行文件名。
    /// @par 示例:
    /// @code
    /// QApplication app(argc, argv);
    ///
    /// TcLog log;
    ///
    /// // 建议把执行文件名作为参数
    /// log.setAppFile(app.applicationFilePath());
    /// @endcode
    /// @see setLogFile
    void setAppFile(const QString& AppFile);

    /// @brief 指定全路径的日志文件名。
    /// @param [in] LogFile 日志文件名。
    /// @par 示例:
    /// @code
    /// log.setLogFile("C:\\Temp\\app.log");
    /// @endcode
    /// @see setAppFile
    void setLogFile(const QString& LogFile);

    /// @brief 写日志
    /// @param [in] S 日志内容。
    /// @param [in] SourceName 源文件名，建议用__FILE__作为参数。
    /// @param [in] SourceLine 源文件行，建议用__LINE__作为参数。
    void write(const QString& S, const QString& SourceName = QString(), int SourceLine = 0);

    /// @brief 调试模式(Debug)下输出日志，在 Release 模式下没有作用。
    /// @param [in] S 日志内容。
    /// @param [in] SourceName 源文件名，建议用__FILE__作为参数。
    /// @param [in] SourceLine 源文件行，建议用__LINE__作为参数。
    inline void debug(const QString& S, const QString& SourceName = QString(), int SourceLine = 0)
    {
      #ifdef _DEBUG
        write(S, SourceName, SourceLine);
      #else
        Q_UNUSED(S);
        Q_UNUSED(SourceName);
        Q_UNUSED(SourceLine);
      #endif
    }

private:
    QString m_FileName;
};

#endif // TIANCHI_LOGTINY_H

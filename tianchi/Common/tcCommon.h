// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：公共单元，此单元不使用 namespace Tianchi
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2014.12.11  圣域天子     根据 Tianchi 的 common & utils 进行了合并整理
//
// ==========================================================================

#ifndef TCCOMMON_H
#define TCCOMMON_H

#include <QByteArray>
#include <QDateTime>
#include <QJsonValue>

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

/// @brief 操作模式的标识常量
struct TIANCHI_API TcOperMode
{
const static int Append = 1; ///< 添加或新建
const static int Change = 2; ///< 修改
const static int Delete = 4; ///< 删除

const static int CopyCell   = 301; ///< 复制一个单元格
const static int CopyCells  = 302; ///< 复制多个单元格
const static int CopyColumn = 303; ///< 复制列
const static int CopyLine   = 304; ///< 复制行
const static int CopyTable  = 305; ///< 复制一张表，默认表示含标题
};

class TIANCHI_API TcCommon
{
public:
    /// @brief 转换字符串为日期时间(yyyy/MM/dd HH:mm:ss)
    static QDateTime toDateTime(const QString& text);

    /// @brief 返回18位身位证的最后一位校验码
    static char getIDCardVerifyCode(const QByteArray& id);

    /// @brief 取编译日期和时间，调用处的代码必须重新编译
    static QDateTime complieDateTime(const QString& complieDate, const QString& complieTime);
};

/// @brief 分支逻辑判断
inline int TIANCHI_API iif(bool logic, int v1, int v2=0) { return logic ? v1 : v2; }
/// @brief 分支逻辑判断
inline QString TIANCHI_API iif(bool logic, const QString& v1, const QString& v2="") { return logic ? v1 : v2; }

/// @brief 取 Json 的键值
/// @param jv 把 Json 键值取出后强行转换为 QString 型
QString TIANCHI_API toString(const QJsonValue& jv);
/// @brief 取 Json 的键值
/// @param jv 把 Json 键值取出后强行转换为 QString 型
QString TIANCHI_API toDoubleString(const QJsonValue& jv);
/// @brief 取 Json 的键值
/// @param jv 把 Json 键值取出后强行转换为 QString 型
QString TIANCHI_API toMoneyString(const QJsonValue& jv);
/// @brief 取 Json 的键值
/// @param jv 把 Json 键值取出后强行转换为 int 型
int TIANCHI_API toInt(const QJsonValue& jv);
/// @brief 取 Json 的键值
/// @param jv 把 Json 键值取出后强行转换为 int 型
qint64 TIANCHI_API toInt64(const QJsonValue& jv);
/// @brief 取 Json 的键值
/// @param jv 把 Json 键值取出后强行转换为 double 型
double TIANCHI_API toDouble(const QJsonValue &jv);
/// @brief 取 Json 的键值
/// @param jv 把 Json 键值取出后强行转换为 bool 型
bool TIANCHI_API toBool(const QJsonValue& jv);


#endif // TCCOMMON_H

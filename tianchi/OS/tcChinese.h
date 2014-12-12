// **************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明： 汉语相关处理
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2013.04.15   圣域天子    建立
// 2014.12.11   圣域天子    局部修复
// ==========================================================================
/// @file tcChinese.h 汉语相关处理

// 请在 .pro 文件中追加：
// QT += axcontainer
// 若以 GBK 格式保存，可能需要修改源码：请在 .cpp 中搜索: <GBK>

#ifndef TIANCHI_TCCHINESE_H
#define TIANCHI_TCCHINESE_H

#if defined(Q_OS_WIN)

#ifndef TIANCHI_API
    #define TIANCHI_API
#endif

#include <QString>

/// @brief 汉语相关处理类
/// @note 此类仅限在 Windows 下有效，使用时需要在 .pro 文件中加上 LIB += -lole32
class TIANCHI_API TcChinese
{
public:
    /// 取得多个汉字的首字母
    /// @param [in] HzString 汉字字符串
    /// @return 每个汉字拼音的首字符
    /// @par 示例:
    /// @code
    /// qDebug()<<TIANCHI::Chinese::firstPinyins(QS("中华人民共和国"));
    /// > zhrmghg
    ///
    /// qDebug()<<TIANCHI::Chinese::firstPinyins(QS("中华大地Qt论坛 - www.qtcn.org"));
    /// > zhddlt
    ///
    /// @endcode
    static QString firstPinyins(const QString& HzString);

    /// 取得多个汉字的全部拼音
    /// @param [in] Str 汉字字符串
    /// @param [in] Tonality 音调不转换成拼音
    /// @return 汉语拼音
    /// @par 示例:
    /// @code
    /// 含音调的输出
    /// qDebug()<<TIANCHI::Chinese::toPinyin(QS("中华人民共和国"), true);
    /// > zhōnghuárénmíngònghéguó
    /// 不含音调的输出
    ///
    /// qDebug()<<TIANCHI::Chinese::toPinyin(QS("中华人民共和国"), false);
    /// > zhonghuarenmingongheguo
    ///
    /// qDebug()<<TIANCHI::Chinese::toPinyin(QS("中华大地Qt论坛 - www.qtcn.org"));
    /// > zhonghuadadiluntan
    ///
    /// @endcode
    static QString toPinyin(const QString& Str, bool Tonality=false);

    /// 混合字符时，转换中不过滤英数符号等
    /// @param [in] Str 汉字字符串
    /// @param [in] Tonality 音调不转换成拼音
    /// @return 汉字的首字母
    /// @par 示例:
    /// @code
    /// qDebug()<<TIANCHI::Chinese::toChars(QS("中华大地Qt论坛 - www.qtcn.org"), true);
    /// > zhōnghuádàdìQtlùntán - www.qtcn.org
    ///
    /// qDebug()<<TIANCHI::Chinese::toChars(QS("中华大地Qt论坛 - www.qtcn.org"));
    /// > zhonghuadadiQtluntan - www.qtcn.org
    ///
    /// @endcode
    static QString toChars(const QString& Str, bool Tonality=false);

    /// 中文名字翻译为英文习惯
    /// @param [in] Str 汉字字符串
    /// @param [in] style 使用英语习惯即姓氏在后名字在前
    /// @param [in] capitalization 姓氏只有首字母大写
    /// @param [in] hyphenatedname 复姓
    /// @return 名字英文形式
    /// @par 示例:
    /// @code
    /// qDebug()<<TIANCHI::Chinese::toEnglishName(QS("杨海智"), true, false, false);
    /// > Haizhi Yang
    ///
    /// qDebug()<<TIANCHI::Chinese::toEnglishName(QS("杨海智"), false, false, false);
    /// > Yang Haizhi
    ///
    /// qDebug()<<TIANCHI::Chinese::toEnglishName(QS("杨海智"), true, true, false);
    /// > Haizhi YANG
    ///
    /// qDebug()<<TIANCHI::Chinese::toEnglishName(QS("诸葛亮"), true, false, true);
    /// > Liang Zhuge
    ///
    /// @endcode
    static QString toEnglishName(const QString& Str, bool style=false, bool capitalization=false,
                                 bool hyphenatedname= false);

    /// @brief 分割中文全名中的姓氏、名字和英文名
    /// @param full 全名
    /// @param sur 姓氏
    /// @param real 名字
    /// @param english 英文名
    /// @return 0: 失败，1: 单姓，2: 复姓，3: 英文名
    static int splitHumanName(const QString& full, QString& sur, QString& real, QString& english);
};

#endif // Q_OS_WIN
#endif // TIANCHI_CHINESE_H

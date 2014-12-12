#include "tcCommon.h"

QDateTime TcCommon::toDateTime(const QString& text)
{
    QDateTime ret = QDateTime();
    switch(text.length())
    {
    case 23:
        ret.fromString(text, "yyyy-MM-dd HH:mm:ss.zzz");
        break;
    case 19:
        ret.fromString(text, "yyyy-MM-dd HH:mm:ss");
        break;
    case 16:
        ret.fromString(text, "yyyy-MM-dd HH:mm");
        break;
    case 14:
        ret.fromString(text, "yyyyMMddHHmmss");
        break;
    case 10:
        ret.fromString(text, "yyyy-MM-dd");
        break;
    case  8:
        ret.fromString(text, "HH:mm:ss");
        break;
    case  7:
        ret.fromString(text, "yyyy/MM");
        break;
    case  6:
        ret.fromString(text, "HHmmss");
        break;
    case  5:
        if ( text.at(2) == '/'
          || text.at(2) == '-' )
        {
            ret.fromString(text, "MM/dd");
        }else
        if ( text.at(2) == ':' )
        {
            ret.fromString(text, "HH:mm");
        }
        break;
    case  4:
        ret.fromString(text, "yyyy");
        break;
    case  2:
        ret.fromString(text, "dd");
        break;
    case  1:
        ret.fromString(text, "d");
        break;
    }
    return ret;
}

char TcCommon::getIDCardVerifyCode(const QByteArray& id)
{
    char ret = '\0';
    if ( id.length() >= 17 )
    {
        // 加权乘积求和除以11的余数所对应的校验数
        const char verifyMap[] = "10X98765432";
        // 加权因子
        const int factor[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1 };

        int Sum = 0;  //加权乘积求和
        for( int i=0;i<17;i++ )
        {
            char c = id[i];

            Sum += (c-'0') * factor[i]; // 加权乘积求和
        }
        ret = verifyMap[Sum % 11]; // 取模
    }
    return ret;
}

QDateTime TcCommon::complieDateTime(const QString& complieDate, const QString& complieTime)
{
    QString DateString = complieDate;
    QString Year  = DateString.right(4);
    QString Month = DateString.left(3).toUpper();
    QString Day   = DateString.mid(4, 2);
    QString TimeString = complieTime;
    QString Hour   = TimeString.left(2);
    QString Minute = TimeString.mid(3, 2);
    QString Second = TimeString.right(2);
    const QString MonthString[12] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                                      "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    unsigned int MonthValue;
    for( MonthValue=0;MonthValue<sizeof(MonthString);MonthValue++ )
    {
        if ( Month == MonthString[MonthValue] )
        {
            MonthValue++;
            break;
        }
    }
    return QDateTime(QDate(Year.toInt(), MonthValue, Day.toInt()),
                     QTime(Hour.toInt(), Minute.toInt(), Second.toInt()));
}

QString toString(const QJsonValue& jv)
{
    QString ret = "";
    if ( jv.isDouble() )
    {
        ret = QString::number(jv.toDouble());
    }else
    if ( jv.isString() )
    {
        ret = jv.toString();
    }
    return ret;
}

QString toDoubleString(const QJsonValue& jv)
{
    QString ret = "";
    if ( jv.isDouble() )
    {
        ret = QString::number(jv.toDouble());
    }else
        if ( jv.isString() )
        {
            ret = QString::number(jv.toDouble());
        }else
        {
            ret = "0";
        }
    return ret;
}

QString toMoneyString(const QJsonValue& jv)
{
    QString ret = "";
    if ( jv.isDouble() )
    {
        ret.sprintf( "%.2lf", jv.toDouble( ) );
        return ret;
    } else if ( jv.isString() )
    {
        if ( jv.toString( ).isEmpty( ) ) return "";
        ret.sprintf( "%.2lf", jv.toDouble( ) );
        return ret;
    } else
    {
        ret = "";
        //ret = "0.00";
    }
    return ret;
}

int toInt(const QJsonValue& jv)
{
    int ret = 0;
    if ( jv.isDouble() )
    {
        ret = jv.toDouble();
    }else
    if ( jv.isString() )
    {
        ret = jv.toString().toInt();
    }
    return ret;
}

qint64 toInt64(const QJsonValue &jv)
{
    qint64 ret = 0;
    if ( jv.isDouble() )
    {
        ret = jv.toDouble();
    }else
        if ( jv.isString() )
        {
            ret = jv.toString().toInt();
        }
    return ret;
}

double toDouble(const QJsonValue &jv)
{
    double ret = 0.0;
    if ( jv.isDouble() )
    {
        ret = jv.toDouble();
    }else
        if ( jv.isString() )
        {
            ret = jv.toString().toInt();
        }
    return ret;
}

bool toBool(const QJsonValue& jv)
{
    bool ret = false;
    if ( jv.isBool() )
    {
        ret = jv.toBool();
    }else
    if ( jv.isDouble() )
    {
        ret = jv.toDouble() >0;
    }else
    if ( jv.isString() )
    {
        QString s = jv.toString();
        ret = s.compare("true",Qt::CaseInsensitive )
                || s.compare("yes",Qt::CaseInsensitive )
                || s.compare("ok",Qt::CaseInsensitive )
                || s.compare("t",Qt::CaseInsensitive )
                || s.compare("y",Qt::CaseInsensitive )
                || s.toInt() >0;
    }
    return ret;
}

#include "tcMSExcel.h"

#if defined(Q_OS_WIN)
#include <QList>

TcMSExcel::TcMSExcel()
{
}

TcMSExcel::~TcMSExcel()
{
    close();
    if (!excel->isNull())
    {
        excel->dynamicCall("Quit()");
    }
    delete sheet ; sheet  = nullptr;
    delete sheets; sheets = nullptr;
    delete book  ; book   = nullptr;
    delete books ; books  = nullptr;
    delete excel ; excel  = nullptr;
}

void TcMSExcel::construct()
{
    destory();
    excel->setControl("Excel.Application");
    if (excel->isNull())
    {
        excel->setControl("ET.Application");
    }
    if (!excel->isNull())
    {
        books = excel->querySubObject("Workbooks");
    }
}

bool TcMSExcel::create(const QString& filename)
{
    bool ret = false;
    if (books != NULL && ! books->isNull())
    {
        books->dynamicCall("Add");
        book   = excel->querySubObject("ActiveWorkBook");
        sheets = book ->querySubObject("WorkSheets"    );
        currentSheet();
        m_filename = filename;
        ret = true;
    }
    return ret;
}

bool TcMSExcel::open(const QString& filename)
{
    bool ret = false;
    construct();
    if ( books != NULL && ! books->isNull() )
    {
        book = books->querySubObject("Open(QString, QVariant)", filename, 0);
        ret = book != NULL && ! book->isNull();
        if ( ret )
        {
            sheets = book->querySubObject("WorkSheets");
            m_filename = filename;
            currentSheet();
        }
    }
    return ret;
}

void TcMSExcel::save(const QString& filename)
{
    if ( book != NULL && ! book->isNull())
    {
        m_filename = filename;
        book->dynamicCall("SaveAs(const QString&)", filename);
    }
}

void TcMSExcel::close()
{
    destory();
}

void TcMSExcel::destory()
{
    delete sheet ; sheet  = nullptr;
    delete sheets; sheets = nullptr;
    if (book != NULL && ! book->isNull())
    {
        book->dynamicCall("Close(Boolean)", false);
    }
    delete book  ; book   = nullptr;
    delete books ; books  = nullptr;
    if (excel != NULL && ! excel->isNull())
    {
        excel->dynamicCall("Quit()");
    }
    delete excel ; excel  = nullptr;
    m_filename  = "";
    m_sheetName = "";
}

void TcMSExcel::kick()
{
    if ( excel != NULL && !excel->isNull())
    {
        excel->setProperty("Visible", true);
    }
    delete sheet ; sheet  = nullptr;
    delete sheets; sheets = nullptr;
    delete book  ; book   = nullptr;
    delete books ; books  = nullptr;
    delete excel ; excel  = nullptr;
    destory();
}

QStringList TcMSExcel::sheetNames()
{
    QStringList ret;
    if ( sheets != NULL && !sheets->isNull() )
    {
        int sheetCount = sheets->property("Count").toInt();
        for (int i = 1; i <= sheetCount; ++i)
        {
            QAxObject* sheet = sheets->querySubObject("Item(int)", i);
            ret.append(sheet->property("Name").toString());
        }
    }
    return ret;
}

void TcMSExcel::setVisible(bool value)
{
    if ( excel != NULL && !excel->isNull())
    {
        excel->setProperty("Visible", value);
    }
}

void TcMSExcel::setCaption(const QString& value)
{
    if ( excel != NULL && !excel->isNull() )
    {
        excel->setProperty("Caption", value);
    }
}

bool TcMSExcel::addBook()
{
    bool ret = false;
    if ( excel != NULL && !excel->isNull())
    {
        delete sheet ; sheet  = nullptr;
        delete sheets; sheets = nullptr;
        delete book  ; book   = nullptr;
        delete books ; books  = nullptr;
        books = excel->querySubObject("WorkBooks");
        ret = books != NULL && !books->isNull();
    }
    return ret;
}

bool TcMSExcel::currentSheet()
{
    bool ret = false;
    delete sheet; sheet = nullptr;
    if ( excel != NULL && ! excel->isNull())
    {
        delete sheet ; sheet  = nullptr;
        sheet = excel->querySubObject("ActiveWorkBook");
        ret = sheet != NULL && !sheet->isNull();
        m_sheetName = ret ? sheet->property("Name").toString() : "";
    }
    return ret;
}

bool TcMSExcel::setCurrentSheet(int index)
{
    bool ret = false;
    if ( sheets != NULL && !sheets->isNull())
    {
        delete sheet; sheet= nullptr;
        sheet = sheets->querySubObject("Item(int)", index);
        ret = sheet != NULL && ! sheet->isNull();
        m_sheetName = ret ? sheet->property("Name").toString() : "";
    }
    return ret;
}

int TcMSExcel::sheetCount()
{
    int ret = 0;
    if ( sheets != NULL && ! sheets->isNull())
    {
        ret = sheets->property("Count").toInt();
    }
    return ret;
}

void TcMSExcel::cellFormat(int row, int col, const QString& format)
{
    if ( sheet != NULL && ! sheet->isNull())
    {
        QAxObject* range = sheet->querySubObject("Cells(int, int)", row, col);
        range->setProperty("NumberFormatLocal", format);
        delete range;
    }
}

void TcMSExcel::cellAlign(int row, int col, Alignment hAlign, Alignment vAlign)
{
    if ( sheet != NULL && !sheet->isNull())
    {
        QAxObject* range = sheet->querySubObject("Cells(int, int)", row, col);
        range->setProperty("HorizontalAlignment", hAlign);
        range->setProperty("VerticalAlignment",   vAlign);
        delete range;
    }
}

QVariant TcMSExcel::read(int row, int col)
{
    QVariant ret;
    if ( sheet != NULL && ! sheet->isNull())
    {
        QAxObject* range = sheet->querySubObject("Cells(int, int)", row, col);
        ret = range->dynamicCall("Value()");
        delete range;
    }
    return ret;
}

void TcMSExcel::write(int row, int col, const QVariant& value)
{
    if ( sheet != NULL && ! sheet->isNull())
    {
        QAxObject* range = sheet->querySubObject("Cells(int, int)", row, col);
        range->setProperty("Value", value);
        delete range;
    }
}

bool TcMSExcel::usedRange(int& rowStart, int& colStart, int& rowEnd, int& colEnd)
{
    bool ret = false;
    if ( sheet != NULL && ! sheet->isNull())
    {
        QAxObject* urange  = sheet->querySubObject("UsedRange");
        rowStart = urange->property("Row"   ).toInt();
        colStart = urange->property("Column").toInt();
        rowEnd   = urange->querySubObject("Rows"   )->property("Count").toInt();
        colEnd   = urange->querySubObject("Columns")->property("Count").toInt();
        delete urange;
        ret = true;
    }
    return ret;
}
#endif // Q_OS_WIN32 / Q_OS_WIN64

#include "mainwindow.h"
#include "tcRunOnceChecker.h"

#include <QApplication>
#include <QMessageBox>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TcRunOnceChecker checker("Tianchi2_Samples_App");
    if ( ! checker.isRunning(TcRunOnceChecker::ProcessList) )
    {
        // 首次运行
        MainWindow w;
        w.show();
        return app.exec();
    }else
    {
        // 已存在其它实例
        QMessageBox::critical(app.desktop(), "错误", "已经有实例在运行了");
    }
    return 0;
}

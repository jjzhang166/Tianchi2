#Tianchi2

天池开源软件库 for Qt5.x

此版本为重新整理，简化使用

使用方式:
   1. 动态链接库方式（推荐）
      打开并编译 tianchi/tianchi.pro , 生成动态链接库
      生成位置：bin/
      Debug  时连接库：-lQt5Tianchid
      Release时连接库：-lQt5Tianchi

   2. 在自己的工程文件中直接包含天池源码库
      include(tianchi/tianchi_all.pri)

   3. 直接使用源代码文件
      Tianchi2 设计时尽量保持单组文件型式，所以只要把对应
      的 .h/.cpp 直接引用到工程文件中即可使用.
      部分使用开源库的源文件需要同时引入开源库文件, 具体
      请参见 tianchi/tianchi_all.pri 中的引入内容

   4. 静态链接库
      打开并编译 tianchi/tianchi_lib.pro , 生成静态链接库
      生成位置：bin


文件列表与说明:

bin/                                            编译生成文件的目录
    Qt5Tianchid.lib (Qt5Tianchid.a )            生成的动态/静态链接库(Debug)
    Qt5Tianchid.dll (Qt5Tianchid.so)            生成的动态链接库(Debug)
    Qt5Tianchi.lib  (Qt5Tianchi.a  )            生成的动态/静态链接库(Release)
    Qt5Tianchi.dll  (Qt5Tianchi.so )            生成的动态链接库(Release)
    tianchi2_sample.exe                         天池的演示程序

help/
    Doxyfile                                    Doxygen 生成文档的配置文件

QtCreatorPlugins/
    QtCreatorPlugins.pro                        可生成 QtCreator 的编译控件(插件)
                                                Windows 下必须使用 MSVC2010 编译
    readme.txt                                  小白编译前必读

sample/                                         演示程序目录
    sample.pro                                  演示程序的工程文件，采用直接包含天池库方式


tianchi/
    tianchi.pro                                 生成动态链接库
    tianchi_lib.pro                             生成静态链接库
    tianchi_all.pri                             包含所有模块的引入文件
    tianchi.pri                                 逐层包含所有模块的引入文件

    Common/
        tcCommon.h                              一些常用的公共单元。根据 Tianchi 的 common & utils 进行了合并整理
        tcCommon.cpp
        tcFunctionalSortFilterProxyModel.h      依所设过滤参数(QVariantMap)来使用已设滤函数进行过滤的模型
        tcFunctionalSortFilterProxyModel.cpp
        tcInvoke.h                              映射信号槽的执行对象
        tcInvoke.cpp
        tcRecentUse.hpp                         "最近使用"模版类，例如：用于最近打开的文件，默认最大10个
        tcSingleton.hpp                         用指针实现的单例模式的模版类
        tcTuple.hpp                             简单的 Tuple(元组) 模版类, 提供2~10个类型参数的模版
        tcVariantMapTableModel.h                以QVariantMap作为数据行的model,只可追加和清除,不可插入与删除
        tcVariantMapTableModel.cpp
    Component/                                  Qt IDE 的控件，由于Qt限制，必须为全小写文件名
        QSint/                                  QSint 开源组件(部分), 请详见：http://www.oschina.net/p/qsint
        Tianchi/                                Tianchi 组件
            tcdateedit.h                        允许输入为空的日期选择插件(IDE控件)
            tcdateedit.cpp
    Encrypt/
        tcAES.h                                 AES 加密/解密（使用 Crypto++）
        tcAES.cpp
        cryptopp562/                            Crypto++5.6.2 加密/解密开源库
    Gui/
        tcAutoCursor.h                          鼠标光标的设置和自动恢复处理
        tcAutoCursor.cpp
        tcGuiCommon.h                           一些GUI相关的公共单元。
        tcGuiCommon.cpp
    IO/
        tcExcel.h                               通过 OLE 方式操作 Microsoft Excel（仅限 Windows 下使用，要求已安装 Excel）
        tcExcel.cpp
        tcExcelReader.h                         通过 OLE 方式读取 Microsoft Excel, WPS（Linux 下仅支持WPS）
        tcExcelReader.cpp
        tcIO.h                                  目录、文件等操作功能
        tcIO.cpp
        tcLog.h                                 简单的文本日志输出功能
        tcLog.cpp
    Network/
        tcDownloader.h                          网络文件下载器，目前仅实现 http 文件下载
        tcDownloader.cpp
        tcFtp.h                                 Ftp 操作
        tcFtp.cpp
        tcHttp.h                                http/https 请求由异步转为同步，即堵塞等待。常用于登录时等待返回
        tcHttp.cpp
        tcUdp.h                                 Udp协议的发送以及接收服务器
        tcUdp.cpp
    OS/
        tcAdminAuthorization.h                  操作系统管理员权限的判断和提升权限执行程序
        tcAdminAuthorization_mac.cpp            本机管理员提权，MacOS实现
        tcAdminAuthorization_win.cpp            本机管理员提权，Windows实现
        tcAdminAuthorization_x11.cpp            本机管理员提权，Linux/BSD实现
        tcChinese.h                             Windows 下汉字转拼音功能
        tcChinese.cpp
        tcChinese.inc
        tcOS.h                                  操作系统相关功能
        tcOS.cpp
        tcRunOnceChecker.h                      程序单实例判断，检查是否当前程序是第一次启动
        tcRunOnceChecker.cpp
        tcSelfRestarter.h                       实现程序退出后自动重启
        tcSelfRestarter.cpp
        tcSystemInfo.h                          磁盘、内存等系统信息
        tcSystemInfo.cpp
        tcSystemInfo_mac.cpp
        tcSystemInfo_win.cpp
        tcSystemInfo_x11.cpp
        tcWindows.h                             Microsoft Windows 系统功能，只能在Windows上使用
        tcWindows.cpp
    QRCode/                                     二维码编码解码模块
        tcQrencode.h                            二维码编码
        tcQrencode.cpp
        qrencode/                               二维码编码的开源库
        tcZxing.h                               二维码解码
        tcZxing.cpp
        zxing/                                  二维码解码的开源库
    Widgets/
        tcPageTurnWidget.h                      翻页按钮组
        tcPageTurnWidget.cpp
        tcScreenshot.h                          截屏
        tcScreenshot.cpp
        tcScreenshot.ui
        tcShadowDialog.h                        含阴影和可缩放的无边对话框父类
        tcShadowDialog.cpp
        tcShadowDialog.ui
        tcShadowDialog.qrc
        tcWidget.h                              自绘窗口的可移动标题
        tcWidget.cpp
        tcWndCaption.qrc
        tcWndSizer.h                            缩放无框窗口，不同实现，不推
        tcWndSizer.cpp
        images/
            close.png                           tcShadowDialog 使用的关闭窗口的X图片


tianchi4qtc/                                    Qt Designer 组件
    tianchi4qtc.pro                             组件工程文件。
                                                注意: 必须以 Release 模式编译 !!!
                                                      Windows 下必须用 VC2010+ 下编译 !!!

天池开源软件库源自1.0的重新整理版
最初原版请参见：https://github.com/qtcn/tianchi


##

##Tianchi 是为简化使用，把常用单位汇集在一起的简单类库。<br/>

###让 QtCreator / QtDesigner 能够在设计时使用 Tianchi 的可视化控件：

把 bin/designer/tianchi4qtc.dll 复制到：C:\\Qt\\Qt5.4.0\\Tools\\QtCreator\\bin\\plugins\\designer<br/>
如果需要单独使用 QtDesigner: 请复制到：C:\\Qt\\Qt5.4.0\\5.4\\mingw491_32\\plugins\\designer<br/>
<br/>
###Tianchi 库的使用方法

####1. 最简便的直接使用方式（直接包含源码编译）：
在您的工程文件(xxx.pro)中直接包括 tianchi.pri, 例如：<br/>

    include (.../tianchi/myProject.pri)
建议您复制一个 tianchi.pri 文件，打开并删除掉不需要的包含单元。<br/>

####2. 动态链接库方式
打开并编译 tianchi/tianchi.pro , 生成动态链接库<br/>
会生成动态链接库：bin/Qt5Tianchi.dll(.so)<br/>
以及生成编译连接库：bin/Qt5Tianchi.lib(.a)<br/>
在 Debug 模式下文件名会追加一个 d 字母。<br/>
<br/>
使用时把编译连接库加到 .pro 中：<br/>

    LIBS += -lQt5Tianchi
如果编译时找不到该连接库，请追加指定目录：<br/>

    LIBS += -L.../tianchi/bin
Debug / Release 自动识别连接的方式是：<br/>

    Debug: -lQt5Tianchid
    Release: -lQt5Tianchi
####3. 静态链接库
打开工程文件并编译 tianchi/tianchi_lib.pro , 生成静态链接库<br/>
会生成静态链接库：bin/Qt5Tianchi.lib(.a)<br/>
编译时连接的设置方式参见第2点。<br/>

####4. 直接使用单组源代码文件<br/>
Tianchi 设计时尽量保持单组文件型式，所以只要把对应<br/>
的 .h/.cpp/.ui/.qrc 以及相关图片文件，直接复制或引
用到工程文件中即可使用.<br/>
部分使用第三方开源库的源码需要同时引入第三方库, 具<br/>
体请参见 tianchi/tianchi.pri 中的引入内容<br/>

文件列表与说明:
---------------

    bin/                                            编译生成文件的目录
        tianchi4qtc.dll                             Windows版天池的 QtCreator / QtDesigner 可视化插件
                                                    请复制到：C:\Qt\Qt5.4.0\Tools\QtCreator\bin\plugins\designer
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
        tianchi.pri                                 包含所有模块的引入文件
        Common/
            tcCommon.h                              一些常用的公共单元。根据 Tianchi 的 common & utils 进行了合并整理
            tcCommon.cpp
            tcInvoke.h                              映射信号槽的执行对象
            tcInvoke.cpp
        Component/                                  Qt IDE 的控件，由于Qt限制，必须为全小写文件名
            QSint/                                  QSint 开源组件(部分), 请详见：http://www.oschina.net/p/qsint
            Tianchi/                                Tianchi 组件
                tcDateEdit.h                        允许输入为空的日期选择插件(IDE控件)
                tcDateEdit.cpp
            wwWidgets/                              wwWidgets 开源组件(部分), 请详见：http://www.wysota.eu.org/wwwidgets
        Encrypt/
            tcAES.h                                 AES 加密/解密（使用 Crypto++）
            tcAES.cpp
            tcRSA.h                                 RSA 加密/解密（使用 Crypto++）
            tcRSA.cpp
            cryptopp/                               Crypto++5.6.2 加密/解密开源库
        Gui/
            tcAutoCursor.h                          鼠标光标的设置和自动恢复处理
            tcAutoCursor.cpp
            tcGuiCommon.h                           一些GUI相关的公共单元。
            tcGuiCommon.cpp
            tcImageAdjust.h                         图片简单处理(柔化, 锐化, 灰度化, 黑白化, 底片化, 浮雕化)
            tcImageAdjust.cpp
        IO/
            tcExcel.h                               通过 OLE 方式操作 Microsoft Excel（仅限 Windows 下使用，要求已安装 Excel）
            tcExcel.cpp
            tcExcelReader.h                         通过 OLE 方式读取 Microsoft Excel, WPS（Linux 下仅支持WPS）
            tcExcelReader.cpp
            tcIO.h                                  目录、文件等操作功能
            tcIO.cpp
            tcLog.h                                 简单的文本日志输出功能
            tcLog.cpp
        Multimedia/
            tcTextToSpeech.h                        文字转为语音进行播放，仅限 Windows 下使用
            tcTextToSpeech.cpp
        Network/
            tcDownloader.h                          网络文件下载器，目前仅实现 http 文件下载
            tcDownloader.cpp
            tcFtp.h                                 Ftp 操作
            tcFtp.cpp
            tcHttp.h                                http/https 请求由异步转为同步，即堵塞等待。常用于登录时等待返回
            tcHttp.cpp
            tcUdp.h                                 Udp协议的接收服务器，以及发送和广播功能
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
            zxing/                                  二维码解码的开源库 (VC2010下无法编译，请自行去除)
        Widgets/
            tcPageTurnWidget.h                      翻页按钮组
            tcPageTurnWidget.cpp
            tcScreenshot.h                          截屏功能
            tcScreenshot.cpp
            tcScreenshot.ui
            tcShadowDialog.h                        含阴影和可缩放的无边对话框父类
            tcShadowDialog.cpp
            tcShadowDialog.ui
            tcShadowDialog.qrc
            tcStyleToolDialog.h                     无边框窗口加阴影，缩放功能
            tcStyleToolDialog.cpp
            tcStyleToolDialog.ui
            tcViewHeaderSetupDialog.h               QTreeWidget 列头设置对话框
            tcViewHeaderSetupDialog.cpp
            tcViewHeaderSetupDialog.ui
            tcViewHeaderSetupDialog.qrc
            tcWidget.h                              自绘窗口的可移动标题
            tcWidget.cpp
            images/
                close.png                           tcShadowDialog 使用的关闭窗口的X图片
    tianchi4qtc/                                    Qt Designer 组件
        tianchi4qtc.pro                             组件工程文件。
                                                    注意: 必须以 Release 模式编译 !!!
                                                          Windows 下必须用 VC2010+ 下编译 !!!

特别感谢代码贡献者以及维护人员
------------------------------
XChinux / www.qtcn.org 坛主<br/>
cnhemiya / 南果梨<br/>
roywillow<br/>
younghz<br/>
渡世白玉<br/>
foxgod<br/>
Jonix<br/>

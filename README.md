Tianchi2
========
Version 0.2.0.0 Build 2015.01.21

��ؿ�Դ����� for Qt5.x

�˰汾Ϊ����������ʹ��

ʹ�÷�ʽ:
---------
####1. QtCreator / QtDesigner ���ӻ����
�� bin/designer/*.* ���Ƶ���C:\Qt\Qt5.4.0\Tools\QtCreator\bin\plugins\designer<br/>
QtDesigner ��Ҫ���Ƶ���C:\Qt\Qt5.4.0\5.4\mingw491_32\plugins\designer<br/>

####2. �������ʹ�÷�ʽ���Ƽ�С��ʹ�ã�
���� tianchi/tianchi.pri Ϊ tianchi/myProject.pri
���Լ��� .pro ����ӣ�
include (.../tianchi/myProject.pri)

####3. ��̬���ӿⷽʽ - mingw���Ƽ���
�򿪲����� tianchi/tianchi.pro , ���ɶ�̬���ӿ�<br/>
����λ�ã�bin/<br/>
Debug  ʱ���ӿ⣺```-lQt5Tianchid```<br/>
Releaseʱ���ӿ⣺```-lQt5Tianchi```<br/>

ע�⣺VC2010 ����ʱ��ZXing ���޷�ͨ����

####4. ���Լ��Ĺ����ļ���ֱ�Ӱ������Դ���
��.pro�ļ�����ӣ�```include(tianchi/tianchi.pri)```<br/>

####5. ֱ��ʹ��Դ�����ļ�
Tianchi2 ���ʱ�������ֵ����ļ���ʽ������ֻҪ��<br/>
��Ӧ�� .h/.cpp/.ui ֱ�����õ������ļ��м���ʹ��.<br/>
����ʹ�ÿ�Դ���Դ�ļ���Ҫͬʱ���뿪Դ���ļ�, ��<br/>
����μ� tianchi/tianchi.pri �е���������<br/>

####6. ��̬���ӿ�
  �򿪲����� tianchi/tianchi_lib.pro , ���ɾ�̬���ӿ�<br/>
  ����λ�ã�bin/<br/>


������ʷ��


�ļ��б���˵��:
---------------
    bin/                                            ���������ļ���Ŀ¼
        tianchi4qtc.dll                             Windows����ص� QtCreator / QtDesigner ���ӻ����
                                                    �븴�Ƶ���C:\Qt\Qt5.4.0\Tools\QtCreator\bin\plugins\designer

    help/
        Doxyfile                                    Doxygen �����ĵ��������ļ�

    QtCreatorPlugins/
        QtCreatorPlugins.pro                        ������ QtCreator �ı���ؼ�(���)
                                                    Windows �±���ʹ�� MSVC2010 ����
        readme.txt                                  С�ױ���ǰ�ض�

    sample/                                         ��ʾ����Ŀ¼
        sample.pro                                  ��ʾ����Ĺ����ļ�������ֱ�Ӱ�����ؿⷽʽ

    tianchi/
        tianchi.pro                                 ���ɶ�̬���ӿ�
        tianchi_lib.pro                             ���ɾ�̬���ӿ�
        tianchi.pri                                 ��������ģ��������ļ�

        Common/
            tcCommon.h                              һЩ���õĹ�����Ԫ������ Tianchi �� common & utils �����˺ϲ�����
            tcCommon.cpp
            tcInvoke.h                              ӳ���źŲ۵�ִ�ж���
            tcInvoke.cpp
        Component/                                  Qt IDE �Ŀؼ�������Qt���ƣ�����ΪȫСд�ļ���
            QSint/                                  QSint ��Դ���(����), �������http://www.oschina.net/p/qsint
            Tianchi/                                Tianchi ���
                tcDateEdit.h                        ��������Ϊ�յ�����ѡ����(IDE�ؼ�)
                tcDateEdit.cpp
            wwWidgets/                              wwWidgets ��Դ���(����), �������http://www.wysota.eu.org/wwwidgets
        Encrypt/
            tcAES.h                                 AES ����/���ܣ�ʹ�� Crypto++��
            tcAES.cpp
            tcRSA.h                                 RSA ����/���ܣ�ʹ�� Crypto++��
            tcRSA.cpp
            cryptopp/                               Crypto++5.6.2 ����/���ܿ�Դ��
        Gui/
            tcAutoCursor.h                          ���������ú��Զ��ָ�����
            tcAutoCursor.cpp
            tcGuiCommon.h                           һЩGUI��صĹ�����Ԫ��
            tcGuiCommon.cpp
            tcImageAdjust.h                         ͼƬ�򵥴���(�ữ, ��, �ҶȻ�, �ڰ׻�, ��Ƭ��, ����)
            tcImageAdjust.cpp
        IO/
            tcExcel.h                               ͨ�� OLE ��ʽ���� Microsoft Excel������ Windows ��ʹ�ã�Ҫ���Ѱ�װ Excel��
            tcExcel.cpp
            tcExcelReader.h                         ͨ�� OLE ��ʽ��ȡ Microsoft Excel, WPS��Linux �½�֧��WPS��
            tcExcelReader.cpp
            tcIO.h                                  Ŀ¼���ļ��Ȳ�������
            tcIO.cpp
            tcLog.h                                 �򵥵��ı���־�������
            tcLog.cpp
        Multimedia/
            tcTextToSpeech.h                        ����תΪ�������в��ţ����� Windows ��ʹ��
            tcTextToSpeech.cpp
        Network/
            tcDownloader.h                          �����ļ���������Ŀǰ��ʵ�� http �ļ�����
            tcDownloader.cpp
            tcFtp.h                                 Ftp ����
            tcFtp.cpp
            tcHttp.h                                http/https �������첽תΪͬ�����������ȴ��������ڵ�¼ʱ�ȴ�����
            tcHttp.cpp
            tcUdp.h                                 UdpЭ��Ľ��շ��������Լ����ͺ͹㲥����
            tcUdp.cpp
        OS/
            tcAdminAuthorization.h                  ����ϵͳ����ԱȨ�޵��жϺ�����Ȩ��ִ�г���
            tcAdminAuthorization_mac.cpp            ��������Ա��Ȩ��MacOSʵ��
            tcAdminAuthorization_win.cpp            ��������Ա��Ȩ��Windowsʵ��
            tcAdminAuthorization_x11.cpp            ��������Ա��Ȩ��Linux/BSDʵ��
            tcChinese.h                             Windows �º���תƴ������
            tcChinese.cpp
            tcChinese.inc
            tcOS.h                                  ����ϵͳ��ع���
            tcOS.cpp
            tcRunOnceChecker.h                      ����ʵ���жϣ�����Ƿ�ǰ�����ǵ�һ������
            tcRunOnceChecker.cpp
            tcSelfRestarter.h                       ʵ�ֳ����˳����Զ�����
            tcSelfRestarter.cpp
            tcSystemInfo.h                          ���̡��ڴ��ϵͳ��Ϣ
            tcSystemInfo.cpp
            tcSystemInfo_mac.cpp
            tcSystemInfo_win.cpp
            tcSystemInfo_x11.cpp
            tcWindows.h                             Microsoft Windows ϵͳ���ܣ�ֻ����Windows��ʹ��
            tcWindows.cpp
        QRCode/                                     ��ά��������ģ��
            tcQrencode.h                            ��ά�����
            tcQrencode.cpp
            qrencode/                               ��ά�����Ŀ�Դ��
            tcZxing.h                               ��ά�����
            tcZxing.cpp
            zxing/                                  ��ά�����Ŀ�Դ�� (VC2010���޷����룬������ȥ��)
        Widgets/
            tcPageTurnWidget.h                      ��ҳ��ť��
            tcPageTurnWidget.cpp
            tcScreenshot.h                          ��������
            tcScreenshot.cpp
            tcScreenshot.ui
            tcShadowDialog.h                        ����Ӱ�Ϳ����ŵ��ޱ߶Ի�����
            tcShadowDialog.cpp
            tcShadowDialog.ui
            tcShadowDialog.qrc
            tcStyleToolDialog.h                     �ޱ߿򴰿ڼ���Ӱ�����Ź���
            tcStyleToolDialog.cpp
            tcStyleToolDialog.ui
            tcViewHeaderSetupDialog.h               QTreeWidget ��ͷ���öԻ���
            tcViewHeaderSetupDialog.cpp
            tcViewHeaderSetupDialog.ui
            tcViewHeaderSetupDialog.qrc
            tcWidget.h                              �Ի洰�ڵĿ��ƶ�����
            tcWidget.cpp
            tcWndCaption.qrc
            images/
                close.png                           tcShadowDialog ʹ�õĹرմ��ڵ�XͼƬ


    tianchi4qtc/                                    Qt Designer ���
        tianchi4qtc.pro                             ��������ļ���
                                                    ע��: ������ Release ģʽ���� !!!
                                                          Windows �±����� VC2010+ �±��� !!!

��ؿ�Դ�����Դ��1.0�����������
---------------------------------
���ԭ����μ���<https://github.com/qtcn/tianchi><br/>


�ر��л���빱�����Լ�����ά����Ա (�������)
----------------------------------
XChinux / www.qtcn.org ̳��<br/>
cnhemiya / �Ϲ���<br/>
roywillow<br/>
younghz<br/>
��������<br/>
foxgod<br/>
Jonix<br/>

#Tianchi2

��ؿ�Դ����� for Qt5.x

�˰汾Ϊ����������ʹ��

ʹ�÷�ʽ:
   1. ��̬���ӿⷽʽ���Ƽ���
      �򿪲����� tianchi/tianchi.pro , ���ɶ�̬���ӿ�
      ����λ�ã�bin/
      Debug  ʱ���ӿ⣺-lQt5Tianchid
      Releaseʱ���ӿ⣺-lQt5Tianchi

   2. ���Լ��Ĺ����ļ���ֱ�Ӱ������Դ���
      include(tianchi/tianchi_all.pri)

   3. ֱ��ʹ��Դ�����ļ�
      Tianchi2 ���ʱ�������ֵ����ļ���ʽ������ֻҪ�Ѷ�Ӧ
      �� .h/.cpp ֱ�����õ������ļ��м���ʹ��.
      ����ʹ�ÿ�Դ���Դ�ļ���Ҫͬʱ���뿪Դ���ļ�, ����
      ��μ� tianchi/tianchi_all.pri �е���������

   4. ��̬���ӿ�
      �򿪲����� tianchi/tianchi_lib.pro , ���ɾ�̬���ӿ�
      ����λ�ã�bin


�ļ��б���˵��:

bin/                                            ���������ļ���Ŀ¼
    Qt5Tianchid.lib (Qt5Tianchid.a )            ���ɵĶ�̬/��̬���ӿ�(Debug)
    Qt5Tianchid.dll (Qt5Tianchid.so)            ���ɵĶ�̬���ӿ�(Debug)
    Qt5Tianchi.lib  (Qt5Tianchi.a  )            ���ɵĶ�̬/��̬���ӿ�(Release)
    Qt5Tianchi.dll  (Qt5Tianchi.so )            ���ɵĶ�̬���ӿ�(Release)
    tianchi2_sample.exe                         ��ص���ʾ����

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
    tianchi_all.pri                             ��������ģ��������ļ�
    tianchi.pri                                 ����������ģ��������ļ�

    Common/
        tcCommon.h                              һЩ���õĹ�����Ԫ������ Tianchi �� common & utils �����˺ϲ�����
        tcCommon.cpp
        tcFunctionalSortFilterProxyModel.h      ��������˲���(QVariantMap)��ʹ�������˺������й��˵�ģ��
        tcFunctionalSortFilterProxyModel.cpp
        tcInvoke.h                              ӳ���źŲ۵�ִ�ж���
        tcInvoke.cpp
        tcRecentUse.hpp                         "���ʹ��"ģ���࣬���磺��������򿪵��ļ���Ĭ�����10��
        tcSingleton.hpp                         ��ָ��ʵ�ֵĵ���ģʽ��ģ����
        tcTuple.hpp                             �򵥵� Tuple(Ԫ��) ģ����, �ṩ2~10�����Ͳ�����ģ��
        tcVariantMapTableModel.h                ��QVariantMap��Ϊ�����е�model,ֻ��׷�Ӻ����,���ɲ�����ɾ��
        tcVariantMapTableModel.cpp
    Component/                                  Qt IDE �Ŀؼ�������Qt���ƣ�����ΪȫСд�ļ���
        QSint/                                  QSint ��Դ���(����), �������http://www.oschina.net/p/qsint
        Tianchi/                                Tianchi ���
            tcdateedit.h                        ��������Ϊ�յ�����ѡ����(IDE�ؼ�)
            tcdateedit.cpp
    Encrypt/
        tcAES.h                                 AES ����/���ܣ�ʹ�� Crypto++��
        tcAES.cpp
        cryptopp562/                            Crypto++5.6.2 ����/���ܿ�Դ��
    Gui/
        tcAutoCursor.h                          ���������ú��Զ��ָ�����
        tcAutoCursor.cpp
        tcGuiCommon.h                           һЩGUI��صĹ�����Ԫ��
        tcGuiCommon.cpp
    IO/
        tcExcel.h                               ͨ�� OLE ��ʽ���� Microsoft Excel������ Windows ��ʹ�ã�Ҫ���Ѱ�װ Excel��
        tcExcel.cpp
        tcExcelReader.h                         ͨ�� OLE ��ʽ��ȡ Microsoft Excel, WPS��Linux �½�֧��WPS��
        tcExcelReader.cpp
        tcIO.h                                  Ŀ¼���ļ��Ȳ�������
        tcIO.cpp
        tcLog.h                                 �򵥵��ı���־�������
        tcLog.cpp
    Network/
        tcDownloader.h                          �����ļ���������Ŀǰ��ʵ�� http �ļ�����
        tcDownloader.cpp
        tcFtp.h                                 Ftp ����
        tcFtp.cpp
        tcHttp.h                                http/https �������첽תΪͬ�����������ȴ��������ڵ�¼ʱ�ȴ�����
        tcHttp.cpp
        tcUdp.h                                 UdpЭ��ķ����Լ����շ�����
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
        zxing/                                  ��ά�����Ŀ�Դ��
    Widgets/
        tcPageTurnWidget.h                      ��ҳ��ť��
        tcPageTurnWidget.cpp
        tcScreenshot.h                          ����
        tcScreenshot.cpp
        tcScreenshot.ui
        tcShadowDialog.h                        ����Ӱ�Ϳ����ŵ��ޱ߶Ի�����
        tcShadowDialog.cpp
        tcShadowDialog.ui
        tcShadowDialog.qrc
        tcWidget.h                              �Ի洰�ڵĿ��ƶ�����
        tcWidget.cpp
        tcWndCaption.qrc
        tcWndSizer.h                            �����޿򴰿ڣ���ͬʵ�֣�����
        tcWndSizer.cpp
        images/
            close.png                           tcShadowDialog ʹ�õĹرմ��ڵ�XͼƬ


tianchi4qtc/                                    Qt Designer ���
    tianchi4qtc.pro                             ��������ļ���
                                                ע��: ������ Release ģʽ���� !!!
                                                      Windows �±����� VC2010+ �±��� !!!

��ؿ�Դ�����Դ��1.0�����������
���ԭ����μ���https://github.com/qtcn/tianchi


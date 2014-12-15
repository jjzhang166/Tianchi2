#Tianchi2

��ؿ�Դ����� for Qt5.x

�˰汾Ϊ����������ʹ��

ʹ�÷�ʽ:
   1. ֱ��ʹ��Դ�����ļ�
      Tianchi2 ���ʱ�������ֵ����ļ���ʽ������ֻҪ�Ѷ�Ӧ
      �� .h/.cpp ֱ�����õ������ļ��м���ʹ��

   2. ���Լ��Ĺ����ļ���ֱ�Ӱ������Դ���
      include(../tianchi/tianchi_all.pri)
      ����
      include(../tianchi/tianchi.pri)
      
      Ҳ���Ը�����Ҫ�ֱ����������ģ��:
      include(../tianchi/Common/Common.pri)
      include(../tianchi/Component/Component.pri)
      include(../tianchi/IO/IO.pri)
      include(../tianchi/Network/Network.pri)
      include(../tianchi/OS/OS.pri)
      include(../tianchi/Widgets/Widgets.pri)       

   3. ��̬���ӿ�
      �򿪲����� tianchi_lib.pro , ���ɾ�̬���ӿ�
      ����λ�ã�./bin

   4. ��̬���ӿ�
      �򿪲����� tianchi.pro , ���ɶ�̬���ӿ�
      ����λ�ã�./bin

�ļ��б���˵��:

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
        tcdateedit.h                            ��������Ϊ�յ�����ѡ����(IDE�ؼ�)
        tcdateedit.cpp
    Gui/
        tcAutoCursor.h                          ���������ú��Զ��ָ�����
        tcAutoCursor.cpp
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
        tcAdminAuthorization_win.h              ��������Ա��Ȩ��Windowsʵ��
        tcAdminAuthorization_x11.h              ��������Ա��Ȩ��Linux/BSDʵ��
        tcAdminAuthorization_mac.h              ��������Ա��Ȩ��MacOSʵ��
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
        tcSystemInfo_win.cpp
        tcSystemInfo_x11.cpp
        tcSystemInfo_mac.cpp
        tcWindows.h                             Microsoft Windows ϵͳ���ܣ�ֻ����Windows��ʹ��
        tcWindows.cpp
    Widgets/
        tcWndCaption.h                          �Ի洰�ڵĿ��ƶ�����
        tcWndCaption.cpp
        tcWndCaption.qrc
        tcWndCaption/
            close.png                           tcWndCaption ʹ�õĹرմ��ڵ�XͼƬ
        tcWndSizer.h                            �����޿򴰿�
        tcWndSizer.cpp


��ؿ�Դ�����Դ��1.0�����������
���ԭ����μ���https://github.com/qtcn/tianchi


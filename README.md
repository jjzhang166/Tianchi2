Tianchi2
========

Ìì³Ø¿ªÔ´Èí¼ş¿â for Qt5.x

´Ë°æ±¾ÎªÖØĞÂÕûÀí£¬¼ò»¯Ê¹ÓÃ

Ê¹ÓÃ·½Ê½:
---------
####1. ¶¯Ì¬Á´½Ó¿â·½Ê½£¨ÍÆ¼ö£©
´ò¿ª²¢±àÒë tianchi/tianchi.pro , Éú³É¶¯Ì¬Á´½Ó¿â<br/>
Éú³ÉÎ»ÖÃ£ºbin/<br/>
Debug  Ê±Á¬½Ó¿â£º```-lQt5Tianchid```<br/>
ReleaseÊ±Á¬½Ó¿â£º```-lQt5Tianchi```<br/>

####2. ÔÚ×Ô¼ºµÄ¹¤³ÌÎÄ¼şÖĞÖ±½Ó°üº¬Ìì³ØÔ´Âë¿â
ÔÚ.proÎÄ¼şÖĞÌí¼Ó£º```include(tianchi/tianchi.pri)```<br/>

####3. Ö±½ÓÊ¹ÓÃÔ´´úÂëÎÄ¼ş
Tianchi2 Éè¼ÆÊ±¾¡Á¿±£³Öµ¥×éÎÄ¼şĞÍÊ½£¬ËùÒÔÖ»Òª°Ñ¶ÔÓ¦<br/>
µÄ .h/.cpp Ö±½ÓÒıÓÃµ½¹¤³ÌÎÄ¼şÖĞ¼´¿ÉÊ¹ÓÃ.<br/>
¿·ÖÊ¹ÓÃ¿ªÔ´¿âµÄÔ´ÎÄ¼şĞèÒªÍ¬Ê±ÒıÈë¿ªÔ´¿âÎÄ¼ş, ¾ßÌå<br/>
Çë²Î¼û tianchi/tianchi.pri ÖĞµÄÒıÈëÄÚÈİ<br/>

####4. ¾²Ì¬Á´½Ó¿â
  ´ò¿ª²¢±àÒë tianchi/tianchi_lib.pro , Éú³É¾²Ì¬Á´½Ó¿â<br/>
  Éú³ÉÎ»ÖÃ£ºbin/<br/>


ÎÄ¼şÁĞ±íÓëËµÃ÷:
---------------
    bin/                                            ±àÒëÉú³ÉÎÄ¼şµÄÄ¿Â¼
        Qt5Tianchid.lib (Qt5Tianchid.a )            Éú³ÉµÄ¶¯Ì¬/¾²Ì¬Á´½Ó¿â(Debug)
        Qt5Tianchid.dll (Qt5Tianchid.so)            Éú³ÉµÄ¶¯Ì¬Á´½Ó¿â(Debug)
        Qt5Tianchi.lib  (Qt5Tianchi.a  )            Éú³ÉµÄ¶¯Ì¬/¾²Ì¬Á´½Ó¿â(Release)
        Qt5Tianchi.dll  (Qt5Tianchi.so )            Éú³ÉµÄ¶¯Ì¬Á´½Ó¿â(Release)
        tianchi2_sample.exe                         Ìì³ØµÄÑİÊ¾³ÌĞò
        tianchi4qtc.dll                             Qt Designer ²å¼ş
                                                    Çë¸´ÖÆµ½£ºC:\Qt\Qt5.4.0\Tools\QtCreator\bin\plugins\designer
                                                    ÖØÆô Qt Creator ºó¿ÉÔÚÉè¼ÆÆ÷ÖĞÊ¹ÓÃ

    help/
        Doxyfile                                    Doxygen Éú³ÉÎÄµµµÄÅäÖÃÎÄ¼ş

    QtCreatorPlugins/
        QtCreatorPlugins.pro                        ¿ÉÉú³É QtCreator µÄ±àÒë¿Ø¼ş(²å¼ş)
                                                    Windows ÏÂ±ØĞëÊ¹ÓÃ MSVC2010 ±àÒë
        readme.txt                                  Ğ¡°×±àÒëÇ°±Ø¶Á

    sample/                                         ÑİÊ¾³ÌĞòÄ¿Â¼
        sample.pro                                  ÑİÊ¾³ÌĞòµÄ¹¤³ÌÎÄ¼ş£¬²ÉÓÃÖ±½Ó°üº¬Ìì³Ø¿â·½Ê½


    tianchi/
        tianchi.pro                                 Éú³É¶¯Ì¬Á´½Ó¿â
        tianchi_lib.pro                             Éú³É¾²Ì¬Á´½Ó¿â
        tianchi_all.pri                             °üº¬ËùÓĞÄ£¿éµÄÒıÈëÎÄ¼ş
        tianchi.pri                                 Öğ²ã°üº¬ËùÓĞÄ£¿éµÄÒıÈëÎÄ¼ş

        Common/
            tcCommon.h                              Ò»Ğ©³£ÓÃµÄ¹«¹²µ¥Ôª¡£¸ù¾İ Tianchi µÄ common & utils ½øĞĞÁËºÏ²¢ÕûÀí
            tcCommon.cpp
            tcFunctionalSortFilterProxyModel.h      ÒÀËùÉè¹ıÂË²ÎÊı(QVariantMap)À´Ê¹ÓÃÒÑÉèÂËº¯Êı½øĞĞ¹ıÂËµÄÄ£ĞÍ
            tcFunctionalSortFilterProxyModel.cpp
            tcInvoke.h                              Ó³ÉäĞÅºÅ²ÛµÄÖ´ĞĞ¶ÔÏó
            tcInvoke.cpp
            tcRecentUse.hpp                         "×î½üÊ¹ÓÃ"Ä£°æÀà£¬ÀıÈç£ºÓÃÓÚ×î½ü´ò¿ªµÄÎÄ¼ş£¬Ä¬ÈÏ×î´ó10¸ö
            tcSingleton.hpp                         ÓÃÖ¸ÕëÊµÏÖµÄµ¥ÀıÄ£Ê½µÄÄ£°æÀà
            tcTuple.hpp                             ¼òµ¥µÄ Tuple(Ôª×é) Ä£°æÀà, Ìá¹©2~10¸öÀàĞÍ²ÎÊıµÄÄ£°æ
            tcVariantMapTableModel.h                ÒÔQVariantMap×÷ÎªÊı¾İĞĞµÄmodel,Ö»¿É×·¼ÓºÍÇå³ı,²»¿É²åÈëÓëÉ¾³ı
            tcVariantMapTableModel.cpp
        Component/                                  Qt IDE µÄ¿Ø¼ş£¬ÓÉÓÚQtÏŞÖÆ£¬±ØĞëÎªÈ«Ğ¡Ğ´ÎÄ¼şÃû
            QSint/                                  QSint ¿ªÔ´×é¼ş(²¿·Ö), ÇëÏê¼û£ºhttp://www.oschina.net/p/qsint
            Tianchi/                                Tianchi ×é¼ş
                tcdateedit.h                        ÔÊĞíÊäÈëÎª¿ÕµÄÈÕÆÚÑ¡Ôñ²å¼ş(IDE¿Ø¼ş)
                tcdateedit.cpp
        Encrypt/
            tcAES.h                                 AES ¼ÓÃÜ/½âÃÜ£¨Ê¹ÓÃ Crypto++£©
            tcAES.cpp
            cryptopp562/                            Crypto++5.6.2 ¼ÓÃÜ/½âÃÜ¿ªÔ´¿â
        Gui/
            tcAutoCursor.h                          Êó±ê¹â±êµÄÉèÖÃºÍ×Ô¶¯»Ö¸´´¦Àí
            tcAutoCursor.cpp
            tcGuiCommon.h                           Ò»Ğ©GUIÏà¹ØµÄ¹«¹²µ¥Ôª¡£
            tcGuiCommon.cpp
        IO/
            tcExcel.h                               Í¨¹ı OLE ·½Ê½²Ù×÷ Microsoft Excel£¨½öÏŞ Windows ÏÂÊ¹ÓÃ£¬ÒªÇóÒÑ°²×° Excel£©
            tcExcel.cpp
            tcExcelReader.h                         Í¨¹ı OLE ·½Ê½¶ÁÈ¡ Microsoft Excel, WPS£¨Linux ÏÂ½öÖ§³ÖWPS£©
            tcExcelReader.cpp
            tcIO.h                                  Ä¿Â¼¡¢ÎÄ¼şµÈ²Ù×÷¹¦ÄÜ
            tcIO.cpp
            tcLog.h                                 ¼òµ¥µÄÎÄ±¾ÈÕÖ¾Êä³ö¹¦ÄÜ
            tcLog.cpp
        Network/
            tcDownloader.h                          ÍøÂçÎÄ¼şÏÂÔØÆ÷£¬Ä¿Ç°½öÊµÏÖ http ÎÄ¼şÏÂÔØ
            tcDownloader.cpp
            tcFtp.h                                 Ftp ²Ù×÷
            tcFtp.cpp
            tcHttp.h                                http/https ÇëÇóÓÉÒì²½×ªÎªÍ¬²½£¬¼´¶ÂÈûµÈ´ı¡£³£ÓÃÓÚµÇÂ¼Ê±µÈ´ı·µ»Ø
            tcHttp.cpp
            tcUdp.h                                 UdpĞ­ÒéµÄ·¢ËÍÒÔ¼°½ÓÊÕ·şÎñÆ÷
            tcUdp.cpp
        OS/
            tcAdminAuthorization.h                  ²Ù×÷ÏµÍ³¹ÜÀíÔ±È¨ÏŞµÄÅĞ¶ÏºÍÌáÉıÈ¨ÏŞÖ´ĞĞ³ÌĞò
            tcAdminAuthorization_mac.cpp            ±¾»ú¹ÜÀíÔ±ÌáÈ¨£¬MacOSÊµÏÖ
            tcAdminAuthorization_win.cpp            ±¾»ú¹ÜÀíÔ±ÌáÈ¨£¬WindowsÊµÏÖ
            tcAdminAuthorization_x11.cpp            ±¾»ú¹ÜÀíÔ±ÌáÈ¨£¬Linux/BSDÊµÏÖ
            tcChinese.h                             Windows ÏÂºº×Ö×ªÆ´Òô¹¦ÄÜ
            tcChinese.cpp
            tcChinese.inc
            tcOS.h                                  ²Ù×÷ÏµÍ³Ïà¹Ø¹¦ÄÜ
            tcOS.cpp
            tcRunOnceChecker.h                      ³ÌĞòµ¥ÊµÀıÅĞ¶Ï£¬¼ì²éÊÇ·ñµ±Ç°³ÌĞòÊÇµÚÒ»´ÎÆô¶¯
            tcRunOnceChecker.cpp
            tcSelfRestarter.h                       ÊµÏÖ³ÌĞòÍË³öºó×Ô¶¯ÖØÆô
            tcSelfRestarter.cpp
            tcSystemInfo.h                          ´ÅÅÌ¡¢ÄÚ´æµÈÏµÍ³ĞÅÏ¢
            tcSystemInfo.cpp
            tcSystemInfo_mac.cpp
            tcSystemInfo_win.cpp
            tcSystemInfo_x11.cpp
            tcWindows.h                             Microsoft Windows ÏµÍ³¹¦ÄÜ£¬Ö»ÄÜÔÚWindowsÉÏÊ¹ÓÃ
            tcWindows.cpp
        QRCode/                                     ¶şÎ¬Âë±àÂë½âÂëÄ£¿é
            tcQrencode.h                            ¶şÎ¬Âë±àÂë
            tcQrencode.cpp
            qrencode/                               ¶şÎ¬Âë±àÂëµÄ¿ªÔ´¿â
            tcZxing.h                               ¶şÎ¬Âë½âÂë
            tcZxing.cpp
            zxing/                                  ¶şÎ¬Âë½âÂëµÄ¿ªÔ´¿â
        Widgets/
            tcPageTurnWidget.h                      ·­Ò³°´Å¥×é
            tcPageTurnWidget.cpp
            tcScreenshot.h                          ½ØÆÁ
            tcScreenshot.cpp
            tcScreenshot.ui
            tcShadowDialog.h                        º¬ÒõÓ°ºÍ¿ÉËõ·ÅµÄÎŞ±ß¶Ô»°¿ò¸¸Àà
            tcShadowDialog.cpp
            tcShadowDialog.ui
            tcShadowDialog.qrc
            tcWidget.h                              ×Ô»æ´°¿ÚµÄ¿ÉÒÆ¶¯±êÌâ
            tcWidget.cpp
            tcWndCaption.qrc
            tcWndSizer.h                            Ëõ·ÅÎŞ¿ò´°¿Ú£¬²»Í¬ÊµÏÖ£¬²»ÍÆ
            tcWndSizer.cpp
            images/
                close.png                           tcShadowDialog Ê¹ÓÃµÄ¹Ø±Õ´°¿ÚµÄXÍ¼Æ¬


    tianchi4qtc/                                    Qt Designer ×é¼ş
        tianchi4qtc.pro                             ×é¼ş¹¤³ÌÎÄ¼ş¡£
                                                    ×¢Òâ: ±ØĞëÒÔ Release Ä£Ê½±àÒë !!!
                                                          Windows ÏÂ±ØĞëÓÃ VC2010+ ÏÂ±àÒë !!!

Ìì³Ø¿ªÔ´Èí¼ş¿âÔ´×Ô1.0µÄÖØĞÂÕûÀí°æ
---------------------------------
×î³õÔ­°æÇë²Î¼û£º<https://github.com/qtcn/tianchi><br/>


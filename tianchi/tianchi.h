﻿/// @file tianchi.h
/// @brief 此头文件仅为方便使用，包含了所有具体头文件。用户可以根据需要进行筛减。

#include "Common/tcCommon.h"
#include "Common/tcInvoke.h"
#include "Component/QSint/actionbox.h"
#include "Component/QSint/actiongroup.h"
#include "Component/QSint/actionlabel.h"
#include "Component/QSint/actionpanel.h"
#include "Component/QSint/actionpanelscheme.h"
#include "Component/QSint/androidpanelscheme.h"
#include "Component/QSint/colordefs.h"
#include "Component/QSint/colorgrid.h"
#include "Component/QSint/macpanelscheme.h"
#include "Component/QSint/winvistapanelscheme.h"
#include "Component/QSint/winxppanelscheme.h"
#include "Component/tianchi/tcColorWheel.h"
#include "Component/tianchi/tcDateEdit.h"
#include "Component/wwWidgets/qwwHueSatPicker.h"
#include "Component/wwWidgets/qwwHueSatRadialPicker.h"
#include "Encrypt/tcAES.h"
#include "Encrypt/tcRSA.h"
#include "Gui/tcAutoCursor.h"
#include "Gui/tcGuiCommon.h"
#include "Gui/tcImageAdjust.h"
#include "IO/tcExcel.h"
#include "IO/tcExcelReader.h"
#include "IO/tcIO.h"
#include "IO/tcLog.h"
#include "Multimedia/tcTextToSpeech.h"
#include "Network/tcDownloader.h"
#include "Network/tcFtp.h"
#include "Network/tcHttp.h"
#include "Network/tcUdp.h"
#include "OS/tcAdminAuthorization.h"
#include "OS/tcChinese.h"
#include "OS/tcOS.h"
#include "OS/tcRunOnceChecker.h"
#include "OS/tcSelfRestarter.h"
#include "OS/tcSystemInfo.h"
#include "OS/tcWindows.h"
#include "QRCode/tcQrencode.h"
#include "QRCode/tcZxing.h"
#include "Widgets/tcPageTurnWidget.h"
#include "Widgets/tcScreenshot.h"
#include "Widgets/tcShadowDialog.h"
#include "Widgets/tcViewHeaderSetupDialog.h"
#include "Widgets/tcWidget.h"

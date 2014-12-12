#include "tcWindows.h"

#if defined(Q_OS_WIN)

#include <QDir>
#include <QFile>
#include <QFileInfo>

#include <ObjBase.h>

#ifndef PIDLIST_ABSOLUTE
typedef ITEMIDLIST *PIDLIST_ABSOLUTE;
#endif

bool TcWindows::createLink(const QString &fileName, const QString &linkName,
                const QString &arguments, const QString &iconPath,
                const QString &iconId)
{
    QString tlinkName = linkName;
    if (!tlinkName.endsWith(".lnk")) tlinkName += ".lnk";
    bool success = QFile::link(fileName, tlinkName);

    if (!success)
        return success;

    CoInitialize(NULL);

    QString workingDir = QFileInfo(fileName).absolutePath();
    workingDir = QDir::toNativeSeparators(workingDir);

    IShellLink *psl = NULL;
    if (FAILED(CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl)))
    {
        CoUninitialize();
        return success;
    }

    psl->SetPath((wchar_t *)QDir::toNativeSeparators(fileName).utf16());
    psl->SetWorkingDirectory((wchar_t *)workingDir.utf16());
    if (!arguments.isNull())
        psl->SetArguments((wchar_t*)arguments.utf16());
    if (!iconPath.isNull())
        psl->SetIconLocation((wchar_t*)(iconPath.utf16()), iconId.toInt());

    IPersistFile *ppf = NULL;
    if (SUCCEEDED(psl->QueryInterface(IID_IPersistFile, (void **)&ppf))) {
        ppf->Save((wchar_t*)QDir::toNativeSeparators(tlinkName).utf16(), true);
        ppf->Release();
    }
    psl->Release();

    PIDLIST_ABSOLUTE pidl;

    if (SUCCEEDED(SHGetFolderLocation(0, CSIDL_STARTMENU, 0, 0, &pidl))) {
        SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_IDLIST, pidl, 0);
        CoTaskMemFree(pidl);
    }
    if (SUCCEEDED(SHGetFolderLocation(0, CSIDL_COMMON_STARTMENU, 0, 0, &pidl))) {
        SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_IDLIST, pidl, 0);
        CoTaskMemFree(pidl);
    }
    CoUninitialize();
    return success;
}

QString TcWindows::getWinSysDir(SYSTEMPATH path)
{
    CoInitialize(NULL);
    PIDLIST_ABSOLUTE pidl;  // Force start menu cache update
    wchar_t MyDir[_MAX_PATH] = {0};
    if (SUCCEEDED(SHGetFolderLocation(0, path, 0, 0, &pidl)))
    {
        SHGetPathFromIDList(pidl,MyDir);
        SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_IDLIST, pidl, 0);
        CoTaskMemFree(pidl);
    }
    CoUninitialize();
    return QString::fromWCharArray(MyDir).replace("\\","/");
}

#endif // Q_OS_WIN


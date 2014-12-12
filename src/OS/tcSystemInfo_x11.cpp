#include "tcSystemInfo.h"

quint64 TcRunInfo::installedMemory()
{
#ifdef Q_OS_LINUX
    QFile f(QLatin1String("/proc/meminfo"));
    f.open(QIODevice::ReadOnly);
    QTextStream stream(&f);
    while (true) {
        const QString s = stream.readLine();
        if( !s.startsWith(QLatin1String("MemTotal:" )))
            continue;
        else if (s.isEmpty())
            return quint64();

        const QStringList parts = s.split(QLatin1Char(' '), QString::SkipEmptyParts);
        return quint64(parts.at(1).toInt() * 1024LL);
    }
#else
    quint64 physmem;
    size_t len = sizeof physmem;
    static int mib[2] = { CTL_HW, HW_MEMSIZE };
    sysctl(mib, 2, &physmem, &len, 0, 0);
    return quint64(physmem);
#endif
    return 0;
}

QList<TcVolumeInfo> TcRunInfo::mountedVolumes()
{
    QList<TcVolumeInfo> result;

    QFile f(QLatin1String("/etc/mtab"));
    if (!f.open(QIODevice::ReadOnly)) {
        qCritical("%s: Could not open %s: %s", Q_FUNC_INFO, qPrintable(f.fileName()), qPrintable(f.errorString()));
        return result; //better error-handling?
    }

    QTextStream stream(&f);
    while (true) {
        const QString s = stream.readLine();
        if (s.isNull())
            return result;

        if (!s.startsWith(QLatin1Char('/')) && !s.startsWith(QLatin1String("tmpfs ") + QDir::tempPath()))
            continue;

        const QStringList parts = s.split(QLatin1Char(' '), QString::SkipEmptyParts);

        VolumeInfo v;
        v.setMountPath(parts.at(1));
        v.setVolumeDescriptor(parts.at(0));
        v.setFileSystemType(parts.value(2));

        struct statvfs data;
        if (statvfs(qPrintable(v.mountPath() + QLatin1String("/.")), &data) == 0) {
            v.setSize(quint64(static_cast<quint64>(data.f_blocks) * data.f_bsize));
            v.setAvailableSize(quint64(static_cast<quint64>(data.f_bavail) * data.f_bsize));
        }
        result.append(v);
    }
    return result;
}

QList<TcProcessInfo> TcRunInfo::runningProcesses()
{
    QList<TcProcessInfo> processes;
    QDir procDir(QLatin1String("/proc"));
    const QFileInfoList procCont = procDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Readable);
    QRegExp validator(QLatin1String("[0-9]+"));
    Q_FOREACH (const QFileInfo &info, procCont) {
        if (validator.exactMatch(info.fileName())) {
            const QString linkPath = QDir(info.absoluteFilePath()).absoluteFilePath(QLatin1String("exe"));
            const QFileInfo linkInfo(linkPath);
            if (linkInfo.exists()) {
                ProcessInfo processInfo;
                processInfo.name = linkInfo.symLinkTarget();
                processInfo.id = info.fileName().toInt();
                processes.append(processInfo);
            }
        }
    }
    return processes;
}

bool TcRunInfo::killProcess(const TcProcessInfo &process, int msecs)
{
    Q_UNUSED(process);
    Q_UNUSED(msecs);

    return true;
}

bool TcRunInfo::pathIsOnLocalDevice(const QString &path)
{
    Q_UNUSED(path);

    return true;
}


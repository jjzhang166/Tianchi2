#include "tcSystemInfo.h"

quint64 TcRunInfo::installedMemory()
{
    SInt32 mb = 0;
    Gestalt(gestaltPhysicalRAMSizeInMegabytes, &mb);
    return quint64(static_cast<quint64>(mb) * 1024LL * 1024LL);
}

QList<TcVolumeInfo> TcRunInfo::mountedVolumes()
{
    QList<TcVolumeInfo> result;
    FSVolumeRefNum volume;
    FSVolumeInfo info;
    HFSUniStr255 volName;
    FSRef ref;
    int i = 0;

    while (FSGetVolumeInfo(kFSInvalidVolumeRefNum, ++i, &volume, kFSVolInfoFSInfo, &info, &volName, &ref) == 0) {
        UInt8 path[PATH_MAX + 1];
        if (FSRefMakePath(&ref, path, PATH_MAX) == 0) {
            FSGetVolumeInfo(volume, 0, 0, kFSVolInfoSizes, &info, 0, 0);

            VolumeInfo v;
            v.setSize(quint64(info.totalBytes));
            v.setAvailableSize(quint64(info.freeBytes));
            v.setMountPath(QString::fromLocal8Bit(reinterpret_cast< char* >(path)));

            struct statfs data;
            if (statfs(qPrintable(v.mountPath() + QLatin1String("/.")), &data) == 0) {
                v.setFileSystemType(QLatin1String(data.f_fstypename));
                v.setVolumeDescriptor(QLatin1String(data.f_mntfromname));
            }
            result.append(v);
        }
    }
    return result;
}

QList<TcProcessInfo> TcRunInfo::runningProcesses()
{
    int mib[4] = {
        CTL_KERN,
        KERN_ARGMAX,
        0,
        0
    };

    int argMax = 0;
    size_t argMaxSize = sizeof(argMax);
    // fetch the maximum process arguments size
    sysctl(mib, 2, &argMax, &argMaxSize, NULL, 0);
    char *processArguments = (char*) malloc(argMax);

    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_ALL;
    size_t processTableSize = 0;
    // fetch the kernel process table size
    sysctl(mib, 4, NULL, &processTableSize, NULL, 0);
    struct kinfo_proc *processTable = (kinfo_proc*) malloc(processTableSize);

    // fetch the process table
    sysctl(mib, 4, processTable, &processTableSize, NULL, 0);

    QList<ProcessInfo> processes;
    for (size_t i = 0; i < (processTableSize / sizeof(struct kinfo_proc)); ++i) {
        struct kinfo_proc *process = processTable + i;

        ProcessInfo processInfo;
        processInfo.id = process->kp_proc.p_pid;

        mib[1] = KERN_PROCARGS2;
        mib[2] = process->kp_proc.p_pid;
        mib[3] = 0;

        size_t size = argMax;
        // fetch the process arguments
        if (sysctl(mib, 3, processArguments, &size, NULL, 0) != -1) {
            /*
             * |-----------------| <-- data returned by sysctl()
             * |      argc       |
             * |-----------------|
             * | executable path |
             * |-----------------|
             * |    arguments    |
             * ~~~~~~~~~~~~~~~~~~~
             * |-----------------|
            */
            processInfo.name = QString::fromLocal8Bit(processArguments + sizeof(int));
        } else {
            // if we fail, use the name from the process table
            processInfo.name = QString::fromLocal8Bit(process->kp_proc.p_comm);
        }
        processes.append(processInfo);
    }
    free(processTable);
    free(processArguments);

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



#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
FileSystem &FileSystem::getInstance()
{
    static FileSystem instance;

    instance.setConfigDir("cfg");
    instance.setRoutesDir("routes");

    return instance;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
QString FileSystem::combine(const QString &path1, const QString &path2)
{
    if (*(path1.end() - 1) != QDir::separator())
        return QDir::toNativeSeparators(path1 + QDir::separator() + path2);
    else
        return QDir::toNativeSeparators(path1 + path2);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void FileSystem::setConfigDir(const QString &name)
{
    setDirPath("XDG_DATA_HOME", combine(appName, name), configDir);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void FileSystem::setRoutesDir(const QString &name)
{
    setDirPath("XDG_DATA_HOME", combine(appName, name), routesDir);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void FileSystem::setDataDir(const QString &name)
{
    setDirPath("XDG_DATA_HOME", combine(appName, name), dataDir);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
QString FileSystem::getLevelUpDirectory(QString path, int num_levels_up)
{
    QDir dir(path);

    for (int i = 0; i < num_levels_up; ++i)
        dir.cdUp();

    return dir.path() + QDir::separator();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void FileSystem::setDirPath(const QString &baseDirEnv,
                            const QString &dirName, QString &dirPath)
{
    Q_UNUSED(baseDirEnv)

#ifdef __WIN32
    QString workDir = QDir::currentPath();
    QString winRootDir = getLevelUpDirectory(workDir, 1);
    dirPath = QDir::toNativeSeparators(winRootDir + dirName);
#endif

#ifdef __unix__
    dirPath = QDir::toNativeSeparators(QString(std::getenv(baseDirEnv.toStdString().c_str())) +
              QDir::separator() + dirName);
#endif
}

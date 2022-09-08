#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
FileSystem &FileSystem::getInstance()
{
    static FileSystem instance;

    QString workDir = QDir::currentPath();
    instance.setConfigDir(workDir, "cfg");

    return instance;
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
void FileSystem::setConfigDir(const QString &workDir,
                              const QString &dirName)
{
    QString winRootDir = getLevelUpDirectory(workDir, 1);

#ifdef __WIN32
    configDir = winRootDir + dirName;
#endif

#ifdef __unix__
    configDir = QString(std::getenv("XDG_CONFIG_HOME")) +
            QDir::separator() + dirName;
#endif

}

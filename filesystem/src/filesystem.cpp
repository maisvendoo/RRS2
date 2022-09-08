#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
FileSystem &FileSystem::getInstance()
{
    static FileSystem instance;

    QString workDir = QDir::currentPath();

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

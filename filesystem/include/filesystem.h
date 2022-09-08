#ifndef     FILESYSTEM_H
#define     FILESYSTEM_H

#include    <QDir>

#ifdef  FILESYSTEM_LIB
    #define FILESYSTEM_EXPORT   Q_DECL_EXPORT
#else
    #define FILESYSTEM_EXPORT   Q_DECL_IMPORT
#endif

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class FILESYSTEM_EXPORT FileSystem
{
public:

    static FileSystem &getInstance();

    /// Сборка пути из двух половинок
    QString combinePath(const QString &path1, const QString &path2);

    QString getConfigDir() const { return configDir; }

    QString getRoutesDir() const { return routesDir; }

    QString getDataDir() const {return dataDir; }

    QString getModulesDir() const { return modulesDir; }

private:

    // Имя приложения
    const QString appName = "RRS";

    // Каталог конфигов
    QString configDir;
    // Каталог маршрутов
    QString routesDir;

    QString dataDir;

    QString modulesDir;

    FileSystem() {}
    FileSystem(const FileSystem &) = delete;
    FileSystem &operator=(FileSystem &) = delete;

    void setConfigDir(const QString &name);

    void setRoutesDir(const QString &name);

    void setDataDir(const QString &name);

    void setModulesDir(const QString &name);

    QString getLevelUpDirectory(QString path, int num_levels_up);

    void setDirPath(const QString &baseDirEnv,
                    const QString &dirName,
                    QString &dirPath);

};

#endif // FILESYSTEM_H

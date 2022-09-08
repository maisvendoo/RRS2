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

private:

    FileSystem() {}
    FileSystem(const FileSystem &) = delete;
    FileSystem &operator=(FileSystem &) = delete;

    QString getLevelUpDirectory(QString path, int num_levels_up);
};

#endif // FILESYSTEM_H

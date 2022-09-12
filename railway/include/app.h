#ifndef     APP_H
#define     APP_H

#include    <QCoreApplication>
#include    <QCommandLineParser>

#include    "railway-cmd-line.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class App : public QCoreApplication
{
    Q_OBJECT

public:

    explicit App(int argc, char *argv[]);

    ~App();

    int exec();

private:

    QCommandLineParser  cmdParser;

    railway_cmd_line_t  cmdLine;

    CmdLineParseResult parseCmdLine(QCommandLineParser &parser,
                                    railway_cmd_line_t &cmdLine,
                                    QString &errorMessage);
};

#endif // APP_H

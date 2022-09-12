#include    "app.h"
#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
App::App(int argc, char *argv[]) : QCoreApplication(argc, argv)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
App::~App()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int App::exec()
{
    FileSystem &fs = FileSystem::getInstance();

    return QCoreApplication::exec();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
CmdLineParseResult App::parseCmdLine(QCommandLineParser &parser,
                                     railway_cmd_line_t &cmdLine,
                                     QString &errorMessage)
{
    QCommandLineOption help = parser.addHelpOption();
    QCommandLineOption version = parser.addVersionOption();

    QCommandLineOption routeDir(QStringList() << "r" << "route",
                                QCoreApplication::translate("main", "Route directory"),
                                QCoreApplication::translate("main", "route-directory"));

    parser.addOption(routeDir);


    if (!parser.parse(this->arguments()))
    {
        errorMessage = parser.errorText();
        return CmdLineError;
    }

    if (parser.isSet(version))
    {
        return CmdLineVersion;
    }

    if (parser.isSet(help))
    {
        return CmdLineHelp;
    }

    if (parser.isSet(routeDir))
    {
        cmdLine.route_dir.is_present = true;
        cmdLine.route_dir.value = parser.value(routeDir);
    }

    return CmdLineOk;
}

#ifndef     RAILWAY_CMD_LINE_H
#define     RAILWAY_CMD_LINE_H

#include    "cmd-line-option.h"

#include    <QString>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
struct railway_cmd_line_t
{
    /// Каталог с текущим маршрутом
    option_t<QString>   route_dir;
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum CmdLineParseResult
{
    CmdLineOk,
    CmdLineError,
    CmdLineVersion,
    CmdLineHelp
};

#endif // RAILWAY_CMD_LINE_H

#ifndef     APP_H
#define     APP_H

#include    <QCoreApplication>
#include    <QCommandLineParser>

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
};

#endif // APP_H

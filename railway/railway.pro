TEMPLATE = app

QT -= gui
QT += core
QT += xml
QT += network

CONFIG += c++17
CONFIG += console

DESTDIR = ../../bin

TARGET = railway

CONFIG(debug, debug|release) {

    TARGET = $$join(TARGET,,,_d)

    LIBS += -L../../lib -lCfgReader_d
    LIBS += -L../../lib -lfilesystem_d


} else {

    LIBS += -L../../lib -lCfgReader
    LIBS += -L../../lib -lfilesystem

}

INCLUDEPATH += ./include
INCLUDEPATH += ../filesystem/include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)

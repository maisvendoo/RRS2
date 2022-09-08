TEMPLATE = lib

QT += core

CONFIG += qt
CONFIG += c++17

TARGET = filesystem

DEFINES += FILESYSTEM_LIB

DESTDIR = ../../lib

CONFIG(debug, debug|release) {

    TARGET = $$join(TARGET,,,_d)
} else {

}

INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)

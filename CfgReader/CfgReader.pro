TEMPLATE = lib

QT -= qui
QT += xml

CONFIG += c++17

TARGET = CfgReader

DEFINES += CFG_READER_LIB

DESTDIR = ../../lib

CONFIG(debug, debug|release) {

    TARGET = $$join(TARGET,,,_d)
} else {

}

INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)

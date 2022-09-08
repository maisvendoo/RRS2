TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += ./CfgReader
SUBDIRS += ./filesystem
SUBDIRS += ./railway

HEADERS += \
    common-headers/include/cmd-line.h

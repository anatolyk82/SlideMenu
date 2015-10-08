TEMPLATE = app

QT += qml quick widgets

android: {
QT += androidextras
}

SOURCES += sources/main.cpp \
    sources/mydevice.cpp

HEADERS += sources/mydevice.h

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)


#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "mydevice.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<MyDevice>("mydevice", 1, 0, "MyDevice");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}


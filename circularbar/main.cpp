#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "clqmlcircularbar.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<clQmlCircularBar>("QmlCircularBar", 1, 0, "CircularBar");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

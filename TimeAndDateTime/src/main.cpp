#include <QtQml>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cppclass.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CppClass>("com.franco.custom", 0, 1, "CppClass");
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("TimeAndDateTime", "Main");

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "t5x5backend.h"


// int main(int argc, char *argv[])
// {
//     QGuiApplication app(argc, argv);
//     QQmlApplicationEngine engine;
//
//     qmlRegisterType<T5x5Backend>("BoardGames.Backend", 1, 0, "T5x5Backend");
//
//
//     QObject::connect(
//         &engine,
//         &QQmlApplicationEngine::objectCreationFailed,
//         &app,
//         []() { QCoreApplication::exit(-1); },
//         Qt::QueuedConnection);
//
//
//     engine.loadFromModule("BoardGame", "Main");
//     engine.load(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "TicTacToe5x5.qml"));
//
//     return app.exec();
// }
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    T5x5Backend x5_backend;
    engine.rootContext()->setContextProperty("x5_backend", &x5_backend);

    engine.loadFromModule("BoardGame", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

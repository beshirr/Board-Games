#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "t5x5backend.h"

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

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.loadFromModule("BoardGame", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

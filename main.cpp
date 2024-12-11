#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TicTacToe5x5.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Board5x5 game_board5x5;
    engine.rootContext()->setContextProperty("Board5x5", &game_board5x5);

    engine.loadFromModule("BoardGame", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

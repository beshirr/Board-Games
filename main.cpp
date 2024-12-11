#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TicTacToe5x5.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Board5x5 game_board5x5;
    engine.rootContext()->setContextProperty("Board5x5", &game_board5x5);
    Player5x5* players[2];
    engine.rootContext()->setContextProperty("Player5x5", *players);
    engine.loadFromModule("BoardGame", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TicTacToe5x5.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<Board5x5>("TicTacToe5x5", 1, 0, "Board5x5");
    qmlRegisterType<Player5x5>("TicTacToe5x5", 1, 0, "Player5x5");
    qmlRegisterType<RandomPlayer5x5>("TicTacToe5x5", 1, 0, "RandomPlayer5x5");

    engine.loadFromModule("BoardGame", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

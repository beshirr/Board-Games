#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TicTacToe5x5.h"
#include "Misere.h"
// #include "PyramidTicTacToe.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<Board5x5>("TicTacToe5x5", 1, 0, "Board5x5");
    qmlRegisterType<Player5x5>("TicTacToe5x5", 1, 0, "Player5x5");
    qmlRegisterType<RandomPlayer5x5>("TicTacToe5x5", 1, 0, "RandomPlayer5x5");
    // qmlRegisterType<PyramidBoard>("PyramidTicTacToe", 1, 0, "PyramidBoard");
    // qmlRegisterType<PyramidPlayer>("PyramidTicTacToe", 1, 0, "PyramidPlayer");
    qmlRegisterType<MisereBoard>("Misere", 1, 0, "MisereBoard");
    qmlRegisterType<MiserePlayer>("Misere", 1, 0, "MiserePlayer");
    qmlRegisterType<MisereRandomPlayer>("Misere", 1, 0, "MisereRandomPlayer");

    engine.loadFromModule("BoardGame", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

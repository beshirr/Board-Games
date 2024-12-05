#include "t5x5backend.h"

T5x5Backend::T5x5Backend(QObject *parent)
    : QObject{parent} {
    player2Type = 1;
}


void T5x5Backend::Main() const {
    Player<QChar>* players[2];
    Board5x5<QChar>* B = new Board5x5<QChar>();

    players[0] = new Player5x5<QChar>("Player 1", 'X');
    if (player2Type == 1) {
        players[1] = new Player5x5<QChar>("Player 2", 'O');
    }

    GameManager<QChar> t5x5(B, players);
    t5x5.run();

    // TODO: think about it if you want to keep data and adding scores
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

void T5x5Backend::changePlayerType() {
    (player2Type == 1)? player2Type = 2: player2Type = 1;
}

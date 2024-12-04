#ifndef TICTACTOE5X5_H
#define TICTACTOE5X5_H

#include "BoardGame_Classes.h"

template <typename T>
class Board5x5 : Board<T> {
public:
    Board5x5();
    ~Board5x5();
    bool update_board(int x, int y, string symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

template <typename T>
class Player5x5 : Player<T> {
public:
    Player5x5(string name, T symbol);
    void getmove(T &x, T &y) override;
};




#endif // TICTACTOE5X5_H



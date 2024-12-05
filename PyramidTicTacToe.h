#ifndef PYRAMIDTICTACTOE_H
#define PYRAMIDTICTACTOE_H
#include "BoardGame_Classes.h"
#include <iostream>

class PyramidBoard : public Board<char>{
public:
    PyramidBoard();
    ~PyramidBoard();
    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

class PyramidPlayer: public Player<char>{
public:
    PyramidPlayer(string playerName, char playerSymbol);
    void getmove(int& x, int& y) override;
};




#endif //PYRAMIDTICTACTOE_H


#ifndef PYRAMIDTICTACTOE_H
#define PYRAMIDTICTACTOE_H
#include "BoardGame_Classes.h"
#include <iostream>


class PyramidBoard : public Board<string>{

public:
    PyramidBoard();

    ~PyramidBoard();

    bool update_board(int x, int y, string symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;
};

class PyramidPlayer: public Player<string>{
public:
    PyramidPlayer(string name, string symbol);

    void getmove(int& x, int& y) override;
};

class PyramidRandomPlayer: public RandomPlayer<string>{
public:
    PyramidRandomPlayer(string symbol);

    void getmove(int& x, int& y) override;
};




#endif //PYRAMIDTICTACTOE_H
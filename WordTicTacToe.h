#ifndef WORDTICTACTOE_H
#define WORDTICTACTOE_H

#include "BoardGame_Classes.h"
#include <iostream>


class WordBoard: public Board<char>{
public:
    WordBoard();
    ~WordBoard();
    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

class WordPlayer: public Player<char>{
public:
    WordPlayer(string playerName, char playerSymbol);
    void getmove(int& x, int& y) override;
};


#endif WORDTICTACTOE_H

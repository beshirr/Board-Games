#ifndef WORDTICTACTOE_H
#define WORDTICTACTOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>


class WordBoard: public Board<string>{


private:
    string WordsFile;
    bool is_word(const string& word);


public:
    WordBoard();
    ~WordBoard();
    bool update_board(int x, int y, string symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;

};

class WordPlayer: public Player<string>{
public:
    WordPlayer(const string& playerName, string playerSymbol);
    void getmove(int& x, int& y) override;


};

class WordRandomPlayer: public RandomPlayer<string>{
public:
    WordRandomPlayer(string symbol);
    void getmove(int& x, int& y) override;
};


#endif //WORDTICTACTOE_H

#ifndef BOARDGAME_ULTIMATETICTACTOE_H
#define BOARDGAME_ULTIMATETICTACTOE_H

#include "BoardGame_Classes.h"


using namespace std;

class UltimateBoard: public Board<string> {
private:
    int currentBoard;
    string ***boards;
    string miniBoard[3][3];
    int playerTurn;


public:
    UltimateBoard();

    ~UltimateBoard();

    bool update_board(int x, int y, string symbol) override;

    void update_mini_board(int i, string symbol);

    void display_board() override;

    bool is_mini_win();

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;
};



class UltimatePlayer: public Player<string> {

public:
    UltimatePlayer(string name, string symbol);
    void getmove(int &x, int &y) override;
};


#endif //BOARDGAME_ULTIMATETICTACTOE_H

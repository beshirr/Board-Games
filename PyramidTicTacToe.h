#ifndef PYRAMIDTICTACTOE_H
#define PYRAMIDTICTACTOE_H
#include "BoardGame_Classes.h"
#include <iostream>
#include <QString>

class PyramidBoard : public Board<QString>{
public:
    PyramidBoard();
    ~PyramidBoard();
    bool update_board(int x, int y, QString symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

class PyramidPlayer: public Player<QString>{
public:
    PyramidPlayer(string playerName, QString playerSymbol);
    void getmove(int& x, int& y) override;
};




#endif //PYRAMIDTICTACTOE_H




// Implementation ----------------------------------------------------------------


PyramidBoard::PyramidBoard(){
    rows = 3;
    columns = 5;
    board = new QString* [rows];
    for(int i = 0; i < rows; i++) {
        board[i] = new QString[columns];
        for(int j = 0; j < columns; j++) {
            board[i][j] = "-";
        }
    }
    board[0][0] = board[0][1] = board[0][3] = board[0][4] = board[1][0] = board[1][4] = " ";
}

PyramidBoard::~PyramidBoard() {
    for(int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool PyramidBoard::update_board(int x, int y, QString symbol) {
    if (x < 0 || y < 0 || x >= rows || y >= columns || board[x][y] != "-")return false;
    else {
        board[x][y] = symbol;
        n_moves++;
        return true;
    }
}

void PyramidBoard::display_board() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << board[i][j].toStdString() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool PyramidBoard::is_win() {
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < columns-2; ++j) {
            if((board[i][j] == board[i][j+1]) && (board[i][j] == board[i][j+2]) && (board[i][j] != '-'))return true;
            if ((j == 2) && (i == 1)){
                if((board[i][j] == board[i+1][j]) && (board[i][j] == board[i-1][j]) && (board[i][j]!= '-')) return true;
            }
        }
    }
    if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && (board[0][2] != '-')) return true;
    else if ((board[0][2] == board[1][3]) && (board[0][2] == board[2][4]) && (board[0][2] != '-')) return true;

    return false;
}

bool PyramidBoard::is_draw() {
    if (n_moves == 9) return true;
    return false;
}

bool PyramidBoard::game_is_over() {
    return is_win() || is_draw();
}

void PyramidPlayer::getmove(int &x, int &y) {
    cout << name << ", enter your move (x y): ";
    cin >> x >> y;
    x--;
    y--;
}

PyramidPlayer::PyramidPlayer(string playerName, QString playerSymbol) : Player(playerName, playerSymbol){};


#include "WordTicTacToe.h"
#include <iostream>

using namespace std;

WordBoard::WordBoard(){
    rows = 3;
    columns = 3;
    board = new char*[rows];
    for(int i = 0; i < rows; i++) {
        board[i] = new char[columns];
        for(int j = 0; j < columns; j++) {
            board[i][j] = '-';
        }
    }
}

WordBoard::~WordBoard(){
    for(int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool WordBoard::update_board(int x, int y, char symbol) {
    if (x < 0 || y < 0 || x >= rows || y >= columns || board[x][y] != '-')return false;
    else {
        board[x][y] = symbol;
        n_moves++;
        return true;
    }
}

void WordBoard::display_board() {
    for(int i = 0; i < rows; i++) {
        cout << i+1 << " ";
        for(int j = 0; j < columns; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool WordBoard::is_word(){

}

bool WordBoard::is_win() {
    for(int i = 0; i < rows; i++) {

    }
}

bool WordBoard::is_draw() {
    if (n_moves == 9) return true;
    return false;
}

bool WordBoard::game_is_over() {
    return is_win() || is_draw();
}

WordPlayer::WordPlayer(string playerName, char playerSymbol): Player(playerName, playerSymbol) {}

void WordPlayer::getmove(int &x, int &y) {
    cout << name << ", enter your move (x y): ";
    cin >> x >> y;
    x--;
    y--;
}
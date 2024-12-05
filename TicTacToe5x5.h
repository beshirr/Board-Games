#ifndef TICTACTOE5X5_H
#define TICTACTOE5X5_H

#include "BoardGame_Classes.h"

template <typename T>
class Board5x5 : public Board<T> {
private:
    int p1_nWins, p2_nWins;

public:
    Board5x5();
    ~Board5x5();
    bool update_board(int x, int y, QChar symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};


template <typename T>
class Player5x5 : public Player<T> {
public:
    Player5x5(string name, T symbol);
    void getmove(int &x, int &y) override;
};


template <typename T>
class RandomPlayer5x5 : public RandomPlayer<T> {
public:
    RandomPlayer5x5(T symbol);
    void getmove(int &x, int &y) override;
};




template<typename T>
Board5x5<T>::Board5x5() {
    this->rows = this->columns = 5;
    this->board = new QChar*[5];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new QChar[5];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }

    this->n_moves = 0;
    this->p1_nWins = this->p2_nWins = 0;
}


template<typename T>
Board5x5<T>::~Board5x5() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}


template<typename T>
bool Board5x5<T>::update_board(int x, int y, QChar symbol) {
    if (this->board[x][y] == ' ') {
        this->board[x][y] = symbol;
        return true;
    }
    return false;
}


template<typename T>
void Board5x5<T>::display_board() {

}


template<typename T>
bool Board5x5<T>::is_win() {

}


template<typename T>
bool Board5x5<T>::is_draw() {
    return this->n_moves == 24 && p1_nWins == p2_nWins;
}


template<typename T>
bool Board5x5<T>::game_is_over() {
    return this->n_moves == 24;
}


template <typename T>
Player5x5<T>::Player5x5(string name, T symbol) : Player<T>(name, symbol) {}


template<typename T>
void Player5x5<T>::getmove(int &x, int &y) {
    // x = object.setCell()[0]
    // y =
}


template<typename T>
RandomPlayer5x5<T>::RandomPlayer5x5(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 5;
    this->name = "Computer";
    srand(static_cast<unsigned int>(time(0)));
}


#endif // TICTACTOE5X5_H



/**
 * @file TicTacToe5x5.h
 * @brief The backend file of 5x5 Tic Tac Toe
 */
#ifndef TICTACTOE5X5_H
#define TICTACTOE5X5_H

#include <QObject>
#include <utility>
#include "BoardGame_Classes.h"


class Board5x5 : public QObject,public Board<QChar> {
    Q_OBJECT
private:
    int p1_nWins, p2_nWins;

public:
    explicit Board5x5(QObject* parent = nullptr) {
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


    bool update_board(const int x, const int y, const QChar symbol) override {
        if (this->board[x][y] == ' ') {
            this->board[x][y] = symbol;
            return true;
        }
        return false;
    }


    void display_board() override {}



    bool is_win() override {
        return true;
    }


    bool is_draw() override {
        return this->n_moves == 24 && p1_nWins == p2_nWins;
    }


    bool game_is_over() override {
        return this->n_moves == 24;
    }
};


class Player5x5 : public QObject, public Player<QChar> {
    Q_OBJECT
public:
    explicit Player5x5(QObject* parent, string name, const QChar symbol) :  QObject(parent),
    Player(std::move(name), symbol) {}
    void getmove(int &x, int &y) override {}
};


class RandomPlayer5x5 : public QObject, public RandomPlayer<QChar> {
    Q_OBJECT
public:
    explicit RandomPlayer5x5(QObject* parent, const QChar symbol) :  QObject(parent), RandomPlayer(symbol) {}
    void getmove(int &x, int &y) override {}
};


#endif // TICTACTOE5X5_H

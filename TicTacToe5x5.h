/**
 * @file TicTacToe5x5.h
 * @brief The backend file of 5x5 Tic Tac Toe
 */
#ifndef TICTACTOE5X5_H
#define TICTACTOE5X5_H

#include <QObject>
#include "BoardGame_Classes.h"
#include <set>
#include <QDebug>

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


    Q_INVOKABLE bool update_board(const int x, const int y, const QChar symbol) override {
        if (this->board[x][y] == ' ') {
            this->board[x][y] = symbol;
            this->n_moves++;
            return true;
        }
        qDebug() << board[x][y];
        return false;
    }


    void display_board() override {}


    bool is_win() override {
        set<string> sequences;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                const bool rowWin = this->board[i][j] != ' ' && this->board[i][j] == this->board[i][j + 1] &&
                    this->board[i][j + 1] == this->board[i][j + 2];

                const bool colWin = this->board[i][j] != ' ' && this->board[i][j] == this->board[i+1][j] &&
                    this->board[i+1][j] == this->board[i+2][j];

                const bool pDiagonalWin = this->board[i][j] != ' ' && this->board[i][j] == this->board[i + 1][j + 1]
                    && this->board[i + 1][j + 1] == this->board[i + 2][j + 2];

                const bool sDiagonalWin = this->board[i][j+ 2] != ' ' && this->board[i][j + 2] == this->board[i + 1][j + 1]
                    && this->board[i + 1][j + 1] == this->board[i + 2][j];

                string seq;
                if (rowWin) {
                    seq = to_string(i) + to_string(j) + to_string(i) + to_string(j + 1) + to_string(i) + to_string(j + 2);

                } else if (colWin) {
                    seq = to_string(i) + to_string(j) + to_string(i + 1) + to_string(j) + to_string(i + 2) + to_string(j);
                } else if (pDiagonalWin) {
                    seq = to_string(i) + to_string(j) + to_string(i + 1) + to_string(j + 1) + to_string(i + 2) + to_string(j + 2);
                } else if (sDiagonalWin) {
                    seq = to_string(i) + to_string(j + 2) + to_string(i + 1) + to_string(j + 1) + to_string(i + 2) + to_string(j);
                }

                if (sequences.insert(seq).second) {
                    // TODO: connect with frontend to do some sort of animation
                    return true;
                }
            }
        }
        return false;
    }


    bool is_draw() override { return game_is_over() && p1_nWins == p2_nWins; }


    bool game_is_over() override { return this->n_moves == 24; }
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

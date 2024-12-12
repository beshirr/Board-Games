/**
 * @file TicTacToe5x5.h
 * @brief The backend file of 5x5 Tic Tac Toe
 */
#ifndef TICTACTOE5X5_H
#define TICTACTOE5X5_H

#include <QGuiApplication>
#include <QObject>
#include "BoardGame_Classes.h"
#include <set>

class Board5x5 : public QObject,public Board<QChar> {
    Q_OBJECT
    Q_PROPERTY(QStringList f_board READ getFrontBoard NOTIFY frontBoardChanged)
private:
    int p1_nWins, p2_nWins;
    QStringList f_board; // Representation of the game board for the frontend

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
        updateFrontBoard();
    }

    Q_INVOKABLE bool update_board(const int x, const int y, const QChar symbol) override {
        if (this->board[x][y] == ' ') {
            this->board[x][y] = symbol;
            this->n_moves++;
            qDebug() << board[x][y];
            return true;
        }
        return false;
    }

    Q_INVOKABLE void reset_Board() {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = ' ';
            }
        }
        this->n_moves = 0;
        this->p1_nWins = this->p2_nWins = 0;
        updateFrontBoard();
    }

    Q_INVOKABLE void reset_game() {
        reset_Board();
    }

    Q_INVOKABLE void play_again() {
        reset_Board();
    }

    QStringList getFrontBoard() const { return f_board; }

    void updateFrontBoard() {
        f_board.clear();
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                f_board.append(QString(this->board[i][j]));
            }
        }
        qDebug() << f_board[0];
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
                    emit sequenceWon();
                    return true;
                }
            }
        }
        return false;
    }

    bool is_draw() override { return  this->n_moves == 24 && p1_nWins == p2_nWins; }

    bool game_is_over() override { return this->n_moves == 24 || (p1_nWins > 4 || p2_nWins > 4); }

signals:
    void frontBoardChanged();
    void sequenceWon();
    void gameWon(const QString& name);
    void gameDrown();
};


class Player5x5 : public QObject, public Player<QChar> {
    Q_OBJECT
    Q_PROPERTY(QString playerName READ getPlayerName)
public:
    explicit Player5x5(QObject* parent = nullptr): Player<QChar>("player", 'X') {
    }

    void getmove(int &x, int &y) override {}
    Q_INVOKABLE void setPlayerData(const string& playerName, const QChar& playerSymbol) {
        this->name = playerName;
        this->symbol = playerSymbol;
    }
    Q_INVOKABLE QString getPlayerName() { return Name; }
    QString getSymbol() const { return this->symbol; }
    QString Name = "TEST";
};


class RandomPlayer5x5 : public QObject, public RandomPlayer<QChar> {
    Q_OBJECT
public:
    explicit RandomPlayer5x5(QObject* parent, const QChar symbol) :  QObject(parent), RandomPlayer(symbol) {}
    void getmove(int &x, int &y) override {}
};


#endif // TICTACTOE5X5_H

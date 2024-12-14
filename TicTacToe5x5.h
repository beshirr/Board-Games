/**
 * @file TicTacToe5x5.h
 * @brief The backend file of 5x5 Tic Tac Toe
 */
#ifndef TICTACTOE5X5_H
#define TICTACTOE5X5_H

#include <QGuiApplication>
#include <QObject>
#include <set>
#include "BoardGame_Classes.h"

class Board5x5 : public QObject,public Board<QChar> {
    Q_OBJECT
    Q_PROPERTY(QStringList f_board READ getFrontBoard NOTIFY frontBoardChanged)
    Q_PROPERTY(int player1Wins READ getN_player1_wins WRITE setN_player1_wins NOTIFY n_player1_winsChanged)
    Q_PROPERTY(int player2Wins READ getN_player2_wins WRITE setN_player2_wins NOTIFY n_player2_winsChanged)

private:
    QStringList f_board; // Representation of the game board for the frontend
    set<string> sequences;
    int player1Wins, player2Wins;

public:
    // Override methods
    explicit Board5x5(QObject* parent = nullptr);
    Q_INVOKABLE bool update_board(const int x, const int y, const QChar symbol) override;
    Q_INVOKABLE bool is_win() override;
    void display_board() override {}
    Q_INVOKABLE bool is_draw() override;
    Q_INVOKABLE bool game_is_over() override;


    Q_INVOKABLE void reset_Board();
    Q_INVOKABLE void reset_game();
    void play_again();
    Q_INVOKABLE int gameWinner() const;
    int getN_player1_wins() const { return player1Wins; }
    int getN_player2_wins() const { return player2Wins; }
    void setN_player1_wins(const int value) {
        player1Wins = value;
        emit n_player1_winsChanged();
    }
    void setN_player2_wins(const int value) {
        player2Wins = value;
        emit n_player1_winsChanged();
    }

    QStringList getFrontBoard() const;
    void updateFrontBoard();


signals:
    void frontBoardChanged();
    void sequenceWon();
    void gameWon(int winner);
    void gameDrown();
    void n_player1_winsChanged();
    void n_player2_winsChanged();
};


class Player5x5 : public QObject, public Player<QString> {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString symbol READ getSymbol WRITE setSymbol NOTIFY symbolChanged)
    Q_PROPERTY(int nWins READ getNWins WRITE setNWins NOTIFY nWinsChanged)

public:
    explicit Player5x5(QObject* parent = nullptr);
    void getmove(int &x, int &y) override {}
    QString getName() const;
    void setName(const QString& newName);
    QString getSymbol() const;
    void setSymbol(const QString &newSymbol);
    int getNWins() const;
    void setNWins(int newNWins);

signals:
    void nameChanged();
    void symbolChanged();
    void nWinsChanged();

public:
    int nWins;
};


class RandomPlayer5x5 : public QObject, public RandomPlayer<QString> {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString symbol READ getSymbol WRITE setSymbol NOTIFY symbolChanged)

public:
    explicit RandomPlayer5x5(QObject* parent = nullptr);
    void getmove(int &x, int &y) override;
    Q_INVOKABLE QList<int> wrapper();
    QString getName() const;
    void setName(const QString& newName);
    QString getSymbol() const;
    void setSymbol(const QString& newSymbol);

signals:
    void nameChanged();
    void symbolChanged();

public:
    int nWins;
};


#endif // TICTACTOE5X5_H

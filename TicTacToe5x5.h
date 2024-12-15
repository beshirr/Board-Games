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

class Board5x5 : public QObject, public Board<QChar> {
    Q_OBJECT
    Q_PROPERTY(QStringList f_board READ getFrontBoard NOTIFY frontBoardChanged)
    Q_PROPERTY(int player1Wins READ getPlayer1Wins WRITE setPlayer1Wins NOTIFY player1WinsChanged)
    Q_PROPERTY(int player2Wins READ getPlayer2Wins WRITE setPlayer2Wins NOTIFY player2WinsChanged)

private:
    QStringList f_board; // Representation of the game board for the frontend
    set<string> sequences;
public:
    int player1Wins, player2Wins;

public:
    // Override methods
    explicit Board5x5(QObject* parent = nullptr);
    ~Board5x5() override;
    Q_INVOKABLE bool update_board(int x, int y, QChar symbol) override;
    Q_INVOKABLE bool is_win() override;
    void display_board() override {}
    Q_INVOKABLE bool is_draw() override;
    Q_INVOKABLE bool game_is_over() override;

    bool checkWinCondition(int x, int y, int dx, int dy, QChar symbol) const;

    int getPlayer1Wins() const { return player1Wins; }
    int getPlayer2Wins() const { return player2Wins; }
    void setPlayer1Wins(int value) { player1Wins = value; }
    void setPlayer2Wins(int value) { player2Wins = value; }

    QStringList getFrontBoard() const;
    void updateFrontBoard();
    Q_INVOKABLE void reset_Board();

signals:
    void frontBoardChanged();
    void sequenceWon();
    void gameWon();
    void gameDrown();
    void boardReset();
    void player1WinsChanged();
    void player2WinsChanged();
};


class Player5x5 : public QObject, public Player<QString> {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString symbol READ getSymbol WRITE setSymbol NOTIFY symbolChanged)

public:
    explicit Player5x5(QObject* parent = nullptr);
    void getmove(int &x, int &y) override {}

    QString getName() const;
    void setName(const QString& newName);
    QString getSymbol() const;
    void setSymbol(const QString &newSymbol);

signals:
    void nameChanged();
    void symbolChanged();
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
};


#endif // TICTACTOE5X5_H

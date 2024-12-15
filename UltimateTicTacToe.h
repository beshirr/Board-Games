#ifndef BOARDGAME_ULTIMATETICTACTOE_H
#define BOARDGAME_ULTIMATETICTACTOE_H


#include <QObject>
#include "BoardGame_Classes.h"
#include <QString>
#include <set>

using namespace std;

class UltimateBoard: public QObject, Board<QString> {
    Q_OBJECT
    Q_PROPERTY(QStringList f_board READ getFrontBoard WRITE setFrontBoard NOTIFY frontBoardChanged)

private:
    QStringList f_board;
    int currentBoard;
    QString*** boards;
    QString miniBoard[3][3];
    int playerTurn;


public:
    explicit UltimateBoard(QObject *parent);
    ~UltimateBoard();
    Q_INVOKABLE bool update_board(int x, int y, QString symbol) override;
    Q_INVOKABLE void update_mini_board(int i, QString symbol);
    void display_board() override;
    Q_INVOKABLE bool is_mini_win();
    Q_INVOKABLE bool is_win() override;
    bool is_draw() override;
    Q_INVOKABLE bool game_is_over() override;
    Q_INVOKABLE void updateFrontBoard();
    QStringList getFrontBoard();

signals:
    void frontBoardChanged();
};

class UltimatePlayer: public QObject, Player<QString> {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString symbol READ getSymbol WRITE setSymbol NOTIFY symbolChanged)

public:
    explicit UltimatePlayer(QObject* parent);
    void getmove(int &x, int &y) override;
    QString getName() const;
    void setName(const QString& newName);
    QString getSymbol() const;
    void setSymbol(const QString& newSymbol);

signals:
    void nameChanged();
    void symbolChanged();
};


#endif //BOARDGAME_ULTIMATETICTACTOE_H

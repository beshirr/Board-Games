#ifndef WORDTICTACTOE_H
#define WORDTICTACTOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <QObject>
#include <list>


class WordBoard: public QObject, Board<QString>{
    Q_OBJECT
    Q_PROPERTY(QStringList f_board READ getFrontBoard WRITE setFrontBoard NOTIFY frontBoardChanged)

private:
    string WordsFile;
    bool is_word(const QString& word);
    QStringList f_board;

public:
    explicit WordBoard(QObject* parent);
    ~WordBoard();
    Q_INVOKABLE bool update_board(int x, int y, QString symbol) override;
    void display_board() override;
    Q_INVOKABLE bool is_win() override;
    bool is_draw() override;
    Q_INVOKABLE bool game_is_over() override;
    Q_INVOKABLE void updateFrontBoard();
    QStringList getFrontBoard();

signals:
    void frontBoardChanged();
};

class WordPlayer: public QObject, Player<QString>{
public:
    explicit WordPlayer(QObject* parent);
    WordPlayer(const QString& playerName, QString playerSymbol);
    void getmove(int& x, int& y) override;
    QString getName() const;
    Q_INVOKABLE void setName(const QString& newName);
    QString getSymbol() const;
    Q_INVOKABLE void setSymbol(const QString& newSymbol);

signals:
    void nameChanged();
    void symbolChanged();
};


#endif //WORDTICTACTOE_H

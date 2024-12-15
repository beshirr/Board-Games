#ifndef PYRAMIDTICTACTOE_H
#define PYRAMIDTICTACTOE_H
#include "BoardGame_Classes.h"
#include <iostream>
#include <QString>
#include <QObject>
#include <set>
#include <QGuiApplication>

class PyramidBoard : public QObject, Board<QString>{
    Q_OBJECT
    Q_PROPERTY(QStringList f_board READ getFrontBoard NOTIFY frontBoardChanged)

private:
    QStringList f_board;

public:
    explicit PyramidBoard(QObject *parent = nullptr);
    ~PyramidBoard() override;
    Q_INVOKABLE bool update_board(int x, int y, QString symbol) override;
    void display_board() override;
    Q_INVOKABLE bool is_win() override;
    bool is_draw() override;
    Q_INVOKABLE bool game_is_over() override;
    QStringList getFrontBoard();
    void updateFrontBoard();

signals:
    void frontBoardChanged();
};

class PyramidPlayer: public QObject, Player<QString>{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString symbol READ getSymbol WRITE setSymbol NOTIFY symbolChanged)

private:
    QString name;
    QString symbol;

public:
    explicit PyramidPlayer(QObject *parent = nullptr);
    void getmove(int& x, int& y) override;
    QString getName() const;
    Q_INVOKABLE void setName(const QString& newName);
    QString getSymbol() const;
    Q_INVOKABLE void setSymbol(const QString &newSymbol);

signals:
    void nameChanged();
    void symbolChanged();
};




#endif //PYRAMIDTICTACTOE_H
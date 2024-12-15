#ifndef MISERE_H
#define MISERE_H

#include <QGuiApplication>
#include <QObject>
#include "BoardGame_Classes.h"


class MisereBoard : public QObject, public Board<QChar> {
    Q_OBJECT
    Q_PROPERTY(QStringList f_board READ getFrontBoard NOTIFY frontBoardChanged)

private:
    QStringList f_board;

public:
    explicit MisereBoard(QObject* parent = nullptr);
    ~MisereBoard() override;

    Q_INVOKABLE bool update_board(int x, int y, QChar symbol) override;
    Q_INVOKABLE bool is_win() override;
    void display_board() override {}
    Q_INVOKABLE bool is_draw() override;
    Q_INVOKABLE bool game_is_over() override;

    QStringList getFrontBoard() const;
    void updateFrontBoard();
    Q_INVOKABLE void reset_Board();

signals:
    void frontBoardChanged();
    void gameWon();
    void gameDrown();
    void gameOver();
    void boardReset();
};


class MiserePlayer : public QObject, public Player<QString> {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString symbol READ getSymbol WRITE setSymbol NOTIFY symbolChanged)

public:
    explicit MiserePlayer(QObject* parent = nullptr);
    void getmove(int &x, int &y) override {}

    QString getName() const;
    void setName(const QString& newName);
    QString getSymbol() const;
    void setSymbol(const QString &newSymbol);

signals:
    void nameChanged();
    void symbolChanged();
};


class MisereRandomPlayer : public QObject, public RandomPlayer<QString> {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString symbol READ getSymbol WRITE setSymbol NOTIFY symbolChanged)

public:
    explicit MisereRandomPlayer(QObject* parent = nullptr);
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


#endif //MISERE_H

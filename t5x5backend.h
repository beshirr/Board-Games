#ifndef T5X5BACKEND_H
#define T5X5BACKEND_H

#include <QObject>
#include "TicTacToe5x5.h"

class T5x5Backend : public QObject
{
    Q_OBJECT
public:
    explicit T5x5Backend(QObject *parent = nullptr);
public:
    int player2Type;

public:
    void Main() const;
    void changePlayerType();
signals:
public slots:

};

#endif // T5X5BACKEND_H

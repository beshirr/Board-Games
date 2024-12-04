#ifndef T5X5BACKEND_H
#define T5X5BACKEND_H

#include <QObject>
#include "TicTacToe5x5.h"

class T5x5Backend : public QObject
{
    Q_OBJECT
public:
    explicit T5x5Backend(QObject *parent = nullptr);

signals:
    void sg_boardCellClicked(int row, int col, QString player);
public slots:
    void sl_boardCellClicked(int row, int col, QString player);
};

#endif // T5X5BACKEND_H

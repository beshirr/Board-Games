#include "Misere.h"
#include <QDebug>

MisereBoard::MisereBoard(QObject* parent) : QObject(parent) {
    this->rows = this->columns = 3;
    this->board = new QChar*[3];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new QChar[3];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }

    this->n_moves = 0;
    updateFrontBoard();
}


MisereBoard::~MisereBoard() {
    for (int i = 0; i < rows; ++i) {
        delete[] board[i];
    }
    delete[] board;
}


bool MisereBoard::update_board(int x, int y, QChar symbol) {
    if (this->board[x][y] == ' ') {
        this->board[x][y] = symbol;
        this->n_moves++;
        qDebug() << this->n_moves;
        updateFrontBoard();
        return true;
    }
    return false;
}


bool MisereBoard::is_win() {
    // winning is losing
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != ' ') ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != ' ')) {
            emit gameWon();
            return true;
        }
    }

    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != ' ') ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != ' ')) {
        emit gameWon();
        return true;
    }

    return false;
}


bool MisereBoard::is_draw() { return this->n_moves == 9 && !is_win(); }


bool MisereBoard::game_is_over() { return is_win() || is_draw(); }


QStringList MisereBoard::getFrontBoard() const { return f_board; }


void MisereBoard::updateFrontBoard() {
    f_board.clear();
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            f_board.append(QString(this->board[i][j]));
        }
    }
    emit frontBoardChanged();
}


void MisereBoard::reset_Board() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            this->board[i][j] = ' ';
        }
    }
    updateFrontBoard();
    n_moves = 0;
    emit boardReset();
}



MiserePlayer::MiserePlayer(QObject* parent) : QObject(parent), Player<QString>("Play", "P") {}


QString MiserePlayer::getName() const { return QString::fromStdString(name); }


void MiserePlayer::setName(const QString& newName) {
    name = newName.toStdString();
    emit nameChanged();
}


QString MiserePlayer::getSymbol() const { return symbol; }


void MiserePlayer::setSymbol(const QString &newSymbol) {
    symbol = newSymbol;
    emit symbolChanged();
}


MisereRandomPlayer::MisereRandomPlayer(QObject* parent) : QObject(parent), RandomPlayer("symbol") {
    this->dimension = 3;
    srand(static_cast<unsigned int>(time(nullptr)));
}


void MisereRandomPlayer::getmove(int &x, int &y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}


QList<int> MisereRandomPlayer::wrapper() {
    int x = 0, y = 0;
    getmove(x, y);
    return QList<int>{x, y};
}


QString MisereRandomPlayer::getName() const { return QString::fromStdString(name); }


void MisereRandomPlayer::setName(const QString& newName) {
    name = newName.toStdString();
    emit nameChanged();
}


QString MisereRandomPlayer::getSymbol() const { return symbol; }

void MisereRandomPlayer::setSymbol(const QString& newSymbol) {
    symbol = newSymbol;
    emit symbolChanged();
}


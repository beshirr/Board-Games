#include "PyramidTicTacToe.h"
#include <QObject>



PyramidBoard::PyramidBoard(QObject* parent): QObject(parent){
    rows = 3;
    columns = 5;
    board = new QString* [rows];
    for(int i = 0; i < rows; i++) {
        board[i] = new QString[columns];
        for(int j = 0; j < columns; j++) {
            board[i][j] = "-";
        }
    }
    board[0][0] = board[0][1] = board[0][3] = board[0][4] = board[1][0] = board[1][4] = " ";
}

PyramidBoard::~PyramidBoard() {
    for(int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool PyramidBoard::update_board(int x, int y, QString symbol) {
    if (x < 0 || y < 0 || x >= rows || y >= columns || board[x][y] != "-")return false;
    else {
        board[x][y] = symbol;
        n_moves++;
        return true;
    }
}

void PyramidBoard::display_board() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << board[i][j].toStdString() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool PyramidBoard::is_win() {
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < columns-2; ++j) {
            if((board[i][j] == board[i][j+1]) && (board[i][j] == board[i][j+2]) && (board[i][j] != "-"))return true;
            if ((j == 2) && (i == 1)){
                if((board[i][j] == board[i+1][j]) && (board[i][j] == board[i-1][j]) && (board[i][j]!= "-")) return true;
            }
        }
    }
    if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && (board[0][2] != "-")) return true;
    else if ((board[0][2] == board[1][3]) && (board[0][2] == board[2][4]) && (board[0][2] != "-")) return true;

    return false;
}

bool PyramidBoard::is_draw() {
    if (n_moves == 9) return true;
    return false;
}

bool PyramidBoard::game_is_over() {
    return is_win() || is_draw();
}

void PyramidBoard::updateFrontBoard(int x, int y, QString symbol) {
    f_board.clear();
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            f_board.append(QString(this->board[i][j]));
        }
    }
    emit frontBoardChanged();
}

QStringList PyramidBoard::getFrontBoard(){return f_board;};

void PyramidPlayer::getmove(int &x, int &y) {
    cout << name.toStdString() << ", enter your move (x y): ";
    cin >> x >> y;
    x--;
    y--;
}


PyramidPlayer::PyramidPlayer(QObject* parent) : QObject(parent), Player<QString>("Player", "P"){}


QString PyramidPlayer::getName() const { return name;}

void PyramidPlayer::setName(const QString& newName) {
    name = newName;
    emit nameChanged();
}

QString PyramidPlayer::getSymbol() const { return symbol;}

void PyramidPlayer::setSymbol(const QString& newSymbol) {
    symbol = newSymbol;
    emit symbolChanged();
}
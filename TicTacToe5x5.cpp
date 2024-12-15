#include "TicTacToe5x5.h"


Board5x5::Board5x5(QObject* parent) : QObject(parent) {
    this->rows = this->columns = 5;
    this->board = new QChar*[5];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new QChar[5];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }

    this->n_moves = 0;
    player1Wins = player2Wins = 0;
    updateFrontBoard();
}


Board5x5::~Board5x5() {
    for (int i = 0; i < rows; ++i) {
        delete[] board[i];
    }
    delete[] board;
}


bool Board5x5::update_board(const int x, const int y, const QChar symbol) {
    if (this->board[x][y] == ' ') {
        this->board[x][y] = symbol;
        this->n_moves++;
        updateFrontBoard();
        return true;
    }
    return false;
}


bool Board5x5::checkWinCondition(int x, int y, int dx, int dy, QChar symbol) const {
    for (int i = 1; i < 3; ++i) {
        int nx = x + i * dx, ny = y + i * dy;
        if (nx < 0 || ny < 0 || nx >= rows || ny >= columns || board[nx][ny] != symbol) {
            return false;
        }
    }
    return true;
}

// bool Board5x5::is_win() {
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < columns; ++j) {
//             if (board[i][j] != ' ') {
//                 QChar symbol = board[i][j];
//                 if (checkWinCondition(i, j, 1, 0, symbol) ||
//                     checkWinCondition(i, j, 0, 1, symbol) ||
//                     checkWinCondition(i, j, 1, 1, symbol) ||
//                     checkWinCondition(i, j, 1, -1, symbol)) {
//                     emit sequenceWon();
//                     return true;
//                     }
//             }
//         }
//     }
//     return false;
// }

// bool Board5x5::is_win() {
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < columns; ++j) {
//             if (board[i][j] != ' ') {
//                 QChar symbol = board[i][j];
//
//                 // Check horizontal, only if j is the start of a possible sequence
//                 if (j <= columns - 3 && checkWinCondition(i, j, 0, 1, symbol)) {
//                     emit sequenceWon();
//                     return true;
//                 }
//
//                 // Check vertical, only if i is the start of a possible sequence
//                 if (i <= rows - 3 && checkWinCondition(i, j, 1, 0, symbol)) {
//                     emit sequenceWon();
//                     return true;
//                 }
//
//                 // Check diagonal (top-left to bottom-right), only if i and j are the start
//                 if (i <= rows - 3 && j <= columns - 3 && checkWinCondition(i, j, 1, 1, symbol)) {
//                     emit sequenceWon();
//                     return true;
//                 }
//
//                 // Check diagonal (top-right to bottom-left), only if i and j are the start
//                 if (i <= rows - 3 && j >= 2 && checkWinCondition(i, j, 1, -1, symbol)) {
//                     emit sequenceWon();
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }


bool Board5x5::is_win()  {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            const bool rowWin = this->board[i][j] != ' ' && this->board[i][j] == this->board[i][j + 1] &&
                                this->board[i][j + 1] == this->board[i][j + 2];
            const bool colWin = this->board[i][j] != ' ' && this->board[i][j] == this->board[i+1][j] &&
                                this->board[i+1][j] == this->board[i+2][j];
            const bool pDiagonalWin = this->board[i][j] != ' ' && this->board[i][j] == this->board[i + 1][j + 1]
                                      && this->board[i + 1][j + 1] == this->board[i + 2][j + 2];
            const bool sDiagonalWin = this->board[i][j+ 2] != ' ' && this->board[i][j + 2] == this->board[i + 1][j + 1]
                                      && this->board[i + 1][j + 1] == this->board[i + 2][j];
            string seq;
            if (rowWin) {
                seq = to_string(i) + to_string(j) + to_string(i) + to_string(j + 1) + to_string(i) + to_string(j + 2);
            } else if (colWin) {
                seq = to_string(i) + to_string(j) + to_string(i + 1) + to_string(j) + to_string(i + 2) + to_string(j);
            } else if (pDiagonalWin) {
                seq = to_string(i) + to_string(j) + to_string(i + 1) + to_string(j + 1) + to_string(i + 2) + to_string(j + 2);
            } else if (sDiagonalWin) {
                seq = to_string(i) + to_string(j + 2) + to_string(i + 1) + to_string(j + 1) + to_string(i + 2) + to_string(j);
            }
            if (sequences.insert(seq).second) {
                emit sequenceWon();
                return true;
            }
        }
    }
    return false;
}

bool Board5x5::is_draw() { return this->player1Wins == this->player2Wins; }


bool Board5x5::game_is_over() { return this->n_moves == 24; }


QStringList Board5x5::getFrontBoard() const { return f_board; }


void Board5x5::updateFrontBoard() {
    f_board.clear();
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            f_board.append(QString(this->board[i][j]));
        }
    }
    emit frontBoardChanged();
}


void Board5x5::reset_Board() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            this->board[i][j] = ' ';
        }
    }
    updateFrontBoard();
    player1Wins = 0;
    player2Wins = 0;
    n_moves = 0;
    emit boardReset();
}


Player5x5::Player5x5(QObject* parent) : QObject(parent), Player<QString>("Play", "P") {}


QString Player5x5::getName() const { return QString::fromStdString(name); }


void Player5x5::setName(const QString& newName) {
    name = newName.toStdString();
    emit nameChanged();
}


QString Player5x5::getSymbol() const { return symbol; }


void Player5x5::setSymbol(const QString &newSymbol) {
    symbol = newSymbol;
    emit symbolChanged();
}


RandomPlayer5x5::RandomPlayer5x5(QObject* parent) : QObject(parent), RandomPlayer("symbol") {
    this->dimension = 5;
    srand(static_cast<unsigned int>(time(nullptr)));
}


void RandomPlayer5x5::getmove(int &x, int &y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}


QList<int> RandomPlayer5x5::wrapper() {
    int x = 0, y = 0;
    getmove(x, y);
    return QList<int>{x, y};
}


QString RandomPlayer5x5::getName() const { return QString::fromStdString(name); }


void RandomPlayer5x5::setName(const QString& newName) {
    name = newName.toStdString();
    emit nameChanged();
}


QString RandomPlayer5x5::getSymbol() const { return symbol; }

void RandomPlayer5x5::setSymbol(const QString& newSymbol) {
    symbol = newSymbol;
    emit symbolChanged();
}

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
    updateFrontBoard();
}


bool Board5x5::update_board(const int x, const int y, const QChar symbol) {
    {
        if (this->board[x][y] == ' ') {
            this->board[x][y] = symbol;
            this->n_moves++;
            updateFrontBoard();
            return true;
        }
        return false;
    }
}


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


bool Board5x5::game_is_over() { return this->n_moves == 23; }


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
}


void Board5x5::reset_game() {}
void Board5x5::play_again() {}

int Board5x5::gameWinner() const {
    return (player1Wins > player2Wins)? 0 : 1;
}



Player5x5::Player5x5(QObject* parent) : QObject(parent), Player<QString>("Play", "P") {
    nWins = 0;
}


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


int Player5x5::getNWins() const { return nWins; }


void Player5x5::setNWins(const int newNWins) {
    nWins = newNWins;
    emit nWinsChanged();
}


RandomPlayer5x5::RandomPlayer5x5(QObject* parent) : QObject(parent), RandomPlayer("symbol") {
    this->dimension = 5;
    nWins = 5;
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

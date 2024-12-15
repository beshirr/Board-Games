#include "WordTicTacToe.h"

WordBoard::WordBoard(QObject *parent): QObject(parent){
    rows = 3;
    columns = 3;
    WordsFile = "dic.txt";
    board = new QString*[rows];
    for(int i = 0; i < rows; i++) {
        board[i] = new QString[columns];
        for(int j = 0; j < columns; j++) {
            board[i][j] = "-";
        }
    }
    updateFrontBoard();
}

WordBoard::~WordBoard(){
    for(int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool WordBoard::update_board(int x, int y, QString symbol) {
    if (x < 0 || y < 0 || x >= rows || y >= columns || board[x][y] != "-")return false;
    else {
        board[x][y] = symbol;
        n_moves++;
        return true;
    }
}

void WordBoard::display_board() {
    for(int i = 0; i < rows; i++) {
        cout << i+1 << " ";
        for(int j = 0; j < columns; j++) {
            cout << board[i][j].toStdString() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool WordBoard::is_word(const QString& word) {
    ifstream file(WordsFile);
    string line;
    while(getline(file, line)) {
        if(line == word) return true;
    }
    file.close();
    return false;
}

bool WordBoard::is_win() {
    for(int i = 0; i < rows; i++) {
        if (is_word(board[i][0] + board[i][1] + board[i][2])) return true;
    }
    for(int j = 0; j < columns; j++) {
        if (is_word(board[0][j] + board[1][j] + board[2][j])) return true;
    }
    if (is_word(board[0][0] + board[1][1] + board[2][2])) return true;
    if (is_word(board[0][2] + board[1][1] + board[2][0])) return true;
    return false;
}

bool WordBoard::is_draw() {
    if (n_moves == 9) return true;
    return false;
}

bool WordBoard::game_is_over() {
    return is_win() || is_draw();
}

void WordBoard::updateFrontBoard() {
    f_board.clear();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            f_board.append(board[i][j]);
        }
    }
}

QStringList WordBoard::getFrontBoard() {return f_board;}

WordPlayer::WordPlayer(QObject* parent) : QObject(parent), Player<QString>("player", "p"){}

QString WordPlayer::getName() const {return QString::fromStdString(name);}

void WordPlayer::setName(const QString& newName) {
    name = newName.toStdString();
    emit nameChanged();
}

QString WordPlayer::getSymbol() const { return symbol;}

void WordPlayer::setSymbol(const QString &newSymbol) {
    symbol = newSymbol;
    emit symbolChanged();
}

void WordPlayer::getmove(int &x, int &y) {
    cout << name << ", enter your move (x y): ";
    cin >> x >> y;
    x--;
    y--;
}
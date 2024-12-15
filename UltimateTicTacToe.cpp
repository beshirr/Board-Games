#include "UltimateTicTacToe.h"

UltimateBoard::UltimateBoard() {
    rows = 3;
    columns = 3;
    currentBoard = 4;
    playerTurn = 1;
    boards = new string**[9];
    for (int i = 0; i < 9; i++) {
        boards[i] = new string *[rows];
        for (int j = 0; j < rows; j++) {
            boards[i][j] = new string[columns];
            for (int k = 0; k < columns; k++) {
                boards[i][j][k] = "-";
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            miniBoard[i][j] = "-";
        }
    }
}

UltimateBoard::~UltimateBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < rows; j++) {
            delete[] boards[i][j];
        }
        delete[] boards[i];
    }
    delete[] boards;
}

bool UltimateBoard::update_board(int x, int y, string symbol) {
    if (x < 0 || y < 0 || x > 9 || y > 9) return false;
    int i, j, k;
    if ((x < 3) && (y < 3)){
        i = 0;
        j = x;
        k = y;
    }
    else if ((x >= 3) && (x < 6) && (y < 3)){
        i = 3;
        j = x - 3;
        k = y;
    }
    else if ((x >= 6) && (y < 3)){
        i = 6;
        j = x - 6;
        k = y;
    }
    else if ((x < 3) && (y >= 3) && (y < 6)){
        i = 1;
        j = x;
        k = y - 3;
    }
    else if ((x >= 3) && (x < 6) && (y >= 3) && (y < 6)){
        i = 4;
        j = x - 3;
        k = y - 3;
    }
    else if ((x >= 6) && (y >= 3) && (y < 6)){
        i = 7;
        j = x - 6;
        k = y - 3;
    }
    else if ((x < 3) && (y >= 6)){
        i = 2;
        j = x;
        k = y - 6;
    }
    else if ((x >= 3) && (x < 6) && (y >= 6)){
        i = 5;
        j = x - 3;
        k = y - 6;
    }
    else if ((x >= 6) && (y >= 6)){
        i = 8;
        j = x - 6;
        k = y - 6;
    }
    if (boards[i][j][k] != "-" || currentBoard != i) return false;
    else {
        boards[i][j][k] = symbol;
        if (j == 0){currentBoard = k;}
        else if (j == 2){currentBoard = k+6;}
        else if (j == 1 && k == 0){currentBoard = 3;}
        else if (j == 1 && k == 2){currentBoard = 4;}
        playerTurn = playerTurn == 1? 2 : 1;
        n_moves++;
        return true;
    }
}

void UltimateBoard::update_mini_board(int i, string symbol) {
    if (i < 3){
        miniBoard[0][i] = symbol;
    }
    else if (i >= 3 && i < 6){
        miniBoard[1][i - 3] = symbol;
    }
    else{
        miniBoard[2][i - 6] = symbol;
    }
}

void UltimateBoard::display_board() {
    int helper = 0;
    for (int i = 0; i < 9; i+=3) {
        for (int j = 0; j < 3; j++) {
            while (helper != 3){
                for (int k = 0; k < 3; ++k) {
                    cout << " " << boards[helper+i][j][k] << " ";
                }
                cout << "   ";
                helper++;
            }
            cout << "\n";
            helper = 0;
        }
        cout << "\n";
    }
}

bool UltimateBoard::is_mini_win() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            bool r_win = boards[i][j][0]!= "-" && boards[i][j][0] == boards[i][j][1] &&
                         boards[i][j][1] == boards[i][j][2];

            bool c_win = boards[i][0][j]!= "-" && boards[i][0][j] == boards[i][1][j] &&
                         boards[i][0][j] == boards[i][2][j];

            if (r_win || c_win) {
                update_mini_board(currentBoard, playerTurn == 2? "X" : "O");
                return true;
            }
        }
        if (boards[i][0][0] != "-" && boards[i][0][0] == boards[i][1][1] && boards[i][0][0] == boards[i][2][2]) {
            update_mini_board(currentBoard, playerTurn == 2? "X" : "O");
            return true;
        }
        if (boards[i][0][2]!= "-" && boards[i][0][2] == boards[i][1][1] && boards[i][0][2] == boards[i][2][0]) {
            update_mini_board(currentBoard, playerTurn == 2? "X" : "O");
            return true;
        }
    }
    return false;
}

bool UltimateBoard::is_win() {
    is_mini_win();
    for (int i = 0; i < 3; ++i) {
        bool r_win = miniBoard[i][0] != "-" && miniBoard[i][0] == miniBoard[i][1] && miniBoard[i][0] == miniBoard[i][2];
        bool c_win = miniBoard[0][i] != "-" && miniBoard[0][i] == miniBoard[1][i] && miniBoard[0][i] == miniBoard[2][i];
        if (r_win || c_win) return true;
    }
    if (miniBoard[0][0]!= "-" && miniBoard[0][0] == miniBoard[1][1] && miniBoard[0][0] == miniBoard[2][2]) return true;
    if (miniBoard[0][2]!= "-" && miniBoard[0][2] == miniBoard[1][1] && miniBoard[0][2] == miniBoard[2][0]) return true;
    return false;
}

bool UltimateBoard::is_draw() {
    if (n_moves >= 81) return true;
    return false;
}

bool UltimateBoard::game_is_over() {
    if (is_win() || is_draw()) return true;
    return false;
}



UltimatePlayer::UltimatePlayer(string name, string symbol) : Player<string>(name, symbol){}
void UltimatePlayer::getmove(int &x, int &y) {
    cout << name << ", enter your move (x y): ";
    cin >> x >> y;
    x--;
    y--;
}

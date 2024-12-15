#pragma once

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // For srand and rand 
#include <ctime>   // For time  


using namespace std;
template<typename T>

class xo4_board :public Board<char> {
    xo4_board() {
        this->rows = 4;
        this->columns = 4;
        this->board = new char* [this->rows]; 

        for (int i = 0; i < this->rows; i++) { 
            this->board[i] = new char[4];
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = ' ';
            }
        }
        this->n_moves = 0;
    }
    void display_board() {
        for (int i = 0; i < this->rows; i++) {
            cout << "\n| ";
            for (int j = 0; j < this->columns; j++) {
                cout << setw(2) << this->board[i][j] << " | ";
            }
            cout << "\n-----------------------------------";
        } 
    }
};


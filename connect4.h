#pragma once

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // For srand and rand 
#include <ctime>   // For time  

using namespace std;
template <typename T>
class connect_4_board :public Board<T> {  
public:
    connect_4_board() {
        this->rows = 6;
        this->columns = 7;
        this->board = new char* [this->rows]; 

        for (int i = 0; i < this->rows; i++) { 
            this->board[i] = new char[7]; 
            for (int j = 0; j < this->columns; j++) { 
                this->board[i][j] = ' ';
            }
        }
        this->n_moves = 0;
    }
   
   
    void display_board() {
        for (int i = 0; i < 6; i++) { 
            for (int j = 0; j < 7; j++) {
                cout << "| " << this->board[i][j] << " ";   
            }
            cout << "|" << endl;
        }
        for (int j = 0; j < 7; j++) {
            cout << "--- ";
        }
        cout << endl;
        for (int j = 0; j < 7; j++) {
            cout << "  " << j  << " ";
        }
        cout << endl;
    }

    
    bool is_win() {

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j <= 3; j++) {
                if (this->board[i][j] == 'X' &&
                    this->board[i][j + 1] == 'X' &&
                    this->board[i][j + 2] == 'X' &&
                    this->board[i][j + 3] == 'X') {
                    return true; // Horizontal win
                }
                if (this->board[i][j] == 'O' &&
                    this->board[i][j + 1] == 'O' && 
                    this->board[i][j + 2] == 'O' && 
                    this->board[i][j + 3] == 'O') { 
                    return true; // Horizontal win
                }

            }

        }
        for (int j = 0; j < 7; j++) {
            for (int i = 0; i <= 2; i++) { 
                if (this->board[i][j] == 'X' &&
                    this->board[i + 1][j] == 'X' &&
                    this->board[i + 2][j] == 'X' && 
                    this->board[i + 3][j] == 'X') {
                    return true; // Vertical win
                }
                if (this->board[i][j] == 'O' &&
                    this->board[i + 1][j] == 'O' &&
                    this->board[i + 2][j] == 'O' &&
                    this->board[i + 3][j] == 'O') {
                    return true; // Vertical win
                }
            }
        }

        // Check for diagonal wins (top-left to bottom-right)
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 3; j++) {
                if (this->board[i][j] == 'X' &&
                    this->board[i + 1][j + 1] == 'X' &&
                    this->board[i + 2][j + 2] == 'X' &&
                    this->board[i + 3][j + 3] == 'X') {
                    return true; // Diagonal win \
                                                        
                }
                if (this->board[i][j] == 'O' &&
                    this->board[i + 1][j + 1] == 'O' &&
                    this->board[i + 2][j + 2] == 'O' &&
                    this->board[i + 3][j + 3] == 'O') {
                    return true; // Diagonal win \
                                                                            
                }
            }
        }

        for (int i = 3; i < 6; i++) {
            for (int j = 0; j <= 3; j++) {
                if (this->board[i][j] == 'X' &&
                    this->board[i - 1][j + 1] == 'X' &&
                    this->board[i - 2][j + 2] == 'X' &&
                    this->board[i - 3][j + 3] == 'X') {
                    return true; // Diagonal win /
                }
                if (this->board[i][j] == 'O' &&
                    this->board[i - 1][j + 1] == 'O' &&
                    this->board[i - 2][j + 2] == 'O' &&
                    this->board[i - 3][j + 3] == 'O') {
                    return true; // Diagonal win /
                }
            }
        }
        return false;
    }

    bool is_draw() {

        return 0;

    }

    bool game_is_over() {

        return is_win();
    }

    bool update_board(int x, int y, T symbol){      
        
        if (y < 0 || y >= 7) { 

            return false;

        }
        for (int i = 5; i >= 0; i--) {

            if (this->board[i][y] == ' ') {
                this->board[i][y] = toupper(symbol);  
                return true;
            }
        }
        cout << "the column is full enter anoter column " << endl;

        return false;
    }

};

template <typename  T >
class connect_4_player :public Player<T> {
public:
    connect_4_player(string name, T symbol) : Player<T>(name, symbol){}

    void getmove(int& x, int& y ){
        cout << "enter the column you want to play at (0 : 6) -> " << endl;
        cin >> y; 
    }

};

template <typename T> 
class connect_4_random_player : public RandomPlayer<T> { 
public:
    connect_4_random_player(T symbol) : RandomPlayer<T>(symbol) {
        this->dimension = 7; 
        this->name = "Random Computer Player"; 
        srand(static_cast<unsigned int>(time(0))); 
    }

    
    void getmove(int& x , int& y) { 
        y = rand() % this->dimension;  
    }
    
};





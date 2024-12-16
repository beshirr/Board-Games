#pragma once

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // For srand and rand 
#include <ctime>   // For time  
#include <cmath>


using namespace std;

template<typename T>
class xo4_board :public Board<T> { 
public:
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




        this->board[0][0] = 'O'; 
        this->board[0][1] = 'X';
        this->board[0][2] = 'O';
        this->board[0][3] = 'X';
        this->board[3][0] = 'X';
        this->board[3][1] = 'O';
        this->board[3][2] = 'X';
        this->board[3][3] = 'O';
        this->n_moves = 8; // Total of 8 tokens placed





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
    bool is_win() {

        // rows
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                if (this->board[i][j] != ' ' && this->board[i][j] == this->board[i][j + 1] && this->board[i][j] == this->board[i][j + 2])
                    return true; 
            }
        }
        // columns
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                if (this->board[i][j] != ' ' && this->board[i][j] == this->board[i + 1][j] && this->board[i][j] == this->board[i + 2][j])
                    return true;
            }
        }
        //diagonals
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (this->board[i][j] != ' ' && this->board[i][j] == this->board[i + 1][j + 1] && this->board[i][j] == this->board[i + 2][j + 2])
                    return true;
                if (this->board[i][j + 2] != ' ' && this->board[i][j + 2] == this->board[i + 1][j + 1] && this->board[i][j + 2] == this->board[i + 2][j])
                    return true;
            }
        }

        return false;

    }

    bool is_draw() {

        return (this->n_moves == 16 && !is_win()); 
    }

    bool game_is_over() {

        return is_win();
    }
    bool update_board(int x, int y, T symbol) {

        this->board[x][y] = toupper(symbol);

        return true;
    }
};


template<typename T>
class xo4_player : public Player<T> {
protected:
public:

    xo4_player(string name, T symbol, xo4_board<char>* board) : Player<T>(name, symbol) {
        this->boardPtr = board; 
    }

    void getmove(int& x, int& y) {


        int old_x = 0; int old_y = 0;

        cout<<"\n" << this->name << " (" << this->symbol << ") - Enter the token to move (old_x old_y)"<<endl;

        cout << "oldx -> ";
        cin >> old_x;
        cout << "oldy-> ";
        cin >> old_y;

        while ( (old_x > 3 || old_x < 0) || (old_y > 3 || old_y < 0) || (this->boardPtr->board[old_x][old_y] != this->symbol)) { 
            cout << "invalid index, enter another x , y  "; 
            int old_x = 0; int old_y = 0; 
            cout << "old_x -> ";
            cin >> old_x;
            cout << "old_y -> ";
            cin >> old_y;


        }

        int new_x = 0;  int new_y = 0; 

        cout << "Enter new position (new_x new_y) -> "; 
        cout << "new_x -> ";
        cin >> new_x;
        cout << "new_y -> ";
        cin >> new_y;

        while ( !((abs(new_x - old_x) == 1 && new_y == old_y) || (abs(new_y - old_y) == 1 && new_x == old_x)) || (new_x > 3 || new_x < 0 ) || (new_y > 3 || new_y < 0) ) {

            cout << "invalid index, enter another new x , y ";

            cout << "new_x -> "; 
            cin >> new_x; 
            cout << "new_y -> "; 
            cin >> new_y; 

        }

        //this->b[x][y] = ' ';


        this->boardPtr->board[old_x][old_y] = ' ';  

        y = new_y;  
        x = new_x; 







    }


};


template <typename T>
class xo4_random_player : public RandomPlayer<T> {
public:
    xo4_random_player(T symbol) : RandomPlayer<T>(symbol) { 
        this->dimension = 4;
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0)));
    }


    void getmove(int& x, int& y) {
        y = rand() % this->dimension; 
        x = rand() % this->dimension;  
    }

};


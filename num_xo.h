#pragma once

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // For srand and rand 
#include <ctime>   // For time  
#include <vector>
#include <algorithm>
#include <set> 

int element; 
using namespace std;
template <typename T>
class num_xo_board :public Board<T> {
private:
    set<int> used_numbers; 
public:
    num_xo_board() { 
        this->rows = 3;
        this->columns = 3;
        this->board = new int* [3];    
         
        for (int i = 0; i < 3; i++) {

            this->board[i] = new int[3];

            for (int j = 0; j < 3; j++) {  

                this->board[i][j] = 0;
            }
        }
    }
    void display_board() { 
        for (int i = 0; i < 3; ++i) {
            cout << i<<" ";
            for (int j = 0; j < 3; ++j) {
                cout << "| " << (this->board[i][j] == 0 ? " " : to_string(this->board[i][j]));  
            } 
            cout << "|";
            cout << endl;
        }
        for (int k = 0; k < 3; k++) cout << " ___";
        cout << endl; 
        cout << "    0  1  2";
        cout << endl;
    }
    bool is_win() {

        for (int i = 0; i < 3; i++) {
            //check for rows

            if (this->board[i][0] + this->board[i][1] + this->board[i][2] == 15) {
                
                return true;

            }
            //check for columns
            if (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15) {

                return true;
            }
        }
        //  check for diagonals
        if (this->board[0][0] + this->board[1][1] + this->board[2][2] == 15) {

            return true;

        }
        //  check for diagonals

        if (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15) {

            return true;

        }

        return false;

            
    }

    bool is_draw() {
        return (this->n_moves == 9 && !is_win());  
    }
    bool game_is_over() {

        return is_win() || is_draw(); 
    }


    bool update_board(int x, int y, T symbol ) {

        /*if ( used_numbers.count(symbol)) { 
            cout << "enter valid index" << endl;
            return false; 

        }*/

        

        this->board[x][y] = symbol;  
        used_numbers.insert(symbol); 
        this->n_moves++;   
        
        return true;
    }

   

};

template <typename T>
class num_xo_player : public Player<T> {
private:
    vector<int> available_numbers;
    num_xo_board<int>* board;

public:

    num_xo_player(string name, T symbol, vector<int> numbers , num_xo_board<int>* board) : Player<T>(name, symbol) {
        available_numbers = numbers; 
        this->board = board; 
        
    }

    void getmove(int& x, int& y) {

        cout << this->name << "'s turn  "; 

        cout << "Available numbers: ";

        for (int num : available_numbers) cout << num << " "; 


        cout << "\nRow -> ";
        cin >> x;

        cout << "Column -> ";
        cin >> y;

        while ((x > 2 || x < 0) || (y > 2 || y < 0) || this->board->board[x][y] != 0)
        {
            cout << "enter valid index" << endl;
            cout << "\nRow -> ";  
            cin >> x; 

            cout << "\nColumn -> "; 
            cin >> y; 
        } 
        

        int number;

        cout << "Number -> ";
        cin >> number;


        // Validate chosen number
        while (find(available_numbers.begin(), available_numbers.end(), number) == available_numbers.end()) {  
            cout << "Invalid number. Choose again: "; 
            cin >> number; 
        }

        this->symbol = number;

        available_numbers.erase(remove(available_numbers.begin(), available_numbers.end(), number), available_numbers.end());
    }
    
};

template <typename T> 
class num_xo_random_player : public RandomPlayer<T> { 
private:
    num_xo_board<int>* board;
    vector<int> numbers  ;
    //num_xo_player<int>* p = new num_xo_random_player;
public:
    num_xo_random_player( T symbol ,vector<int> selected_numbers, num_xo_board<int>* board ) : RandomPlayer<T>(symbol) { 
        this->dimension = 3;  
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0)));
        numbers = selected_numbers;
        this->board = board;  
        
    }
    
    
    void getmove(int& x, int& y) {
        
        x = rand() % 3;  
        y = rand() % 3; 

        while (this->board->board[x][y] != 0 )
        {
            x = rand() % this->dimension;  
            y = rand() % this->dimension; 
        }
        

        //while (!numbers.empty()) {
        //    int randomIndex = std::rand() % numbers.size();  
        //    int element = numbers[randomIndex];  
        //    cout << "the random element :" << element << endl;
        //    //this->board->update_board(x, y, element);
        //    //numbers.erase(numbers.begin() + randomIndex); 
        //    auto it = find(numbers.begin(), numbers.end(), element);
        //    if (it != numbers.end()) {
        //        numbers.erase(it);
        //    }
        //    
        //}
        //int randomIndex = std::rand() % numbers.size(); 
        //cout << "the randomIndex :" << randomIndex << endl; 

        //int element = numbers[randomIndex];
        //
        //cout << "the random element :" << element << endl;
        ////this->board->update_board(x, y, element);
        ////numbers.erase(numbers.begin() + randomIndex); 
        //auto it = find(numbers.begin(), numbers.end(), element);
        //if (it != numbers.end()) {
        //    numbers.erase(it);
        //}
        
    }
    

};
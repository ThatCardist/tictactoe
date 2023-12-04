// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//for ai version make it check to see which spots have the most possible winning moves and then also if opponenet has any winning moves
#include <iostream>
#include <string>
#include <cstring> 
#include <cstring> 
#include <algorithm>
//#include "game.h"

using namespace std;

int menu() {
    int x = 0;
    while (x < 1 || x > 3) {
        cout << "Select an option" << endl;
        cout << "1: Start a game" << endl;
        cout << "2: See Score" << endl;
        cout << "3: Quit" << endl;
        cin >> x;
    }
    return x;
}

class Game {
private:
    int computerScore = 0;
    int playerScore = 0;
    string movesMade[9] = {"N","N", "N", "N", "N", "N", "N", "N", "N"};
    int curPlayer = 0;
public:
    string board[3][3] = { {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"} };
    Game() {
    
    }
    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                cout << " " << board[i][j] << " | ";
            }
            cout << board[i][2] << endl;
            if (i != 2) {
                cout << "_____________" << endl;
            }
        }
    }
    bool checkWinner() {
        
        //check rows
        
        //check columns
        //check diagonals
        //make sure not all moves are taken
        return true;
    }

    bool isTie() {
        for (int i = 0; i < 9; i++) {
            if (movesMade[i] == "N") {
                return false;
            }
        }
        return true;
    }
    void swapPlayer() {
        curPlayer = (curPlayer + 1) % 2;
    }

    string getCurPlayer() {
        if (curPlayer == 0) {
            return "X";
        }
        else {
            return "O";
        }
    }

    bool isValidMove(string m) {
        int move = stoi(m);
        if ((move <= 9 && move >= 1) && movesMade[move] == "N") {
            
            return true;
        }
        else {
            return false;
        }
    }
    void placeMove(string m) {
        int move = stoi(m);
        movesMade[move] = "Y";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if (board[i][j] == m) {
                    switch (curPlayer)
                    {
                    case 0:
                        board[i][j] = "X";
                        break;
                    case 1:
                        board[i][j] = "O";
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
};

int main() {
    //cout << "Hello World!\n";
    //left off at implementing a place move and adding a loop to main if move is invalid
    while (true) {
        int mChoice = menu();
        switch (mChoice) {
        case 1: {
            Game* newGame = new Game();
            string move;
            while ((newGame->checkWinner() == false) || !newGame->isTie()) {
                newGame->printBoard();
                    cout << newGame->getCurPlayer() << " select a spot" << endl;
                    cin >> move;
                newGame->swapPlayer();
            }
            
            //break;
        }
        case 2:

            //break;
        case 3:
            break;
        }
        if (mChoice == 3) {
            break;
        }
    }
    cout << "Good bye!";
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

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
    int movesMade = 0;
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
    bool checkWinner(string p) {
        //check rows
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) {
                cout << getCurPlayer() << " is the winner!" << endl;
                return true;
            }
        }
        //check columns
        for (int i = 0; i < 3; i++) {
            if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i])) {
                cout << getCurPlayer() << " is the winner!" << endl;
                return true;
            }
    }
        //check diagonals
        if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) {
            cout << getCurPlayer() << " is the winner!" << endl;
            return true;
        }
        if ((board[0][2] == board[1][1]) && (board[0][0] == board[2][0])) {
            cout << getCurPlayer() << " is the winner!" << endl;
            return true;
        }
        return false;
    }

    bool isTie() {
        if (movesMade == 9 && !checkWinner(getCurPlayer())) {
            cout << "it's a tie!" << endl;
            return true;
        }
        return false;
            
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
        try {
            int move = stoi(m);
            if ((move <= 9 && move >= 1) && ((board[(move - 1) / 3][(move - 1) % 3]) != "X" || (board[(move - 1) / 3][(move - 1) % 3]) != "O")) {
                return true;
            }
            else {
                cout << "Invalid Move, try again..." << endl;
                return false;
            }
            
        }
        catch(string m){
            cout << "not a number, try again..." << endl;
            return false;
        }
    }
    void placeMove(string m) {
        //make row = (m - 1) % 3
        //make col = (m- 1) /3
        int move = stoi(m);
        board[(move - 1) / 3][(move - 1) % 3] = getCurPlayer();
    }
};

int main() {
    //cout << "Hello World!\n";
    //left off at implementing a place move and adding a loop to main if move is invalid
    /*
    -------------TODO------------
    >error handle non-number entered
    >board not updating
    >check if check winner works
    >add something to enter when game is over
    >computer player and player number select
    >change place move to remove loop method
    */
    while (true) {
        int mChoice = menu();
        switch (mChoice) {
        case 1: {
            Game* newGame = new Game();
            string move;
            while (!newGame->isTie()) {
                newGame->printBoard();
                do {
                    cout << newGame->getCurPlayer() << " select a spot" << endl;
                    cin >> move;
                } while (!newGame->isValidMove(move));
                newGame->placeMove(move);
                if (newGame->checkWinner(newGame->getCurPlayer())) {
                    break;
                }
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

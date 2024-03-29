// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
//Declaring Variables
int board [9] = { 0,0,0,0,0,0,0,0,0};
int i, num1, winner;
bool winCondition, gameOver;

//This checks the board after each player goes to check if they have won, it then sets the win variable to true and selects the winner.
void checkWin() {
	for (i = 1; i <= 2; i++) {
		if ((board[0] == i && board[1] == i && board[2] == i) || (board[3] == i && board[4] == i && board[5] == i) || (board[6] == i && board[7] == i && board[8] == i)
			|| (board[0] == i && board[3] == i && board[6] == i) || (board[1] == i && board[4] == i && board[7] == i) || (board[2] == i && board[5] == i && board[8] == i)
			|| (board[0] == i && board[4] == i && board[8] == i) || (board[2] == i && board[4] == i && board[6] == i)) {
		winCondition = true;
		winner = i;
		}
	}
}
//This checks if the board is full and flips the gameOver variable if it is.
int checkFull() {
	for (i = 0; i <= 8; i++) {
		if (board[i] == 0) {
			return 0;
		}

	}
	cout << "The board is full, Game Over, it's a draw." << endl;
	gameOver = true;
}

//This generates the complete board when it is run and then checks if anyone has won.
void createBoard() {
	for (i = 0; i <= 8; i++) {
		if (board[i] == 0) {
			cout << "|   ";
		}
		else if (board[i] == 1) {
			cout << "| X ";
		}
		else if (board[i] == 2) {
			cout << "| 0 ";
		}
			if (i == 2||i==5||i==8) {
				cout << "|" << endl;
		
		}
	}
checkWin();
}


// These two function are very similar and prompt the player to enter a number, updates the board array, then runs board creation and checks if the board is full.
void turn1() {
if (winCondition == false) {
	cout << "Player one's turn:" << endl;
	cin >> num1;
	//This checks if the selected spot is taken and if it is reruns the function.
	if (board[num1 - 1] != 0) {
		cout << "Sorry that spot has already been taken." << endl;
		turn1();
	}
	board[num1 - 1] = 1;
createBoard();
checkFull();
	}
}
// Almost Identical but works for player 2.
void turn2() {

	if (winCondition == false) {
		cout << "Player two's turn:" << endl;
		cin >> num1;
		if (board[num1 - 1] != 0) {
			cout << "Sorry that spot has already been taken." << endl;
			turn2();
		}board[num1 - 1] = 2;
		createBoard();
		checkFull();
	}
}

	int main() {
		//Sets all the variables to a default value and starts the game.
		winner = 0;
		gameOver = false;
		winCondition = false;
		for (i = 0; i <= 8; i++) {
			board[i] == 0;
		}
		//Generates the intial board and explains how to enter choices.
		createBoard();
		cout << "To select a number from the first row press 1 to 3, for the second row, 4 to 6 and the third row, 7 to 9." << endl;
		//This cycles the turns until one player has won or the board is full.
		while (winCondition == false) {
			turn1();
			if (gameOver == true) {
				return 0;
			}
			turn2();
			if (gameOver == true) {
				return 0;
			}
		}
		//Delclares the winner then allows the players to close the game.
		cout << "The winner is:  Player " << winner << endl;
		system("pause");
		return 0;
	}

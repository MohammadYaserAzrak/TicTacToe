#pragma once
#include <iostream>
#include <string>
using namespace std;

class TicTacToeGame
{
public:
	TicTacToeGame();

	void printBoard(const char board[3][3]);

	int getCoordinate(string line);

	bool isOccupied(int x, int y, const char board[3][3]);

	bool checkWin(char playerSymbol, const char board[3][3]);

	bool isBoardFull(const char board[3][3]);

	void playGame();
};

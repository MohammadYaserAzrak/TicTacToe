#include "TicTacToeGame.h"
#include "Player.h"

TicTacToeGame::TicTacToeGame() {}

bool TicTacToeGame::isBoardFull(const char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				return false;
		}
	}
	return true;
}

bool TicTacToeGame::checkWin(char playerSymbol, const char board[3][3])
{
	// Check rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
		{
			return true;
		}
	}

	// Check columns
	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == playerSymbol && board[1][j] == playerSymbol && board[2][j] == playerSymbol)
		{
			return true;
		}
	}

	// Check diagonals
	if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
	{
		return true;
	}
	if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
	{
		return true;
	}

	return false;
}

bool TicTacToeGame::isOccupied(int x, int y, const char board[3][3])
{
	if (board[x - 1][y - 1] != ' ')
	{
		return true;
	}
	return false;
}

void TicTacToeGame::printBoard(const char board[3][3])
{
	cout << "   1   2    3" << endl;
	cout << "  -------------" << endl;

	for (int row = 0; row < 3; row++)
	{
		cout << row + 1 << " | ";
		for (int col = 0; col < 3; col++)
		{
			cout << board[row][col];
			if (col < 3)
				cout << " | ";
		}
		cout << endl;
		if (row < 3)
			cout << "  -------------" << endl;
	}
	cout << endl;
}

int TicTacToeGame::getCoordinate(string line)
{
	int coordinate;
	cout << "Enter the " << line << " number of where you wish to place your marker:\n";
	while (!(cin >> coordinate))
	{ // If the player inputs a non-int variable
		cout << "Wrong input!\n";
		cin.clear();
		cin.ignore(64, '\n');
	}
	while (coordinate != 3 && coordinate != 2 && coordinate != 1)
	{
		cout << "Wrong input!\n";
		cin >> coordinate;
	}
	return coordinate;
}

void TicTacToeGame::playGame()
{
	char board[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}};
	int x, y;
	string name;
	char symbol, turn;

	cout << "Welcome to TicTacToe!\n"
		 << endl;

	// Initializing player one
	cout << "The first player should now enter their name: \n";
	cin >> name;
	cout << "Hello " << name << "!\n";
	cout << "What would you like your symbol to be?\n";
	cin >> symbol;
	cin.ignore(64, '\n');
	Player firstPlayer(name, symbol);
	turn = symbol;

	// Initializing player two
	cout << "\nThe second player should now enter their name: \n";
	cin >> name;
	while (name == firstPlayer.getName())
	{ // Ensure distinct names
		cout << "Choose a distinct name please:\n";
		cin >> name;
	}
	cout << "Hello " << name << "!\n";
	cout << "What would you like your symbol to be?\n";
	cin >> symbol;
	cin.ignore(64, '\n');
	while (symbol == firstPlayer.getSymbol())
	{ // Ensure distinct symbols
		cout << "Choose a distinct symbol please:\n";
		cin >> symbol;
		cin.ignore(64, '\n');
	}
	Player secondPlayer(name, symbol);

	// Game started!
	cout << "Preparing a new game of TicTacToe...\n"
		 << endl;
	printBoard(board);

	while (true)
	{
		if (turn == firstPlayer.getSymbol())
		{
			cout << firstPlayer.getName() << "'s Turn!\n";
			x = getCoordinate("row");
			y = getCoordinate("column");
			while (isOccupied(x, y, board))
			{ // Ensure no obstruction
				cout << "This tile is occupied!\n";
				x = getCoordinate("row");
				y = getCoordinate("column");
			}
			board[x - 1][y - 1] = firstPlayer.getSymbol();
			printBoard(board);
			turn = secondPlayer.getSymbol();
		}

		// Check if game ended
		if (checkWin(firstPlayer.getSymbol(), board))
		{
			cout << firstPlayer.getName() << " won!\n";
			break;
		}

		// Check if draw
		if (isBoardFull(board))
		{
			cout << "Draw!\n";
			break;
		}

		if (turn == secondPlayer.getSymbol())
		{
			cout << secondPlayer.getName() << "'s Turn!\n";
			x = getCoordinate("row");
			y = getCoordinate("column");
			while (isOccupied(x, y, board))
			{ // Ensure no obstruction
				cout << "This tile is occupied!\n";
				x = getCoordinate("row");
				y = getCoordinate("column");
			}
			board[x - 1][y - 1] = secondPlayer.getSymbol();
			printBoard(board);
			turn = firstPlayer.getSymbol();
		}

		// Check if game ended
		if (checkWin(secondPlayer.getSymbol(), board))
		{
			cout << secondPlayer.getName() << " won!\n";
			break;
		}
	}
}
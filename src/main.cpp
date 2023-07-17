#include <iostream>
#include <string>
#include "Player.h"
#include "TicTacToeGame.h"
using namespace std;

int main()
{
	char input;
	TicTacToeGame game;

	while (true)
	{
		game.playGame();
		cout << "Do you want to play again? (Y/N)\n";
		cin >> input;
		cout << endl;
		cin.ignore(64, '\n'); // ignores all char except the first one
		if (input != 'Y' && input != 'y')
		{
			cout << "Thank you for playing!\n";
			break;
		}
	}

	cin.get();
	return 0;
}
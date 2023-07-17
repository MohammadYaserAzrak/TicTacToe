#include "Player.h"

Player::Player(string name, char symbol) : _name(name), _symbol(symbol) {}

void Player::print()
{
	cout << _name << " " << _symbol << endl;
}

string Player::getName()
{
	return _name;
}

char Player::getSymbol()
{
	return _symbol;
}
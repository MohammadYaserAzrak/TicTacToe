#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
	string _name;
	char _symbol;

public:
	Player(string name = "NONE", char symbol = '$');

	string getName();

	char getSymbol();

	void print();
};
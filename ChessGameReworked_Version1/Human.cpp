#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "Human.h"
using namespace std;

Human::Human(char c) : Player(c) {
	assert(c == 'w' || c == 'b'); // Ensure color is valid
}

int* Human::getMove()
{
	int* move;
	cout << "Enter your move (e.g., e2-e4 or 00-00 if you want to exit): ";
	string input;
	cin >> input;

	move = Player::moveConverter(input);
	if (move == nullptr) {
		cout << "Invalid move format. Please try again." << endl;
		return nullptr; // Return nullptr if the move is invalid
	}

	return move;
}

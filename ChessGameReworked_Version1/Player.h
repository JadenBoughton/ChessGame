#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ChessGame.h"
using namespace std;

class Player
{
private:
	//ChessGame chessGame;
	// You can add any private members specific to Human player if needed
	const char color; // 'w' for white, 'b' for black

public:
	Player(char c) : color(c) {
		assert(c == 'w' || c == 'b'); // Ensure color is valid
	}
	virtual ~Player() = default; // Virtual destructor for proper cleanup in derived classes
	virtual int* getMove() = 0; // Pure virtual function to get the player's move

	static int* moveConverter(string move);

	static int characterConversion(char letter);
};

#endif

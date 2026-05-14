#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Player.h"

class Human : public Player
{




public:
	// Default constructor for Human player, assuming white color ('w')
	Human(char c) : Player(c) {}
	// You can add any additional constructors or methods specific to Human player if needed
	~Human() override = default; // Virtual destructor for proper cleanup
	// Override the getMove method to get input from the user
	// This method will be called to get the player's move
	int* getMove() override;

};
#endif

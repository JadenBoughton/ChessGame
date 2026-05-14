#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Computer.h"

Computer::Computer(char c) : Player(c) {
	// Constructor for Computer player, assuming color is either 'w' or 'b'
	// The color is validated in the Player constructor
	assert(c == 'w' || c == 'b'); // Ensure color is valid
}

int* Computer::getMove(){
	// This function should implement the logic for the computer to decide its move
	// For now, we will return nullptr to indicate that this function is not yet implemented
	return nullptr;
}

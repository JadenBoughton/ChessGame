#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
using namespace std;

#include "King.h"


King::King(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->firstMove = true;
	Castling = false;
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

int* King::moveLogic(int* move, char GameBoardArray[][8], int row)
{
	int down_from = move[0];
	int across_from = move[1];	
	int down_to = move[2];
	int across_to = move[3];

	int directionalDifferenceYAxis = down_from - down_to;
	int directionalDifferenceXAxis = across_from - across_to;

	if(across_from > 7 || across_from < 0){return nullptr;}
    else if(across_to > 7 || across_to < 0){return nullptr;}
    else if(down_from > 7 || down_from < 0){return nullptr;}
    else if(down_to > 7 || down_to < 0){return nullptr;}

	int absoluteY = abs(directionalDifferenceYAxis);
    int absoluteX = abs(directionalDifferenceXAxis);

	if(directionalDifferenceYAxis == 0 && directionalDifferenceXAxis == 0){return nullptr;}
	if(absoluteY > 1 || absoluteX > 1){
		return nullptr;
	}

	if(absoluteY == 1 && absoluteX == 1){
		if(GameBoardArray[down_to][across_to] == '_'){
			return move;
		}
	}

	return nullptr;
}

bool King::testIfInCheck(Piece *GameBoardArray[][8], char blackAndWhite[][8], int move[4])
{
	// This function should be implemented in derived classes
	// It is a placeholder here to satisfy the interface
	cout << "King::testIfInCheck called" << endl;
	// Implement logic to check if the king is in check
	// For now, just print a message
	cout << "Checking if king is in check..." << endl;

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			// Check if the piece at (i, j) is a king
			// if(GameBoardArray[i][j] != nullptr && GameBoardArray[i][j]->getSymbol() == 'K') {
			// 	// Check if the king is in check
			// 	// This is a placeholder for the actual logic to determine if the king is in check
			// 	cout << "King found at position: " << i << ", " << j << endl;
			// } 
			if(GameBoardArray[i][j] != nullptr && GameBoardArray[i][j]->getDirection() != this->direction) {
				GameBoardArray[i][j]->testKingCheck(blackAndWhite, i, j);
				cout << "Opponent piece found at position: " << i << ", " << j << endl;
			}
		}
	}

	int down_from = move[0];
	int across_from = move[1];	
	int down_to = move[2];
	int across_to = move[3];

	bool isInCheck = false;

	if(blackAndWhite[down_to][across_to] != 'x') {
		isInCheck = true;
	}

	cout << "King is " << (isInCheck ? "in check." : "not in check.") << endl;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(blackAndWhite[i][j] == 'x'){
				blackAndWhite[i][j] = '_'; // Reset the check status after checking
			}
		}
	}

	return isInCheck; // Return nullptr for now, as this is a placeholder
}
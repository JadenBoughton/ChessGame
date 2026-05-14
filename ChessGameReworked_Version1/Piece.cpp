#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Piece.h"


char Piece::getSymbol()
{
	return this->symbol;
}

char Piece::getDirection()
{
	return this->direction;
}

Piece::Piece(char direction, char symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->firstMove = true;
	Castling = false;
	assert(direction == 'w' || direction == 'b' || direction == '_');
	assert(symbol != ' ');
}

bool Piece::testIfInCheck(Piece *(*GameBoardArray)[8], char (*gameBoardArray)[8], int *locationList) const
{
	// This function should be implemented in derived classes
	// It is a placeholder here to satisfy the interface
	return false;
}

void Piece::testKingCheck(char (*gameBoardArray)[8], int x, int y) const
{
	// This function should be implemented in derived classes
	// It is a placeholder here to satisfy the interface
}

int* Piece::moveLogic(int* move, char gameBoardArray[][8], int row) const
{
	// This function should be implemented in derived classes
	// It is a placeholder here to satisfy the interface
	return nullptr;
}
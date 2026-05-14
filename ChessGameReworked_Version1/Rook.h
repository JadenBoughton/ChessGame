#ifndef ROOK_H
#define ROOK_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook::Rook(char direction, char symbol) : Piece(direction, symbol) {
		this->direction = direction;
		this->symbol = symbol;
		this->firstMove = true;
		Castling = false;
		assert(direction == 'w' || direction == 'b');
		assert(symbol != ' ');
	}

	int* moveLogic(int* move, char GameBoardArray[][8], int row);

	void testKingCheck(char GameBoardArray[][8], int x, int y);

};
#endif

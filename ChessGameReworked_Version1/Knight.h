#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(char direction, char symbol);

	int* moveLogic(int* move, char GameBoardArray[][8], int row);

	void testKingCheck(char GameBoardArray[][8], int x, int y);

};
#endif

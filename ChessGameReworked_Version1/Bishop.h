#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(char direction, char symbol);

	int* moveLogic(int* move, char GameBoardArray[][8], int row);

	void testKingCheck(char GameBoardArray[][8], int x, int y);

};
#endif

#ifndef QUEEN_H
#define QUEEN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Piece.h"

class Queen : public Piece
{
private:
	Rook *rook;

	Bishop *bishop;


public:
	Queen(char direction, char symbol);

	int* moveLogic(int* move, char GameBoardArray[][8], int row);

	void testKingCheck(char GameBoardArray[][8], int x, int y);

};
#endif

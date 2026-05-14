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
	void Rook();

	boolean moveLogic(int* move, char GameBoardArray[][8], int row);

	void testKingCheck(char GameBoardArray[][8], int x, int y);

};
#endif

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
	Piece *rook;

	Piece *bishop;


public:
	void Queen();

	boolean moveLogic(int* move, char GameBoardArray[][8], int row);

	int* testKingCheck(char GameBoardArray[][8], int x, int y);

};
#endif

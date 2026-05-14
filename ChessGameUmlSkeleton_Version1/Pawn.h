#ifndef PAWN_H
#define PAWN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Piece.h"

class Pawn : public Piece
{
public:
	/**
	 *  
	 */
	void Pawn();

	boolean moveLogic(int* move, char GameBoardArray[][8], int row);

	void testKingCheck(char GameBoardArray[][8], int x, int y);

	int* forward(int* numberArray, char GameBoardArray[][8], int row);

	int* backward(int* numberArray, char GameBoardArray[][8], int row);

};
#endif

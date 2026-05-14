#ifndef KING_H
#define KING_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Piece.h"

class King : public Piece
{
public:
	void King();

	boolean moveLogic(int* move, char GameBoardArray[][8], int row);

	/**
	 *  
	 */
	int* testIfInCheck(Piece *GameBoardArray[][8], char blackAndWhite[][8], int locationList[4]);

};
#endif

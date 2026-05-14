#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ChessBoard.h"

class Piece
{
private:
	ChessBoard chessBoard;

protected:
	char direction;

	char symbol;

	boolean firstMove;


public:
	boolean Castling;


public:
	virtual boolean moveLogic(int* move, char gameBoardArray[][8], int row)=0;

	virtual void testKingCheck(boolean gameBoardArray[][8], int x, int y)=0;

	virtual int* testIfInCheck(Piece *GameBoardArray[][8], char gameBoardArray[][8], int locationList[4])=0;

	char getSymbol();

	char getDirection();

	void Piece();

};
#endif

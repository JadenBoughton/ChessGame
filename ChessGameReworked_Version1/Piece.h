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
	ChessBoard* chessBoard;

protected:
	char direction;

	char symbol;

	bool firstMove;


public:
	bool Castling;


public:
	Piece(char direction, char symbol) : direction(direction), symbol(symbol), firstMove(true), Castling(false), chessBoard(nullptr) {};

	virtual int* moveLogic(int* move, char gameBoardArray[][8], int row) const;

	virtual void testKingCheck(char gameBoardArray[][8], int x, int y) const;

	virtual bool testIfInCheck(Piece *GameBoardArray[][8], char gameBoardArray[][8], int locationList[4]) const;

	char getSymbol();

	char getDirection();

};
#endif

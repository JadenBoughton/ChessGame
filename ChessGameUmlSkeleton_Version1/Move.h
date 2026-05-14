#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ChessGame.h"
#include "ChessBoard.h"

class Move
{
private:
	ChessGame chessGame;
	ChessBoard chessBoard;

public:
	boolean inputMove();

	static int* moveConverter(string move);

	static int characterConversion(char letter);

};
#endif

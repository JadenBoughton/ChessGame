#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ArrayList.h"
#include "Piece.h"
#include "ChessGame.h"
#include "Move.h"
#include "Subject.h"
#include "Observer.h"
#include "ChessBoard.instance.h"

class ChessBoard
{
private:
	ArrayList<string> moveHistory;

	static Piece gameBoard[][8];

	static ChessBoard instance;

	Piece piece[32];
	ChessGame chessGame;
	Move move;
	Subject subject;
	Observer observer;

private:
	boolean swap(int* move);

public:
	ChessBoard.instance getInstance();

	ArrayList<string> getMoveHistory(int prevMoves);

	void updateBoard(int* move);

};
#endif

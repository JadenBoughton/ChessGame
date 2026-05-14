#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ChessBoard.h"
#include "Move.h"
#include "Player.h"

class ChessGame
{
private:
	ChessBoard *chessBoard;
	Move move;
	Player* player[2];

public:
	void main();
	bool setup();
};
#endif

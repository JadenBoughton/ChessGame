#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <Rook.h>
#include <Bishop.h>

#include "Queen.h"


Queen::Queen(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->rook = new Rook(direction, 'R');  
	this->bishop = new Bishop(direction, 'B'); 
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

int* Queen::moveLogic(int* move, char GameBoardArray[][8], int row)
{
    int down_from1 = *move;
    move++;
    int across_from1 = *move;
    move++;
    int down_to1 = *move;
    move++;
    int across_to1 = *move;

    int directionalDifferenceYAxis = down_from1-down_to1;
    int directionalDifferenceXAxis = across_from1-across_to1;

    if(directionalDifferenceYAxis == 0 || directionalDifferenceXAxis == 0){
        return rook->moveLogic(move, GameBoardArray, row);
    }else if(directionalDifferenceYAxis == directionalDifferenceXAxis){
        return bishop->moveLogic(move, GameBoardArray, row);
    }

	return nullptr;
}

void Queen::testKingCheck(char GameBoardArray[][8], int x, int y)
{
	rook->testKingCheck(GameBoardArray, x, y);
	bishop->testKingCheck(GameBoardArray, x, y);
}

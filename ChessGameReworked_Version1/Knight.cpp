#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Knight.h"


Knight::Knight(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->firstMove = true;
	Castling = false;
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

int* Knight::moveLogic(int* move, char GameBoardArray[][8], int row)
{

    int down_from = *move;
    move++;
    int across_from = *move;
    move++;
    int down_to = *move;
    move++;
    int across_to = *move;

    int directionalDifferenceYAxis = down_from-down_to;
    int directionalDifferenceXAxis = across_from-across_to;

    if(across_from > 7 || across_from < 0){
        return nullptr;
    }
    else if(across_to > 7 || across_to < 0){
        return nullptr;
    }
    else if(down_from > 7 || down_from < 0){
        return nullptr;
    }
    else if(down_to > 7 || down_to < 0){
        return nullptr;
    }

    int absoluteY = abs(directionalDifferenceYAxis);
    int absoluteX = abs(directionalDifferenceXAxis);

    if(absoluteY == 2 && absoluteX == 1){
        if(direction == '+' &&
           GameBoardArray[down_to][across_to] != 'w' &&
           GameBoardArray[down_to][across_to] != 'W'){
            firstMove = false;
            return move;
        }
        else if(direction == '-' &&
                GameBoardArray[down_to][across_to] != 'b' &&
                GameBoardArray[down_to][across_to] != 'B'){
            firstMove = false;
            return move;
        }
    }
    else if(absoluteY == 1 && absoluteX == 2){
        if(direction == '+' &&
           GameBoardArray[down_to][across_to] != 'w' &&
           GameBoardArray[down_to][across_to] != 'W'){
            firstMove = false;
            return move;
        }
        else if(direction == '-' &&
                GameBoardArray[down_to][across_to] != 'b' &&
                GameBoardArray[down_to][across_to] != 'B'){
            firstMove = false;
            return move;
        }
    }
    return nullptr;
}

void Knight::testKingCheck(char GameBoardArray[][8], int y, int x)
{


    if(y > 1 && x < 7){
        if(GameBoardArray[y-2][x+1] == '_'){
            GameBoardArray[y-2][x+1] = 'x';
        }
    }

    if(y > 0 && x < 6){
        if(GameBoardArray[y-1][x+2] == '_'){
            GameBoardArray[y-1][x+2] = 'x';
        }
    }

    if(y < 6 && x < 7){
        if(GameBoardArray[y+2][x+1] == '_'){
            GameBoardArray[y+2][x+1] = 'x';
        }
    }

    if(y < 7 && x < 6){
        if(GameBoardArray[y+1][x+2] == '_'){
            GameBoardArray[y+1][x+2] = 'x';
        }
    }


    if(y > 1 && x > 0){
        if(GameBoardArray[y-2][x-1] == '_'){
            GameBoardArray[y-2][x-1] = 'x';
        }
    }

    if(y > 0 && x > 1){
        if(GameBoardArray[y-1][x-2] == '_'){
            GameBoardArray[y-1][x-2] = 'x';
        }
    }

    if(y < 6 && x > 0){
        if(GameBoardArray[y+2][x-1] == '_'){
            GameBoardArray[y+2][x-1] = 'x';
        }
    }

    if(y < 7 && x > 1){
        if(GameBoardArray[y+1][x-2] == '_'){
            GameBoardArray[y+1][x-2] = 'x';
        }
    }
}

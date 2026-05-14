#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Rook.h"


Rook::Rook(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->firstMove = true;
	this->Castling = false;
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

int* Rook::moveLogic(int* move, char GameBoardArray[][8], int row)
{

    int down_from = move[0];
    int across_from = move[1];
    int down_to = move[2];
    int across_to = move[3];

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

    if(absoluteY == 0 && absoluteX == 0){return nullptr;}
    if(absoluteY != 0 && absoluteX != 0){return nullptr;}

    int distanceFromStartToFinish = absoluteY + absoluteX;

    //int directionX = absoluteX/directionalDifferenceXAxis;
    //int directionY = absoluteY/directionalDifferenceYAxis;

    for(int i = 0; i < distanceFromStartToFinish; i++){
        if(GameBoardArray[down_from-directionalDifferenceYAxis][across_from-directionalDifferenceXAxis] != '_'){
            return nullptr;
        }
    }

    return move;
}

void Rook::testKingCheck(char GameBoardArray[][8], int y, int x)
{
    int yCopy = y;
    int xCopy = x;

    xCopy++;
    while(xCopy < 8){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x'){
            GameBoardArray[yCopy][xCopy] = 'x';
            xCopy++;
        }else{break;}
    }

    xCopy = x;

    xCopy--;
    while(xCopy > 0){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x'){
            GameBoardArray[yCopy][xCopy] = 'x';
            xCopy--;
        }else{break;}
    }

    yCopy = y;
    xCopy = x;

    yCopy++;
    while(yCopy < 8){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x'){
            GameBoardArray[yCopy][xCopy] = 'x';
            yCopy++;
        }else{break;}
    }

    yCopy = y;

    yCopy--;
    while(yCopy > 0){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x'){
            GameBoardArray[yCopy][xCopy] = 'x';
            yCopy--;
        }else{break;}
    }
}
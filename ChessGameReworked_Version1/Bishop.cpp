#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Bishop.h"


Bishop::Bishop(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->firstMove = true;
	Castling = false;
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

int* Bishop::moveLogic(int* move, char GameBoardArray[][8], int row)
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

    if(absoluteY != absoluteX || absoluteY == 0 || absoluteX == 0){
        return nullptr;
    }

    int distanceFromStartToFinish = absoluteY * absoluteX;

    int directionY = absoluteY/directionalDifferenceYAxis;
    int directionX = absoluteX/directionalDifferenceXAxis;

    for(int i = 0; i < distanceFromStartToFinish; i++){
        if(GameBoardArray[down_from-directionY][across_from-directionX] != '_'){
            return nullptr;
        }
    }

    return move;
}

void Bishop::testKingCheck(char GameBoardArray[][8], int y, int x)
{
	int yCopy = y;
    int xCopy = x;

    yCopy--;
    xCopy++;
    while(yCopy > 0 || xCopy < 8){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x') {
            GameBoardArray[yCopy][xCopy] = 'x';
            yCopy--;
            xCopy++;
        }else{break;}
    }

    yCopy = y;
    xCopy = x;

    yCopy++;
    xCopy++;
    while(yCopy < 8 || xCopy < 8){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x') {
            GameBoardArray[yCopy][xCopy] = 'x';
            yCopy++;
            xCopy++;
        }else{break;}
    }

    //if(GameBoardArray[xCopy][yCopy] == '_') {
    //}else{break;}

    yCopy = y;
    xCopy = x;

    yCopy++;
    xCopy--;
    while(yCopy < 8 || xCopy > 0){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x') {
            GameBoardArray[yCopy][xCopy] = 'x';
            yCopy++;
            xCopy--;
        }else{break;}
    }

    yCopy = y;
    xCopy = x;

    yCopy--;
    xCopy--;
    while(yCopy > 0 || xCopy > 0){
        if(GameBoardArray[yCopy][xCopy] == '_' || GameBoardArray[yCopy][xCopy] == 'x') {
            GameBoardArray[yCopy][xCopy] = 'x';
            yCopy--;
            xCopy--;
        }else{break;}
    }
}

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Pawn.h"


Pawn::Pawn(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->firstMove = true;
	Castling = false;
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

bool Pawn::moveLogic(int* move, char GameBoardArray[][8], int row)
{
	if(Piece::direction == '+'){
        return forward(move, GameBoardArray, row);
    }else{
        return backward(move, GameBoardArray, row);
    }
}

void Pawn::testKingCheck(char GameBoardArray[][8], int y, int x)
{
	if(direction == '+'){
        if(GameBoardArray[y-1][x+1] == '_' && y > 0 && x < 8){
            GameBoardArray[y-1][x+1] = 'x';
        }
        if(GameBoardArray[y+1][x+1] == '_' && y < 8 && x < 8){
            GameBoardArray[y+1][x+1] = 'x';
        }
    }else{
        if(GameBoardArray[y-1][x-1] == '_' && y > 0 && x > 0){
            GameBoardArray[y-1][x-1] = 'x';
        }
        if(GameBoardArray[y+1][x-1] == '_' && y < 8 && x > 0){
            GameBoardArray[y+1][x-1] = 'x';
        }
    }
}

int* Pawn::forward(int* numberArray, char GameBoardArray[][8], int row)
{
	int down_from = *numberArray;
    numberArray++;
    int across_from = *numberArray;
    numberArray++;
    int down_to = *numberArray;
    numberArray++;
    int across_to = *numberArray;

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

    if(GameBoardArray[down_to][across_to] == 'b' || GameBoardArray[down_to][across_to] == 'B') {
        if (directionalDifferenceXAxis == -1) {
            if (down_from < 7 && directionalDifferenceYAxis == 1){
                firstMove = false;
                return numberArray;
            }
            else if (down_from > 0 && directionalDifferenceYAxis == -1){
                firstMove = false;
                return numberArray;
            }
        }
    }

    if(down_from > 0 && GameBoardArray[down_from-1][across_from] == 'l'){
        if(directionalDifferenceXAxis == -1){
            if(directionalDifferenceYAxis == 1){
                return numberArray;
            }

        }
    }

    if(down_from < 7 && GameBoardArray[down_from+1][across_from] == 'l'){
        if(directionalDifferenceXAxis == -1) {
            if (directionalDifferenceYAxis == -1) {
                firstMove = false;
                return numberArray;
            }
        }
    }

    if(directionalDifferenceYAxis == 0 && directionalDifferenceXAxis == -1){
        if(GameBoardArray[down_to][across_to] == '_'){
            firstMove = false;
            return numberArray;
        }
    }

    if(directionalDifferenceXAxis == -2 && firstMove){
        firstMove = false;
        return numberArray;
    }

    return nullptr;
}

int* Pawn::backward(int* numberArray, char GameBoardArray[][8], int row)
{
	int down_from1 = *numberArray;
    numberArray++;
    int across_from1 = *numberArray;
    numberArray++;
    int down_to1 = *numberArray;
    numberArray++;
    int across_to1 = *numberArray;

    int directionalDifferenceYAxis = down_from1-down_to1;
    int directionalDifferenceXAxis = across_from1-across_to1;

    if(across_from1 > 7 || across_from1 < 0){
        return nullptr;
    }
    else if(across_to1 > 7 || across_to1 < 0){
        return nullptr;
    }
    else if(down_from1 > 7 || down_from1 < 0){
        return nullptr;
    }
    else if(down_to1 > 7 || down_to1 < 0){
        return nullptr;
    }

    if(GameBoardArray[down_to1][across_to1] == 'w' || GameBoardArray[down_to1][across_to1] == 'W') {
        if (directionalDifferenceXAxis == 1) {
            if (down_from1 < 7 && directionalDifferenceYAxis == 1){
                firstMove = false;
                return numberArray;
            }
            else if (down_from1 > 0 && directionalDifferenceYAxis == -1){
                firstMove = false;
                return numberArray;
            }
        }
    }

    if(down_from1 > 0 && GameBoardArray[down_from1-1][across_from1] == 'p'){
        if(directionalDifferenceXAxis == 1){
            if(directionalDifferenceYAxis == 1){
                return numberArray;
            }

        }
    }

    if(down_from1 < 7 && GameBoardArray[down_from1+1][across_from1] == 'p'){
        if(directionalDifferenceXAxis == 1) {
            if (directionalDifferenceYAxis == -1) {
                return numberArray;
            }
        }
    }

    if(directionalDifferenceYAxis == 0 && directionalDifferenceXAxis == 1){
        if(GameBoardArray[down_to1][across_to1] == '_'){
            firstMove = false;
            return numberArray;
        }
    }

    if(directionalDifferenceXAxis == 2 && firstMove){
        firstMove = false;
        return numberArray;
    }

    return nullptr;
}

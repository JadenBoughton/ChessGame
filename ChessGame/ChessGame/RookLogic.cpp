//
// Created by Jaden Boughton on 8/17/24.
//

#include <iostream>
#include "RookLogic.h"
#include "GamePiecesLogic.h"
using namespace std;

int* RookLogic::moveLogic(string move, char (*GameBoardArray)[8], int row) {
    if(move.length() != 5){return nullptr;}
    if(move.at(2) != '-'){return nullptr;}

    int* numberArray = moveConverter(move);

    int across_from = *numberArray;
    numberArray++;
    int down_from = *numberArray;
    numberArray++;
    int across_to = *numberArray;
    numberArray++;
    int down_to = *numberArray;

    int directionalDifferenceXAxis = across_from-across_to;
    int directionalDifferenceYAxis = down_from-down_to;

    if(down_from > 7 || down_from < 0){
        return nullptr;
    }
    else if(down_to > 7 || down_to < 0){
        return nullptr;
    }
    else if(across_from > 7 || across_from < 0){
        return nullptr;
    }
    else if(across_to > 7 || across_to < 0){
        return nullptr;
    }

    int absoluteX = abs(directionalDifferenceXAxis);
    int absoluteY = abs(directionalDifferenceYAxis);

    if(absoluteX == 0 && absoluteY == 0){return nullptr;}
    if(absoluteX != 0 && absoluteY != 0){return nullptr;}

    int distanceFromStartToFinish = absoluteX + absoluteY;

    //int directionX = absoluteX/directionalDifferenceXAxis;
    //int directionY = absoluteY/directionalDifferenceYAxis;

    for(int i = 0; i < distanceFromStartToFinish; i++){
        if(GameBoardArray[across_from-directionalDifferenceXAxis][down_from-directionalDifferenceYAxis] != '_'){
            return nullptr;
        }
    }

    return numberArray;
}

void RookLogic::testKingCheck(char (*GameBoardArray)[8], int x, int y) {
    int xCopy = x;
    int yCopy = y;

    yCopy++;
    while(yCopy < 8){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x'){
            GameBoardArray[xCopy][yCopy] = 'x';
            yCopy++;
        }else{break;}
    }

    yCopy = y;

    yCopy--;
    while(yCopy > 0){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x'){
            GameBoardArray[xCopy][yCopy] = 'x';
            yCopy--;
        }else{break;}
    }

    xCopy = x;
    yCopy = y;

    xCopy++;
    while(xCopy < 8){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x'){
            GameBoardArray[xCopy][yCopy] = 'x';
            xCopy++;
        }else{break;}
    }

    xCopy = x;

    xCopy--;
    while(xCopy > 0){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x'){
            GameBoardArray[xCopy][yCopy] = 'x';
            xCopy--;
        }else{break;}
    }
}
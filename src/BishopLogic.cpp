//
// Created by Jaden Boughton on 8/18/24.
//
#include <iostream>
#include "BishopLogic.h"
#include "GamePiecesLogic.h"
using namespace std;

int* BishopLogic::moveLogic(string move, char (*GameBoardArray)[8], int row) {
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

    if(absoluteX != absoluteY || absoluteX == 0 || absoluteY == 0){
        return nullptr;
    }

    int distanceFromStartToFinish = absoluteX * absoluteY;

    int directionX = absoluteX/directionalDifferenceXAxis;
    int directionY = absoluteY/directionalDifferenceYAxis;

    for(int i = 0; i < distanceFromStartToFinish; i++){
        if(GameBoardArray[across_from-directionX][down_from-directionY] != '_'){
            return nullptr;
        }
    }

    return numberArray;

}

void BishopLogic::testKingCheck(char (*GameBoardArray)[8], int x, int y) {
    int xCopy = x;
    int yCopy = y;

    xCopy--;
    yCopy++;
    while(xCopy > 0 || yCopy < 8){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x') {
            GameBoardArray[xCopy][yCopy] = 'x';
            xCopy--;
            yCopy++;
        }else{break;}
    }

    xCopy = x;
    yCopy = y;

    xCopy++;
    yCopy++;
    while(xCopy < 8 || yCopy < 8){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x') {
            GameBoardArray[xCopy][yCopy] = 'x';
            xCopy++;
            yCopy++;
        }else{break;}
    }

    //if(GameBoardArray[xCopy][yCopy] == '_') {
    //}else{break;}

    xCopy = x;
    yCopy = y;

    xCopy++;
    yCopy--;
    while(xCopy < 8 || yCopy > 0){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x') {
            GameBoardArray[xCopy][yCopy] = 'x';
            xCopy++;
            yCopy--;
        }else{break;}
    }

    xCopy = x;
    yCopy = y;

    xCopy--;
    yCopy--;
    while(xCopy > 0 || yCopy > 0){
        if(GameBoardArray[xCopy][yCopy] == '_' || GameBoardArray[xCopy][yCopy] == 'x') {
            GameBoardArray[xCopy][yCopy] = 'x';
            xCopy--;
            yCopy--;
        }else{break;}
    }

}
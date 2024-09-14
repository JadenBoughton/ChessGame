//
// Created by Jaden Boughton on 8/13/24.
//

#include <iostream>
#include "KnightLogic.h"
#include "GamePiecesLogic.h"
using namespace std;

int* KnightLogic::moveLogic(std::string move, char (*GameBoardArray)[8], int row) {
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

    if(absoluteX == 2 && absoluteY == 1){
        if(direction == '+' &&
           GameBoardArray[across_to][down_to] != 'w' &&
           GameBoardArray[across_to][down_to] != 'W'){
            firstMove = false;
            return numberArray;
        }
        else if(direction == '-' &&
                GameBoardArray[across_to][down_to] != 'b' &&
                GameBoardArray[across_to][down_to] != 'B'){
            firstMove = false;
            return numberArray;
        }
    }else if(absoluteX == 1 && absoluteY == 2){
        if(direction == '+' &&
           GameBoardArray[across_to][down_to] != 'w' &&
           GameBoardArray[across_to][down_to] != 'W'){
            firstMove = false;
            return numberArray;
        }
        else if(direction == '-' &&
                GameBoardArray[across_to][down_to] != 'b' &&
                GameBoardArray[across_to][down_to] != 'B'){
            firstMove = false;
            return numberArray;
        }
    }
    return nullptr;
}

void KnightLogic::testKingCheck(char (*GameBoardArray)[8], int x, int y) {


    if(x > 1 && y < 7){
        if(GameBoardArray[x-2][y+1] == '_'){
            GameBoardArray[x-2][y+1] = 'x';
        }
    }

    if(x > 0 && y < 6){
        if(GameBoardArray[x-1][y+2] == '_'){
            GameBoardArray[x-1][y+2] = 'x';
        }
    }

    if(x < 6 && y < 7){
        if(GameBoardArray[x+2][y+1] == '_'){
            GameBoardArray[x+2][y+1] = 'x';
        }
    }

    if(x < 7 && y < 6){
        if(GameBoardArray[x+1][y+2] == '_'){
            GameBoardArray[x+1][y+2] = 'x';
        }
    }


    if(x > 1 && y > 0){
        if(GameBoardArray[x-2][y-1] == '_'){
            GameBoardArray[x-2][y-1] = 'x';
        }
    }

    if(x > 0 && y > 1){
        if(GameBoardArray[x-1][y-2] == '_'){
            GameBoardArray[x-1][y-2] = 'x';
        }
    }

    if(x < 6 && y > 0){
        if(GameBoardArray[x+2][y-1] == '_'){
            GameBoardArray[x+2][y-1] = 'x';
        }
    }

    if(x < 7 && y > 1){
        if(GameBoardArray[x+1][y-2] == '_'){
            GameBoardArray[x+1][y-2] = 'x';
        }
    }
}
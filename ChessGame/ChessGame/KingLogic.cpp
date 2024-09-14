//
// Created by Jaden Boughton on 8/17/24.
//

#include <iostream>
#include "KingLogic.h"
#include "GamePiecesLogic.h"
#include "QueenLogic.h"
#include "BishopLogic.h"
#include "RookLogic.h"
#include "PawnLogic.h"
#include "KnightLogic.h"
using namespace std;

int* KingLogic::moveLogic(string move, char (*GameBoardArray)[8], int row) {
    /*
    TODO: creating the logic for determining whether the king's move
     will put it in check should be part of the main game class
     because it will need to access multiple arrays
     Alternative solution: create a function that shows the path of the
     opposing side's pieces to determine which king's move will put it in
     check
     */

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

    if(absoluteX == 1 && absoluteY == 1){
        firstMove = false;
        return numberArray;
    }

    if(absoluteX == 2 && firstMove){
        firstMove = false;
        Castling = true;
        return numberArray;
    }

    return nullptr;
}

/* GameBoardArray
 * Current location
 * Where it will be moved
 *
 *
 * */

int* KingLogic::testIfInCheck(GamePiecesLogic *LogicArray[][8], char blackAndWhite[][8], int *locationList) {
    int across_from = *locationList;
    locationList++;
    int down_from = *locationList;
    locationList++;
    int across_to = *locationList;
    locationList++;
    int down_to = *locationList;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(LogicArray[i][j]->getSymbol() != '_' && LogicArray[i][j]->getSymbol() != getSymbol()){
                LogicArray[i][j]->testKingCheck(blackAndWhite, across_from, down_from);
            }
        }
    }

    /*TODO: if the black and white array does not save,
     * the array needs to be returned
     * */

    char moveTo = blackAndWhite[across_to][down_to];

    if (getDirection() == '+') {
        if (across_from - across_to == -2) {
            if (blackAndWhite[0][6] == '_' && blackAndWhite[0][5] == '_') {
                return locationList;
            }
        }
        if (across_from - across_to == 2) {
            if (blackAndWhite[0][2] == '_' && blackAndWhite[0][3] == '_') {
                return locationList;
            }
        }
    }else if(getDirection() == '-'){
        if (across_from - across_to == -2) {
            if (blackAndWhite[7][6] == '_' && blackAndWhite[7][5] == '_') {
                return locationList;
            }
        }
        if (across_from - across_to == 2) {
            if (blackAndWhite[7][2] == '_' && blackAndWhite[7][3] == '_') {
                return locationList;
            }
        }
    }

    if(moveTo != 'x' && moveTo != (getSymbol()+32)){
        return locationList;
    }

    return nullptr;
}
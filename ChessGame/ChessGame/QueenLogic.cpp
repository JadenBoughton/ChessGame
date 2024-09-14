//
// Created by Jaden Boughton on 8/18/24.
//

#include <iostream>
#include "QueenLogic.h"
//#include "RookLogic.h"
//#include "BishopLogic.h"
//#include "GamePiecesLogic.h"
using namespace std;

int* QueenLogic::moveLogic(string move, char (*GameBoardArray)[8], int row) {
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

    if(directionalDifferenceXAxis == 0 || directionalDifferenceYAxis == 0){
        return rook->moveLogic(move, GameBoardArray, row);
    }else if(directionalDifferenceXAxis == directionalDifferenceYAxis){
        return bishop->moveLogic(move, GameBoardArray, row);
    }
    return nullptr;

}

void QueenLogic::testKingCheck(char (*GameBoardArray)[8], int x, int y) {

    rook->testKingCheck(GameBoardArray, x, y);
    bishop->testKingCheck(GameBoardArray, x, y);
}
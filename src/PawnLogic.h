//
// Created by Jaden Boughton on 8/8/24.
//

#ifndef _PAWNLOGIC_H
#define _PAWNLOGIC_H


#include "GamePiecesLogic.h"

class PawnLogic : public GamePiecesLogic{
public:
    PawnLogic(char direction, char symbol) : GamePiecesLogic(direction, symbol) {};

    int* moveLogic(string move, char GameBoardArray[][8], int row) override;
    void testKingCheck(char GameBoardArray[][8], int x, int y) override;
    int* forward(int* numberArray, char GameBoardArray[][8], int row);
    int* backward(int* numberArray, char GameBoardArray[][8], int row);
};



#endif //_PAWNLOGIC_H
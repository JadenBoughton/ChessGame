//
// Created by Jaden Boughton on 8/13/24.
//

#ifndef UNTITLED1_KNIGHTLOGIC_H
#define UNTITLED1_KNIGHTLOGIC_H

#include "GamePiecesLogic.h"

class KnightLogic : public GamePiecesLogic {

public:
    KnightLogic(char direction, char symbol) : GamePiecesLogic(direction, symbol) {};

    int* moveLogic(string move, char GameBoardArray[][8], int row) override;

    void testKingCheck(char GameBoardArray[][8], int x, int y) override;
};



#endif //UNTITLED1_KNIGHTLOGIC_H

//
// Created by Jaden Boughton on 8/18/24.
//

#ifndef UNTITLED1_BISHOPLOGIC_H
#define UNTITLED1_BISHOPLOGIC_H

#include "GamePiecesLogic.h"

class BishopLogic : public GamePiecesLogic {

public:
    BishopLogic(char direction, char symbol) : GamePiecesLogic(direction, symbol) {};

    int* moveLogic(string move, char GameBoardArray[][8], int row) override;

    void testKingCheck(char GameBoardArray[][8], int x, int y) override;
};

#endif //UNTITLED1_BISHOPLOGIC_H

//
// Created by Jaden Boughton on 8/17/24.
//

#ifndef UNTITLED1_ROOKLOGIC_H
#define UNTITLED1_ROOKLOGIC_H

#include "GamePiecesLogic.h"

class RookLogic : public GamePiecesLogic {
public:
    RookLogic(char direction, char symbol) : GamePiecesLogic(direction, symbol) {};

    int* moveLogic(string move, char GameBoardArray[][8], int row) override;

    void testKingCheck(char GameBoardArray[][8], int x, int y) override;
};

#endif //UNTITLED1_ROOKLOGIC_H

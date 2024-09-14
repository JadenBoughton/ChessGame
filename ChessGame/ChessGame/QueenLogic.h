//
// Created by Jaden Boughton on 8/18/24.
//

#ifndef UNTITLED1_QUEENLOGIC_H
#define UNTITLED1_QUEENLOGIC_H

#include "GamePiecesLogic.h"
#include "RookLogic.h"
#include "BishopLogic.h"

class QueenLogic : public GamePiecesLogic {

protected:
    GamePiecesLogic *rook = new RookLogic(direction, symbol);
    GamePiecesLogic *bishop = new BishopLogic(direction, symbol);

public:
    QueenLogic(char direction, char symbol) : GamePiecesLogic(direction, symbol) {};

    int* moveLogic(string move, char GameBoardArray[][8], int row) override;

    void testKingCheck(char GameBoardArray[][8], int x, int y) override;
};

#endif //UNTITLED1_QUEENLOGIC_H

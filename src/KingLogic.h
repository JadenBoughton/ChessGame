//
// Created by Jaden Boughton on 8/17/24.
//

#ifndef UNTITLED1_KINGLOGIC_H
#define UNTITLED1_KINGLOGIC_H

#include "GamePiecesLogic.h"

class KingLogic : public GamePiecesLogic {

public:
    KingLogic(char direction, char symbol) : GamePiecesLogic(direction, symbol) {};

    int* moveLogic(string move, char GameBoardArray[][8], int row) override;

    int* testIfInCheck(GamePiecesLogic *GameBoardArray[][8], char blackAndWhite[][8], int locationList[4]) override;
};


#endif //UNTITLED1_KINGLOGIC_H

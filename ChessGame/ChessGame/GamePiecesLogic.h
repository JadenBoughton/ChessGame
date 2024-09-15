#ifndef _GAMEPIECESLOGIC_H
#define _GAMEPIECESLOGIC_H

#include <iostream>
#include <string>
using namespace std;

class GamePiecesLogic{

protected:
    char direction;
    char symbol;
    bool firstMove;

public:
    GamePiecesLogic(char direction, char symbol);

    virtual int* moveLogic(string move, char gameBoardArray[][8], int row);
    virtual void testKingCheck(char gameBoardArray[][8], int x, int y);
    virtual int* testIfInCheck(GamePiecesLogic *GameBoardArray[][8], char gameBoardArray[][8], int locationList[4]);
    static int* moveConverter(string move);
    static int characterConversion(char letter);
    char getSymbol() const;
    char getDirection() const;
    bool Castling;
};

#endif //_GAMEPIECESLOGIC_H
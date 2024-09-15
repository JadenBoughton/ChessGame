//
// Created by Jaden Boughton on 8/8/24.
//

#include <iostream>
#include "GamePiecesLogic.h"
#include <sstream>
using namespace std;


GamePiecesLogic::GamePiecesLogic(char pieceDirection, char thisSymbol)
{
    direction = pieceDirection;
    firstMove = true;
    symbol = thisSymbol;
    Castling = false;
}

int* GamePiecesLogic::moveLogic(string move, char GameBoardArray[][8], int row)
{
    cout<<"TODO: write logic for individuals pieces"<<endl;
    return nullptr;
}

int* GamePiecesLogic::testIfInCheck(GamePiecesLogic *GameBoardArray[][8], char blackAndWhite[][8], int *locationList) {
    cout<<"TODO: write the logic"<<endl;
    return nullptr;
}

void GamePiecesLogic::testKingCheck(char (*gameBoardArray)[8], int x, int y) {
    cout<<"TODO: write logic to show path of each piece to see if the king will go into check."<<endl;
}

int* GamePiecesLogic::moveConverter(string move) {
    char across_from = move.at(0);
    char down_from = move.at(1);
    char across_to = move.at(3);
    char down_to = move.at(4);

    int across_from1 = GamePiecesLogic::characterConversion(across_from)-1;
    stringstream convert;
    convert << down_from;
    int down_from1 = stoi(convert.str())-1;
    convert.clear();
    int across_to1 = GamePiecesLogic::characterConversion(across_to)-1;
    convert << down_to;
    int down_to1 = stoi(convert.str())-1;

    int moveArray[] = {across_from1, down_from1, across_to1, down_to1};
    return &moveArray[0];

}

int GamePiecesLogic::characterConversion(char letter)
{
    switch (letter) {
        case 'a': return 1;
        case 'b': return 2;
        case 'c': return 3;
        case 'd': return 4;
        case 'e': return 5;
        case 'f': return 6;
        case 'g': return 7;
        case 'h': return 8;
        default: return 9;
    }


}

char GamePiecesLogic::getSymbol() const {return symbol;}
char GamePiecesLogic::getDirection() const {return direction;}
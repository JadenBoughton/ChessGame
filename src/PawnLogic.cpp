//
// Created by Jaden Boughton on 8/8/24.
//

#include <iostream>
#include "PawnLogic.h"
#include "GamePiecesLogic.h"
using namespace std;

int* PawnLogic::moveLogic(string move, char GameBoardArray[][8], int row)
{
    /*
     --this may not work--
     Look into other passing methods for getting
     the 2D array into the functionality while
     still maintaining a strong abstraction.
     */

    if(move.length() != 5){return nullptr;}
    if(move.at(2) != '-'){return nullptr;}

    int* numberArray = moveConverter(move);

    if(GamePiecesLogic::direction == '+'){
        return forward(numberArray, GameBoardArray, row);
    }else{
        return backward(numberArray, GameBoardArray, row);
    }
}

int* PawnLogic::forward(int *numberArray, char GameBoardArray[][8], int row)
{
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

    if(GameBoardArray[across_to][down_to] == 'b' || GameBoardArray[across_to][down_to] == 'B') {
        if (directionalDifferenceYAxis == -1) {
            if (across_from < 7 && directionalDifferenceXAxis == 1){
                firstMove = false;
                return numberArray;
            }
            else if (across_from > 0 && directionalDifferenceXAxis == -1){
                firstMove = false;
                return numberArray;
            }
        }
    }

    if(across_from > 0 && GameBoardArray[across_from-1][down_from] == 'l'){
        if(directionalDifferenceYAxis == -1){
            if(directionalDifferenceXAxis == 1){
                return numberArray;
            }

        }
    }

    if(across_from < 7 && GameBoardArray[across_from+1][down_from] == 'l'){
        if(directionalDifferenceYAxis == -1) {
            if (directionalDifferenceXAxis == -1) {
                firstMove = false;
                return numberArray;
            }
        }
    }

    if(directionalDifferenceXAxis == 0 && directionalDifferenceYAxis == -1){
        if(GameBoardArray[across_to][down_to] == '_'){
            firstMove = false;
            return numberArray;
        }
    }

    if(directionalDifferenceYAxis == -2 && firstMove){
        firstMove = false;
        return numberArray;
    }

    return nullptr;
}

int* PawnLogic::backward(int *numberArray, char GameBoardArray[][8], int row)
{
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
    }else if(down_to > 7 || down_to < 0){
        return nullptr;
    }else if(across_from > 7 || across_from < 0){
        return nullptr;
    }else if(across_to > 7 || across_to < 0){
        return nullptr;
    }

    if(GameBoardArray[across_to][down_to] == 'w' || GameBoardArray[across_to][down_to] == 'W') {
        if (directionalDifferenceYAxis == 1) {
            if (across_from < 7 && directionalDifferenceXAxis == 1){
                firstMove = false;
                return numberArray;
            }
            else if (across_from > 0 && directionalDifferenceXAxis == -1){
                firstMove = false;
                return numberArray;
            }
        }
    }

    if(across_from > 0 && GameBoardArray[across_from-1][down_from] == 'p'){
        if(directionalDifferenceYAxis == 1){
            if(directionalDifferenceXAxis == 1){
                return numberArray;
            }

        }
    }

    if(across_from < 7 && GameBoardArray[across_from+1][down_from] == 'p'){
        if(directionalDifferenceYAxis == 1) {
            if (directionalDifferenceXAxis == -1) {
                return numberArray;
            }
        }
    }

    if(directionalDifferenceXAxis == 0 && directionalDifferenceYAxis == 1){
        if(GameBoardArray[across_to][down_to] == '_'){
            firstMove = false;
            return numberArray;
        }
    }

    if(directionalDifferenceYAxis == 2 && firstMove){
        firstMove = false;
        return numberArray;
    }

    return nullptr;
}

void PawnLogic::testKingCheck(char (*GameBoardArray)[8], int x, int y) {
    if(direction == '+'){
        if(GameBoardArray[x-1][y+1] == '_' && x > 0 && y < 8){
            GameBoardArray[x-1][y+1] = 'x';
        }
        if(GameBoardArray[x+1][y+1] == '_' && x < 8 && y < 8){
            GameBoardArray[x+1][y+1] = 'x';
        }
    }else{
        if(GameBoardArray[x-1][y-1] == '_' && x > 0 && y > 0){
            GameBoardArray[x-1][y-1] = 'x';
        }
        if(GameBoardArray[x+1][y-1] == '_' && x < 8 && y > 0){
            GameBoardArray[x+1][y-1] = 'x';
        }
    }
}

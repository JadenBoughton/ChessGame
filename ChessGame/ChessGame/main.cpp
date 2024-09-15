#include <iostream>
#include "GamePiecesLogic.h"
#include "PawnLogic.h"
#include "RookLogic.h"
#include "BishopLogic.h"
#include "KnightLogic.h"
#include "QueenLogic.h"
#include "KingLogic.h"
#include <stack>
#include <sstream>

using namespace std;

void processInput(char response);
void gameLoop();
void startGamePvPWhite();
void startGamePvPBlack();
void printBoard();
int characterConversion(char letter);
bool additionalKingLogicForward(int *numArray);
bool additionalKingLogicBackward(int *numArray);
void executeMove(int *numArray);


bool endProgram = false;

bool gameWon = false;

stack<int> pawnCoordinates;

GamePiecesLogic *LogicArray[8][8] =
        {{new RookLogic('+', 'R'), new KnightLogic('+', 'N'),
          new BishopLogic('+', 'B'), new QueenLogic('+', 'Q'),
          new KingLogic('+', 'K'), new BishopLogic('+', 'B'),
          new KnightLogic('+', 'N'), new RookLogic('+', 'R')},

         {new PawnLogic('+', 'P'), new PawnLogic('+', 'P'),
          new PawnLogic('+', 'P'), new PawnLogic('+', 'P'),
          new PawnLogic('+', 'P'), new PawnLogic('+', 'P'),
          new PawnLogic('+', 'P'), new PawnLogic('+', 'P')},

         {new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_')},

         {new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_')},

         {new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_')},

         {new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_'),
          new GamePiecesLogic('_', '_'), new GamePiecesLogic('_', '_')},

         {new PawnLogic('-', 'p'), new PawnLogic('-', 'p'),
          new PawnLogic('-', 'p'), new PawnLogic('-', 'p'),
          new PawnLogic('-', 'p'), new PawnLogic('-', 'p'),
          new PawnLogic('-', 'p'), new PawnLogic('-', 'p')},

         {new RookLogic('-', 'r'), new KnightLogic('-', 'n'),
          new BishopLogic('-', 'b'), new QueenLogic('-', 'q'),
          new KingLogic('-', 'k'), new BishopLogic('-', 'b'),
          new KnightLogic('-', 'n'), new RookLogic('-', 'r')},
        };

char blackAndWhite[8][8] = {{'w', 'w', 'w', 'w', 'W', 'w', 'w', 'w'},
                            {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
                            {'_', '_', '_', '_', '_', '_', '_', '_'},
                            {'_', '_', '_', '_', '_', '_', '_', '_'},
                            {'_', '_', '_', '_', '_', '_', '_', '_'},
                            {'_', '_', '_', '_', '_', '_', '_', '_'},
                            {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
                            {'b', 'b', 'b', 'b', 'B', 'b', 'b', 'b'}};

/*char typeOfPieces[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                           {'_', '_', '_', '_', '_', '_', '_', '_'},
                           {'_', '_', '_', '_', '_', '_', '_', '_'},
                           {'_', '_', '_', '_', '_', '_', '_', '_'},
                           {'_', '_', '_', '_', '_', '_', '_', '_'},
                           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                           {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};*/

int main() {
    char response;
    while (!endProgram) {
        cout << "Welcome to Chess! \n";
        cout << "What would you like to do? \n";
        cout << "\t p: play PvP game without logging in\n";
        cout << "\t e: exit program\n";
        //cout << "\t l: login"; TODO: implement login w/ mySQL

        cin >> response;
        cin.ignore();
        processInput(response);
    }

    return 0;
}

void processInput(char response){
    switch (response) {
        case 'p':
            gameLoop();
        case 'e':
            endProgram = true;
        default:
            cout << "That's not one of the options";
    }
}

void gameLoop(){
    bool endGame = false;
    while(!endGame) {
        startGamePvPWhite();
        startGamePvPBlack();
        if(gameWon){endGame = true;}
    }
}

void startGamePvPBlack() {
    bool correctMove = false;
    int *numArray;
    while (!correctMove) {
        printBoard();
        string move;

        cout << "Enter your move:\n For example c2-c4" << endl;
        cin >> move;

        char across = move.at(0);
        char down = move.at(1);

        int across1 = characterConversion(across) - 1;
        stringstream convert;
        convert<<down;
        int down1 = stoi(convert.str()) - 1;

        if (across1 < 7 && across1 > 0 && down1 < 7 && down1 > 0 && LogicArray[across1][down1]->getSymbol() != '_') {
            if(LogicArray[across1][down1]->getDirection() == '-') {
                numArray = LogicArray[across1][down1]->moveLogic(move, blackAndWhite, 8);

                if(numArray != nullptr && LogicArray[across1][down1]->getSymbol() == 'k'){
                    numArray--;
                    numArray--;
                    numArray--;
                    numArray = LogicArray[across1][down1]->testIfInCheck(LogicArray, blackAndWhite, numArray);

                    if(LogicArray[across1][down1]->Castling){
                        bool ifPossible = additionalKingLogicBackward(numArray);
                        LogicArray[across1][down1]->Castling = false;

                        if(!ifPossible){
                            numArray = nullptr;
                        }
                    }
                }
            }
        }

        if(numArray != nullptr) {
            numArray--;
            numArray--;
            numArray--;

            /*if(LogicArray[across1][down1]->getSymbol() == 'K') {
                if(additionalKingLogic(numArray)){correctMove = true;}
            }else {
                correctMove = true;
                executeMove(numArray);
            }*/

            correctMove = true;
            executeMove(numArray);

        }else{cout<<"Your input does not fit the parameters of the game."<<endl;}
    }
}

void startGamePvPWhite() {
    bool correctMove = false;
    int *numArray;
    while (!correctMove) {
        printBoard();
        string move;

        cout << "Enter your move:\n For example c2-c4" << endl;
        cin >> move;

        char across = move.at(0);
        char down = move.at(1);

        int across1 = characterConversion(across) - 1;
        stringstream convert;
        convert<<down;
        int down1 = stoi(convert.str()) - 1;

        if (across1 < 8 && across1 > -1 && down1 < 8 && down1 > -1 && LogicArray[across1][down1]->getSymbol() != '_') {
            if(LogicArray[across1][down1]->getDirection() == '+') {
                numArray = LogicArray[across1][down1]->moveLogic(move, blackAndWhite, 8);

                if(numArray != nullptr && LogicArray[across1][down1]->getSymbol() == 'K'){
                    numArray--;
                    numArray--;
                    numArray--;
                    numArray = LogicArray[across1][down1]->testIfInCheck(LogicArray, blackAndWhite, numArray);

                    if(LogicArray[across1][down1]->Castling){
                        bool ifPossible = additionalKingLogicForward(numArray);
                        LogicArray[across1][down1]->Castling = false;

                        if(!ifPossible){
                            numArray = nullptr;
                        }
                    }
                }
            }
        }

        if(numArray != nullptr) {
            numArray--;
            numArray--;
            numArray--;

            /*if(LogicArray[across1][down1]->getSymbol() == 'K') {
                if(additionalKingLogic(numArray)){correctMove = true;}
            }else {
                correctMove = true;
                executeMove(numArray);
            }*/

            correctMove = true;
            executeMove(numArray);

        }else{cout<<"Your input does not fit the parameters of the game."<<endl;}
    }
}

bool additionalKingLogicForward(int *numArray){
    //TODO
    int across_from = *numArray;
    numArray++;
    int down_from = *numArray;
    numArray++;
    int across_to = *numArray;
    numArray++;
    int down_to = *numArray;

    numArray--;
    numArray--;
    numArray--;

    int difference = across_from - across_to;

    numArray = LogicArray[0][4]->testIfInCheck(LogicArray, blackAndWhite, numArray);

    if(numArray != nullptr) {
        if (difference == -2 && blackAndWhite[0][5] == '_' && blackAndWhite[0][6] == '_'
            && LogicArray[0][7]->getSymbol() == 'R' && LogicArray[0][7]->Castling) {

            GamePiecesLogic *temp = LogicArray[0][4];
            LogicArray[0][4] = LogicArray[0][6];
            LogicArray[0][6] = temp;

            blackAndWhite[0][4] = '_';
            blackAndWhite[0][6] = 'W';

            GamePiecesLogic *temp2 = LogicArray[0][7];
            LogicArray[0][7] = LogicArray[0][5];
            LogicArray[0][5] = temp2;

            blackAndWhite[0][7] = '_';
            blackAndWhite[0][5] = 'w';
            return true;
        }else if (difference == 2 && blackAndWhite[0][2] == '_' && blackAndWhite[0][3] == '_'
            && LogicArray[0][7]->getSymbol() == 'R' && LogicArray[0][0]->Castling){

            GamePiecesLogic *temp = LogicArray[0][4];
            LogicArray[0][4] = LogicArray[0][2];
            LogicArray[0][2] = temp;

            blackAndWhite[0][4] = '_';
            blackAndWhite[0][2] = 'W';

            GamePiecesLogic *temp2 = LogicArray[0][0];
            LogicArray[0][0] = LogicArray[0][3];
            LogicArray[0][3] = temp2;

            blackAndWhite[0][0] = '_';
            blackAndWhite[0][3] = 'w';
            return true;
        }
    }

    return false;
}

bool additionalKingLogicBackward(int *numArray){
    int across_from = *numArray;
    numArray++;
    int down_from = *numArray;
    numArray++;
    int across_to = *numArray;
    numArray++;
    int down_to = *numArray;

    numArray--;
    numArray--;
    numArray--;

    int difference = across_from - across_to;

    numArray = LogicArray[7][4]->testIfInCheck(LogicArray, blackAndWhite, numArray);

    if(numArray != nullptr) {
        if (difference == -2 && blackAndWhite[7][5] == '_' && blackAndWhite[7][6] == '_'
            && LogicArray[7][7]->getSymbol() == 'r' && LogicArray[7][7]->Castling) {

            GamePiecesLogic *temp = LogicArray[7][4];
            LogicArray[7][4] = LogicArray[7][6];
            LogicArray[7][6] = temp;

            blackAndWhite[7][4] = '_';
            blackAndWhite[7][6] = 'B';

            GamePiecesLogic *temp2 = LogicArray[7][7];
            LogicArray[7][7] = LogicArray[7][5];
            LogicArray[7][5] = temp2;

            blackAndWhite[7][7] = '_';
            blackAndWhite[7][5] = 'b';
            return true;
        }else if (difference == 2 && blackAndWhite[7][2] == '_' && blackAndWhite[7][3] == '_'
                  && LogicArray[0][7]->getSymbol() == 'r' && LogicArray[0][0]->Castling){

            GamePiecesLogic *temp = LogicArray[7][4];
            LogicArray[7][4] = LogicArray[7][2];
            LogicArray[7][2] = temp;

            blackAndWhite[7][4] = '_';
            blackAndWhite[7][2] = 'W';

            GamePiecesLogic *temp2 = LogicArray[7][0];
            LogicArray[7][0] = LogicArray[7][3];
            LogicArray[7][3] = temp2;

            blackAndWhite[7][0] = '_';
            blackAndWhite[7][3] = 'w';
            return true;
        }
    }
    return false;
}

void executeMove(int *numArray){
    int across_from = *numArray;
    numArray++;
    int down_from = *numArray;
    numArray++;
    int across_to = *numArray;
    numArray++;
    int down_to = *numArray;

    GamePiecesLogic* temp = LogicArray[across_to][down_to];
    LogicArray[across_to][down_to] = LogicArray[across_from][down_from];
    LogicArray[across_from][down_from] = temp;

    blackAndWhite[across_to][down_to] = blackAndWhite[across_from][down_from];
    blackAndWhite[across_from][down_from] = '_';

    if(!pawnCoordinates.empty()){
        int tempAcross = pawnCoordinates.top();
        int tempDown = pawnCoordinates.top();

        if(blackAndWhite[tempAcross][tempDown] == 'p'){
            blackAndWhite[tempAcross][tempDown] = 'w';
        }else if(blackAndWhite[tempAcross][tempDown] == 'l'){
            blackAndWhite[tempAcross][tempDown] = 'b';
        }
    }


    if(abs(down_from - down_to) == 2 && across_from - across_to == 0) {
        if (LogicArray[across_to][down_to]->getSymbol() == 'P') {
            blackAndWhite[across_to][down_to] = 'p';
            pawnCoordinates.push(down_to);
            pawnCoordinates.push(across_to);
        } else if (LogicArray[across_to][down_to]->getSymbol() == 'p') {
            blackAndWhite[across_to][down_to] = 'l';
            pawnCoordinates.push(down_to);
            pawnCoordinates.push(across_to);
        }
    }




}

int characterConversion(char letter)
{
    switch (letter) {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        default: return 9;
    }


}



void printBoard(){
    string board;
    int num = 8;
    for(int i = 7; i >= 0; i--){
        stringstream convert;
        convert<<num--;
        board += convert.str();
        for(int j = 0; j < 8; j++){
            board += "|";
            board.push_back(LogicArray[i][j]->getSymbol());
        }
        board += "|\n";
    }
    board += "  a b c d e f g h";


    cout << board << endl;
}
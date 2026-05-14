#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Player.h"
using namespace std;

Player::Player(char c) : color(c) {
    assert(c == 'w' || c == 'b'); // Ensure color is valid
}

int* Player::moveConverter(string move)
{
    if(move.length() != 5) {
        return nullptr;
    }
    if(move.at(2) != '-') {
        return nullptr;
    }

    int across_from = characterConversion(move.at(0)) - 1;
    int down_from = move.at(1) - '1';
    int across_to = characterConversion(move.at(3)) - 1;
    int down_to = move.at(4) - '1';

    static int moveArray[4];
    moveArray[0] = across_from;
    moveArray[1] = down_from;
    moveArray[2] = across_to;
    moveArray[3] = down_to;

    return moveArray;
}

int Player::characterConversion(char letter)
{
    if (letter >= 'a' && letter <= 'h') {
        return letter - 'a' + 1; // Convert 'a'-'h' to 1-8
    }
    return 0; // Invalid character
}

int* Player::getMove() {
    // This function should be overridden in derived classes
    // It is a placeholder here to satisfy the interface
    return nullptr;
}


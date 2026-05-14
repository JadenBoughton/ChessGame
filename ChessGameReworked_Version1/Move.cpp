#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>

#include "Move.h"
using namespace std;


int* Move::inputMove(string move)
{
	if(move.length() != 5){return nullptr;}
    if(move.at(2) != '-'){return nullptr;}

    int* numberArray = moveConverter(move);
}

int* Move::moveConverter(string move)
{
    char across_from = move.at(0);
    char down_from = move.at(1);
    char across_to = move.at(3);
    char down_to = move.at(4);

    int across_from1 = characterConversion(across_from)-1;
    stringstream convert;
    convert << down_from;
    int down_from1 = stoi(convert.str())-1;
    convert.clear();
    int across_to1 = characterConversion(across_to)-1;
    convert << down_to;
    int down_to1 = stoi(convert.str())-1;

    int moveArray[] = {across_from1, down_from1, across_to1, down_to1};
    return &moveArray[0];}

int Move::characterConversion(char letter)
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

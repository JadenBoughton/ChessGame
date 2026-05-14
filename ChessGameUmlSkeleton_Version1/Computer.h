#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Player.h"

class Computer : public Player
{
public:
	string generateMove();

};
#endif

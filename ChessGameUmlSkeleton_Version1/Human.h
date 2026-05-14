#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Player.h"

class Human : public Player
{
public:
	string collectInput();

};
#endif

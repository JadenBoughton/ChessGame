#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "__interface__ IObserver.h"
#include "Subject.h"
#include "ChessBoard.h"

class Observer : public __interface__ IObserver
{
private:
	string message_from_subject;

	Subject &subject;

	static int static_number;

	int number;

	ChessBoard chessBoard;

public:
	virtual void Observer()=0;

	void update(string &message_from_subject);

	void removeMeFromTheList();

	void printInfo();

};
#endif

#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "__interface__ ISubject.h"
#include "list.h"
#include "IObserver .h"
#include "ChessBoard.h"
#include "IObserver.h"

class Subject : public __interface__ ISubject
{
private:
	list<IObserver *> list_observer : std:;

	string message;

	ChessBoard chessBoard;

public:
	virtual void Subject()=0;

	void attach(IObserver *observer);

	void detach(IObserver *observer);

	void notify();

};
#endif

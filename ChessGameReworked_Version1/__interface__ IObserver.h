#ifndef <<INTERFACE>> _I_OBSERVER_H
#define <<INTERFACE>> _I_OBSERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class __interface__ IObserver
{
public:
	virtual void IObserver()=0;

	virtual void update(string &message_from_subject)=0;

};
#endif

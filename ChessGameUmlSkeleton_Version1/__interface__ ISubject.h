#ifndef <<INTERFACE>> _I_SUBJECT_H
#define <<INTERFACE>> _I_SUBJECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "IObserver.h"

class __interface__ ISubject
{
public:
	virtual void ISubject()=0;

	virtual void attach(IObserver *observer)=0;

	virtual void detach(IObserver *observer)=0;

	virtual void notify()=0;

};
#endif

#ifndef I_OBSERVER_H
#define I_OBSERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class IObserver
{
    public:
    virtual ~IObserver() = default; // Virtual destructor for proper cleanup
    virtual void update(string &message) = 0; // Pure virtual function to update observer with a message
    virtual void removeMeFromTheList() = 0; // Pure virtual function to remove observer from the subject's list
    virtual void printInfo() const = 0; // Pure virtual function to print observer's information
};
#endif

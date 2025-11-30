#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include <string>
using namespace std;

class MediatorClass;

class People {
protected:
    MediatorClass* mediator;

public:
    People() : mediator(nullptr) {}
    People(const People& other) : mediator(other.mediator) {}
    People(MediatorClass* b) : mediator(b) {}
    ~People() = default;

    virtual string getName() const = 0;
    void setMediator(MediatorClass* a) { mediator = a; }
};

#endif
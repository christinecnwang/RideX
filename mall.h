#ifndef MALL_H
#define MALL_H

#include "destination.h"
#include "sedan.h"
#include "minivan.h"

#include <iostream>
#include <string>

using namespace std;

class Mall : public Destination { //derived class of Destination
public:
    Mall(string str) : Destination(str) {} //constructor
    Sedan hondaCiv{"Honda Civic", 5};
    Minivan dodgeGC{"Dodge Grand Caravan", 7};
};

#endif 
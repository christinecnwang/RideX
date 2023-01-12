#ifndef PARK_H
#define PARK_H

#include "destination.h"
#include "minivan.h"
#include "sedan.h"

#include <iostream>
#include <string>

using namespace std;

class Park : public Destination { //derived class of Destination
public:
    Park(string str) : Destination(str) {} //constructor
    Sedan toyotaCam{"Toyota Camry", 5};
    Minivan hondaOdy{"Honda Odyssey", 8};
};

#endif 
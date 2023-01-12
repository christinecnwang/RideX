#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "destination.h"
#include "sedan.h"
#include "suv.h"

#include <iostream>
#include <string>

using namespace std;

class Restaurant : public Destination { //derived class of Destination
public:
    Restaurant(string str) : Destination(str) {} //constructor
    Sedan teslaM3{"Tesla Model 3", 5};
    SUV toyotaRav{"Toyota RAV4", 5};
};

#endif 
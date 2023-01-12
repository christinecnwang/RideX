#ifndef SEDAN_H
#define SEDAN_H

#include "car.h"

#include <string>

using namespace std;

class Sedan : public Car { //derived class of Car
public:
    Sedan(string str, int num) : Car(str, num) {} //constructor
};

#endif
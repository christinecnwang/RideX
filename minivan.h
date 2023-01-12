#ifndef MINIVAN_H
#define MINIVAN_H

#include "car.h"

#include <string>

using namespace std;

class Minivan : public Car { //derived class of Car
public:
    Minivan(string str, int num) : Car(str, num) {} //constructor
};

#endif
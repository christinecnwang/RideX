#ifndef SUV_H
#define SUV_H

#include "car.h"

#include <string>

using namespace std;

class SUV : public Car { //derived class of Car
public:
    SUV(string str, int num) : Car(str, num) {} //constructor
};

#endif
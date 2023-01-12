#ifndef DESTINATION_H
#define DESTINATION_H

#include <iostream>
#include <string>

using namespace std;

class Destination { //base class
protected:
    string destName;
public:
    Destination(string str) : destName(str) {} //constructor
    string GetName();
};

#endif 
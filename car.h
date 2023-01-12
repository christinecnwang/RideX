#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car { //base class
protected:
    string carName;
    int seats;
public:
    Car(string str, int num) : carName(str), seats(num) {} //constructor
    string GetName();
    int GetSeats(); 
    void FillSeats(int num);
    void FreeSeats(int num);
};

#endif 
#ifndef RESERVATION_H
#define RESERVATION_H

#include "mall.h"
#include "park.h"
#include "restaurant.h"

using namespace std;

class Reservation { //declare new class
    string name, destination, car;
    int passengers;
public:
    Reservation() {choice = 0; choice2 = 0;} //constructor
    ~Reservation() {} //destructor to free memory
    static int resNum; //counts # of reservations
    int choice, choice2; //variables for user input
    void AddRes(Mall &m, Restaurant &r, Park &p);
    void CancelRes(Mall &m, Restaurant &r, Park &p, int num);
    void DisplayRecords(int num);
};

#endif 
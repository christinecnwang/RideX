#include "car.h"

#include <iostream>
#include <string>

using namespace std;

string Car::GetName() {return carName;}

int Car::GetSeats() {return seats;}

void Car::FillSeats(int num) {
  if((seats - num) < 0) {
    //throw exception if car is too full
    throw string("ERROR: Not enough seats available!"); 
  }
  seats -= num;
  cout << "\nSuccess!" << endl;
}

void Car::FreeSeats(int num) {seats += num;}
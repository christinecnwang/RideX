#include "car.h"
#include "destination.h"
#include "mall.h"
#include "minivan.h"
#include "park.h"
#include "reservation.h"
#include "restaurant.h"
#include "sedan.h"
#include "suv.h"

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

//DISPLAY MENU
void Menu() {
    cout << "\n************************* RIDE-SHARING APP MENU *************************\n" << endl;
    cout << "Please use the following command prompts:" << endl;
    cout << "   (0): Exit app" << endl;
    cout << "   (1): Display all rides" << endl;
    cout << "   (2): Make a reservation" << endl;
    cout << "   (3): Cancel a reservation" << endl;
    cout << "   (4): Display past records" << endl;
    cout << "\nEnter your choice: ";
}

//DISPLAY ALL RIDES AND DESTINATIONS
void DisplayAll(Mall &m, Restaurant &r, Park &p) {
    cout << "\n************************* DISPLAYING ALL RIDES **************************\n" << endl;
    cout << "DESTINATION: " << m.GetName() << endl;
    cout << "RIDES AND AVAILABLE SEATS:" << endl;
    cout << "   " << m.hondaCiv.GetName() << ": " << m.hondaCiv.GetSeats() << endl;
    cout << "   " << m.dodgeGC.GetName() << ": " << m.dodgeGC.GetSeats() << endl;

    cout << "\nDESTINATION: " << r.GetName() << endl;
    cout << "RIDES AND AVAILABLE SEATS:" << endl;
    cout << "   " << r.teslaM3.GetName() << ": " << r.teslaM3.GetSeats() << endl;
    cout << "   " << r.toyotaRav.GetName() << ": " << r.toyotaRav.GetSeats() << endl;

    cout << "\nDESTINATION: " << p.GetName() << endl;
    cout << "RIDES AND AVAILABLE SEATS:" << endl;
    cout << "   " << p.toyotaCam.GetName() << ": " << p.toyotaCam.GetSeats()<< endl;
    cout << "   " << p.hondaOdy.GetName() << ": " << p.hondaOdy.GetSeats() << endl;
}

int main() {
    //declare array of pointers
    Reservation *res[35]; //max number of reservations (# of total seats)
    for(int i = 0; i < 35; i++) {
        res[i] = new Reservation(); //create Reservation objects
    }//end for loop

    //create Destination objects
    Mall mall("Toronto Eaton Centre");
    Restaurant restaurant("McDonald's");
    Park park("High Park");

    cout << "Hello! Welcome to our ride-sharing app!" << endl;
    Menu(); //display menu
    int input;
    cin >> input;

    //exits loop if user inputs '0'
    while(input != 0) {
        //check for valid choice (1-4)
        while(input < 1 || input > 4) {
            cout << "ERROR: Invalid choice!" << endl;
            cout << "Enter your choice: ";
            cin >> input;
        }
        if(input == 1) { //display all available rides
            DisplayAll(mall, restaurant, park);
        }
        if(input == 2) { //make a reservation
            try {
                res[Reservation::resNum]->AddRes(mall, restaurant, park);
            }catch(string str) {cout << str << endl << endl;} //catch exception if car is full
        }
        if(input == 3) { //cancel a reservation
            cout << "\n************************ CANCELLING RESERVATION *************************\n" << endl;
            cout << "Enter your reservation #: ";
            int num;
            cin >> num;
            try {
                res[num-1]->CancelRes(mall, restaurant, park, num);
            }catch(string str) {cout << str << endl << endl;} //catch exception if reservation is not found
        }
        if(input == 4) { //display past records
            cout << "\n************************** DISPLAYING RECORDS ***************************" << endl;
            for(int i = 0; i < 35; i++) {
                if(res[i]->choice > 0)
                    res[i]->DisplayRecords(i+1);
            }//end for loop
        }
        Menu(); //display menu
        cin >> input;
    }//end while loop

    cout << "\nThank you for using our app. Goodbye!" << endl;

    return 0;
}

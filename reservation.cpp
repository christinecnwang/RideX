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

int Reservation::resNum = 0; //define static variable

//CREATE RESERVATION
void Reservation::AddRes(Mall &m, Restaurant &r, Park &p) {
    cout << "\n************************* CREATING RESERVATION **************************\n" << endl;
    cout << "RESERVATION #: " << ++resNum << endl << endl;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    //choose destination
    cout << "\nChoose a destination: " << endl;
    cout << "   (1): " << m.GetName() << endl;
    cout << "   (2): " << r.GetName() << endl;
    cout << "   (3): " << p.GetName() << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    //check for valid choice (1-3)
    while(choice < 1 || choice > 3) {
        cout << "ERROR: Invalid choice!" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }//end while

    //choose car
    if(choice == 1) {
        destination = m.GetName();
        cout << "\nChoose a car: " << endl;
        cout << "   (1): " << m.hondaCiv.GetName() << endl;
        cout << "   (2): " << m.dodgeGC.GetName() << endl;
        cout << "Enter your choice: ";
        cin >> choice2;
        //check for valid choice (1-2)
        while(choice2 < 1 || choice2 > 2) {
            cout << "ERROR: Invalid choice!" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
        }//end while
        cout << "\nEnter the number of passengers: ";
        cin >> passengers;
        try {
            if(choice2 == 1) {
                car = m.hondaCiv.GetName();
                m.hondaCiv.FillSeats(passengers);
            }
            if(choice2 == 2) {
                car = m.dodgeGC.GetName();
                m.dodgeGC.FillSeats(passengers);
            }
        }catch(string str) { //catch exception if car is full
            choice = 0;
            throw; //rethrow exception to main function
        }
    }//end destination 1

    if(choice == 2) {
        destination = r.GetName();
        cout << "\nChoose a car: " << endl;
        cout << "   (1): " << r.teslaM3.GetName() << endl;
        cout << "   (2): " << r.toyotaRav.GetName() << endl;
        cout << "Enter your choice: ";
        cin >> choice2;
        //check for valid choice (1-2)
        while(choice2 < 1 || choice2 > 2) {
            cout << "ERROR: Invalid choice!" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
        }//end while
        cout << "\nEnter the number of passengers: ";
        cin >> passengers;
        try {
            if(choice2 == 1) {
                car = r.teslaM3.GetName();
                r.teslaM3.FillSeats(passengers);
            }
            if(choice2 == 2) {
                car = r.toyotaRav.GetName();
                r.toyotaRav.FillSeats(passengers);
            }
        }catch(string str) { //catch exception if car is full
            choice = 0;
            throw; //rethrow exception to main function
        }
    }//end destination 2

    if(choice == 3) {
        destination = p.GetName();
        cout << "\nChoose a car: " << endl;
        cout << "   (1): " << p.toyotaCam.GetName() << endl;
        cout << "   (2): " << p.hondaOdy.GetName() << endl;
        cout << "Enter your choice: ";
        cin >> choice2;
        //check for valid choice (1-2)
        while(choice2 < 1 || choice2 > 2) {
            cout << "ERROR: Invalid choice!" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
        }//end while
        cout << "\nEnter the number of passengers: ";
        cin >> passengers;
        try {
            if(choice2 == 1) {
                car = p.toyotaCam.GetName();
                p.toyotaCam.FillSeats(passengers);
            }
            if(choice2 == 2) {
                car = p.hondaOdy.GetName();
                p.hondaOdy.FillSeats(passengers);
            }
        }catch(string str) { //catch exception if car is full
            choice = 0;
            throw; //rethrow exception to main function
        }
    }//end destination 3
}

//CANCEL RESERVATION
void Reservation::CancelRes(Mall &m, Restaurant &r, Park &p, int num) {
    if(choice == 1) {
        if(choice2 == 1) {
            m.hondaCiv.FreeSeats(passengers);
        }
        if(choice2 == 2) {
            m.dodgeGC.FreeSeats(passengers);
        }
        cout << "\nReservation #" << num << " under '" << name << "' for " << passengers << " person(s) at "
             << destination << " via " << car << " has been cancelled." << endl;
        choice = 0;
    }//end destination 1

    else if(choice == 2) {
        if(choice2 == 1) {
            r.teslaM3.FreeSeats(passengers);
        }
        if(choice2 == 2) {
            r.toyotaRav.FreeSeats(passengers);
        }
        cout << "\nReservation #" << num << " under '" << name << "' for " << passengers << " person(s) at "
             << destination << " via " << car << " has been cancelled." << endl;
        choice = 0;
    }//end destination 2

    else if(choice == 3) {
        if(choice2 == 1) {
            p.toyotaCam.FreeSeats(passengers);
        }
        if(choice2 == 2) {
            p.hondaOdy.FreeSeats(passengers);
        }
        cout << "\nReservation #" << num << " under '" << name << "' for " << passengers << " person(s) at "
             << destination << " via " << car << " has been cancelled." << endl;
        choice = 0;
    }//end destination 3

    else
        throw string("ERROR: Reservation not found!"); //throw exception if choice = 0 (no valid reservation)
}

//DISPLAY PAST RECORDS
void Reservation::DisplayRecords(int num) {
    cout << "\nRESERVATION #" << num << ":" << endl;
    cout << "   Name: " << name << endl;
    cout << "   Destination: " << destination << endl;
    cout << "   Car: " << car << endl;
    cout << "   # of Passengers: " << passengers << endl;
}
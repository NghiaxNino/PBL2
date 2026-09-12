#include <bits/stdc++.h>
#include "PBL2.h"
using namespace std;
void Airline::input(){
    getline(cin >> ws, this->airlineID);
    getline(cin >> ws, this->airlineName);
    getline(cin >> ws, this->country);
    getline(cin >> ws, this->contactInfo);
}
void Airline::output(){
    cout<< this->airlineID <<endl;
    cout<< this->airlineName <<endl;
    cout<< this->country <<endl;
    cout<< this->contactInfo <<endl;
}
void Flight::input(){
    getline(cin >> ws, this->);

}
void Flight::output(){
    cout<< this->flightID <<endl;
    cout<< this->airlineID <<endl;
    cout<< this->departure <<endl;
    cout<< this->destination <<endl;
    cout<< this->departureTime <<endl;
    cout<< this->arrivalTime <<endl;
    cout<< this->status <<endl;

}
void Airplane::input(){

}
void Airplane::output(){
    cout<< this->airplaneID <<endl;
    cout<< this->airplaneType <<endl;
    cout<< this->seatCount <<endl;
    cout<< this->status <<endl;
}
void Seat::input(){

}
void Seat::output(){
    cout<< this->seatID <<endl;
    cout<< this->seatClass <<endl;
    cout<< this->status <<endl;
}
void Passenger::input(){

}
void Passenger::output(){
    cout<< this->passengerID <<endl;
    cout<< this->fullName <<endl;
    cout<< this->birthDate <<endl;
    cout<< this->citizenID <<endl;
    cout<< this->phoneNumber <<endl;
    cout<< this->email <<endl;
    cout<< this->username <<endl;
    cout<< this->password <<endl;
}
void Ticket::input(){

}
void Ticket::output(){
    cout<< this->ticketID <<endl;
    cout<< this->ticketID <<endl;
    cout<< this->flightID <<endl;
    cout<< this->seatID <<endl;
    cout<< this->price <<endl;
    cout<< this->bookingDate <<endl;
    cout<< this->status <<endl;
}
void Payment::input(){

}
void Payment::output(){
    cout<< this->transactionID <<endl;
    cout<< this->paymentMethod <<endl;
    cout<< this->ticketPrice <<endl;
    cout<< this->paymentTime <<endl;
    cout<< this->status <<endl;

}
void Employee::input(){

}
void Employee::output(){
    cout<< this->employeeID <<endl;
    cout<< this->fullName <<endl;
    cout<< this->position <<endl;
    cout<< this->username <<endl;    
    cout<< this->password <<endl;    

}
bool Delayed(){

}
bool Cancel(){

}
bool OnTime(){
    
}
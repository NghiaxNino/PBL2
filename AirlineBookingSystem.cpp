#include "PBL2.h"

AirlineBookingSystem::AirlineBookingSystem(){
    flight = NULL;
    passenger = NULL;
    employee = NULL;
    ticket = NULL;

    flightCount = 0;
    passengerCount = 0;
    employeeCount = 0;
    ticketCount = 0;
}

AirlineBookingSystem::~AirlineBookingSystem(){
    delete[] flight;
    delete[] passenger;
    delete[] employee;
    delete[] ticket;
}

void AirlineBookingSystem::sortFlightByID(){
    for(int i = 0; i < flightCount - 1; i++){
        for(int j = i + 1; j < flightCount; j++){
            if(flight[i].getFlightID() > flight[j].getFlightID()){
                Flight temp = flight[i];
                flight[i] = flight[j];
                flight[j] = temp;
            }
        }
    }
}

void AirlineBookingSystem::addFlight(){
    Flight* temp = new Flight[flightCount + 1];
    for(int i = 0; i < flightCount; i++){
        temp[i] = flight[i];
    }
    cin.ignore();
    temp[flightCount].input();
    delete[] flight;
    flight = temp;
    flightCount++;
    sortFlightByID();
    cout << "Them thanh cong\n";
}

void AirlineBookingSystem::displayFlights(){
    if(flightCount == 0){
        cout << "Danh sach rong\n";
        return;
    }
    for(int i = 0; i < flightCount; i++){
        flight[i].output();
        cout << endl;
    }
}

int AirlineBookingSystem::searchFlight(string flightID){
    int left = 0;
    int right = flightCount - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(flight[mid].getFlightID() == flightID) return mid;
        if(flight[mid].getFlightID() < flightID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void AirlineBookingSystem::deleteFlight(){
    string flightID;
    cout << "Nhap ma chuyen bay can xoa: ";
    cin >> flightID;
    int pos = searchFlight(flightID);
    if(pos == -1){
        cout << "Khong tim thay\n";
        return;
    }
    Flight* temp = new Flight[flightCount - 1];
    int j = 0;
    for(int i = 0; i < flightCount; i++){
        if(i != pos) temp[j++] = flight[i];
    }
    delete[] flight;
    flight = temp;
    flightCount--;
    cout << "Xoa thanh cong\n";
}

void AirlineBookingSystem::updateFlight(){
    string flightID;
    cout << "Nhap ma chuyen bay can cap nhat: ";
    cin >> flightID;
    int pos = searchFlight(flightID);
    if(pos == -1){
        cout << "Khong tim thay!\n";
        return;
    }
    cin.ignore();
    flight[pos].updateInfo();
    cout << "Cap nhat thanh cong!\n";
}

void AirlineBookingSystem::sortPassengerByID(){
    for(int i = 0; i < passengerCount - 1; i++){
        for(int j = i + 1; j < passengerCount; j++){
            if(passenger[i].getPassengerID() >passenger[j].getPassengerID()){
                Passenger temp =passenger[i];
               passenger[i] =passenger[j];
               passenger[j] = temp;
            }
        }
    }
}

int AirlineBookingSystem::searchPassenger(string passengerID){
    int left = 0;
    int right = passengerCount - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(passenger[mid].getPassengerID() == passengerID) return mid;
        if(passenger[mid].getPassengerID() < passengerID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
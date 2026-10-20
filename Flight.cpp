#include "PBL2.h"

Flight::Flight(){
    flightID = "";
    departure = "";
    destination = "";
    departureTime = "";
    arrivalTime = "";
    status = "";
    totalSeats = 0;
    bookedSeats = 0;
}

void Flight::input(){
    cout << "Nhap ma chuyen bay: ";
    getline(cin, flightID);
    cout << "Nhap diem di: ";
    getline(cin, departure);
    cout << "Nhap diem den: ";
    getline(cin, destination);
    cout << "Nhap thoi gian khoi hanh: ";
    getline(cin, departureTime);
    cout << "Nhap thoi gian ha canh: ";
    getline(cin, arrivalTime);
    cout << "Nhap trang thai: ";
    getline(cin, status);
    cout << "Nhap tong so ghe: ";
    cin >> totalSeats;
    cin.ignore();
}

void Flight::output(){
    cout << "\n===== THONG TIN CHUYEN BAY =====\n";
    cout << "Ma chuyen bay: " << flightID << endl;
    cout << "Diem di: " << departure << endl;
    cout << "Diem den: " << destination << endl;
    cout << "Khoi hanh: " << departureTime << endl;
    cout << "Ha canh: " << arrivalTime << endl;
    cout << "Trang thai: " << status << endl;
    cout << "So ghe: " << bookedSeats << "/" << totalSeats << endl;
}


void Flight::updateInfo(){
    cout << "Nhap diem di moi: ";
    getline(cin, departure);
    cout << "Nhap diem den moi: ";
    getline(cin, destination);
    cout << "Nhap thoi gian khoi hanh moi: ";
    getline(cin, departureTime);
    cout << "Nhap thoi gian ha canh moi: ";
    getline(cin, arrivalTime);
}

void Flight::updateStatus(string status){
    this->status = status;
}

bool Flight::isFull(){
    return bookedSeats >= totalSeats;
}

void Flight::increaseBookedSeats(){
    bookedSeats++;
}

void Flight::decreaseBookedSeats(){
    if(bookedSeats > 0) bookedSeats--;
}

void Flight::setFlightData(string flightID, string departure, string destination, string departureTime,
                           string arrivalTime, string status, int totalSeats, int bookedSeats)
{
    this->flightID = flightID;
    this->departure = departure;
    this->destination = destination;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->status = status;
    this->totalSeats = totalSeats;
    this->bookedSeats = bookedSeats;
}

string Flight::getFlightID() const{
    return flightID;
}

string Flight::getDeparture() const{
    return departure;
}

string Flight::getDestination() const{
    return destination;
}

string Flight::getDepartureTime() const{
    return departureTime;
}

string Flight::getArrivalTime() const{
    return arrivalTime;
}

string Flight::getStatus() const{
    return status;
}

int Flight::getTotalSeats() const{
    return totalSeats;
}

int Flight::getBookedSeats() const{
    return bookedSeats;
}
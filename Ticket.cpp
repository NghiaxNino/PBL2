#include "PBL2.h"

Ticket::Ticket(){
    ticketID = "";
    passengerID = "";
    flightID = "";
    seatID = "";
    price = 0;
    bookingDate = "";
    status = "";
}

void Ticket::input(){
    cout << "Nhap ma ve: ";
    getline(cin, ticketID);
    cout << "Nhap ma hanh khach: ";
    getline(cin, passengerID);
    cout << "Nhap ma chuyen bay: ";
    getline(cin, flightID);
    cout << "Nhap ma ghe: ";
    getline(cin, seatID);
    cout << "Nhap gia ve: ";
    cin >> price;
    cin.ignore();
    cout << "Nhap ngay dat ve: ";
    getline(cin, bookingDate);
    status = "Booked";
}

void Ticket::output(){
    cout << "\n===== THONG TIN VE =====\n";
    cout << "Ma ve: " << ticketID << endl;
    cout << "Ma hanh khach: " << passengerID << endl;
    cout << "Ma chuyen bay: " << flightID << endl;
    cout << "Ma ghe: " << seatID << endl;
    cout << "Gia ve: " << price << endl;
    cout << "Ngay dat ve: " << bookingDate << endl;
    cout << "Trang thai: " << status << endl;
}

string Ticket::getTicketID() const{
    return ticketID;
}

string Ticket::getPassengerID() const{
    return passengerID;
}

string Ticket::getFlightID() const{
    return flightID;
}

void Ticket::bookTicket(){
    status = "Booked";
}

void Ticket::cancelTicket(){
    status = "Cancelled";
}

void Ticket::printTicket(){
    cout << "\n========== VE MAY BAY ==========\n";
    cout << "Ma ve: " << ticketID << endl;
    cout << "Ma hanh khach: " << passengerID << endl;
    cout << "Ma chuyen bay: " << flightID << endl;
    cout << "Ma ghe: " << seatID << endl;
    cout << "Gia ve: " << price << endl;
    cout << "Ngay dat ve: " << bookingDate << endl;
    cout << "Trang thai: " << status << endl;
    cout << "================================\n";
}
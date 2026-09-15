#include "PBL2.h"
#include "Sort.h"

bool compareFlight(const Flight& a, const Flight& b){
    return a.getFlightID() <= b.getFlightID();
}
bool comparePassenger(const Passenger& a, const Passenger& b){
    return a.getPassengerID() <= b.getPassengerID();
}
bool compareEmployee(const Employee& a, const Employee& b){
    return a.getRole() <= b.getRole();
}
bool compareTicket(const Ticket& a, const Ticket& b){
    return a.getTicketID() <= b.getTicketID();
}


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
    mergeSort(flight, 0, flightCount - 1, compareFlight);
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
        cout << "Khong tim thay\n";
        return;
    }
    cin.ignore();
    flight[pos].updateInfo();
    cout << "Cap nhat thanh cong\n";
}

void AirlineBookingSystem::addPassenger(){
    Passenger* temp = new Passenger[passengerCount + 1];
    for(int i = 0; i < passengerCount; i++) temp[i] = passenger[i];
    
    cin.ignore();
    temp[passengerCount].input();
    delete[] passenger;
    passenger = temp;
    passengerCount++;
    mergeSort(passenger, 0, passengerCount - 1, comparePassenger);
    cout << "Them hanh khach thanh cong\n";
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

void AirlineBookingSystem::displayPassengers(){
    if(passengerCount == 0){
        cout << "Danh sach rong\n";
        return;
    }
    for(int i = 0; i < passengerCount; i++){
        passenger[i].output();
        cout << endl;
    }
}

void AirlineBookingSystem::deletePassenger(){
    string passengerID;
    cout << "Nhap ma hanh khach can xoa: ";
    cin >> passengerID;
    int pos = searchPassenger(passengerID);
    if(pos == -1){
        cout << "Khong tim thay\n";
        return;
    }
    Passenger* temp = new Passenger[passengerCount - 1];
    int j = 0;
    for(int i = 0; i < passengerCount; i++){
        if(i != pos) temp[j++] = passenger[i];
    }
    delete[] passenger;
    passenger = temp;
    passengerCount--;
    cout << "Xoa thanh cong\n";
}

void AirlineBookingSystem::updatePassenger(){
    string passengerID;
    cout << "Nhap ma hanh khach can cap nhat: ";
    cin >> passengerID;
    int pos = searchPassenger(passengerID);
    if(pos == -1){
        cout << "Khong tim thay\n";
        return;
    }
    cin.ignore();
    passenger[pos].updateInfo();
    cout << "Cap nhat thanh cong\n";
}

void AirlineBookingSystem::addEmployee(){
    Employee* temp = new Employee[employeeCount + 1];
    for(int i = 0; i < employeeCount; i++) temp[i] = employee[i];
    cin.ignore();
    temp[employeeCount].input();
    delete[] employee;
    employee = temp;
    employeeCount++;
    mergeSort(employee, 0, employeeCount - 1, compareEmployee);
    cout << "Them nhan vien thanh cong\n";
}

void AirlineBookingSystem::deleteEmployee(){
    string employeeID;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> employeeID;
    int pos = searchEmployee(employeeID);
    if(pos == -1){
        cout << "Khong tim thay\n";
        return;
    }
    Employee* temp = new Employee[employeeCount - 1];
    int j = 0;
    for(int i = 0; i < employeeCount; i++){
        if(i != pos) temp[j++] = employee[i];
    }
    delete[] employee;
    employee = temp;
    employeeCount--;
    cout << "Xoa thanh cong\n";
}

void AirlineBookingSystem::displayEmployees(){
    if(employeeCount == 0){
        cout << "Danh sach rong\n";
        return;
    }
    for(int i = 0; i < employeeCount; i++){
        employee[i].output();
        cout << endl;
    }
}

void AirlineBookingSystem::updateEmployee(){
    string employeeID;
    cout << "Nhap ma nhan vien can cap nhat: ";
    cin >> employeeID;
    int pos = searchEmployee(employeeID);
    if(pos == -1){
        cout << "Khong tim thay\n";
        return;
    }
    cin.ignore();
    employee[pos].updateInfo();
    cout << "Cap nhat thanh cong\n";
}

int AirlineBookingSystem::searchTicket(string ticketID){
    int left = 0;
    int right = ticketCount - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(ticket[mid].getTicketID() == ticketID) return mid;
        if(ticket[mid].getTicketID() < ticketID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void AirlineBookingSystem::createTicket(){
    Ticket* temp = new Ticket[ticketCount + 1];
    for(int i = 0; i < ticketCount; i++) temp[i] = ticket[i];
    cin.ignore();
    temp[ticketCount].input();
    delete[] ticket;
    ticket = temp;
    ticketCount++;
    mergeSort(ticket, 0, ticketCount - 1, compareTicket);
    cout << "Dat ve thanh cong\n";
}

void AirlineBookingSystem::cancelTicket(){
    string ticketID;
    cout << "Nhap ma ve can huy: ";
    cin >> ticketID;
    int pos = searchTicket(ticketID);
    if(pos == -1){
        cout << "Khong tim thay ve\n";
        return;
    }
    ticket[pos].cancelTicket();
    cout << "Huy ve thanh cong\n";
}

void AirlineBookingSystem::displayTickets(){
    if(ticketCount == 0){
        cout << "Danh sach ve rong\n";
        return;
    }
    for(int i = 0; i < ticketCount; i++){
        ticket[i].output();
        cout << endl;
    }
}

void AirlineBookingSystem::menu(){
    int choice;
    do{
        cout << "\n===================================\n";
        cout << " AIRLINE BOOKING SYSTEM\n";
        cout << "===================================\n";
        cout << "1. Quan ly chuyen bay\n";
        cout << "2. Quan ly hanh khach\n";
        cout << "3. Quan ly nhan vien\n";
        cout << "4. Quan ly ve\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch(choice){
            case 1:
                flightMenu();
                break;
            case 2:
                passengerMenu();
                break;
            case 3:
                employeeMenu();
                break;
            case 4:
                ticketMenu();
                break;
            case 0:
                cout << "Thoat\n";
                break;
        }

    }while(choice != 0);
}

void AirlineBookingSystem::flightMenu(){
    int choice;
    do{
        cout << "\n===== QUAN LY CHUYEN BAY =====\n";
        cout << "1. Them chuyen bay\n";
        cout << "2. Xoa chuyen bay\n";
        cout << "3. Cap nhat chuyen bay\n";
        cout << "4. Tim kiem chuyen bay\n";
        cout << "5. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch(choice){
            case 1:
                addFlight();
                break;
            case 2:
                deleteFlight();
                break;
            case 3:
                updateFlight();
                break;
            case 4:{
                string id;
                cout << "Nhap ma chuyen bay: ";
                cin >> id;
                int pos = searchFlight(id);
                if(pos == -1) cout << "Khong tim thay!\n";
                else flight[pos].output();
                break;
            }
            case 5:
                displayFlights();
                break;
        }
    }while(choice != 0);
}
void AirlineBookingSystem::passengerMenu(){
    int choice;

    do{
        cout << "\n===== QUAN LY HANH KHACH =====\n";
        cout << "1. Them hanh khach\n";
        cout << "2. Xoa hanh khach\n";
        cout << "3. Cap nhat hanh khach\n";
        cout << "4. Tim kiem hanh khach\n";
        cout << "5. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch(choice){
            case 1:
                addPassenger();
                break;
            case 2:
                deletePassenger();
                break;
            case 3:
                updatePassenger();
                break;
            case 4:{
                string id;
                cout << "Nhap ma hanh khach: ";
                cin >> id;
                int pos = searchPassenger(id);
                if(pos == -1) cout << "Khong tim thay!\n";
                else passenger[pos].output();
                break;
            }
            case 5:
                displayPassengers();
                break;
        }

    }while(choice != 0);
}
void AirlineBookingSystem::employeeMenu(){
    int choice;
    do{
        cout << "\n===== QUAN LY NHAN VIEN =====\n";
        cout << "1. Them nhan vien\n";
        cout << "2. Xoa nhan vien\n";
        cout << "3. Cap nhat nhan vien\n";
        cout << "4. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch(choice){
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                displayEmployees();
                break;
        }

    }while(choice != 0);
}
void AirlineBookingSystem::ticketMenu(){
    int choice;
    do{
        cout << "\n===== QUAN LY VE =====\n";
        cout << "1. Dat ve\n";
        cout << "2. Huy ve\n";
        cout << "3. Tim kiem ve\n";
        cout << "4. Hien thi danh sach ve\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch(choice){
            case 1:
                createTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:{
                string id;
                cout << "Nhap ma ve: ";
                cin >> id;
                int pos = searchTicket(id);
                if(pos == -1) cout << "Khong tim thay!\n";
                else ticket[pos].output();
                break;
            }
            case 4:
                displayTickets();
                break;
        }

    }while(choice != 0);
}
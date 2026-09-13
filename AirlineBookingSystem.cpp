#include "PBL2.h"
#include <string>

bool ascending(string a, string b){
    return a < b;
}
bool descending(string a, string b){
    return a > b;
}
void mergeFlight(Flight* base, int left, int mid, int right, bool (*cmp)(string, string)){
    int n1 = mid - left +1;
    int n2 = right - mid;

    Flight* L = new Flight[n1];
    Flight* R = new Flight[n2];

    for (int i = 0; i < n1; i++) L[i]=base[left+i];
    for (int j = 0; j < n2; j++) R[j]=base[mid+1+j];

    int i=0; int j=0; int k=left;
    while (i < n1 && j< n2){
        if ( cmp(L[i].getFlightID(), R[j].getFlightID()) ){
            base[k++] = L[i++];
        }
        else{
            base[k++] = R[j++];
        }
    }
    while (i < n1) base[k++] = L[i++];
    while (j < n2) base[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergePassenger(Passenger* base, int left, int mid, int right, bool (*cmp)(string, string)){
    int n1 = mid - left +1;
    int n2 = right - mid;

    Passenger* L = new Passenger[n1];
    Passenger* R = new Passenger[n2];
    
    for (int i=0; i < n1; i++) L[i] = base[left+i];
    for (int j=0; j < n2; j++) R[j] = base[mid +1 +j];

    int i=0;
    int j=0;
    int k=left;

    while (i < n1 && j < n2){
        if(cmp(L[i].getPassengerID(), R[j].getPassengerID())) base[k++] = L[i++];
        else base[k++] = R[j++];
    }
    while (i < n1) base[k++] = L[i++];
    while (j < n2) base[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergeTicket(Ticket* base, int left, int mid, int right, bool (*cmp)(string, string)){
    int n1 = mid - left +1;
    int n2 = right - mid;

    Ticket* L = new Ticket[n1];
    Ticket* R = new Ticket[n2];

    for (int i = 0; i < n1; i++) L[i] = base[left+i];
    for (int j = 0; j < n2; j++) R[j] = base[mid +1 +j];

    int i=0; int j=0; int k= left;
    while(i < n1 && j < n2){
        if (cmp(L[i].getTicketID(), R[j].getTicketID())) base[k++] = L[i++];
        else base[k++] = R[j++];
    }
    while (i < n1) base[k++] = L[i++];
    while (j < n2) base[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergeEmployee(Employee* base, int left, int mid, int right, bool (*cmp)(string, string)){
    int n1 = mid - left +1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++) L[i] = base[left+i];
    for (int j = 0; j < n2; j++) R[j] = base[mid +1 +j];

    int i=0; int j=0; int k= left;
    while(i < n1 && j < n2){
        if (cmp(L[i].getRole(), R[j].getRole())) base[k++] = L[i++];
        else base[k++] = R[j++];
    }
    while (i < n1) base[k++] = L[i++];
    while (j < n2) base[k++] = R[j++];

    delete[] L;
    delete[] R;
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

void AirlineBookingSystem::sortFlightByID(int left, int right, bool (*cmp)(string, string)){
    if(left < right){
        int mid = left + (right - left) / 2;
        sortFlightByID(left, mid, cmp);
        sortFlightByID(mid + 1, right, cmp);
        mergeFlight(flight, left, mid, right, cmp);
    }
    else return;   
}

void AirlineBookingSystem::addFlight(bool (*cmp)(string, string) = ascending){
    Flight* temp = new Flight[flightCount + 1];
    for(int i = 0; i < flightCount; i++){
        temp[i] = flight[i];
    }
    cin.ignore();
    temp[flightCount].input();
    delete[] flight;
    flight = temp;
    flightCount++;
    sortFlightByID(0, flightCount - 1, cmp);
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

int AirlineBookingSystem::searchFlight(string flightID, bool (*cmp)(string, string) = ascending){
    int left = 0;
    int right = flightCount - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(flight[mid].getFlightID() == flightID) return mid;
        if(cmp(flight[mid].getFlightID(), flightID)) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void AirlineBookingSystem::deleteFlight(bool (*cmp)(string, string) = ascending){
    string flightID;
    cout << "Nhap ma chuyen bay can xoa: ";
    cin >> flightID;
    int pos = searchFlight(flightID, cmp);
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

void AirlineBookingSystem::updateFlight(bool (*cmp)(string, string) = ascending){
    string flightID;
    cout << "Nhap ma chuyen bay can cap nhat: ";
    cin >> flightID;
    int pos = searchFlight(flightID, cmp);
    if(pos == -1){
        cout << "Khong tim thay!\n";
        return;
    }
    cin.ignore();
    flight[pos].updateInfo();
    cout << "Cap nhat thanh cong!\n";
}

void AirlineBookingSystem::sortPassengerByID(int left, int right, bool (*cmp)(string, string)){
    if(left < right){
        int mid = left + (right - left) / 2;
        sortPassengerByID(left, mid, cmp);
        sortPassengerByID(mid + 1, right, cmp);
        mergePassenger(passenger, left, mid, right, cmp);
    }
    else return;
}
void AirlineBookingSystem::addPassenger(bool (*cmp)(string, string) = ascending){
    Passenger* temp = new Passenger[passengerCount + 1];
    for(int i = 0; i < passengerCount; i++) temp[i] = passenger[i];
    
    cin.ignore();
    temp[passengerCount].input();
    delete[] passenger;
    passenger = temp;
    passengerCount++;
    sortPassengerByID(0, passengerCount - 1, cmp);
    cout << "Them hanh khach thanh cong!\n";
}

int AirlineBookingSystem::searchPassenger(string passengerID, bool (*cmp)(string, string) = ascending){
    int left = 0;
    int right = passengerCount - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(passenger[mid].getPassengerID() == passengerID) return mid;
        if(cmp(passenger[mid].getPassengerID(), passengerID)) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void AirlineBookingSystem::displayPassengers(){
    if(passengerCount == 0){
        cout << "Danh sach rong!\n";
        return;
    }
    for(int i = 0; i < passengerCount; i++){
        passenger[i].output();
        cout << endl;
    }
}

void AirlineBookingSystem::deletePassenger(bool (*cmp)(string, string) = ascending){
    string passengerID;
    cout << "Nhap ma hanh khach can xoa: ";
    cin >> passengerID;
    int pos = searchPassenger(passengerID, cmp);
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

void AirlineBookingSystem::updatePassenger(bool (*cmp)(string, string) = ascending){
    string passengerID;
    cout << "Nhap ma hanh khach can cap nhat: ";
    cin >> passengerID;
    int pos = searchPassenger(passengerID, cmp);
    if(pos == -1){
        cout << "Khong tim thay!\n";
        return;
    }
    cin.ignore();
    passenger[pos].updateInfo();
    cout << "Cap nhat thanh cong\n";
}

void AirlineBookingSystem::sortEmployeeByRole(int left, int right, bool (*cmp)(string, string)){
    if(left < right){
        int mid = left + (right - left) / 2;
        sortEmployeeByRole(left, mid, cmp);
        sortEmployeeByRole(mid + 1, right, cmp);
        mergeEmployee(employee, left, mid, right, cmp);
    }
    else return;
}

void AirlineBookingSystem::addEmployee(bool (*cmp)(string, string) = ascending){
    Employee* temp = new Employee[employeeCount + 1];
    for(int i = 0; i < employeeCount; i++) temp[i] = employee[i];
    cin.ignore();
    temp[employeeCount].input();
    delete[] employee;
    employee = temp;
    employeeCount++;
    sortEmployeeByRole(0, employeeCount - 1, cmp);
    cout << "Them nhan vien thanh cong!\n";
}

void AirlineBookingSystem::deleteEmployee(bool (*cmp)(string, string) = ascending){
    string employeeID;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> employeeID;
    int pos = searchEmployee(employeeID, cmp);
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
    cout << "Xoa thanh cong!\n";
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

void AirlineBookingSystem::updateEmployee(bool (*cmp)(string, string) = ascending){
    string employeeID;
    cout << "Nhap ma nhan vien can cap nhat: ";
    cin >> employeeID;
    int pos = searchEmployee(employeeID, cmp);
    if(pos == -1){
        cout << "Khong tim thay!\n";
        return;
    }
    cin.ignore();
    employee[pos].updateInfo();
    cout << "Cap nhat thanh cong\n";
}

void AirlineBookingSystem::sortTicketByID(int left, int right, bool (*cmp)(string, string)){
    if(left < right){
        int mid = left + (right - left) / 2;
        sortTicketByID(left, mid, cmp);
        sortTicketByID(mid + 1, right, cmp);
        mergeTicket(ticket, left, mid, right, cmp);
    }
    else return;
}

int AirlineBookingSystem::searchTicket(string ticketID, bool (*cmp)(string, string) = ascending){
    int left = 0;
    int right = ticketCount - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(ticket[mid].getTicketID() == ticketID) return mid;
        if(cmp(ticket[mid].getTicketID(), ticketID)) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void AirlineBookingSystem::createTicket(bool (*cmp)(string, string) = ascending){
    Ticket* temp = new Ticket[ticketCount + 1];
    for(int i = 0; i < ticketCount; i++) temp[i] = ticket[i];
    cin.ignore();
    temp[ticketCount].input();
    delete[] ticket;
    ticket = temp;
    ticketCount++;
    sortTicketByID(0, ticketCount - 1, cmp);
    cout << "Dat ve thanh cong\n";
}

void AirlineBookingSystem::cancelTicket(bool (*cmp)(string, string) = ascending){
    string ticketID;
    cout << "Nhap ma ve can huy: ";
    cin >> ticketID;
    int pos = searchTicket(ticketID, cmp);
    if(pos == -1){
        cout << "Khong tim thay ve!\n";
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
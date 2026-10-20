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

int AirlineBookingSystem::employeeLogin(){
    string username, password;
    cin.ignore();
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    for(int i = 0; i < employeeCount; i++){
        if(employee[i].login(username, password)){
            return i;
        }
    }
    return -1;
}

int AirlineBookingSystem::passengerLogin(){
    string username, password;
    cin.ignore();
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    for(int i = 0; i < passengerCount; i++){
        if(passenger[i].login(username, password)){
            return i;
        }
    }
    return -1;
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

int AirlineBookingSystem::searchEmployee(string employeeID){
    for(int i = 0; i < employeeCount; i++){
        if(employee[i].getEmployeeID() == employeeID)
            return i;
    }
    return -1;
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

void AirlineBookingSystem::createTicket(string passengerID){
    Ticket newTicket;
    cin.ignore();
    newTicket.input();

    int flightPos = searchFlight(newTicket.getFlightID());
    if(flightPos == -1){
        cout << "Chuyen bay khong ton tai!\n";
        return;
    }
    if(flight[flightPos].isFull()){
        cout << "Chuyen bay da het cho!\n";
        return;
    }

    Ticket* temp = new Ticket[ticketCount + 1];
    for(int i = 0; i < ticketCount; i++){
        temp[i] = ticket[i];
    }
    temp[ticketCount] = newTicket;
    delete[] ticket;
    ticket = temp;
    ticketCount++;
    flight[flightPos].increaseBookedSeats();
    mergeSort(ticket, 0, ticketCount - 1, compareTicket);
    cout << "Dat ve thanh cong\n";
}

void AirlineBookingSystem::cancelTicket(string passengerID){
    if(passengerID == ""){
        cout << "\n===== DANH SACH VE =====\n";
        displayTickets();
    }
    else{
        bool found = false;
        cout << "\n===== DANH SACH VE =====\n";
        for(int i = 0; i < ticketCount; i++){
            if(ticket[i].getPassengerID() == passengerID){
                ticket[i].output();
                cout << endl;
                found = true;
            }
        }
        if(!found){
            cout << "Ban chua co ve nao\n";
            return;
        }
    }

    string ticketID;
    cout << "Nhap ma ve can huy: ";
    cin >> ticketID;
    int pos = searchTicket(ticketID);
    if(pos == -1){
        cout << "Khong tim thay ve\n";
        return;
    }

    if(passengerID != "" && ticket[pos].getPassengerID() != passengerID){
        cout << "Ve khong hop le\n";
        return;
    }

    int flightPos = searchFlight(ticket[pos].getFlightID());
    if(flightPos != -1) flight[flightPos].decreaseBookedSeats();
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

void AirlineBookingSystem::Menu(){
    int choice;

    do{
        cout << "\n=============================\n";
        cout << " AIRLINE BOOKING SYSTEM\n";
        cout << "=============================\n";
        cout << "1. Dang nhap nhan vien\n";
        cout << "2. Dang nhap hanh khach\n";
        cout << "3. Xem danh sach chuyen bay\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";

        cin >> choice;

        switch(choice){
            case 1:{
                int pos = employeeLogin();
                if(pos != -1){
                    if(employee[pos].getRole() == "Manager") managerMenu();
                    else if(employee[pos].getRole() == "Staff") staffMenu();
                }
                else cout << "Dang nhap that bai\n";
                break;
            }

            case 2:{
                int pos = passengerLogin();
                if(pos != -1) passengerMenu(pos);
                else cout << "Dang nhap that bai\n";
                break;
            }
            case 3:
                displayFlights();
                break;
        }
    }while(choice != 0);
}

void AirlineBookingSystem::managerMenu(){
    int choice;
    do{
        cout << "\n===== MANAGER MENU =====\n";
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
                e_passengerMenu();
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

void AirlineBookingSystem::passengerMenu(int pos){
    int choice;

    do{
        cout << "\n===== PASSENGER MENU =====\n";
        cout << "1. Xem danh sach chuyen bay\n";
        cout << "2. Dat ve\n";
        cout << "3. Huy ve\n";
        cout << "4. Xem thong tin ca nhan\n";
        cout << "5. Cap nhat thong tin ca nhan\n";
        cout << "0. Dang xuat\n";
        cout << "Lua chon: ";

        cin >> choice;

        switch(choice){
            case 1:
                displayFlights();
                break;
            case 2:
                createTicket(passenger[pos].getPassengerID());
                break;
            case 3:
                cancelTicket(passenger[pos].getPassengerID());
                break;
            case 4:
                passenger[pos].output();
                break;
            case 5:
                cin.ignore();
                passenger[pos].updateInfo();
                break;
        }

    }while(choice != 0);
}

void AirlineBookingSystem::staffMenu(){
    int choice;
    do{
        cout << "\n===== STAFF MENU =====\n";
        cout << "1. Quan ly hanh khach\n";
        cout << "2. Quan ly ve\n";
        cout << "0. Dang xuat\n";
        cout << "Lua chon: ";

        cin >> choice;
        switch(choice){
            case 1:
                e_passengerMenu();
                break;
            case 2:
                ticketMenu();
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
void AirlineBookingSystem::e_passengerMenu(){
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

void AirlineBookingSystem::readPassenger(){
    ifstream fin("person.passenger.txt");
    if(!fin){
        cout << "Khong mo duoc person.passenger.txt\n";
        return;
    }
    string line;

    while(getline(fin, line)){
        stringstream ss(line); 
        string id, fullname, username, password, gender, citizenID, phoneNumber, email;

        getline(ss, id, '|');
        getline(ss, fullname, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');
        getline(ss, gender, '|');
        getline(ss, citizenID, '|');
        getline(ss, phoneNumber, '|');
        getline(ss, email, '|');

        Passenger* temp = new Passenger[passengerCount + 1];
        for(int i = 0; i < passengerCount; i++){
            temp[i] = passenger[i];
        }

        temp[passengerCount].setPassengerData(
            id, fullname, username, password, gender, citizenID, phoneNumber, email
        );

        delete[] passenger;
        passenger = temp;
        passengerCount++;
    }
    fin.close();
}

void AirlineBookingSystem::savePassenger(){
    ofstream fout("person.passenger.txt");
    for(int i = 0; i < passengerCount; i++){
        fout << passenger[i].getPassengerID() << "|"
             << passenger[i].getFullName() << "|"
             << passenger[i].getUsername() << "|"
             << passenger[i].getPassword() << "|"
             << passenger[i].getGender() << "|"
             << passenger[i].getCitizenID() << "|"
             << passenger[i].getPhoneNumber() << "|"
             << passenger[i].getEmail()
             << "\n";
    }
    fout.close();
}

void AirlineBookingSystem::readEmployee(){
    ifstream fin("person.employee.txt");
    if(!fin){
        cout << "Khong mo duoc person.employee.txt\n";
        return;
    }

    string line;
    while(getline(fin, line)){
        stringstream ss(line);
        string id, fullname, role, username, password;

        getline(ss, id, '|');
        getline(ss, fullname, '|');
        getline(ss, role, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');

        Employee* temp = new Employee[employeeCount + 1];
        for(int i = 0; i < employeeCount; i++){
            temp[i] = employee[i];
        }
        temp[employeeCount].setEmployeeData(
            id, fullname, role, username, password
        );

        delete[] employee;
        employee = temp;
        employeeCount++;
    }
    fin.close();
}

void AirlineBookingSystem::saveEmployee(){
    ofstream fout("person.employee.txt");
    for(int i = 0; i < employeeCount; i++){
        fout << employee[i].getEmployeeID() << "|"
             << employee[i].getFullName() << "|"
             << employee[i].getRole() << "|"
             << employee[i].getUsername() << "|"
             << employee[i].getPassword() 
             << "\n";
    }
    fout.close();
}

void AirlineBookingSystem::readFlight(){
    ifstream fin("flight.txt");
    if(!fin){
        cout << "Khong mo duoc flight.txt\n";
        return;
    }

    string line;
    while(getline(fin, line)){
        stringstream ss(line);
        string flightID, departure, destination, departureTime, arrivalTime, status, totalSeatsStr, bookedSeatsStr;

        getline(ss, flightID, '|');
        getline(ss, departure, '|');
        getline(ss, destination, '|');
        getline(ss, departureTime, '|');
        getline(ss, arrivalTime, '|');
        getline(ss, status, '|');
        getline(ss, totalSeatsStr, '|');
        getline(ss, bookedSeatsStr, '|');

        Flight* temp = new Flight[flightCount + 1];
        for(int i = 0; i < flightCount; i++){
            temp[i] = flight[i];
        }
        temp[flightCount].setFlightData(
            flightID, departure, destination, departureTime,
            arrivalTime, status, stoi(totalSeatsStr), stoi(bookedSeatsStr)
        );

        delete[] flight;
        flight = temp;
        flightCount++;
    }

    fin.close();
}

void AirlineBookingSystem::saveFlight(){
    ofstream fout("flight.txt");
    for(int i = 0; i < flightCount; i++){
        fout << flight[i].getFlightID() << "|"
             << flight[i].getDeparture() << "|"
             << flight[i].getDestination() << "|"
             << flight[i].getDepartureTime() << "|"
             << flight[i].getArrivalTime() << "|"
             << flight[i].getStatus() << "|"
             << flight[i].getTotalSeats() << "|"
             << flight[i].getBookedSeats()
             << "\n";
    }
    fout.close();
}
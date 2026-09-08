#ifndef PBL2_H
#define PBL2_H
#include <string>
using namespace std;

class Airline{
    private:
        string airlineID;
        string airlineName;
        string country;
        string contactInfo;

    public:
        void input();
        void output();
        string getAirlineID();
        string getAirlineName();
        void updateInfo();
        void updateStatus(string status);
};

class Flight{
    private:
        string flightID;
        string airlineID;
        string departure;
        string destination;
        string departureTime;
        string arrivalTime;
        string status;

    public:
        void input();
        void output();
        string getFlightID();
        void updateInfo();
};

class Airplane{
    private:
        string airplaneID;
        string airplaneType;
        int seatCount;
        string status;

    public:
        void input();
        void output();
        string getAirplaneID();
        void updateInfo();
};

class Seat{
    private:
        string seatID;
        string seatClass;
        string status;

    public:
        void input();
        void output();
        string getSeatID();
        void bookSeat();
        void cancelSeat();
};

class Passenger{
    private:
        string passengerID;
        string fullName;
        string birthDate;
        string citizenID;
        string phoneNumber;
        string email;
        string username;
        string password;

    public:
        void input();
        void output();
        string getPassengerID();
        void updateInfo();
        bool login(string username, string password);
        void viewFlight();
        void viewTicket();
        void printTicket();

};

class Ticket{
    private:
        string ticketID;
        string passengerID;
        string flightID;
        string seatID;
        double price;
        string bookingDate;
        string status;

    public:
        void input();
        void output();
        string getTicketID();
        void bookTicket();
        void cancelTicket();
        void printTicket();
};

class Payment{
    private:
        string transactionID;
        string paymentMethod;
        double ticketPrice;
        string paymentTime;
        string status;

    public:
        void input();
        void output();
        void updateStatus(string status);

};

class Employee{
    protected:
        string employeeID;
        string fullName;
        string position;
        string username;
        string password;

    public:
        void input();
        void output();
        string getEmployeeID();
        bool login(string username, string password);
};

class Admin : public Employee {
    public:
        void addEmployee();
        void deleteEmployee();
        void assignRole();
};

class TicketStaff : public Employee {
    public:
        void searchFlight(string flightID);
        void createTicket();
        void cancelTicket();
};

class FlightManager : public Employee{
    public:
        void updateFlight();
        void updateFlightStatus();
};

class Accountant : public Employee{
    public:
        void refundPayment();
        void revenue();
};

class AirlineManagementSystem{
    private:
        Flight* flights;
        Passenger* passengers;
        Ticket* tickets;
        Employee* employees;
        Airline* airlines;

        int flightCount;
        int passengerCount;
        int ticketCount;
        int employeeCount;
        int airlineCount;

    public:
        AirlineManagementSystem();
        ~AirlineManagementSystem();

        // Flight
        void addFlight();
        void deleteFlight();
        void updateFlight();
        void searchFlight(string flightID);
        void displayFlights();

        // Passenger
        void addPassenger();
        void deletePassenger();
        void updatePassenger();
        void searchPassenger(string passengerID);
        void displayPassengers();

        // Ticket
        void createTicket();
        void cancelTicket();
        void searchTicket(string ticketID);
        void displayTickets();

        // Employee
        void addEmployee();
        void deleteEmployee();
        void searchEmployee(string employeeID);

        // Airline
        void addAirline();
        void deleteAirline();
        void searchAirline(string airlineID);
        
};
#endif
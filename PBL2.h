#ifndef PBL2_H
#define PBL2_H

#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:
        string ID;
        string fullName;
    public:
        Person();
        virtual void input() = 0;
        virtual void output() = 0;
        string getID();
        string getFullName();
        virtual ~Person();
};

class Passenger : public Person{
    private:
        string username;
        string password;
        string gender;
        string citizenID;
        string phoneNumber;
        string email;
    public:
        Passenger();
        void input();
        void output();
        void updateInfo();
        bool login(string username, string password);
        string getPassengerID() const;
};

class Employee : public Person{
    private:
        string role;
        string username;
        string password;
    public:
        Employee();
        void input();
        void output();
        void updateInfo();
        bool login(string username, string password);
        string getRole() const;
        string getEmployeeID() const;
};

class Flight{
    private:
        string flightID;
        string departure;
        string destination;
        string departureTime;
        string arrivalTime;
        string status;
        int totalSeats;
        int bookedSeats;

    public:
        Flight();
        void input();
        void output();
        string getFlightID() const;
        void updateInfo();
        void updateStatus(string status);
        bool isFull();
        void increaseBookedSeats();
        void decreaseBookedSeats();
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
        Ticket();
        void input();
        void output();
        string getTicketID() const;
        string getPassengerID() const;
        string getFlightID() const;
        void bookTicket();
        void cancelTicket();
        void printTicket();
};


class AirlineBookingSystem{
    private:
        Flight* flight;
        Passenger* passenger;
        Employee* employee;
        Ticket* ticket;

        int flightCount;
        int passengerCount;
        int employeeCount;
        int ticketCount;

    public:
        AirlineBookingSystem();
        ~AirlineBookingSystem();

        void menu();
        void flightMenu();
        void passengerMenu();
        void employeeMenu();
        void ticketMenu();
        
        void addFlight();
        void deleteFlight();
        void updateFlight();
        int searchFlight(string flightID);
        void displayFlights();

        void addPassenger();
        void deletePassenger();
        void updatePassenger();
        int searchPassenger(string passengerID);
        void displayPassengers();

        void addEmployee();
        void deleteEmployee();
        void updateEmployee();
        int searchEmployee(string employeeID);
        void displayEmployees();

        void createTicket();
        void cancelTicket();
        int searchTicket(string ticketID);
        void displayTickets();

        // void sortPassengerByID(int left, int right);
        // void sortTicketByID(int left, int right, );
        // void sortFlightByID(int left, int right, );

        // void sortEmployeeByRole(int left, int right, );
        void sortFlightByTime();
        void sortPassengerByName();
        

};
#endif
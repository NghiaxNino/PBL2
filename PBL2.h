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
        string gender;
        string citizenID;
        string phoneNumber;
        string email;
    public:
        Passenger();
        void input();
        void output();
        void updateInfo();
        string getPassengerID();
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
        string getRole();
        string getEmployeeID();
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
        string getFlightID();
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
        string getTicketID();
        string getPassengerID();
        string getFlightID();
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
        
        void addFlight(bool (*cmp)(string, string));
        void deleteFlight(bool (*cmp)(string, string));
        void updateFlight(bool (*cmp)(string, string));
        int searchFlight(string flightID, bool (*cmp)(string, string));
        void displayFlights();

        void addPassenger(bool (*cmp)(string, string));
        void deletePassenger(bool (*cmp)(string, string));
        void updatePassenger(bool (*cmp)(string, string));
        int searchPassenger(string passengerID, bool (*cmp)(string, string));
        void displayPassengers();

        void addEmployee(bool (*cmp)(string, string));
        void deleteEmployee(bool (*cmp)(string, string));
        void updateEmployee(bool (*cmp)(string, string));
        int searchEmployee(string employeeID, bool (*cmp)(string, string));
        void displayEmployees();

        void createTicket(bool (*cmp)(string, string));
        void cancelTicket(bool (*cmp)(string, string));
        int searchTicket(string ticketID, bool (*cmp)(string, string));
        void displayTickets();

        void sortPassengerByID(int left, int right, bool (*cmp)(string, string));
        void sortTicketByID(int left, int right, bool (*cmp)(string, string));
        void sortFlightByID(int left, int right, bool (*cmp)(string, string));

        void sortEmployeeByRole(int left, int right, bool (*cmp)(string, string));

        void sortFlightByTime();
        void sortPassengerByName();
};
#endif
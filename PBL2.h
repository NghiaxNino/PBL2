#ifndef PBL2_H
#define PBL2_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
        string getUsername() const;
        string getPassword() const;
        bool login(string username, string password);
        string getPassengerID() const;
        string getGender() const;
        string getCitizenID() const;
        string getPhoneNumber() const;
        string getEmail() const;
        void setPassengerData(string id, string fullname, string username, string password,
                              string gender, string citizenID, string phoneNumber, string email);

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
        string getUsername() const;
        string getPassword() const;
        bool login(string username, string password);
        string getRole() const;
        string getEmployeeID() const;
        void setEmployeeData(string id, string fullname, string role, string username, string password);
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
        void updateInfo();
        void updateStatus(string status);
        bool isFull();
        void increaseBookedSeats();
        void decreaseBookedSeats();
        string getFlightID() const;
        string getDeparture() const;
        string getDestination() const;
        string getDepartureTime() const;
        string getArrivalTime() const;
        string getStatus() const;
        int getTotalSeats() const;
        int getBookedSeats() const;
        void setFlightData(string flightID, string departure, string destination, string departureTime, 
                           string arrivalTime, string status, int totalSeats, int bookedSeats);
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
        void input(string passengerID = "");        
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

        void createTicket(string passengerID = "");
        void cancelTicket(string passengerID = "");
        int searchTicket(string ticketID);
        void displayTickets();

        // void sortPassengerByID(int left, int right);
        // void sortTicketByID(int left, int right, );
        // void sortFlightByID(int left, int right, );

        // void sortEmployeeByRole(int left, int right, );
        void sortFlightByTime();
        void sortPassengerByName();

        void Menu();
        void flightMenu();
        void e_passengerMenu();
        void passengerMenu(int pos);
        void employeeMenu();
            void managerMenu();
            void staffMenu();
        void ticketMenu();
        int passengerLogin();
        int employeeLogin();

        void readEmployee();
        void saveEmployee();
        void readPassenger();
        void savePassenger();
        void readFlight();
        void saveFlight();

};
#endif
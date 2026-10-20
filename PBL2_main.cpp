#include "PBL2.h"

int main(){
    AirlineBookingSystem system1;

    system1.readPassengers();
    system1.readEmployees();
    system1.readFlights();
    
    system1.Menu();

    system1.savePassengers();
    system1.saveEmployees();
    system1.saveFlights();

    system("pause");
    return 0;
}
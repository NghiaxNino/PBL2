#include "PBL2.h"

int main(){
    AirlineBookingSystem system1;

    system1.readPassenger();
    system1.readEmployee();
    system1.readFlight();
    
    system1.Menu();

    system1.savePassenger();
    system1.saveEmployee();
    system1.saveFlight();

    system("pause");
    return 0;
}
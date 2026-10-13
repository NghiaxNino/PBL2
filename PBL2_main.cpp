#include "PBL2.h"

int main(){
    AirlineBookingSystem system1;
    string role;

    if(system1.employeeLogin(role)){
        if(role == "Manager") system1.menu();
        else if(role == "Staff") system1.staffMenu();
    }
    else{
        cout << "Dang nhap that bai\n";
    }
    system("pause");
    return 0;
}
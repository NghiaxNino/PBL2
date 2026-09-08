#include <bits/stdc++.h>
#include "PBL2.h"
using namespace std;
void Airline::input(){
    getline(cin >> ws, this-> airlineID);
    getline(cin >> ws, this-> airlineName);
    getline(cin >> ws, this-> country);
    getline(cin >> ws, this-> contactInfo);
}
void Airline::output(){
    cout<< this->airlineID <<endl;
    cout<< this->airlineName <<endl;
    cout<< this->country <<endl;
    cout<< this->contactInfo <<endl;
}
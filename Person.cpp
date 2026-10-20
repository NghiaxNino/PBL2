#include "PBL2.h"

Person::Person(){
    ID = "";
    fullName = "";
}

string Person::getID(){
    return ID;
}

string Person::getFullName(){
    return fullName;
}

Person::~Person(){
}

Passenger::Passenger(){
    username = "";
    password = "";
    citizenID = "";
    phoneNumber = "";
    email = "";
}

void Passenger::input(){
    cout << "Nhap username: ";
    getline(cin, username);
    cout << "Nhap password: ";
    getline(cin, password);
    cout << "Nhap ma hanh khach: ";
    getline(cin, ID);
    cout << "Nhap ho ten: ";
    getline(cin, fullName);
    cout << "Nhap gioi tinh: ";
    getline(cin, gender);
    cout << "Nhap CCCD: ";
    getline(cin, citizenID);
    cout << "Nhap so dien thoai: ";
    getline(cin, phoneNumber);
    cout << "Nhap email: ";
    getline(cin, email);
}

void Passenger::output(){
    cout << "\n===== THONG TIN HANH KHACH =====\n";
    cout << "Ma hanh khach: " << ID << endl;
    cout << "Ho ten: " << fullName << endl;
    cout << "Gioi tinh: " << gender<< endl;
    cout << "CCCD: " << citizenID << endl;
    cout << "So dien thoai: " << phoneNumber << endl;
    cout << "Email: " << email << endl;
}

void Passenger::updateInfo(){
    cout << "Nhap username: ";
    getline(cin, username);
    cout << "Nhap password: ";
    getline(cin, password);
    cout << "Nhap ho ten moi: ";
    getline(cin, fullName);
    cout << "Nhap gioi tinh moi: ";
    getline(cin, gender);
    cout << "Nhap so dien thoai moi: ";
    getline(cin, phoneNumber);
    cout << "Nhap email moi: ";
    getline(cin, email);
}

bool Passenger::login(string username, string password){
    return this->username == username && this->password == password;
}

string Passenger::getPassengerID() const{
    return ID;
}

string Passenger::getGender() const{
    return gender;
}

string Passenger::getCitizenID() const{
    return citizenID;
}

string Passenger::getPhoneNumber() const{
    return phoneNumber;
}

string Passenger::getEmail() const{
    return email;
}

string Passenger::getUsername() const{
    return username;
}

string Passenger::getPassword() const{
    return password;
}

void Passenger::setPassengerData(string id, string fullname, string username, string password,
                              string gender, string citizenID, string phoneNumber, string email)
{
    this->ID = id;
    this->fullName = fullname;
    this->username = username;
    this->password = password;
    this->gender = gender;
    this->citizenID = citizenID;
    this->phoneNumber = phoneNumber;
    this->email = email;
}


 Employee::Employee(){
    role = "";
    username = "";
    password = "";
}

void Employee::input(){
    cout << "Nhap username: ";
    getline(cin, username);
    cout << "Nhap password: ";
    getline(cin, password);
    cout << "Nhap ma nhan vien: ";
    getline(cin, ID);
    cout << "Nhap ho ten: ";
    getline(cin, fullName);
    cout << "Nhap chuc vu: ";
    getline(cin, role);
}

void Employee::output(){
    cout << "\n===== THONG TIN NHAN VIEN =====\n";
    cout << "Ma nhan vien: " << ID << endl;
    cout << "Ho ten: " << fullName << endl;
    cout << "Chuc vu: " << role << endl;
}

void Employee::updateInfo(){
    cout << "Nhap ho ten moi: ";
    getline(cin, fullName);
    cout << "Nhap chuc vu moi: ";
    getline(cin, role);
}

string Employee::getUsername() const{
    return username;
}

string Employee::getPassword() const{
    return password;
}

bool Employee::login(string username, string password){
    return this->username == username && this->password == password;
}

string Employee::getRole() const{
    return role;
}

string Employee::getEmployeeID() const{
    return ID;
}

void Employee::setEmployeeData(string id, string fullname, string role, string username, string password){
    this->ID = id;
    this->fullName = fullname;
    this->role = role;
    this->username = username;
    this->password = password;
}

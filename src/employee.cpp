//Author: Harry Allen
//Name: employee.cpp
//Desc: Source for employee.h

#include "../lib/employee.h"

employee::employee(string _first_name, string _last_name, short _age) : human(_first_name, _last_name, _age, 1){
    id_employee = assignNewEmployeeId();
    cout << "First Name:\t\t" << first_name << endl;
    cout << "Last Name:\t\t" << last_name << endl;
    cout << "ID Number:\t\t" << id_number << endl;
    cout << "User Classification:\t" << id_type << endl;
    cout << "Employee ID Number:\t" << id_employee << endl;
    cout << "\n--------------------\n" << endl;
}

employee::employee(string _first_name, string _last_name, short _age, int _id_number, int _id_employee) : human(_first_name, _last_name, _age, _id_number, 1), id_employee(_id_employee){
    cout << "First Name:\t\t" << first_name << endl;
    cout << "Last Name:\t\t" << last_name << endl;
    cout << "ID Number:\t\t" << id_number << endl;
    cout << "User Classification:\t" << id_type << endl;
    cout << "Employee ID Number:\t" << id_employee << endl;
    cout << "\n--------------------\n" << endl;
}

int employee::assignNewEmployeeId(){
    return (rand()%90000)+10000;
}

void employee::dispInformation(string _status){
    human::dispInformation(_status);
    cout << "Employee ID Number:\t" << id_employee << endl;
    cout << "\n--------------------\n" << endl;
}

int employee::getEmployeeId(){
    return id_employee;
}

//Author: Harry Allen
//Name: employee.h
//Desc: Header for employee.cpp

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../lib/human.h"
#include <iostream>
#include <string>

using namespace std;

class employee : public human{  //employee inherits human attributes
private:
    int id_employee;
public:
    employee(string, string, short);                //Constructor for initializing employee object (FName, LName, Age)
    employee(string, string, short, int, int);      //Constructor for existing employee (FName, LName, Age, ID Number, Employee ID Number)
    int assignNewEmployeeId();                      //Assigns random 5 digit number for employee
    int getEmployeeId();                            //Returns the object's Employee ID
    void dispInformation(string = "Employee");      //Displays current object's attributes
};

#endif //EMPLOYEE_H

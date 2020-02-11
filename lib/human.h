//Author: Harry Allen
//Name: human.h
//Desc: Header for human.cpp

#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

using namespace std;

class human{
protected:
    string first_name, last_name;   //First and Last names of user
    short age;                      //Age of user
    int id_number;                  //Id number (Applies to all derived objects)
    int id_type;                    //Defines object type (0: human, 1: employee)
public:
    human(string, string, short, int = 0);      //FirstName, LastName, Age, UserType
    human(string, string, short, int, int);     //Constructor for already exisitng user data (FName, LName, Age, ID, ID Type)
    string getFullName();                       //returns "first_name last_name"
    string getFirstName(int = 0);               //returns "first_name"
    string getLastName(int = 0);                //returns "last_name"
    short getAge();                             //returns age
    int getId();                                //returns pointer to id_number
    int assignNewId();                          //returns random number from 1 to 10000
    void dispInformation(string = "Regular");   //prints object attribute data to console (first_name, last_name, age, id_number[0])
};

#endif //HUMAN_H

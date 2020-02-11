//Author: Harry Allen
//Name: human.cpp
//Desc: Source for human.h

#include "../lib/human.h"

human::human(string _first_name, string _last_name, short _age, int _id_type) : first_name(_first_name), last_name(_last_name), age(_age), id_type(_id_type){
    id_number = assignNewId();
    if(!id_type){
        cout << "First Name:\t\t" << first_name << endl;
        cout << "Last Name:\t\t" << last_name << endl;
        cout << "ID Number:\t\t" << id_number << endl;
        cout << "User Classification:\t" << id_type << endl;
        cout << "\n--------------------\n" << endl;
    }
}

human::human(string _first_name, string _last_name, short _age, int _id_number, int _id_type) : first_name(_first_name), last_name(_last_name), age(_age), id_number(_id_number), id_type(_id_type){
    if(!id_type){
        cout << "First Name:\t\t" << first_name << endl;
        cout << "Last Name:\t\t" << last_name << endl;
        cout << "ID Number:\t\t" << id_number << endl;
        cout << "User Classification:\t" << id_type << endl;
        cout << "\n--------------------\n" << endl;
    }
}

string human::getFirstName(int _length){
    if(!_length){
        return first_name;
    }else{
        if(_length > first_name.length()){
            return first_name+"\t";
        }else{
            return first_name.substr(0, _length);
        }
    }
}

string human::getLastName(int _length){
    if(!_length){
        return last_name;
    }else{
        if(_length > last_name.length()){
            return last_name+"\t";
        }else{
            return last_name.substr(0, _length);
        }
    }
}

string human::getFullName(){
    return first_name+" "+last_name;
}

short human::getAge(){
    return age;
}

int human::getId(){
    return id_number;
}

int human::assignNewId(){
    return (rand()%9998)+1;
}

void human::dispInformation(string _status){
    cout << "Status:\t" << _status << endl;
    cout << "Name:\t" << getFullName() << endl;
    cout << "Age:\t" << getAge() << endl;
    cout << "ID:\t" << getId() << endl;
    if(!_status.compare("Regular")){
        cout << "\n--------------------\n" << endl;
    }
}

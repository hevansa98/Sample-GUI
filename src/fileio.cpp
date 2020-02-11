//Author: Harry Allen
//Name: fileio.cpp
//Desc: Source for fileio.h

#include "../lib/fileio.h"

fileio::fileio() : path(init_path()){
    ofstream initFile;
    if(!std::experimental::filesystem::exists(path+"/Sample-GUI/data/human.txt")){
        initFile.open(path+"/Sample-GUI/data/human.txt", ios::out | ios::binary);
        initFile << "FNAM\tLNAM\tAGE\tID" << endl;
        initFile.close();
    }
    if(!std::experimental::filesystem::exists(path+"/Sample-GUI/data/employee.txt")){
        initFile.open(path+"/Sample-GUI/data/employee.txt", ios::out | ios::binary);
        initFile << "FNAM\tLNAM\tAGE\tID\t\tEMID" << endl;
        initFile.close();
    }
}

string fileio::init_path(){
    QDir curDir;
    curDir.cdUp();
    return curDir.path().toUtf8().toStdString();
}

employee * fileio::getEmployee(int _eId){
    employee *tmp;
    ifstream fileIn;
    
    fileIn.open(path+"/Sample-GUI/data/employee.txt");
    
    fileIn >> f_name >> f_name >> f_name >> f_name >> f_name;
    
    while(fileIn >> f_name >> l_name >> age >> id_num >> id_employee){
        if(_eId == id_employee){
            tmp = new employee(f_name, l_name, age, id_num, id_employee);
            fileIn.close();
            return tmp;
        }        
    }
    fileIn.close();
    return nullptr;
}

human * fileio::getHuman(int _uId){
    human *tmp;
    ifstream fileIn;
    fileIn.open(path+"/Sample-GUI/data/human.txt");
    
    fileIn >> f_name >> f_name >> f_name >> f_name;
    
    while(fileIn >> f_name >> l_name >> age >> id_num){
        if(_uId == id_num){
            tmp = new human(f_name, l_name, age, id_num, 0);
            fileIn.close();
            return tmp;
        }        
    }
    fileIn.close();
    return nullptr;
}

void fileio::writeEmployee(employee* _user){
    ofstream fileOut;
    fileOut.open(path+"/Sample-GUI/data/employee.txt", ios::out | ios::app);
    fileOut << _user -> getFirstName(4) << "\t" << _user -> getLastName(4) << "\t" << _user -> getAge() << "\t" << _user -> getId() << "\t" << _user -> getEmployeeId() << endl;
    fileOut.close();
}

void fileio::writeHuman(human* _user){
    ofstream fileOut;
    fileOut.open(path+"/Sample-GUI/data/human.txt", ios::out | ios::app);
    fileOut << _user -> getFirstName(4) << "\t" << _user -> getLastName(4) << "\t" << _user -> getAge() << "\t" << _user -> getId() << endl;
    fileOut.close();
}

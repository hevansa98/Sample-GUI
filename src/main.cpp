#include "../lib/mainwindow.h"
#include "../lib/fileio.h"
#include "../lib/employee.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    srand(time(NULL));
    human *user1;
    employee *user2;
    fileio writeOut;

    user1 = new human("John", "Smith", 21);
    user2 = new employee("Flight", "McGrinch", 59);
    /*
        user1 -> dispInformation();
        user2 -> dispInformation();
        */
    writeOut.writeEmployee(user2);
    writeOut.writeHuman(user1);

    employee * newEmployee;
    newEmployee = writeOut.getEmployee(user2 -> getEmployeeId());

    human * newHuman;
    newHuman = writeOut.getHuman(user1 -> getId());

    if(!newEmployee){
        std::cout << "User is null!" << std::endl;
        delete newEmployee;
    }

    if(!newHuman){
        std::cout << "User is null!" << std::endl;
        delete newHuman;
    }

    delete user1, user2, newHuman, newEmployee;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

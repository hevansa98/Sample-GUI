#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression expression("[a-zA-Z]*");

    ui->AgeField->setValidator(new QIntValidator(0, 150, this));
    ui->UserNumField->setValidator(new QIntValidator(1000, 9999, this));
    ui->EmpNumField->setValidator(new QIntValidator(10000, 99999, this));
    ui->FNField->setValidator(new QRegularExpressionValidator(expression, this));
    ui->LNField->setValidator(new QRegularExpressionValidator(expression, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::fieldsFilled(int numFields){   //1: userID, 2: empID
    switch (numFields) {
    case 1:
        if(!ui->UserNumField->text().isEmpty()){
            return true;
        }else{return false;}
    case 2:
        if(!ui->EmpNumField->text().isEmpty()){
            return true;
        }else{return false;}
    case 3:
        if(!ui->FNField->text().isEmpty() && !ui->LNField->text().isEmpty() && !ui->AgeField->text().isEmpty()){
            return true;
        }else{return false;}
    case 4:
        if(!ui->FNField->text().isEmpty() && !ui->LNField->text().isEmpty() && !ui->AgeField->text().isEmpty() && !ui->UserNumField->text().isEmpty()){
            return true;
        }else{return false;}
    case 5:
        if(!ui->FNField->text().isEmpty() && !ui->LNField->text().isEmpty() && !ui->AgeField->text().isEmpty() && !ui->UserNumField->text().isEmpty() && !ui->EmpNumField->text().isEmpty()){
            return true;
        }else{return false;}
    default:
        std::cout << "ERROR: fieldsFilled() arg out of bounds!" << std::endl;
        return false;
    }
}

void MainWindow::on_CreateUserButton_clicked()
{
    if(fieldsFilled(3)){
        FName = ui->FNField->text().toStdString();
        LName = ui->LNField->text().toStdString();
        age = ui->AgeField->text().toInt();

        if(ui->EmpCheckBox->isChecked()){
            empNum = ui->EmpNumField->text().toInt();
            empObj = new employee(FName, LName, age);
            empObj -> dispInformation();
            fileObj -> writeEmployee(empObj);
        }else{
            humanObj = new human(FName, LName, age);
            humanObj -> dispInformation();
            fileObj -> writeHuman(humanObj);
        }
    }else{
        errorBox.setText("First Name, Last Name, and Age must be filled out.");
        errorBox.exec();
    }
}

void MainWindow::on_SearchUserButton_clicked()
{
    if(ui->EmpCheckBox->isChecked()){
        if(fieldsFilled(2)){
            empNum = ui->EmpNumField->text().toInt();
            empObj = fileObj -> getEmployee(empNum);
        }
    }else{
        if(fieldsFilled(1)){
            userNum = ui->UserNumField->text().toInt();
            humanObj = fileObj -> getHuman(userNum);
        }
    }
}

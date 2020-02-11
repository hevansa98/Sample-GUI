#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CreateUserButton_clicked()
{
    if(ui->EmpCheckBox->isChecked()){
        std::cout << "This works checked!" << std::endl;
    }else{
        std::cout << "This works unchecked!" << std::endl;
    }
}

void MainWindow::on_SearchUserButton_clicked()
{
    if(ui->EmpCheckBox->isChecked()){
        std::cout << "This works checked!" << std::endl;
    }else{
        std::cout << "This works unchecked!" << std::endl;
    }
}

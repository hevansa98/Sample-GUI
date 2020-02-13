#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "../lib/employee.h"
#include "../lib/fileio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_CreateUserButton_clicked();
    void on_SearchUserButton_clicked();

private:
    Ui::MainWindow *ui;

    bool fieldsFilled(int);
    short age;
    int empNum, userNum;

    string FName, LName;

    employee * empObj;
    human * humanObj;

    QMessageBox errorBox;

    fileio * fileObj = new fileio();
};
#endif // MAINWINDOW_H

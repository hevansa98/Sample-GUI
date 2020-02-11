#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_CreateUserButton_clicked();

    void on_SearchUserButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

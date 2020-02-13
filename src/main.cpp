#include "../lib/mainwindow.h"
#include "../lib/fileio.h"
#include "../lib/employee.h"

#include <QApplication>
#include <time.h>
#include <cstdlib>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

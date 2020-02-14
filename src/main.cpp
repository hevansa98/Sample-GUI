#include "../lib/mainwindow.h"
#include "../lib/camerawindow.h"
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
    CameraWindow c;
    w.show();
    c.show();
    return a.exec();
}

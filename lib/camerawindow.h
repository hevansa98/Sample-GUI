#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDir>

#include <unistd.h>

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/videoio.hpp>

#include "lib/human.h"

namespace Ui {
class CameraWindow;
}

class CameraWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CameraWindow(QWidget *parent = nullptr);
    void assignUser(human *);
    void initCast();
    ~CameraWindow();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_captureButton_pressed();
    void on_closeButton_pressed();
    void on_saveButton_pressed();

private:
    Ui::CameraWindow *ui;

    //Qt types

    QImage stallImg;
    QGraphicsPixmapItem pixmap;
    QDir projLocation;
    QString dirPath;

    //OpenCV types

    cv::VideoCapture video;
    cv::Mat frame;
    cv::Mat frameClone;

    //c++ types

    bool isLive = false;
    string profilePrefix;
};

#endif // CAMERAWINDOW_H

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

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/videoio.hpp>

namespace Ui {
class CameraWindow;
}

class CameraWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CameraWindow(QWidget *parent = nullptr);
    ~CameraWindow();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_captureButton_pressed();
    void on_closeButton_pressed();

private:
    Ui::CameraWindow *ui;

    QGraphicsPixmapItem pixmap;
    cv::VideoCapture video;

    bool isLive = false;
};

#endif // CAMERAWINDOW_H

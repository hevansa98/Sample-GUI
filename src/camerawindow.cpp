#include "lib/camerawindow.h"
#include "ui_camerawindow.h"

CameraWindow::CameraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CameraWindow)
{
    ui->setupUi(this);

    ui->cameraView->setScene(new QGraphicsScene(this));
    ui->cameraView->scene()->addItem(&pixmap);
}

CameraWindow::~CameraWindow()
{
    delete ui;
}

void CameraWindow::on_closeButton_pressed(){
    this->close();
}

void CameraWindow::on_captureButton_pressed(){
    cv::Mat frame;
    if(isLive){
        video.release();
        isLive = false;
        qApp->processEvents();
        QImage stallImg = QImage("/home/hawkeye/Sample-GUI/data/imgs/suspendCapture.jpg");
        pixmap.setPixmap(QPixmap::fromImage(stallImg));
        ui->cameraView->fitInView(&pixmap, Qt::KeepAspectRatio);
        ui->captureButton->setText("Capture");
        return;
    }
    video.open(0);
    video.set(3, 640);
    video.set(4, 480);
    while(video.isOpened()){
        video >> frame;
        if(!frame.empty()){
            copyMakeBorder(frame,
                           frame,
                           frame.rows/2,
                           frame.rows/2,
                           frame.cols/2,
                           frame.cols/2,
                           cv::BORDER_CONSTANT);

            QImage qimg(frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_RGB888);
            pixmap.setPixmap(QPixmap::fromImage(qimg.rgbSwapped()));
            ui->cameraView->fitInView(&pixmap, Qt::KeepAspectRatio);
        }        
        isLive = true;
        ui->captureButton->setText("Stop");
        qApp->processEvents();
    }
}

void CameraWindow::closeEvent(QCloseEvent *event){
    if(video.isOpened()){
        QMessageBox::warning(this, "Warning", "Stop the feed before closeing the application!");
        event->ignore();
    }else{
        event->accept();
    }
}

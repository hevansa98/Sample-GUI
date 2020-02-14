#include "lib/camerawindow.h"
#include "ui_camerawindow.h"

CameraWindow::CameraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CameraWindow)
{
    ui->setupUi(this);

    ui->cameraView->setScene(new QGraphicsScene(this));
    ui->cameraView->scene()->addItem(&pixmap);

    ui->captureButton->setIcon(QIcon("/home/hawkeye/Sample-GUI/data/imgs/record.png"));
    ui->captureButton->setIconSize(QSize(128, 128));

    ui->closeButton->setIcon(QIcon("/home/hawkeye/Sample-GUI/data/imgs/close.png"));
    ui->closeButton->setIconSize(QSize(128, 128));
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
        ui->captureButton->setIcon(QIcon("/home/hawkeye/Sample-GUI/data/imgs/record.png"));
        ui->captureButton->setIconSize(QSize(128, 128));
        return;
    }
    video.open(0);
    video.set(3, 640);  //640
    video.set(4, 480);  //480
    while(video.isOpened()){
        video >> frame;
        if(!frame.empty()){
            QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            pixmap.setPixmap(QPixmap::fromImage(qimg.rgbSwapped()));
            ui->cameraView->fitInView(&pixmap, Qt::KeepAspectRatio);
            ui->cameraView->centerOn(&pixmap);
        }        
        isLive = true;
        ui->captureButton->setIcon(QIcon("/home/hawkeye/Sample-GUI/data/imgs/stop.png"));
        ui->captureButton->setIconSize(QSize(128, 128));
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

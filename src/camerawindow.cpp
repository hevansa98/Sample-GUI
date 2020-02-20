#include "lib/camerawindow.h"
#include "ui_camerawindow.h"

CameraWindow::CameraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CameraWindow)
{
    ui->setupUi(this);

    projLocation.cdUp();
    dirPath = projLocation.absolutePath();
    dirPath += QString::fromStdString("/Sample-GUI");
    profilePrefix = projLocation.absolutePath().toUtf8().constData();

    ui->cameraView->setScene(new QGraphicsScene(this));
    ui->cameraView->scene()->addItem(&pixmap);

    ui->captureButton->setIcon(QIcon(dirPath + "/data/imgs/record.png"));
    ui->captureButton->setIconSize(QSize(128, 128));

    ui->saveButton->setIcon(QIcon(dirPath + "/data/imgs/save.png"));
    ui->saveButton->setIconSize(QSize(128, 128));

    ui->closeButton->setIcon(QIcon(dirPath + "/data/imgs/close.png"));
    ui->closeButton->setIconSize(QSize(128, 128));

}

CameraWindow::~CameraWindow()
{
    delete ui;
}

void CameraWindow::initCast(){  //MUST BE FIRST CALL (after constructor) IF USING CAMERA!

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
        ui->captureButton->setIcon(QIcon(dirPath + "/data/imgs/stop.png"));
        ui->captureButton->setIconSize(QSize(128, 128));
        qApp->processEvents();
    }
}

void CameraWindow::assignUser(human * user){
    profilePrefix += "/Sample-GUI/data/profile/" + to_string(user -> getId());
}

void CameraWindow::on_saveButton_pressed(){
        cv::imwrite(profilePrefix+"_PROFILE.png", frame);
}

void CameraWindow::on_closeButton_pressed(){
    this->close();
}

void CameraWindow::on_captureButton_pressed(){
    if(isLive){

        video.release();    //Stop recording

        isLive = false; //Kick out of state

        qApp->processEvents();  //Process threads

        //Update QGraphicsView

        cv::cvtColor(frame, frameClone, cv::COLOR_BGR2RGB);
        stallImg = QImage((uchar *) frameClone.data, frameClone.cols, frameClone.rows, frameClone.step, QImage::Format_RGB888);
        pixmap.setPixmap(QPixmap::fromImage(stallImg));
        ui->cameraView->fitInView(&pixmap, Qt::KeepAspectRatio);

        //Update Icons

        ui->captureButton->setIcon(QIcon(dirPath + "/data/imgs/record.png"));
        ui->captureButton->setIconSize(QSize(128, 128));
        return;
    }
    video.open(0);
    while(video.isOpened()){
        video >> frame;
        if(!frame.empty()){
            QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            pixmap.setPixmap(QPixmap::fromImage(qimg.rgbSwapped()));
            ui->cameraView->fitInView(&pixmap, Qt::KeepAspectRatio);
            ui->cameraView->centerOn(&pixmap);
        }        
        isLive = true;
        ui->captureButton->setIcon(QIcon(dirPath + "/data/imgs/stop.png"));
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

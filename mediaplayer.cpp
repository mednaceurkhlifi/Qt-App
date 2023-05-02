#include "mediaplayer.h"
#include "ui_mediaplayer.h"



mediaplayer::mediaplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediaplayer)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
        videoWidget = new QVideoWidget(this);
        player->setVideoOutput(videoWidget);

        ui->playerLayout->addWidget(videoWidget);
}

mediaplayer::~mediaplayer()
{
    delete ui;
}


void mediaplayer::on_openButton_clicked()
{

    QString fileName= "C:/Users/medna/OneDrive/Bureau/integration finale/2a3-2a3-smart-rdi-center-integration/sample/video.mp4";

    if (fileName != "") {
        player->setMedia(QUrl::fromLocalFile(fileName));
         player->play();
    }
}

void mediaplayer::on_playButton_clicked()
{


         player->play();
}

void mediaplayer::on_stopButton_clicked()
{
    player->pause();
}

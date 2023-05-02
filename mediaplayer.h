#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QDialog>
#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>

namespace Ui {
class mediaplayer;
}

class mediaplayer : public QDialog
{
    Q_OBJECT

public:
    explicit mediaplayer(QWidget *parent = nullptr);
    ~mediaplayer();

public slots:
    void on_playButton_clicked();
    void on_stopButton_clicked();
    void on_openButton_clicked();

private:
    Ui::mediaplayer *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // MEDIAPLAYER_H

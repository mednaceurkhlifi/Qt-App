#ifndef WIDGET_H
#define WIDGET_H
#include <QMainWindow>
#include "materiel.h"
#include <QSqlTableModel>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QFileDialog>
#include<QProgressBar>
#include<QSlider>
#include "mediaplayer.h"
#include "arduino.h"

#include <QWidget>

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();
private Q_SLOTS:
     void on_ajouter_clicked();

     void on_supprimer_clicked();

     void on_modifier_clicked();

    // void on_modifier_select();

     void on_table_materiel_activated(const QModelIndex &index);

     void on_search_clicked();

     void on_filter_clicked();



     void on_pdf_clicked();

     void on_mediaplayer_clicked();
private slots:


    void on_rechercher_textChanged();

    void on_comboBox_activated(const QString &arg1);

    void on_statistics_clicked();
    void update_label();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

private:
   Ui::widget *ui;
   mediaplayer *player;
    materiel M;
   // QMediaPlayer * player;
    QVideoWidget *vw;
    QProgressBar* bar;
    QSlider* slider;
    QByteArray data; // variable contenant les données reçues

    arduino A; // objet temporaire



};

#endif // WIDGET_H

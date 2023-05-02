#ifndef DIALOG_H
#define DIALOG_H

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
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
     Dialog(QWidget *parent = nullptr);
    ~Dialog();

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

private:
    Ui::Dialog *ui;
   mediaplayer *player;
    materiel M;
   // QMediaPlayer * player;
    QVideoWidget *vw;
    QProgressBar* bar;
    QSlider* slider;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire


};

#endif // DIALOG_H

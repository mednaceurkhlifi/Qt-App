#ifndef SPONSORING_H
#define SPONSORING_H
#include <QSqlTableModel>
#include <QMainWindow>
#include <QDialog>
#include <QObject>
#include "sponsor.h"
#include "arduino.h"
#include <arduino.h>
namespace Ui { class sponsoring; }

class sponsoring : public QDialog
{
    Q_OBJECT

public:
    explicit sponsoring(QWidget *parent = nullptr);
    ~sponsoring();

private slots:
    void on_ajouter_clicked();
   /* void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_tableView_activated(const QModelIndex &index);
    void on_camera_pic_clicked();
    void on_pdf_pic_clicked();
    void on_tri_pic_clicked();
    void on_rech_pic_clicked();
    void on_calendrier_pic_clicked();
    void on_stat_clicked();
    void on_tri_pic_2_clicked();
    void on_tri_pic_3_clicked(); */
    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_camera_pic_clicked();

    void on_pdf_pic_clicked();

    void on_tri_pic_clicked();

    void on_tri_pic_2_clicked();

    void on_tri_pic_3_clicked();

    void on_rech_pic_clicked();

    void on_stat_clicked();

    void on_calendrier_pic_clicked();

    void on_push1_clicked();

    void on_push0_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sponsoring *ui;
    sponsor spo;
    QByteArray data; // variable contenant les données reçues

       arduino A; // objet temporaire
};
#endif // SPONSORING_H

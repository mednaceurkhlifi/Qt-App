#ifndef STUDENT_H
#define STUDENT_H
#include <QObject>
#include "etudiant.h"
#include "arduino.h"

#include <QDialog>

namespace Ui {
class student;
}

class student : public QDialog
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr);
    ~student();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_menu_clicked();

    void on_pb_modifier_clicked();

    void on_tab_etudiant_activated(const QModelIndex &index);

    void on_pb_tri_asc_clicked();

    void on_pb_tri_desc_clicked();

    void on_send_clicked();

    void on_pb_pdf_clicked();

    void on_pb_recherche_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::student *ui;
    Etudiant E;
    arduino A;
    QByteArray data;
};

#endif // STUDENT_H

#ifndef ENCAD_H
#define ENCAD_H

#include <QDialog>
#include "encadrant.h"
#include <QSqlTableModel>
#include <QStandardItemModel>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class encad; }
QT_END_NAMESPACE

class encad : public QDialog
{
    Q_OBJECT

public:
    encad(QWidget *parent = nullptr);
    ~encad();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_search_clicked();

    void on_filter_clicked();

    void on_pdf_clicked();

    void on_table_encadrant_activated(const QModelIndex &index);

    void on_filter_2_clicked();

    void on_filter_3_clicked();

    void on_stat_clicked();

    void on_sendButton_clicked();

    void on_notification_clicked();

    void on_clearButton_clicked();

    void on_push0_clicked();

    void on_push1_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::encad *ui;
    encadrant e;
    QByteArray data; // variable contenant les données reçues

        //Arduino A; // objet temporaire
};
#endif // ENCAD_H

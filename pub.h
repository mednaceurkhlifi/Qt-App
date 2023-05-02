#ifndef PUB_H
#define PUB_H
#include "arduino.h"
#include "publication.h"
#include <QWidget>
#include <QPainter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>


namespace Ui {
class pub;
}

class pub : public QWidget
{
    Q_OBJECT

public:
    explicit pub(QWidget *parent = nullptr);
    ~pub();
private slots:
    void on_btn_delete_clicked();
    void on_ajouter_btn_clicked();
    void onTableClicked(const QModelIndex &);



    void on_btn_update_clicked();



    void on_modifier_clicked();

    void on_modifier_annuler_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_tri_pic_clicked();

    void on_tri_pic_2_clicked();

    void on_pushButton_clicked();



    void on_pushButton_7_clicked();



    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();


    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    void update_label();


    publication Ptmp;
    int selected_publication = -1;
    QByteArray data; // variable contenant les données reçues

        arduino A; // objet temporaire

private:
    Ui::pub *ui;
public :
    QWidget *getPubUi();

};

#endif // PUB_H

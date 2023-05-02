#include "student.h"
#include "ui_student.h"
#include "etudiant.h"
#include <QDate>
#include <QMessageBox>
#include <QValidator>
#include <QModelIndex>
#include <QCompleter>
#include <QSslSocket>
#include "smtp.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFile>
#include <QFileDialog>
#include <qpdfwriter.h>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtSerialPort/QSerialPort>
#include <QByteArray>
#include <QtSerialPort/QSerialPortInfo>
#include "widget.h"
#include "sponsoring.h"
#include "sponsor.h"
#include "pub.h"
#include "encad.h"
#include "encadrant.h"



student::student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999));
    ui->tab_etudiant->setModel(E.afficherEtudiant());
    connect(ui->pb_menu, &QPushButton::clicked, this, &student::on_pb_menu_clicked);

    //tooltips
    ui->pb_supprimer->setToolTip("Supprimer un etudiant par son ID");
    ui->pb_ajouter->setToolTip("Ajouter un etudiant a la liste");
    ui->pb_modifier->setToolTip("Modifier un etudiant dans la liste");
    ui->pb_tri_asc->setToolTip("trier la liste en ordre ascendant");
    ui->pb_tri_desc->setToolTip("trier la liste en ordre descendant");
    ui->pb_pdf->setToolTip("Exporter en PDF");
    ui->pb_recherche->setToolTip("Rechercher un etudiant par nom");
    ui->send->setToolTip("Enoyer le email");

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getArduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" << A.getArduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }



    QSqlQuery query,query1;
    QStringList wordlist,wordlist1;
    query.prepare("SELECT id_etudiant FROM etudiant");
    //query.prepare("SELECT nom FROM etudiant");
    int i=0;
    if(query.exec()) {

        while(query.next()) {
            wordlist.insert(i, query.value(i).toString());
        }

        QCompleter* completer = new QCompleter(wordlist, this);

        completer->setCaseSensitivity(Qt::CaseInsensitive);
        ui->le_supprimer->setCompleter(completer);
    }

    query1.prepare("SELECT nom FROM etudiant");
    int j=0;
    if(query1.exec()) {

        while(query1.next()) {
            wordlist1.insert(j, query1.value(i).toString());
        }

        QCompleter* completer1 = new QCompleter(wordlist1, this);

        completer1->setCaseSensitivity(Qt::CaseInsensitive);
        ui->recherche->setCompleter(completer1);
    }

}

student::~student()
{
    delete ui;
}

void student::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString email = ui->le_email->text();
    QString specialite = ui->le_specialite->text();
    QString mention = ui->le_mention->text();

    Etudiant E(id, nom,prenom,email, specialite,mention);
    bool test = E.ajouterEtudiant();
    QMessageBox msgBox;

    if(test)
    {
        ui->tab_etudiant->setModel(E.afficherEtudiant());
        ui->le_id->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_email->clear();
        ui->le_specialite->clear();
        ui->le_mention->clear();

        //update de wordlist
        QSqlQuery query;
        QStringList wordlist;
        query.prepare("SELECT id_etudiant FROM etudiant ORDER BY id_etudiant DESC");
        //query.prepare("SELECT nom FROM etudiant");
        int i=0;
        if(query.exec()) {

            while(query.next()) {
                wordlist.insert(i, query.value(i).toString());
            }

            QCompleter* completer = new QCompleter(wordlist, this);

            completer->setCaseSensitivity(Qt::CaseInsensitive);
            ui->le_supprimer->setCompleter(completer);

        }

        //msg
        msgBox.setText("Ajout avec succès");
    }
    else
        msgBox.setText("Etudiant existe deja, Verifier vos informations");
        msgBox.exec();

}

void student::on_pb_supprimer_clicked()
{
    Etudiant E1;
    E1.setID(ui->le_supprimer->text().toInt());
    bool test = E1.supprimerEtudiant(E1.getID());
    QMessageBox msgBox;



    if(test)
    {
        msgBox.setText("Suppression effectuée");
        ui->tab_etudiant->setModel(E.afficherEtudiant());
        ui->le_supprimer->clear();

        //update wordlist

        QSqlQuery query;
        QStringList wordlist;
        query.prepare("SELECT id_etudiant FROM etudiant ORDER BY id_etudiant ASC");
        //query.prepare("SELECT nom FROM etudiant");
        int i=0;
        if(query.exec()) {

            while(query.next()) {
                wordlist.insert(i, query.value(i).toString());
            }

            QCompleter* completer = new QCompleter(wordlist, this);

            completer->setCaseSensitivity(Qt::CaseInsensitive);
            ui->le_supprimer->setCompleter(completer);

        }
    }
    else
        msgBox.setText("Etudiant n'existe pas");
        msgBox.exec();
}

void student::on_pb_menu_clicked()
{
    if(ui->sidemenu->isVisible()) {
        ui->sidemenu->hide();
    }
    else
    ui->sidemenu->setVisible(true);
}

void student::on_pb_modifier_clicked()
{
    Etudiant etudiant;
    etudiant.setID(ui->le_id->text().toInt());
    etudiant.setNom(ui->le_nom->text());
    etudiant.setPrenom(ui->le_prenom->text());
    etudiant.setEmail(ui->le_email->text());
    etudiant.setSpecialite(ui->le_specialite->text());
    etudiant.setMention(ui->le_mention->text());

    bool test = etudiant.modifierEtudiant();

    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("modification effectuée");
        ui->tab_etudiant->setModel(E.afficherEtudiant());
        ui->le_id->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_email->clear();
        ui->le_specialite->clear();
        ui->le_mention->clear();
    }
    else
        msgBox.setText("Etudiant n'existe pas");
        msgBox.exec();
}


void student::on_tab_etudiant_activated(const QModelIndex &index)
{
    QSqlQuery query;
    QString val = ui->tab_etudiant->model()->data(index).toString();

    query.prepare("SELECT * FROM etudiant where id_etudiant='"+val+"' or nom='"+val+"' or prenom='"+val+"'");
    if(query.exec()) {
        while(query.next()) {
            ui->le_id->setText(query.value(0).toString());
            ui->le_nom->setText(query.value(1).toString());
            ui->le_prenom->setText(query.value(2).toString());
            ui->le_email->setText(query.value(3).toString());
            ui->le_specialite->setText(query.value(4).toString());
            ui->le_mention->setText(query.value(5).toString());
            ui->email->setText(query.value(3).toString());
            ui->le_supprimer->setText(query.value(0).toString());
        }
    }
}

void student::on_pb_tri_asc_clicked()
{   Etudiant E;
    ui->tab_etudiant->setModel(E.afficherEtudiantasc());
}

void student::on_pb_tri_desc_clicked()
{
    Etudiant E;
        ui->tab_etudiant->setModel(E.afficherEtudiantdesc());
}

void student::on_send_clicked()
{
    Smtp* smtp = new Smtp("your email","your password", "smtp.gmail.com");
    //connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("Sender", ui->email->text(),"Message de l'administration",ui->textemail->toPlainText());
    ui->textemail->clear();
    ui->email->clear();

}

void student::on_pb_pdf_clicked()
{

        QFile file("mypdf.pdf");
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(this, "Error", "Could not create file!");
            return;
        }

        QPdfWriter pdfWriter(&file);
        pdfWriter.setPageSize(QPagedPaintDevice::A4);
        pdfWriter.setPageMargins(QMarginsF(30, 30, 30, 30));

        QPainter painter(&pdfWriter);
        int i = 4000;
        painter.setPen(Qt::red); // change the color of the title to red
        painter.setFont(QFont("Time New Roman", 25));
        painter.drawText(2000,1000,"Liste Des Etudiants Disponibles");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 15));
        painter.drawRect(50,100,9000,13000);
        painter.drawRect(100,3000,8800,500);
        painter.setFont(QFont("Time New Roman", 9));
        painter.drawText(400,3300,"ID");
        painter.drawText(1000,3300,"NOM");
        painter.drawText(2200,3300,"Prenom");
        painter.drawText(3400,3300,"email");
        painter.drawText(5900,3300,"mention");
        painter.drawText(8100,3300,"specialite");

        // increase the vertical space between each line by 500
        i = 4500;

        painter.drawRect(100,3000,8800,8000);

        QSqlQuery query;
        query.prepare("select * from etudiant");
        query.exec();
        while (query.next())
        {
            painter.drawText(400,i,query.value(0).toString());
            painter.drawText(1000,i,query.value(1).toString());
            painter.drawText(2300,i,query.value(2).toString());
            painter.drawText(3400,i,query.value(3).toString());
            painter.drawText(5900,i,query.value(4).toString());
            painter.drawText(8100,i,query.value(5).toString());

            i = i + 500; // increase the vertical space between each line by 500
        }

        QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                    QObject::tr("PDF Enregistré!.\n"), QMessageBox::Ok);


}

void student::on_pb_recherche_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;

    query.prepare("SELECT * FROM etudiant WHERE nom LIKE :searchTerm OR prenom LIKE :searchTerm");
    query.bindValue(":searchTerm", "%" + ui->recherche->text() + "%");
    query.exec();

    model->setQuery(query);

    if (model->rowCount() == 0) {
        QMessageBox::warning(this, "Aucun étudiant trouvé", "Aucun étudiant ne correspond à votre recherche.");
    } else {
        ui->tab_etudiant->setModel(model);
        ui->tab_etudiant->show();
    }

}

void student::on_pushButton_clicked()
{
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from etudiant where mention = 'A' ");
        float place1=model->rowCount();
        model->setQuery("select * from etudiant where mention = 'B' ");
        float place2=model->rowCount();
        model->setQuery("select * from etudiant where mention = 'C' ");
        float place3=model->rowCount();
        float total= place1 + place2 + place3;

        QString a=QString("Les Etudiants avec mention A "+QString::number((place1 * 100)/total,'f',2)+"%" );
        QString b=QString("Les Etudiants avec mention B "+QString::number((place2 * 100)/total,'f',2)+"%" );
        QString c=QString("Les Etudiants avec mention C  "+QString::number((place3 * 100)/total,'f',2)+"%" );

        QPieSeries *series = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
        series->append(a,place1);
        series->append(b,place2);//concatiner 2 chaines
        series->append(c,place3);
        if (place1!=0)
        {
            QPieSlice *slice = series->slices().at(0);//the percentage the actual slice
            slice->setLabelVisible();
            slice->setPen(QPen(Qt::red));
        }
        if ( place2!=0)
           {
               // Add label, explode and define brush for 2nd slice
               QPieSlice *slice1 = series->slices().at(1);
               //slice1->setExploded();
               slice1->setLabelVisible();
           }
           if(place3!=0)
           {
               // Add labels to rest of slices
               QPieSlice *slice2 = series->slices().at(2);
               //slice1->setExploded();
               slice2->setLabelVisible();// Sets the label visibility for all contours in the collection
           }
           // Create the chart widget
           QChart *chart = new QChart();
           // Add data to chart with title and hide legend
           chart->addSeries(series); // widget
           chart->setTitle("Statistiques des Etudiants de laboratoire: "+ QString::number(total));
           chart->legend()->hide();
           // Used to display the chart
           QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->resize(1000,500);
           chartView->show();



}

void student::on_pushButton_7_clicked()
{

    if (A.write_to_arduino("1")) {
    Smtp* smtp = new Smtp("your email","password", "smtp.gmail.com");
    smtp->sendMail("INTELAB", "the recipient" ,"ALERTE URGENTE", "Temperature très elevée dans le laboratoire");


    QSqlQuery query;

    query.prepare("UPDATE ARDUINO SET STATUS = 'alarm on' WHERE TEMP >= 25");
    query.exec();
    }

}

void student::on_pushButton_8_clicked()
{
    if (A.write_to_arduino("0")) {
    QSqlQuery query;

    query.prepare("UPDATE ARDUINO SET STATUS = 'alarm off' WHERE TEMP >= 25");
    query.exec();
    }

}

void student::on_pushButton_4_clicked()
{
    widget* w = new widget();
    w->show();
    close();
}

void student::on_pushButton_3_clicked()
{
     QMessageBox::warning(this, "warning", "Vous etes deja sur cette fenetre...!");
}


void student::on_pushButton_5_clicked()
{
    sponsoring* sp =new sponsoring();
    sp->show();
    close();
}
//pub
void student::on_pushButton_6_clicked()
{
    pub *PubPage = new pub();
    PubPage->show();
    close();
}

void student::on_pushButton_2_clicked()
{
    encad *enc = new encad();
    enc->show();
    close();
}

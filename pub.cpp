#include "pub.h"
#include "ui_pub.h"
#include <QMessageBox>
#include "publication.h"
#include<QIntValidator>
#include <QDebug>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFile>
#include <QPdfWriter>
#include <QDialog>
#include <QtDebug>
#include <QSqlQuery>
#include <QFile>
#include <QFileDialog>
#include <QDialog>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QDesktopServices>
#include <QUrl>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QDesktopServices>
#include <QAbstractItemModel>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "calendar.h"
#include "arduino.h"
#include "widget.h"
#include "student.h"
#include "sponsoring.h"
#include "sponsor.h"
#include "encad.h"
pub::pub(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pub)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ptmp.afficher());

    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));

        ui->lineEdit_id_create->setValidator(new QIntValidator(0, 99999999,this));
        ui->lineEdit_sujet_create->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
        ui->lineEdit_propriete_create->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
        ui->lineEdit_description_create->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
        ui->nombrepub->setValidator(new QIntValidator(0, 99999999,this));
        int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getArduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getArduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).


}

pub::~pub()
{
    delete ui;
}

void pub::onTableClicked(const QModelIndex &index)
{
    selected_publication = index.row();
}

//ajout
void pub::on_ajouter_btn_clicked()
{
    int id = ui->lineEdit_id_create->text().toInt();
    QString sujet = ui->lineEdit_sujet_create->text();
    QString prorpiete = ui->lineEdit_propriete_create->text();
    QString desciption = ui->lineEdit_description_create->text();
    QDate date = ui->dateEdit_create->date();
    int nbpub = ui->nombrepub->text().toInt();

    if(ui->lineEdit_id_create->text() == ""||sujet == ""||prorpiete == ""||desciption=="" ||ui->nombrepub->text()=="")
    {
        QMessageBox::warning(nullptr, QObject::tr("Publication"),
                    QObject::tr("Fields are empty.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return;


    }


    if(Ptmp.researchID(id))
    {
        QMessageBox::warning(nullptr, QObject::tr("Publication"),
                    QObject::tr("Id already used.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }

    publication p(id,date,sujet,prorpiete,desciption,nbpub);

    if(!p.ajouter())
    {

        QMessageBox::warning(nullptr, QObject::tr("Publication"),
                    QObject::tr("Failed to add a publication.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }

    QMessageBox::information(nullptr, QObject::tr("Publication"),
                QObject::tr("Publication was added successfully.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    QString nomFile ="Historique";


                      //              lien      historique ****************************************************************************



               QFile file("C:/Users/medna/OneDrive/Bureau/integration finale/2a3-2a3-smart-rdi-center-integration/pdf/Historique.txt");
                 QString finalmsg="fichier ajouter avec succes";
                  if(!file.exists()){
                  finalmsg="fichier cree avec succes";
                  }
                 file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                 QTextStream txt(&file);
                   QString d_info = QDateTime::currentDateTime().toString();
                 QString message2=d_info+" - Un publication a été ajoutée avec un sujet:  "+ sujet +"\n";
                 txt << message2;

    ui->lineEdit_id_create->setText("");
    ui->lineEdit_sujet_create->setText("");
    ui->lineEdit_propriete_create->setText("");
    ui->lineEdit_description_create->setText("");
    ui->nombrepub->setText("");

    ui->tableView->setModel(p.afficher());
}

//modifier

void pub::on_btn_update_clicked()
{
    if(selected_publication == -1)
        return;


    ui->stackedWidget->setCurrentIndex(1);

    ui->lineEdit_id_modifier->setText(ui->tableView->model()->index(selected_publication,0).data().toString());
    ui->lineEdit_nbpub_modifier->setText(ui->tableView->model()->index(selected_publication,1).data().toString());
    ui->lineEdit_propriete_modifier->setText(ui->tableView->model()->index(selected_publication,2).data().toString());
    ui->lineEdit_description_modifier->setText(ui->tableView->model()->index(selected_publication,3).data().toString());
    ui->dateEdit_modifier->setDate(ui->tableView->model()->index(selected_publication,4).data().toDate());
    ui->lineEdit_sujet_modifier->setText(ui->tableView->model()->index(selected_publication,5).data().toString());



}



void pub::on_modifier_clicked()
{

    int id = ui->lineEdit_id_modifier->text().toInt();
    QString sujet = ui->lineEdit_sujet_modifier->text();
    QString prorpiete = ui->lineEdit_propriete_modifier->text();
    QString desciption = ui->lineEdit_description_modifier->text();
    QDate date = ui->dateEdit_modifier->date();
    int nbpub = ui->lineEdit_nbpub_modifier->text().toInt();

    if(ui->lineEdit_id_modifier->text() == ""||sujet == ""||prorpiete == ""||desciption=="" ""||ui->lineEdit_nbpub_modifier->text()=="")
    {
        QMessageBox::warning(nullptr, QObject::tr("Publication"),
                    QObject::tr("Fields are empty.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }



    publication p(id,date,sujet,prorpiete,desciption,nbpub);

    if(!p.modifier())
    {

        QMessageBox::warning(nullptr, QObject::tr("Publication"),
                    QObject::tr("Failed to update a publication.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }

    QMessageBox::information(nullptr, QObject::tr("Publication"),
                QObject::tr("Publication was updated successfully.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


    QString nomFile ="Historique";

                   //          lien historique        ***********************************

                 QFile file("C:/Users/medna/OneDrive/Bureau/integration finale/2a3-2a3-smart-rdi-center-integration/pdf/Historique.txt");
                 QString finalmsg="fichier ajouter avec succes";
                  if(!file.exists()){
                  finalmsg="fichier cree avec succes";
                  }
                 file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                 QTextStream txt(&file);
                   QString d_info = QDateTime::currentDateTime().toString();

                 QString message2=d_info+" - Un publication a été modifier avec un sujet:  "+ sujet +"\n";
                 txt << message2;



    selected_publication = -1;
    ui->tableView->setModel(p.afficher());
    ui->stackedWidget->setCurrentIndex(0);

}

void pub::on_modifier_annuler_clicked()
{
    selected_publication = -1;
    ui->stackedWidget->setCurrentIndex(0);
}

//delete
void pub::on_btn_delete_clicked()
{
    qDebug()<<"click";
    if(selected_publication == -1)
        return;
    int id = ui->tableView->model()->index(selected_publication,0).data().toInt();
        QString sujet = ui->tableView->model()->index(selected_publication,0).data().toString();


    Ptmp.supprimer(id);
    ui->tableView->setModel(Ptmp.afficher());
    QString nomFile ="Historique";

               //           lien    historique                                             ***********************************************


                 QFile file("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/pdf/Historique.txt");
                 QString finalmsg="fichier ajouter avec succes";
                  if(!file.exists()){
                  finalmsg="fichier cree avec succes";
                  }
                 file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                 QTextStream txt(&file);
                   QString d_info = QDateTime::currentDateTime().toString();

                 QString message2=d_info+" - Un publication a été supprimer avec un id:  "+ sujet +"\n";
                 txt << message2;

}
//recherche

void pub::on_lineEdit_4_textChanged(const QString &arg1)
{
   publication p;

         QString rech=ui->lineEdit_4->text();
         ui->tableView->setModel(p.Recherche(rech));
}

//tri
void pub::on_tri_pic_clicked()
{
    publication p;
    ui->tableView->setModel(Ptmp.triB());


}

void pub::on_tri_pic_2_clicked()
{
    publication p;
    ui->tableView->setModel(Ptmp.triA());
}

void pub::on_pushButton_8_clicked()
{
    publication p;
    ui->tableView->setModel(Ptmp.triN());
}



//pdf
void pub::on_pushButton_clicked()
{

    //         lien       PDF                                       ********************************************************

    QPdfWriter pdf("C:/Users/medna/OneDrive/Bureau/integration finale/2a3-2a3-smart-rdi-center-integration/pdf/publication.pdf");


     QPainter painter(&pdf);
                                QPixmap image("icons/intelab.jpg");

                                // Afficher l'image avec QPainter

                              painter.drawPixmap(423,417,image);
                  int i = 4000;
                         painter.setPen(Qt::darkCyan);
                         painter.setFont(QFont("Time New Roman", 25));
                         painter.drawText(3000,1400,"publication LIST");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Time New Roman", 15));
                         painter.drawRect(100,100,9400,2500);
                         painter.drawRect(100,3000,9400,500);
                         painter.setFont(QFont("Time New Roman", 9));
                         painter.drawText(500,3300,"ID_PUBLICATION");
                         painter.drawText(2000,3300,"PROPRIETE");
                         painter.drawText(3000,3300,"DESCRIPTION");
                         painter.drawText(4000,3300,"SUJET");
                         painter.drawText(5000,3300,"DATE_DE_PUBLICATION");
                          painter.drawText(7000,3300,"NOMBRE PUB");
                         painter.drawRect(100,3000,9400,9000);

                         QSqlQuery query;
                         query.prepare("select * from PUBLICATION");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(500,i,query.value(0).toString());
                             painter.drawText(2000,i,query.value(2).toString());
                             painter.drawText(3000,i,query.value(3).toString());
                             painter.drawText(4000,i,query.value(5).toString());
                             painter.drawText(5000,i,query.value(4).toString());
                             painter.drawText(7000,i,query.value(1).toString());




                            i = i + 350;
                         }
                         QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                         QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

//Excel

void pub::on_pushButton_9_clicked()
{
    QTableView *table;
                     table = ui->tableView;

                     QString filters("CSV files (.csv);;All files (.*)");
                     QString defaultFilter("CSV files (*.csv)");
                     QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                        filters, &defaultFilter);
                     QFile file(fileName);

                     QAbstractItemModel *model =  table->model();
                     if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                         QTextStream data(&file);
                         QStringList strList;
                         for (int i = 0; i < model->columnCount(); i++) {
                             if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                 strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                             else
                                 strList.append("");
                         }
                         data << strList.join(";") << "\n";
                         for (int i = 0; i < model->rowCount(); i++) {
                             strList.clear();
                             for (int j = 0; j < model->columnCount(); j++) {

                                 if (model->data(model->index(i, j)).toString().length() > 0)
                                     strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                 else
                                     strList.append("");
                             }
                             data << strList.join(";") + "\n";
                         }
                         file.close();
                         QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
                     }
}

//statistique

void pub::on_pushButton_7_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
               QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("select * from publication where nbpub < 4 ");
               float place1=model->rowCount();
               model->setQuery("select * from publication where nbpub  between 4 and 8 ");
               float place2=model->rowCount();
               model->setQuery("select * from publication where nbpub > 8 ");
               float place3=model->rowCount();
               float total=place1+place2+place3;

               QString a=QString("inferier 4 nombre publication faible . "+QString::number((place1*100)/total,'f',2)+"%" );
               QString b=QString("entre 4 et 8 nombre publication moyen .  "+QString::number((place2*100)/total,'f',2)+"%" );
               QString c=QString("plus de 10 nombre publication tres bien.   "+QString::number((place3*100)/total,'f',2)+"%" );

               QPieSeries *series = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
               series->append(a,place1);
               series->append(b,place2);//concatiner 2 chaines
               series->append(c,place3);

               QColor purpleColor("#7f3fbf");
                                  QBrush brush1(purpleColor);

                                  QColor pinkColor("#f562ff");
                                  QBrush brush2(pinkColor);

                                  series->slices().at(0)->setBrush(brush1);
                                  series->slices().at(1)->setBrush(brush2);




               if (place1!=0)
               {QPieSlice *slice = series->slices().at(0);//the percentage the actual slice
                   slice->setLabelVisible();
                   slice->setPen(QPen(Qt::red));}

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
               chart->setTitle("review de nombre de publication "+ QString::number(total));
               chart->legend()->hide();
               // Used to display the chart
               QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1000,500);
               chartView->show();
}


//arduino
void pub::update_label()
{
   QString data=A.read_from_arduino();
   // QString data1(data);
    float temperature = data.toFloat();


    if(temperature < 26)
    {
        QFont font("Arial", 10, QFont::Bold);
        ui->popupLabel->setText(data+"°C :Temperature normale");
        ui->popupLabel->setFont(font);
    ui->popupLabel->show();}


   else if (temperature >= 26)

       {
   QFont font("Arial", 10, QFont::Bold);
        ui->popupLabel->setText(data+"°C :Temperature élevée");
        ui->popupLabel->setFont(font);
    ui->popupLabel->show();}

    else ui->popupLabel->hide();

}
//**
//btn arduino***on/off//auto
void pub::on_pushButton_11_clicked()
{
    A.write_to_arduino("off");
}

void pub::on_pushButton_10_clicked()
{
    A.write_to_arduino("on");
}

void pub::on_pushButton_12_clicked()
{
     A.write_to_arduino("auto");
}

QWidget *pub::getPubUi()
{
    return  ui->pdf;
}

//les interfaces//
void pub::on_pushButton_4_clicked()
{
    widget* w = new widget();
    w->show();
    close();
}

void pub::on_pushButton_5_clicked()
{
    sponsoring* sp =new sponsoring();
    sp->show();
    close();
}

void pub::on_pushButton_3_clicked()
{
    student* s = new student();
    s->show();
    close();
}

void pub::on_pushButton_2_clicked()
{
    encad *enc = new encad();
    enc->show();
    close();
}

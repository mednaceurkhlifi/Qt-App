#include "sponsoring.h"
#include "sponsor.h"
#include<QIntValidator>
#include "connection.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QPainter>
#include <QtSql>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QPdfWriter>
#include "camera.h"
#include "ui_camera.h"
#include <QCameraViewfinder>
#include <QTextDocument>
#include <QPrinter>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "ui_sponsoring.h"
//#include "window.h"
#include "calendar.h"
#include "arduino.h"
#include "widget.h"
#include "student.h"
#include "pub.h"
#include "encad.h"
sponsoring::sponsoring(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sponsoring)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(100,999,this));
    ui->tableView->setModel(spo.afficher());
    ///////////////////////////////////////pour ajouter icons
    QPixmap pix1("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/camera.png");
    ui->camera_pic->setIcon(pix1);

    QPixmap pix2("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/calendar-date.png");
    ui->calendrier_pic->setIcon(pix2);

    QPixmap pix3("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/pdf.png");
    ui->pdf_pic->setIcon(pix3);

    QPixmap pix4("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/hamburger.png");
    ui->hamburger_pic->setIcon(pix4);

    QPixmap pix5("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/calendar-date.png");
    ui->calendrier_pic->setIcon(pix5);

    QPixmap pix6("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons.png");
    ui->encadrant_pic->setPixmap(pix6);

    QPixmap pix7("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/student.png");
    ui->student_pic->setPixmap(pix7);

    QPixmap pix8("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/flask.png");
    ui->materiel_pic->setPixmap(pix8);

    QPixmap pix9("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/search.png");

    //ui->rech_pic->setPixmap(pix9);


    QPixmap pix10("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/funnel.png");
    ui->tri_pic->setIcon(pix10);

    QPixmap pix13("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/funnel.png");
    ui->tri_pic_2->setIcon(pix13);

    QPixmap pix14("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/funnel.png");
    ui->tri_pic_3->setIcon(pix14);

    QPixmap pix11("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/handshake.png");
    ui->sponsor_pic->setPixmap(pix11);

    QPixmap pix12("C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/research.png");
    ui->research_pic->setPixmap(pix12);
    ///////////////////////////////////////
    ui->rech_pic->setIcon(pix9);
    ////////////////////////////////////////
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
        ////////////////////////////////////////
}

sponsoring::~sponsoring()
{
    delete ui;
}


void sponsoring::on_ajouter_clicked()
{
    int id_sponsor=ui->lineEdit->text().toInt();
    int contact=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit_6->text();
    float montant=ui->lineEdit_2->text().toFloat();
    float duree=ui->lineEdit_5->text().toFloat();
    sponsor s(id_sponsor,contact,nom,duree,montant);
    sponsor stmp;

    bool test=s.ajouter();

    if(test)
    {
        ui->tableView->setModel(s.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Ajout effectué\n"
                                                                        "Click Ok to exit."),QMessageBox::Ok);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Ajout non effectué ID_SPONSOR deja existe ou un erreur d'ajout\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
}

void sponsoring::on_supprimer_clicked()
{
    sponsor s1;
      s1.Setid_sponsor(ui->lineEdit_7->text().toInt());

      QSqlQuery query;
      query.prepare("SELECT * FROM sponsor WHERE id_sponsor = ?");
      query.addBindValue(ui->lineEdit_7->text().toInt());


      if (query.exec() && query.next()) {
          if(s1.supprimer(s1.Getid_sponsor()))
         { ui->tableView->setModel(spo.afficher());
          QMessageBox::information(nullptr, QObject::tr("Supression effectué"),
                      QObject::tr("sponsor supprimé.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

         }
      } else {
          QMessageBox::critical(nullptr, QObject::tr("Supression échoué"),
                      QObject::tr("sponsor non existant.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
ui->lineEdit_7->clear();
}


void sponsoring::on_modifier_clicked()
{
    int id_sponsor=ui->lineEdit->text().toInt();
    int contact=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit_6->text();
    float duree=ui->lineEdit_5->text().toFloat();
    float montant=ui->lineEdit_2->text().toFloat();


      sponsor s(id_sponsor,contact,nom,duree,montant);
          QSqlQuery query;
       query.prepare("SELECT * FROM sponsor WHERE id_sponsor = ?");
       query.addBindValue(ui->lineEdit->text().toInt());

       if (query.exec() && query.next()) {
           s.modifier();
             ui->tableView->setModel(spo.afficher());
             QMessageBox::information(nullptr, QObject::tr("Modification effectué"),
                         QObject::tr("sponsor modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       } else {
           QMessageBox::critical(nullptr, QObject::tr("Modification échoué"),
                       QObject::tr("Vous ne pouvez pas changer l'identifiant du sponsor.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       ui->lineEdit_3->clear();
       ui->lineEdit_5->clear();
       ui->lineEdit_6->clear();

}

void sponsoring::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from sponsor where id_sponsor='"+val+"' or duree='"+val+"' or nom='"+val+"' or montant='"+val+"' or contact='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit_5->setText(qry.value(1).toString());
            ui->lineEdit_3->setText(qry.value(2).toString());
            ui->lineEdit_2->setText(qry.value(3).toString());
            ui->lineEdit_6->setText(qry.value(4).toString());

        }
    }
}


void sponsoring::on_camera_pic_clicked()
{
    camera *c = new camera();
        c ->show();
}

void sponsoring::on_pdf_pic_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out << "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        "<style>\n"
        "body { text-align: center; position: relative; }\n" // Added relative positioning
        "table { margin-left: auto; margin-right: auto; }\n"
        "img { position: absolute; bottom: 0; right: 0; width: 200px; height: auto; }\n"
        ".footer { position: absolute; bottom: 0; left: 50%; transform: translateX(-50%); }\n" // Added footer class for centered message
        "</style>\n"
        << QString("<title>%1</title>\n").arg("eleve")
        << "</head>\n"
        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
        "<h1 style='text-align: center;'>Liste des Sponsors</h1>"

        "<table border=5 cellspacing=0 cellpadding=5>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
    {
        if (!ui->tableView->isColumnHidden(column))
        {
            out << QString("<th>%8</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";
    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView->isColumnHidden(column))
            {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%8</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out << "</table>\n";

    // Insert smaller image at the bottom right corner
    out << "<img src='file:///C:/Users/Fares/Desktop/2a3-2a3-smart-rdi-center-sponsor/intelab.png' style='position: absolute; bottom: 0; right: 0; width: 200px; height: auto;'>\n";

    // Add footer with message "Powered by Intelab"
    out << "<div class='footer'><p>Powered by Intelab</p></div>\n";

    out << "</body>\n"
           "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("mypdffile.pdf");

    // Set the page layout to landscape
    QPageLayout pageLayout = printer.pageLayout();
    pageLayout.setOrientation(QPageLayout::Landscape);
    printer.setPageLayout(pageLayout);

    // Print the document to the printer
    document->print(&printer);

    QMessageBox::information(nullptr, QObject::tr("Export Du PDF"),
                             QObject::tr("Export Du PDF effectué.\n"
                                         "Click Ok to exit."),
                             QMessageBox::Ok);




}

void sponsoring::on_tri_pic_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
   // QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("select * from SPONSOR ORDER BY duree DESC ");
          // q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->tableView->setModel(model);
           }
}


void sponsoring::on_tri_pic_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
   // QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("select * from SPONSOR ORDER BY montant DESC ");
          // q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->tableView->setModel(model);
           }
}


void sponsoring::on_tri_pic_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
   // QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("select * from SPONSOR ORDER BY id_sponsor DESC ");
          // q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->tableView->setModel(model);
           }
}

void sponsoring::on_rech_pic_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
       QString query = ui->lineEdit_4->text();
              QSqlQuery q;
              q.prepare("SELECT * FROM sponsor WHERE id_sponsor LIKE ? ");
              q.bindValue(0, "%" + query + "%");
              if (q.exec()) {
                  model->setQuery(q);
                  ui->tableView->setModel(model);

              }
ui->lineEdit_4->clear();
}

void sponsoring::on_stat_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
                   QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from sponsor where montant < 50 ");
                   float place1=model->rowCount();
                   model->setQuery("select * from sponsor where montant  between 50 and 100 ");
                   float place2=model->rowCount();
                   model->setQuery("select * from sponsor where montant > 100 ");
                   float place3=model->rowCount();
                   float total=place1+place2+place3;

                   QString a=QString("inferieur a 50 montant de sponsor faible . "+QString::number((place1*100)/total,'f',2)+"%" );
                   QString b=QString("entre 50 et 100 montant de sponsor moyen .  "+QString::number((place2*100)/total,'f',2)+"%" );
                   QString c=QString("plus de 100 montant de sponsor tres bien.   "+QString::number((place3*100)/total,'f',2)+"%" );

                   QPieSeries *series = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
                   series->append(a,place1);
                   series->append(b,place2);//concatiner 2 chaines
                   series->append(c,place3);
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
                   chart->setTitle("review de nombre de sponsor: "+ QString::number(total));
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);
                   chartView->show();

}

void sponsoring::on_calendrier_pic_clicked()
{
    Calendar *calendar = new Calendar(this);
       calendar->exec();
}

void sponsoring::on_push1_clicked()
{

    QSqlQuery query;
        query.prepare("SELECT * FROM sponsor WHERE id_sponsor = 1");
        if (!query.exec()) {
            qDebug() << "Error selecting sponsor from database:" << query.lastError().text();
            return;
        }
        if (!query.next()) {
            QMessageBox::critical(this, "Error", "Access denied: No sponsor with id_sponsor = 1 found.");
            return;
        }

        QByteArray data;
        data.append('1'); // append the value '1' to the byte array

        // write the byte array to the serial port
        if (A.write_to_arduino(data) == -1) {
            qDebug() << "Failed to write to Arduino";
        }

}

void sponsoring::on_push0_clicked()
{

    QSqlQuery query;
        query.prepare("SELECT * FROM sponsor WHERE id_sponsor = 1");
        if (!query.exec()) {
            qDebug() << "Error selecting sponsor from database:" << query.lastError().text();
            return;
        }
        if (!query.next()) {
            QMessageBox::critical(this, "Error", "Access denied: No sponsor with id_sponsor = 1 found.");
            return;
        }

        QByteArray data;
        data.append('0'); // append the value '0' to the byte array

        // write the byte array to the serial port
        if (A.write_to_arduino(data) == -1) {
            qDebug() << "Failed to write to Arduino";
        }

}

void sponsoring::on_pushButton_4_clicked()
{
    widget* w = new widget();
    w->show();
    close();
}

void sponsoring::on_pushButton_3_clicked()
{
    student* s = new student();
    s->show();
    close();
}

void sponsoring::on_pushButton_5_clicked()
{
    QMessageBox::warning(this, "warning", "Vous etes deja sur cette fenetre...!");

}
//pub
void sponsoring::on_pushButton_6_clicked()
{
    pub *PubPage = new pub();
    PubPage->show();
    close();
}

void sponsoring::on_pushButton_2_clicked()
{
    encad *enc = new encad();
    enc->show();
    close();
}

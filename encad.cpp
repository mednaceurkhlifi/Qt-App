#include "encad.h"
#include "ui_encad.h"
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "encadrant.h"
#include <QSystemTrayIcon>
#include<QIntValidator>
#include "connection.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QtSql>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QObject>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include "arduino.h"
#include "etudiant.h"
#include "student.h"
#include "smtp.h"
#include "widget.h"
#include "sponsoring.h"
#include "sponsor.h"
#include "pub.h"
encad::encad(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::encad)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100,999,this));
       ui->table_encadrant->setModel(e.afficher());
}

encad::~encad()
{
    delete ui;
}


void encad::on_ajouter_clicked()
{
    int id_encadrant=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    QString specialite=ui->le_specialite->text();
    QString etablissement=ui->le_etablissement->text();


    encadrant e(id_encadrant,nom,prenom,email,specialite,etablissement);
    QSqlQuery query;
    query.prepare("SELECT * FROM encadrant WHERE id_encadrant = ?");
    query.addBindValue(ui->le_id->text().toInt());

    if (query.exec() && query.next()) {

        QMessageBox::critical(nullptr, QObject::tr("Ajout échoué"),
                    QObject::tr("encadrant existe deja.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    } else {
        e.ajouter();
         ui->table_encadrant->setModel(e.afficher());

    }


     ui->le_id->clear();
     ui->le_nom->clear();
     ui->le_prenom->clear();
     ui->le_email->clear();
     ui->le_specialite->clear();
     ui->le_etablissement->clear();

}

void encad::on_supprimer_clicked()
{
    encadrant e1;
    e1.Setid_encadrant(ui->id_supp->text().toInt());

    QSqlQuery query;
    query.prepare("SELECT * FROM encadrant WHERE id_encadrant = ?");
    query.addBindValue(ui->id_supp->text().toInt());


    if (query.exec() && query.next()) {
        if(e1.supprimer(e1.Getid_encadrant()))
       { ui->table_encadrant->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supression effectué"),
                    QObject::tr("encadrant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
       }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Supression échoué"),
                    QObject::tr("encadrant non existant.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void encad::on_modifier_clicked()
{
    int id_encadrant=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    QString specialite=ui->le_specialite->text();
    QString etablissement=ui->le_etablissement->text();

    encadrant e(id_encadrant,nom,prenom,email,specialite,etablissement);
       QSqlQuery query;
    query.prepare("SELECT * FROM encadrant WHERE id_encadrant = ?");
    query.addBindValue(ui->le_id->text().toInt());

    if (query.exec() && query.next()) {
        e.modifier();
          ui->table_encadrant->setModel(e.afficher());


    } else {
        QMessageBox::critical(nullptr, QObject::tr("Modification échoué"),
                    QObject::tr("Vous ne pouvez pas changer l'identifiant de l'encadrant.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void encad::on_search_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
    QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("SELECT id_encadrant,nom,prenom,email,specialite,etablissement FROM encadrant WHERE id_encadrant LIKE ? ");
           q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->table_encadrant->setModel(model);

           }
}

void encad::on_filter_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
   // QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("SELECT id_encadrant,nom,prenom,email,specialite,etablissement FROM encadrant ORDER BY id_encadrant ASC ");
          // q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->table_encadrant->setModel(model);
           }

}

void encad::on_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->table_encadrant->model()->rowCount();
    const int columnCount = ui->table_encadrant->model()->columnCount();

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
        "<h1 style='text-align: center;'>Liste des Encadrants</h1>"

        "<table border=5 cellspacing=0 cellpadding=5>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
    {
        if (!ui->table_encadrant->isColumnHidden(column))
        {
            out << QString("<th>%8</th>").arg(ui->table_encadrant->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";
    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->table_encadrant->isColumnHidden(column))
            {
                QString data = ui->table_encadrant->model()->data(ui->table_encadrant->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%8</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out << "</table>\n";

    // Insert smaller image at the bottom right corner
    out << "<img src='file:///C:/Users/EXTRA/Documents/projet/intelab.png' style='position: absolute; bottom: 0; right: 0; width: 200px; height: auto;'>\n";

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

void encad::on_table_encadrant_activated(const QModelIndex &index)
{
    QSqlQuery query;
     QString val=ui->table_encadrant->model()->data(index).toString();
    query.prepare("select id_encadrant,nom,prenom,email,specialite,etablissement  from encadrant where id_encadrant='"+val+"' or nom='"+val+"' or prenom='"+val+"' or email='"+val+"' or specialite='"+val+"' or etablissement='"+val+"' "
                  );
    if (query.exec())
    {
      while(query.next())
      {
    ui->le_id->setText(query.value(0).toString());
    ui->le_nom->setText(query.value(1).toString());
    ui->le_prenom->setText(query.value(2).toString());
    ui->le_email->setText(query.value(3).toString());
    ui->le_specialite->setText(query.value(4).toString());
     ui->le_etablissement->setText(query.value(5).toString());
      }

    }
}

void encad::on_filter_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
   // QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("SELECT id_encadrant,nom,prenom,email,specialite,etablissement FROM encadrant ORDER BY nom ASC ");
          // q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->table_encadrant->setModel(model);
           }
}

void encad::on_filter_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
   // QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("SELECT id_encadrant,nom,prenom,email,specialite,etablissement FROM encadrant ORDER BY email ASC ");
          // q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->table_encadrant->setModel(model);
           }
}

void encad::on_stat_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
                   QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from encadrant where specialite = 'business' ");
                   float place1=model->rowCount();
                   model->setQuery("select * from encadrant where specialite = 'info' ");
                   float place2=model->rowCount();
                   model->setQuery("select * from encadrant where specialite = 'geniecv' ");
                   float place3=model->rowCount();
                   float total=place1+place2+place3;

                   QString a=QString("Encadrant en business. "+QString::number((place1*100)/total,'f',2)+"%" );
                   QString b=QString("Encadrant en info.  "+QString::number((place2*100)/total,'f',2)+"%" );
                   QString c=QString("Encadrant en genie civil.   "+QString::number((place3*100)/total,'f',2)+"%" );

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
                   chart->setTitle("review de nombre des encadrants: "+ QString::number(total));
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);
                   chartView->show();


}

void encad::on_sendButton_clicked()
{
    QString message = ui->lineEdit->text();
        ui->lineEdit->clear();
        QString currentText = ui->messagesLabel->text();
        if (!currentText.isEmpty()) {
            currentText += "\n";
        }
        currentText += "> " + message;
        ui->messagesLabel->setText(currentText);
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

              notifyIcon->setIcon(QIcon("C:/Users/EXTRA/star.png"));

              notifyIcon->show();
              notifyIcon->showMessage("elyes a envoyé :",message,QSystemTrayIcon::Information,15000);
}

void encad::on_notification_clicked()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

          notifyIcon->setIcon(QIcon("C:/Users/EXTRA/star.png"));

          notifyIcon->show();
          notifyIcon->showMessage("Reminder ","testing notification",QSystemTrayIcon::Information,15000);
}

void encad::on_clearButton_clicked()
{
 ui->messagesLabel->clear();
}

void encad::on_push0_clicked()
{
  /*  QSqlQuery query;
        query.prepare("SELECT * FROM encadrant WHERE id_encadrant = 1");
        if (!query.exec()) {
            qDebug() << "Error selecting encadrant from database:" << query.lastError().text();
            return;
        }
        if (!query.next()) {
            QMessageBox::critical(this, "Error", "Access denied: No encadrant with id_encadrant = 1 found.");
            return;
        }

        QByteArray data;
        data.append('0'); // append the value '0' to the byte array

        // write the byte array to the serial port
        if (A.write_to_arduino(data) == -1) {
            qDebug() << "Failed to write to Arduino";
        }*/
}

void encad::on_push1_clicked()
{
   /* QSqlQuery query;
        query.prepare("SELECT * FROM encadrant WHERE id_encadrant = 1");
        if (!query.exec()) {
            qDebug() << "Error selecting encadrant from database:" << query.lastError().text();
            return;
        }
        if (!query.next()) {
            QMessageBox::critical(this, "Error", "Access denied: No encadrant with id_encadrant = 1 found.");
            return;
        }

        QByteArray data;
        data.append('1'); // append the value '1' to the byte array

        // write the byte array to the serial port
        if (A.write_to_arduino(data) == -1) {
            qDebug() << "Failed to write to Arduino";
        }*/
}

void encad::on_pushButton_8_clicked()
{
    student* s = new student();
    s->show();
    close();
}

void encad::on_pushButton_9_clicked()
{
    widget* w = new widget();
    w->show();
    close();
}

void encad::on_pushButton_10_clicked()
{
    sponsoring* sp =new sponsoring();
    sp->show();
    close();
}

void encad::on_pushButton_11_clicked()
{
    pub *PubPage = new pub();
    PubPage->show();
    close();
}

void encad::on_pushButton_7_clicked()
{
    QMessageBox::warning(this, "warning", "Vous etes deja sur cette fenetre...!");
}

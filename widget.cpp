#include "widget.h"
#include "ui_widget.h"
#include "materiel.h"
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
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include <QSystemTrayIcon>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtGui>
#include "student.h"
#include "sponsoring.h"
#include "pub.h"
#include "encad.h"
widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100,999,this));
       ui->table_materiel->setModel(M.afficher());
    player = new mediaplayer(this);
    ui->popupLabel->hide();

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

widget::~widget()
{
    delete ui;
}

void widget::on_ajouter_clicked()
{
    int id_materiel=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    int quantite=ui->la_qte->text().toInt();
    QString disponibilite=ui->la_disp->text();
    float prix=ui->le_prix->text().toFloat();

    materiel m(id_materiel,nom,quantite,disponibilite,prix);
    QSqlQuery query;
    query.prepare("SELECT * FROM materiel WHERE id_materiel = ?");
    query.addBindValue(ui->le_id->text().toInt());

    if (query.exec() && query.next()) {

        QMessageBox::critical(nullptr, QObject::tr("Ajout échoué"),
                    QObject::tr("materiel existe deja.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    } else {
        m.ajouter();
         ui->table_materiel->setModel(M.afficher());

    }


     ui->le_id->clear();
     ui->le_nom->clear();
     ui->la_qte->clear();
     ui->la_disp->clear();
     ui->le_prix->clear();

     QSqlQuery q;
     if (q.exec("SELECT quantite FROM materiel WHERE quantite = 0")) {
             if (q.next()) {
                 q.prepare("update materiel set disponibilite='non' where id_materiel=:id_materiel"
                               );
                 q.bindValue(":id_materiel", id_materiel);
                        if (!q.exec()) {
                            qWarning() << "Impossible de mettre à jour la disponibilité";
                        }

  ui->table_materiel->setModel(M.afficher());}
}

    else if (q.exec("SELECT quantite FROM materiel WHERE quantite>0")) {
             if (q.next()) {
                 q.prepare("update materiel set disponibilite='oui' where id_materiel=:id_materiel"
                               );
                 q.bindValue(":id_materiel", id_materiel);
                        if (!q.exec()) {
                            qWarning() << "Impossible de mettre à jour la disponibilité";
                        }

  ui->table_materiel->setModel(M.afficher());}
}
}

void widget::on_supprimer_clicked()
{
    materiel m1;
    m1.Setid_materiel(ui->id_supp->text().toInt());

    QSqlQuery query;
    query.prepare("SELECT * FROM materiel WHERE id_materiel = ?");
    query.addBindValue(ui->id_supp->text().toInt());


    if (query.exec() && query.next()) {
        if(m1.supprimer(m1.Getid_materiel()))
       { ui->table_materiel->setModel(M.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supression effectué"),
                    QObject::tr("materiel supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
       }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Supression échoué"),
                    QObject::tr("materiel non existant.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

   }

void widget::on_modifier_clicked()
{
    int id_materiel=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    int quantite=ui->la_qte->text().toInt();
    QString disponibilite=ui->la_disp->text();
    float prix=ui->le_prix->text().toFloat();

    materiel m(id_materiel,nom,quantite,disponibilite,prix);
    QSqlQuery q;


    if (q.exec("SELECT quantite FROM materiel WHERE quantite = 0")) {
            if (q.next()) {

                q.prepare("update materiel set disponibilite='non' where id_materiel=:id_materiel"
                              );
                q.bindValue(":id_materiel", id_materiel);
                       if (!q.exec()) {
                           qWarning() << "Impossible de mettre à jour la disponibilité";
                       }

                     ui->table_materiel->setModel(M.afficher());

   QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

         notifyIcon->setIcon(QIcon("C:/Users/ines/Documents/projet/icons/notification.PNG"));

         notifyIcon->show();
         notifyIcon->showMessage("Attention! ","Materiel en rupture de stock",QSystemTrayIcon::Information,15000);


            }
            else {
                        qDebug() << "No record found with quantite = 0";
                        ui->popupLabel->hide();

                    }
    }
    else {
            qWarning() << "Failed to execute query:" << q.lastError().text();

        }
       QSqlQuery query;
    query.prepare("SELECT * FROM materiel WHERE id_materiel = ?");
    query.addBindValue(ui->le_id->text().toInt());

    if (query.exec() && query.next()) {
        m.modifier();
          ui->table_materiel->setModel(M.afficher());


    } else {
        QMessageBox::critical(nullptr, QObject::tr("Modification échoué"),
                    QObject::tr("Vous ne pouvez pas changer l'identifiant du materiel.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    ui->le_id->clear();
    ui->le_nom->clear();
    ui->la_qte->clear();
    ui->la_disp->clear();
    ui->le_prix->clear();








}


void widget::on_table_materiel_activated(const QModelIndex &index)
{


    QSqlQuery query;
     QString val=ui->table_materiel->model()->data(index).toString();
    query.prepare("select id_materiel,nom,quantite,disponibilite,prix  from materiel where id_materiel='"+val+"' or nom='"+val+"' or quantite='"+val+"' or disponibilite='"+val+"' or prix='"+val+"' "
                  );
    if (query.exec())
    {
      while(query.next())
      {
    ui->le_id->setText(query.value(0).toString());
    ui->le_nom->setText(query.value(1).toString());
    ui->la_qte->setText(query.value(2).toString());
    ui->la_disp->setText(query.value(3).toString());
    ui->le_prix->setText(query.value(4).toString());
      }

    }
}

void widget::on_search_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
    QString query = ui->rechercher->text();
           QSqlQuery q;
           q.prepare("SELECT id_materiel,nom,quantite,disponibilite,prix FROM materiel WHERE id_materiel LIKE ? ");
           q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->table_materiel->setModel(model);

           }
}

void widget::on_filter_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel(nullptr);

           QSqlQuery q;
           q.prepare("SELECT id_materiel,nom,quantite,disponibilite,prix FROM materiel ORDER BY quantite ASC ");
          // q.bindValue(0, "%" + query + "%");
           if (q.exec()) {
               model->setQuery(q);
               ui->table_materiel->setModel(model);
           }

}






void widget::on_pdf_clicked()
{

    QString strStream;
      QTextStream out(&strStream);
       out << "<img src='file:///C:/Users/hp/Desktop/2a3-2a3-smart-rdi-center/icons/pdf.png' style='position: absolute; top: 0; right: 0;'>\n";
      const int rowCount = ui->table_materiel->model()->rowCount();
      const int columnCount = ui->table_materiel->model()->columnCount();

      out << "<html>\n"

          "<head>\n"

          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          "<style>\n"
          "body { text-align: center; position: relative; }\n" // Added relative positioning
          "table { margin-left: auto; margin-right: auto; }\n"
          "img { position: absolute; top: 0; right: 0; width: auto; height: auto; }\n"
          ".footer { position: absolute; bottom: 0; left: 50%; transform: translateX(-50%); }\n" // Added footer class for centered message
          "</style>\n"
          << QString("<title>%1</title>\n").arg("materiel")
          << "</head>\n"
          "<body bgcolor=#ffffff link=#5000A0>\n"
          "      <h1 style='text-align: center;font-size: 15px; color: purple;font-weight: bold;'>Gestion des Materiels InteLab</h1> <br>  <h1 style='text-align: center;font-size: 15px; color: blue;'>Liste des Materiels</h1>   <br>"

          "<table border=1 cellspacing=2 cellpadding=15 >\n";

      // headers
      out << "<thead><tr bgcolor=#de90ff>";
      for (int column = 0; column < columnCount; column++)
      {
          if (!ui->table_materiel->isColumnHidden(column))
          {
              out << QString("<th style='font-size: 17px;'>%8</th>").arg(ui->table_materiel->model()->headerData(column, Qt::Horizontal).toString());
          }
      }
      out << "</tr></thead>\n";
      // data table
      for (int row = 0; row < rowCount; row++)
      {
          out << "<tr>";
          for (int column = 0; column < columnCount; column++)
          {
              if (!ui->table_materiel->isColumnHidden(column))
              {
                  QString data = ui->table_materiel->model()->data(ui->table_materiel->model()->index(row, column)).toString().simplified();
                  out << QString("<td style='font-size: 13px;' bkcolor=0>%8</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
              }
          }
          out << "</tr>\n";
      }

      out << "</table>\n";



      // Add footer with message "Powered by Intelab"
      out << "<div class='footer' ><p style='font-size: 14px;'>Powered by Intelab</p></div>\n";

      out << "</body>\n"
             "</html>\n";

      QTextDocument *document = new QTextDocument();
      document->setHtml(strStream);

      QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName("listemateriel.pdf");

      // Set the page layout to landscape
      QPageLayout pageLayout = printer.pageLayout();
      pageLayout.setOrientation(QPageLayout::Landscape);
      printer.setPageLayout(pageLayout);

      // Print the document to the printer
      document->print(&printer);


      QString listemateriel = "C:/Users/medna/OneDrive/Bureau/integration finale/2a3-2a3-smart-rdi-center-integration/listemateriel.pdf";
 QDesktopServices::openUrl(QUrl::fromLocalFile(listemateriel));


}



void widget::on_mediaplayer_clicked()
{
player->on_openButton_clicked();
player->show();


}


void widget::on_rechercher_textChanged()
{

   QSqlQueryModel *model = new QSqlQueryModel(nullptr);
   QString query = ui->rechercher->text();
          QSqlQuery q;
          q.prepare("SELECT id_materiel,nom,quantite,disponibilite,prix FROM materiel WHERE id_materiel LIKE ? ");
          q.bindValue(0, "%" + query + "%");
          if (q.exec()) {
              model->setQuery(q);
              ui->table_materiel->setModel(model);

          }
}

void widget::on_comboBox_activated(const QString &selectedOption)
{
    if (selectedOption == "id") {
        QSqlQueryModel *model = new QSqlQueryModel(nullptr);

               QSqlQuery q;
               q.prepare("SELECT id_materiel,nom,quantite,disponibilite,prix FROM materiel ORDER BY id_materiel ASC ");

               if (q.exec()) {
                   model->setQuery(q);
                   ui->table_materiel->setModel(model);
               }
           qDebug() << "Option 1 selected";
       } else if (selectedOption == "nom") {
        QSqlQueryModel *model = new QSqlQueryModel(nullptr);

               QSqlQuery q;
               q.prepare("SELECT id_materiel,nom,quantite,disponibilite,prix FROM materiel ORDER BY nom ASC ");

               if (q.exec()) {
                   model->setQuery(q);
                   ui->table_materiel->setModel(model);
               }
           qDebug() << "Option 2 selected";
       } else if (selectedOption == "quantite") {
        QSqlQueryModel *model = new QSqlQueryModel(nullptr);

               QSqlQuery q;
               q.prepare("SELECT id_materiel,nom,quantite,disponibilite,prix FROM materiel ORDER BY quantite ASC ");

               if (q.exec()) {
                   model->setQuery(q);
                   ui->table_materiel->setModel(model);
               }
           qDebug() << "Option 3 selected";
       }
}



void widget::on_statistics_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from materiel where quantite>0 ");
                   float place1=model->rowCount();
                   model->setQuery("select * from materiel where quantite=0 ");
                   float place2=model->rowCount();

                   float total=place1+place2;

                   QString a=QString("materiel diponible  . "+QString::number((place1*100)/total,'f',2)+"%" );
                   QString b=QString("materiel non diponible.  "+QString::number((place2*100)/total,'f',2)+"%" );


                   QPieSeries *series = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.

                   series->append(a,place1);
                   series->append(b,place2);//concatiner 2 chaines


                   QColor purpleColor("#7f3fbf");
                   QBrush brush1(purpleColor);

                   QColor pinkColor("#f562ff");
                   QBrush brush2(pinkColor);

                   series->slices().at(0)->setBrush(brush1);
                   series->slices().at(1)->setBrush(brush2);

                   if (place1!=0)
                   {QPieSlice *slice = series->slices().at(0);//the percentage the actual slice
                       slice->setLabelVisible();
                       slice->setPen(QPen(Qt::white));
                       QFont LabelFont;
                       LabelFont.setPointSize(10);

                       slice->setLabelFont(LabelFont);
                       QColor whiteColor(Qt::white);
                        slice->setLabelColor(whiteColor);
                   }
                   if ( place2!=0)
                   {
                       // Add label, explode and define brush for 2nd slice
                       QPieSlice *slice1 = series->slices().at(1);
                       //slice1->setExploded();
                       slice1->setLabelVisible();
                       QColor whiteColor(Qt::white);
                        slice1->setLabelColor(whiteColor);
                        QFont LabelFont;
                        LabelFont.setPointSize(10);

                        slice1->setLabelFont(LabelFont);
                   }

                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series); // widget
                   QFont titleFont;
                   titleFont.setPointSize(19);

                   chart->setTitleFont(titleFont);
                   QColor whiteColor(Qt::white);
                   chart->setTitleBrush(QBrush(whiteColor));
                   titleFont.setBold(true);
                   chart->setTitle("Statistique du materiel disponible de l'ensemble de "+ QString::number(total)+" materiels en total");
                   chart->legend()->hide();

                   chart->setBackgroundBrush(QBrush(QColor("#071e26")));




                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
                  // chartScene->addItem(chartView);

                 // chartView->setScene(chartScene);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);
                   chartView->setBackgroundBrush(QBrush(QColor("#071e26")));
                   chartView->setContentsMargins(0, 0, 0, 0); // remove any margins

                   QGraphicsPixmapItem *logoItem = new QGraphicsPixmapItem();
                     QPixmap logoPixmap("C:/Users/ines/Downloads/pie-chart.png");
                     logoItem->setPixmap(logoPixmap);

                     // Create the scene and add the logo and chart view
                     QGraphicsScene *chartScene = new QGraphicsScene();
                     QGraphicsProxyWidget *chartProxy = chartScene->addWidget(chartView);
                     chartProxy->setPos(0, logoPixmap.height());
                     chartScene->addItem(logoItem);

                     // Create the chart view for the scene
                     QGraphicsView *sceneView = new QGraphicsView(chartScene);
                     sceneView->setRenderHint(QPainter::Antialiasing);
                     sceneView->show();



}



void widget::update_label()
{
   QString data=A.read_from_arduino();
   // QString data1(data);
    float temperature = data.toFloat();


    if(temperature < 26)
    {
        ui->popupLabel->setText("Temperature normale");
    ui->popupLabel->show();}


   else if (temperature >= 26)

       {

        ui->popupLabel->setText("Temperature élevée");
    ui->popupLabel->show();}

    else ui->popupLabel->hide();

}


void widget::on_pushButton_3_clicked()
{
    student* s = new student();
    s->show();
    close();

}

void widget::on_pushButton_4_clicked()
{
    QMessageBox::warning(this, "warning", "Vous etes deja sur cette fenetre...!");

}

void widget::on_pushButton_5_clicked()
{
    sponsoring* sp =new sponsoring();
    sp->show();
    close();
}

void widget::on_pushButton_6_clicked()
{
    pub *PubPage = new pub();
    PubPage->show();
    close();
}

void widget::on_pushButton_2_clicked()
{
    encad *enc = new encad();
    enc->show();
    close();
}

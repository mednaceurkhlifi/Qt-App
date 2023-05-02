#include "publication.h"

#include <QSqlQuery>
#include<QPainter>
#include<QPdfWriter>

publication::publication()
{

}


publication::publication(int ID_PUBLICATION,QDate DATE_DE_PUBLICATION,QString SUJET,QString PROPRIETE,QString DESCRIPTION,int NBPUB)
{
    this->ID_PUBLICATION=ID_PUBLICATION;
    this->DATE_DE_PUBLICATION=DATE_DE_PUBLICATION;
    this->SUJET=SUJET;
    this->PROPRIETE=PROPRIETE;
    this->DESCRIPTION=DESCRIPTION;
    this->NBPUB=NBPUB;
}

bool publication::ajouter()
{
    QSqlQuery query;
    QString SqlQuery = "insert into publication (ID_PUBLICATION,DATE_DE_PUBLICATION,SUJET,PROPRIETE,DESCRIPTION,NBPUB) "
                         "VALUES (:ID_PUBLICATION,:DATE_DE_PUBLICATION,:SUJET,:PROPRIETE,:DESCRIPTION,:NBPUB)";
    query.prepare(SqlQuery);

    query.bindValue(":ID_PUBLICATION",ID_PUBLICATION);
    query.bindValue(":DATE_DE_PUBLICATION",DATE_DE_PUBLICATION);
    query.bindValue(":SUJET",SUJET);
    query.bindValue(":PROPRIETE",PROPRIETE);
    query.bindValue(":DESCRIPTION",DESCRIPTION);
    query.bindValue(":NBPUB",NBPUB);

    return query.exec();
}
QSqlQueryModel* publication::afficher()
{
    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("Select * from publication");
    return  model;
}
bool publication::researchID(int id)
{

    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(QString("Select * from publication where ID_PUBLICATION = %1;").arg(id));
    if(model->rowCount()>0)
        return  true;
    return false;
}

bool publication::modifier()
{
    QSqlQuery query;
    QString SqlQuery = "UPDATE publication set SUJET=:SUJET,PROPRIETE=:PROPRIETE,DESCRIPTION=:DESCRIPTION,DATE_DE_PUBLICATION=:DATE_DE_PUBLICATION ,NBPUB=:NBPUB where ID_PUBLICATION=:ID_PUBLICATION";

    query.prepare(SqlQuery);

    query.bindValue(":ID_PUBLICATION",ID_PUBLICATION);
    query.bindValue(":DATE_DE_PUBLICATION",DATE_DE_PUBLICATION);
    query.bindValue(":SUJET",SUJET);
    query.bindValue(":PROPRIETE",PROPRIETE);
    query.bindValue(":DESCRIPTION",DESCRIPTION);
    query.bindValue(":NBPUB",NBPUB);
    return query.exec();
}
bool publication::supprimer(int ID_PUBLICATION)
{
    QSqlQuery query;

    QString SqlQuery = "Delete FROM publication WHERE ID_PUBLICATION = :ID_PUBLICATION;";
    query.prepare(SqlQuery);

    query.bindValue(":ID_PUBLICATION",ID_PUBLICATION);

    return query.exec();
}
//recherche
QSqlQueryModel* publication::Recherche(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM publication WHERE ID_PUBLICATION LIKE '"+recherche+"%' OR PROPRIETE LIKE '"+recherche+"%' OR SUJET LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PUBLICATION"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROPRIETE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("SUJET"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCRIPTION"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DE_PUBLICATION"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBPUB"));
return model;
}

//tri asc desc par id
QSqlQueryModel * publication::triB()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM publication ORDER BY ID_PUBLICATION ASC");
        return model;
}


QSqlQueryModel * publication::triA()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM publication ORDER BY ID_PUBLICATION DESC");
        return model;
}

QSqlQueryModel * publication::triN()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM publication ORDER BY NBPUB DESC");
        return model;
}


//***pdf
void publication::genererPDFact()
{

    //         lien       PDF                                       ********************************************************

   QPdfWriter pdf("C:/Users/medna/OneDrive/Bureau/integration finale/2a3-2a3-smart-rdi-center-integration/pdf/publication.pdf");
    QPainter painter(&pdf);
   int i = 4000;
        painter.setPen(Qt::green);
        painter.setFont(QFont("Arial", 50));
        painter.drawText(1100,1200,"Liste Des publication");
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 15));
        painter.drawRect(100,100,7300,2600);
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(500,3300,"ID_PUBLICATION");
        painter.drawText(2000,3300,"PROPRIETE");
        painter.drawText(3000,3300,"SUJET");
        painter.drawText(4000,3300,"DESCRIPTION");
        painter.drawText(5000,3300,"DATE_DE_PUBLICATION");
        painter.drawText(7000,3300,"NBPUB");






        QSqlQuery query;
        query.prepare("select * from publication");
        query.exec();
        while (query.next())
        {
            painter.drawText(500,i,query.value(0).toString());
            painter.drawText(2000,i,query.value(2).toString());
            painter.drawText(3000,i,query.value(3).toString());
            painter.drawText(4000,i,query.value(5).toString());
            painter.drawText(5000,i,query.value(4).toString());
            painter.drawText(7000,i,query.value(1).toString());

           i = i + 500;
        }


}


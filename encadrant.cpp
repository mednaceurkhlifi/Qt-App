#include "encadrant.h"
#include <QSqlQuery>
#include <QString>
#include <QtDebug>
#include<QObject>

encadrant::encadrant()
{
id_encadrant=0;
nom="";
prenom="";
email="";
specialite="";
etablissement="";
}

encadrant::encadrant(int id_encadrant,QString nom,QString prenom,QString email,QString specialite,QString etablissement)
{
    this->id_encadrant=id_encadrant;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->specialite=specialite;
    this->etablissement=etablissement;

}
bool encadrant::ajouter()
{


    QSqlQuery query;
    QString id_string= QString::number(id_encadrant);


    query.prepare("INSERT INTO encadrant (id_encadrant, nom,prenom,email,specialite,etablissement) "
                  "VALUES (:id, :nom, :pr,:em,:sp,:et)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":pr", prenom);
    query.bindValue(":em", email);
    query.bindValue(":sp", specialite);
    query.bindValue(":et", etablissement);
  query.bindValue("sd","sd");
   return query.exec();

}

bool encadrant::modifier()
{


    QSqlQuery query;
    QString id_string= QString::number(id_encadrant);

    query.prepare("update encadrant set id_encadrant=:id_encadrant, nom=:nom,prenom=:prenom,email=:email,specialite=:specialite,etablissement=:etablissement where id_encadrant=:id_encadrant"
                  );
    query.bindValue(":id_encadrant", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":specialite", specialite);
     query.bindValue(":etablissement", etablissement);

   return query.exec();

}
bool encadrant :: supprimer(int id)
{ QSqlQuery query;
    query.prepare("Delete from encadrant WHERE id_encadrant=:id");
    query.bindValue(0, id);
    return query.exec();
}
QSqlQueryModel* encadrant :: afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel;
          model->setQuery("SELECT id_encadrant,nom,prenom,email,specialite,etablissement FROM encadrant");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("specialite"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("etablissement"));





          return model;

}

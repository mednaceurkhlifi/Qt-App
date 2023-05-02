#include "sponsor.h"
#include <QSqlQuery>
#include <QString>
#include <QtDebug>
#include<QObject>
/*
sponsor::sponsor()
{
    id_sponsor=0;
    duree=0;
    contact=0;
    montant=0;
    nom="";
}*/
sponsor::sponsor(int id_sponsor,int contact,QString nom,float duree,float montant)
{
    this->id_sponsor=id_sponsor;
    this->contact=contact;
    this->nom=nom;
    this->duree=duree;
    this->montant=montant;
}
bool sponsor::ajouter()
{
  QSqlQuery query;
  QString id_string = QString::number(id_sponsor);
  QString cont = QString::number(contact);
  QString mont = QString::number(montant);
  QString dur = QString::number(duree);
  query.prepare("INSERT INTO SPONSOR (ID_SPONSOR, DUREE, CONTACT, MONTANT, NOM)"
                "VALUES (:id_sponsor, :duree, :contact, :montant, :nom)");

  query.bindValue(":id_sponsor",id_string);
  query.bindValue(":duree",dur);
  query.bindValue(":contact",cont);
  query.bindValue(":montant",mont);
  query.bindValue(":nom",nom);
  // query.bindValue("sd","sd");

  return query.exec();
}

QSqlQueryModel * sponsor::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from SPONSOR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SPONSOR"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CONTACT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("MONTANT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM"));

    return model;
}

bool sponsor :: supprimer(int id)
{ /*
    QSqlQuery query;
    query.prepare("Delete from SPONSOR WHERE id_sponsor=:id");
    query.bindValue(0, id);
    return query.exec();
    */
    QSqlQuery query;
        query.prepare("Delete from SPONSOR WHERE id_sponsor=:id");
        query.bindValue(0, id);
        return query.exec();

}
bool sponsor::modifier()
{
    QSqlQuery query;
    QString id_string = QString::number(id_sponsor);
    QString cont = QString::number(contact);
    QString mont = QString::number(montant);
    QString dur = QString::number(duree);

    query.prepare("update SPONSOR set ID_SPONSOR=:id_sponsor, duree=:duree,contact=:contact,montant=:montant,nom=:nom where ID_SPONSOR=:id_sponsor"
                  );
    query.bindValue(":id_sponsor",id_string);
    query.bindValue(":duree",dur);
    query.bindValue(":contact",cont);
    query.bindValue(":montant",mont);
    query.bindValue(":nom",nom);
   return query.exec();

}


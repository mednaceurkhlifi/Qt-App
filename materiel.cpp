#include "materiel.h"
#include <QSqlQuery>
#include <QString>
#include <QtDebug>
#include<QObject>

materiel::materiel()
{
id_materiel=0;
nom="";
quantite=0;
disponibilite="";
prix=0;
}

materiel::materiel(int id_materiel,QString nom,int quantite,QString disponibilite,float prix)
{
    this->id_materiel=id_materiel;
    this->nom=nom;
    this->quantite=quantite;
    this->disponibilite=disponibilite;
    this->prix=prix;

}
bool materiel::ajouter()
{


    QSqlQuery query;
    QString id_string= QString::number(id_materiel);
    QString qte_string= QString::number(quantite);
    QString prix_string= QString::number(prix);

    query.prepare("INSERT INTO materiel (id_materiel, nom,quantite,disponibilite,prix) "
                  "VALUES (:id, :nom, :qte,:disp,:prix)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":qte", qte_string);
    query.bindValue(":disp", disponibilite);
    query.bindValue(":prix", prix_string);
  query.bindValue("sd","sd");
   return query.exec();

}

bool materiel::modifier()
{


    QSqlQuery query;
    QString id_string= QString::number(id_materiel);
    QString qte_string= QString::number(quantite);
    QString prix_string= QString::number(prix);

    query.prepare("update materiel set id_materiel=:id_materiel, nom=:nom,quantite=:quantite,disponibilite=:disponibilite,prix=:prix where id_materiel=:id_materiel"
                  );
    query.bindValue(":id_materiel", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", qte_string);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":prix", prix_string);

   return query.exec();

}
bool materiel :: supprimer(int id)
{ QSqlQuery query;
    query.prepare("Delete from materiel WHERE id_materiel=:id");
    query.bindValue(0, id);
    return query.exec();
}
QSqlQueryModel* materiel :: afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel;
          model->setQuery("SELECT id_materiel,nom,quantite,disponibilite,prix FROM materiel");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("disp"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));





          return model;

}



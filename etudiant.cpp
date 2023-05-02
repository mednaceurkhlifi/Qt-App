#include "etudiant.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>

Etudiant::Etudiant() {
    id_Etudiant=0;
    nomEtudiant="";
    prenomEtudiant="";
    email="";
    specialite="";
    mention="";
}
Etudiant::Etudiant(int id_Etudiant, QString nomEtudiant, QString prenomEtudiant, QString email, QString specialite, QString mention)
{
    this->id_Etudiant = id_Etudiant;
    this->nomEtudiant = nomEtudiant;
    this->prenomEtudiant = prenomEtudiant;    
    this->email = email;
    this->specialite = specialite;
    this->mention = mention;
}



bool Etudiant::ajouterEtudiant() {
    QSqlQuery query;
    QString id_string = QString::number(id_Etudiant);

    // Check if the student with the specified ID already exists
    query.prepare("SELECT COUNT(*) FROM etudiant WHERE id_etudiant = :id_etudiant");
    query.bindValue(":id_etudiant", id_string);
    if (!query.exec()) {
        return false;
    }
    query.next();
    if (query.value(0).toInt() > 0) {
        // Student already exists
        return false;
    }

    // Add the new student to the table
    query.prepare("INSERT INTO etudiant (id_etudiant, nom, prenom, email, specialite, mention) "
                  "VALUES (:id_etudiant, :nom, :prenom, :email, :specialite, :mention)");
    query.bindValue(":id_etudiant", id_string);
    query.bindValue(":nom", nomEtudiant);
    query.bindValue(":prenom", prenomEtudiant);
    query.bindValue(":email", email);
    query.bindValue(":specialite", specialite);
    query.bindValue(":mention", mention);
    return query.exec();
}


QSqlQueryModel* Etudiant::afficherEtudiant(){
          QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM etudiant");
          model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3,Qt::Horizontal, QObject::tr("Email"));
          model->setHeaderData(4,Qt::Horizontal, QObject::tr("Specialite"));
          model->setHeaderData(5,Qt::Horizontal, QObject::tr("Mention"));

         return model;
}



bool Etudiant::supprimerEtudiant(int id_Etudiant) {
    QSqlQuery query;
    QString id_string = QString::number(id_Etudiant);

    // Check if the student with the specified ID exists
    query.prepare("SELECT COUNT(*) FROM etudiant WHERE id_etudiant = :id_etudiant");
    query.bindValue(":id_etudiant", id_string);
    if (!query.exec()) {
        return false;
    }
    query.next();
    if (query.value(0).toInt() == 0) {
        // Student does not exist
        return false;
    }

    // Delete the student from the table
    query.prepare("DELETE FROM etudiant where id_etudiant = :id_etudiant");
    query.bindValue(":id_etudiant", id_string);
    return query.exec();
}




bool Etudiant::modifierEtudiant() {
    QSqlQuery query;
    QString id_string = QString::number(id_Etudiant);

    // Check if the student with the specified ID exists
    query.prepare("SELECT COUNT(*) FROM etudiant WHERE id_etudiant = :id_etudiant");
    query.bindValue(":id_etudiant", id_string);
    if (!query.exec()) {
        return false;
    }
    query.next();
    if (query.value(0).toInt() == 0) {
        // Student does not exist
        return false;
    }

    // Update the student's information
    query.prepare("UPDATE etudiant SET nom = :nom, prenom = :prenom, email = :email, "
                  "specialite = :specialite, mention = :mention where id_etudiant = :id_etudiant");
    query.bindValue(":id_etudiant", id_string);
    query.bindValue(":nom", nomEtudiant);
    query.bindValue(":prenom", prenomEtudiant);
    query.bindValue(":email", email);
    query.bindValue(":specialite", specialite);
    query.bindValue(":mention", mention);
    return query.exec();
}


QSqlQueryModel* Etudiant::afficherEtudiantasc(){
          QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM etudiant ORDER BY id_etudiant ASC");
          model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3,Qt::Horizontal, QObject::tr("Email"));
          model->setHeaderData(4,Qt::Horizontal, QObject::tr("Specialite"));
          model->setHeaderData(5,Qt::Horizontal, QObject::tr("Mention"));

         return model;
}

QSqlQueryModel* Etudiant::afficherEtudiantdesc(){
          QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM etudiant ORDER BY nom ASC");
          model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3,Qt::Horizontal, QObject::tr("Email"));
          model->setHeaderData(4,Qt::Horizontal, QObject::tr("Specialite"));
          model->setHeaderData(5,Qt::Horizontal, QObject::tr("Mention"));

         return model;
}

#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Etudiant
{
    int id_Etudiant;
    QString nomEtudiant;
    QString prenomEtudiant;
    //QString date_de_naissance;
    QString email;
    QString specialite;
    QString mention;


public:
    Etudiant();
    Etudiant(int id_Etudiant, QString nomEtudiant, QString prenomEtudiant, QString email, QString specialite, QString mention);

    //getters
    int getID(){return id_Etudiant;}
    QString getNom() {return nomEtudiant;}
    QString getPrenom() {return prenomEtudiant;}
    //QString getDate(){return date_de_naissance;}
    QString getEmail(){return email;}
    QString getSpecialte(){return specialite;}
    QString getMention(){return mention;}

    //setters
    void setID(int id){id_Etudiant=id;}
    void setNom(QString n){nomEtudiant=n;}
    void setPrenom(QString p){prenomEtudiant=p;}
    //void setDate(QString d){date_de_naissance=d;}
    void setEmail(QString e){email=e;}
    void setSpecialite(QString s){specialite=s;}
    void setMention(QString m){mention=m;}

    //autres fonctions
    bool ajouterEtudiant();
    QSqlQueryModel * afficherEtudiant();
    bool supprimerEtudiant(int id_Etudiant);
    bool modifierEtudiant();
    QSqlQueryModel * afficherEtudiantasc();
    QSqlQueryModel* afficherEtudiantdesc();

};

#endif // ETUDIANT_H

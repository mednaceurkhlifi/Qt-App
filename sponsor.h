#ifndef SPONSOR_H
#define SPONSOR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class sponsor
{
    int id_sponsor,contact;
    QString nom;
    float duree,montant;
public:
    sponsor()
    {
        id_sponsor=0;
        duree=0;
        contact=0;
        montant=0;
        nom="";
    };
    sponsor(int,int,QString,float,float);
    int Getid_sponsor() { return id_sponsor; }
           void Setid_sponsor(int val) { id_sponsor = val; }
           float Getduree() { return duree; }
           void Setduree(float val) { duree = val; }
           int Getcontact() { return contact; }
           void Setcontact(int val) { contact = val; }
           float Getmontant() { return montant; }
           void Setmontant(float val) { montant = val; }
           QString Getnom(){return nom;}
           void Setnom(QString val){nom=val;}

           bool ajouter();
           bool supprimer(int id);
           bool modifier();
           QSqlQueryModel* afficher();

};
#endif // SPONSOR_H

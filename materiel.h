#ifndef MATERIEL_H
#define MATERIEL_H
#include<QString>
#include<QSqlQueryModel>

class materiel
{
public:
       materiel();
       materiel(int id_materiel,QString nom,int quantite,QString disponibilite,float prix);

       //~materiel();


       int Getid_materiel() { return id_materiel; }

       void Setid_materiel(int val) { id_materiel = val; }

       QString Getnom() { return nom; }

       void Setnom(QString val) { nom = val; }

       int Getquantite() { return quantite; }

       void Setquantite(int val) { quantite = val; }

       QString Getdisponibilite() { return disponibilite; }

       void Setdisponibilite(QString val) { disponibilite = val; }

       float Getprix() { return prix; }

       void Setprix(float val) { prix = val; }
       bool modifier();
       bool ajouter();
       bool supprimer(int id);
       void rechercher(QString rech);
       QSqlQueryModel* afficher();



   private:
       int id_materiel;
       QString nom;
       int quantite;
       QString disponibilite;
       float prix;
};

#endif // MATERIEL_H

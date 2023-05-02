#ifndef ENCADRANT_H
#define ENCADRANT_H

#include<QString>
#include<QSqlQueryModel>

class encadrant
{
public:
       encadrant();
       encadrant(int id_encadrant,QString nom,QString prenom,QString email,QString specialite,QString etablissement);

       //~encadrant();


       int Getid_encadrant() { return id_encadrant; }
       void Setid_encadrant(int val) { id_encadrant = val; }

       QString Getnom() { return nom; }
       void Setnom(QString val) { nom = val; }

       QString Getprenom() { return prenom; }
       void Setprenom(QString val) { prenom = val; }

       QString Getemail() { return email; }
       void Setemail(QString val) { email = val; }

       QString Getspecialite() { return specialite; }
       void Setspecialite(QString val) { specialite = val; }

       QString Getetablissement() { return etablissement; }
       void Setetablissement(QString val) { etablissement = val; }






       bool modifier();
       bool ajouter();
       bool supprimer(int id);
       QSqlQueryModel* afficher();



   private:
       int id_encadrant;
       QString nom;
         QString prenom;
           QString email;
             QString specialite;
               QString etablissement;

};

#endif // ENCADRANT_H

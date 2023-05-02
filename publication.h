#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <QSqlQueryModel>
#include <QDate>
class publication
{
private:
    int ID_PUBLICATION;
    QDate DATE_DE_PUBLICATION;
    QString SUJET;
    QString PROPRIETE;
    QString DESCRIPTION;
    int NBPUB;

public:
    publication();
    publication(int,QDate,QString,QString,QString,int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool researchID(int);
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel* Recherche(QString);
    QSqlQueryModel * triB();
    QSqlQueryModel * triA();
    QSqlQueryModel * triN();
     void genererPDFact();
};

#endif // PUBLICATION_H

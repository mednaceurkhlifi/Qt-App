#include "mainwindow.h"
#include "student.h"
#include "connection.h"
#include <QMessageBox>
#include <QSslSocket>
#include "smtp.h"
#include <QCoreApplication>
#include <QtNetwork>
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    //declaration des variables
    QApplication a(argc, argv);

    Connection c;

    //connection

    bool test=c.createconnect(); // doit etre declaree avant le student s pour que l'affichage fonctionne

    student s;
    login l;


    if(test)
    {

        if(l.exec() == QDialog::Accepted) {
        s.show();

        }
        else
        {
            return 0;
        }



    }


    return a.exec();
}

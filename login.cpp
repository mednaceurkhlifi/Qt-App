#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSystemTrayIcon>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->label_3->hide();
    ui->label_4->hide();
    ui->pushButton_2->hide();
    ui->forgottenpass->hide();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    ui->label_3->hide();
    ui->label_4->hide();
    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM employe WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if(query.exec() && query.next()) {
        accept(); // login successful
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

          notifyIcon->setIcon(QIcon("C:/Users/medna/OneDrive/Bureau/login.png"));

          notifyIcon->show();
          notifyIcon->showMessage("Login successful","you are now connected to the INTELAB desktop application", QIcon("C:/Users/medna/OneDrive/Bureau/login.png") ,15000);
    }
    else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");

    }
}

void login::on_pushButton_3_clicked()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->pushButton->hide();
    ui->label_3->show();
    ui->label_4->show();
    ui->pushButton_2->show();
    ui->forgottenpass->show();
    ui->login_2->hide();




}

void login::on_pushButton_2_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQuery query;
    query.prepare("UPDATE employe SET password ='"+password+"' where username ='"+username+"'");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if(query.exec())
    {
        ui->label->show();
        ui->label_2->show();
        ui->pushButton->show();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->pushButton_2->hide();
        ui->forgottenpass->hide();
        ui->login_2->show();
    }
}

/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLabel *login_2;
    QLabel *forgottenpass;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(980, 579);
        login->setStyleSheet(QLatin1String("*{\n"
"\n"
"background-color:transparent;\n"
"color: #aa54ff; \n"
"}\n"
"\n"
"\n"
"\n"
"#centralwidget{\n"
"background-color: #040f13;\n"
"}\n"
"#sidemenu{\n"
"background-color: #071e26; \n"
"border-radius: 20px; \n"
"}\n"
"#ajouter \n"
"{\n"
"padding: 20px; \n"
"background-color: #7f3fbf; \n"
"border-radius: 5px;\n"
"color : #fff;\n"
"}\n"
"QPushButton,QLineEdit{\n"
"\n"
"background-color: #040f13; \n"
"border-radius: 5px; }\n"
"#header{\n"
"background-color: #071e26; \n"
"border-radius: 10px;\n"
"}\n"
"#rightsidemenu\n"
"{\n"
"background-color: #071e26; \n"
"border-radius: 20px; \n"
"}\n"
"\n"
"#mainbody{\n"
"background-color: #071e26; \n"
"border-radius: 10px;\n"
"}"));
        username = new QLineEdit(login);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(470, 240, 241, 22));
        password = new QLineEdit(login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(470, 290, 241, 22));
        password->setEchoMode(QLineEdit::Password);
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 236, 56, 20));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 290, 56, 16));
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 400, 141, 31));
        pushButton_3 = new QPushButton(login);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 400, 131, 31));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 240, 91, 16));
        label_4 = new QLabel(login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 290, 161, 20));
        pushButton_2 = new QPushButton(login);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 400, 131, 31));
        login_2 = new QLabel(login);
        login_2->setObjectName(QStringLiteral("login_2"));
        login_2->setGeometry(QRect(450, 70, 331, 91));
        QFont font;
        font.setPointSize(48);
        login_2->setFont(font);
        forgottenpass = new QLabel(login);
        forgottenpass->setObjectName(QStringLiteral("forgottenpass"));
        forgottenpass->setGeometry(QRect(230, 60, 751, 101));
        forgottenpass->setFont(font);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("login", "username", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "Password", Q_NULLPTR));
        pushButton->setText(QApplication::translate("login", "login", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("login", "mot de passe oubli\303\251", Q_NULLPTR));
        label_3->setText(QApplication::translate("login", "entrer votre nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("login", "entrer le nouveau mot de passe ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("login", "ok", Q_NULLPTR));
        login_2->setText(QApplication::translate("login", "LOGIN", Q_NULLPTR));
        forgottenpass->setText(QApplication::translate("login", "mot de passe oubli\303\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

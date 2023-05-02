/********************************************************************************
** Form generated from reading UI file 'sponsoring.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPONSORING_H
#define UI_SPONSORING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_sponsoring
{
public:
    QFrame *frame_2;
    QFrame *sidemenu;
    QPushButton *pushButton_6;
    QLabel *research_pic;
    QPushButton *pushButton_5;
    QLabel *sponsor_pic;
    QPushButton *pushButton_4;
    QLabel *materiel_pic;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *student_pic;
    QLabel *encadrant_pic;
    QFrame *mainbody;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QPushButton *pdf_pic;
    QPushButton *tri_pic;
    QTableView *tableView;
    QPushButton *rech_pic;
    QPushButton *tri_pic_2;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *tri_pic_3;
    QLabel *label_7;
    QPushButton *push0;
    QPushButton *push1;
    QFrame *rightsidemenu;
    QPushButton *ajouter;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QPushButton *supprimer;
    QPushButton *modifier;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QFrame *header;
    QPushButton *hamburger_pic;
    QLabel *label;
    QPushButton *stat;
    QPushButton *calendrier_pic;
    QPushButton *camera_pic;

    void setupUi(QDialog *sponsoring)
    {
        if (sponsoring->objectName().isEmpty())
            sponsoring->setObjectName(QStringLiteral("sponsoring"));
        sponsoring->resize(1168, 727);
        sponsoring->setStyleSheet(QLatin1String("*{\n"
"	background-color: rgb(4, 15, 19);\n"
"\n"
"color: #aa54ff; \n"
"}\n"
"#filter,#mediaplayer,#notif,#pdf{\n"
"background-color: transparent;\n"
"}\n"
"\n"
"\n"
"#centralwidget{\n"
"background-color: #040f13;\n"
"}\n"
"#sidemenu{\n"
"background-color: #071e26; \n"
"border-radius: 20px; \n"
"}\n"
"#ajouter,#supprimer,#modifier\n"
"{\n"
"padding: 20px; \n"
"background-color: #7f3fbf; \n"
"border-radius: 5px;\n"
"color : #fff;\n"
"}\n"
"QPushButton,QLineEdit{\n"
"padding: 20px; \n"
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
        frame_2 = new QFrame(sponsoring);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(-30, 120, 1111, 601));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        sidemenu = new QFrame(frame_2);
        sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->setGeometry(QRect(40, 50, 181, 431));
        pushButton_6 = new QPushButton(sidemenu);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 60, 141, 28));
        research_pic = new QLabel(sidemenu);
        research_pic->setObjectName(QStringLiteral("research_pic"));
        research_pic->setGeometry(QRect(30, 60, 21, 20));
        research_pic->setPixmap(QPixmap(QString::fromUtf8("../../2a3-2a3-smart-rdi-center-sponsor - Copie/icons/research.png")));
        pushButton_5 = new QPushButton(sidemenu);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 100, 141, 29));
        sponsor_pic = new QLabel(sidemenu);
        sponsor_pic->setObjectName(QStringLiteral("sponsor_pic"));
        sponsor_pic->setGeometry(QRect(40, 100, 21, 21));
        sponsor_pic->setPixmap(QPixmap(QString::fromUtf8("../../2a3-2a3-smart-rdi-center-sponsor - Copie/icons/handshake.png")));
        pushButton_4 = new QPushButton(sidemenu);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 150, 141, 29));
        materiel_pic = new QLabel(sidemenu);
        materiel_pic->setObjectName(QStringLiteral("materiel_pic"));
        materiel_pic->setGeometry(QRect(40, 150, 20, 20));
        materiel_pic->setPixmap(QPixmap(QString::fromUtf8("../../2a3-2a3-smart-rdi-center-sponsor - Copie/icons/flask.png")));
        pushButton_2 = new QPushButton(sidemenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 20, 141, 29));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/teacher.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_3 = new QPushButton(sidemenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 200, 141, 29));
        student_pic = new QLabel(sidemenu);
        student_pic->setObjectName(QStringLiteral("student_pic"));
        student_pic->setGeometry(QRect(40, 200, 21, 21));
        student_pic->setPixmap(QPixmap(QString::fromUtf8("../../2a3-2a3-smart-rdi-center-sponsor - Copie/icons/student.png")));
        encadrant_pic = new QLabel(sidemenu);
        encadrant_pic->setObjectName(QStringLiteral("encadrant_pic"));
        encadrant_pic->setGeometry(QRect(20, 20, 21, 21));
        encadrant_pic->setPixmap(QPixmap(QString::fromUtf8("../../../teacher.png")));
        mainbody = new QFrame(frame_2);
        mainbody->setObjectName(QStringLiteral("mainbody"));
        mainbody->setGeometry(QRect(260, 40, 581, 441));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(mainbody->sizePolicy().hasHeightForWidth());
        mainbody->setSizePolicy(sizePolicy1);
        mainbody->setMinimumSize(QSize(0, 100));
        mainbody->setFrameShape(QFrame::StyledPanel);
        mainbody->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(mainbody);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, -10, 141, 41));
        label_2->setStyleSheet(QStringLiteral("background-color:transparent;"));
        lineEdit_4 = new QLineEdit(mainbody);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(40, 39, 421, 21));
        pdf_pic = new QPushButton(mainbody);
        pdf_pic->setObjectName(QStringLiteral("pdf_pic"));
        pdf_pic->setGeometry(QRect(450, 280, 91, 21));
        tri_pic = new QPushButton(mainbody);
        tri_pic->setObjectName(QStringLiteral("tri_pic"));
        tri_pic->setGeometry(QRect(30, 280, 31, 28));
        tableView = new QTableView(mainbody);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 80, 521, 171));
        rech_pic = new QPushButton(mainbody);
        rech_pic->setObjectName(QStringLiteral("rech_pic"));
        rech_pic->setGeometry(QRect(500, 30, 51, 31));
        tri_pic_2 = new QPushButton(mainbody);
        tri_pic_2->setObjectName(QStringLiteral("tri_pic_2"));
        tri_pic_2->setGeometry(QRect(120, 280, 31, 28));
        label_5 = new QLabel(mainbody);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 320, 56, 16));
        label_5->setStyleSheet(QStringLiteral("background-color:transparent;"));
        label_6 = new QLabel(mainbody);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 320, 71, 16));
        label_6->setStyleSheet(QStringLiteral("background-color:transparent;"));
        tri_pic_3 = new QPushButton(mainbody);
        tri_pic_3->setObjectName(QStringLiteral("tri_pic_3"));
        tri_pic_3->setGeometry(QRect(210, 280, 31, 28));
        label_7 = new QLabel(mainbody);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 320, 56, 16));
        label_7->setStyleSheet(QStringLiteral("background-color:transparent;"));
        push0 = new QPushButton(mainbody);
        push0->setObjectName(QStringLiteral("push0"));
        push0->setGeometry(QRect(60, 390, 93, 28));
        push1 = new QPushButton(mainbody);
        push1->setObjectName(QStringLiteral("push1"));
        push1->setGeometry(QRect(230, 390, 93, 28));
        rightsidemenu = new QFrame(frame_2);
        rightsidemenu->setObjectName(QStringLiteral("rightsidemenu"));
        rightsidemenu->setGeometry(QRect(870, 40, 201, 451));
        rightsidemenu->setFrameShape(QFrame::StyledPanel);
        rightsidemenu->setFrameShadow(QFrame::Raised);
        ajouter = new QPushButton(rightsidemenu);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(30, 270, 101, 23));
        label_3 = new QLabel(rightsidemenu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 10, 41, 41));
        QFont font;
        font.setPointSize(30);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("background-color:transparent;"));
        label_4 = new QLabel(rightsidemenu);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 70, 111, 20));
        lineEdit_5 = new QLineEdit(rightsidemenu);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(20, 200, 116, 20));
        lineEdit_6 = new QLineEdit(rightsidemenu);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(20, 230, 116, 20));
        lineEdit_7 = new QLineEdit(rightsidemenu);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(10, 350, 131, 20));
        supprimer = new QPushButton(rightsidemenu);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(30, 390, 101, 23));
        modifier = new QPushButton(rightsidemenu);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(30, 310, 101, 23));
        lineEdit_2 = new QLineEdit(rightsidemenu);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 140, 116, 21));
        lineEdit_3 = new QLineEdit(rightsidemenu);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 170, 111, 20));
        lineEdit = new QLineEdit(rightsidemenu);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 110, 116, 20));
        lineEdit->setStyleSheet(QStringLiteral("border-radius: 5px;"));
        header = new QFrame(sponsoring);
        header->setObjectName(QStringLiteral("header"));
        header->setGeometry(QRect(30, 30, 1111, 50));
        header->setMinimumSize(QSize(0, 50));
        header->setFrameShape(QFrame::StyledPanel);
        header->setFrameShadow(QFrame::Raised);
        hamburger_pic = new QPushButton(header);
        hamburger_pic->setObjectName(QStringLiteral("hamburger_pic"));
        hamburger_pic->setEnabled(true);
        hamburger_pic->setGeometry(QRect(51, 10, 40, 30));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(hamburger_pic->sizePolicy().hasHeightForWidth());
        hamburger_pic->setSizePolicy(sizePolicy2);
        hamburger_pic->setMinimumSize(QSize(40, 20));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/hamburger.png"), QSize(), QIcon::Normal, QIcon::Off);
        hamburger_pic->setIcon(icon1);
        hamburger_pic->setIconSize(QSize(16, 20));
        label = new QLabel(header);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 0, 141, 41));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(50);
        sizePolicy3.setVerticalStretch(50);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(50, 1));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("background-color:transparent;"));
        label->setLineWidth(2);
        stat = new QPushButton(header);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(150, 10, 93, 28));
        QIcon icon2;
        icon2.addFile(QStringLiteral("pdf/icons/statistic.png"), QSize(), QIcon::Normal, QIcon::Off);
        stat->setIcon(icon2);
        calendrier_pic = new QPushButton(header);
        calendrier_pic->setObjectName(QStringLiteral("calendrier_pic"));
        calendrier_pic->setGeometry(QRect(750, 10, 121, 21));
        QIcon icon3;
        icon3.addFile(QStringLiteral("pdf/icons/calendar-date.png"), QSize(), QIcon::Normal, QIcon::Off);
        calendrier_pic->setIcon(icon3);
        camera_pic = new QPushButton(header);
        camera_pic->setObjectName(QStringLiteral("camera_pic"));
        camera_pic->setGeometry(QRect(890, 10, 111, 21));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        camera_pic->setIcon(icon4);

        retranslateUi(sponsoring);

        hamburger_pic->setDefault(true);


        QMetaObject::connectSlotsByName(sponsoring);
    } // setupUi

    void retranslateUi(QDialog *sponsoring)
    {
        sponsoring->setWindowTitle(QApplication::translate("sponsoring", "sponsoring", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("sponsoring", "  publication", Q_NULLPTR));
        research_pic->setText(QString());
        pushButton_5->setText(QApplication::translate("sponsoring", "sponsor", Q_NULLPTR));
        sponsor_pic->setText(QString());
        pushButton_4->setText(QApplication::translate("sponsoring", "materiel", Q_NULLPTR));
        materiel_pic->setText(QString());
        pushButton_2->setText(QApplication::translate("sponsoring", "  encadrant", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("sponsoring", "etudiant", Q_NULLPTR));
        student_pic->setText(QString());
        encadrant_pic->setText(QString());
        label_2->setText(QApplication::translate("sponsoring", "Liste des sponsors", Q_NULLPTR));
        lineEdit_4->setPlaceholderText(QApplication::translate("sponsoring", "Rechercher", Q_NULLPTR));
        pdf_pic->setText(QApplication::translate("sponsoring", "PDF", Q_NULLPTR));
        tri_pic->setText(QString());
        rech_pic->setText(QString());
        tri_pic_2->setText(QString());
        label_5->setText(QApplication::translate("sponsoring", "Tri Duree", Q_NULLPTR));
        label_6->setText(QApplication::translate("sponsoring", "Tri Montant", Q_NULLPTR));
        tri_pic_3->setText(QString());
        label_7->setText(QApplication::translate("sponsoring", "Tri ID", Q_NULLPTR));
        push0->setText(QApplication::translate("sponsoring", "open", Q_NULLPTR));
        push1->setText(QApplication::translate("sponsoring", "close", Q_NULLPTR));
        ajouter->setText(QApplication::translate("sponsoring", "ajouter", Q_NULLPTR));
        label_3->setText(QApplication::translate("sponsoring", "+", Q_NULLPTR));
        label_4->setText(QApplication::translate("sponsoring", "Ajouter un sponsor", Q_NULLPTR));
        lineEdit_5->setText(QString());
        lineEdit_5->setPlaceholderText(QApplication::translate("sponsoring", "Duree", Q_NULLPTR));
        lineEdit_6->setText(QString());
        lineEdit_6->setPlaceholderText(QApplication::translate("sponsoring", "Nom", Q_NULLPTR));
        lineEdit_7->setText(QString());
        lineEdit_7->setPlaceholderText(QApplication::translate("sponsoring", "id a supprimer", Q_NULLPTR));
        supprimer->setText(QApplication::translate("sponsoring", "supprimer", Q_NULLPTR));
        modifier->setText(QApplication::translate("sponsoring", "modifier", Q_NULLPTR));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("sponsoring", "Montant", Q_NULLPTR));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QApplication::translate("sponsoring", "Contact", Q_NULLPTR));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("sponsoring", "ID_sponsor", Q_NULLPTR));
        hamburger_pic->setText(QString());
        label->setText(QApplication::translate("sponsoring", "InteLab", Q_NULLPTR));
        stat->setText(QApplication::translate("sponsoring", "sta", Q_NULLPTR));
        calendrier_pic->setText(QApplication::translate("sponsoring", "calendrier", Q_NULLPTR));
        camera_pic->setText(QApplication::translate("sponsoring", "camera", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sponsoring: public Ui_sponsoring {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPONSORING_H

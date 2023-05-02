/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_student
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QWidget *mainbody;
    QLabel *label_2;
    QLineEdit *recherche;
    QTableView *tab_etudiant;
    QLineEdit *le_supprimer;
    QPushButton *pb_supprimer;
    QPushButton *pb_tri_asc;
    QPushButton *pb_tri_desc;
    QLineEdit *email;
    QTextEdit *textemail;
    QPushButton *send;
    QPushButton *pb_recherche;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QFrame *rightsidemenu;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *ajout;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_email;
    QLineEdit *le_specialite;
    QLineEdit *le_mention;
    QPushButton *pb_modifier;
    QPushButton *pb_ajouter;
    QFrame *header;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pb_menu;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_24;
    QPushButton *pushButton;
    QPushButton *pb_pdf;
    QFrame *sidemenu;
    QFrame *frame_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *student)
    {
        if (student->objectName().isEmpty())
            student->setObjectName(QStringLiteral("student"));
        student->resize(1191, 703);
        student->setStyleSheet(QLatin1String("*{\n"
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
"\n"
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
        frame = new QFrame(student);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(9, 9, 1171, 691));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(170, 86, 1021, 601));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        mainbody = new QWidget(frame_2);
        mainbody->setObjectName(QStringLiteral("mainbody"));
        mainbody->setEnabled(true);
        mainbody->setGeometry(QRect(20, 0, 751, 601));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(mainbody->sizePolicy().hasHeightForWidth());
        mainbody->setSizePolicy(sizePolicy2);
        mainbody->setMinimumSize(QSize(0, 100));
        mainbody->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(mainbody);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 0, 281, 81));
        QFont font;
        font.setFamily(QStringLiteral("Bahnschrift Light Condensed"));
        font.setPointSize(31);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(0);
        label_2->setIndent(-1);
        recherche = new QLineEdit(mainbody);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(30, 80, 441, 31));
        tab_etudiant = new QTableView(mainbody);
        tab_etudiant->setObjectName(QStringLiteral("tab_etudiant"));
        tab_etudiant->setGeometry(QRect(20, 130, 721, 261));
        le_supprimer = new QLineEdit(mainbody);
        le_supprimer->setObjectName(QStringLiteral("le_supprimer"));
        le_supprimer->setGeometry(QRect(520, 480, 71, 31));
        pb_supprimer = new QPushButton(mainbody);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(530, 520, 61, 31));
        pb_supprimer->setCursor(QCursor(Qt::PointingHandCursor));
        pb_tri_asc = new QPushButton(mainbody);
        pb_tri_asc->setObjectName(QStringLiteral("pb_tri_asc"));
        pb_tri_asc->setGeometry(QRect(640, 50, 93, 28));
        pb_tri_asc->setCursor(QCursor(Qt::PointingHandCursor));
        pb_tri_desc = new QPushButton(mainbody);
        pb_tri_desc->setObjectName(QStringLiteral("pb_tri_desc"));
        pb_tri_desc->setGeometry(QRect(640, 90, 93, 28));
        pb_tri_desc->setCursor(QCursor(Qt::PointingHandCursor));
        email = new QLineEdit(mainbody);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(40, 440, 441, 31));
        email->setEchoMode(QLineEdit::Normal);
        textemail = new QTextEdit(mainbody);
        textemail->setObjectName(QStringLiteral("textemail"));
        textemail->setGeometry(QRect(40, 490, 351, 71));
        send = new QPushButton(mainbody);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(400, 490, 81, 71));
        pb_recherche = new QPushButton(mainbody);
        pb_recherche->setObjectName(QStringLiteral("pb_recherche"));
        pb_recherche->setGeometry(QRect(480, 80, 81, 31));
        pushButton_7 = new QPushButton(mainbody);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(650, 440, 75, 23));
        pushButton_8 = new QPushButton(mainbody);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(650, 470, 75, 23));
        rightsidemenu = new QFrame(frame_2);
        rightsidemenu->setObjectName(QStringLiteral("rightsidemenu"));
        rightsidemenu->setGeometry(QRect(780, 0, 221, 601));
        rightsidemenu->setFrameShape(QFrame::StyledPanel);
        rightsidemenu->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(rightsidemenu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(61, 450, 20, 20));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);
        label_4 = new QLabel(rightsidemenu);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 20, 141, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe Fluent Icons"));
        font2.setPointSize(10);
        label_4->setFont(font2);
        ajout = new QFrame(rightsidemenu);
        ajout->setObjectName(QStringLiteral("ajout"));
        ajout->setGeometry(QRect(20, 50, 181, 371));
        ajout->setFrameShape(QFrame::StyledPanel);
        ajout->setFrameShadow(QFrame::Raised);
        le_id = new QLineEdit(ajout);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(10, 30, 161, 31));
        le_nom = new QLineEdit(ajout);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(10, 74, 161, 31));
        le_prenom = new QLineEdit(ajout);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(10, 118, 161, 31));
        le_email = new QLineEdit(ajout);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(10, 162, 161, 31));
        le_specialite = new QLineEdit(ajout);
        le_specialite->setObjectName(QStringLiteral("le_specialite"));
        le_specialite->setGeometry(QRect(10, 206, 161, 31));
        le_mention = new QLineEdit(ajout);
        le_mention->setObjectName(QStringLiteral("le_mention"));
        le_mention->setGeometry(QRect(10, 250, 161, 31));
        pb_modifier = new QPushButton(rightsidemenu);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(60, 500, 101, 41));
        pb_modifier->setFont(font2);
        pb_modifier->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ajouter = new QPushButton(rightsidemenu);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(60, 430, 101, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe Fluent Icons"));
        font3.setPointSize(9);
        pb_ajouter->setFont(font3);
        pb_ajouter->setCursor(QCursor(Qt::PointingHandCursor));
        header = new QFrame(frame);
        header->setObjectName(QStringLiteral("header"));
        header->setGeometry(QRect(0, 0, 1171, 81));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy3);
        header->setMinimumSize(QSize(0, 50));
        header->setCursor(QCursor(Qt::PointingHandCursor));
        header->setFrameShape(QFrame::StyledPanel);
        header->setFrameShadow(QFrame::Raised);
        frame_8 = new QFrame(header);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setGeometry(QRect(280, 9, 72, 32));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(20);
        sizePolicy4.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy4);
        frame_8->setMinimumSize(QSize(40, 30));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_8);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pb_menu = new QPushButton(header);
        pb_menu->setObjectName(QStringLiteral("pb_menu"));
        pb_menu->setEnabled(true);
        pb_menu->setGeometry(QRect(20, 20, 121, 51));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(50);
        sizePolicy5.setVerticalStretch(10);
        sizePolicy5.setHeightForWidth(pb_menu->sizePolicy().hasHeightForWidth());
        pb_menu->setSizePolicy(sizePolicy5);
        pb_menu->setMinimumSize(QSize(40, 20));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/hamburger.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_menu->setIcon(icon);
        pb_menu->setIconSize(QSize(16, 20));
        label_16 = new QLabel(header);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 30, 31, 31));
        label_16->setPixmap(QPixmap(QString::fromUtf8("../../T\303\251l\303\251chargements/icons/icons/hamburger.png")));
        label_17 = new QLabel(header);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(550, 0, 151, 41));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(50);
        sizePolicy6.setVerticalStretch(50);
        sizePolicy6.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy6);
        label_17->setMinimumSize(QSize(50, 1));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        label_17->setFont(font4);
        label_17->setLineWidth(2);
        label_18 = new QLabel(header);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(690, 20, 31, 21));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../T\303\251l\303\251chargements/Downloads/notification.png")));
        label_19 = new QLabel(header);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(660, 20, 21, 21));
        label_19->setPixmap(QPixmap(QString::fromUtf8("../../T\303\251l\303\251chargements/Downloads/video.png")));
        label_24 = new QLabel(header);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(450, 40, 371, 41));
        sizePolicy6.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy6);
        label_24->setMinimumSize(QSize(50, 1));
        label_24->setFont(font4);
        label_24->setLineWidth(2);
        pushButton = new QPushButton(header);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1040, 30, 81, 31));
        pb_pdf = new QPushButton(header);
        pb_pdf->setObjectName(QStringLiteral("pb_pdf"));
        pb_pdf->setGeometry(QRect(980, 30, 51, 31));
        pb_pdf->setCursor(QCursor(Qt::PointingHandCursor));
        sidemenu = new QFrame(frame);
        sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->setGeometry(QRect(0, 90, 181, 601));
        sizePolicy3.setHeightForWidth(sidemenu->sizePolicy().hasHeightForWidth());
        sidemenu->setSizePolicy(sizePolicy3);
        frame_4 = new QFrame(sidemenu);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 20, 161, 481));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy7);
        frame_4->setMinimumSize(QSize(50, 0));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 20, 141, 51));
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 90, 141, 61));
        pushButton_4 = new QPushButton(frame_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 170, 141, 51));
        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 240, 141, 51));
        pushButton_6 = new QPushButton(frame_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 310, 141, 51));
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_4->raise();

        retranslateUi(student);

        pb_menu->setDefault(true);


        QMetaObject::connectSlotsByName(student);
    } // setupUi

    void retranslateUi(QDialog *student)
    {
        student->setWindowTitle(QApplication::translate("student", "Gestion Etudiants", Q_NULLPTR));
        label_2->setText(QApplication::translate("student", "Liste des \303\251tudiants", Q_NULLPTR));
        recherche->setPlaceholderText(QApplication::translate("student", "Rechercher un \303\251tudiant", Q_NULLPTR));
        le_supprimer->setPlaceholderText(QApplication::translate("student", "Supprimer avec ID", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("student", "supprimer", Q_NULLPTR));
        pb_tri_asc->setText(QApplication::translate("student", "ID sort", Q_NULLPTR));
        pb_tri_desc->setText(QApplication::translate("student", "Name sort", Q_NULLPTR));
        email->setInputMask(QString());
        email->setText(QString());
        email->setPlaceholderText(QApplication::translate("student", "taper l'email ici", Q_NULLPTR));
        textemail->setPlaceholderText(QApplication::translate("student", "input email text here", Q_NULLPTR));
        send->setText(QApplication::translate("student", "envoyer", Q_NULLPTR));
        pb_recherche->setText(QApplication::translate("student", "OK", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("student", "Buzzer ON", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("student", "Buzzer OFF", Q_NULLPTR));
        label_3->setText(QApplication::translate("student", "+", Q_NULLPTR));
        label_4->setText(QApplication::translate("student", "Ajouter /Modifier", Q_NULLPTR));
        le_id->setText(QString());
        le_id->setPlaceholderText(QApplication::translate("student", "Id Etudiant", Q_NULLPTR));
        le_nom->setText(QString());
        le_nom->setPlaceholderText(QApplication::translate("student", "Nom", Q_NULLPTR));
        le_prenom->setText(QString());
        le_prenom->setPlaceholderText(QApplication::translate("student", "Prenom", Q_NULLPTR));
        le_email->setText(QString());
        le_email->setPlaceholderText(QApplication::translate("student", "Email", Q_NULLPTR));
        le_specialite->setText(QString());
        le_specialite->setPlaceholderText(QApplication::translate("student", "Specialite", Q_NULLPTR));
        le_mention->setText(QString());
        le_mention->setPlaceholderText(QApplication::translate("student", "Mention", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("student", "Modifier", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("student", "Ajouter", Q_NULLPTR));
        pb_menu->setText(QApplication::translate("student", "Menu", Q_NULLPTR));
        label_16->setText(QString());
        label_17->setText(QApplication::translate("student", "InteLab", Q_NULLPTR));
        label_18->setText(QString());
        label_19->setText(QString());
        label_24->setText(QApplication::translate("student", "Gestion des \303\251tudiants", Q_NULLPTR));
        pushButton->setText(QApplication::translate("student", "Statistiques", Q_NULLPTR));
        pb_pdf->setText(QApplication::translate("student", "pdf", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("student", "  Encadrants", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("student", "Etudiants", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("student", "Materiels", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("student", "Sponsor", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("student", "Publications", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class student: public Ui_student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H

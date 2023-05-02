/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QFrame *header;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *mediaplayer;
    QPushButton *notif;
    QLabel *popupLabel;
    QFrame *frame_2;
    QFrame *sidemenu;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QFrame *mainbody;
    QLabel *label_2;
    QLineEdit *rechercher;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *filter;
    QPushButton *pdf;
    QLabel *label_15;
    QTableView *table_materiel;
    QPushButton *supprimer;
    QLineEdit *id_supp;
    QLabel *label_16;
    QPushButton *search;
    QComboBox *comboBox;
    QLabel *label_17;
    QPushButton *statistics;
    QFrame *rightsidemenu;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *la_qte;
    QLineEdit *la_disp;
    QLineEdit *le_prix;
    QPushButton *ajouter;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *modifier;

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QStringLiteral("widget"));
        widget->resize(1191, 703);
        widget->setStyleSheet(QLatin1String("*{\n"
"\n"
"background-color:transparent;\n"
"color: #aa54ff; \n"
"}\n"
"#filter,#mediaplayer,#notif,#pdf,#supprimer,#search,#statistics{\n"
"background-color: transparent;\n"
"}\n"
"\n"
"\n"
"#widget{\n"
"background-color: #040f13;\n"
"}\n"
"#sidemenu{\n"
"background-color: #071e26; \n"
"border-radius: 20px; \n"
"}\n"
"#ajouter,#modifier\n"
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
"#rightsidemenu,#popupLabel\n"
"{\n"
"background-color: #071e26; \n"
"border-radius: 20px; \n"
"}\n"
"\n"
"#mainbody{\n"
"background-color: #071e26; \n"
"border-radius: 10px;\n"
"}\n"
"#comboBox{\n"
"\n"
"}\n"
"\n"
""));
        header = new QFrame(widget);
        header->setObjectName(QStringLiteral("header"));
        header->setGeometry(QRect(0, 0, 1181, 71));
        header->setMinimumSize(QSize(0, 50));
        header->setFrameShape(QFrame::StyledPanel);
        header->setFrameShadow(QFrame::Raised);
        frame = new QFrame(header);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(9, 9, 90, 50));
        frame->setMinimumSize(QSize(40, 50));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/hamburger.png")));

        verticalLayout_5->addWidget(label_6);

        frame_3 = new QFrame(header);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(280, 9, 72, 32));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(40, 30));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton = new QPushButton(header);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(51, 10, 40, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(40, 20));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/hamburger.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(16, 20));
        label = new QLabel(header);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 10, 111, 41));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(50, 1));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLineWidth(2);
        label_11 = new QLabel(header);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(690, 20, 31, 21));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/notification.png")));
        label_12 = new QLabel(header);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(660, 20, 21, 21));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/video.png")));
        mediaplayer = new QPushButton(header);
        mediaplayer->setObjectName(QStringLiteral("mediaplayer"));
        mediaplayer->setGeometry(QRect(954, 12, 161, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/play-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        mediaplayer->setIcon(icon1);
        notif = new QPushButton(header);
        notif->setObjectName(QStringLiteral("notif"));
        notif->setGeometry(QRect(690, 20, 31, 23));
        popupLabel = new QLabel(header);
        popupLabel->setObjectName(QStringLiteral("popupLabel"));
        popupLabel->setGeometry(QRect(130, 10, 201, 51));
        label_12->raise();
        notif->raise();
        mediaplayer->raise();
        frame->raise();
        frame_3->raise();
        pushButton->raise();
        label->raise();
        label_11->raise();
        popupLabel->raise();
        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 90, 1191, 631));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        sidemenu = new QFrame(frame_2);
        sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->setGeometry(QRect(0, 10, 221, 601));
        frame_4 = new QFrame(sidemenu);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 0, 211, 531));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy3);
        frame_4->setMinimumSize(QSize(50, 0));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/teacher.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("icons/student.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(frame_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/flask.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("icons/handshake.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon5);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(frame_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("icons/research.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon6);

        verticalLayout->addWidget(pushButton_6);

        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_4->raise();
        mainbody = new QFrame(frame_2);
        mainbody->setObjectName(QStringLiteral("mainbody"));
        mainbody->setGeometry(QRect(239, 10, 711, 601));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mainbody->sizePolicy().hasHeightForWidth());
        mainbody->setSizePolicy(sizePolicy4);
        mainbody->setMinimumSize(QSize(0, 0));
        mainbody->setMaximumSize(QSize(16777215, 16777215));
        mainbody->setLayoutDirection(Qt::LeftToRight);
        mainbody->setAutoFillBackground(false);
        mainbody->setFrameShape(QFrame::StyledPanel);
        mainbody->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(mainbody);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 0, 141, 41));
        rechercher = new QLineEdit(mainbody);
        rechercher->setObjectName(QStringLiteral("rechercher"));
        rechercher->setGeometry(QRect(20, 50, 431, 51));
        label_13 = new QLabel(mainbody);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(220, 40, 20, 16));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/search (1).png")));
        label_14 = new QLabel(mainbody);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(250, 40, 21, 21));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/funnel.png")));
        filter = new QPushButton(mainbody);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setGeometry(QRect(250, 30, 31, 31));
        pdf = new QPushButton(mainbody);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(600, 510, 81, 61));
        QIcon icon7;
        icon7.addFile(QStringLiteral("icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon7);
        label_15 = new QLabel(mainbody);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(380, 220, 31, 31));
        label_15->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/pdf (1).png")));
        table_materiel = new QTableView(mainbody);
        table_materiel->setObjectName(QStringLiteral("table_materiel"));
        table_materiel->setGeometry(QRect(10, 110, 571, 471));
        table_materiel->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_materiel->setSelectionMode(QAbstractItemView::SingleSelection);
        table_materiel->setSelectionBehavior(QAbstractItemView::SelectRows);
        supprimer = new QPushButton(mainbody);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(560, 60, 51, 41));
        id_supp = new QLineEdit(mainbody);
        id_supp->setObjectName(QStringLiteral("id_supp"));
        id_supp->setGeometry(QRect(550, 50, 101, 51));
        label_16 = new QLabel(mainbody);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(370, 70, 21, 21));
        label_16->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/garbage-bin.png")));
        search = new QPushButton(mainbody);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(400, 60, 41, 31));
        QIcon icon8;
        icon8.addFile(QStringLiteral("icons/search (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        search->setIcon(icon8);
        comboBox = new QComboBox(mainbody);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(470, 60, 61, 31));
        label_17 = new QLabel(mainbody);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(630, 140, 31, 31));
        label_17->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/pie-chart.png")));
        statistics = new QPushButton(mainbody);
        statistics->setObjectName(QStringLiteral("statistics"));
        statistics->setGeometry(QRect(600, 460, 81, 51));
        QIcon icon9;
        icon9.addFile(QStringLiteral("icons/statistic.png"), QSize(), QIcon::Normal, QIcon::Off);
        statistics->setIcon(icon9);
        label_15->raise();
        rechercher->raise();
        label_2->raise();
        label_13->raise();
        label_14->raise();
        table_materiel->raise();
        id_supp->raise();
        label_16->raise();
        supprimer->raise();
        search->raise();
        filter->raise();
        comboBox->raise();
        label_17->raise();
        statistics->raise();
        pdf->raise();
        rightsidemenu = new QFrame(frame_2);
        rightsidemenu->setObjectName(QStringLiteral("rightsidemenu"));
        rightsidemenu->setGeometry(QRect(970, 20, 211, 611));
        rightsidemenu->setFrameShape(QFrame::StyledPanel);
        rightsidemenu->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(rightsidemenu);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(10, 70, 201, 371));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        le_id = new QLineEdit(frame_5);
        le_id->setObjectName(QStringLiteral("le_id"));

        verticalLayout_2->addWidget(le_id);

        le_nom = new QLineEdit(frame_5);
        le_nom->setObjectName(QStringLiteral("le_nom"));

        verticalLayout_2->addWidget(le_nom);

        la_qte = new QLineEdit(frame_5);
        la_qte->setObjectName(QStringLiteral("la_qte"));

        verticalLayout_2->addWidget(la_qte);

        la_disp = new QLineEdit(frame_5);
        la_disp->setObjectName(QStringLiteral("la_disp"));

        verticalLayout_2->addWidget(la_disp);

        le_prix = new QLineEdit(frame_5);
        le_prix->setObjectName(QStringLiteral("le_prix"));

        verticalLayout_2->addWidget(le_prix);

        ajouter = new QPushButton(rightsidemenu);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(50, 440, 101, 23));
        label_3 = new QLabel(rightsidemenu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 10, 41, 41));
        QFont font1;
        font1.setPointSize(30);
        label_3->setFont(font1);
        label_4 = new QLabel(rightsidemenu);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 50, 111, 20));
        modifier = new QPushButton(rightsidemenu);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(50, 490, 101, 23));
        mainbody->raise();
        sidemenu->raise();
        rightsidemenu->raise();

        retranslateUi(widget);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "Form", Q_NULLPTR));
        label_6->setText(QString());
        pushButton->setText(QString());
        label->setText(QApplication::translate("widget", "InteLab", Q_NULLPTR));
        label_11->setText(QString());
        label_12->setText(QString());
        mediaplayer->setText(QApplication::translate("widget", "mediaPlayer", Q_NULLPTR));
        notif->setText(QString());
        popupLabel->setText(QString());
        pushButton_2->setText(QApplication::translate("widget", "  encadrant", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("widget", "etudiant", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("widget", "materiel", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("widget", "sponsor", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("widget", "  publication", Q_NULLPTR));
        label_2->setText(QApplication::translate("widget", "Liste des materiels", Q_NULLPTR));
        rechercher->setPlaceholderText(QApplication::translate("widget", "Rechercher", Q_NULLPTR));
        label_13->setText(QString());
        label_14->setText(QString());
        filter->setText(QString());
        pdf->setText(QApplication::translate("widget", "PDF", Q_NULLPTR));
        label_15->setText(QString());
        supprimer->setText(QString());
        id_supp->setPlaceholderText(QApplication::translate("widget", "supprimer", Q_NULLPTR));
        label_16->setText(QString());
        search->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("widget", "id", Q_NULLPTR)
         << QApplication::translate("widget", "nom", Q_NULLPTR)
         << QApplication::translate("widget", "quantite", Q_NULLPTR)
        );
        label_17->setText(QString());
        statistics->setText(QApplication::translate("widget", "STA", Q_NULLPTR));
        le_id->setPlaceholderText(QApplication::translate("widget", "  Identifiant", Q_NULLPTR));
        le_nom->setPlaceholderText(QApplication::translate("widget", "      Nom", Q_NULLPTR));
        la_qte->setPlaceholderText(QApplication::translate("widget", "   Quantit\303\251", Q_NULLPTR));
        la_disp->setPlaceholderText(QApplication::translate("widget", " Disponibilite", Q_NULLPTR));
        le_prix->setPlaceholderText(QApplication::translate("widget", "      Prix", Q_NULLPTR));
        ajouter->setText(QApplication::translate("widget", "ajouter", Q_NULLPTR));
        label_3->setText(QApplication::translate("widget", "+", Q_NULLPTR));
        label_4->setText(QApplication::translate("widget", "Ajouter un materiel", Q_NULLPTR));
        modifier->setText(QApplication::translate("widget", "modifier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

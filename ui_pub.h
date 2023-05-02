/********************************************************************************
** Form generated from reading UI file 'pub.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUB_H
#define UI_PUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pub
{
public:
    QFrame *pdf;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_2;
    QFrame *sidemenu;
    QFrame *frame_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *student_pic;
    QLabel *materiel_pic;
    QLabel *sponsor_pic;
    QLabel *encadrant_pic;
    QPushButton *pushButton_6;
    QLabel *research_pic;
    QPushButton *tri_pic_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *tri_pic;
    QFrame *mainbody;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLabel *recherche_pic;
    QPushButton *filter;
    QPushButton *btn_delete;
    QTableView *tableView;
    QPushButton *btn_update;
    QLabel *popupLabel;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *rightsidemenu;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *nombrepub;
    QLineEdit *lineEdit_id_create;
    QLineEdit *lineEdit_sujet_create;
    QLineEdit *lineEdit_propriete_create;
    QLineEdit *lineEdit_description_create;
    QLabel *label_5;
    QLabel *label_6;
    QDateEdit *dateEdit_create;
    QPushButton *ajouter_btn;
    QPushButton *pushButton;
    QPushButton *pushButton_9;
    QWidget *page_2;
    QFrame *rightsidemenu_2;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit_nbpub_modifier;
    QLineEdit *lineEdit_id_modifier;
    QLineEdit *lineEdit_sujet_modifier;
    QLineEdit *lineEdit_propriete_modifier;
    QDateEdit *dateEdit_modifier;
    QLineEdit *lineEdit_description_modifier;
    QPushButton *modifier;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *modifier_annuler;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_13;
    QLabel *label;
    QPushButton *pushButton_7;

    void setupUi(QWidget *pub)
    {
        if (pub->objectName().isEmpty())
            pub->setObjectName(QStringLiteral("pub"));
        pub->resize(1032, 597);
        pub->setStyleSheet(QLatin1String("*{\n"
"\n"
"background-color:transparent;\n"
"color: #aa54ff; \n"
"}\n"
"#filter,#mediaplayer,#notif,#pdf{\n"
"background-color: transparent;\n"
"}\n"
"\n"
"\n"
"#pub{\n"
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
"#rightsidemenu_2\n"
"{\n"
"background-color: #071e26; \n"
"border-radius: 20px; \n"
"}\n"
"\n"
"#mainbody{\n"
"background-color: #071e26; \n"
"border-radius: 10px;\n"
"}"));
        pdf = new QFrame(pub);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(0, 0, 968, 535));
        pdf->setMinimumSize(QSize(0, 50));
        pdf->setFrameShape(QFrame::StyledPanel);
        pdf->setFrameShadow(QFrame::Raised);
        frame = new QFrame(pdf);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 0, 141, 61));
        frame->setMinimumSize(QSize(40, 50));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        frame_3 = new QFrame(pdf);
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
        frame_2 = new QFrame(pdf);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(-10, 103, 1001, 561));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        sidemenu = new QFrame(frame_2);
        sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->setGeometry(QRect(30, 40, 191, 391));
        frame_4 = new QFrame(sidemenu);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(9, 9, 113, 188));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy2);
        frame_4->setMinimumSize(QSize(50, 0));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 111, 29));
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 40, 111, 29));
        pushButton_4 = new QPushButton(frame_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 80, 111, 29));
        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(0, 120, 111, 29));
        student_pic = new QLabel(frame_4);
        student_pic->setObjectName(QStringLiteral("student_pic"));
        student_pic->setGeometry(QRect(10, 40, 21, 21));
        student_pic->setPixmap(QPixmap(QString::fromUtf8("icons/student.png")));
        materiel_pic = new QLabel(frame_4);
        materiel_pic->setObjectName(QStringLiteral("materiel_pic"));
        materiel_pic->setGeometry(QRect(10, 80, 20, 20));
        materiel_pic->setPixmap(QPixmap(QString::fromUtf8("icons/flask.png")));
        sponsor_pic = new QLabel(frame_4);
        sponsor_pic->setObjectName(QStringLiteral("sponsor_pic"));
        sponsor_pic->setGeometry(QRect(10, 120, 21, 21));
        sponsor_pic->setPixmap(QPixmap(QString::fromUtf8("icons/handshake.png")));
        encadrant_pic = new QLabel(frame_4);
        encadrant_pic->setObjectName(QStringLiteral("encadrant_pic"));
        encadrant_pic->setGeometry(QRect(10, 10, 21, 21));
        encadrant_pic->setPixmap(QPixmap(QString::fromUtf8("icons/teacher (1).png")));
        pushButton_6 = new QPushButton(frame_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(0, 160, 121, 21));
        research_pic = new QLabel(frame_4);
        research_pic->setObjectName(QStringLiteral("research_pic"));
        research_pic->setGeometry(QRect(10, 160, 21, 20));
        research_pic->setPixmap(QPixmap(QString::fromUtf8("icons/research.png")));
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_5->raise();
        pushButton_4->raise();
        student_pic->raise();
        materiel_pic->raise();
        sponsor_pic->raise();
        encadrant_pic->raise();
        pushButton_6->raise();
        research_pic->raise();
        tri_pic_2 = new QPushButton(sidemenu);
        tri_pic_2->setObjectName(QStringLiteral("tri_pic_2"));
        tri_pic_2->setGeometry(QRect(20, 240, 101, 21));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/funnel.png"), QSize(), QIcon::Normal, QIcon::Off);
        tri_pic_2->setIcon(icon);
        pushButton_8 = new QPushButton(sidemenu);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(20, 270, 101, 21));
        pushButton_8->setIcon(icon);
        pushButton_10 = new QPushButton(sidemenu);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 310, 81, 28));
        pushButton_11 = new QPushButton(sidemenu);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(100, 310, 81, 28));
        pushButton_12 = new QPushButton(sidemenu);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(60, 350, 81, 28));
        tri_pic = new QPushButton(sidemenu);
        tri_pic->setObjectName(QStringLiteral("tri_pic"));
        tri_pic->setGeometry(QRect(20, 210, 101, 21));
        tri_pic->setIcon(icon);
        mainbody = new QFrame(frame_2);
        mainbody->setObjectName(QStringLiteral("mainbody"));
        mainbody->setGeometry(QRect(250, 50, 400, 381));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(50);
        sizePolicy3.setHeightForWidth(mainbody->sizePolicy().hasHeightForWidth());
        mainbody->setSizePolicy(sizePolicy3);
        mainbody->setMinimumSize(QSize(0, 100));
        mainbody->setMaximumSize(QSize(9000, 9000));
        mainbody->setFrameShape(QFrame::StyledPanel);
        mainbody->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(mainbody);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 0, 141, 41));
        lineEdit_4 = new QLineEdit(mainbody);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(50, 40, 321, 21));
        recherche_pic = new QLabel(mainbody);
        recherche_pic->setObjectName(QStringLiteral("recherche_pic"));
        recherche_pic->setGeometry(QRect(20, 40, 20, 16));
        recherche_pic->setPixmap(QPixmap(QString::fromUtf8("icons/search (1).png")));
        filter = new QPushButton(mainbody);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setGeometry(QRect(340, 30, 31, 31));
        btn_delete = new QPushButton(mainbody);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));
        btn_delete->setGeometry(QRect(360, 180, 31, 28));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_delete->setIcon(icon1);
        tableView = new QTableView(mainbody);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 90, 341, 271));
        btn_update = new QPushButton(mainbody);
        btn_update->setObjectName(QStringLiteral("btn_update"));
        btn_update->setGeometry(QRect(360, 220, 31, 28));
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_update->setIcon(icon2);
        filter->raise();
        label_2->raise();
        lineEdit_4->raise();
        recherche_pic->raise();
        btn_delete->raise();
        tableView->raise();
        btn_update->raise();
        popupLabel = new QLabel(frame_2);
        popupLabel->setObjectName(QStringLiteral("popupLabel"));
        popupLabel->setGeometry(QRect(340, 350, 121, 16));
        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(660, 40, 311, 381));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        rightsidemenu = new QFrame(page);
        rightsidemenu->setObjectName(QStringLiteral("rightsidemenu"));
        rightsidemenu->setGeometry(QRect(20, 0, 601, 591));
        rightsidemenu->setFrameShape(QFrame::StyledPanel);
        rightsidemenu->setFrameShadow(QFrame::Raised);
        frame_6 = new QFrame(rightsidemenu);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(0, 70, 271, 161));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        nombrepub = new QLineEdit(frame_6);
        nombrepub->setObjectName(QStringLiteral("nombrepub"));

        verticalLayout_3->addWidget(nombrepub);

        lineEdit_id_create = new QLineEdit(frame_6);
        lineEdit_id_create->setObjectName(QStringLiteral("lineEdit_id_create"));

        verticalLayout_3->addWidget(lineEdit_id_create);

        lineEdit_sujet_create = new QLineEdit(frame_6);
        lineEdit_sujet_create->setObjectName(QStringLiteral("lineEdit_sujet_create"));

        verticalLayout_3->addWidget(lineEdit_sujet_create);

        lineEdit_propriete_create = new QLineEdit(frame_6);
        lineEdit_propriete_create->setObjectName(QStringLiteral("lineEdit_propriete_create"));

        verticalLayout_3->addWidget(lineEdit_propriete_create);

        lineEdit_description_create = new QLineEdit(frame_6);
        lineEdit_description_create->setObjectName(QStringLiteral("lineEdit_description_create"));

        verticalLayout_3->addWidget(lineEdit_description_create);

        label_5 = new QLabel(rightsidemenu);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 30, 31, 31));
        QFont font;
        font.setPointSize(30);
        label_5->setFont(font);
        label_6 = new QLabel(rightsidemenu);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 40, 141, 20));
        dateEdit_create = new QDateEdit(rightsidemenu);
        dateEdit_create->setObjectName(QStringLiteral("dateEdit_create"));
        dateEdit_create->setGeometry(QRect(10, 240, 231, 31));
        ajouter_btn = new QPushButton(rightsidemenu);
        ajouter_btn->setObjectName(QStringLiteral("ajouter_btn"));
        ajouter_btn->setGeometry(QRect(90, 300, 101, 23));
        pushButton = new QPushButton(rightsidemenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 350, 101, 20));
        QIcon icon3;
        icon3.addFile(QStringLiteral("icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton_9 = new QPushButton(rightsidemenu);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 350, 91, 21));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon4);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        rightsidemenu_2 = new QFrame(page_2);
        rightsidemenu_2->setObjectName(QStringLiteral("rightsidemenu_2"));
        rightsidemenu_2->setGeometry(QRect(10, 0, 301, 411));
        rightsidemenu_2->setStyleSheet(QStringLiteral(""));
        rightsidemenu_2->setFrameShape(QFrame::StyledPanel);
        rightsidemenu_2->setFrameShadow(QFrame::Raised);
        frame_9 = new QFrame(rightsidemenu_2);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setGeometry(QRect(0, 70, 281, 211));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_9);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        lineEdit_nbpub_modifier = new QLineEdit(frame_9);
        lineEdit_nbpub_modifier->setObjectName(QStringLiteral("lineEdit_nbpub_modifier"));

        verticalLayout_8->addWidget(lineEdit_nbpub_modifier);

        lineEdit_id_modifier = new QLineEdit(frame_9);
        lineEdit_id_modifier->setObjectName(QStringLiteral("lineEdit_id_modifier"));
        lineEdit_id_modifier->setEnabled(false);

        verticalLayout_8->addWidget(lineEdit_id_modifier);

        lineEdit_sujet_modifier = new QLineEdit(frame_9);
        lineEdit_sujet_modifier->setObjectName(QStringLiteral("lineEdit_sujet_modifier"));

        verticalLayout_8->addWidget(lineEdit_sujet_modifier);

        lineEdit_propriete_modifier = new QLineEdit(frame_9);
        lineEdit_propriete_modifier->setObjectName(QStringLiteral("lineEdit_propriete_modifier"));

        verticalLayout_8->addWidget(lineEdit_propriete_modifier);

        dateEdit_modifier = new QDateEdit(frame_9);
        dateEdit_modifier->setObjectName(QStringLiteral("dateEdit_modifier"));

        verticalLayout_8->addWidget(dateEdit_modifier);

        lineEdit_description_modifier = new QLineEdit(frame_9);
        lineEdit_description_modifier->setObjectName(QStringLiteral("lineEdit_description_modifier"));

        verticalLayout_8->addWidget(lineEdit_description_modifier);

        modifier = new QPushButton(rightsidemenu_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(40, 310, 101, 23));
        label_11 = new QLabel(rightsidemenu_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(220, 20, 41, 41));
        label_11->setFont(font);
        label_12 = new QLabel(rightsidemenu_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(60, 30, 151, 20));
        modifier_annuler = new QPushButton(rightsidemenu_2);
        modifier_annuler->setObjectName(QStringLiteral("modifier_annuler"));
        modifier_annuler->setGeometry(QRect(160, 310, 101, 20));
        stackedWidget->addWidget(page_2);
        horizontalLayoutWidget = new QWidget(pdf);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 961, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(42);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_13 = new QPushButton(horizontalLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("icons/hamburger.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon5);

        verticalLayout->addWidget(pushButton_13);


        horizontalLayout->addLayout(verticalLayout);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(50);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setMinimumSize(QSize(50, 1));
        label->setMaximumSize(QSize(300, 50));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setLineWidth(2);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        pushButton_7 = new QPushButton(horizontalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("icons/statistic.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);

        horizontalLayout->addWidget(pushButton_7);


        retranslateUi(pub);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pub);
    } // setupUi

    void retranslateUi(QWidget *pub)
    {
        pub->setWindowTitle(QApplication::translate("pub", "Form", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pub", "  encadrant", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("pub", "etudiant", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pub", "materiel", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pub", "sponsor", Q_NULLPTR));
        student_pic->setText(QString());
        materiel_pic->setText(QString());
        sponsor_pic->setText(QString());
        encadrant_pic->setText(QString());
        pushButton_6->setText(QApplication::translate("pub", "Publication", Q_NULLPTR));
        research_pic->setText(QString());
        tri_pic_2->setText(QApplication::translate("pub", "Tri Desc", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("pub", "Tri Pub", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("pub", "on", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("pub", "off", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("pub", "auto", Q_NULLPTR));
        tri_pic->setText(QApplication::translate("pub", "Tri ASC", Q_NULLPTR));
        label_2->setText(QApplication::translate("pub", "Liste des publications", Q_NULLPTR));
        lineEdit_4->setPlaceholderText(QApplication::translate("pub", "Rechercher", Q_NULLPTR));
        recherche_pic->setText(QString());
        filter->setText(QString());
        btn_delete->setText(QString());
        btn_update->setText(QString());
        popupLabel->setText(QString());
        nombrepub->setText(QString());
        nombrepub->setPlaceholderText(QApplication::translate("pub", "nobr pub", Q_NULLPTR));
        lineEdit_id_create->setText(QString());
        lineEdit_id_create->setPlaceholderText(QApplication::translate("pub", "ID_publication", Q_NULLPTR));
        lineEdit_sujet_create->setText(QString());
        lineEdit_sujet_create->setPlaceholderText(QApplication::translate("pub", "Sujet", Q_NULLPTR));
        lineEdit_propriete_create->setText(QString());
        lineEdit_propriete_create->setPlaceholderText(QApplication::translate("pub", "Propri\303\251t\303\251", Q_NULLPTR));
        lineEdit_description_create->setText(QString());
        lineEdit_description_create->setPlaceholderText(QApplication::translate("pub", "Description", Q_NULLPTR));
        label_5->setText(QApplication::translate("pub", "+", Q_NULLPTR));
        label_6->setText(QApplication::translate("pub", "Ajouter une publication", Q_NULLPTR));
        ajouter_btn->setText(QApplication::translate("pub", "ajouter", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pub", "PDF", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("pub", "Excel", Q_NULLPTR));
        lineEdit_nbpub_modifier->setText(QString());
        lineEdit_nbpub_modifier->setPlaceholderText(QApplication::translate("pub", "nobr pub", Q_NULLPTR));
        lineEdit_id_modifier->setText(QString());
        lineEdit_id_modifier->setPlaceholderText(QApplication::translate("pub", "ID_publication", Q_NULLPTR));
        lineEdit_sujet_modifier->setText(QString());
        lineEdit_sujet_modifier->setPlaceholderText(QApplication::translate("pub", "Sujet", Q_NULLPTR));
        lineEdit_propriete_modifier->setText(QString());
        lineEdit_propriete_modifier->setPlaceholderText(QApplication::translate("pub", "Propri\303\251t\303\251", Q_NULLPTR));
        lineEdit_description_modifier->setText(QString());
        lineEdit_description_modifier->setPlaceholderText(QApplication::translate("pub", "Description", Q_NULLPTR));
        modifier->setText(QApplication::translate("pub", "modifier", Q_NULLPTR));
        label_11->setText(QApplication::translate("pub", "+", Q_NULLPTR));
        label_12->setText(QApplication::translate("pub", "Modifier une publication", Q_NULLPTR));
        modifier_annuler->setText(QApplication::translate("pub", "annuler ", Q_NULLPTR));
        pushButton_13->setText(QString());
        label->setText(QApplication::translate("pub", "InteLab", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("pub", "statistique", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pub: public Ui_pub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUB_H

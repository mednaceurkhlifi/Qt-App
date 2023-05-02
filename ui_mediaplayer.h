/********************************************************************************
** Form generated from reading UI file 'mediaplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPLAYER_H
#define UI_MEDIAPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaplayer
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *playerLayout;
    QFrame *frame;
    QPushButton *playButton;
    QLabel *label_2;
    QPushButton *stopButton;
    QLabel *label_3;

    void setupUi(QDialog *mediaplayer)
    {
        if (mediaplayer->objectName().isEmpty())
            mediaplayer->setObjectName(QStringLiteral("mediaplayer"));
        mediaplayer->resize(400, 300);
        mediaplayer->setStyleSheet(QLatin1String("*{\n"
"\n"
"background-color: transparent;\n"
"color: #aa54ff; \n"
"} \n"
"#openButton,#stopButton,#playButton{\n"
"background-color: transparent;\n"
"}\n"
"\n"
"\n"
"#mediaplayer{\n"
"background-color: #040f13;\n"
"}  \n"
"#frame{\n"
"background-color: #071e26; \n"
"border-radius: 20px; \n"
"}\n"
""));
        verticalLayoutWidget = new QWidget(mediaplayer);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 221));
        playerLayout = new QVBoxLayout(verticalLayoutWidget);
        playerLayout->setObjectName(QStringLiteral("playerLayout"));
        playerLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(mediaplayer);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 229, 361, 61));
        frame->setStyleSheet(QLatin1String("#openButton,#stopButton,#playButton{\n"
"background-color: transparent;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        playButton = new QPushButton(frame);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(10, 10, 51, 41));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 47, 21));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/icons/play-button.png")));
        stopButton = new QPushButton(frame);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(60, 10, 51, 41));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 20, 47, 21));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/icons/pause-button.png")));
        label_2->raise();
        label_3->raise();
        playButton->raise();
        stopButton->raise();
        frame->raise();
        verticalLayoutWidget->raise();

        retranslateUi(mediaplayer);

        QMetaObject::connectSlotsByName(mediaplayer);
    } // setupUi

    void retranslateUi(QDialog *mediaplayer)
    {
        mediaplayer->setWindowTitle(QApplication::translate("mediaplayer", "Dialog", Q_NULLPTR));
        playButton->setText(QString());
        label_2->setText(QString());
        stopButton->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mediaplayer: public Ui_mediaplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYER_H

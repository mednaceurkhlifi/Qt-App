#include "dialog.h"
#include "ui_dialog.h"
#include "materiel.h"
#include<QIntValidator>
#include "connection.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QtSql>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include <QSystemTrayIcon>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtGui>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

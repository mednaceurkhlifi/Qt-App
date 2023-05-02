#ifndef CALENDAR_H
#define CALENDAR_H

#include <QCalendarWidget>
#include <QDate>
#include <QDialog>
#include <QInputDialog>
#include <QLabel>
#include <QMap>
#include <QMessageBox>

class Calendar : public QDialog
{
    Q_OBJECT

public:
    Calendar(QWidget *parent = nullptr);

private slots:
    void onDayDoubleClicked(const QDate &date);

private:
    QCalendarWidget *calendarWidget;
    QMap<QDate, QString> messages;
     QString fileName = "messages.txt";

    void saveMessages();
    void loadMessages();
    void displayMessage();
};

#endif // CALENDAR_H

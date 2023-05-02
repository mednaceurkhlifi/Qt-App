
#include "calendar.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFile>
#include <QTextStream>

Calendar::Calendar(QWidget *parent)
    : QDialog(parent)
{
    calendarWidget = new QCalendarWidget(this);
    setWindowTitle("Calendar");
    setFixedSize(500, 500);

    // Set the style sheet to color the "today" box in yellow
    calendarWidget->setStyleSheet("QCalendarWidget QAbstractItemView:enabled:selected { background-color: yellow; }");

    // Set the size and position of the calendar widget
    calendarWidget->setGeometry(20, 40, 460, 400);

    // Create a label to display the month and year
    QLabel *label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(20, 10, 460, 30);

    // Update the label text whenever the month changes
    connect(calendarWidget, &QCalendarWidget::currentPageChanged, [=]() {
        QDate date = calendarWidget->selectedDate();
        label->setText(date.toString("MMMM yyyy"));
    });

    // Set the initial text for the label
    QDate date = calendarWidget->selectedDate();
    label->setText(date.toString("MMMM yyyy"));

    // Connect doubleClicked signal of calendarWidget to onDayDoubleClicked slot
    connect(calendarWidget, &QCalendarWidget::activated, this, &Calendar::onDayDoubleClicked);

    // Load messages from persistent storage (file)
    loadMessages();
}

void Calendar::onDayDoubleClicked(const QDate &date)
{
    // Get existing message for the selected date, or an empty string if not found
    QString message = messages.value(date, "");

    // Show input dialog to edit or add a message
    bool ok;
    QString newMessage = QInputDialog::getText(this, "Enter Message", "Message:", QLineEdit::Normal, message, &ok);

    if (ok) {
        // Update messages map with the new message
        messages[date] = newMessage;

        // Save messages to persistent storage (file)
        saveMessages();

        // Show a message box with the updated message
        QMessageBox::information(this, "Message", "Message for " + date.toString() + ": " + newMessage);
    }
}

void Calendar::saveMessages()
{
    /*
    QFile file("messages.txt"); // File name and path of the text file
       if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
           QTextStream out(&file);
           for (const auto &date : messages.keys()) {
               QString dateString = date.toString(Qt::ISODate);
               QString message = messages.value(date);
               out << dateString << '\n'; // Write date to file
               out << message << '\n'; // Write message to file
           }
           file.close();
       }
       */
    QFile file(fileName);
      if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
          QTextStream out(&file);
          for (const auto &date : messages.keys()) {
              out << date.toString(Qt::ISODate) << "||" << messages.value(date) << "\n";
          }
          file.close();
      }
}

void Calendar::loadMessages()
{
    /*
    QFile file("messages.txt"); // File name and path of the text file
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString dateString = in.readLine(); // Read date from file
                QString message = in.readLine(); // Read message from file
                QDate date = QDate::fromString(dateString, Qt::ISODate);
                messages.insert(date, message); // Insert into messages map
            }
            file.close();
        }
        */
    QFile file(fileName);
       if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
           QTextStream in(&file);
           while (!in.atEnd()) {
               QString line = in.readLine();
               QStringList parts = line.split("||");
               if (parts.size() == 2) {
                   QString dateString = parts[0];
                   QString message = parts[1];
                   QDate date = QDate::fromString(dateString, Qt::ISODate);
                   messages.insert(date, message);
               }
           }
           file.close();
       }
}
void Calendar::displayMessage()
{
    // Get the selected date from the calendar widget
    QDate date = calendarWidget->selectedDate();
    // Get the corresponding message from the map
    QString message = messages.value(date);
    // Display the message in a message box
    QMessageBox::information(this, "Message", "Message for selected day: \n\n" + message);
}

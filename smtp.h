#ifndef SMTP_H
#define SMTP_H

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QSsl>
#include <qsslsocket.h>
#include <QSslError>

#include <QTextStream>
#include <QSslSocket>
#include <QVariant>
#include <QDebug>
#include <QAbstractSocket>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>



class Smtp : public QObject
{
    Q_OBJECT


public:
    Smtp( const QString &user, const QString &pass,
          const QString &host, qint16 port = 587, int timeout = 30000 );
    ~Smtp();

    void sendMail( const QString &from, const QString &to,
                   const QString &subject, const QString &body,
                   QStringList files = QStringList());

signals:
    void status( const QString &);

private slots:
    void stateChanged(QAbstractSocket::SocketState socketState);
    void errorReceived(QAbstractSocket::SocketError socketError);
    void disconnected();
    void connected();
    void readyRead();

private:
    int timeout;
    QString message;
    QTextStream *t;
    QSslSocket *socket;
    QString from;
    QString rcpt;
    QString response;
    QString user;
    QString pass;
    QString host;
    qint16 port;
    enum states{Tls, HandShake ,Auth,User,Pass,Rcpt,Mail,Data,Init,Body,Quit,Close};
    int state;

};
#endif // SMTP_H

#ifndef IOTHREAD_H
#define IOTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDataStream>
#include <QtSql>
#include <QObject>
#include "platformclient.h"

QT_BEGIN_NAMESPACE
class QTextEdit;
QT_END_NAMESPACE

class IOThread : public QThread
{
    Q_OBJECT

public:
    IOThread(int socketDescriptor, QObject *parent);
    void run() override;
    void sendRecommendation(QTcpSocket *tcpSocket);
signals:
    void error(QTcpSocket::SocketError socketError);
    void passInfoToServer(PlatformClient client);
    void passFbToServer(PlatformClient client);
    void RecommendationsReceivedfromMainServerThread();

public slots:
    void handleRecommendations(PlatformClient client);

private slots:
    void readInfo();
    void readFeedback();


private:
    PlatformClient Client;
    int socketDescriptor;
    QString text;
    QDataStream in;
};

#endif // IOTHREAD_H

#include "iothread.h"
#include <QtNetwork>

//for debugging purposes
#include <QTextStream>

IOThread::IOThread(int socketDescriptor, QObject *parent)
    : QThread(parent)
    , socketDescriptor(socketDescriptor)
{
}

void IOThread::run()
{
    QTcpSocket tcpSocket;
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket.error());
        return;
    }

    in.setDevice(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    connect(&tcpSocket, &QIODevice::readyRead, this, &IOThread::readInfo);

    QEventLoop loop1;
    connect(this, &IOThread::RecommendationsReceivedfromMainServerThread,
            &loop1, &QEventLoop::quit);

    loop1.exec();

    sendRecommendation(&tcpSocket);

    connect(&tcpSocket, &QIODevice::readyRead, this, &IOThread::readFeedback);

    tcpSocket.waitForDisconnected();
}

void IOThread::readInfo()
{
    in.startTransaction();

    QString name, age , gender, oScore, cScore, eScore, aScore, nScore;

    in >> name >> age >> gender >> oScore >> cScore >> eScore >> aScore >> nScore;

    Client.setName(name);
    Client.setAge(age.toInt());
    Client.setGender(gender);
    Client.setOpennessScore(oScore.toInt());
    Client.setConscientiousnessSScore(cScore.toInt());
    Client.setExtraversionScore(eScore.toInt());
    Client.setAgreeablenessScore(aScore.toInt());
    Client.setNeuroticismScore(nScore.toInt());

    if (!in.commitTransaction())
        return;

    emit passInfoToServer(Client);
}

void IOThread::readFeedback()
{
    in.startTransaction();

    QString feedback;
    in >> feedback;

    if (!in.commitTransaction())
        return;

    Client.setFeedback(feedback.toInt());

    emit passFbToServer(Client);
}

void IOThread::handleRecommendations(PlatformClient client)
{
    Client.setId(client.getId());
    Client.setBookRecommendation(client.getBookRecommendation());
    Client.setMovieRecommendation(client.getMovieRecommendation());
    Client.setQuoteRecommendation(client.getQuoteRecommendation());

    emit RecommendationsReceivedfromMainServerThread();
}

void IOThread::sendRecommendation(QTcpSocket *tcpSocket)
{
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << QString(Client.getBookRecommendation().getTitle())
            << QString(Client.getBookRecommendation().getDescription())
            << QString(Client.getBookRecommendation().getTag1Name())
            << QString(Client.getBookRecommendation().getTag2Name())
            << QString(Client.getBookRecommendation().getTag3Name())
            << QString(Client.getMovieRecommendation().getTitle())
            << QString(Client.getMovieRecommendation().getDescription())
            << QString(Client.getMovieRecommendation().getTag1Name())
            << QString(Client.getMovieRecommendation().getTag2Name())
            << QString(Client.getMovieRecommendation().getTag3Name())
            << QString(Client.getQuoteRecommendation().getContent())
            << QString(Client.getQuoteRecommendation().getTag1Name())
            << QString(Client.getQuoteRecommendation().getTag2Name())
            << QString(Client.getQuoteRecommendation().getTag3Name());               
        tcpSocket->write(block);
        tcpSocket->waitForBytesWritten(10000);
}

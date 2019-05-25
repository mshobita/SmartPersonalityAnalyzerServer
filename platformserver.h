#ifndef PLATFORMSERVER_H
#define PLATFORMSERVER_H

#include <QStringList>
#include <QTcpServer>
#include <QDataStream>
#include <QVector>
#include "iothread.h"

QT_BEGIN_NAMESPACE
class QTextEdit;
QT_END_NAMESPACE

class PlatformServer : public QTcpServer//, public QObject
{
    Q_OBJECT
public:
    PlatformServer(QObject *parent = 0);
    int saveInfo(PlatformClient client);

signals:
    void passInfotoGUI(PlatformClient client);
    void passRecommendationstoIOThread(PlatformClient client);
    void passFbtoGUI(PlatformClient client);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void handleInfo(PlatformClient client);
    void handleFeedback(PlatformClient client);

private:
    QVector<Book>   Books;
    QVector<Movie>  Movies;
    QVector<Quote>  Quotes;
    QVector<Tag>    Tags;
    QVector<PlatformClient> Clients;

    void generateBookRecommendation(int id);
    void generateMovieRecommendation(int id);
    void generateQuoteRecommendation(int id);
    void generateRecommendations(int id);
};

#endif // PLATFORMSERVER_H

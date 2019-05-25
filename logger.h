#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTextEdit>

class Logger : public QObject
{
 Q_OBJECT
public:
 explicit Logger(QObject *parent, QString fileName, QTextEdit *editor = 0);
 ~Logger();

private:
 QFile *file;
 QTextEdit *m_editor;

signals:

public slots:
 void write(const QString &value);

};

#endif // LOGGER_H

#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include "platformservergui.h"
#include "ui_platformservergui.h"


PlatformServerGUI::PlatformServerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlatformServerGUI)
{
    ui->setupUi(this);

    if (!server.listen()) {
        QMessageBox::critical(this, tr("Threaded Platform Server"),
                              tr("Unable to start the server: %1.")
                              .arg(server.errorString()));
        close();
        return;
    }

    connect(&server, &PlatformServer::passInfotoGUI,
            this, &PlatformServerGUI::handleInfo);

    connect(&server, &PlatformServer::passFbtoGUI,
            this, &PlatformServerGUI::handleFeedback);


    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    ui->IPvalLabel->setText(ipAddress);
    ui->PortvalLabel->setText(tr("%1").arg(server.serverPort()));

    setWindowTitle(tr("Threaded Platform Server"));

    createStatusBar();
    QString random_number = QString::number(QRandomGenerator::global()->bounded(100000));
    QString userName = QDir::home().dirName();
    QString fileName = "/home/"+userName+"/Desktop/log"+random_number+".txt";
    logger = new Logger(this, fileName, ui->statustextEdit);

}


PlatformServerGUI::~PlatformServerGUI()
{
    delete ui;
}

void PlatformServerGUI::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void PlatformServerGUI::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

void PlatformServerGUI::handleInfo(PlatformClient client)
{
    statusBar()->showMessage(client.getName());

    //writes in both log file and in multi-line text box
    logger->write("\n\nName: " + client.getName() + "\n"
                 + client.getName() + "'s Age: " + QString::number(client.getAge()) + "\n"
                 + client.getName() +  "'s Gender: " + client.getGender() +  "\n"
                 + client.getName() + "'s Openness Score: " + QString::number(client.getOpennessScore()) +  "\n"
                 + client.getName() + "'s ConscientiousnessSScore: " + QString::number(client.getConscientiousnessSScore()) + "\n"
                 + client.getName() + "'s ExtraversionScore: " + QString::number(client.getExtraversionScore()) + "\n"
                 + client.getName() + "'s AgreeablenessScore: " + QString::number(client.getAgreeablenessScore()) + "\n"
                 + client.getName() + "'s NeuroticismScore: " + QString::number(client.getNeuroticismScore()));
}

void PlatformServerGUI::handleFeedback(PlatformClient client)
{
    //writes in both log file and in multi-line text box
    logger->write("\n" + client.getName() + "'s Feedback: " + QString::number(client.getFeedback()));

}

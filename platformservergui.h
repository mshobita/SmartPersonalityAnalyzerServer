#ifndef PLATFORMSERVERGUI_H
#define PLATFORMSERVERGUI_H

#include <QMainWindow>
#include <QtSql>
#include "platformserver.h"
#include "logger.h"

namespace Ui {
class PlatformServerGUI;
}

class PlatformServerGUI : public QMainWindow//, public QObject
{
    Q_OBJECT

public:
    explicit PlatformServerGUI(QWidget *parent = nullptr);
    ~PlatformServerGUI();

private slots:
    void handleInfo(PlatformClient client);
    void handleFeedback(PlatformClient client);

private:
    Ui::PlatformServerGUI *ui;
    void createStatusBar();
    void showError(const QSqlError &err);
    PlatformServer server;
    Logger *logger;

};

#endif // PLATFORMSERVERGUI_H

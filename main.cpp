#include <QApplication>
#include <QtCore>

#include <stdlib.h>
#include "platformservergui.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlatformServerGUI gui;
    gui.show();

    return a.exec();
}

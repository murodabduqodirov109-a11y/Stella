#include "stellawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StellaWindow w;
    w.show();
    return a.exec();
}

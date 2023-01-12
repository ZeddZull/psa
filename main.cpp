#include "mainwindow.h"
#include "loadchart.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    LoadChart lc;
    lc.show();
    return a.exec();
}

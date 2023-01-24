#include "mainwindow.h"
//#include "mapwidget.h"
#include <QApplication>



//#include "dashboardwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //ashboardWindow mw;
    //mw.show();
    return a.exec();
}

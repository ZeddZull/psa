#ifndef AIRPORTWINDOW_H
#define AIRPORTWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "airport.h"

namespace Ui {
class AirportWindow;
}

class AirportWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AirportWindow(QWidget *parent = nullptr);
    ~AirportWindow();

private:
    Ui::AirportWindow *ui;
    QTableWidget *table;
    Airport AeroportClass = Airport();
    QVector<Airport::Donnees> ListeAeroport;
    QVector<Airport::Donnees>::Iterator it;

private :
    void TableWidgetDisplay();
};

#endif // AIRPORTWINDOW_H

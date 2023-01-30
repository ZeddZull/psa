#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include "planeposition.h"
#include <QMap>
#include <QVector>
#include <QListWidgetItem>
#include <QListWidget>
#include "airportwindow.h"
#include "flightwindow.h"

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

signals:
    void showAirportWindow();
    void showFlightWindow();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_ButtonAirportListDashboard_clicked();

    void on_ButtonFlightListDashboard_clicked();

    void on_ButtonDisconnect_clicked();

private:
    Ui::DashboardWindow *ui;
    QMap<QString,QVector<PlanePosition*>> planePaths;
    AirportWindow *airportwindow;
    FlightWindow *flightwindow;
};

#endif // DASHBOARDWINDOW_H

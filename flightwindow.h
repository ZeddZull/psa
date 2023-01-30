#ifndef FLIGHTWINDOW_H
#define FLIGHTWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QStringList>

namespace Ui {
class FlightWindow;
}

class FlightWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlightWindow(QWidget *parent = nullptr);
    ~FlightWindow();
    void readCSV();

private:
    Ui::FlightWindow *ui;
    QTableWidget *table;
};

#endif // FLIGHTWINDOW_H

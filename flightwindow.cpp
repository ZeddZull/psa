#include "flightwindow.h"
#include "ui_flightwindow.h"

FlightWindow::FlightWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FlightWindow)
{
    ui->setupUi(this);
    table = new QTableWidget(this);
    table->setRowCount(200);
    table->setColumnCount(6);
    QStringList hlabels;
    hlabels << "Name" << "Hours" << "Minutes" << "Latitude" << "Logitude" << "Altitude";
    table->setHorizontalHeaderLabels(hlabels);
    readCSV();
    table->setStyleSheet("QTableWidget{"
                                   "background-color : white;"
                                   "alternate-background-color: light blue;"
                                   "selection-background-color : black;"
                                   "}");
    table->setAlternatingRowColors(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setTextElideMode(Qt::ElideRight);

    table->setShowGrid(true);
    table->setGridStyle(Qt::DotLine);
    table->setSortingEnabled(true);
    table->setCornerButtonEnabled(true);
    setCentralWidget(table);

}

FlightWindow::~FlightWindow()
{
    delete ui;
    delete table;
}

void FlightWindow::readCSV()
{
    QFile file(":/data/Vol.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream stream(&file);
    QStringList list;
    QVector<QString> test;
    int row = 0;
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        list = line.split(",");
        int col = 0;
        bool header = false;
        for (QString &str : list) {
            if(str == "name" || str == "heure" || str == "minutes" || str == "latitude" || str == "longitude" || str == "altitude") {header = true; continue;}

            test.push_back(str);
            table->setItem(row, col, new QTableWidgetItem(str));
            col++;
        }
        if(header) continue;

        row++;
    }
    file.close();
}

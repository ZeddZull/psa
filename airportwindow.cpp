#include "airportwindow.h"
#include "ui_airportwindow.h"

AirportWindow::AirportWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AirportWindow)
{
    ui->setupUi(this);
    TableWidgetDisplay();
}

AirportWindow::~AirportWindow()
{
    delete ui;
    delete table;
}

void AirportWindow::TableWidgetDisplay()
{
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(9);
    table->setColumnCount(12);

    QStringList hlabels;
    hlabels << "[x] coordinate" << "[y] coordinate" << "Name" << "Name(en)" << "Name(fr)" << "IATA code" << "ICAO code" << "Wikidata id" << "Operator" << "Country" << "Country Code" << "Altitude";
    table->setHorizontalHeaderLabels(hlabels);
    AeroportClass.lireFichierDonnees(ListeAeroport);
    it = ListeAeroport.begin();

    for(int i =0; i < table->rowCount();i++){
        QTableWidgetItem *item;
        for(int j=0; j< table->columnCount();j++){
            item = new QTableWidgetItem;
            if (j ==0)
            item->setText(it->geoPoint_x);
            if (j ==1)
            item->setText(it->geoPoint_y);
            if (j ==2)
            item->setText(it->name);
            if (j ==3)
            item->setText(it->nameENG);
            if (j ==4)
            item->setText(it->nameFR);
            if (j ==5)
            item->setText(it->iataCode);
            if (j ==6)
            item->setText(it->icaoCode);
            if (j ==7)
            item->setText(it->wikidataID);
            if (j ==8)
            item->setText(it->operator_);
            if (j ==9)
            item->setText(it->country);
            if (j ==10)
            item->setText(it->countryCode);
            if (j ==11)
            item->setText(it->altitude);

            table->setItem(i,j,item);
        }
        ++it;
    }

    // --> modification de l'esthétique du tableau.
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

    table->horizontalHeader()->setVisible(true);

    // --> Affichage du tableau dans la fenetre.
    this->setCentralWidget(table);
}

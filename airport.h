#ifndef AIRPORT_H
#define AIRPORT_H
#include <QString>
#include <QFile>
#include "QMessageBox"

class Airport
{
public:
    Airport();

public:
    struct Donnees{
        QString geoPoint_x;
        QString geoPoint_y;
        QString name;
        QString nameENG;
        QString nameFR;
        QString iataCode;
        QString icaoCode;
        QString wikidataID;
        QString operator_;
        QString country;
        QString countryCode;
        QString altitude;
    };

    static void lireFichierDonnees(QVector<Donnees>& tableau);
};

#endif // AIRPORT_H

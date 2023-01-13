#include "airport.h"

Airport::Airport()
{

}

void Airport::lireFichierDonnees(QVector<Donnees>& tableau)
{


    QString chemin = ":/Airports.csv" ;

    QFile fichier(chemin);
    QMessageBox messageAlert;
    if (!fichier.open(QFile::ReadOnly)) {
        messageAlert.setWindowTitle("Attention !");
        messageAlert.setIcon(QMessageBox::Warning);
        messageAlert.setText(QString::fromUtf8("Problème non critique !"));
        messageAlert.setInformativeText(QString::fromUtf8("<center><big>Le fichier :</big> \"<b>%1</b>\" <big>est absent du serveur!</big></center>").arg(chemin));
        messageAlert.exec();
    }

    QTextStream flux(&fichier);
    while(!flux.atEnd()){
        Donnees data;
        QString ligne = flux.readLine();
        QStringList champ = ligne.split(",");
        data.geoPoint_x = champ.at(0);  // pour des floats
        data.geoPoint_y = champ.at(1);  // pour des floats
        data.name = champ.at(2); // pour du texte
        data.nameENG = champ.at(3); // pour du texte
        data.nameFR = champ.at(4); // pour du texte
        data.iataCode = champ.at(5); // pour du texte
        data.icaoCode = champ.at(6); // pour du texte
        data.wikidataID = champ.at(7); // pour du texte
        data.operator_ = champ.at(8); // pour du texte
        data.country = champ.at(9); // pour du texte
        data.countryCode = champ.at(10); // pour du texte
        data.altitude = champ.at(11); // pour des entiers
        tableau.push_back(data);
    }
}

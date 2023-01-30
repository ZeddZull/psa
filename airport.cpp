#include "airport.h"

Airport::Airport()
{

}

void Airport::lireFichierDonnees(QVector<Donnees>& tableau)
{
    QString chemin = ":Airports.csv" ;
    QFile fichier(chemin);
    QMessageBox messageAlert;

    // --> verification du fichier, si probleme, le signaler à l'utilisateur.
    if (!fichier.open(QFile::ReadOnly)) {
        messageAlert.setWindowTitle("Attention !");
        messageAlert.setIcon(QMessageBox::Warning);
        messageAlert.setText(QString::fromUtf8("Problème non critique !"));
        messageAlert.setInformativeText(QString::fromUtf8("<center><big>Le fichier :</big> \"<b>%1</b>\" <big>est absent du serveur!</big></center>").arg(chemin));
        messageAlert.exec();
    }

    // --> Parcours du vecteur tableau et stockage des differentes données.
    QTextStream flux(&fichier);
    while(!flux.atEnd()){
        Donnees data;
        QString ligne = flux.readLine();
        QStringList champ = ligne.split(",");
        data.geoPoint_x = champ.at(0);
        data.geoPoint_y = champ.at(1);
        data.name = champ.at(2);
        data.nameENG = champ.at(3);
        data.nameFR = champ.at(4);
        data.iataCode = champ.at(5);
        data.icaoCode = champ.at(6);
        data.wikidataID = champ.at(7);
        data.operator_ = champ.at(8);
        data.country = champ.at(9);
        data.countryCode = champ.at(10);
        data.altitude = champ.at(11);
        tableau.push_back(data);
    }

    // --> Fermeture du fichier
    fichier.close();
}

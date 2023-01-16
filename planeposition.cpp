#include "planeposition.h"

PlanePosition::PlanePosition(QString pn, int h, int m, float lat, float lon, float alt)
{
    planeName = pn;
    hour = h;
    minute = m;
    latitude = lat;
    longitude = lon;
    altitude = alt;
}
QString PlanePosition::getPlaneName(){
    return planeName;
}
int PlanePosition::getHour(){
    return hour;
}
int PlanePosition::getMinute(){
    return minute;
}
float PlanePosition::getLatitude(){
    return latitude;
}
float PlanePosition::getLongitude(){
    return longitude;
}
float PlanePosition::getAltitude(){
    return altitude;
}

bool PlanePosition::getPositions(QVector<PlanePosition*> *paths){
    *paths = QVector<PlanePosition*>();

    QFile file(":/data/Vol.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }
    QTextStream in(&file);
    in.readLine();
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList lines = line.split(',');
        paths->push_back(new PlanePosition(lines[0], lines[1].toInt(), lines[2].toInt(), lines[4].toFloat(), lines[3].toFloat(), lines[5].toFloat()));
    }
    return true;
}

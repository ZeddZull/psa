#include "planepath.h"

PlanePath::PlanePath(QString pn, int h, int m, float lat, float lon, float alt)
{
    planeName = pn;
    hour = h;
    minute = m;
    latitude = lat;
    longitude = lon;
    altitude = alt;
}
QString PlanePath::getPlaneName(){
    return planeName;
}
int PlanePath::getHour(){
    return hour;
}
int PlanePath::getMinute(){
    return minute;
}
float PlanePath::getLatitude(){
    return latitude;
}
float PlanePath::getLongitude(){
    return longitude;
}
float PlanePath::getAltitude(){
    return altitude;
}

bool PlanePath::getPaths(std::vector<PlanePath*> *paths){
    *paths = std::vector<PlanePath*>();

    QFile file(":/data/Vol.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }
    QTextStream in(&file);
    qDebug() << in.readLine();
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList lines = line.split(',');
        paths->push_back(new PlanePath(lines[0], lines[1].toInt(), lines[2].toInt(), lines[3].toFloat(), lines[4].toFloat(), lines[5].toFloat()));
    }
    return true;
}

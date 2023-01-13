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

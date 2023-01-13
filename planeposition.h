#ifndef PLANEPATH_H
#define PLANEPATH_H
#include <QString>
#include <vector>
#include <QFile>
#include <QDebug>

class PlanePosition
{
public:
    PlanePosition(QString, int, int, float, float, float);
    QString getPlaneName();
    int getHour();
    int getMinute();
    float getLatitude();
    float getLongitude();
    float getAltitude();
    static bool getPositions(std::vector<PlanePosition*>*);
private:
    QString planeName;
    int hour;
    int minute;
    float latitude;
    float longitude;
    float altitude;
};

#endif // PLANEPATH_H
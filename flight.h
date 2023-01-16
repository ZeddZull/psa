#ifndef FLIGHT_H
#define FLIGHT_H

#include <QObject>
#include <QPointF>

class Flight : public QObject
{
    Q_OBJECT

public:
    explicit Flight(QObject *parent = nullptr);

signals:
    void triggerAddPath(QPointF coord);
    void triggerClearPath();
};

#endif // FLIGHT_H

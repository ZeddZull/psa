#ifndef MAPMODEL_H
#define MAPMODEL_H

#include <QObject>
#include <QGeoCoordinate>
#include <QList>
#include <qqml.h>

class MapModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QGeoCoordinate> markers READ markers NOTIFY markersChanged)
    QML_ELEMENT

public:
    explicit MapModel(QObject *parent = nullptr);
    QList<QGeoCoordinate> markers() const;

public slots:
    void setMarkers(const QList<QGeoCoordinate> &markers);

signals:
    void markersChanged(const QList<QGeoCoordinate> &markers);

public:
    QList<QGeoCoordinate> m_markers;
};

#endif // MAPMODEL_H

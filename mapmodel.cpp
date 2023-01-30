#include "mapmodel.h"
#include <QGeoCoordinate>

MapModel::MapModel(QObject *parent) : QObject(parent)
{

}

QList<QGeoCoordinate> MapModel::markers() const
{
    return m_markers;;
}

void MapModel::setMarkers(const QList<QGeoCoordinate> &markers)
    {
        if (m_markers == markers)
            return;

        m_markers = markers;
        emit markersChanged(m_markers);
    }

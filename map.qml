import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.6
import QtPositioning 5.5
import Flight 1.0

Item {
    width: 512
    height: 512
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map{
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(44.78,3.19)
        zoomLevel: 6
        MapPolyline{
            id: flight_view
            line.width: 3
            line.color: 'green'
            path:[
                {latitude: 43.0962276, longitude: 6.1498611},
                {latitude: 43.05754144285714, longitude: 6.387892314285714},
                {latitude: 43.01885528571429, longitude: 6.625923528571429},
                {latitude: 42.980169128571426, longitude: 6.863954742857143}
            ]
            Connections{
                target: flight
                onTriggerClearPath: flight_view.setPath([])
                onTriggerAddPath: (point) => {flight_view.addCoordinate({latitude: point.y, longitude: point.x})}
            }
        }
    }
}

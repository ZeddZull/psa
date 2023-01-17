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
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(44.78,3.19)
        zoomLevel: 6
        copyrightsVisible: false
        focus: true

        MapPolyline{
            id: flight_view
            line.width: 2
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

        MapCircle {
                        center: QtPositioning.coordinate(43.0962276,6.1498611)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(42.5546214,9.4822981)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(43.4375586,5.2135912)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(43.6299473,1.3637499)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(43.3791392,-0.4201974)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(45.7245281,5.0873268)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(43.5798377,3.9664417)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(43.6597926,7.2150735)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }
        MapCircle {
                        center: QtPositioning.coordinate(43.4691926,-1.5231207)
                        radius: 5000.0
                        color: 'red'
                        border.width: 1
                    }

        }
}

/*Component.onCompleted: {
        var textObject = map.

        textObject.text = "Aéroport de Toulon-Hyères"
        textObject.coordinate = QtPositioning.coordinate(43.0962276, 6.1498611)

        textObject.text = "Aéroport international de Bastia-Poretta"
        textObject.coordinate = QtPositioning.coordinate(42.5546214, 9.4822981)

        textObject.text = "Aéroport de Marseille Provence"
        textObject.coordinate = QtPositioning.coordinate(43.4375586, 5.2135912)

        textObject.text = "Aéroport de Toulouse-Blagnac"
        textObject.coordinate = QtPositioning.coordinate(43.6299473, 1.3637499)

        textObject.text = "Aéroport de Pau Pyrénées"
        textObject.coordinate = QtPositioning.coordinate(43.3791392,-0.4201974)

        textObject.text = "Aéroport Lyon Saint-Exupéry"
        textObject.coordinate = QtPositioning.coordinate(45.7245281, 5.0873268)

        textObject.text = "Aéroport de Montpellier - Méditerranée"
        textObject.coordinate = QtPositioning.coordinate(43.5798377, 3.9664417)

        textObject.text = "Aéroport de Nice-Côte d'Azur"
        textObject.coordinate = QtPositioning.coordinate(43.6597926, 7.2150735)

        textObject.text = "Aéroport de Biarritz Pays Basque"
        textObject.coordinate = QtPositioning.coordinate(43.4691926, -1.5231207)

        map.addMapObject(textObject)
    }*/

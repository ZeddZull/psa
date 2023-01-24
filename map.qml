import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.6
import QtPositioning 5.5
import Flight 1.0

Item {
    width: 1080
    height: 580
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    ListModel {
            id: locationModel
            ListElement {lat: 43.0962276; lon: 6.1498611; color: "red"; radius:5000}
            ListElement {lat: 42.5546214; lon: 9.4822981; color: "red"; radius:5000}
            ListElement {lat: 43.4375586; lon: 5.2135912; color: "red"; radius:5000}
            ListElement {lat: 43.6299473; lon: 1.3637499; color: "red"; radius:5000}
            ListElement {lat: 43.3791392; lon: -0.4201974; color: "red"; radius:5000}
            ListElement {lat: 45.7245281; lon: 5.0873268; color: "red"; radius:5000}
            ListElement {lat: 43.5798377; lon: 3.9664417; color: "red"; radius:5000}
            ListElement {lat: 43.6597926; lon: 7.2150735; color: "red"; radius:5000}
            ListElement {lat: 43.4691926; lon: -1.5231207; color: "red"; radius:5000}
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
            path:[]
            Connections{
                target: flight
                onTriggerClearPath: flight_view.setPath([])
                onTriggerAddPath: (point) => {flight_view.addCoordinate({latitude: point.y, longitude: point.x})}
            }
        }

        MapItemView {
                    model: locationModel

                    delegate: MapCircle {
                        center: QtPositioning.coordinate(lat, lon) // lat et lon depuis le modele
                        radius: model.radius
                        opacity: 1
                        color: model.color
                        border.color: model.color
                    }
                }

        /*MapItemView {
                    model: locationModel

                    delegate: MapQuickItem {
                        coordinate: QtPositioning.coordinate(lat, lon)
                        anchorPoint: Qt.point(10,30) // les coordonnées locale de l'icon a centées sur les coordonnées géographique

                        sourceItem: Image {
                            source: "qrc:/data_images/images/marker.jpg"
                            height: 30
                            width: 20
                        }
                    }
                }*/
    }
}

        /*MapCircle {
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

        }*/

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

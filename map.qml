import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.6
import QtPositioning 5.5


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
        property MapCircle circle
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(44.78,3.19)
        zoomLevel:  6

        //@disable-check M16
        /*Component.onCompleted: {
                circle = Qt.createQmlObject('import QtLocation 5.6; MapCircle {}', page)
                circle.center = map.center
                circle.center = map.
                circle.radius = 5000.0
                circle.color = 'green'
                circle.border.width = 100
                map.addMapItem(circle)
            }*/

        MapCircle {
                center: map.center
                radius: 5000.0
                color: 'green'
                border.width: 3
            }
    }
}



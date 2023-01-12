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
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(44.78,3.19)
        zoomLevel: 6
    }
}

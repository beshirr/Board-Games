import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Board Games")

    Loader {
        id: gamecontentLoader
        anchors.fill: parent
        source: "mianwindow.qml"
    }
}

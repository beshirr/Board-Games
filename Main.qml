import QtQuick

Window {
    width: 1024
    height: 768
    visible: true
    title: qsTr("Board Games")

    Loader {
        id: gamecontentLoader
        anchors.fill: parent
        source: "mainwindow.qml"
    }
}

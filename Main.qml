import QtQuick

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("Board Games")

    Loader {
        id: gamecontentLoader
        anchors.fill: parent
        source: "mainwindow.qml"
    }
}

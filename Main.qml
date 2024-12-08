import QtQuick

Window {
    width: 1280
    height: 800
    visible: true
    title: qsTr("Board Games")

    Loader {
        id: gamecontentLoader
        anchors.fill: parent
        source: "mainwindow.qml"
    }
}

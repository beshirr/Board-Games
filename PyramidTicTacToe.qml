import QtQuick
import QtQuick.Controls

Item {
    id: pyramidWindow
    width: 400
    height: 400
    property int playerTurn: 1

    Rectangle {
        anchors.fill: parent
        color: "#000000"
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        spacing: 5

        Text {
            text: "Pyramid Tic Tac Toe"
            font.pixelSize: 28
            color: "#555"
        }
    }

    Grid {
        id: topPyramidGrid
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 100
        columns: 1
        rows: 1
        width: parent.width * (0.8/5.0)
        height: parent.height * (0.8/3.3)

        Repeater {
            model: 1
            Rectangle {
                id: topCell
                anchors.fill: parent
                color: "#000000"
                border.width: 2
                border.color: "#ffffff"
                radius: 20
            }
        }
    }

    Grid {
        id: middlePyramidGrid
        anchors.top: topPyramidGrid.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
        columns: 3
        rows: 1
        width: parent.width * (2.4/5.0)
        height: parent.height * (0.8/3.3)
        columnSpacing: 10
        Repeater{
            model: 3

            Rectangle {
                id: middleCell
                width: parent.width / 3.0
                height: parent.height
                color: "#000000"
                border.width: 2
                border.color: "#ffffff"
                radius: 20
            }
        }
    }

    Grid {
        id: bottomPyramidGrid
        anchors.top: middlePyramidGrid.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
        columns: 5
        rows: 1
        width: parent.width * 0.8
        height: parent.height * (0.8/3.3)
        columnSpacing: 10
        Repeater {
            model: 5

            Rectangle {
                id: bottomCell
                width: parent.width / 5.0
                height: parent.height
                color: "#000000"
                border.width: 2
                border.color: "#ffffff"
                radius: 20
            }
        }
    }

    Button {
        text: "Back to Menu"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        onClicked: {
            gamecontentLoader.source = "mainwindow.qml";
        }
    }

}

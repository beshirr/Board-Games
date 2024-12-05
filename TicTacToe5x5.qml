import QtQuick
import QtQuick.Controls

Item {
    width: 400
    height: 400

    Rectangle {
        anchors.fill: parent
        color: "black"
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        spacing: 10

        Text {
            text: "Tic Tac Toe 5x5"
            font.pixelSize: 28
            color: "#555"
        }
    }

    Grid {
        id: gameBoard
        rows: 5
        columns: 5
        spacing: 8
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.8

        Repeater {
            model: 25
            Rectangle {
                width: gameBoard.width / 5 - gameBoard.spacing
                height: gameBoard.height / 5 - gameBoard.spacing
                color: "#000000"
                border.color: "white"
                border.width: 2
                Text {
                    id: cellText
                    anchors.centerIn: parent
                    font.pixelSize: 128
                    text: ""
                    color: "#333"
                }
                MouseArea {
                    anchors.fill: parent
                    // onClicked: {
                    //     cellText.text = "X"
                    //     // TODO: Add code logic
                    //
                    // }
                }
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

    Connections {
        target: x5_backend
    }

}

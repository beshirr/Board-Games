import QtQuick
import QtQuick.Controls

Item{
    id: wordWindow
    width: 400
    height: 400
    property int playerTurn: 1

    Rectangle{
        anchors.fill: parent
        color: "#000000"
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        spacing: 5

        Text {
            text: "Word Tic Tac Toe"
            font.pixelSize: 28
            color: "#555"
        }
    }

    Grid {
        id: gameBoard
        rows: 3
        columns: 3
        spacing: 10
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.8
        Repeater {
            model: 9
            Rectangle {
                width: gameBoard.width / 3.0
                height: gameBoard.height / 3.0
                color: "#000000"
                border.color: "white"
                border.width: 2
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

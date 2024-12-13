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
        spacing: 10

        Text {
            text: "Word Tic Tac Toe"
            font.pixelSize: 28
            color: "#555"
        }
        Text {
            text: "Player " + wordWindow.playerTurn + "'s turn"
            font.pixelSize: 20
            color: "#555"
        }
    }

    Grid {
        id: gameBoard
        rows: 3
        columns: 3
        spacing: 12
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.8
        Repeater {
            model: 9
            Rectangle {
                width: gameBoard.width / 3 - gameBoard.spacing
                height: gameBoard.height / 3 - gameBoard.spacing
                color: "#000000"
                border.color: "white"
                border.width: 2
                radius: 20
                Text {
                    id: cellText
                    anchors.centerIn: parent
                    font.pixelSize: 128
                    text: ""
                    color: "#333"
                }
                TextArea {
                    id: textcell
                    anchors.fill: parent
                    anchors.centerIn: parent
                    font.pixelSize: 32
                    text: ""
                    readOnly: false
                    color: "#000000"
                    onTextChanged: {
                        if(text === ""){
                            if (text.length > 1 || !text.match(/^[a-zA-Z]$/)) {
                                text = text.slice(0, 1).toUpperCase();
                                WordWindow.playerTurn = 2
                            }
                        }
                    }
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
}

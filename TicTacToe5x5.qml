import QtQuick
import QtQuick.Controls
import TicTacToe5x5
import "t5x5Helpers.js" as Helpers

Item {
    anchors.fill: parent
    property string nPlayers: "1"
    Board5x5 {
        id: board
    }

    Player5x5 {
        id: player1
        name: "PLAYER-1"
        symbol: 'X'
        nWins: 0
    }

    Player5x5 {
        id: player2
        name: "PLAYER-2"
        symbol: "O"
        nWins: 0
    }

    RandomPlayer5x5 {
        id: computer
        name: "COMPUTER"
        symbol: "O"
    }

    Rectangle {
        anchors.fill: parent
        color: "black"
    }

    Component.onCompleted: {

    }

    Button {
        id: playersType
        width: 30
        height: 30
        text: nPlayers + "P"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 700
        onClicked: {
            nPlayers = (nPlayers === "1")? "2" : "1";
            text: nPlayers + "P"
            board.reset_Board()
        }
    }

    TextEdit {
        id: player1Name
        anchors.left: parent.left
        anchors.leftMargin: 450
        y: 650
        text: player1.name
        color: "white"
        font.pointSize: 20
        onTextChanged: {
            player1.name = text
        }
        Keys.onReturnPressed: {
            focus = false;
        }
    }
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 24
        text: Helpers.player1Score
        color: "white"
    }


    TextEdit {
        id: player2Name
        anchors.right: parent.right
        anchors.rightMargin: 450
        y: 650
        text: (nPlayers === "1")? computer.name : player2.name
        color: "white"
        font.pointSize: 20
        onTextChanged: {
            player_2Name: text
        }
        Keys.onReturnPressed: {
            focus = false;
        }
    }

    Grid {
        id: gameBoard
        rows: 5
        columns: 5
        spacing: 0
        anchors.centerIn: parent
        width: parent.width * 0.5
        height: parent.height * 0.5

        Repeater {
            model: board.f_board
            Rectangle {
                width: gameBoard.width / 5 - gameBoard.spacing
                height: gameBoard.height / 5 - gameBoard.spacing
                color: "#000000"
                border.color: "white"
                border.width: 2
                Text {
                    id: cellText
                    anchors.centerIn: parent
                    font.pixelSize: 85
                    text: modelData
                    color: "#333"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        Helpers.run(index);
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

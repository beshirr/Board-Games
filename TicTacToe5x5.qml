import QtQuick
import QtQuick.Controls
import TicTacToe5x5


Item {
    anchors.fill: parent

    Board5x5 {
        id: board
    }

    Rectangle {
        anchors.fill: parent
        color: "black"
    }

    property string nPlayers : "1"
    property int playerTurn: 1
    property int player1_Score: 0
    property int player2_Score: 0
    property string player_1Name: "PLAYER-1"
    property string player_2Name: (nPlayers === "1")? "COMPUTER" : "PLayer2"

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
        text: player_1Name
        color: "white"
        font.pointSize: 20
        onTextChanged: {
            player_1Name: text
        }
        Keys.onReturnPressed: {
            focus = false;
        }
    }
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 24
        text: player1_Score
        color: "white"
    }


    TextEdit {
        id: player2Name
        anchors.right: parent.right
        anchors.rightMargin: 450
        y: 650
        text: player_2Name
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
                        if (nPlayers === "2") {
                            if (playerTurn === 1) {
                                if (board.update_board(Math.floor(index / 5), index % 5, 'X')) { // Modify to make it player.symbol
                                    cellText.text = "X"
                                    playerTurn = 2
                                }
                            } else {
                                if (board.update_board(Math.floor(index / 5), index % 5, 'O')) {
                                    cellText.text = "O"
                                    playerTurn = 1
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    Connections {
        target: board
        function onSequenceWon() {
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

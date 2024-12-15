import QtQuick
import QtQuick.Controls
import Misere
import "MisereHelpers.js" as Helpers

Item {
    anchors.fill: parent
    property string nPlayers: "1"
    property int player_1Total: 0
    property int player_2Total: 0
    property bool gameActive: true
    property bool game_is_won: false
    property bool game_is_drawn: false


    MisereBoard {
        id: board
    }

    MiserePlayer {
        id: player1
        name: "PLAYER-1"
        symbol: 'X'
    }

    MiserePlayer {
        id: player2
        name: "PLAYER-2"
        symbol: "O"
    }

    MisereRandomPlayer {
        id: computer
        name: "COMPUTER"
        symbol: "O"
    }

    Rectangle {
        anchors.fill: parent
        color: "black"
    }

    Text {
        text: "MISERE TIC-TAC-TOE"
        color: "white"
        font.bold: true;
        font.pixelSize: 64
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 40
    }

    Button {
        id: playersType_button
        width: 50
        height: 50
        font.pixelSize: 20
        text: nPlayers + "P"
        anchors.bottom: player2Name_textEdit.top
        anchors.bottomMargin: 20
        anchors.horizontalCenter: player2Name_textEdit.horizontalCenter
        onClicked: {
            nPlayers = (nPlayers === "1") ? "2" : "1";
            text = nPlayers + "P"
            player2Name_textEdit.text = (nPlayers === "1") ? computer.name : player2.name;
            board.reset_Board()
            Helpers.resetScore();
            Helpers.resetPlayerTurn();
        }

        background: Rectangle {
            color: "#333"
            radius: 10
        }
    }

    TextEdit {
        id: player1Name_textEdit
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.verticalCenter: parent.verticalCenter
        text: player1.name
        color: "white"
        font.pointSize: 20
        onTextChanged: {
            if (text.trim() === "") text = "PLAYER-1";
        }
        Keys.onReturnPressed: {
            focus = false;
        }
    }

    Text {
        id: player1TotalScore
        text: player_1Total
        color: "white"
        font.pixelSize: 48

        anchors.horizontalCenter: player1Name_textEdit.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: player1Name_textEdit.bottom
    }

    TextEdit {
        id: player2Name_textEdit
        anchors.right: parent.right
        anchors.rightMargin: 100
        anchors.verticalCenter: parent.verticalCenter
        text: (nPlayers === "1") ? computer.name : player2.name
        color: "white"
        font.pointSize: 20
        onTextChanged: {
            if (text.trim() === "") {
                text = (nPlayers === "1") ? computer.name : player2.name;
            }
        }
        Keys.onReturnPressed: {
            focus = false;
        }
    }

    Text {
        id: player2TotalScore
        text: player_2Total
        color: "white"
        font.pixelSize: 48

        anchors.horizontalCenter: player2Name_textEdit.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: player2Name_textEdit.bottom
    }

    Grid {
        id: gameBoard
        rows: 3
        columns: 3
        spacing: 0
        anchors.centerIn: parent
        width: parent.width * 0.45
        height: parent.height * 0.45

        Repeater {
            model: board.f_board
            Rectangle {
                width: gameBoard.width / 3 - gameBoard.spacing
                height: gameBoard.height / 3 - gameBoard.spacing
                color: "#000000"
                border.color: "white"
                border.width: 2
                radius: 5

                Text {
                    id: cellText
                    anchors.centerIn: parent
                    font.pixelSize: 72
                    text: modelData
                    color: "#333"
                }
                MouseArea {
                    id: cellMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    enabled: gameActive
                    onClicked: {
                        Helpers.run(index);
                    }
                    onEntered: parent.color = "#666"
                    onExited: parent.color = "#444"
                }
            }
        }
    }

    Button {
        id: playAgainButton
        text: "  Play Again  "
        font.pixelSize: 24
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: statusMessage.bottom
        anchors.topMargin: 20
        visible: !gameActive
        onClicked: {
            Helpers.playAgain();
            gameActive = true;
        }

        background: Rectangle {
            color: "#007BFF"
            radius: 10
        }
    }


    Text {
        id: statusMessage
        text: gameActive ? "" : "Game Over! Press 'Play Again'"
        color: "white"
        font.pixelSize: 32
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: gameStatusMessage.bottom
        anchors.topMargin: 15
        visible: !gameActive
    }

    Text {
        id: gameStatusMessage
        text: {
            if (game_is_won) {
                return (Helpers.playerTurn === 0) ? player2Name_textEdit.text + " WINS!" : player1Name_textEdit.text + " WINS!";
            } else if (game_is_drawn) {
                return "TIE!";
            } else {
                return "";
            }
        }
        color: "white"
        font.pixelSize: 42
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: gameBoard.bottom
        anchors.topMargin: 20
        visible: !gameActive
    }


    Connections {
       target: board
       onBoardReset: Helpers.resetPlayerTurn()
    }

    Button {
        id: backMenu
        text: "Back to Menu"
        font.pixelSize: 16
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 30
        anchors.leftMargin: 40
        onClicked: {
            gamecontentLoader.source = "mainwindow.qml";
        }

        background: Rectangle {
            color: "#333"
            radius: 10
        }
    }
}

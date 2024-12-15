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
    }

    Player5x5 {
        id: player2
        name: "PLAYER-2"
        symbol: "O"
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

    Text {
        text: "5x5 TIC-TAC-TOE"
        color: "white"
        font.bold: true;
        font.pixelSize: 64
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 85
    }

    Button {
        id: playersType_button
        width: 50
        height: 50
        text: nPlayers + "P"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: gameBoard.bottom
        anchors.topMargin: 60
        onClicked: {
            nPlayers = (nPlayers === "1") ? "2" : "1";
            text = nPlayers + "P"
            player2Name_textEdit.text = (nPlayers === "1") ? computer.name : player2.name;
            board.reset_Board()
            Helpers.resetPlayerTurn();
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
            player1.name = text;
        }
        Keys.onReturnPressed: {
            focus = false;
        }
    }

    Text {
        id: player1TotalScore
        text: Helpers.player_1Total + " : " + board.player1Wins
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
        text: (nPlayers === "1")? computer.name : player2.name
        color: "white"
        font.pointSize: 20
        onTextChanged: {
            if (text.trim() === "") text = (nPlayers === "1") ? computer.name : "PLAYER-2";
            player2.name = text
        }
        Keys.onReturnPressed: {
            focus = false;
        }
    }

    Text {
        id: player2TotalScore
        text: Helpers.player_1Total + " : " + board.player2Wins
        color: "white"
        font.pixelSize: 48

        anchors.horizontalCenter: player2Name_textEdit.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: player2Name_textEdit.bottom
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
                    font.pixelSize: 72
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

    Connections {
        target: board
        onBoardReset: Helpers.resetPlayerTurn()
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

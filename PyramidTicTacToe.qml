import QtQuick
import QtQuick.Controls
import PyramidTicTacToe
import PyramidHelpel as Helper

Item {
    id: pyramidWindow
    width: 400
    height: 400
    property int playerTurn: 1

    Rectangle {
        anchors.fill: parent
        color: "#000000"
    }

    PyramidBoard {
        id: board
    }

    PramidPlayer {
        id: player1
        name: "PLAYER-1"
        symol: "X"

    }

    PyramidPlayer {
        id: player2
        name: "PLAYER-2"
        symbol: "O"
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

                Text {
                    id: topTextCell
                    color: "#333"
                    anchors.centerIn: parent
                    font.pixelSize: 120
                    text: " "
                }
                MouseArea{
                    id: topMouseArea
                    anchors.fill: parent
                    onClicked: {
                        if (topTextCell.text === " "){
                            topTextCell.text = "X"
                        }
                    }
                }
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
                Text {
                    id: middleTextCell
                    color: "#333"
                    anchors.centerIn: parent
                    font.pixelSize: 120
                    text: " "
                }
                MouseArea{
                    id: middleMouseArea
                    anchors.fill: parent
                    onClicked: {
                        if (middleTextCell.text === " "){
                            middleTextCell.text = "X"
                        }
                    }
                }

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
                Text {
                    id: bottomTextCell
                    color: "#333"
                    anchors.centerIn: parent
                    font.pixelSize: 120
                    text: " "
                }
                MouseArea{
                    id: bottomMouseArea
                    anchors.fill: parent
                    onClicked: {
                        if (bottomTextCell.text === " "){
                            bottomTextCell.text = "X"
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

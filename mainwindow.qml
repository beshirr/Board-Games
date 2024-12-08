import QtQuick
import QtQuick.Controls

Item {
    Rectangle {
        id: mainrec
        anchors.fill: parent
        color: "#0D1B2A"

        FontLoader {
            id: primaryFont
            source: "qrc:/fonts/Jaro_60pt-Regular.ttf"
        }
        FontLoader {
            id: secondaryFont
            source: "qrc:/fonts/Kanit-Regular.ttf"
        }

        Text {
            id: titleText
            text: "Welcome To Board Games"
            color: "#E0E1DD"
            font.pixelSize: 32
            font.family: primaryFont.name || "DefaultFont"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 40
        }

        Text {
            text: "Select A Game To Start"
            color: "#778DA9"
            font.pixelSize: 18
            font.family: secondaryFont.name || "DefaultFont"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: titleText.bottom
        }

        // property var buttonLabels: ["Pyramid Tic-Tac-Toe", "Four in a row", "5x5 Tic-Tac-Toe", "Word Tic-Tac-Toe",
        //                             "Numerical Tic-Tac-Toe", "Misere Tic-Tac-Toe", "4x4 Tic-Tac-Toe", "Ultimate Tic-Tac-Toe"]

        Button {
            id: tictactoe5x5Button
            width: 150
            height: 150
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 120
            anchors.leftMargin: 60

            background: Rectangle {
                id: tictactoe5x5buttonBack
                color: "#1B998BFF"
                radius: 10

                Image {
                    id: t5x5logo
                    source: "qrc:/icons/5x5.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

            Text {
                text: "5x5 Tic Tac Toe"
                anchors.top: tictactoe5x5buttonBack.bottom
                anchors.topMargin: 10
                anchors.horizontalCenter: tictactoe5x5buttonBack.horizontalCenter
                font.pixelSize: 18
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                color: "#E0E1DD"

                Text {
                    text: "This Tic-Tac-Toe variation\n is played on a 5x5 grid"
                    anchors.top: parent.bottom
                    anchors.topMargin: 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 11
                    font.family: secondaryFont.name || "DefaultFont"
                    color: "#555"
                }
            }
            onClicked: gamecontentLoader.source = "TicTacToe5x5.qml";
        }

        Button {
            id: tictactoeButton
            width: 150
            height: 150
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 120
            anchors.leftMargin: 240

            background: Rectangle {
                id: tictactoebuttonBack
                color: "#1B998BFF"
                radius: 10

                Image {
                    id: tlogo
                    source: "qrc:/icons/5x5.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

            Text {
                text: "Misere Tic Tac Toe"
                anchors.top: tictactoebuttonBack.bottom
                anchors.topMargin: 10
                anchors.horizontalCenter: tictactoebuttonBack.horizontalCenter
                font.pixelSize: 18
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                color: "#E0E1DD"

                Text {
                    text: "Unique twist on the\n" +
                        " classic game"
                    anchors.top: parent.bottom
                    anchors.topMargin: 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 11
                    font.family: secondaryFont.name || "DefaultFont"
                    color: "#555"
                }
            }
            onClicked: gamecontentLoader.source = "TicTacToe5x5.qml";
        }
    }
}


import QtQuick
import QtQuick.Controls

Item {
    // Main App rectangle
    Rectangle {
        id: mainrec
        anchors.fill: parent
        color: "#0D1B2A"

        FontLoader {
            id: primaryFont
            source: "file:///C:/Users/youss/Downloads/Jaro,Rubik/Jaro/static/Jaro_60pt-Regular.ttf"
        }
        FontLoader {
            id: secondaryFont
            source: "file:///C:/Users/youss/Downloads/Kanit/Kanit-Regular.ttf"
        }

        Text {
            id: titleText
            text: "Welcome To Board Games"
            color: "#E0E1DD"
            font.pixelSize: 32
            font.family: primaryFont.name
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        Text {
            text: "Select A Game To Start"
            color: "#778DA9"
            font.pixelSize: 18
            font.family: secondaryFont.name
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: titleText.bottom
        }

        property var buttonLabels: ["Pyramid Tic-Tac-Toe", "Four in a row", "5x5 Tic-Tac-Toe", "Word Tic-Tac-Toe",
                                    "Numerical Tic-Tac-Toe", "Misere Tic-Tac-Toe", "4x4 Tic-Tac-Toe", "Ultimate Tic-Tac-Toe"]

        Button {
            id: tictactoeButton
            width: 200
            height: 40
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: titleText.bottom
            anchors.margins: 60

            background: Rectangle {
                color: "#1B998BFF"
                radius: 10
            }

            contentItem: Text {
                text: "Pyramid Tic-Tac-Toe"
                font.family: secondaryFont.name
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#E0E1DD"
                font.pixelSize: 16
            }

            onClicked: gamecontentLoader.source = "TicTacToe.qml";
        }
    }
}


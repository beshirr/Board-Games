import QtQuick
import QtQuick.Controls

Item {
    Rectangle {
        id: mainrec
        anchors.fill: parent
        color: "#eaeaea"

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
            color: "#272424"
            font.pixelSize: 32
            font.family: primaryFont.name || "DefaultFont"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 40
        }

        Text {
            text: "Select A Game To Start"
            color: "#c8272424"
            font.pixelSize: 18
            font.family: secondaryFont.name || "DefaultFont"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: titleText.bottom
        }

        Button {
            id: t5x5button
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 90
            anchors.leftMargin: 80
            display: AbstractButton.IconOnly
            highlighted: true

            background: Rectangle {
                id: t5x5buttonBackground
                color: "#1B998BFF"
                radius: 20
                Image {
                    id: t5x5logo
                    source: "qrc:/icons/5x5.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

            Text {
                x: 50
                y: 257
                text: "5x5 Tic-Tac-Toe"
                anchors.top: t5x5buttonBackground.bottom
                anchors.topMargin: 6
                anchors.horizontalCenter: t5x5buttonBackground.horizontalCenter
                font.pixelSize: 24
                anchors.horizontalCenterOffset: 0
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                color: "#272424"

                Text {
                    text: "This Tic-Tac-Toe variation is played on\na 5x5 grid"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenterOffset: 1
                    font.family: secondaryFont.name || "DefaultFont"
                    color: "#555"
                }
            }
                onClicked: gamecontentLoader.source = "TicTacToe5x5.qml";
        }

        Button {
            id: misereButton
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 90
            anchors.leftMargin: 380
            display: AbstractButton.IconOnly
            highlighted: true

            Text {
                x: 50
                y: 257
                color: "#272424"
                text: "Misere Tic-Tac-Toe"
                anchors.top: misereButtonBackground.bottom
                anchors.topMargin: 6
                font.pixelSize: 24
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                Text {
                    color: "#555555"
                    text: "Unique twist on the classic Game"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    font.family: secondaryFont.name || "DefaultFont"
                    anchors.horizontalCenterOffset: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: misereButtonBackground.horizontalCenter
            }
            background: Rectangle {
                id: misereButtonBackground
                color: "#1b998bff"
                radius: 20
                Image {
                    // id: t5x5logo
                    source: "qrc:/icons/5x5.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
            onClicked: gamecontentLoader.source = "Misere.qml";
        }

        Button {
            id: pyramidButton
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 90
            anchors.leftMargin: 680
            display: AbstractButton.IconOnly
            highlighted: true

            Text {
                x: 50
                y: 257
                color: "#272424"
                text: "Pyramid Tic-Tac-Toe"
                anchors.top: tictactoe5x5buttonBack4.bottom
                anchors.topMargin: 6
                font.pixelSize: 24
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                Text {
                    color: "#555555"
                    text: "The game board is shaped like a pyramid"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    font.family: secondaryFont.name || "DefaultFont"
                    anchors.horizontalCenterOffset: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: tictactoe5x5buttonBack4.horizontalCenter
            }
            background: Rectangle {
                id: tictactoe5x5buttonBack4
                color: "#1b998bff"
                radius: 20

                // Icon
            }
            onClicked: gamecontentLoader.source = "PyramidTicTacToe.qml";
        }

        Button {
            id: forinrow
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 90
            anchors.leftMargin: 980
            display: AbstractButton.IconOnly
            highlighted: true

            Text {
                x: 50
                y: 257
                color: "#272424"
                text: "Four-in-a-row"
                anchors.top: tictactoe5x5buttonBack6.bottom
                anchors.topMargin: 6
                font.pixelSize: 24
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                Text {
                    color: "#555555"
                    text: "You will recognize four-in-a row as\na two-dimensional version of Connect Four"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    font.family: secondaryFont.name || "DefaultFont"
                    anchors.horizontalCenterOffset: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: tictactoe5x5buttonBack6.horizontalCenter
            }
            background: Rectangle {
                id: tictactoe5x5buttonBack6
                color: "#1b998bff"
                radius: 20
            }
        }

        Button {
            id: wordButton
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 400
            anchors.leftMargin: 80
            display: AbstractButton.IconOnly
            highlighted: true

            Text {
                x: 39
                y: 256
                color: "#272424"
                text: "Word Tic-Tac-Toe"
                anchors.top: tictactoe5x5buttonBack1.bottom
                anchors.topMargin: 6
                font.pixelSize: 24
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                Text {
                    color: "#555555"
                    text: "Innovative twist on the classic\nTic-Tac-Toe game"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    font.family: secondaryFont.name || "DefaultFont"
                    anchors.horizontalCenterOffset: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: tictactoe5x5buttonBack1.horizontalCenter
            }
            background: Rectangle {
                id: tictactoe5x5buttonBack1
                color: "#1b998bff"
                radius: 20
            }
            onClicked: gamecontentLoader.source = "WordTicTacToe.qml";
        }

        Button {
            id: numButton
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 400
            anchors.leftMargin: 380
            display: AbstractButton.IconOnly
            highlighted: true

            Text {
                x: 12
                y: 256
                color: "#272424"
                text: "Numerical Tic-Tac-Toe"
                anchors.top: tictactoe5x5buttonBack3.bottom
                anchors.topMargin: 6
                font.pixelSize: 24
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                Text {
                    color: "#555555"
                    text: "Offers a mathematical twist to\n the classic Tic-Tac-Toe game"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    font.family: secondaryFont.name || "DefaultFont"
                    anchors.horizontalCenterOffset: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: tictactoe5x5buttonBack3.horizontalCenter
            }
            background: Rectangle {
                id: tictactoe5x5buttonBack3
                color: "#1b998bff"
                radius: 20
            }
        }

        Button {
            id: t4x4Button
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 400
            anchors.leftMargin: 680
            display: AbstractButton.IconOnly
            highlighted: true

            Text {
                x: 50
                y: 257
                color: "#272424"
                text: "4x4 Tic-Tac-Toe"
                anchors.top: tictactoe5x5buttonBack5.bottom
                anchors.topMargin: 6
                font.pixelSize: 24
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                Text {
                    color: "#555555"
                    text: "Extended version of the classic game\nplayed on a larger board"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    font.family: secondaryFont.name || "DefaultFont"
                    anchors.horizontalCenterOffset: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: tictactoe5x5buttonBack5.horizontalCenter
            }
            background: Rectangle {
                id: tictactoe5x5buttonBack5
                color: "#1b998bff"
                radius: 20
            }
        }

        Button {
            id: ultimateButton
            width: 220
            height: 210
            anchors.top: titleText.bottom
            anchors.left: parent.left
            anchors.topMargin: 400
            anchors.leftMargin: 980
            display: AbstractButton.IconOnly
            highlighted: true

            Text {
                x: 24
                y: 256
                color: "#272424"
                text: "Ultimate Tic Tac Toe"
                anchors.top: tictactoe5x5buttonBack7.bottom
                anchors.topMargin: 6
                font.pixelSize: 24
                font.family: secondaryFont.name || "DefaultFont"
                font.bold: true
                Text {
                    color: "#555555"
                    text: "Expansion of the classic game, where players \nengage in a meta game\nof Tic Tac Toe"
                    anchors.top: parent.bottom
                    anchors.topMargin: 6
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    font.family: secondaryFont.name || "DefaultFont"
                    anchors.horizontalCenterOffset: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: tictactoe5x5buttonBack7.horizontalCenter
            }
            background: Rectangle {
                id: tictactoe5x5buttonBack7
                color: "#1b998bff"
                radius: 20
            }
        }
    }
}


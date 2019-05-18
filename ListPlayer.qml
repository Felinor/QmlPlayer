import QtQuick 2.0
import QtQuick.Controls 2.5
import QtMultimedia 5.12
import "formatSize.js" as MyScript

Item {

    property int counter: mediaPlayer.count
    property int curIndex: 0

    Connections {
        target: mediaPlayer
        onCountChanged: console.log(counter)
    }

    property string str:  Qt.formatTime(new Date(0, 0, 0, 0, 0, counter, 0), "mm:ss")

    anchors.fill: parent

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("str")
    }

    ListView {
        id: view
        spacing: 10
        anchors.fill: parent


        highlight: Rectangle {
            color: "gray"

        }
        highlightFollowsCurrentItem: true

        model: mediaPlayer

        header: Rectangle {
            width: parent.width
            height: 30
            border {
                color: "black"
                width: 1
            }

            Text {
                id: text
                anchors.centerIn: parent
                //renderType: Text.NativeRendering
                text: str
            }
        }

        delegate: Rectangle {
           /* Text {
                text: Qt.formatTime(new Date(0, 0, 0, 0, 0, count, 0), "m:ss")
            }*/
            // property var view: ListView.view
            // property var isCurrent: ListView.isCurrentItem

            width: view.width
            height: 40
            color: "skyblue"
            border.width: 1
            border.color: area.pressed ? "yellow" : "black"
            radius: height / 2

            Label {
                id: trackName
                text: name
                anchors.centerIn: parent
            }
            Label {
                anchors {
                    left: sizetrack.right
                    leftMargin: 30
                    verticalCenter: sizetrack.verticalCenter
                }
            }

            Label {
                id: sizetrack
                text: MyScript.formatBytes(size, 1)
                anchors {
                    left: trackName.right
                    leftMargin: 30
                    verticalCenter: trackName.verticalCenter
                }
            }
            Label {
                text: dataModified
                anchors {
                    right: trackName.left
                    rightMargin: 30
                    verticalCenter: trackName.verticalCenter
                }
            }
            MouseArea {
                id: area
                anchors.fill: parent
                onClicked: {
                    pathToTrack = path
                    view.currentIndex = model.index
                    curIndex = model.index
                }

            }
        }
    }
}


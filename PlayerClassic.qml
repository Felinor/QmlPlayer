import QtQuick 2.0
import QtQuick.Window 2.2
import module 1.0
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 700
    height: 700
    title: qsTr("Simple audio player")

    property string pathToTrack
    Item {
        anchors.fill: parent


            ListPlayer {
                id: listPlayer
                width: parent.width
                height: 500
            }

            Buttons {
                anchors.horizontalCenter: listPlayer.horizontalCenter
                anchors.bottom: listPlayer.bottom
                indexFile: listPlayer.curIndex
            }
        }

}


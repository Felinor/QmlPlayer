import QtQuick 2.0
import QtQuick.Controls 1.0
import QtMultimedia 5.12

    Item {
        anchors.fill: parent


    TableView {
        id: view
        model: mediaPlayer
        anchors.margins: 10
        anchors.fill: parent
        clip: true

        TableViewColumn {
            width: 100
            title: "Name"
            role: "name"
        }
        TableViewColumn {
            width: 100
            title: "Size"
            role: "size"
        }

        itemDelegate: Item {

            //property var view: ListView.view
            //property var isCurrent: ListView.isCurrentItem

            //width: view.width
            //height: 40


           /* Label {
                id: trackName
                text: name
                anchors.centerIn: parent
            }
            Label {
                anchors.right: parent.right
                text: count
            }

            Label {
                text: size
                anchors.left: trackName.right
                anchors.leftMargin: 10

            }*/

            MouseArea {
                id: area
                anchors.fill: parent
                onClicked: {
                    pathToTrack = path
                    view.currentIndex = model.index
                }
            }
        }
            Text {
                anchors.centerIn: parent
                renderType: Text.NativeRendering
                text: styleData.value
            }
        }
    }


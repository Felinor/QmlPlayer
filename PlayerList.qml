//import QtQuick 2.0
//import QtQuick.Controls 2.5
//import QtMultimedia 5.12
//import "formatSize.js" as MyScript

//Item {
//    property int count: 0
//    Timer {
//        interval: 1000
//        running: true
//        repeat: true
//        onTriggered: {
//            count++
//        }
//    }

//    anchors.fill: parent

//    ListView {
//        id: view
//        spacing: 10
//        anchors.fill: parent


//        highlight: Rectangle {
//            color: "gray"

//        }
//        highlightFollowsCurrentItem: true

//        model: mediaPlayer

//        header: Rectangle {
//            width: parent.width
//            height: 30
//            border {
//                color: "black"
//                width: 1
//            }

//            Text {
//                id: text
//                anchors.centerIn: parent
//                //renderType: Text.NativeRendering
//                text: "Audio track"
//            }
//        }

//        delegate: Rectangle {

//           // property var view: ListView.view
//           // property var isCurrent: ListView.isCurrentItem

//            width: view.width
//            height: 40
//            color: "skyblue"
//            border.width: 1
//            border.color: area.pressed ? "yellow" : "black"
//            radius: height / 2

//            Label {
//                id: trackName
//                text: name
//                anchors.centerIn: parent
//            }
//            Label {
//                anchors {
//                    left: sizetrack.right
//                    leftMargin: 30
//                    verticalCenter: sizetrack.verticalCenter
//                }

//                text: Qt.formatTime(new Date(1, 0, 2010, 0, 0, count, 0), "mm:ss")
//            }

//            Label {
//                id: sizetrack
//                text: MyScript.formatBytes(size, 1)
//                anchors {
//                    left: trackName.right
//                    leftMargin: 30
//                    verticalCenter: trackName.verticalCenter
//                }
//            }
//            Label {
//                text: dataModified
//                anchors {
//                    right: trackName.left
//                    rightMargin: 30
//                    verticalCenter: trackName.verticalCenter
//                }
//            }
//            MouseArea {
//                id: area
//                anchors.fill: parent
//                onClicked: {
//                    pathToTrack = path
//                    view.currentIndex = model.index
//                }

//            }
//        }
//    }
//}


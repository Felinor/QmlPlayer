import QtQuick 2.0
import module 1.0



Row {
    property int indexFile

    FileWork {
        id: audio
    }

    Image {
        id: back

        source: "qrc:/Images/media-skip-backward.png"

    }

    Image {
        id: play
        source: "qrc:/Images/media-playback-start.png"
        state: "Play"

        states: [
            State {
                name: "Play"
                PropertyChanges {
                    target: play
                    source: "qrc:/Images/media-playback-start.png"
                }

            },
            State {
                name: "Pause"
                PropertyChanges {
                    target: play
                    source: "qrc:/Images/media-playback-pause.png"

                }
            }
        ]

        MouseArea {
            anchors.fill: parent
            onClicked: {
                audio.listen(pathToTrack)
                parent.state = (parent.state == "Play")  ? "Pause" : "Play"
                if (parent.state == "Pause") {

                }
                else { audio.pause()}

            }
        }
    }


    Image {
        id: stop
        source: "qrc:/Images/media-playback-stop.png"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                audio.stop()
                play.state = "Play"
               // mediaPlayer.deleter(indexFile)
            }
        }

    }

    Image {
        id: next
        source: "qrc:/Images/media-skip-forward.png"
        MouseArea {
            anchors.fill: parent
            onClicked: audio.next()


        }
    }


}

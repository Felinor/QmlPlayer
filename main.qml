import QtQuick 2.0
import QtQuick.Window 2.2
import module 1.0
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 600
    height: 480
    title: qsTr("Simple audio player")
    color: "skyblue"

    FileWork {
        id: audio
    }





    Slider {
        id: slider
        x: 123
        y: -5
        value: 0.5
    }

}


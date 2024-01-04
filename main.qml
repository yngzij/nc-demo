import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    DropArea {
        id: dropArea
        anchors.fill: parent
        onEntered: {
            console.log("entered")
        }
        onExited: {
            console.log("exited")
        }
        onDropped: {
        if(drop.hasUrls){
           backend.cppFunction(drop.urls)
        }
    }
    }
}

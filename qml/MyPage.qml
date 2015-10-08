import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2



Rectangle {
    id: page

    clip: true
    property string title: "Title"

    Rectangle {
        id: curtain
        color: "black"
        opacity: app._progressOpening*0.5
        anchors.fill: parent
        z: 100
    }
}



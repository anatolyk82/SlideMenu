import QtQuick 2.5

//based on https://gist.github.com/cyberbobs/8d62ab257d332914a72c

Item {
    id: root
    width: 24
    height: 24

    property real value: 0 //from 0 to 1

    rotation: root.state == "menu" ? value*180 : -value*180

    Rectangle {
        id: barUp
        x: 2 + 7.5*value
        y: 5 + 3*value
        width: 20 - 7*value
        height: 2
        rotation: 45*value
        antialiasing: true
    }

    Rectangle {
        id: barMiddle
        x: 2 + value
        y: 10 + 2*value
        width: 20 - 3*value
        height: 2
        antialiasing: true
    }

    Rectangle {
        id: barDown
        x: 2 + 7.5*value
        y: 15 + value
        width: 20 - 7*value
        height: 2
        rotation: -45*value
        antialiasing: true
    }

    state: "menu"
    states: [
        State { name: "menu" },
        State { name: "back" }
    ]

    onValueChanged: {
        if(value == 1) root.state = "back"
        else if(value == 0) root.state = "menu"
    }

}

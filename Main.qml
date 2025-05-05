import QtQuick
import QtQuick.VirtualKeyboard
import QtQuick.Controls
import QtQuick.Layouts

// import mymodel 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    ListModel{
        id:testmodel
        ListElement{ value:"suyambu" }
        ListElement{ value:"karthick" }
        ListElement{ value:"saritha" }
        ListElement{ value:"saritha 1" }
        ListElement{ value:"saritha 2" }


    }

    // Rectangle{
        // ColumnLayout{
            // spacing: 10
            // TextInput{
            //     id:searchinput
            //     text: "sdfasdf"
            // }
            ListView{
                 anchors.fill: parent
                model:myitemmodel
                delegate:Text {
                        text: modelvalue
                        font.pixelSize: 20
                        padding: 10
                    Component.onCompleted: {
                         console.log("my name is", modelvalue)
                    }
                    }
                Component.onCompleted: {
                    console.log("my name is"/*,myitemmodel.myname()*/,myitemmodel,myitemmodel.rowCount());
                }



            }

        // }
    // }

    // InputPanel {
    //     id: inputPanel
    //     z: 99
    //     x: 0
    //     y: window.height
    //     width: window.width

    //     states: State {
    //         value: "visible"
    //         when: inputPanel.active
    //         PropertyChanges {
    //             target: inputPanel
    //             y: window.height - inputPanel.height
    //         }
    //     }
    //     transitions: Transition {
    //         from: ""
    //         to: "visible"
    //         reversible: true
    //         ParallelAnimation {
    //             NumberAnimation {
    //                 properties: "y"
    //                 duration: 250
    //                 easing.type: Easing.InOutQuad
    //             }
    //         }
    //     }
    // }

}

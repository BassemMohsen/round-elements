import QtQuick 2.4
import QtQuick.Window 2.2
import QmlCircularBar 1.0
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 600
    height: 600
    color: "white"

    //Test slider .. just to test the circular bar.
    Slider {
        id: testSlider
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        value: 50
        minimumValue: 0
        maximumValue: 100
        stepSize: 1.0
        orientation: Qt.Horizontal
        width: 400
    }

    //Bar background image.
    Image{
        id: barBgImg
        source: "bar_bg.png"
        anchors.centerIn: circularBar
        width: 400
        height: 400
        Text
        {
            id: valueText
            anchors.centerIn: parent
            text: testSlider.value + " %"
            font.pixelSize: 50
        }
    }

    //Bar active Image to cover Background bar image.
    CircularBar{
        id : circularBar
        width : 400
        height : 400
        anchors.centerIn: parent
        z: 1
        progress: testSlider.value
    }
}

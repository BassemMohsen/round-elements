import QtQuick 2.1
import QtGraphicalEffects 1.0

Rectangle {
    width: 620
    height: 400
    color: "white"

    //source Image, might be from web service or QQuickImageProvider Class.
    Image {
        id: profileImg
        source: "profilePic.jpg"
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        width: 300
        height: 300
        smooth: true
        visible: true
    }

    //mask Image, you should prepare this image to exact resolution
    //to prevent pixelization.
    Image {
        id: maskImg
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        source: "mask.png"
        width: 300
        height: 300
        smooth: true
        visible: true
    }

    //Final result image of round profile picture.
    OpacityMask {
        id: roundProfileImg
        anchors.fill: maskImg
        source: profileImg
        maskSource: maskImg
    }
}

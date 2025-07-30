import QtQuick
import QtQuick.Controls
import com.franco.custom

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Time and DateTime")

    property string value: "Click %1 times, double is %2"
    property int clickCount: 0

    CppClass {
        id: cppClassId
        onSendDateTime: (dateTime) => {
            console.log("Received datetime: " + dateTime)
            // Extract info
            console.log("Year: " + dateTime.getFullYear())
            console.log("..." + dateTime.toGMTString())
        }

        onSendTime: (time) => {
            console.log("Received time: " + time)
        }
    }

    Button {
        id: buttonId
        text: "Click me"
        onClicked: function() {
            // Receive data from C++
            cppClassId.cppSlot()

            // Sending date to C++
            var date = new Date()
            cppClassId.timeSlot(date)
            cppClassId.dateTimeSlot(date)

            // String formatting
            clickCount++
            buttonId.text = value.arg(clickCount).arg(clickCount * 2)
        }
    }
}

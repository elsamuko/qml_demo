import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    Button {
        text: "Third with QML"
        objectName: "thirdButton"
    }
    Button {
        text: "Fourth with QML"
        objectName: "fourthButton"
    }
    Dial {
        objectName: "dial"
    }
}

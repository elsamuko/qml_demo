import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    Button {
        text: "First with QML"
        objectName: "firstButton"
    }
    Button {
        text: "Second with QML"
        objectName: "secondButton"
    }
    Tumbler {
        model: 5
        objectName: "tumbler"
    }
}

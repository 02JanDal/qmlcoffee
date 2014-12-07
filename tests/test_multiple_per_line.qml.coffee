import QtQuick 2.0

Rectangle {
	Behaviour on opacity { SmoothedAnimation { duration: if y isnt 20 then 250 else 300; easing.type: Easing.InOutElastic }
}

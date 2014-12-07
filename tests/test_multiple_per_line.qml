import QtQuick 2.0

Rectangle {
	Behaviour on opacity { SmoothedAnimation { duration: y !== 20 ? 250 : 300; easing.type: Easing.InOutElastic;}
}

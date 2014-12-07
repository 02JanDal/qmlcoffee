import QtQuick 2.0

Rectangle {
	width: if 45 < x < 90 then 20 else 40
	height: 62

	Behaviour on opacity { SmoothedAnimation { duration: if y isnt 20 then 250 else 300; easing.type: Easing.InOutElastic }

	onClicked ->
		a = 2
		console.debug a + a
}

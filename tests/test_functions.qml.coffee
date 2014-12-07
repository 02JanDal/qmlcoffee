import QtQuick 2.0

Rectangle {
	onClicked ->
		a = 2
		console.debug a + a
	onWidthChanged (width) ->
		$height = $width * 2
}

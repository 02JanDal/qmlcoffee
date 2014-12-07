import QtQuick 2.0

Rectangle {
	onClicked: {
	  var a;
	  a = 2;
	  return console.debug(a + a);
	}
	onWidthChanged: {
	  return height = width * 2;
	}
}

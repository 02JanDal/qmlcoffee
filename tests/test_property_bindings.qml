import QtQuick 2.0

Rectangle {
	width: (45 < x && x < 90) ? 20 : 40;
	height: 62;
	text: "the ratio is " + (width / height) + ", right?";
}

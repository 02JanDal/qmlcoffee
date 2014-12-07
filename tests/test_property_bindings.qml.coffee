import QtQuick 2.0

Rectangle {
	width: if 45 < x < 90 then 20 else 40
	height: 62
	text: "the ratio is #{width / height}, right?"
}

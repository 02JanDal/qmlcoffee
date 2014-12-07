#include <QTest>
#include <QStandardPaths>

#include "../main.h"

class Tester : public QObject
{
	Q_OBJECT
	void doCompare(const QString &baseName)
	{
		processQML(fileFor(QFINDTESTDATA(baseName + ".qml.coffee"), QFile::ReadOnly),
				   fileFor(baseName + ".qml.out", QFile::WriteOnly));
		QCOMPARE(QString::fromUtf8(fileFor(baseName + ".qml.out", QFile::ReadOnly)->readAll()),
				 QString::fromUtf8(fileFor(QFINDTESTDATA(baseName + ".qml"), QFile::ReadOnly)->readAll()));
	}

private slots:
	void initTestCase()
	{
		executable = QStandardPaths::findExecutable("coffee");
	}

	void testPropertyBindings()
	{
		doCompare("test_property_bindings");
	}
	void testMultiplePerLine()
	{
		doCompare("test_multiple_per_line");
	}
	void testFunctions()
	{
		doCompare("test_functions");
	}
};

QTEST_GUILESS_MAIN(Tester)

#include "test.moc"

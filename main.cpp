#include <QCoreApplication>
#include <QCommandLineParser>
#include <QStandardPaths>
#include <QDebug>

#include "main.h"

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);
	app.setApplicationName("qmlcoffee");
	app.setApplicationVersion("1.0");
	app.setOrganizationName("Jan Dalheimer");

	QCommandLineParser parser;
	{
		parser.addHelpOption();
		parser.addVersionOption();
		parser.setApplicationDescription("QML/JS + CoffeeScript -> QML/JS transformer");
		parser.addOption(QCommandLineOption(QStringList() << "input" << "i", "Specifies the input (CoffeeScript) file. Use - for stdin.", "FILE", "-"));
		parser.addOption(QCommandLineOption(QStringList() << "output" << "o", "Specifies the output (QML/JS) file. Use - for stdout.", "FILE", "-"));
		parser.addOption(QCommandLineOption(QStringList() << "literate", "Use if the input file is literate CoffeeScript"));
		parser.addOption(QCommandLineOption(QStringList() << "type" << "t", "Specifies what type of file the input is. Possible values: detect, qml, js", "TYPE", "detect"));
		parser.addOption(QCommandLineOption(QStringList() << "coffeescript" << "c", "Specifies the coffeescript executable to use", "EXECUTABLE", QStandardPaths::findExecutable("coffee")));
	}
	parser.process(app);

	QFile *in = fileFor(parser.value("input"), QIODevice::ReadOnly);
	QFile *out = fileFor(parser.value("output"), QIODevice::WriteOnly);

	executable = parser.value("coffeescript");

	QString type = parser.value("type");
	if (type == "detect")
	{
		if (parser.value("input") == "-")
		{
			qFatal("When reading from stdin you need to explicitly specify the type of file using --type");
		}
		else if (parser.value("input").contains(".qml"))
		{
			type = "qml";
		}
		else
		{
			type = "js";
		}
	}

	if (type == "js")
	{
		out->write(process(in->readAll(), true));
	}
	else if (type == "qml")
	{
		processQML(in, out);
	}
}

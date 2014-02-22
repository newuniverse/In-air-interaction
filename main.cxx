#include <QtGui/QApplication>
#include <QMainWindow>
#include <QToolBox>
#include <QScrollArea>
#include <QSpinBox>
#include <QLabel>

//#include "ui_mainWindow.h"
#include "mainWindowController.h"
#include "LeapListener.h"

int main(int argc, char** argv) 
{
	QApplication app(argc, argv);

	MainWindowController *mainWindow = new MainWindowController();
	mainWindow->show();

	return app.exec();
}
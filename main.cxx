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

	LeapListener *listener = new LeapListener;
	Leap::Controller *controller = new Leap::Controller;
	controller->addListener(*listener); 

	MainWindowController *mainWindow = new MainWindowController(*listener);
	mainWindow->show();

	return app.exec();
}
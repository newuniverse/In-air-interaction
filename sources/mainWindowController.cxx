#include <QtGui>
#include "mainWindowController.h"

MainWindowController::MainWindowController(QWidget *parent)
{
	setupUi(this);
}

/*
	Creating new windows is triggered when createWindowbutton is clicked
	Automatically connected when create function like below on_ObjectName_EventName()
*/
void MainWindowController::on_createWindowButton_clicked()
{
	int winNum = windowNumSpinBox->value();
	int width, height;
	
	for (int i = 0; i < winNum; ++i)
	{
		width = 800;
		height = 600;
		QLineEdit* le = this->findChild<QLineEdit*>(QString("width").append(QString::number(i+1)));
		if (!(le->text().isEmpty())) {
			width = le->text().toInt();
		}

		le = this->findChild<QLineEdit*>(QString("height").append(QString::number(i+1)));
		if (!(le->text().isEmpty())) {
			height = le->text().toInt();
		}
		createWindow(width, height, i);
	}
}
/*
	Create new window 
*/
void MainWindowController::createWindow(int width, int height, int index = 0)
{
	QWidget* newWindow = new QWidget;
	QRect rect(1200*(index+1), 0, width, height);
	newWindow->setGeometry(rect);
	newWindow->showFullScreen();
}
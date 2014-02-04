#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include "../ui_mainWindow.h"

class MainWindowController : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindowController(QWidget *parent = 0);

private:
	void createWindow(int width, int height, int index);

private slots:
	void on_createWindowButton_clicked();

};

#endif
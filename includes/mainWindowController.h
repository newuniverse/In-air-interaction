#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

//Qt ui header automatically generated in root directory
#include "../ui_mainWindow.h"

//all vtk headers are included in here
#include "vtkInclude.h" 

//vtk headers about rendering process
#include "vtkIncludeViewer.h"

//Leap listener class wrapper
#include "LeapListener.h"

#include "graphicalViewer.h"


class MainWindowController : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindowController(QWidget *parent = 0);
	~MainWindowController();

private slots:
	void on_createWindowButton_clicked();
	void on_leapActivateButton_clicked();
	void on_actionOpen_File_triggered();

private:
	void createWindow(int width, int height, int index);

private:
	LeapListener     *g_lmListener;
	Leap::Controller *g_lmController;

	vtkSmartPointer<vtkActor> _actor;
	
	vtkSmartPointer<vtkRenderer> ren1;
	vtkSmartPointer<vtkRenderWindow> renWin;

	GraphicalViewer* viewer;

	vtkSmartPointer<vtkTimerCallback> g_vtkCallback;

	std::chrono::high_resolution_clock::time_point currentTime;
    std::chrono::high_resolution_clock::time_point lastTime;
};

#endif
#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include "../ui_mainWindow.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"

#include <vtkSmartPointer.h>

class MainWindowController : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindowController(QWidget *parent = 0);
	~MainWindowController();
private:
	void createWindow(int width, int height, int index);

private slots:
	void on_createWindowButton_clicked();

private:
	vtkSmartPointer<vtkConeSource> cone;
	vtkSmartPointer<vtkPolyDataMapper> coneMapper;
	vtkSmartPointer<vtkActor> coneActor;
	vtkSmartPointer<vtkRenderer> ren1;
	vtkSmartPointer<vtkRenderWindow> renWin;
};

#endif
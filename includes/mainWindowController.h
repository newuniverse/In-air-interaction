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

////////////////
#include "OVR.h"
#include <Kernel/OVR_SysFile.h>
#include <Kernel/OVR_Log.h>
#include <Kernel/OVR_Timer.h>
////////////////

#include "tinyxml2.h"
using namespace OVR;
class MainWindowController : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
public://methods
	MainWindowController(QWidget *parent = 0);
	~MainWindowController();

private slots:
	void on_createWindowButton_clicked();
	void on_leapActivateButton_clicked();
	void on_actionOpen_File_triggered();
	void on_actionNew_triggered();
	void on_actionOpen_Config_triggered();
	void on_setKeystoneButton_clicked();
	void on_saveKeystoneButton_clicked();
	
	void on_windowIndexSpinBox_valueChanged() {
		x1SpinBox->setValue(1.0);
		y1SpinBox->setValue(1.0);
		x2SpinBox->setValue(-1.0);
		y2SpinBox->setValue(1.0);
		x3SpinBox->setValue(-1.0);
		y3SpinBox->setValue(-1.0);
		x4SpinBox->setValue(1.0);
		y4SpinBox->setValue(-1.0);
	}


	void on_x1SpinBox_valueChanged(double d) {
		X1 = d;
		keystoneSpinBoxCommon();
	}
	void on_y1SpinBox_valueChanged(double d) {
		Y1 = d;
		keystoneSpinBoxCommon();
	}
	void on_x2SpinBox_valueChanged(double d){
		X2 = d;
		keystoneSpinBoxCommon();
	}
	void on_y2SpinBox_valueChanged(double d){
		Y2 = d;
		keystoneSpinBoxCommon();
	}
	void on_x3SpinBox_valueChanged(double d) {
		X3 = d;
		keystoneSpinBoxCommon();
	}
	void on_y3SpinBox_valueChanged(double d) {
		Y3 = d;
		keystoneSpinBoxCommon();
	}
	void on_x4SpinBox_valueChanged(double d) {
		X4 = d;
		keystoneSpinBoxCommon();
	}
	void on_y4SpinBox_valueChanged(double d) {
		Y4 = d;
		keystoneSpinBoxCommon();
	}
	
	void keystoneSpinBoxCommon();

private://methods
	void createOne(int width, int height, int index);
	void addActorsToScene(vtkSmartPointer<vtkActor> actor);
	void removeAllActorsFromScene();

	void refreshAllWindows();
	void addAllLeapModels();
	void removeAllLeapModels();

	void setWindowConfigurations();

	void createWindowFromConfig();

	double* calcKeystones();
private://members
	double X1, X2, X3, X4, Y1, Y2, Y3, Y4;//keystones

	tinyxml2::XMLDocument*   conf_xml;
	LeapListener*     g_lmListener;
	Leap::Controller* g_lmController;
	
	vtkSmartPointer<vtkRenderer> mainRenderer;
	vtkSmartPointer<vtkRenderWindow> mainWindow;
	vtkSmartPointer<vtkTimerCallback> g_vtkCallback;

	std::vector<vtkSmartPointer<vtkRenderer> > subRenderers;
	std::vector<vtkSmartPointer<vtkRenderWindow> > subRenWindows;
	std::vector<vtkSmartPointer<vtkRenderWindowInteractor> > subInteractors;
	std::vector<vtkSmartPointer<vtkCamera> > subCameras;

	std::vector<vtkSmartPointer<vtkActor> > allActors;

	std::chrono::high_resolution_clock::time_point currentTime;
    std::chrono::high_resolution_clock::time_point lastTime;

protected: //methods and members
	Ptr<DeviceManager>  pManager;
	Ptr<HMDDevice>      pHMD;

	void initConfigFile();
};


#endif
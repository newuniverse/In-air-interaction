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
// #include "LeapController.h"

#include "graphicalViewer.h"

#include "robotModel.h"

#include "LeapControllerModel.h"

#include "ToolModel.h"
////////////////
#ifdef _APPLE_
#include "OVR.h"
#include <Kernel/OVR_SysFile.h>
#include <Kernel/OVR_Log.h>
#include <Kernel/OVR_Timer.h>
using namespace OVR;
#elif __linux
#endif
////////////////

#include "tinyxml2/tinyxml2.h"
#define TEST_DELTA 0.1
class MainWindowController : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
public://methods
	MainWindowController(QWidget *parent = 0);
	~MainWindowController();

private slots:
	void on_createWindowButton_clicked();
	void on_leapActivateButton_clicked();
	void on_robotActivateButton_clicked();

	void on_actionOpen_File_triggered();
	void on_actionNew_triggered();
	void on_actionOpen_Config_triggered();
	void on_setKeystoneButton_clicked();
	void on_saveKeystoneButton_clicked();
	void on_parallaxSlider_valueChanged(int value);

	void on_windowIndexSpinBox_valueChanged() {
		x1SpinBox->setValue(1.0);  y1SpinBox->setValue(1.0);
		x2SpinBox->setValue(-1.0); y2SpinBox->setValue(1.0);
		x3SpinBox->setValue(-1.0); y3SpinBox->setValue(-1.0);
		x4SpinBox->setValue(1.0);  y4SpinBox->setValue(-1.0);
	}

	void on_j1d_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j1a_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j1alpha_editingFinished () { dhParameterEditedCommonProcess(); }
	void on_j1theta_valueChanged() {     dhParameterEditedCommonProcess(); }

	void on_j2d_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j2a_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j2alpha_editingFinished () { dhParameterEditedCommonProcess(); }
	void on_j2theta_valueChanged() {     dhParameterEditedCommonProcess(); }

	void on_j3d_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j3a_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j3alpha_editingFinished () { dhParameterEditedCommonProcess(); }
	void on_j3theta_valueChanged() {     dhParameterEditedCommonProcess(); }

	void on_j4d_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j4a_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j4alpha_editingFinished () { dhParameterEditedCommonProcess(); }
	void on_j4theta_valueChanged() {     dhParameterEditedCommonProcess(); }

	void on_j5d_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j5a_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j5alpha_editingFinished () { dhParameterEditedCommonProcess(); }
	void on_j5theta_valueChanged() {     dhParameterEditedCommonProcess(); }

	void on_j6d_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j6a_editingFinished () {     dhParameterEditedCommonProcess(); }
	void on_j6alpha_editingFinished () { dhParameterEditedCommonProcess(); }
	void on_j6theta_valueChanged() {     dhParameterEditedCommonProcess(); }

	void on_x1SpinBox_valueChanged(double d) { X1 = d; keystoneSpinboxEditedCommonProcess();}
	void on_y1SpinBox_valueChanged(double d) { Y1 = d; keystoneSpinboxEditedCommonProcess();}
	void on_x2SpinBox_valueChanged(double d) { X2 = d; keystoneSpinboxEditedCommonProcess();}
	void on_y2SpinBox_valueChanged(double d) { Y2 = d; keystoneSpinboxEditedCommonProcess();}
	void on_x3SpinBox_valueChanged(double d) { X3 = d; keystoneSpinboxEditedCommonProcess();}
	void on_y3SpinBox_valueChanged(double d) { Y3 = d; keystoneSpinboxEditedCommonProcess();}
	void on_x4SpinBox_valueChanged(double d) { X4 = d; keystoneSpinboxEditedCommonProcess();}
	void on_y4SpinBox_valueChanged(double d) { Y4 = d; keystoneSpinboxEditedCommonProcess();}

	void on_xPlusButton_clicked() 
	{
		Eigen::Matrix< double , 6 , 1> goal(6);
		goal << TEST_DELTA, 0.0, 0.0, 0.0, 0.0, 0.0;
		_robotModel->calcInverseKinematics(goal);
		refreshAllWindows(false);
	}

	void on_xMinusButton_clicked() 
	{
		Eigen::Matrix< double , 6 , 1> goal(6);
		goal << -TEST_DELTA, 0.0, 0.0, 0.0, 0.0, 0.0;
		_robotModel->calcInverseKinematics(goal);
		refreshAllWindows(false);
	}

	void on_yPlusButton_clicked() 
	{
		Eigen::Matrix< double , 6 , 1> goal(6);
		goal << 0.0, TEST_DELTA, 0.0, 0.0, 0.0, 0.0;
		_robotModel->calcInverseKinematics(goal);
		refreshAllWindows(false);
	}

	void on_yMinusButton_clicked() 
	{
		Eigen::Matrix< double , 6 , 1> goal(6);
		goal << 0.0, -TEST_DELTA, 0.0, 0.0, 0.0, 0.0;
		_robotModel->calcInverseKinematics(goal);
		refreshAllWindows(false);
	}

	void on_zPlusButton_clicked() 
	{
		Eigen::Matrix< double , 6 , 1> goal(6);
		goal << 0.0, 0.0, TEST_DELTA, 0.0, 0.0, 0.0;
		_robotModel->calcInverseKinematics(goal);
		refreshAllWindows(false);
	}

	void on_zMinusButton_clicked() 
	{
		Eigen::Matrix< double , 6 , 1> goal(6);
		goal << 0.0, 0.0, -TEST_DELTA, 0.0, 0.0, 0.0;
		_robotModel->calcInverseKinematics(goal);
		refreshAllWindows(false);
	}
public: //members
	enum WINDOWNAME {
		MAIN, ENDOSCOPE, CONTROLLER, MAIN_AND_ENDOSCOPE,
	};
private://methods
	void updateThetas() {

	}
	void setupRendererAndWindow();
	void attachRendererToWindow(vtkSmartPointer<vtkRenderer> ren, vtkSmartPointer<vtkRenderWindow> win, QVTKWidget* widget);
	void setupCharts();
	
	void createSubWindow(int width, int height, int index);
	void setKeystoneTransform(double* ks_array, int index);
	void addActorToScenes(vtkSmartPointer<vtkActor> actor, WINDOWNAME name);
	void addActorToScenes(vtkSmartPointer<vtkAxesActor> actor, WINDOWNAME name);
	void removeActorFromScenes(vtkSmartPointer<vtkActor> actor, WINDOWNAME name);
	void removeActorFromScenes(vtkSmartPointer<vtkAxesActor> actor, WINDOWNAME name);
	void removeAllActorsFromScene();
	void refreshAllWindows(bool resetCamera);
	void addAllLeapModels();
	void removeAllLeapModels();
	void createWindowFromConfig();
	void read3DModel(QString filename);
	double* getDHparameters();
	void dhParameterEditedCommonProcess();
	void updateEndoscopeCamera();
	double* calcKeystones();
	void keystoneSpinboxEditedCommonProcess();
private://members
	static const int DELTATIME = 30; //ms
	double X1, X2, X3, X4, Y1, Y2, Y3, Y4;//keystones

	double* dh_parameter;

	tinyxml2::XMLDocument   _confXML;
	LeapListener*     _lmListener;
	Leap::Controller* _lmController;
	// manipulator
	RobotModel* _robotModel;
	// leap controller visual
	LeapControllerModel* _uiModel;
	// forcept
	ToolModel* _surgicalToolModel;



	//main window
	vtkSmartPointer<vtkRenderer> mainRenderer;
	vtkSmartPointer<vtkRenderWindow> mainWindow;
	vtkSmartPointer<vtkTimerCallback> g_vtkCallback;
	//sub windows for holo-table 
	std::vector<vtkSmartPointer<vtkRenderer> > subRenderers;
	std::vector<vtkSmartPointer<vtkRenderWindow> > subRenWindows;
	std::vector<vtkSmartPointer<vtkRenderWindowInteractor> > subInteractors;
	std::vector<vtkSmartPointer<vtkCamera> > subCameras;
	std::vector<vtkSmartPointer<vtkTransform> > keystoneTsf;

	vtkSmartPointer<vtkRenderer> endoscopeViewRenderer;
	vtkSmartPointer<vtkRenderWindow> endoscopeViewWindow;
	vtkSmartPointer<vtkCamera> endoscopeViewCamera;

	vtkSmartPointer<vtkRenderer> leapControllerViewRenderer;
	vtkSmartPointer<vtkRenderWindow> leapControllerViewWindow;
	vtkSmartPointer<vtkCamera> leapControllerViewCamera;

	vtkSmartPointer<vtkAxesActor> worldAxes;
	vtkSmartPointer<vtkOrientationMarkerWidget> axesWidget;

	std::vector<vtkSmartPointer<vtkActor> > allActors;
	std::chrono::high_resolution_clock::time_point currentTime;
    std::chrono::high_resolution_clock::time_point lastTime;

    //WINDOWNAME windowName;
protected: //methods and members
	
#ifdef _APPLE_
	Ptr<DeviceManager>  pManager;
	Ptr<HMDDevice>      pHMD;
#endif
	void initConfigFile();
};


#endif
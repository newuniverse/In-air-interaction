#include <QtGui>
#include "mainWindowController.h"

#include "graphicalModel.h"
#include "Shared.h"
#define DELTATIME 30 //ms


MainWindowController::MainWindowController(QWidget *parent)
{
	setupUi(this);

	currentTime = std::chrono::high_resolution_clock::now();
	lastTime    = currentTime;

  	ren1= vtkSmartPointer<vtkRenderer>::New();
  	ren1->SetBackground( 0.0, 0.0, 0.0 );

  	renWin = vtkSmartPointer<vtkRenderWindow>::New();
  	renWin->AddRenderer(ren1);
  	renWin->SetSize(300, 300);

  	qvtkWidget->SetRenderWindow(renWin);
  	
  	renWin->SetInteractor(qvtkWidget->GetInteractor());
  	g_vtkCallback = vtkSmartPointer<vtkTimerCallback>::New();
 	 	
  	//chart rendering example
  	vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
	vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();

	chart->SetRenderEmpty(true);
	chart->SetAutoAxes(false);
	view->GetScene()->AddItem(chart.GetPointer());
	view->SetInteractor(vtkChart1->GetInteractor());

	vtkChart1->SetRenderWindow(view->GetRenderWindow());
	vtkChart2->SetRenderWindow(view->GetRenderWindow());

	g_lmListener   = new LeapListener;
	g_lmController = new Leap::Controller;
	g_lmController->addListener(*g_lmListener); 
}

MainWindowController::~MainWindowController() {
	
}


void MainWindowController::on_actionOpen_File_triggered() 
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open graphical model"), ".", tr("STL files (*.stl *.STL)\n" "OBJ files (*.obj *.OBJ)"));
	if (!filename.isEmpty()) {
		int lastPoint = filename.lastIndexOf(".");
		QString extention = filename.right(lastPoint);
		GraphicalModel* model = new GraphicalModel();

		if (extention.contains("stl", Qt::CaseInsensitive)) {
			vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
  			reader->SetFileName(filename.toStdString().c_str());
  			reader->Update();
  			
  			model->setModel(reader);
		}
		if (extention.contains("obj", Qt::CaseInsensitive)) {
			vtkSmartPointer<vtkOBJReader> reader = vtkSmartPointer<vtkOBJReader>::New();
  			reader->SetFileName(filename.toStdString().c_str());
  			reader->Update();

  			model->setModel(reader);
		}
		ren1->AddActor(model->getModelActor());
		statusbar->showMessage(filename);
		ren1->ResetCamera();
		renWin->Render();
	}
}


/*
	activate Leap Motion when button is pressed
*/
void MainWindowController::on_leapActivateButton_clicked()
{
	//enable or disable leap
	g_lmListener->switchListener();
	
	if (g_lmListener->getStatus() == 1) { //running
		//leap reaction 
		HandModel* rightHand = g_lmListener->getRightHand();
		HandModel* leftHand  = g_lmListener->getLeftHand();

		ren1->AddActor(leftHand->getPalmModel()->getModelActor());
		for (int i = 0, n = leftHand->getTipsModel().size(); i < n; ++i)
		{
			ren1->AddActor(leftHand->getTipsModel().at(i)->getModelActor());
		}
		ren1->AddActor(rightHand->getPalmModel()->getModelActor());
		for (int i = 0, n = rightHand->getTipsModel().size(); i < n; ++i)
		{
			ren1->AddActor(rightHand->getTipsModel().at(i)->getModelActor());
		}

		ren1->AddActor(g_lmListener->getLeapDeviceModel()->getModelActor());

		//qt reaction
		leapActivateButton->setText(QString("Disable Leap Motion"));
		statusbar->showMessage(QString("FPS: ") + QString::number(g_lmListener->getFPS()));
		//vtk reaction
		renWin->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
		int timerId = renWin->GetInteractor()->CreateRepeatingTimer(DELTATIME);
	} else {	//stop
		//leap reaction 
		HandModel* rightHand = g_lmListener->getRightHand();
		HandModel* leftHand  = g_lmListener->getLeftHand();

		ren1->RemoveActor(leftHand->getPalmModel()->getModelActor());
		for (int i = 0, n = leftHand->getTipsModel().size(); i < n; ++i)
		{
			ren1->RemoveActor(leftHand->getTipsModel().at(i)->getModelActor());
		}
		ren1->RemoveActor(rightHand->getPalmModel()->getModelActor());
		for (int i = 0, n = rightHand->getTipsModel().size(); i < n; ++i)
		{
			ren1->RemoveActor(rightHand->getTipsModel().at(i)->getModelActor());
		}
		ren1->RemoveActor(g_lmListener->getLeapDeviceModel()->getModelActor());
		//qt reaction
		leapActivateButton->setText(QString("Enable Leap Motion"));
		//vtk reaction
		renWin->GetInteractor()->RemoveObserver(g_vtkCallback);
	}
	ren1->ResetCamera();
	renWin->Render();
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
	Create new window for projector
*/
void MainWindowController::createWindow(int width, int height, int index = 0)
{
	QVTKWidget *newWidget = new QVTKWidget();
	vtkSmartPointer<vtkRenderer> ren2 = vtkSmartPointer<vtkRenderer>::New();
  	ren2->AddActor( _actor );
  	ren2->SetBackground( 0.0, 0.0, 0.0 );

  	vtkSmartPointer<vtkRenderWindow> renWin2 = vtkSmartPointer<vtkRenderWindow>::New();
  	renWin2->AddRenderer( ren2 );
  	renWin2->SetSize( 300, 300 );
  	ren2->SetActiveCamera(ren1->GetActiveCamera());

    newWidget->setObjectName(QString::fromUtf8("newWidget"));
	QRect rect(1200*(index+1), 0, width, height);
	newWidget->setGeometry(rect);
	newWidget->SetRenderWindow(renWin2);

	renWin2->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
	int timerId = renWin2->GetInteractor()->CreateRepeatingTimer(DELTATIME);
	newWidget->show();
}
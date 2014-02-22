#include <QtGui>
#include "mainWindowController.h"

#define DELTATIME 1.0/60.0

MainWindowController::MainWindowController(QWidget *parent)
{
	setupUi(this);
	currentTime = std::chrono::high_resolution_clock::now();
	lastTime    = currentTime;

	cone = vtkSmartPointer<vtkConeSource>::New();
  	cone->SetHeight( 3.0 );
  	cone->SetRadius( 1.0 );
  	cone->SetResolution( 10 );

  	coneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  	coneMapper->SetInputConnection( cone->GetOutputPort() );

  	coneActor = vtkSmartPointer<vtkLODActor>::New();
  	coneActor->SetMapper( coneMapper );

  	ren1= vtkSmartPointer<vtkRenderer>::New();
  	ren1->AddActor( coneActor );
  	ren1->SetBackground( 0.0, 0.0, 0.0 );

  	renWin = vtkSmartPointer<vtkRenderWindow>::New();
  	renWin->AddRenderer( ren1 );
  	renWin->SetSize( 300, 300 );

  
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
	g_lmListener->addActor(coneActor);
}

MainWindowController::~MainWindowController() {
	
}



/*
	call it in main.cxx while{}
*/
/*void MainWindowController::update(vtkObject*, unsigned long eid, void* clientdata, void *calldata)
{
	currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSpan =  std::chrono::duration_cast< std::chrono::duration<double> > (currentTime - lastTime);
	if (timeSpan.count() < DELTATIME) {
		return;
	}

	vtkSmartPointer<vtkTransform> translation = vtkSmartPointer<vtkTransform>::New();
  	Leap::Vector vec = Leap::Vector::zero();//_listener.getTranslation();
  	translation->Translate(vec.x, vec.y, vec.z);
 
  	vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
  	transformFilter->SetInputConnection(cone->GetOutputPort());
  	transformFilter->SetTransform(translation);
  	transformFilter->Update();
 
  	coneMapper->SetInputConnection(cone->GetOutputPort());

	lastTime = currentTime;
}*/









/*
	activate Leap Motion when button is pressed
*/
void MainWindowController::on_leapActivateButton_clicked()
{
	//enable or disable leap
	g_lmListener->switchListener();

	if (g_lmListener->getStatus() == 1) { //running
		//qt reaction
		leapActivateButton->setText(QString("Disable Leap Motion"));
		statusbar->showMessage(QString("FPS: ") + QString::number(g_lmListener->getFPS()));
		//vtk reaction
		renWin->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
		int timerId = renWin->GetInteractor()->CreateRepeatingTimer(50);
  	    std::cout << "timerId: " << timerId << std::endl;

	} else {	//stop
		//qt reaction
		leapActivateButton->setText(QString("Enable Leap Motion"));
		//vtk reaction
		renWin->GetInteractor()->RemoveObserver(g_vtkCallback);
	}
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
	QVTKWidget *newWindow = new QVTKWidget();
	vtkSmartPointer<vtkRenderer> ren2 = vtkSmartPointer<vtkRenderer>::New();
  	ren2->AddActor( coneActor );
  	ren2->SetBackground( 0.0, 0.0, 0.0 );

  	vtkSmartPointer<vtkRenderWindow> renWin2 = vtkSmartPointer<vtkRenderWindow>::New();
  	renWin2->AddRenderer( ren2 );
  	renWin2->SetSize( 300, 300 );
  	ren2->SetActiveCamera(ren1->GetActiveCamera());

    newWindow->setObjectName(QString::fromUtf8("newWindow"));
	QRect rect(1200*(index+1), 0, width, height);
	newWindow->setGeometry(rect);
	newWindow->SetRenderWindow(renWin2);
	newWindow->show();
}
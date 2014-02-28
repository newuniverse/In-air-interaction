#include <QtGui>
#include "mainWindowController.h"

#include "graphicalModel.h"
#include "Shared.h"
#define DELTATIME 30 //ms


MainWindowController::MainWindowController(QWidget *parent)
{
	setupUi(this);
	//OVR for future use
	pManager = *DeviceManager::Create();
	//pHMD = *pManager->EnumerateDevices<HMDDevice>().CreateDevice();
	conf_xml = new tinyxml2::XMLDocument();
	
  	mainRenderer= vtkSmartPointer<vtkRenderer>::New();
  	mainRenderer->SetBackground( 0.0, 0.0, 0.0 );

  	mainWindow = vtkSmartPointer<vtkRenderWindow>::New();
  	mainWindow->AddRenderer(mainRenderer);
  	mainWindow->SetSize(300, 300);

  	qvtkWidget->SetRenderWindow(mainWindow);
  	
  	mainWindow->SetInteractor(qvtkWidget->GetInteractor());
  	g_vtkCallback = vtkSmartPointer<vtkTimerCallback>::New();
 	 	
  	//chart rendering example
  	vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  	vtkSmartPointer<vtkContextView> view2 = vtkSmartPointer<vtkContextView>::New();
  	
	vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
	vtkSmartPointer<vtkChartXY> chart2 = vtkSmartPointer<vtkChartXY>::New();

	chart->SetRenderEmpty(true);
	chart->SetAutoAxes(false);
	chart2->SetRenderEmpty(true);
	chart2->SetAutoAxes(false);

	view->GetScene()->AddItem(chart.GetPointer());
	view2->GetScene()->AddItem(chart2.GetPointer());

	view->SetInteractor(vtkChart1->GetInteractor());
	view2->SetInteractor(vtkChart2->GetInteractor());
	
	vtkChart1->SetRenderWindow(view->GetRenderWindow());
	vtkChart2->SetRenderWindow(view2->GetRenderWindow());

	g_lmListener   = new LeapListener;
	g_lmController = new Leap::Controller;
	g_lmController->addListener(*g_lmListener); 

	X1 = 1; Y1 = 1; X2 = -1; Y2 = 1; X3 = -1; Y3 = -1; X4 = 1; Y4 = -1;
}

MainWindowController::~MainWindowController() {
	delete g_lmListener;
	delete g_lmController;
}

void MainWindowController::on_saveKeystoneButton_clicked() {
	if (createWindowButton->isEnabled()) {
		return;
	}
	/*
	tinyxml2::XMLDeclaration* decl = new tinyxml2::XMLDeclaration( "1.0");  
	conf_xml->LinkEndChild(decl);
	tinyxml2::XMLElement* root = new XMLElement("IN-AIR-CONFIG");
	conf_xml->LinkEndChild(root);

	tinyxml2::XMLComment* comment = new tinyxml2::XMLComment();
	comment->SetValue("Configuration for MyApp");  
	root->LinkEndChild(comment);
 	
	tinyxml2::XMLElement* windows = new tinyxml2::XMLElement("Windows");  
	root->LinkEndChild(windows);

	tinyxml2::XMLElement* total = new tinyxml2::XMLElement("Total");  

	QString str = QString::number(windowNumSpinBox->value());

	total->LinkEndChild(new tinyxml2::XMLText(str.toStdString()));
	windows->LinkEndChild(total);
	conf_xml->SaveFile("Config.xml");*/
}

void MainWindowController::on_setKeystoneButton_clicked() {
	int index = windowIndexSpinBox->value();
	if (index > subCameras.size()) {
		return;
	}
	index = index - 1;
	subCameras.at(index)->SetViewShear(index*0.1, 0.1, 1);
	subRenWindows.at(index)->Render();
}


void MainWindowController::addActorsToScene(vtkSmartPointer<vtkActor> actor) 
{
	mainRenderer->AddActor(actor);
	for (int i = 0, n = subRenderers.size(); i < n; ++i)
	{
		subRenderers.at(i)->AddActor(actor);
	}
}

/*
*/
void MainWindowController::refreshAllWindows() {
	mainRenderer->ResetCamera();
	mainRenderer->GetActiveCamera()->Zoom(0.8);
	mainWindow->Render();
	for (int i = 0, n = subRenWindows.size(); i < n; ++i)
	{
		//subRenderers.at(i)->GetActiveCamera()->SetViewShear(0, 0, 0);
		subRenderers.at(i)->ResetCamera();
		subRenderers.at(i)->GetActiveCamera()->Zoom(0.8);
		subRenWindows.at(i)->Render();
	}
}

void MainWindowController::addAllLeapModels() 
{
	HandModel* rightHand = g_lmListener->getRightHand();
	HandModel* leftHand  = g_lmListener->getLeftHand();

	this->addActorsToScene(leftHand->getPalmModel()->getModelActor());
	for (int i = 0, n = leftHand->getTipsModel().size(); i < n; ++i)
	{
		this->addActorsToScene(leftHand->getTipsModel().at(i)->getModelActor());
	}
	this->addActorsToScene(rightHand->getPalmModel()->getModelActor());

	for (int i = 0, n = rightHand->getTipsModel().size(); i < n; ++i)
	{
		this->addActorsToScene(rightHand->getTipsModel().at(i)->getModelActor());
	}
	this->addActorsToScene(g_lmListener->getLeapDeviceModel()->getModelActor());
	this->addActorsToScene(g_lmListener->getKeystoneFrameModel()->getModelActor());
}

void MainWindowController::removeAllLeapModels() 
{
	HandModel* rightHand = g_lmListener->getRightHand();
	HandModel* leftHand  = g_lmListener->getLeftHand();

	mainRenderer->RemoveActor(leftHand->getPalmModel()->getModelActor());
		
	for (int j = 0, m = subRenderers.size(); j < m; ++j)
	{
		subRenderers.at(j)->RemoveActor(leftHand->getPalmModel()->getModelActor());
	}

	for (int i = 0, n = leftHand->getTipsModel().size(); i < n; ++i)
	{
		mainRenderer->RemoveActor(leftHand->getTipsModel().at(i)->getModelActor());
		for (int j = 0, m = subRenderers.size(); j < m; ++j)
		{
			subRenderers.at(j)->RemoveActor(leftHand->getTipsModel().at(i)->getModelActor());
		}
	}

	mainRenderer->RemoveActor(rightHand->getPalmModel()->getModelActor());
	for (int j = 0, m = subRenderers.size(); j < m; ++j)
	{
		subRenderers.at(j)->RemoveActor(rightHand->getPalmModel()->getModelActor());
	}

	for (int i = 0, n = rightHand->getTipsModel().size(); i < n; ++i)
	{
		mainRenderer->RemoveActor(rightHand->getTipsModel().at(i)->getModelActor());
		for (int j = 0, m = subRenderers.size(); j < m; ++j)
		{
			subRenderers.at(j)->RemoveActor(rightHand->getTipsModel().at(i)->getModelActor());
		}
	}

	mainRenderer->RemoveActor(g_lmListener->getLeapDeviceModel()->getModelActor());
	mainRenderer->RemoveActor(g_lmListener->getKeystoneFrameModel()->getModelActor());
	for (int j = 0, m = subRenderers.size(); j < m; ++j)
	{
		subRenderers.at(j)->RemoveActor(g_lmListener->getLeapDeviceModel()->getModelActor());
		subRenderers.at(j)->RemoveActor(g_lmListener->getKeystoneFrameModel()->getModelActor());
	}
}

void MainWindowController::removeAllActorsFromScene() 
{
	for (int j = 0, m = allActors.size(); j < m; ++j)
	{
		mainRenderer->RemoveActor(allActors.at(j));

		for (int i = 0, n = subRenderers.size(); i < n; ++i)
		{
			subRenderers.at(i)->RemoveActor(allActors.at(j));
		}
	}
}


double* MainWindowController::calcKeystones() 
{
	double x1= 1, y1=1;
    double x2=-1, y2=1;
    double x3=-1, y3=-1;
    double x4= 1, y4=-1;
    /* X1-X4, Y1-Y4 are observed values */
    double A [9][9] = { 
    {x1,y1,1,0,0,0,-x1*X1,-y1*X1,-X1},
    {0,0,0,x1,y1,1,-x1*Y1,-y1*Y1,-Y1},
    {x2,y2,1,0,0,0,-x2*X2,-y2*X2,-X2},
    {0,0,0,x2,y2,1,-x2*Y2,-y2*Y2,-Y2},
    {x3,y3,1,0,0,0,-x3*X3,-y3*X3,-X3},
    {0,0,0,x3,y3,1,-x3*Y3,-y3*Y3,-Y3},
    {x4,y4,1,0,0,0,-x4*X4,-y4*X4,-X4},
    {0,0,0,x4,y4,1,-x4*Y4,-y4*Y4,-Y4},
    {0,0,0,0 , 0,0,     0,     0,  1}
    };
    
    double b[9] = { 0,0,0,0,0,0,0,0,1};
    
    /* Perform a Gauss Jordan to solve the system A h = b*/
    for(int j=0;j<9;j++){
        int count = j;
        while(count<9 && A[count][j]==0){
            count++;
        }
        if(count == 9){
           throw "InvalidKeystoneSettingException";
        }
        for(int i=0;i<9;i++){
            double tmp;
            tmp=A[j][i];
            A[j][i]=A[count][i];
            A[count][i]=tmp;
        }
        
        double divisor = A[j][j]; 
        for(int i=0;i<9;i++){
            A[j][i] /= divisor;
        }
        
        for(int i=j+1;i<9;i++){
            double factor = -A[i][j];
            //Fixa rad i
            for(int k=0;k<9;k++){
                A[i][k] += factor*A[j][k];
            }
        }
    }

    for(int j=8;j>=0;j--){
        for(int i=j+1;i<=8;i++){
            b[j] += -b[i]*A[j][i];
        }
    }

    double h33 = 1;
    if(b[6]>0)
        h33 -=b[6];
    else
        h33 +=b[6];
    if(b[7]>0)
        h33 -=b[7];
    else
        h33 +=b[7];

    /* the matrix responsible for the keystone effect (beware, this is the transponate of the matrix)*/
    double h[16] = { b[0], b[3], 0, b[6], b[1], b[4], 0, b[7], 0, 0, h33, 0, b[2], b[5], 0 , 1 };
    return h;
}

void MainWindowController::on_actionNew_triggered() 
{
	this->removeAllActorsFromScene();
	this->refreshAllWindows();
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
		allActors.push_back(model->getModelActor());
		statusbar->showMessage(filename);
		this->addActorsToScene(model->getModelActor());
		this->refreshAllWindows();
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
		this->addAllLeapModels();
		//qt reaction
		leapActivateButton->setText(QString("Disable Leap Motion"));
		statusbar->showMessage(QString("FPS: ") + QString::number(g_lmListener->getFPS()));
		//vtk reaction
		mainWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
		int timerId = mainWindow->GetInteractor()->CreateRepeatingTimer(DELTATIME);
	} else {	//stop
		//leap reaction 
		this->removeAllLeapModels();
		//qt reaction
		leapActivateButton->setText(QString("Enable Leap Motion"));
		//vtk reaction
		mainWindow->GetInteractor()->RemoveObserver(g_vtkCallback);
	}
	
	this->refreshAllWindows();
	//mainWindow->Render();
}

/*
	Creating new windows is triggered when createWindowbutton is clicked
	Automatically connected when create function like below on_ObjectName_EventName()
*/
void MainWindowController::on_createWindowButton_clicked()
{
	int winNum = windowNumSpinBox->value();
	int width, height;
	subInteractors.reserve(winNum);
	subRenderers.reserve(winNum);
	subRenWindows.reserve(winNum);
	subCameras.reserve(winNum);

	for (int i = 0; i < winNum; ++i)
	{
		width = 500;
		height = 500;
		if (!(widthLineEdit->text().isEmpty())) {
			width = widthLineEdit->text().toInt();
		}
		//le = this->findChild<QLineEdit*>(QString("height"));
		if (!(heightLineEdit->text().isEmpty())) {
			height = heightLineEdit->text().toInt();
		}
		createWindow(width, height, i);
	}
	subInteractors.at(winNum-1)->Start();
	createWindowButton->setEnabled(false);
	this->refreshAllWindows();
}


/*
	Create new window for projector
*/
void MainWindowController::createWindow(int width, int height, int index = 0)
{	
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  	renderer->SetBackground( 0.0, 0.0, 0.0 );
  	subRenderers.push_back(renderer);

  	vtkSmartPointer<vtkRenderWindow> renWindow = vtkSmartPointer<vtkRenderWindow>::New();
  	subRenWindows.push_back(renWindow);
  	renWindow->AddRenderer( renderer );
  	renWindow->SetSize( width, height );
  	std::stringstream ss;
    ss << "Window " << index;
    renWindow->SetWindowName(ss.str().c_str());
    renWindow->SetPosition((index+1)*1200, 100);
  	
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	subInteractors.push_back(renderWindowInteractor);

	renderWindowInteractor->SetRenderWindow(renWindow);
	renWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
	int timerId = renWindow->GetInteractor()->CreateRepeatingTimer(DELTATIME);
	//renWindow->FullScreenOn();
	//renWindow->BordersOff();
	vtkSmartPointer<vtkCamera> camera = vtkSmartPointer<vtkCamera>::New();
	subCameras.push_back(camera);
	renderer->SetActiveCamera(camera);

	std::cout << "window " << index <<": diplayid = " << renWindow->GetGenericDisplayId() << std::endl;
}
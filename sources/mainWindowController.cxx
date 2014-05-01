#include <QtGui>
#include "mainWindowController.h"

#include "graphicalModel.h"

#include "Leap/Shared.h"
#include <boost/algorithm/string.hpp>
#include <sstream>

//#define DELTATIME 30 //ms
#define CONFIGFILENAME "conf.xml"

MainWindowController::MainWindowController(QWidget *parent)
{	
	//OVR for future use
	//pHMD = *pManager->EnumerateDevices<HMDDevice>().CreateDevice();
	#ifdef _APPLE_
	pManager = *DeviceManager::Create();
	#endif
	setupUi(this);
	this->initConfigFile();
	this->setupRenderAndWindow();
	this->setupCharts();
  	
	g_lmListener   = new LeapListener;
	g_lmController = new Leap::Controller;
	g_lmController->addListener(*g_lmListener); 

	robot = new RobotModel();
	X1 = 1; Y1 = 1; X2 = -1; Y2 = 1; X3 = -1; Y3 = -1; X4 = 1; Y4 = -1;
}

MainWindowController::~MainWindowController() 
{
	delete g_lmListener;
	delete g_lmController;
	delete conf_xml;
}

void MainWindowController::setupCharts()
{
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
}

void MainWindowController::setupRenderAndWindow() 
{
	g_vtkCallback = vtkSmartPointer<vtkTimerCallback>::New();

	mainRenderer = vtkSmartPointer<vtkRenderer>::New();
	mainWindow = vtkSmartPointer<vtkRenderWindow>::New();
	attachRendererToWindow(mainRenderer, mainWindow, qvtkWidget);
	mainWindow->SetInteractor(qvtkWidget->GetInteractor());

	
	topViewRenderer = vtkSmartPointer<vtkRenderer>::New();
	topViewCamera = vtkSmartPointer<vtkCamera>::New();
	topViewRenderer->SetActiveCamera(topViewCamera);
	topViewWindow = vtkSmartPointer<vtkRenderWindow>::New();
	attachRendererToWindow(topViewRenderer, topViewWindow, qvtkWidget_top);

	frontViewRenderer = vtkSmartPointer<vtkRenderer>::New();
	frontViewCamera = vtkSmartPointer<vtkCamera>::New();
	frontViewRenderer->SetActiveCamera(frontViewCamera);
	frontViewWindow = vtkSmartPointer<vtkRenderWindow>::New();
  	attachRendererToWindow(frontViewRenderer, frontViewWindow, qvtkWidget_front);

  	sideViewRenderer = vtkSmartPointer<vtkRenderer>::New();
  	sideViewCamera = vtkSmartPointer<vtkCamera>::New();
	sideViewRenderer->SetActiveCamera(sideViewCamera);
	sideViewWindow = vtkSmartPointer<vtkRenderWindow>::New();
  	attachRendererToWindow(sideViewRenderer, sideViewWindow, qvtkWidget_side);

  	endoscopeViewRenderer = vtkSmartPointer<vtkRenderer>::New();
  	endoscopeViewCamera = vtkSmartPointer<vtkCamera>::New();
	endoscopeViewRenderer->SetActiveCamera(endoscopeViewCamera);
	endoscopeViewWindow = vtkSmartPointer<vtkRenderWindow>::New();
  	attachRendererToWindow(endoscopeViewRenderer, endoscopeViewWindow, qvtkWidget_endoscope);
}

void MainWindowController::attachRendererToWindow(vtkSmartPointer<vtkRenderer> ren, 
													vtkSmartPointer<vtkRenderWindow> win, QVTKWidget* widget)
{
	ren->SetBackground(0.0, 0.0, 0.0);
	win->AddRenderer(ren);
	widget->SetRenderWindow(win);
}

void MainWindowController::initConfigFile ()
{
	conf_xml = new tinyxml2::XMLDocument();
	if (conf_xml->LoadFile(CONFIGFILENAME) == 0) {
		return;
	}

	//create new config file if there is not
	tinyxml2::XMLDeclaration* decl = conf_xml->NewDeclaration();
	conf_xml->InsertFirstChild(decl);
	tinyxml2::XMLComment* comment = conf_xml->NewComment("Configuration for MyApp");
	conf_xml->InsertAfterChild(decl, comment);

	//insert elements of holo-table
	tinyxml2::XMLElement* holo_table = conf_xml->NewElement("Holo_table");
	conf_xml->InsertAfterChild(comment, holo_table);
	tinyxml2::XMLElement* windows = conf_xml->NewElement("Windows");
	holo_table->InsertFirstChild(windows);
	/*
		insert new elements 
	*/	
	//insert elements of OVR
	tinyxml2::XMLElement* ovr = conf_xml->NewElement("OVR");
	conf_xml->InsertAfterChild(holo_table, ovr);
	conf_xml->SaveFile(CONFIGFILENAME);
}

void MainWindowController::on_parallaxSlider_valueChanged(int value) {
	for (int i = 0, n = subCameras.size(); i < n; ++i)
	{
		subCameras.at(i)->SetViewShear(i*value/1000.0, 0.1, 1);
		subRenWindows.at(i)->Render();
	}
}

void MainWindowController::on_saveKeystoneButton_clicked() {
	if (createWindowButton->isEnabled()) {
		return;
	}
	conf_xml->SaveFile("conf.xml");
}

void MainWindowController::on_setKeystoneButton_clicked() 
{
	int index = windowIndexSpinBox->value();
	if (index > subCameras.size()) {
		return;
	}
		
	std::string keystone_str = QString::number(X1).toStdString() + "," +
							   QString::number(Y1).toStdString() + "," +
							   QString::number(X2).toStdString() + "," +
							   QString::number(Y2).toStdString() + "," +
							   QString::number(X3).toStdString() + "," +
							   QString::number(Y3).toStdString() + "," +
							   QString::number(X4).toStdString() + "," +
							   QString::number(Y4).toStdString();

	tinyxml2::XMLElement* holo_table = conf_xml->FirstChildElement();
	tinyxml2::XMLElement* window = holo_table->FirstChildElement();
	window->SetAttribute(("Keystone"+QString::number(index).toStdString()).c_str(), keystone_str.c_str());

	index = index - 1;
	//subCameras.at(index)->SetViewShear(index*0.1, 0.1, 1);
	subRenWindows.at(index)->Render();
}

void MainWindowController::removeActorFromScenes(vtkSmartPointer<vtkActor> actor) 
{
	mainRenderer->RemoveActor(actor);
	for (int i = 0, n = subRenderers.size(); i < n; ++i)
	{
		subRenderers.at(i)->RemoveActor(actor);
	}
}

void MainWindowController::removeActorFromScenes(vtkSmartPointer<vtkAxesActor> actor) 
{
	mainRenderer->RemoveActor(actor);
	for (int i = 0, n = subRenderers.size(); i < n; ++i)
	{
		subRenderers.at(i)->RemoveActor(actor);
	}
}


void MainWindowController::addActorToScenes(vtkSmartPointer<vtkActor> actor) 
{
	mainRenderer->AddActor(actor);
	topViewRenderer->AddActor(actor);
	frontViewRenderer->AddActor(actor);
	sideViewRenderer->AddActor(actor);
	endoscopeViewRenderer->AddActor(actor);
	// std::cout<<"number of renderer: " << subRenderers.size() <<std::endl;
	for (int i = 0, n = subRenderers.size(); i < n; ++i)
	{
		subRenderers.at(i)->AddActor(actor);
	}
}

void MainWindowController::addActorToScenes(vtkSmartPointer<vtkAxesActor> actor) 
{
	mainRenderer->AddActor(actor);
	topViewRenderer->AddActor(actor);
	frontViewRenderer->AddActor(actor);
	sideViewRenderer->AddActor(actor);
	endoscopeViewRenderer->AddActor(actor);
	// std::cout<<"number of renderer: " << subRenderers.size() <<std::endl;
	for (int i = 0, n = subRenderers.size(); i < n; ++i)
	{
		subRenderers.at(i)->AddActor(actor);
	}
}

void MainWindowController::removeAllActorsFromScene() 
{
	for (int j = 0, m = allActors.size(); j < m; ++j)
	{
		mainRenderer->RemoveActor(allActors.at(j));
		topViewRenderer->RemoveActor(allActors.at(j));
		frontViewRenderer->RemoveActor(allActors.at(j));
		sideViewRenderer->RemoveActor(allActors.at(j));
		endoscopeViewRenderer->RemoveActor(allActors.at(j));
		for (int i = 0, n = subRenderers.size(); i < n; ++i)
		{
			subRenderers.at(i)->RemoveActor(allActors.at(j));
		}
	}
}


/*
*/
void MainWindowController::refreshAllWindows(bool resetCamera) {
	if (resetCamera) {
		mainRenderer->ResetCamera();
		topViewRenderer->ResetCamera();
		frontViewRenderer->ResetCamera();
		sideViewRenderer->ResetCamera();
		endoscopeViewRenderer->ResetCamera();
	}
	mainWindow->Render();
	topViewWindow->Render();
	frontViewWindow->Render();
	sideViewWindow->Render();
	endoscopeViewWindow->Render();

	for (int i = 0, n = subRenderers.size(); i < n; ++i)
	{
		//subRenderers.at(i)->GetActiveCamera()->SetViewShear(0, 0, 0);
		if (resetCamera) subRenderers.at(i)->ResetCamera();
		//subRenderers.at(i)->GetActiveCamera()->Zoom(0.8);
		subRenWindows.at(i)->Render();
	}
}

void MainWindowController::addAllLeapModels() 
{
	HandModel* rightHand = g_lmListener->getRightHand();
	HandModel* leftHand  = g_lmListener->getLeftHand();

	this->addActorToScenes(leftHand->getPalmModel()->getModelActor());
	for (int i = 0, n = leftHand->getTipsModel().size(); i < n; ++i)
	{
		this->addActorToScenes(leftHand->getTipsModel().at(i)->getModelActor());
	}
	this->addActorToScenes(rightHand->getPalmModel()->getModelActor());

	for (int i = 0, n = rightHand->getTipsModel().size(); i < n; ++i)
	{
		this->addActorToScenes(rightHand->getTipsModel().at(i)->getModelActor());
	}
	this->addActorToScenes(g_lmListener->getLeapDeviceModel()->getModelActor());
	this->addActorToScenes(g_lmListener->getLeapDeviceModel()->getAxesActor());
	this->addActorToScenes(g_lmListener->getKeystoneFrameModel()->getModelActor());

}

void MainWindowController::removeAllLeapModels() 
{
	HandModel* rightHand = g_lmListener->getRightHand();
	HandModel* leftHand  = g_lmListener->getLeftHand();

	this->removeActorFromScenes(leftHand->getPalmModel()->getModelActor());

	for (int i = 0, n = leftHand->getTipsModel().size(); i < n; ++i)
	{
		this->removeActorFromScenes(leftHand->getTipsModel().at(i)->getModelActor());
	}

	this->removeActorFromScenes(rightHand->getPalmModel()->getModelActor());

	for (int i = 0, n = rightHand->getTipsModel().size(); i < n; ++i)
	{
		this->removeActorFromScenes(rightHand->getTipsModel().at(i)->getModelActor());
	}
	this->removeActorFromScenes(g_lmListener->getLeapDeviceModel()->getModelActor());
	this->removeActorFromScenes(g_lmListener->getLeapDeviceModel()->getAxesActor());
	this->removeActorFromScenes(g_lmListener->getKeystoneFrameModel()->getModelActor());
}


float* MainWindowController::getDHparameters() 
{
	float* dh_parameter = new float[24];
	dh_parameter[0] = j1d->text().toFloat();
	dh_parameter[1] = j1a->text().toFloat();
	dh_parameter[2] = j1alpha->text().toFloat();
	dh_parameter[3] = j1theta->value();

	dh_parameter[4] = j2d->text().toFloat();
	dh_parameter[5] = j2a->text().toFloat();
	dh_parameter[6] = j2alpha->text().toFloat();
	dh_parameter[7] = j2theta->value();

	dh_parameter[8] = j3d->text().toFloat();
	dh_parameter[9] = j3a->text().toFloat();
	dh_parameter[10] = j3alpha->text().toFloat();
	dh_parameter[11] = j3theta->value();

	dh_parameter[12] = j4d->text().toFloat();
	dh_parameter[13] = j4a->text().toFloat();
	dh_parameter[14] = j4alpha->text().toFloat();
	dh_parameter[15] = j4theta->value();

	dh_parameter[16] = j5d->text().toFloat();
	dh_parameter[17] = j5a->text().toFloat();
	dh_parameter[18] = j5alpha->text().toFloat();
	dh_parameter[19] = j5theta->value();

	dh_parameter[20] = j6d->text().toFloat();
	dh_parameter[21] = j6a->text().toFloat();
	dh_parameter[22] = j6alpha->text().toFloat();
	dh_parameter[23] = j6theta->value();
	return dh_parameter;
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

void MainWindowController::keystoneSpinBoxCommon() {
	int index = windowIndexSpinBox->value();
	if (index > subCameras.size())
		return;

	index = index - 1;
	double* matH = new double[16];
	matH = calcKeystones();

	vtkSmartPointer<vtkTransform> keystone = vtkSmartPointer<vtkTransform>::New();
	keystone->SetMatrix(matH);
	subCameras.at(index)->SetUserTransform(keystone);
	subRenWindows.at(index)->Render();
}

void MainWindowController::on_actionNew_triggered() 
{
	this->removeAllActorsFromScene();
	this->refreshAllWindows(true);
}

void MainWindowController::on_actionOpen_Config_triggered()
{
	if (!createWindowButton->isEnabled()) {
		return;
	}

	QString filename = QFileDialog::getOpenFileName(this, tr("Open config file"), ".", tr("XML files (*.xml *.XML)"));
	if (filename.isEmpty()) {
		return;
	}

	if (conf_xml->LoadFile(filename.toStdString().c_str()) != 0) {
		return;
	}

	tinyxml2::XMLElement* holo_table = conf_xml->FirstChildElement();
	tinyxml2::XMLElement* window = holo_table->FirstChildElement();

	int width(500), height(500);

	const char* str = window->Attribute("Total");
	int winNum = atoi(str);
	str = window->Attribute("Width");
	width = atoi(str);
	str = window->Attribute("Height");
	height = atoi(str);

	subInteractors.reserve(winNum);
	subRenderers.reserve(winNum);
	subRenWindows.reserve(winNum);
	subCameras.reserve(winNum);
	keystoneTsf.reserve(winNum);

	for (int i = 0; i < winNum; ++i)
	{
		createOne(width, height, i);
	}
	subInteractors.at(winNum-1)->Start();
	createWindowButton->setEnabled(false);
	this->refreshAllWindows(false);
	
	
	double keystones[winNum][8];

	for (int i = 0; i < winNum; ++i) {
		std::stringstream ss;
		ss << i+1;
		str = window->Attribute(("Keystone"+ss.str()).c_str());
		cout << "keystone str: " << str << std::endl;
		std::string delim (",");
 		std::list<std::string> list_string;
 		boost::split(list_string, str, boost::is_any_of(delim), boost::algorithm::token_compress_on);
 		if (list_string.size() != 8) {
 			//throw "InvalidKeystoneSettingException";
 			return;
 		}
		std::list<std::string>::iterator it = list_string.begin();
		int counter = 0;
		while (it != list_string.end()) {
			cout << "keystone each: " << atof((*it).c_str()) << std::endl;;
			keystones[i][counter] = atof((*it).c_str());
			++counter;
			++it;
		}
	}
	double* ks_array = new double[8];
	for (int i = 0; i < winNum; ++i)
	{
		ks_array = keystones[i];
		setKeystoneTransform(ks_array, i);
	}
	//this->refreshAllWindows();*/
}

void MainWindowController::setKeystoneTransform(double* ks_array, int index) 
{
	vtkSmartPointer<vtkTransform> keystone = vtkSmartPointer<vtkTransform>::New();
	keystoneTsf.push_back(keystone);
	double* matH = new double[16];	

	this->X1 = ks_array[0]; this->Y1 = ks_array[1]; 
	this->X2 = ks_array[2]; this->Y2 = ks_array[3];
	this->X3 = ks_array[4]; this->Y3 = ks_array[5];
	this->X4 = ks_array[6]; this->Y4 = ks_array[7];
	std::cout << "keystone: " << X1 <<" "<< Y1 <<" "<< X2 <<" "<< Y2 <<" "<< X3 <<" "<< Y3 <<" "<< X4 <<" "<< Y4 <<std::endl;
	matH = calcKeystones();
	keystone->SetMatrix(matH);
	subCameras.at(index)->SetUserTransform(keystone);
	//delete matH;
	//subCameras.at(index)->SetViewShear(i*0.1, 0.1, 1);
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
		this->addActorToScenes(model->getModelActor());
		this->refreshAllWindows(true);
	}
}

/*
	activate robot manipulator when button is pressed
*/
void MainWindowController::on_robotActivateButton_clicked()
{
	if (robotActivateButton->isCheckable() == false) {
		robotActivateButton->setText(QString("Disable Manipulator"));
		
		for (int i = 0, l = robot->getModel().size(); i < l; ++i)
		{
			this->addActorToScenes(robot->getModel().at(i)->getModelActor()); 
			this->addActorToScenes(robot->getModel().at(i)->getAxesActor()); 
		} 
		robot->setup(this->getDHparameters());
		//todo
		//endoscopeViewCamera->GetProperty()->RotateX(90);
		endoscopeViewCamera->SetUserTransform(robot->getEndEffectorTransform());
		this->refreshAllWindows(true);
		robotActivateButton->setCheckable(true);
	} else {
		robotActivateButton->setText(QString("Enable Manipulator"));
		robotActivateButton->setCheckable(false);

		for (int i = 0, l = robot->getModel().size(); i < l; ++i) {
			this->removeActorFromScenes(robot->getModel().at(i)->getModelActor());
		}
		this->refreshAllWindows(false);
	}
	//delete robot;
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
		topViewWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
		int timerIdTop = topViewWindow->GetInteractor()->CreateRepeatingTimer(DELTATIME);
		frontViewWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
		int timerIdfront = frontViewWindow->GetInteractor()->CreateRepeatingTimer(DELTATIME);
		sideViewWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, g_vtkCallback);
		int timerIdside = sideViewWindow->GetInteractor()->CreateRepeatingTimer(DELTATIME);
		this->refreshAllWindows(true);
	} else {	//stop
		//leap reaction 
		this->removeAllLeapModels();
		//qt reaction
		leapActivateButton->setText(QString("Enable Leap Motion"));
		//vtk reaction
		mainWindow->GetInteractor()->RemoveObserver(g_vtkCallback);
		this->refreshAllWindows(false);
	}
	//std::cout<< "number of actors in window1: " << subRenderers.at(0)->GetActors()->GetNumberOfItems() << std::endl;
	//subRenderers.at(0)->ResetCamera();
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
		createOne(width, height, i);
	}
	subInteractors.at(winNum-1)->Start();
	createWindowButton->setEnabled(false);
	this->refreshAllWindows(true);

	tinyxml2::XMLElement* holo_table = conf_xml->FirstChildElement();
	tinyxml2::XMLElement* window = holo_table->FirstChildElement();
	window->SetAttribute("Total", winNum);
	window->SetAttribute("Width", width);
	window->SetAttribute("Height", height);
}


void MainWindowController::createWindowFromConfig()
{
}

/*
	Create new window for projector
*/
void MainWindowController::createOne(int width, int height, int index = 0)
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
    std::cout << "create index:" << index << std::endl;
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
	//std::cout << "window " << index <<": diplayid = " << renWindow->GetGenericDisplayId() << std::endl;
}
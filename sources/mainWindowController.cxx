#include <QtGui>
#include "mainWindowController.h"


MainWindowController::MainWindowController(QWidget *parent)
{
	setupUi(this);
	
	cone = vtkSmartPointer<vtkConeSource>::New();
  	cone->SetHeight( 3.0 );
  	cone->SetRadius( 1.0 );
  	cone->SetResolution( 10 );

  	coneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  	coneMapper->SetInputConnection( cone->GetOutputPort() );

  	coneActor = vtkSmartPointer<vtkActor>::New();
  	coneActor->SetMapper( coneMapper );

  	ren1= vtkSmartPointer<vtkRenderer>::New();
  	ren1->AddActor( coneActor );
  	ren1->SetBackground( 0.1, 0.2, 0.4 );

  	renWin = vtkSmartPointer<vtkRenderWindow>::New();
  	renWin->AddRenderer( ren1 );
  	renWin->SetSize( 300, 300 );

  
  	qvtkWidget->SetRenderWindow(renWin);
  	renWin->SetInteractor(qvtkWidget->GetInteractor());

}

MainWindowController::~MainWindowController() {
	
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
  	ren2->SetBackground( 0.1, 0.2, 0.4 );

  	vtkSmartPointer<vtkRenderWindow> renWin2 = vtkSmartPointer<vtkRenderWindow>::New();
  	renWin2->AddRenderer( ren2 );
  	renWin2->SetSize( 300, 300 );
  	ren2->SetActiveCamera(ren1->GetActiveCamera());

    newWindow->setObjectName(QString::fromUtf8("newWindow"));
	QRect rect(1200*(index+1), 0, width, height);
	newWindow->setGeometry(rect);
	newWindow->SetRenderWindow(renWin2);
	
  	//renWin2->SetInteractor(qvtkWidget->GetInteractor());
	newWindow->show();
}
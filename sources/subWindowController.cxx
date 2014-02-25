#include <QtGui>
#include "subWindowController.h"

#include "Shared.h"
#define DELTATIME 30 //ms

SubWindowController::SubWindowController(QWidget *parent) 
{
	setupUi(this);

    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->SetBackground( 0.0, 0.0, 0.0 );
    window = vtkSmartPointer<vtkRenderWindow>::New();
    window->AddRenderer(renderer);
    window->SetSize(800, 600);
    callback = vtkSmartPointer<vtkTimerCallback>::New();
    window->GetInteractor()->AddObserver(vtkCommand::TimerEvent, callback);
	int timerId = window->GetInteractor()->CreateRepeatingTimer(DELTATIME);
    subWidget->SetRenderWindow(window);
    	//this->show();
}
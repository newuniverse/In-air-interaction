#ifndef SUBWINDOWCONTROLLER_H
#define SUBWINDOWCONTROLLER_H

#include "../ui_subWindow.h"

#include "vtkIncludeViewer.h"


class SubWindowController : public QWidget, private Ui::SubWindow
{
	Q_OBJECT
public://methods
    SubWindowController(QWidget *parent = 0);

    void addActor(vtkSmartPointer<vtkActor> actor) {
    	renderer->AddActor(actor);
    }
    ~SubWindowController();
private://methods
	
public://members
	
private://members
	vtkSmartPointer<vtkRenderer> renderer;
	vtkSmartPointer<vtkRenderWindow> window;
	vtkSmartPointer<vtkTimerCallback> callback;
};

#endif
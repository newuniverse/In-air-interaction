#ifndef GRAPHICALVIEWER
#define GRAPHICALVIEWER

#include "vtkIncludeViewer.h"
/*
	Viewer class for the second half of vtk rendering pipeline
	this class receive vtk***Actor and vtk**Interactor as input 
	and automatically create from vtkActor -> vtkRenderer -> vtkRenderWindow

	Controller class should call getModelActor() and attach the actor to 
	Viewer class like:
		vtkRenderer->AddActor(actor)
*/

class GraphicalViewer 
{
public://methods
    GraphicalViewer();
    template<class T>
	GraphicalViewer(vtkSmartPointer<T> ia) {

		_viewerRenderer= vtkSmartPointer<vtkRenderer>::New();
  		_viewerRenderer->SetBackground( 0.0, 0.0, 0.0 );

  		_viewerWindow = vtkSmartPointer<vtkRenderWindow>::New();
  		_viewerWindow->AddRenderer(_viewerRenderer);
  		_viewerWindow->SetSize(300, 300);

  		//_viewerWinInteractor = ia;
  		_viewerWindow->SetInteractor(ia);

  		_viewerCallBack = vtkSmartPointer<vtkTimerCallback>::New();
	}

	template<class T>
	void setViewer(vtkSmartPointer<T> ia) {

		_viewerRenderer= vtkSmartPointer<vtkRenderer>::New();
  		_viewerRenderer->SetBackground( 0.0, 0.0, 0.0 );

  		_viewerWindow = vtkSmartPointer<vtkRenderWindow>::New();
  		_viewerWindow->AddRenderer(_viewerRenderer);
  		_viewerWindow->SetSize(300, 300);

  		//_viewerWinInteractor = ia;
  		_viewerWindow->SetInteractor(ia);

  		_viewerCallBack = vtkSmartPointer<vtkTimerCallback>::New();
	}

	void Render() {
		_viewerWindow->Render();
	}

	void addActor(vtkSmartPointer<vtkActor> actor) {
		_viewerRenderer->AddActor(actor);
	}

	void removeActor(vtkSmartPointer<vtkActor> actor) {
		_viewerRenderer->RemoveActor(actor);
	}

	void setTimerEvent() {
		_viewerWinInteractor->AddObserver(vtkCommand::TimerEvent, _viewerCallBack);
	}

	void stopTimerEvent() {
		_viewerWinInteractor->RemoveObserver(_viewerCallBack);
	}

	vtkSmartPointer<vtkRenderer> getViewerRenderer() {
		return _viewerRenderer;
	}

	vtkSmartPointer<vtkRenderWindow> getViewerWindow() {
		return _viewerWindow;
	}

	vtkSmartPointer<vtkRenderWindowInteractor> getViewerWinInteractor() {
		return _viewerWinInteractor;
	}

	vtkSmartPointer<vtkTimerCallback> getTimerCallback() {
		return _viewerCallBack;
	}


    ~GraphicalViewer();
private://methods
	
public://members

private://members
	vtkSmartPointer<vtkRenderer>               _viewerRenderer;
	vtkSmartPointer<vtkRenderWindow>     	   _viewerWindow;
	vtkSmartPointer<vtkRenderWindowInteractor> _viewerWinInteractor; 
	vtkSmartPointer<vtkTimerCallback>          _viewerCallBack;
};

#endif
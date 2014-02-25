#ifndef VTKINCLUDEVIEWER_H
#define VTKINCLUDEVIEWER_H

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkTransform.h>
#include <vtkHomogeneousTransform.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <QVTKInteractor.h>
/*
	callback class which update renderwindow in constant frame rate
*/
class vtkTimerCallback : public vtkCommand
{
  public:
    static vtkTimerCallback *New()
    {
      vtkTimerCallback *cb = new vtkTimerCallback;
      return cb;
    }
    virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData) {
      if (vtkCommand::TimerEvent == eventId) {
        	vtkRenderWindowInteractor *renderWinIn = reinterpret_cast<vtkRenderWindowInteractor*>(caller);
      		renderWinIn->GetRenderWindow()->Render();
        }
    }
  private:
};
#endif
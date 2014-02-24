#include "graphicalModel.h"

/*
	Model class of the first half of vtk rendering pipeline
	this class receive vtk***Source, vtk***Reader as input 
	and automatically create from vtkSource -> vtkMapper -> vtkActor

	Controller class should call getModelActor() and attach the actor to 
	Viewer class like:
		vtkRenderer->AddActor(actor)
*/

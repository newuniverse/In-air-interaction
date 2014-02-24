#ifndef GRAPHICALMODEL_H
#define GRAPHICALMODEL_H

#include "vtkIncludeModel.h"

/*
	Model class for the first half of vtk rendering pipeline
	this class receive vtk***Source or vtk***Reader as input 
	and automatically create from vtkSource -> vtkMapper -> vtkActor

	Controller class should call getModelActor() and attach the actor to 
	Viewer class like:
		vtkRenderer->AddActor(actor)
*/

class GraphicalModel
{
public://methods
	GraphicalModel() {}

	template<class T>
	GraphicalModel(vtkSmartPointer<T> t) {
		_modelSource = t;

		_modelMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		_modelMapper->SetInputConnection(_modelSource->GetOutputPort());

		_modelActor = vtkSmartPointer<vtkActor>::New();
		_modelActor->SetMapper(_modelMapper);
	}

	template<class T>
	void setModel(vtkSmartPointer<T> t) {
		_modelSource = t;

		_modelMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		_modelMapper->SetInputConnection(_modelSource->GetOutputPort());

		_modelActor = vtkSmartPointer<vtkActor>::New();
		_modelActor->SetMapper(_modelMapper);
	}

	vtkSmartPointer<vtkActor> getModelActor() {
		vtkSmartPointer<vtkActor> myActor = _modelActor;
		return myActor;
	}

	vtkSmartPointer<vtkPolyDataMapper> getModelMapper() {
		return _modelMapper;
	}
	//template<class U>
	vtkSmartPointer<vtkPolyDataAlgorithm> getModelSource() {
		return _modelSource;
	}

private://methods
	
public://arguments
	
private://arguments
	vtkSmartPointer<vtkPolyDataAlgorithm> _modelSource;
	vtkSmartPointer<vtkPolyDataMapper> _modelMapper;
	vtkSmartPointer<vtkActor> _modelActor;
};

#endif
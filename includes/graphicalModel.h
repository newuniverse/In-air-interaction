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
	~GraphicalModel() {std::cout << "graphicalModel destructor called" << std::endl;}
	template<class T>
	GraphicalModel(T *t) {
		//model from source
		_modelSource = vtkSmartPointer<vtkPolyDataAlgorithm>::New();
		_modelSource = t;

		_modelMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		_modelMapper->SetInputConnection(_modelSource->GetOutputPort());

		_modelActor = vtkSmartPointer<vtkActor>::New();
		_modelActor->SetMapper(_modelMapper);
		//axis model
		_axesActor = vtkSmartPointer<vtkAxesActor>::New();
	}

	template<class T>
	void setModel(T *t) {
		_modelSource = vtkSmartPointer<vtkPolyDataAlgorithm>::New();
		_modelSource = t;

		_modelMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		_modelMapper->SetInputConnection(_modelSource->GetOutputPort());

		_modelActor = vtkSmartPointer<vtkActor>::New();
		_modelActor->SetMapper(_modelMapper);
		_axesActor = vtkSmartPointer<vtkAxesActor>::New();
	}

	vtkSmartPointer<vtkActor> getModelActor() {
		return _modelActor;
	}

	vtkSmartPointer<vtkAxesActor> getAxesActor() {
		return _axesActor;
	}

	vtkSmartPointer<vtkPolyDataMapper> getModelMapper() {
		return _modelMapper;
	}
	// template<class U>
	vtkSmartPointer<vtkPolyDataAlgorithm> getModelSource() {
		return _modelSource;
	}

private://methods
	
public://members

private: //members

protected://members
	vtkSmartPointer<vtkPolyDataAlgorithm> _modelSource;
	vtkSmartPointer<vtkPolyDataMapper> _modelMapper;
	vtkSmartPointer<vtkActor> _modelActor;
	vtkSmartPointer<vtkAxesActor> _axesActor;
};

#endif
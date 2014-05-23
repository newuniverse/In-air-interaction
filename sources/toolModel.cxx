#include "toolModel.h"

ToolModel::ToolModel()
{
	using namespace ConfigIntegrated;
	// vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
	vtkSphereSource* sphere = vtkSphereSource::New();
    sphere->SetRadius(CONSTRAIN_POINT_RAD);
  	sphere->SetThetaResolution(32);
  	sphere->SetPhiResolution(32);
	_constrainPoint = new GraphicalModel(sphere);
	_constrainPoint->getModelActor()->GetProperty()->SetAmbientColor(1.0, 1.0, 1.0);
	_constrainPoint->getModelActor()->GetProperty()->SetDiffuseColor(0.9, 0.8, 0.1);
	_constrainPoint->getModelActor()->GetProperty()->SetSpecularColor(0.0, 0.5, 0.0);
	_constrainPoint->getModelActor()->SetPosition(CONSTRAIN_POINT_POS);
	_components.push_back(_constrainPoint);

	_tipPos << FORCEPT_DOWN_END_INIT_POS[0], FORCEPT_DOWN_END_INIT_POS[1], FORCEPT_DOWN_END_INIT_POS[2];
	_constrainPointPos << CONSTRAIN_POINT_POS[0], CONSTRAIN_POINT_POS[1], CONSTRAIN_POINT_POS[2];


	// vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
	vtkCylinderSource* cylinder = vtkCylinderSource::New();
	cylinder->SetRadius(FORCEPT_RADIUS);
    cylinder->SetHeight(FORCEPT_LENGTH);
    cylinder->SetResolution(PRIMITIVE_RESOLUTION);
    // cylinder->SetCenter(0, FORCEPT_LENGTH, 0);

  	_forcept = new GraphicalModel(cylinder);
	// _forcept->getModelActor()->SetOrigin(CONSTRAIN_POINT_POS);
	// _forcept->getModelActor()->SetPosition(CONSTRAIN_POINT_POS);
    _forcept->getModelActor()->GetProperty()->SetAmbientColor(AMBIENT);
	_forcept->getModelActor()->GetProperty()->SetDiffuseColor(DIFFUSE);
	_forcept->getModelActor()->GetProperty()->SetSpecularColor(SPECULAR);
	_forcept->getModelActor()->RotateX(45);
    _components.push_back(_forcept); 
}

ToolModel::~ToolModel()
{
	delete _constrainPoint;
    delete _forcept;
    std::cout << "toolModel destructor called" << std::endl;
}

Eigen::Vector3d ToolModel::getToolsHandlePos(Eigen::Vector3d deltaPos)
{
	using namespace ConfigIntegrated;
	Eigen::Vector3d handlePos; //start of forcept which is connected to end of end-effector 
	_tipPos += deltaPos;	//end of forcept
	_deltaOrientation = (_constrainPointPos - _tipPos).normalized();
	handlePos =  _tipPos + FORCEPT_LENGTH * _deltaOrientation;
	return handlePos;
}	

void ToolModel::update(vtkSmartPointer<vtkMatrix4x4> mat) 
{
	// std::cout << "toolmodel \n" << std::endl;
	vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
	transform->SetMatrix(mat);
	_forcept->getModelActor()->SetUserTransform(transform);
	std::cout << "forcept pos\n" << _forcept->getModelActor()->GetPosition()[0]<<" " 
								<< _forcept->getModelActor()->GetPosition()[1]<<" " 
								<< _forcept->getModelActor()->GetPosition()[2]<<" "
								<< std::endl;
}




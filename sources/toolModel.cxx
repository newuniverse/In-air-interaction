#include "toolModel.h"
#define CONSTRAIN_POINT_RAD 1.5//cm
#define CONSTRAIN_POINT_POS_X 22.0
#define CONSTRAIN_POINT_POS_Y 45.0
#define CONSTRAIN_POINT_POS_Z 15.0
#define FORCEPT_LENGTH 		40//cm
#define FORCEPT_RAD         0.15//cm
ToolModel::ToolModel()
{
	vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
    sphere->SetRadius(CONSTRAIN_POINT_RAD);
  	sphere->SetThetaResolution(32);
  	sphere->SetPhiResolution(32);
	_constrainPoint = new GraphicalModel(sphere);
	_constrainPoint->getModelActor()->GetProperty()->SetAmbientColor(1.0, 1.0, 1.0);
	_constrainPoint->getModelActor()->GetProperty()->SetDiffuseColor(0.9, 0.8, 0.1);
	_constrainPoint->getModelActor()->GetProperty()->SetSpecularColor(0.0, 0.5, 0.0);
	_constrainPoint->getModelActor()->SetPosition(CONSTRAIN_POINT_POS_X, CONSTRAIN_POINT_POS_Y, CONSTRAIN_POINT_POS_Z);
	_components.push_back(_constrainPoint);

	vtkSmartPointer<vtkLineSource> line = vtkSmartPointer<vtkLineSource>::New();
	line->SetPoint1(30.0, 50.0, 6.0); 
	_deltaOrientation = FORCEPT_LENGTH * (Leap::Vector(CONSTRAIN_POINT_POS_X, CONSTRAIN_POINT_POS_Y, CONSTRAIN_POINT_POS_Z) 
							- Leap::Vector(30.0, 50.0, 6.0) ).normalized();
	line->SetPoint2(30.0+_deltaOrientation.x, 50.0+_deltaOrientation.y, 6.0+_deltaOrientation.z);

	vtkSmartPointer<vtkTubeFilter> tubeFilter = vtkSmartPointer<vtkTubeFilter>::New();
  	tubeFilter->SetInputConnection(line->GetOutputPort());
  	tubeFilter->SetRadius(FORCEPT_RAD); //default is .5
  	tubeFilter->SetNumberOfSides(16);
  	tubeFilter->Update();

  	_forcept = new GraphicalModel(tubeFilter);

	vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
	
    _forcept->getModelActor()->GetProperty()->SetAmbientColor(1, 1, 1);
	_forcept->getModelActor()->GetProperty()->SetDiffuseColor(0.6, 0.6, 0.6);
	_forcept->getModelActor()->GetProperty()->SetSpecularColor(1, 1, 1);
    _components.push_back(_forcept);


    _tipPos << 30.0, 50.0, 6.0;

}

ToolModel::~ToolModel()
{
	delete _constrainPoint;
    delete _forcept;
}

Eigen::Matrix< float , 6 , 1> ToolModel::getToolsHandlePos(Eigen::Vector3f deltaPos)
{
	Eigen::Matrix<float, 6, 1> targetPos; //start of forcept and end of end-effector
	Eigen::Matrix4f poseMat;
	_tipPos += deltaPos;	//end of forcept
	_deltaOrientation = FORCEPT_LENGTH * (Leap::Vector(CONSTRAIN_POINT_POS_X, CONSTRAIN_POINT_POS_Y, CONSTRAIN_POINT_POS_Z) 
							- Leap::Vector(_tipPos(0), _tipPos(1), _tipPos(2))).normalized();

	Eigen::Vector4f pPos, zAxis, yAxis, xAxis;
	pPos << _tipPos, 1.0;
	zAxis << _deltaOrientation.x, _deltaOrientation.y, _deltaOrientation.z, 0;
	yAxis << _deltaOrientation.x, _deltaOrientation.y, _deltaOrientation.z, 0;
	xAxis << _deltaOrientation.x, _deltaOrientation.y, _deltaOrientation.z, 0;
	
	targetPos << _tipPos(0) + _deltaOrientation.x,  _tipPos(1) + _deltaOrientation.y, _tipPos(0) + _deltaOrientation.x;
				
}	

void ToolModel::update() 
{

}




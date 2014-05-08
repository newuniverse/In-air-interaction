#include "vtkInclude.h"
#include "robotModel.h"

#define ACTUATOR_SIZE 5//cm
#define NUM_JOINTS 6
#define STEP 10;

RobotModel::RobotModel() 
{
	_endEffectorTransform = vtkSmartPointer<vtkTransform>::New();
    _endEffectorMatrix    = vtkSmartPointer<vtkMatrix4x4>::New();
    _dh_parameters        = new float*[NUM_JOINTS];
    for (int i = 0; i < NUM_JOINTS; ++i) {
    	_dh_parameters[i] = new float[4];
    }

   	vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    vtkSmartPointer<vtkCylinderSource> eef_cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    eef_cylinder->SetRadius(ACTUATOR_SIZE/5);
    eef_cylinder->SetHeight(ACTUATOR_SIZE*10);
    eef_cylinder->SetResolution(12);
    vtkSmartPointer<vtkLineSource> link_line = vtkSmartPointer<vtkLineSource>::New();
    
    _joints = new GraphicalModel*[NUM_JOINTS];
    _links = new GraphicalModel*[NUM_JOINTS-1];
    _end_Effector = new GraphicalModel(eef_cylinder);
    
    for (int i = 0; i < NUM_JOINTS; ++i) {	
    	_joints[i] = new GraphicalModel(cylinder);
      	_joints[i]->getModelActor()->RotateX(-90.0);
       	_components.push_back(_joints[i]);
    }
    for (int i = 0; i < NUM_JOINTS-1; ++i) {
        _links[i] = new GraphicalModel(link_line);
       	_links[i]->getModelActor()->RotateX(-90.0);
       	_components.push_back(_links[i]);
    }
    _end_Effector->getModelActor()->RotateX(-90.0);
    _components.push_back(_end_Effector);
}

RobotModel::~RobotModel() 
{
    delete _joints;
    delete _links;
    delete _end_Effector;
    delete _dh_parameters;
}

std::vector<GraphicalModel* > RobotModel::getModel() 
{
	return _components;
}

void RobotModel::updateDHs (float* DHs)
{
	for (int i = 0; i < NUM_JOINTS; ++i) {
		for (int j = 0; j < 4; ++j) {
			_dh_parameters[i][j] = DHs[i*4 + j];
		}
	}
}

void RobotModel::update() 
{
	Eigen::Matrix4f axis[NUM_JOINTS];
    Eigen::Matrix4f axis_eef;
  	axis[0] << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
   	_joints[0]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);

    vtkSmartPointer<vtkAlgorithm> algorithm = vtkSmartPointer<vtkAlgorithm>::New();
    vtkSmartPointer<vtkCylinderSource> srcRef = vtkSmartPointer<vtkCylinderSource>::New();

    for (int i = 1; i < NUM_JOINTS; ++i) {
        vtkSmartPointer<vtkMatrix4x4> mat = vtkSmartPointer<vtkMatrix4x4>::New();
        vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
        float d = _dh_parameters[i-1][0]; 
        float a = _dh_parameters[i-1][1];
        float alpha = MathIntegrated::degreeToRad(_dh_parameters[i-1][2]);
        float theta = MathIntegrated::degreeToRad(_dh_parameters[i-1][3]);
   		axis[i] = axis[i-1] * calcHomoTransMatrix(d, a, alpha, theta);

        MathIntegrated::convertMatrixFromTo(axis[i], mat);
		transform->SetMatrix(mat);
   		_joints[i]->getModelActor()->SetUserTransform(transform);
   		_joints[i]->getModelActor()->GetProperty()->SetColor(1.0, 0.0, 0.0);
        _joints[i]->getAxesActor()->SetUserTransform(transform);
        _joints[i]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);
        //set source property
        //joint 
        algorithm = _joints[i]->getModelActor()->GetMapper()->GetInputConnection(0, 0)->GetProducer();
        srcRef = vtkCylinderSource::SafeDownCast(algorithm);
        srcRef->SetRadius(ACTUATOR_SIZE);
        srcRef->SetHeight(ACTUATOR_SIZE*2);
        srcRef->SetResolution(12);
   	}
        //end-effector
    algorithm = _end_Effector->getModelActor()->GetMapper()->GetInputConnection(0, 0)->GetProducer();
   	srcRef = vtkCylinderSource::SafeDownCast(algorithm);
   	srcRef->SetCenter(0.0, ACTUATOR_SIZE*5.0, 0.0);

    vtkSmartPointer<vtkMatrix4x4> mat = vtkSmartPointer<vtkMatrix4x4>::New();
    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
    float d = _dh_parameters[NUM_JOINTS-1][0]; 
    float a = _dh_parameters[NUM_JOINTS-1][1];
    float alpha = MathIntegrated::degreeToRad(_dh_parameters[NUM_JOINTS-1][2]);
    float theta = MathIntegrated::degreeToRad(_dh_parameters[NUM_JOINTS-1][3]);

    // axis_eef = axis[NUM_JOINTS-1] * calcHomoTransMatrix(DHs[5*4], DHs[5*4+1], DHs[5*4+2]*M_PI/180.0, DHs[5*4+3]*M_PI/180.0);
    axis_eef = axis[NUM_JOINTS-1] * calcHomoTransMatrix(d, a, alpha, theta);
    MathIntegrated::convertMatrixFromTo(axis_eef, mat);
    _endEffectorMatrix = mat;
    transform->SetMatrix(mat);
    _endEffectorTransform = transform;
    _end_Effector->getModelActor()->SetUserTransform(transform);
    _end_Effector->getModelActor()->GetProperty()->SetColor(1.0, 0.0, 0.0);
    _end_Effector->getAxesActor()->SetUserTransform(_end_Effector->getModelActor()->GetUserTransform());
    _end_Effector->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);
}

void RobotModel::setup (float* DHs) 
{
	updateDHs(DHs);
	update();
    // calculate transform matrix
}

vtkSmartPointer<vtkTransform> RobotModel::getEndEffectorTransform() 
{
    return _endEffectorTransform;
}

vtkSmartPointer<vtkMatrix4x4> RobotModel::getEndEffectorMatrix() 
{
    return _endEffectorMatrix;
}

Eigen::Matrix4f RobotModel::calcHomoTransMatrix(float d, float a, float alpha, float theta) 
{
	Eigen::Matrix4f htm;
	htm << cos(theta), -cos(alpha)*sin(theta), sin(theta)*sin(alpha), a*cos(theta),
		   sin(theta), cos(alpha)*cos(theta), -sin(alpha)*cos(theta), a*sin(theta),
		   0,          sin(alpha),            cos(alpha),             d,
		   0,          0,                     0,                      1;
	return htm; 
}

void calcInverseKinematics(Eigen::VectorXf& goal) 
{
	if (goal.rows() !== NUM_JOINTS) {
		return 
	}
	
	
}



#include "vtkInclude.h"
#include "robotModel.h"

#define ACTUATOR_SIZE 5//cm
#define NUM_JOINTS 6
#define DOF        6
#define STEP 10.0; //todo
#define UPSILON 0.01
#define ROTATION_AJUST -90


RobotModel::RobotModel() 
{
    _current.resize(6);
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
    
    _joints = new GraphicalModel*[NUM_JOINTS+1];
    _links = new GraphicalModel*[NUM_JOINTS-1];
    
    for (int i = 0; i < NUM_JOINTS+1; ++i) {
        if (i == NUM_JOINTS) {  //end-effector
            _joints[i] = new GraphicalModel(eef_cylinder);
        } else {
            _joints[i] = new GraphicalModel(cylinder);
        }
      	_joints[i]->getModelActor()->RotateX(ROTATION_AJUST);
       	_components.push_back(_joints[i]);
    }
    for (int i = 0; i < NUM_JOINTS-1; ++i) {
        _links[i] = new GraphicalModel(link_line);
       	_links[i]->getModelActor()->RotateX(ROTATION_AJUST);
       	//_components.push_back(_links[i]); //hide links
    }
}

RobotModel::~RobotModel() 
{
    delete _joints;
    delete _links;
    delete _dh_parameters;

}

std::vector<GraphicalModel* > RobotModel::getModel() 
{
	return _components;
}

void RobotModel::updateDHs (float* DHs)
{
	for (int i = 0; i < NUM_JOINTS; ++i) {
		_dh_parameters[i][0] = DHs[i*4];
        _dh_parameters[i][1] = DHs[i*4+1];
        _dh_parameters[i][2] = MathIntegrated::degreeToRad(DHs[i*4+2]);
        _dh_parameters[i][3] = MathIntegrated::degreeToRad(DHs[i*4+3]);
	}
}


void RobotModel::calcInverseKinematics(const Eigen::VectorXf& pg) 
{
    if (pg.rows() != NUM_JOINTS) {
        return;
    }
    //temporary
    Eigen::VectorXf goal(6);
    goal = _current + pg;

    Eigen::VectorXf deltaP(DOF);
    Eigen::VectorXf deltaTheta(NUM_JOINTS);
    float deltaPos;
    _lastDeltaPos = std::numeric_limits<float>::max();
    int count(0);
    std::cout << "start Position: \n" << _current(0) <<", " << _current(1) <<", " << _current(2) <<", " << _current(3) <<", " << _current(4) <<", " << _current(5) <<std::endl;
    std::cout << "goal Position: \n" << goal(0) <<", " << goal(1) <<", " << goal(2) <<", " << goal(3) <<", " << goal(4) <<", " << goal(5) <<std::endl;

    do {
        _lastDeltaPos = deltaPos;
        for (int i = 3; i < DOF; ++i) {
            goal(i) = _current(i);
        }
        deltaP = (goal - _current);
        std::cout << count <<":\n"<<"delta Position: \n" << deltaP(0) <<", " << deltaP(1) <<", " << deltaP(2) <<", " << deltaP(3) <<", " << deltaP(4) <<", " << deltaP(5) <<std::endl;
        // deltaP /= STEP; //deltaP.norm();
        //deltaP *= STEP;
        deltaTheta = calcJacobian() * deltaP;
        std::cout << "deltaTheta: \n" << deltaTheta(0) <<", " << deltaTheta(1) <<", " << deltaTheta(2) <<", " << deltaTheta(3) <<", " << deltaTheta(4) <<", " << deltaTheta(5) <<std::endl;
        for (int i = 0; i < NUM_JOINTS; ++i) {
            _dh_parameters[i][3] += deltaTheta(i);
        }
        update();
        std::cout << "updated start Position: \n" << _current(0) <<", " << _current(1) <<", " << _current(2) <<", " << _current(3) <<", " << _current(4) <<", " << _current(5) <<std::endl;
        deltaP = (goal - _current);
        deltaPos = sqrtf(deltaP(0)*deltaP(0) + deltaP(1)*deltaP(1) + deltaP(2)*deltaP(2));
        std::cout <<count <<": delta length\n" <<deltaPos<< std::endl;
        count++;
        if(_lastDeltaPos+UPSILON+1 < deltaPos) break;
    } while (deltaPos > UPSILON);
}

Eigen::MatrixXf RobotModel::calcJacobian() 
{
    Eigen::MatrixXf jacobian(NUM_JOINTS, NUM_JOINTS);
    Eigen::Matrix4f poseMat[NUM_JOINTS+1];
    Eigen::Vector3f zBase[NUM_JOINTS+1];
    Eigen::Vector3f pBase[NUM_JOINTS+1];

    poseMat[0] << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
    zBase[0] = MathIntegrated::extractZBase(poseMat[0]);
    pBase[0] = MathIntegrated::extractPBase(poseMat[0]);
 
    for (int i = 1; i < NUM_JOINTS+1; ++i) {
        float d = _dh_parameters[i-1][0]; 
        float a = _dh_parameters[i-1][1];
        float alpha = _dh_parameters[i-1][2];
        float theta = _dh_parameters[i-1][3];
        // std::cout << "dh parameters"<<i<<": \n"<<d<<" "<<a<<" "<<alpha<<" "<<theta<<std::endl;
        poseMat[i] = poseMat[i-1] * calcHomoTransMatrix(d, a, alpha, theta);
        zBase[i] = MathIntegrated::extractZBase(poseMat[i]);
        pBase[i] = MathIntegrated::extractPBase(poseMat[i]);
    }

    Eigen::Vector3f zTemp[NUM_JOINTS+1];
    Eigen::Vector3f pTemp[NUM_JOINTS+1];
    for (int i = 0; i < NUM_JOINTS+1; ++i) {
        zTemp[i] = zBase[i];
        pTemp[i] = pBase[i];
        // std::cout << "zBase"<<i<<": \n"<<zTemp[i] << std::endl;
    }
    
    for (int i = 0; i < NUM_JOINTS; ++i) {
        pTemp[i] = zBase[i].cross((pBase[NUM_JOINTS] - pBase[i]));
        // std::cout << "joint pos"<<i<<": "<<pBase[i] << std::endl;
    }
    // std::cout << "joint pos"<<6<<": \n"<<pBase[NUM_JOINTS] << std::endl;
    
    for (int j = 0; j < NUM_JOINTS; ++j) {
        for (int i = 0; i < 3; ++i) {
            if( MathIntegrated::withinRange(-1e-5, 1e-5, pTemp[j][i])) pTemp[j][i] = 0.0;
            jacobian(i, j) = pTemp[j](i);
        }
        for (int i = 0; i < 3; ++i) {
            if( MathIntegrated::withinRange(-1e-5, 1e-5, zTemp[j+1][i]) ) zTemp[j+1][i] = 0.0;
            jacobian(i+3, j) = zTemp[j+1](i);        
        }
    }

    for (int j = 0; j < NUM_JOINTS; ++j) {
        for (int i = 0; i < 3; ++i) {
            jacobian(i, j) = pTemp[j](i);
        }
        for (int i = 0; i < 3; ++i) {
            jacobian(i+3, j) = zTemp[j+1](i);        
        }
    }
    std::cout << "Jacobian =\n" << std::endl;
    cout << jacobian << std::endl;
    Eigen::FullPivLU< Eigen::Matrix<float, 6, 6> > lu(jacobian);

    try {
        std::cout << "Jacobian* =\n" << std::endl;
        cout << lu.matrixLU().inverse() << std::endl;
        return lu.matrixLU().inverse();
    }catch (...) {
        throw 20;
    }   
    //return jacobian;
}


void RobotModel::update() 
{
	Eigen::Matrix4f poseMat[NUM_JOINTS+1];
    Eigen::Matrix4f axis_eef;
  	poseMat[0] << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
   	_joints[0]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);

    vtkSmartPointer<vtkAlgorithm> algorithm = vtkSmartPointer<vtkAlgorithm>::New();
    vtkSmartPointer<vtkCylinderSource> srcRef = vtkSmartPointer<vtkCylinderSource>::New();
    for (int i = 1; i < NUM_JOINTS+1; ++i) {
        vtkSmartPointer<vtkMatrix4x4> mat = vtkSmartPointer<vtkMatrix4x4>::New();
        vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
        float d     = _dh_parameters[i-1][0]; 
        float a     = _dh_parameters[i-1][1];
        float alpha = _dh_parameters[i-1][2];
        float theta = _dh_parameters[i-1][3];
   		poseMat[i] = poseMat[i-1] * calcHomoTransMatrix(d, a, alpha, theta);

        MathIntegrated::convertMatrixFromTo(poseMat[i], mat);
		transform->SetMatrix(mat);
   		_joints[i]->getModelActor()->SetUserTransform(transform);
   		_joints[i]->getModelActor()->GetProperty()->SetColor(1.0, 0.0, 0.0);
        _joints[i]->getAxesActor()->SetUserTransform(transform);
        _joints[i]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);
        //set source property
        //end-effector
        algorithm = _joints[i]->getModelActor()->GetMapper()->GetInputConnection(0, 0)->GetProducer();
        srcRef = vtkCylinderSource::SafeDownCast(algorithm);
        if (i == NUM_JOINTS) {
            _endEffectorMatrix = mat;
            srcRef->SetCenter(0.0, ACTUATOR_SIZE*5.0, 0.0);
            Leap::Vector endEffectorZAxis = Leap::Vector(_endEffectorMatrix->GetElement(0, 2), 
                                                 _endEffectorMatrix->GetElement(1, 2), _endEffectorMatrix->GetElement(2, 2));
    
            _current << _endEffectorMatrix->GetElement(0, 3), _endEffectorMatrix->GetElement(1, 3), _endEffectorMatrix->GetElement(2, 3),
                endEffectorZAxis.roll(), endEffectorZAxis.pitch(), endEffectorZAxis.yaw();
        } else {
            //joint 
            srcRef->SetRadius(ACTUATOR_SIZE);
            srcRef->SetHeight(ACTUATOR_SIZE*2);
            srcRef->SetResolution(12);
        }
   	}
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
    // std::cout << "dh parameters"<<": \n"<<d<<" "<<a<<" "<<alpha<<" "<<theta<<std::endl;
    // std::cout<<"homogenerous mat:\n"<<htm<<std::endl; 
	return htm; 
}

Eigen::Matrix3f RobotModel::calcRotTransMatrix(float d, float a, float alpha, float theta) 
{
    Eigen::Matrix3f rtm;
    rtm << cos(theta), -cos(alpha)*sin(theta), sin(theta)*sin(alpha),
           sin(theta), cos(alpha)*cos(theta), -sin(alpha)*cos(theta), 
           0,          sin(alpha),            cos(alpha),             
           0,          0,                     0;
    return rtm;
}

float* RobotModel::getThetas() 
{
    float thetas[NUM_JOINTS];
    for (int i = 0; i < NUM_JOINTS; ++i)
    {
        thetas[i] = _dh_parameters[i][3];
    }
    return thetas;
}



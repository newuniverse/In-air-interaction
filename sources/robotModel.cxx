#include "vtkInclude.h"
#include "robotModel.h"

using namespace ConfigIntegrated;
RobotModel::RobotModel() 
{
	_endEffectorTransform = vtkSmartPointer<vtkTransform>::New();
    _endEffectorMatrix    = vtkSmartPointer<vtkMatrix4x4>::New();
    _dh_parameters        = new double*[NUM_JOINTS];
    for (int i = 0; i < NUM_JOINTS; ++i) {
    	_dh_parameters[i] = new double[4];
    }

   	// vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    vtkCylinderSource* cylinder = vtkCylinderSource::New();
    // vtkSmartPointer<vtkCylinderSource> eef_cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    vtkCylinderSource* eef_cylinder = vtkCylinderSource::New();
    // vtkSmartPointer<vtkLineSource> link_line = vtkSmartPointer<vtkLineSource>::New();
    vtkLineSource* link_line = vtkLineSource::New();

     // Create a tube (cylinder) around the line
    vtkTubeFilter* tubeFilter = vtkTubeFilter::New();
    tubeFilter->SetInputConnection(link_line->GetOutputPort());
    tubeFilter->SetRadius(1.0); //default is .5
    tubeFilter->SetNumberOfSides(PRIMITIVE_RESOLUTION);
    tubeFilter->Update();


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
        _links[i] = new GraphicalModel(tubeFilter);
       	_links[i]->getModelActor()->RotateX(ROTATION_AJUST);
       	//_components.push_back(_links[i]); //hide links
    }
}

RobotModel::~RobotModel() 
{
    for (int i = 0; i < NUM_JOINTS+1; ++i)
    {
        delete _joints[i];
    }
    delete _joints;

    for (int i = 0; i < NUM_JOINTS-1; ++i)
    {
        delete _links[i];
    }
    delete _links;

    for (int i = 0; i < NUM_JOINTS; ++i) {
        delete _dh_parameters[i];
    }
    delete _dh_parameters;
    std::cout << "robotModel destructor called" << std::endl;
}

void RobotModel::updateDHs (double* DHs)
{
	for (int i = 0; i < NUM_JOINTS; ++i) {
		_dh_parameters[i][0] = DHs[i*4];
        _dh_parameters[i][1] = DHs[i*4+1];
        _dh_parameters[i][2] = MathIntegrated::degreeToRad(DHs[i*4+2]);
        _dh_parameters[i][3] = MathIntegrated::degreeToRad(DHs[i*4+3]);
	}
}


void RobotModel::calcInverseKinematics(const Eigen::Matrix< double , 6 , 1>& pg) 
{
    if (pg.rows() != NUM_JOINTS) {
        return;
    }
    //temporary
    Eigen::VectorXd goal(6);
    goal = _twistVector + pg;

    Eigen::VectorXd deltaP(DOF);
    Eigen::VectorXd deltaTheta(NUM_JOINTS);
    double deltaPos;
    _lastDeltaPos = std::numeric_limits<double>::max();
    int count(0);
    std::cout << "start Position: \n" << _twistVector(0) <<", " << _twistVector(1) <<", " << _twistVector(2) 
              <<", " << _twistVector(3) <<", " << _twistVector(4) <<", " << _twistVector(5) <<std::endl;
    std::cout << "goal Position: \n" << goal(0) <<", " << goal(1) <<", " << goal(2) 
              <<", " << goal(3) <<", " << goal(4) <<", " << goal(5) <<std::endl;

    do {
        _lastDeltaPos = deltaPos;
        for (int i = 3; i < DOF; ++i) {
            goal(i) = _twistVector(i);
        }
        deltaP = (goal - _twistVector);
        std::cout << count <<":\n"<<"delta Position: \n" << deltaP(0) <<", " << deltaP(1) <<", " << deltaP(2) <<", " << deltaP(3) <<", " << deltaP(4) <<", " << deltaP(5) <<std::endl;
        // deltaP /= STEP; //deltaP.norm();
        //deltaP *= STEP;
        deltaTheta = calcJacobian() * deltaP;
        std::cout << "deltaTheta: \n" << deltaTheta(0) <<", " << deltaTheta(1) <<", " << deltaTheta(2) <<", " << deltaTheta(3) <<", " << deltaTheta(4) <<", " << deltaTheta(5) <<std::endl;
        for (int i = 0; i < NUM_JOINTS; ++i) {
            _dh_parameters[i][3] += deltaTheta(i);
        }
        update();
        std::cout << "updated start Position: \n" << _twistVector(0) <<", " << _twistVector(1) <<", " << _twistVector(2) <<", " << _twistVector(3) <<", " << _twistVector(4) <<", " << _twistVector(5) <<std::endl;
        deltaP = (goal - _twistVector);
        deltaPos = sqrtf(deltaP(0)*deltaP(0) + deltaP(1)*deltaP(1) + deltaP(2)*deltaP(2));
        std::cout <<count <<": delta length\n" <<deltaPos<< std::endl;
        count++;
        // if(_lastDeltaPos+UPSILON < deltaPos) break;
    } while (deltaPos > UPSILON);
}

Eigen::MatrixXd RobotModel::calcJacobian() 
{
    Eigen::MatrixXd jacobian(NUM_JOINTS, NUM_JOINTS);
    Eigen::Matrix4d poseMat[NUM_JOINTS+1];
    Eigen::Vector3d zBase[NUM_JOINTS+1];
    Eigen::Vector3d pBase[NUM_JOINTS+1];

    poseMat[0] << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 30.0, 100.0, 0, 1;
    zBase[0] = MathIntegrated::extractZBase(poseMat[0]);
    pBase[0] = MathIntegrated::extractPBase(poseMat[0]);
 
    for (int i = 1; i < NUM_JOINTS+1; ++i) {
        double d = _dh_parameters[i-1][0]; 
        double a = _dh_parameters[i-1][1];
        double alpha = _dh_parameters[i-1][2];
        double theta = _dh_parameters[i-1][3];
        // std::cout << "dh parameters"<<i<<": \n"<<d<<" "<<a<<" "<<alpha<<" "<<theta<<std::endl;
        poseMat[i] = poseMat[i-1] * calcHomoTransMatrix(d, a, alpha, theta);
        zBase[i] = MathIntegrated::extractZBase(poseMat[i]);
        pBase[i] = MathIntegrated::extractPBase(poseMat[i]);
    }

    Eigen::Vector3d zTemp[NUM_JOINTS+1];
    Eigen::Vector3d pTemp[NUM_JOINTS+1];
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
    Eigen::FullPivLU< Eigen::Matrix<double, 6, 6> > lu(jacobian);

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
	Eigen::Matrix4d poseMat[NUM_JOINTS+1];
    Eigen::Matrix4d axis_eef;
  	poseMat[0] << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
   	_joints[0]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SCALE*2.0, ACTUATOR_SCALE*2.0, ACTUATOR_SCALE*2.0);

    vtkSmartPointer<vtkAlgorithm> algorithm = vtkSmartPointer<vtkAlgorithm>::New();
    vtkSmartPointer<vtkCylinderSource> srcRef = vtkSmartPointer<vtkCylinderSource>::New();
    for (int i = 1; i < NUM_JOINTS+1; ++i) {
        vtkSmartPointer<vtkMatrix4x4> mat = vtkSmartPointer<vtkMatrix4x4>::New();
        vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
        double d     = _dh_parameters[i-1][0]; 
        double a     = _dh_parameters[i-1][1];
        double alpha = _dh_parameters[i-1][2];
        double theta = _dh_parameters[i-1][3];
   		poseMat[i] = poseMat[i-1] * calcHomoTransMatrix(d, a, alpha, theta);

        MathIntegrated::convertMatrixFromTo(poseMat[i], mat);
		transform->SetMatrix(mat);
   		_joints[i]->getModelActor()->SetUserTransform(transform);
   		_joints[i]->getModelActor()->GetProperty()->SetColor(1.0, 0.0, 0.0);
        _joints[i]->getAxesActor()->SetUserTransform(transform);
        _joints[i]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SCALE*2.0,
                                         ACTUATOR_SCALE*2.0, ACTUATOR_SCALE*2.0);
        //set source property
        //end-effector
        algorithm = _joints[i]->getModelActor()->GetMapper()->GetInputConnection(0, 0)->GetProducer();
        // _joints[i]->getModelActor()->GetProperty()->SetCenter(0,0,_dh_parameters[i][0]/2.0);
        srcRef = vtkCylinderSource::SafeDownCast(algorithm);
        if (i == NUM_JOINTS) {
            srcRef->SetCenter(0, ACTUATOR_SCALE, 0);
            _endEffectorMatrix = mat;
            std::vector<double> rpyAngleRad;
            rpyAngleRad = MathIntegrated::poseMatToRPYAngleRad(poseMat[i]);
            
             _twistVector << _endEffectorMatrix->GetElement(0, 3), _endEffectorMatrix->GetElement(1, 3), 
                             _endEffectorMatrix->GetElement(2, 3),
                              0,0,0;// rpyAngleRad.at(0), rpyAngleRad.at(1), rpyAngleRad.at(2);
        }
        srcRef->SetRadius(ACTUATOR_SCALE);
        srcRef->SetHeight(ACTUATOR_SCALE*2);
        srcRef->SetResolution(12);
   	}
}

void RobotModel::setup (double* DHs) 
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

Eigen::Matrix4d RobotModel::calcHomoTransMatrix(double d, double a, double alpha, double theta) 
{
	Eigen::Matrix4d htm;
	htm << cos(theta), -cos(alpha)*sin(theta), sin(theta)*sin(alpha), a*cos(theta),
		   sin(theta), cos(alpha)*cos(theta), -sin(alpha)*cos(theta), a*sin(theta),
		   0,          sin(alpha),            cos(alpha),             d,
		   0,          0,                     0,                      1;

	return htm; 
}

Eigen::Matrix3d RobotModel::calcRotTransMatrix(double d, double a, double alpha, double theta) 
{
    Eigen::Matrix3d rtm;
    rtm << cos(theta), -cos(alpha)*sin(theta), sin(theta)*sin(alpha),
           sin(theta), cos(alpha)*cos(theta), -sin(alpha)*cos(theta), 
           0,          sin(alpha),            cos(alpha),             
           0,          0,                     0;
    return rtm;
}

std::vector<double> RobotModel::getThetas() 
{
    std::vector<double> thetas;
    thetas.resize(NUM_JOINTS);
    for (int i = 0; i < NUM_JOINTS; ++i)
    {
        thetas.push_back( _dh_parameters[i][3] );
    }
    return thetas;
}



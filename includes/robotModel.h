#ifndef ROBOTMODEL_H_
#define ROBOTMODEL_H_

#include "baseModel.h"
// #include "Common/MathIntegrated.h"

class RobotModel : public BaseModel
{
public://methods
    RobotModel();
    ~RobotModel();
    
    void updateDHs(double* DHS);
    std::vector<double> getThetas();
    void setup (double* DHs);
    void update();

    vtkSmartPointer<vtkTransform> getEndEffectorTransform();
    vtkSmartPointer<vtkMatrix4x4> getEndEffectorMatrix();
    void calcInverseKinematics(const Eigen::Matrix< double , 6 , 1>& goal);
private://methods
	Eigen::Matrix4d calcHomoTransMatrix(double d, double a, double alpha, double theta);
    Eigen::Matrix3d calcRotTransMatrix(double d, double a, double alpha, double theta);
    Eigen::MatrixXd calcJacobian();

public://members
	
private://members
    vtkSmartPointer<vtkTransform> _endEffectorTransform;
    vtkSmartPointer<vtkMatrix4x4> _endEffectorMatrix;
	GraphicalModel** _joints;
	GraphicalModel** _links;
    double** _dh_parameters;
    Eigen::Matrix< double , 6 , 1> _twistVector;
    double _lastDeltaPos;
protected: 
    
};

#endif
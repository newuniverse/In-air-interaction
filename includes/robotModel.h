#ifndef ROBOTMODEL_H_
#define ROBOTMODEL_H_

#include "baseModel.h"
// #include "Common/MathIntegrated.h"

class RobotModel : public BaseModel
{
public://methods
    RobotModel();
    ~RobotModel();
    
    void updateDHs(float* DHS);
    std::vector<float> getThetas();
    void setup (float* DHs);
    void update();

    vtkSmartPointer<vtkTransform> getEndEffectorTransform();
    vtkSmartPointer<vtkMatrix4x4> getEndEffectorMatrix();
    void calcInverseKinematics(const Eigen::Matrix< float , 6 , 1>& goal);
private://methods
	Eigen::Matrix4f calcHomoTransMatrix(float d, float a, float alpha, float theta);
    Eigen::Matrix3f calcRotTransMatrix(float d, float a, float alpha, float theta);
    Eigen::MatrixXf calcJacobian();

public://members
	
private://members
    vtkSmartPointer<vtkTransform> _endEffectorTransform;
    vtkSmartPointer<vtkMatrix4x4> _endEffectorMatrix;
	GraphicalModel** _joints;
	GraphicalModel** _links;
    float** _dh_parameters;
    Eigen::Matrix< float , 6 , 1> _twistVector;
    float _lastDeltaPos;
protected: 
    
};

#endif
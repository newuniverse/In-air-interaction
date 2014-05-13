#ifndef ROBOTMODEL_H_
#define ROBOTMODEL_H_

#include "graphicalModel.h"
#include "Common/MathIntegrated.h"

class RobotModel 
{
public://methods
    RobotModel();
    ~RobotModel();
    void update();
    void updateDHs(float* DHS);
    float* getThetas();
    void setup (float* DHs);
    std::vector<GraphicalModel* > getModel();
    vtkSmartPointer<vtkTransform> getEndEffectorTransform();
    vtkSmartPointer<vtkMatrix4x4> getEndEffectorMatrix();
    void calcInverseKinematics(const Eigen::VectorXf& goal);
private://methods
	Eigen::Matrix4f calcHomoTransMatrix(float d, float a, float alpha, float theta);
    Eigen::Matrix3f calcRotTransMatrix(float d, float a, float alpha, float theta);
    Eigen::MatrixXf calcJacobian();

public://members
	
private://members
	std::vector<GraphicalModel* > _components;
    vtkSmartPointer<vtkTransform> _endEffectorTransform;
    vtkSmartPointer<vtkMatrix4x4> _endEffectorMatrix;
	GraphicalModel** _joints;
	GraphicalModel** _links;
    float** _dh_parameters;
    Eigen::VectorXf _current;
    float _lastDeltaPos;
protected: 
    
};

#endif
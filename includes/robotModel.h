#ifndef ROBOTMODEL_H_
#define ROBOTMODEL_H_

#include "graphicalModel.h"
#include "math.h"
#define PI 3.141592
#include <Eigen/Dense>
class RobotModel 
{
public://methods
    RobotModel() {
    	//cylinder joint model
    	vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
        cylinder->SetRadius(2.5);//cm
        cylinder->SetHeight(5);
        cylinder->SetResolution(12);
        cylinder->Update();

        joint = new GraphicalModel*[6];
        for (int i = 0; i < 6; ++i) {	
        	joint[i] = new GraphicalModel(cylinder);
        	joint[i]->getModelActor()->RotateX(90.0);
        	joints.push_back(joint[i]);
        }
    };
    ~RobotModel() {
    	delete joint;
    };

    std::vector<GraphicalModel* > getModel() {
    	return joints;
    };

    void setup (float* DHs) {
    	Eigen::Matrix4f axis[6];
   		axis[0] << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
   		joint[0]->getAxesActor()->SetNormalizedShaftLength(5.0, 5.0, 5.0);
   		vtkSmartPointer<vtkMatrix4x4> mat = vtkSmartPointer<vtkMatrix4x4>::New();
   		for (int i = 1; i < 6; ++i) {
   			axis[i] = 
   			axis[i-1] * homogenerousTransformMatrix(DHs[(i-1)*4], DHs[(i-1)*4+1], DHs[(i-1)*4+2]*PI/180.0, DHs[(i-1)*4+3]*PI/180.0);
   			for (int k = 0; k < 4; ++k)
   			{
   				for (int j = 0; j < 4; ++j)
   				{
   					mat->SetElement(k, j, axis[i](k, j)); 
   				}
   			}
   			vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
			transform->SetMatrix(mat);
   			joint[i]->getModelActor()->SetUserTransform(transform);
   			joint[i]->getModelActor()->GetProperty()->SetColor(1.0 - i*0.15, 0.0, 0.0);
   			joint[i]->getAxesActor()->SetUserTransform(transform);
   			joint[i]->getAxesActor()->SetNormalizedShaftLength(5.0, 5.0, 5.0);
   			//todo xyz軸の長さを長くする
   		}
    };
private://methods
	Eigen::Matrix4f homogenerousTransformMatrix(float d, float a, float alpha, float theta) 
	{
		Eigen::Matrix4f htm;
		htm << cos(theta), -cos(alpha)*sin(theta), sin(theta)*sin(alpha), a*cos(theta),
			   sin(theta), cos(alpha)*cos(theta), -sin(alpha)*cos(theta), a*sin(theta),
			   0,          sin(alpha),            cos(alpha),             d,
			   0,          0,                     0,                      1;
		return htm; 
	};
public://members
	
private://members
	std::vector<GraphicalModel* > joints;
	Eigen::MatrixXf DHs;
	GraphicalModel** joint;
	//GraphicalModel** axes;

protected: 

};

#endif
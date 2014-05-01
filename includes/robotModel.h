#ifndef ROBOTMODEL_H_
#define ROBOTMODEL_H_

#include "graphicalModel.h"
#include "math.h"
#define PI 3.141592
#define ACTUATOR_SIZE 5//cm
#define NUM_JOINTS 6
#include <Eigen/Dense>
class RobotModel 
{
public://methods
    RobotModel() {
        endEffectorTransform = vtkSmartPointer<vtkTransform>::New();
    	//joint_cylinder joints model
    	vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
        vtkSmartPointer<vtkCylinderSource> eef_cylinder = vtkSmartPointer<vtkCylinderSource>::New();
        eef_cylinder->SetRadius(ACTUATOR_SIZE/5);
        eef_cylinder->SetHeight(ACTUATOR_SIZE*10);
        eef_cylinder->SetResolution(12);
        vtkSmartPointer<vtkLineSource> link_line = vtkSmartPointer<vtkLineSource>::New();
        
        joints = new GraphicalModel*[NUM_JOINTS];
        links = new GraphicalModel*[NUM_JOINTS-1];
        for (int i = 0; i < NUM_JOINTS; ++i) {	
        	joints[i] = new GraphicalModel(cylinder);
        	joints[i]->getModelActor()->RotateX(-90.0);
        	components.push_back(joints[i]);
        }
        for (int i = 0; i < NUM_JOINTS-1; ++i)
        {
        	links[i] = new GraphicalModel(link_line);
        	links[i]->getModelActor()->RotateX(-90.0);
        	components.push_back(links[i]);
        }
        end_effector = new GraphicalModel(eef_cylinder);
        end_effector->getModelActor()->RotateX(-90.0);
        components.push_back(end_effector);
    };
    ~RobotModel() {
    	delete joints;
    };

    std::vector<GraphicalModel* > getModel() {
    	return components;
    };

    void setup (float* DHs) {
    	// calculate transform matrix
        Eigen::Matrix4f axis[NUM_JOINTS];
        Eigen::Matrix4f axis_eef;
   		axis[0] << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
   		joints[0]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);

        vtkSmartPointer<vtkAlgorithm> algorithm = vtkSmartPointer<vtkAlgorithm>::New();
        vtkSmartPointer<vtkCylinderSource> srcRef = vtkSmartPointer<vtkCylinderSource>::New();

        for (int i = 1; i < NUM_JOINTS; ++i) {
            vtkSmartPointer<vtkMatrix4x4> mat = vtkSmartPointer<vtkMatrix4x4>::New();
            vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();

   			axis[i] = axis[i-1] * homogenerousTransformMatrix(DHs[(i-1)*4], DHs[(i-1)*4+1], DHs[(i-1)*4+2]*PI/180.0, DHs[(i-1)*4+3]*PI/180.0);
            for (int k = 0; k < 4; ++k)
   			{
   				for (int j = 0; j < 4; ++j)
   				{
   					mat->SetElement(k, j, axis[i](k, j)); 
   				}
   			} 
			transform->SetMatrix(mat);
   			joints[i]->getModelActor()->SetUserTransform(transform);
   			joints[i]->getModelActor()->GetProperty()->SetColor(1.0, 0.0, 0.0);
            joints[i]->getAxesActor()->SetUserTransform(transform);
            joints[i]->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);
        //set source property
            //joint 
            algorithm = joints[i]->getModelActor()->GetMapper()->GetInputConnection(0, 0)->GetProducer();
            srcRef = vtkCylinderSource::SafeDownCast(algorithm);
            srcRef->SetRadius(ACTUATOR_SIZE);
            srcRef->SetHeight(ACTUATOR_SIZE*2);
            srcRef->SetResolution(12);
   		}
        //end-effector
        algorithm = end_effector->getModelActor()->GetMapper()->GetInputConnection(0, 0)->GetProducer();
        srcRef = vtkCylinderSource::SafeDownCast(algorithm);
        srcRef->SetCenter(0.0, ACTUATOR_SIZE*5.0, 0.0);

        vtkSmartPointer<vtkMatrix4x4> mat = vtkSmartPointer<vtkMatrix4x4>::New();
        vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
        axis_eef = axis[5] * homogenerousTransformMatrix(DHs[5*4], DHs[5*4+1], DHs[5*4+2]*PI/180.0, DHs[5*4+3]*PI/180.0);
        for (int k = 0; k < 4; ++k) {
            for (int j = 0; j < 4; ++j) {
                mat->SetElement(k, j, axis_eef(k, j)); 
            }
        } 
        transform->SetMatrix(mat);
        endEffectorTransform = transform;
        end_effector->getModelActor()->SetUserTransform(transform);
        end_effector->getModelActor()->GetProperty()->SetColor(1.0, 0.0, 0.0);
        end_effector->getAxesActor()->SetUserTransform(end_effector->getModelActor()->GetUserTransform());
        end_effector->getAxesActor()->SetNormalizedShaftLength(ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0, ACTUATOR_SIZE*2.0);
    };
    vtkSmartPointer<vtkTransform> getEndEffectorTransform() {
        return endEffectorTransform;
    }

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
	std::vector<GraphicalModel* > components;
	Eigen::MatrixXf  DHs;
    vtkSmartPointer<vtkTransform> endEffectorTransform;
	GraphicalModel** joints;
    GraphicalModel*  end_effector;
	GraphicalModel** links;

protected: 

};

#endif
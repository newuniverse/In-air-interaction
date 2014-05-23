#ifndef _TOOLMODEL_
#define _TOOLMODEL_

#include "baseModel.h"
class ToolModel : public BaseModel
{
public://methods
    ToolModel();
    ~ToolModel();
    void update(vtkSmartPointer<vtkMatrix4x4> mat);
private://methods
	Eigen::Vector3d getToolsHandlePos(Eigen::Vector3d deltaPos);
public://members
	
private://members
	GraphicalModel* 			 _constrainPoint;
	GraphicalModel* 			 _forcept;
	Eigen::Vector3d              _tipPos;
	Eigen::Vector3d 			 _constrainPointPos;
	Eigen::Vector3d 			 _deltaOrientation;
	// Leap::Vector _deltaOrientation;
protected: 

};

#endif
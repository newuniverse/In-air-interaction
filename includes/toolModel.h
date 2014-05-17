#ifndef _TOOLMODEL_
#define _TOOLMODEL_

#include "baseModel.h"
class ToolModel : public BaseModel
{
public://methods
    ToolModel();
    ~ToolModel();
    Eigen::Matrix< float , 6 , 1> getToolsHandlePos(Eigen::Vector3f deltaPos);
    void update();
private://methods
	
public://members
	
private://members
	GraphicalModel* 			 _constrainPoint;
	GraphicalModel* 			 _forcept;
	Eigen::Vector3f              _tipPos;
	Leap::Vector _deltaOrientation;
protected: 

};

#endif
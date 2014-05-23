#ifndef _BASEMODEL_
#define _BASEMODEL_

#include "vtkInclude.h"
#include "graphicalModel.h"
#include "Common/MathIntegrated.h"
#include "Common/ConfigIntegrated.h"

class BaseModel 
{
public://methods
    BaseModel(){};
    ~BaseModel(){};
    std::vector<GraphicalModel* > getModel() {
    	return _components;
    };
    virtual void update(){};
private://methods
	
public://members

private://members

protected: 
	std::vector<GraphicalModel* > _components;
};
#endif
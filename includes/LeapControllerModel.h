#ifndef _LEAPCONTROLLERMODEL_
#define _LEAPCONTROLLERMODEL_

#include "graphicalModel.h"
#include "Common/MathIntegrated.h"

using namespace Leap;
class LeapControllerModel 
{
public://methods
    LeapControllerModel();
    ~LeapControllerModel();

    void setup();
    void update();
    void updateHandProps(HandList hands);

    std::vector<GraphicalModel* > getModel();
private://methods
	
public://members
	
private://members
	std::vector<GraphicalModel* > _components;
	GraphicalModel** _tips;
	GraphicalModel*  _palm;
	GraphicalModel* _innerSphere;
	GraphicalModel* _outerSphere;
protected: 

};

#endif
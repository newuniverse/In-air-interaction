#ifndef _LEAPCONTROLLERMODEL_
#define _LEAPCONTROLLERMODEL_

#include "baseModel.h"
// #include "graphicalModel.h"
// #include "Common/MathIntegrated.h"

using namespace Leap;
class LeapControllerModel : public BaseModel
{
public://methods
    LeapControllerModel();
    ~LeapControllerModel();

    void setup();
    
    void updateHandProps(HandList hands);
    void update(){return;};
private://methods
	
public://members
	
private://members
	GraphicalModel** _tips;
	GraphicalModel*  _palm;
	GraphicalModel* _innerSphere;
	GraphicalModel* _outerSphere;
protected: 
	
};

#endif
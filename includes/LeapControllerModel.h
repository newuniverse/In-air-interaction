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
	std::vector<Leap::Vector> _tipsDir;
	std::vector<int> _tipIDs;
	GraphicalModel*  _palm;
	int _palmId;
	Leap::Vector     _palmDir;
	Leap::FingerList _fingers;
	GraphicalModel* _innerSphere;
	GraphicalModel* _outerSphere;


protected: 
	
};

#endif
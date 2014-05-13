#include "vtkInclude.h"
#include "LeapControllerModel.h"

#define INNER_RANGE 10
#define OUTER_RANGE 20
#define NUM_FINGERS 5

LeapControllerModel::LeapControllerModel()
{
	vtkSmartPointer<vtkSphereSource> innerSphere = vtkSmartPointer<vtkSphereSource>::New();
    vtkSmartPointer<vtkSphereSource> outerSphere = vtkSmartPointer<vtkSphereSource>::New();
    innerSphere->SetRadius(INNER_RANGE);
  	innerSphere->SetThetaResolution(32);
  	innerSphere->SetPhiResolution(32);
    outerSphere->SetRadius(OUTER_RANGE);
    outerSphere->SetThetaResolution(32);
  	outerSphere->SetPhiResolution(32);

  	_innerSphere = new GraphicalModel(innerSphere);
  	_outerSphere = new GraphicalModel(outerSphere);

  	_innerSphere->getModelActor()->GetProperty()->SetOpacity(0.6);
  	_outerSphere->getModelActor()->GetProperty()->SetOpacity(0.35);
  	_innerSphere->getModelActor()->GetProperty()->SetColor(0.5, 0.5, 0.0);
  	_outerSphere->getModelActor()->GetProperty()->SetColor(0.5, 0.5, 0.0);

  	_components.push_back(_innerSphere);
  	_components.push_back(_outerSphere);

  	vtkSmartPointer<vtkArrowSource> arrow = vtkSmartPointer<vtkArrowSource>::New();
  	_palm = new GraphicalModel(arrow);
  	_palm->getModelActor()->GetProperty()->SetColor(0.8, 0.0, 0.8);
  	_palm->getModelActor()->SetScale(3.0);
  	_components.push_back(_palm);

  	_tips  = new GraphicalModel*[NUM_FINGERS];
  	for (int i = 0; i < NUM_FINGERS; ++i) {
  		_tips[i] = new GraphicalModel(arrow);
  		_tips[i]->getModelActor()->GetProperty()->SetColor(0.0, 0.8, 0.8);
  		_tips[i]->getModelActor()->SetScale(3.0);
  		_components.push_back(_tips[i]);
  	}
}

void LeapControllerModel::updateHandProps(HandList hands)
{
	Hand* hand = new Hand(hands.leftmost());
	Finger** fingers = new Finger*[hand->fingers().count()];
	for (int i = 0; i < hand->fingers().count(); ++i) {
		fingers[i] = new Finger(hand->fingers()[i]);
	}
	std::cout << "debug1\n" << std::endl;
	_palm->getModelActor()->SetPosition(hand->palmPosition().x/10, hand->palmPosition().y/10, hand->palmPosition().z/10);
	// _palm->getModelActor()->SetOrientation(0, 0, 0);
	// _palm->getModelActor()->SetOrientation(,0,0);
	_palm->getModelActor()->RotateX(hand->palmNormal().pitch());
	// _palm->getModelActor()->RotateY(hand->palmNormal().yaw());
	// _palm->getModelActor()->RotateZ(hand->palmNormal().roll());
	std::cout << "debug2\n" << std::endl;
	if (hand->fingers().count() <= 1) return; 
	std::cout << "debug3\n" << std::endl;

	for (int i = 0, l = hand->fingers().count(); i < l; ++i) {
		_tips[i]->getModelActor()->SetPosition(fingers[i]->tipPosition().x/10, fingers[i]->tipPosition().y/10, fingers[i]->tipPosition().z/10);
		// _tips[i]->getModelActor()->SetOrientation(0, 0, 0);
		 _tips[i]->getModelActor()->RotateX(fingers[i]->direction().pitch());
		// _tips[i]->getModelActor()->RotateY(fingers[i]->direction().yaw());
		// _tips[i]->getModelActor()->RotateZ(fingers[i]->direction().roll());
		
	}
	if (hand->fingers().count() >= NUM_FINGERS) return;
	
	for (int i = hand->fingers().count(); i < NUM_FINGERS; ++i) {
		_tips[i]->getModelActor()->SetPosition(0, 0, 0);
	}

	for (int i = 0; i < hand->fingers().count(); ++i) {
		delete fingers[i];
	}
	delete hand;
	//delete fingers;
	std::cout << "debug4\n" << std::endl;
}

LeapControllerModel::~LeapControllerModel() 
{
    delete _innerSphere;
    delete _outerSphere;
}

std::vector<GraphicalModel* > LeapControllerModel::getModel() 
{
	return _components;
}
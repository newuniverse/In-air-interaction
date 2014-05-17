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
	if (hands.isEmpty()) {
		_palm->getModelActor()->SetPosition(0,0,0);
		for (int i = 0; i < NUM_FINGERS; ++i) {
			_tips[i]->getModelActor()->SetPosition(0, 0, 0);
		}
		return;
	}

	Hand* hand = new Hand(hands.leftmost());
	Finger** fingers = new Finger*[hand->fingers().count()];
	for (int i = 0; i < hand->fingers().count(); ++i) {
		fingers[i] = new Finger(hand->fingers()[i]);
	}

	_palm->getModelActor()->SetPosition(hand->palmPosition().x/10, hand->palmPosition().y/10, hand->palmPosition().z/10);
	if (hand->fingers().isEmpty()) return; 

	for (int i = 0, l = hand->fingers().count(); i < l; ++i) {
		_tips[i]->getModelActor()->SetPosition(fingers[i]->tipPosition().x/10, fingers[i]->tipPosition().y/10, fingers[i]->tipPosition().z/10);
	}
	if (hand->fingers().count() >= NUM_FINGERS) return;

	for (int i = hand->fingers().count(); i < NUM_FINGERS; ++i) {
		_tips[i]->getModelActor()->SetPosition(0, 0, 0);
	}

	for (int i = 0; i < hand->fingers().count(); ++i) {
		delete fingers[i];
	}
	delete hand;
}

LeapControllerModel::~LeapControllerModel() 
{
    delete _innerSphere;
    delete _outerSphere;
}

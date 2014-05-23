#include "LeapControllerModel.h"

LeapControllerModel::LeapControllerModel()
{
    using namespace ConfigIntegrated; 
	// vtkSmartPointer<vtkSphereSource> innerSphere = vtkSmartPointer<vtkSphereSource>::New();
    // vtkSmartPointer<vtkSphereSource> outerSphere = vtkSmartPointer<vtkSphereSource>::New();

    vtkSphereSource* innerSphere = vtkSphereSource::New();
    vtkSphereSource* outerSphere = vtkSphereSource::New();

    innerSphere->SetRadius(I_RADIUS);
  	innerSphere->SetThetaResolution(PRIMITIVE_RESOLUTION);
  	innerSphere->SetPhiResolution(PRIMITIVE_RESOLUTION);
    outerSphere->SetRadius(O_RADIUS);
    outerSphere->SetThetaResolution(PRIMITIVE_RESOLUTION);
  	outerSphere->SetPhiResolution(PRIMITIVE_RESOLUTION);

  	_innerSphere = new GraphicalModel(innerSphere);
  	_outerSphere = new GraphicalModel(outerSphere);

  	_innerSphere->getModelActor()->GetProperty()->SetOpacity(I_OPACITY);
  	_outerSphere->getModelActor()->GetProperty()->SetOpacity(O_OPACITY);
  	_innerSphere->getModelActor()->GetProperty()->SetColor(&RED_RGB[0]);
  	_outerSphere->getModelActor()->GetProperty()->SetColor(&WHITE_RGB[0]);

  	_components.push_back(_innerSphere);
  	_components.push_back(_outerSphere);

    vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetRadius(TIP_RADIUS);
    cylinder->SetHeight(TIP_LENGTH);
    // cylinder->SetCenter(0.0, TIP_LENGTH, 0.0);

    // vtkSmartPointer<vtkSphereSource> tipSphere = vtkSmartPointer<vtkSphereSource>::New();
    vtkSphereSource* tipSphere = vtkSphereSource::New();
    tipSphere->SetRadius(TIP_RADIUS);
    tipSphere->SetThetaResolution(PRIMITIVE_RESOLUTION);
    tipSphere->SetPhiResolution(PRIMITIVE_RESOLUTION);

  	// vtkSmartPointer<vtkArrowSource> arrow = vtkSmartPointer<vtkArrowSource>::New();
  	_palm = new GraphicalModel(tipSphere);
  	_palm->getModelActor()->GetProperty()->SetColor(&BLUE_RGB[0]);
  	_components.push_back(_palm);

  	_tips  = new GraphicalModel*[NUM_FINGERS];
  	for (int i = 0; i < NUM_FINGERS; ++i) {
  		_tips[i] = new GraphicalModel(tipSphere);
  		_tips[i]->getModelActor()->GetProperty()->SetColor(&GREEN_RGB[0]);
  		// _tips[i]->getModelActor()->SetScale(3.0);
  		_components.push_back(_tips[i]);
  	}

    _tipsDir.resize(NUM_FINGERS);
    _tipIDs.resize(NUM_FINGERS);
    for (int i = 0; i < NUM_FINGERS; ++i) {
        _tipsDir.at(i) = Leap::Vector::yAxis();
        _tipIDs.at(i) = -1;
    }
    
    _palmDir = Leap::Vector::yAxis();
    _palmId = 0;
}

void LeapControllerModel::updateHandProps(HandList hands)
{
    using namespace ConfigIntegrated; 
	if (hands.isEmpty()) {
        _innerSphere->getModelActor()->SetPosition(0, 0, 0);
        _outerSphere->getModelActor()->SetPosition(0, 0, 0);
		_palm->getModelActor()->SetPosition(&ZERO_VEC3[0]);
		for (int i = 0; i < NUM_FINGERS; ++i) {
			_tips[i]->getModelActor()->SetPosition(&ZERO_VEC3[0]);
		}
		return;
	}

    if (!hands.leftmost().isValid()) return;
    if (_palmId == -1) _palmId = hands.leftmost().id();
    if (_palmId != hands.leftmost().id()) {
        _innerSphere->getModelActor()->SetPosition(hands.leftmost().palmPosition().x/10, hands.leftmost().palmPosition().y/10, hands.leftmost().palmPosition().z/10 - 10.0);
        _outerSphere->getModelActor()->SetPosition(hands.leftmost().palmPosition().x/10, hands.leftmost().palmPosition().y/10, hands.leftmost().palmPosition().z/10 - 10.0 );
    }
    _palmId = hands.leftmost().id();
	_palm->getModelActor()->SetPosition(hands.leftmost().palmPosition().x/10, hands.leftmost().palmPosition().y/10, hands.leftmost().palmPosition().z/10);
    // return;
    double roll_new = MathIntegrated::radToDegree(hands.leftmost().palmNormal().roll());
    double roll_old = MathIntegrated::radToDegree(_palmDir.roll());
    // _palm->getModelActor()->RotateX(roll_old-roll_new);
    // _palm->getModelActor()->RotateZ(roll_old-roll_new);
    _palmDir = hands.leftmost().palmNormal();
    if (hands.leftmost().fingers().isEmpty()) return;

    for (int j = 0; j < hands.leftmost().fingers().count(); ++j) {
        if (hands.leftmost().fingers()[j].isValid() && hands.leftmost().fingers()[j].isFinger()) {
                    _tips[j]->getModelActor()->SetPosition(hands.leftmost().fingers()[j].tipPosition().x/10,
                                                   hands.leftmost().fingers()[j].tipPosition().y/10, 
                                                   hands.leftmost().fingers()[j].tipPosition().z/10);
            }
    }
        /*if (hand.fingers().count() < NUM_FINGERS) {
            for (int i = hand.fingers().count(); i < NUM_FINGERS; i++) {
                _tips[i]->getModelActor()->SetPosition(&ZERO_VEC3[0]);
            }
        }*/
    
}

LeapControllerModel::~LeapControllerModel() 
{
    using namespace ConfigIntegrated; 
    delete _innerSphere;
    delete _outerSphere;
    delete _palm;
    for (int i = 0; i < NUM_FINGERS; ++i) {
        delete _tips[i];
    }
    delete _tips;
    std::cout << "uiModel destructor called" << std::endl;
}

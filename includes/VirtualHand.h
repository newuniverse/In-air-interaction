#ifndef VIRTUALHAND_H_
#define VIRTUALHAND_H_

#include "Leap.h"
#include "GraphicalObject.h"
#include "Shared.h"
#include <vector>

using namespace Leap;
//(5 fingers + 1 hand) multiply 4 
#define MAX_DETECT_OBJECTS 24 

class VirtualHand
{
public:
    VirtualHand();
    GraphicalObject*              getDeviceObject();
    GraphicalObject*              getHands();
    void                         setHands(HANDINFO* info, int numHands); 
    static Vector                        getVectorRelateToOrigo(Vector pos);
    int     getMaxNumObj(); 
   	static GraphicalObject       ray;
private:     
	static GraphicalObject       hands[MAX_DETECT_OBJECTS];
    static GraphicalObject       leapMotion;
};

#endif

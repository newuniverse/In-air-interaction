#ifndef LEAPGESTURETRAINER_H_
#define LEAPGESTURETRAINER_H_

#include "Leap/Leap.h"
#include "Leap/Shared.h"
#include <list>
#include <vector>
#include <string>
using namespace Leap;

class LeapGestureTrainer
{
public:
	LeapGestureTrainer();
	bool recordableFrame(Frame frame);
	void record(Frame frame);
	void normalize(); 	//generate several gestures from one teaching input
	void recognize();
	void save();
	bool recording;
	int frameCount;
	
	GestureList gestures;
	Gesture     detectedGesture;

	std::list<std::string> gestureNames;
	const static float minRecordingVel;
	const static int resamplePointNum;
	const static int minGestureFrames;
private:

	void correlate();
	void templateMatching();
};

#endif
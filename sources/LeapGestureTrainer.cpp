#include "LeapGestureTrainer.h"

const float LeapGestureTrainer::minRecordingVel  = 300.0f;
const int   LeapGestureTrainer::resamplePointNum = 100;
const int   LeapGestureTrainer::minGestureFrames = 10;

LeapGestureTrainer::LeapGestureTrainer() {
	
}

bool LeapGestureTrainer::recordableFrame(Frame frame) {
	return false;
}

void LeapGestureTrainer::record(Frame frame) {


}


void LeapGestureTrainer::normalize() {


}

void LeapGestureTrainer::save() {


}
void LeapGestureTrainer::recognize() {


}

void LeapGestureTrainer::correlate() {


}

void LeapGestureTrainer::templateMatching() {


}
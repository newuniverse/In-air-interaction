#include "LeapGestureTrainer.h"
#include <fstream>
#include <algorithm>

const float LeapGestureTrainer::inputMinRecordingVel  = 400.0f;
const float LeapGestureTrainer::trainedMinRecordingVel = 200.0f;
const int   LeapGestureTrainer::resamplePointNum = 20;
const int   LeapGestureTrainer::inputMinGestureFrames   = FrameMatching::requiredMinFrameCounts;
const int   LeapGestureTrainer::trainedMinGestureFrames = FrameMatching::templateFrameCounts;
const float LeapGestureTrainer::matchThreshold   = 0.6f;
const float LeapGestureTrainer::recordingMinDeltaTime_s = 0.010f;

LeapGestureTrainer::LeapGestureTrainer() {
	//matcher = new TemplateMatching();
}

/* return true if input gesture data meet the condition of recording */
bool LeapGestureTrainer::recordableFrame(const Frame &frame) {
	
	HandList hands = frame.hands();
	FingerList fingers;
	Hand hand;
	float palmVel, tipVel;
	for (int i = 0; i < hands.count(); ++i)
	{
		hand = hands[i];
		palmVel = hand.palmVelocity().magnitude();
		/*if (palmVel >= minRecordingVel) {
			return true;
		}*/

		fingers = hand.fingers();
		for (int j = 0; j < fingers.count(); ++j)
		{
			tipVel = fingers[j].tipVelocity().magnitude();
			float minRecordingVel;
			if (isTraining == true) {
				minRecordingVel = trainedMinRecordingVel;
			} else {
				minRecordingVel = inputMinRecordingVel;
			}
			if (tipVel >= minRecordingVel) {
				return true;
			}
		}
	}
	return false;
}


/*
	for frame matching
	record one frame of hand´s data 
	one frame contains palm, thumb, index, middle, ring, pinky (as many as detected)
*/
void LeapGestureTrainer::record(const Frame &currentFrame) {
	std::vector<MovingPoint> oneFrame;
	oneFrame.reserve(6);

	HandList hands = currentFrame.hands();
	Hand     rHand = hands.rightmost();
	MovingPoint palm = {rHand.palmPosition(), rHand.palmNormal().normalized(), rHand.id()};
	
	oneFrame.push_back(palm);

	int fingerNum = currentFrame.fingers().count();
	FingerList _fingers = currentFrame.fingers();
	Finger fingers[fingerNum];
	for (int i = 0; i < fingerNum; ++i)
	{
		fingers[i] = _fingers[i];
	}

	MovingPoint finger;
	int n = fingerNum <= 5 ? fingerNum : 5;
	
	//todo push back in the x larger order
	sortFingersX(fingers, fingerNum);

	for (int i = 0; i < n; ++i)
	{
		finger = { fingers[i].stabilizedTipPosition(), fingers[i].direction().normalized(), fingers[i].id() };
		oneFrame.push_back(finger);
	}
	rHandMotionFrames.push_back(oneFrame);
}

//simple bubble sort
void LeapGestureTrainer::sortFingersX(Finger fingers[], int num) {
	if (num == 0)
		return;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 1; j < num - i; ++j)
		{
			if (fingers[j].stabilizedTipPosition().x < fingers[j-1].stabilizedTipPosition().x) {
				Leap::Finger temp = fingers[j];
				fingers[j] = fingers[j-1];
				fingers[j-1] = temp;
			}
				
		}
	}
}

/*
	store the recorded frames as gesture dataset
	for frame matching
*/
void LeapGestureTrainer::store(std::string gestureName) {
	fmatcher = new FrameMatching();

	fmatcher->process(rHandMotionFrames, isTraining);

	templateGestures.push_back(fmatcher->motionFrames);
	gestureNames.push_back(gestureName);
	if(!rHandMotionFrames.empty()) rHandMotionFrames.clear();
	delete fmatcher;
}

/*
	recognize gesture by comparing input gesture with templates(stored gestures)
	for frame matching
*/
void LeapGestureTrainer::recognize() {
	fmatcher = new FrameMatching();
	fmatcher->process(rHandMotionFrames, isTraining);

	float nearest = std::numeric_limits<float>::max();
	bool  foundMatch = false;
	float distance = 0;
	int gestureNum = templateGestures.size();

	if(gestureNum < 1) return;
	std::cout << "recognizing!, trainedGestures num : "<< gestureNum << std::endl;
	
	gestureScores.clear();
	gestureScores.reserve(gestureNum);
	scoreSum = 0;
	scoreVariance = 0;
	for (int i = 0; i < gestureNum; ++i)
	{ 
		distance = fmatcher->match( fmatcher->motionFrames, templateGestures.at(i) );
		std::cout << "distance : "<< gestureNames.at(i) << " : " << distance << std::endl;
		gestureScores.push_back(distance);
		scoreSum += distance;
		if (distance < nearest) {
			nearest = distance;
			matchedGestureName = gestureNames.at(i);
			foundMatch = true;
		}
	}
	float average = scoreSum / gestureNum;
	for (int i = 0; i < gestureNum; ++i)
	{
		double temp = average - gestureScores.at(i);
		scoreVariance += (float)(temp*temp);
	}
	scoreVariance /= gestureNum;

	std::cout << "score sum : "<< scoreSum << ", score variance " << scoreVariance << std::endl;
	delete fmatcher;
}


/*correlate the value which indicate how near two gestures are (TODO)*/
float LeapGestureTrainer::correlate() {
	matcher->process(gestureData, resamplePointNum);
	//fmatcher->process()
	float nearest = std::numeric_limits<float>::max();
	bool  foundMatch = false;
	float distance(0);
	int gestureNum = trainedGestures.size();

	std::cout << "recognizing!, trainedGestures num : "<< gestureNames.size() << std::endl;
	
	gestureScores.clear();
	gestureScores.reserve(gestureNum);
	scoreSum = 0;
	scoreVariance = 0;
	for (int i = 0; i < gestureNum; ++i)
	{ 
		distance = matcher->match( matcher->formattedGesture, trainedGestures.at(i) ); 
		std::cout << "distance : "<< gestureNames.at(i) << " : " << distance << std::endl;
		gestureScores.push_back(distance);
		scoreSum += distance;
		if (distance < nearest) {
			nearest = distance;
			matchedGestureName = gestureNames.at(i);
			foundMatch = true;
		}
	}
	float average = scoreSum / gestureNum;
	for (int i = 0; i < gestureNum; ++i)
	{
		double temp = average - gestureScores.at(i);
		scoreVariance += (float)(temp*temp);
	}
	scoreVariance /= gestureNum;

	std::cout << "score sum : "<< scoreSum << ", score variance " << scoreVariance << std::endl;

	if(!foundMatch) {
		return 0.0f;
	} else {
		float max = std::max(100 * (nearest - 8.0f) / 8.0f, 0.0f);
		float min = std::min(max, 100.0f);
		std::cout << "min : "<< min << std::endl;
		return min / 100.0f;
	}
}

/*save the stored gestures in txt file
for frame matching
*/
bool LeapGestureTrainer::save(std::string fileName) {
	std::ofstream gestureFile;
	gestureFile.open(fileName, ios::trunc);
	if (gestureFile.is_open()) {
		if (templateGestures.empty()) {
			gestureFile.close();
			return false;
		}
		for (int i = 0, l = templateGestures.size(); i < l; ++i)
		{
			std::vector<std::vector<MovingPoint> > frames = templateGestures.at(i);
			std::string                            gesName = gestureNames.at(i);
			gestureFile << gesName << std::endl;
			for (int j = 0, m = frames.size(); j < m; ++j)
			{
				std::vector<MovingPoint>  oneFrame = frames.at(j);
				
				for (int k = 0, p = oneFrame.size(); k < p; ++k)
				{
					MovingPoint mp = oneFrame.at(k);
					gestureFile << mp.pos.x << " " << mp.pos.y <<" " << mp.pos.z << " "
							 << mp.dir.x << " " << mp.dir.y <<" " << mp.dir.z << " "
							 << mp.strokeID << std::endl; 

				}
				
				for (int i = oneFrame.size(); i < FrameMatching::pointNum; ++i)
				{
					MovingPoint mp = { Leap::Vector::zero(), Leap::Vector::zero(), 0 };
					gestureFile << mp.pos.x << " " << mp.pos.y <<" " << mp.pos.z << " "
							 << mp.dir.x << " " << mp.dir.y <<" " << mp.dir.z << " "
							 << mp.strokeID << std::endl;
				}
			}
		}
	} 
	gestureFile.close();
	return true;	
}


/* load the gesture txt file
	for frame matching
 */
bool LeapGestureTrainer::load(std::string path) {
	std::ifstream gestureFile;
	gestureFile.open(path);
	if (gestureFile.is_open()) {
		std::string name;
		gestureFile >> name;
		gestureNames.push_back(name);
		name.clear();

		while (!gestureFile.eof()) {
			std::vector<std::vector<MovingPoint> > frames;
			frames.reserve(trainedMinGestureFrames);
			for (int i = 0, l = trainedMinGestureFrames; i < l; ++i)
			{
				std::vector<MovingPoint> oneFrame;
				oneFrame.reserve(FrameMatching::pointNum);
				for (int j = 0, m = FrameMatching::pointNum; j < m; ++j)
				{
					MovingPoint mp;
					gestureFile >> mp.pos.x;
					gestureFile >> mp.pos.y;
					gestureFile >> mp.pos.z;
					gestureFile >> mp.dir.x;
					gestureFile >> mp.dir.y;
					gestureFile >> mp.dir.z;
					gestureFile >> mp.strokeID;
					if (mp.strokeID != 0)
						oneFrame.push_back(mp); 	
				}
				if (!oneFrame.empty())
					frames.push_back(oneFrame);
			}

			if(!frames.empty())
				templateGestures.push_back(frames);

			gestureFile >> name;
			if(!name.empty()) {
				gestureNames.push_back(name);
				name.clear();
			}
		}
	} else {
		gestureFile.close(); 
		return false; 
	}
	gestureFile.close();
	return true;
}
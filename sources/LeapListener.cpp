#include "LeapListener.h"

#include <iostream>
#include <deque>
#include <string>
#include "Leap/Shared.h"

using namespace Leap;

std::deque<int>         LeapListener::handNum;
std::deque<int>         LeapListener::fingerNum;
#define HAND_AND_FINGER_MAX_NUM 12

Leap::Vector LeapListener::getTranslation() 
{
   return vTotalMotionTranslation / 1000.0f; //scale to meter
}
Leap::Matrix LeapListener::getRotation()
{
    return mtxTotalMotionRotation;
} 
float LeapListener::getScaleFactor()
{
    return fTotalMotionScale;
}

void LeapListener::onFrame(const Leap::Controller& controller)
{
    if ( enableLeap )
    {
        const Leap::Frame frame = controller.frame();
        
        if(handNum.size() >= 10) {
            handNum.pop_front();
            fingerNum.pop_front();
        }

        handNum.push_back(frame.hands().count());
        fingerNum.push_back(frame.fingers().count());

        avg_numHands = 0;
        avg_numFingers = 0;

        for (int i = 0; i < handNum.size(); ++i)
        {
            avg_numHands    += (float)handNum.at(i);
            avg_numFingers  += (float)fingerNum.at(i);   
        }
        if(handNum.size() > 0) {
            avg_numHands /= (float)handNum.size();
            avg_numFingers /= (float)handNum.size();
        }

        update(frame);
        lastFrame = frame;
    }
}

void  LeapListener::onInit(const Leap::Controller&)
{
    std::cout << "init leap" << std::endl;
    enableLeap = false;
    status = PAUSE;
    mode = PHYSICS;    
    initParameters();
}

void LeapListener::onConnect(const Leap::Controller&)
{
    std::cout << "onConnect!" << std::endl;
} 

void LeapListener::onDisconnect(const Leap::Controller&){} 

void LeapListener::onExit(const Controller&){}

void LeapListener::onFocusGained(const Controller&){}

void LeapListener::onFocusLost(const Controller&){}

void LeapListener::switchListener() 
{
    enableLeap = !enableLeap;
    
    if (!enableLeap) {
        status = PAUSE;
        initParameters();
    } else {
        status = RUNNING;
    }
}

int LeapListener::getStatus() 
{
    return status;
}
int LeapListener::getMode()
{
    return mode;
}

float LeapListener::getFPS()
{
    return this->fUpdateFPS;
}

void LeapListener::setMode(const Frame frame) 
{
    int lastMode = mode;
    if (avg_numFingers < 1.8f && avg_numHands > 0.5f) {
            mode = SELECTION;
            initParameters();
            return;
    }
    
    if (avg_numHands > 1.5f && avg_numFingers > 4.5f) {
            mode = MANIPULATION;
            return;
    }
        
    mode = PHYSICS;
    initParameters();  
    if (mode != lastMode)
        std::cout << "current mode: " << mode << std::endl;
}

void LeapListener::getHandInfo(const Leap::Frame& frame)
{
    Leap::HandList hands = frame.hands();  
    int handNum = hands.count();

    if (handNum == 0)
        return;  
    //std::cout << "hand num: "<< handNum << std::endl;
    HANDINFO* hi;
    hi = new HANDINFO[handNum];
    int handCounter = 0;
    for ( Leap::HandList::const_iterator hit = hands.begin(); hit != hands.end(); ++hit ) {      
        //std::cout << (*hit) << std::endl;
        Leap::Hand hand = (*hit);
        hi[handCounter].palmPos = hand.palmPosition();
        hi[handCounter].palmDir = hand.direction();
        hi[handCounter].palmNor = hand.palmNormal();
        
        Leap::FingerList fingers = hand.fingers();
        //std::cout << "finger num: "<<fingers.count() << std::endl;
        int fingerCounter = 0;
        for (Leap::FingerList::const_iterator fit = fingers.begin(); fit != fingers.end(); ++fit ) {
            if(fingerCounter>=5) break;             
            Leap::Finger finger = (*fit);
            hi[handCounter].fingers[fingerCounter].tipPos = finger.stabilizedTipPosition();
            hi[handCounter].fingers[fingerCounter].tipDir = finger.direction();
            fingerCounter++;
        }       
        handCounter++;
    }
    delete hi;
    //virtualHand.setHands(hi, handNum);
}

void LeapListener::initParameters() 
{
    vTotalMotionTranslation = Leap::Vector::zero();
    mtxTotalMotionRotation = Leap::Matrix::identity();
    fTotalMotionScale = 1.0f;
    vRotationAngle = Leap::Vector::zero();
    //selectedObject = NULL;
}

/* update translation vector, rotation matrix, scale factor from every frame if mode is MANIPULATION*/

void LeapListener::updateParameters(const Frame& frame)
{
    Leap::Hand leftHand = frame.hands().leftmost();
    Leap::Hand rightHand = frame.hands().rightmost();
    
    mtxTotalMotionRotation = leftHand.rotationMatrix(lastFrame);
    vTotalMotionTranslation = rightHand.translation(lastFrame);
    
    if (leftHand.rotationProbability(lastFrame) > 0.3f) {
        vRotationAngle = Vector(leftHand.rotationAngle(lastFrame, Vector::xAxis()),
        -1*leftHand.rotationAngle(lastFrame, Vector::yAxis()), -1*leftHand.rotationAngle(lastFrame, Vector::zAxis()) );
    } 
    fTotalMotionScale = frame.scaleFactor(lastFrame);
}

/*
    
*/
void LeapListener::updateHandModelProps(const Frame& frame) 
{
    currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span =  std::chrono::duration_cast< std::chrono::duration<double> > (currentTime - lastTime);
    lastTime = currentTime; 

    if (time_span.count() < 1 / 60)
        return;

    int handNum = frame.hands().count();

    leftHand->initTransforms();
    rightHand->initTransforms();
    if (handNum == 0) return;

    Leap::Hand left = frame.hands().leftmost();
    Vector palmPos = left.stabilizedPalmPosition();
    Vector palmDir = left.direction();
    Vector palmNor = left.palmNormal();
    //std::cout<< "\norientation: " <<" X. "<< palmDir.pitch()*180.0/3.14 <<" Y. "<< palmDir.yaw()*180.0/3.14<<" Z. "<< palmNor.roll()*180.0/3.14<<std::endl;
    //double x = palmDir.pitch()*180.0/3.14;
    //double y = palmDir.yaw()*180.0/3.14;
    //double z = palmNor.roll()*180.0/3.14;
    //leftHand->getPalmModel()->getModelActor()->SetOrientation(x, y, z);
    leftHand->getPalmModel()->getModelActor()->SetPosition(palmPos.x/10, palmPos.y/10, palmPos.z/10);
    Leap::FingerList fingers = left.fingers();
    
    int counter = 0;
    for (Leap::FingerList::const_iterator fit = fingers.begin(); fit != fingers.end(); ++fit ) {    
        Leap::Finger finger = (*fit);
        Vector tipPos = finger.stabilizedTipPosition();
        leftHand->getTipsModel().at(counter)->getModelActor()->SetPosition(tipPos.x/10, tipPos.y/10, tipPos.z/10);
        counter++;
    }      

    if (handNum == 1) return; 

    Leap::Hand right = frame.hands().rightmost();
    palmPos = right.stabilizedPalmPosition();
    rightHand->getPalmModel()->getModelActor()->SetPosition(palmPos.x/10, palmPos.y/10, palmPos.z/10);

    fingers = right.fingers();
    counter = 0;
    for (Leap::FingerList::const_iterator fit = fingers.begin(); fit != fingers.end(); ++fit ) {
        Leap::Finger finger = (*fit);
        Vector tipPos = finger.stabilizedTipPosition();
        rightHand->getTipsModel().at(counter)->getModelActor()->SetPosition(tipPos.x/10, tipPos.y/10, tipPos.z/10);
        counter++;
    }      
}


/*main update function*/
void LeapListener::update(const Leap::Frame frame)
{
    //renderMutex.lock();
    if(!frame.isValid())
        return;

    updateParameters(frame);
    updateHandModelProps(frame);
    
    getHandInfo(frame);
    
    setMode(frame);
    
    switch (mode) {
        case SELECTION:
            //updateRayHitObject(frame);
            break;
        case MANIPULATION:
            //updateParameters(frame);
            break;
        case PHYSICS:
            //updateGestures(frame);
            break;
    }
    //renderMutex.unlock();
}

/* calculate frame rates from leapmotion */
void LeapListener::calcDataFPS()
{
    currentTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span =  std::chrono::duration_cast< std::chrono::duration<double> > (currentTime - lastTime);
    
    lastTime = currentTime;    

    float fUpdateDT = time_span.count();
    this->fUpdateFPS = (fUpdateDT > 0) ? 1.0/fUpdateDT : 0.0;
    std::cout << "data FPS: " << fUpdateFPS <<std::endl;
}





bool LeapListener::checkSameSign(float* nums, int size){
    if(nums[0] > 0.0)
        if(nums[1] > 0.0)
            if(nums[3] > 0.0)
                if(nums[4] > 0.0)
                    return true;
    if(nums[0] < 0.0)
        if(nums[1] < 0.0)
            if(nums[3] < 0.0)
                if(nums[4] < 0.0)
                    return true;

    return false;
}
/*update selected object if mode is SELECTION*/
/*
void LeapListener::updateRayHitObject(const Frame& frame)
{
    selectedObject = NULL;
    Leap::Vector tipPos = VirtualHand::getVectorRelateToOrigo(frame.fingers().frontmost().stabilizedTipPosition());
    Leap::Vector tipDir = frame.fingers().frontmost().direction().normalized();
    tipDir = Vector(tipDir.x, -tipDir.z, tipDir.y); 
    std::deque<GraphicalObject*> tempSelceted;
    
    for (int j = 0; j < sceneObjects.size(); j++)
    {
        Leap::Vector* go = sceneObjects.at(j)->getBoundingBox();
        Vector vec[8]; 
        for (int i = 0; i < 8; ++i)
        {
            vec[i] = go[i] - tipPos;
        }
        float sign[4];
        sign[0] = (vec[0].cross(vec[3])).dot(tipDir);
        sign[1] = (vec[3].cross(vec[7])).dot(tipDir);
        sign[2] = (vec[7].cross(vec[4])).dot(tipDir);
        sign[3] = (vec[4].cross(vec[0])).dot(tipDir);

        if(checkSameSign(sign, 4) == true) {
            tempSelceted.push_back(sceneObjects.at(j));
        } else {
            sign[0] = (vec[3].cross(vec[0])).dot(tipDir);
            sign[1] = (vec[0].cross(vec[1])).dot(tipDir);
            sign[2] = (vec[1].cross(vec[2])).dot(tipDir);
            sign[3] = (vec[2].cross(vec[3])).dot(tipDir);
            
            if(checkSameSign(sign, 4) == true) {
                tempSelceted.push_back(sceneObjects.at(j));
            } else {
                sign[0] = (vec[4].cross(vec[7])).dot(tipDir);
                sign[1] = (vec[7].cross(vec[6])).dot(tipDir);
                sign[2] = (vec[6].cross(vec[5])).dot(tipDir);
                sign[3] = (vec[5].cross(vec[4])).dot(tipDir);
            
                if(checkSameSign(sign, 4) == true) {
                    tempSelceted.push_back(sceneObjects.at(j));
                } else {
                    sign[0] = (vec[0].cross(vec[4])).dot(tipDir);
                    sign[1] = (vec[4].cross(vec[5])).dot(tipDir);
                    sign[2] = (vec[5].cross(vec[1])).dot(tipDir);
                    sign[3] = (vec[1].cross(vec[0])).dot(tipDir);
            
                    if(checkSameSign(sign, 4) == true) {
                        tempSelceted.push_back(sceneObjects.at(j));
                    } else {
                        sign[0] = (vec[7].cross(vec[3])).dot(tipDir);
                        sign[1] = (vec[3].cross(vec[2])).dot(tipDir);
                        sign[2] = (vec[2].cross(vec[6])).dot(tipDir);
                        sign[3] = (vec[6].cross(vec[7])).dot(tipDir);
            
                        if(checkSameSign(sign, 4) == true) {
                            tempSelceted.push_back(sceneObjects.at(j));
                        } else {
                            sign[0] = (vec[1].cross(vec[5])).dot(tipDir);
                            sign[1] = (vec[5].cross(vec[6])).dot(tipDir);
                            sign[2] = (vec[6].cross(vec[2])).dot(tipDir);
                            sign[3] = (vec[2].cross(vec[1])).dot(tipDir);
            
                            if(checkSameSign(sign, 4) == true) {
                                tempSelceted.push_back(sceneObjects.at(j));
                            }
                
                        }
                
                    }
                
                }
            }
        }

        if(tempSelceted.size()==2) {
            if (tempSelceted.at(0)->getPosition().y < tempSelceted.at(1)->getPosition().y) {
                tempSelceted.pop_back();
            } else {
                tempSelceted.pop_front();
            }
        }      
    }
    if (tempSelceted.size() > 0) {
        selectedObject = tempSelceted.at(0);
    } else {
        selectedObject = NULL;
    }
}
*/

/*
void LeapListener::updateGestures(const Frame& frame) 
{
    LeapGestureTrainer* temp = gTrainer;
    if(temp->recordableFrame(frame)) {
        
        if( !temp->recording ) {
            temp->recording = true;
            temp->frameCount = 0;
            //temp->detectedGesture = NULL;
        }
        temp->frameCount++;
        temp->record(frame);

    } else if (temp->recording) {
        temp->recording = false;
        std::cout << "recording stopped!" << std::endl; 

        if (temp->frameCount >= LeapGestureTrainer::minGestureFrames) {
            std::string gName; //=
            if (gName!="") {
                temp->save();
            } else {
                temp->recognize();
            }
        }
    }
}
*/


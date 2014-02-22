#ifndef LEAPLISTENER_H_
#define LEAPLISTENER_H_

#include "Leap.h"

#include "vtkInclude.h" 

#include <string>
#include <chrono>
#include <ratio>
#include <ctime>
#include <mutex>
#include <deque>

using namespace Leap;

class LeapListener : public Listener 
{
public:
    LeapListener();
    virtual void         onInit(const Controller&);
    virtual void         onConnect(const Controller&);
    virtual void         onDisconnect(const Controller&);
    virtual void         onExit(const Controller&);
    virtual void         onFrame(const Controller&);
    virtual void         onFocusGained(const Controller&);
    virtual void         onFocusLost(const Controller&);
    enum STATUS {
        PAUSE = 0,
        RUNNING = 1
    };
    enum MODE {
        SELECTION = 1,
        MANIPULATION = 2,
        PHYSICS = 3
    };

    struct FINGERINFO {
        Leap::Vector tipPos;
        Leap::Vector tipDir;
    };

    struct HANDINFO {
        Leap::Vector palmPos;
        Leap::Vector palmNor;
        Leap::Vector palmDir;
        FINGERINFO fingers[5];
    };  

    void                  switchListener();
    int                   getStatus();
    int                   getMode();
    Vector                getTranslation();
    Matrix                getRotation();
    float                 getScaleFactor();
    float                 getFPS();

    //GraphicalObject*      getSelectedObject();
    
    //LeapGestureTrainer*   gTrainer;
    //VirtualHand           virtualHand;
    HANDINFO*             hand_info;
    std::mutex            renderMutex;

    //void                  setGraphicalObjectsInScene (std::vector<GraphicalObject*> go );  
    vtkActor* _actor;
    void addActor(vtkActor* actor) {
        _actor = actor;
    }
private:
    std::chrono::high_resolution_clock::time_point           currentTime;
    std::chrono::high_resolution_clock::time_point           lastTime;

    enum STATUS           status;
    enum MODE             mode;
   
    Frame                 lastFrame;
    bool                  enableLeap;
    Matrix                mtxTotalMotionRotation;
    Vector                vTotalMotionTranslation;
    float                 fTotalMotionScale;

    float                 fUpdateFPS;
    virtual void                  update(const Frame frame);
    void                  setMode(const Frame frame);
    void                  initParameters();
    void                  updateParameters(const Frame& frame);
    void                  updateRayHitObject(const Frame& frame);
    void                  updateGestures(const Frame& frame);
    void                  getHandInfo(const Frame& frame);
    void                  calcDataFPS();
    void                  createBresenhamLine();
    bool                  checkSameSign(float* nums, int size);
    
    static std::deque<int>         handNum;
    static std::deque<int>         fingerNum;
    float                          avg_numHands;
    float                          avg_numFingers;
};
#endif

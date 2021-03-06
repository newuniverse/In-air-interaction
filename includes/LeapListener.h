#ifndef LEAPLISTENER_H_
#define LEAPLISTENER_H_

#include "Leap/Leap.h"
#include "graphicalModel.h"
#include "Leap/Shared.h"

#include "LeapControllerModel.h"
#include "ToolModel.h"
#include "RobotModel.h"

#include <string>
#include <chrono>
#include <ratio>
#include <ctime>
#include <mutex>
#include <deque>

using namespace Leap;
class HandModel;

class LeapListener : public Listener 
{
public://method 
    LeapListener(LeapControllerModel& controller, ToolModel& tool, RobotModel& robot, vtkSmartPointer<vtkCamera> camera);
    virtual void         onInit(const Controller&);
    virtual void         onConnect(const Controller&);
    virtual void         onDisconnect(const Controller&);
    virtual void         onExit(const Controller&);
    virtual void         onFrame(const Controller&);
    virtual void         onFocusGained(const Controller&);
    virtual void         onFocusLost(const Controller&);
    

    void                  switchListener();
    int                   getStatus();
    int                   getMode();
    Vector                getTranslation();
    Matrix                getRotation();
    double                 getScaleFactor();
    double                 getFPS();

    //GraphicalObject*      getSelectedObject();
    //LeapGestureTrainer*   gTrainer;
    //VirtualHand           virtualHand;

    GraphicalModel* getLeapDeviceModel() {
        return leapDeviceModel;
    }

    GraphicalModel* getKeystoneFrameModel() {
        return keystoneFrame;
    }

    HandModel* getRightHand() {
        return rightHand;
    }
    HandModel* getLeftHand() {
        return leftHand;
    }
    void addActor(vtkSmartPointer<vtkActor> actor) {
        _actor = actor;
    }
private://method
    void                  setMode(const Frame frame);
    void                  initParameters();
    void                  updateParameters(const Frame& frame);
    void                  updateRayHitObject(const Frame& frame);
    void                  updateGestures(const Frame& frame);
    void                  getHandInfo(const Frame& frame);
    void                  calcDataFPS();
    void                  createBresenhamLine();
    bool                  checkSameSign(double* nums, int size);
    virtual void          update(const Frame frame);
    void                  updateHandModelProps(const Frame& frame);

    

public://arguments
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
    HANDINFO*             hand_info;
    std::mutex            renderMutex;
    

    
private://members
    vtkSmartPointer<vtkCamera> _camera;
    LeapControllerModel& controllerModel;
    ToolModel&           toolModel;
    RobotModel&          robotModel;
    HandModel* leftHand;
    HandModel* rightHand;
    GraphicalModel* leapDeviceModel;
    GraphicalModel* keystoneFrame;

    vtkSmartPointer<vtkActor> _actor; 

    std::chrono::high_resolution_clock::time_point           currentTime;
    std::chrono::high_resolution_clock::time_point           lastTime;

    enum STATUS           status;
    enum MODE             mode;
   
    Frame                 lastFrame;
    bool                  enableLeap;
    Matrix                mtxTotalMotionRotation;
    Vector                vTotalMotionTranslation;
    double                 fTotalMotionScale;
    Vector                vRotationAngle;

    double                 fUpdateFPS;    
    static std::deque<int>         handNum;
    static std::deque<int>         fingerNum;
    double                          avg_numHands;
    double                          avg_numFingers;
};

class HandModel {
public://functions
    HandModel() {
        // vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
        vtkSphereSource* sphere = vtkSphereSource::New();
        sphere->SetRadius(TIP_SPHERE_SIZE);//0.5cm
        
        palm = new GraphicalModel(sphere);
        tips.reserve(5);
        for (int i = 0; i < 5; ++i)
        {
            GraphicalModel* tip = new GraphicalModel(sphere);
            tips.push_back(tip);
        }
    }

    void initTransforms() {
        palm->getModelActor()->SetPosition(0.0, 0.0, 0.0);
        for (int i = 0, n = tips.size(); i < n; ++i)
        {
            tips.at(i)->getModelActor()->SetPosition(0.0, 0.0, 0.0);
        }
    }

    GraphicalModel* getPalmModel() {
        return palm;
    }

    std::vector<GraphicalModel*> getTipsModel() {
        return tips;
    }

private: //members
    GraphicalModel* palm;
    std::vector<GraphicalModel*> tips;
};
#endif

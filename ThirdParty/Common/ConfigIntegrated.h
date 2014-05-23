#ifndef CONFIGINTEGRATED_H_
#define CONFIGINTEGRATED_H_
namespace ConfigIntegrated
{
// common
	// colors
static double YELLOW_RGB[] = {0.5, 0.5, 0.5}; 
static double RED_RGB[] = {1.0, 0.0, 0.0};
static double GREEN_RGB[] = {0.0, 1.0, 0.0};
static double BLUE_RGB[] = {0.0, 0.0, 1.0};
static double WHITE_RGB[] = {1.0, 1.0, 1.0};
static const int PRIMITIVE_RESOLUTION = 64;
	// vectors
static double ZERO_VEC3[] = {0.0, 0.0, 0.0};

// Leap Common
static const int NUM_FINGERS = 5;
static const double FPS = 30.0;
	// leap controller model

static const double I_OPACITY = 0.65;
static const double O_OPACITY = 0.35;
static const double I_RADIUS = 10;
static const double O_RADIUS = 20;
static const double TIP_LENGTH = 5.0;
static const double TIP_RADIUS = 0.6;
	// tool model
static double CONSTRAIN_POINT_POS[] = {22.0, 45.0, 15.0};
static double FORCEPT_DOWN_END_INIT_POS[] = {30.0, 50.0, 6.0};
static const double CONSTRAIN_POINT_RAD = 1.5;
static const double FORCEPT_LENGTH = 40.0;
static const double FORCEPT_RADIUS = 0.15;

static double AMBIENT[] = {1.0, 1.0, 1.0};
static double DIFFUSE[] = {0.6, 0.6, 0.6};
static double SPECULAR[] = {1.0, 1.0, 1.0};

// robot model
static const double DELTA_MOVE = 0.1;
static const double UPSILON    = 0.05;// delta_move / 5
static const double ACTUATOR_SCALE = 2.0;
static const unsigned int NUM_JOINTS = 6;
static const unsigned int DOF = 6;
static const double ROTATION_AJUST = -90.0;

//main Window
static const double ENDOSCOPE_FOCAL_DISTANCE = 1.0;
static const double ROBOT_X_DISPLACEMENT = 30.0;
static const double ROBOT_Y_DISPLACEMENT = 20.0;

}



#endif
#ifndef SHARED_H_
#define SHARED_H_
#include <cstring>

#include "Leap.h"

#define TIP_SPHERE_SIZE 0.5//cm

namespace MathCommon {
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

struct Point {
    float x;
    float y;
    float z;
    int strokeID;
};

struct Vec3 {
    float x, y, z;
};
struct Vec3Int {
    int x, y, z;
};

struct Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    float m[16];
static Mat4 matrixMultiplication(Mat4 a, Mat4 b){
	
    Mat4 m;
    memset(&m.m, 0, sizeof(m));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
	    for(int k=0;k<4;k++){
	    	m.m[i+4*j] += a.m[i+4*k]*b.m[k+4*j];
            }
        }
    }
    return m;
    }

};

static void ErrorPlace(int i = 1) {
    std::cout << "\nerror " << i <<std::endl;
}

struct KeystoneSetting{
    float k[8];
};

}
#endif

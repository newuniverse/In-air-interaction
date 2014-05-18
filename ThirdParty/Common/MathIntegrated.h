#ifndef MATHINTEGRATED_H_
#define MATHINTEGRATED_H_

#include "Leap/Leap.h"
#include <Eigen/Dense>
#include <vtkMatrix4x4.h>
#include <math.h>

namespace MathIntegrated {
static void convertMatrixFromTo(Eigen::Matrix4f& from, vtkSmartPointer<vtkMatrix4x4> to) 
{
    if (from.rows() != 4 && from.cols() != 4) 
        return;

    for (int k = 0; k < 4; ++k) {
        for (int j = 0; j < 4; ++j) {
            to->SetElement(k, j, from(k, j)); 
        }
    } 
}

static void convertMatrixFromTo(vtkSmartPointer<vtkMatrix4x4> from, Eigen::Matrix4f& to) 
{
    if (to.rows() != 4 && to.cols() != 4) 
        return;

    for (int k = 0; k < 4; ++k) {
        for (int j = 0; j < 4; ++j) {
            to(k, j) = from->GetElement(k, j);
        }
    } 
}

static Eigen::Vector3f extractZBase(const Eigen::MatrixXf& mat)
{
    //if (mat.cols() < 3 || mat.rows() < 3) return Eigen::Vector3f::Zero();
    Eigen::Vector3f zBase;
    zBase << mat(0, 2), mat(1, 2), mat(2, 2);
    return zBase;
}

static Eigen::Vector3f extractPBase(const Eigen::MatrixXf& mat)
{
    //if (mat.cols() < 4 || mat.rows() < 4) return Eigen::Vector3f::Zero();
    Eigen::Vector3f pBase;
    pBase << mat(0, 3), mat(1, 3), mat(2, 3);
    return pBase;
}

static void convertMatrixFromTo(Leap::Matrix& from, vtkSmartPointer<vtkMatrix4x4> to)
{
    return;
}

static void convertMatrixFromTo(Leap::Matrix& from, Eigen::Matrix4f& to)
{
    return;
}

static float degreeToRad(float degree) 
{
    return degree * M_PI/180;
}
static float radToDegree(float rad) 
{
    return rad * 180.0 / M_PI;
}

static bool withinRange(float min, float max, float target)
{
    if (target > min && target < max) {
        return true;
    } else {
        return false;
    }
}

static std::vector<float> poseMatToRPYAngleRad(const Eigen::Matrix4f& poseMat)
{
    std::vector<float> rpyAngles;
    rpyAngles.resize(3);
    float minusSinPitch = poseMat(2, 0);
    if (minusSinPitch == 1) {
        rpyAngles.push_back( atan2(-poseMat(0, 1), poseMat(1, 1)) - 0.0 );
        rpyAngles.push_back(-M_PI/2.0);
        rpyAngles.push_back(0.0);
        return rpyAngles;
    }
    if (minusSinPitch == -1) {
        rpyAngles.push_back( atan2(-poseMat(0, 1), poseMat(1, 1)) + 0.0 );
        rpyAngles.push_back(M_PI/2.0);
        rpyAngles.push_back(0.0);
        return rpyAngles;
    }
    float beta1 = atan2(-poseMat(2, 0), sqrtf(1.0 - poseMat(2, 0)*poseMat(2, 0)));
    float beta2 = atan2(-poseMat(2, 0), -sqrtf(1.0 - poseMat(2, 0)*poseMat(2, 0)));
    float beta;
    abs(beta1) < abs(beta2) ? beta = beta1 : beta = beta2;
    float cosBeta = cos(beta);
    rpyAngles.push_back(atan2(poseMat(2, 1)/cosBeta, poseMat(2, 2)/cosBeta));
    rpyAngles.push_back(beta);
    rpyAngles.push_back(atan2(poseMat(1, 0)/cosBeta, poseMat(0, 0)/cosBeta));
    return rpyAngles;
}

}
#endif

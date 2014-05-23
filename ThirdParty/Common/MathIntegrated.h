#ifndef MATHINTEGRATED_H_
#define MATHINTEGRATED_H_

#include "Leap/Leap.h"
#include <Eigen/Dense>
#include <vtkMatrix4x4.h>
#include <math.h>

namespace MathIntegrated {

static void convertMatrixFromTo(Leap::Matrix& from, vtkSmartPointer<vtkMatrix4x4> to)
{

    to->SetElement(0, 0, from.xBasis.x); 
    to->SetElement(1, 0, from.xBasis.y); 
    to->SetElement(2, 0, from.xBasis.z);  
    to->SetElement(3, 0, 0.0);
    to->SetElement(0, 1, from.yBasis.x); 
    to->SetElement(1, 1, from.yBasis.y); 
    to->SetElement(2, 1, from.yBasis.z);  
    to->SetElement(3, 1, 0.0);
    to->SetElement(0, 2, from.zBasis.x); 
    to->SetElement(1, 2, from.zBasis.y); 
    to->SetElement(2, 2, from.zBasis.z);  
    to->SetElement(3, 2, 0.0);
    to->SetElement(0, 3, 22.0); 
    to->SetElement(1, 3, 45.0); 
    to->SetElement(2, 3, 15.0);  
    to->SetElement(3, 3, 1.0);
    // return to;
}


static void convertMatrixFromTo(Eigen::Matrix4d& from, vtkSmartPointer<vtkMatrix4x4> to) 
{
    if (from.rows() != 4 && from.cols() != 4) 
        return;

    for (int k = 0; k < 4; ++k) {
        for (int j = 0; j < 4; ++j) {
            to->SetElement(k, j, from(k, j)); 
        }
    } 
}

static void convertMatrixFromTo(vtkSmartPointer<vtkMatrix4x4> from, Eigen::Matrix4d& to) 
{
    if (to.rows() != 4 && to.cols() != 4) 
        return;

    for (int k = 0; k < 4; ++k) {
        for (int j = 0; j < 4; ++j) {
            to(k, j) = from->GetElement(k, j);
        }
    } 
}

static Eigen::Vector3d extractZBase(const Eigen::MatrixXd& mat)
{
    //if (mat.cols() < 3 || mat.rows() < 3) return Eigen::Vector3d::Zero();
    Eigen::Vector3d zBase;
    zBase << mat(0, 2), mat(1, 2), mat(2, 2);
    return zBase;
}

static Eigen::Vector3d extractPBase(const Eigen::MatrixXd& mat)
{
    //if (mat.cols() < 4 || mat.rows() < 4) return Eigen::Vector3d::Zero();
    Eigen::Vector3d pBase;
    pBase << mat(0, 3), mat(1, 3), mat(2, 3);
    return pBase;
}


static void convertMatrixFromTo(Leap::Matrix& from, Eigen::Matrix4d& to)
{
    return;
}

static double degreeToRad(double degree) 
{
    return degree * M_PI/180;
}
static double radToDegree(double rad) 
{
    return rad * 180.0 / M_PI;
}

static bool withinRange(double min, double max, double target)
{
    if (target > min && target < max) {
        return true;
    } else {
        return false;
    }
}

static std::vector<double> poseMatToRPYAngleRad(const Eigen::Matrix4d& poseMat)
{
    std::vector<double> rpyAngles;
    rpyAngles.resize(3);
    double minusSinPitch = poseMat(2, 0);
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
    double beta1 = atan2(-poseMat(2, 0), sqrtf(1.0 - poseMat(2, 0)*poseMat(2, 0)));
    double beta2 = atan2(-poseMat(2, 0), -sqrtf(1.0 - poseMat(2, 0)*poseMat(2, 0)));
    double beta;
    abs(beta1) < abs(beta2) ? beta = beta1 : beta = beta2;
    double cosBeta = cos(beta);
    rpyAngles.push_back(atan2(poseMat(2, 1)/cosBeta, poseMat(2, 2)/cosBeta));
    rpyAngles.push_back(beta);
    rpyAngles.push_back(atan2(poseMat(1, 0)/cosBeta, poseMat(0, 0)/cosBeta));
    return rpyAngles;
}

// static Eigen::Vector3d CartesianToPolar(Eigen::Vector3d cartesian) 
// {
    // double r = sqrt(cartesian(0)*cartesian(0) + cartesian(1)*cartesian(1) + cartesian(2)*cartesian(2));
    // double theta = acos()
// }

}
#endif

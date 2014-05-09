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
    if (mat.cols() < 3 || mat.rows() < 3) return Eigen::Vector3f::Zero();
    Eigen::Vector3f zBase;
    zBase << mat(0, 2), mat(1, 2), mat(2, 2);
    return zBase;
}

static Eigen::Vector3f extractPBase(const Eigen::MatrixXf& mat)
{
    if (mat.cols() < 4 || mat.rows() < 4) return Eigen::Vector3f::Zero();
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
    return degree * M_PI/180.0;
}
static float radToDegree(float rad) 
{
    return rad * 180.0 / M_PI;
}


}
#endif

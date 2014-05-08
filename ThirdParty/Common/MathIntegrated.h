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

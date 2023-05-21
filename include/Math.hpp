#ifndef QUICKMAFS_H_INCLUDED

#define QUICKMAFS_H_INCLUDED

#include "Shape.hpp"

#include "Vector3D.hpp"
#include "Matrix3x3.hpp"

Vector3D convertAlignmentAngleToVector(const Shape*);
Matrix3x3 convertOrientationAngleToMatrix(const Shape*);

#endif
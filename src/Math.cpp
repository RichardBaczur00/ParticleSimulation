#include "Math.hpp"

#include "Constants.h"

#include <cmath>

Vector3D convertAlignmentAngleToVector(const Shape* shape) {
    float alignmentAngle = shape->getAlignment();
    float alignmentAngleRad = alignmentAngle * (PI / STRAIGHT_ANGLE);

    float alignmentX = std::cos(alignmentAngleRad);
    float alignmentY = std::sin(alignmentAngleRad);

    float alignmentZ = 0.0f;

    return Vector3D(alignmentX, alignmentY, alignmentZ);
}

Matrix3x3 convertOrientationAngleToMatrix(const Shape* shape) {
    float orientationAngle = shape->getOrientation();

    float orientationAngleRad = orientationAngle * (PI / STRAIGHT_ANGLE);

    Matrix3x3 rotationMatrix;
    rotationMatrix.setRotationZ(orientationAngleRad);
    return rotationMatrix;
}
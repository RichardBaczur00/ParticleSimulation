#include "Shape.hpp"

#include "Constants.h"
#include "Math.hpp"

Shape::Shape(float _alignment, float _orientation) : alignment(_alignment), orientation(_orientation) {}

Cube::Cube(float _alignment, float _orientation, double _side) : 
    Shape(_alignment, _orientation), side(_side) {}

Sphere::Sphere(float _alignment, float _orientation, double _radius) : 
    Shape(_alignment, _orientation), radius(_radius) {}

Cylinder::Cylinder(float _alignment, float _orientation, double _radius, double _height) : 
    Shape(_alignment, _orientation), radius(_radius), height(_height) {}

float Shape::getAlignment() const {
    return this->alignment;
}

float Shape::getOrientation() const {
    return this->orientation;
}

void Shape::setAlignment() {
    this->alignment = alignment;
}

void Shape::setOrientation() {
    this->orientation = orientation;
}

float Cube::calculateEffectiveCrossSectionalArea() const {
    return side * side;
}

double Cube::getDragCoefficient(const Medium& medium) const {
    if (medium == Air) {

    }
}

float Sphere::calculateEffectiveCrossSectionalArea() const {
    return PI * (radius * radius) * std::sin(alignment);
}

float Cylinder::calculateEffectiveCrossSectionalArea() const {
    return PI * (radius * radius) * std::abs(std::cos(alignment - orientation)) * height;
}

Vector3D Cylinder::calculateCylinderAxis() const {
    Vector3D cylinderAxis = convertAlignmentAngleToVector(static_cast<const Shape*>(this));
    cylinderAxis = convertOrientationAngleToMatrix(static_cast<const Shape*>(this)) * cylinderAxis;
    return cylinderAxis.normalize();
}

bool Cylinder::checkAlignmentWithFlow(Vector3D flowDirection, double& angle) const {
    flowDirection.normalize();
    Vector3D cylinderAxis = this->calculateCylinderAxis();
    if (&angle == nullptr)
        return cylinderAxis.dotProduct(flowDirection) >= FLOW_DIRECTION_THRESHOLD;
    else {
        double dot = cylinderAxis.dotProduct(flowDirection);

        angle = std::acos(dot) * (STRAIGHT_ANGLE / PI);

        return dot >= FLOW_DIRECTION_THRESHOLD;
    }
}
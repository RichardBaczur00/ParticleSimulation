#ifndef SHAPE_H_INCLUDED

#define SHAPE_H_INCLUDED

#include "Particle.hpp"

class Shape {
protected:
    Shape(float, float);

    float alignment;
    float orientation;

public:
    float getAlignment() const;
    float getOrientation() const;
    
    void setAlignment();
    void setOrientation();

    virtual float calculateEffectiveCrossSectionalArea() const = 0;
};

class Sphere : public Shape {
private:
    double radius;

public:
    Sphere(float, float, double);

    float calculateEffectiveCrossSectionalArea() const override;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(float, float, double, double);

    float calculateEffectiveCrossSectionalArea() const override;
    Vector3D calculateCylinderAxis() const;
    bool checkAlignmentWithFlow(Vector3D, double&) const;
};

class Cube : public Shape {
private:
    double side;

public:
    Cube(float, float, double);

    float calculateEffectiveCrossSectionalArea() const override;
};

#endif
#include "Particle.hpp"
#include "Shape.hpp"
#include "Vector3D.hpp"
#include "Constants.h"

#include <iostream>

#include <vector>
#include <algorithm>

std::vector<Particle*> Particle::particles;

Particle::Particle(double _mass, bool _charge, Vector3D _pos, Vector3D _vel, Shape* _shape) : 
    mass(_mass), charge(_charge), position(_pos), velocity(_vel), shape(_shape) {
        particles.push_back(this);
    }

Particle::~Particle() {
    particles.erase(std::find(particles.begin(), particles.end(), this));
}

double Particle::getMass() const {
    return this->mass;
}

bool Particle::getCharge() const {
    return this->charge;
}

Vector3D Particle::getPosition() const {
    return this->position;
}

Vector3D Particle::getVelocity() const {
    return this->velocity;
}

Shape* Particle::getShape() const {
    return this->shape;
}

void Particle::updateAcceleration() {
    acceleration = GRAVITY; // initialize acceleration with GRAVITY
}

void Particle::updateVelocity() {
    this->velocity += acceleration * TIME_STEP;
}

void Particle::updatePosition() {
    this->position += velocity * TIME_STEP;
}

double Particle::getDragCoefficient(Vector3D flowDirection) const {
    Shape* s = this->shape;

    if (Cube* cube = dynamic_cast<Cube*>(s)) {
        delete s;
        return (this->medium == Medium::Air) ? CUBE_AIR_DRAG_COEFF : CUBE_WATER_DRAG_COEFF;
    } else if (Sphere* sphere = dynamic_cast<Sphere*>(s)) {
        delete s;
        return (this->medium == Medium::Air) ? SPHERE_AIR_DRAG_COEFF : SPHERE_WATER_DRAG_COEFF;
    } else if (Cylinder* cylinder = dynamic_cast<Cylinder*>(s)) {
        double angle;
        if (cylinder->checkAlignmentWithFlow(flowDirection, angle)) {
            delete s;
            return (this->medium == Medium::Air) ? CYLINDER_AIR_ALIGN_DRAG_COEFF : CYLINDER_WATER_ALIGN_DRAG_COEFF;
        } else {
            delete s;
            return (this->medium == Medium::Air) ? CYLINDER_AIR_NON_ALIGN_DRAG_COEFF : CYLINDER_WATER_NON_ALIGN_DRAG_COEFF;
        }
    }
}

void Particle::print() const {
    std::cout << "Particle properties:" << std::endl;
    std::cout << "Mass: " << mass << std::endl;
    std::cout << "Charge: " << charge << std::endl;
    // TODO: Add velocity and position debugging here

}
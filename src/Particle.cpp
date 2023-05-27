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
        this->force = Vector3D();
        particles.push_back(this);
    }

Particle::~Particle() {
    particles.erase(std::find(particles.begin(), particles.end(), this));
}

double Particle::getMass() const {
    return this->mass;
}

double Particle::getDivergence() const {
    return this->divergence;
}

double Particle::getPressure() const {
    return this->pressure;
}

double Particle::getVolume() const {
    
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

Vector3D Particle::getForce() const {
    return this->force;
}

Shape* Particle::getShape() const {
    return this->shape;
}

void Particle::setDivergence(const float _divergence) {
    this->divergence = _divergence;
}

void Particle::setPressure(const float _pressure) {
    this->pressure = _pressure;
}

void Particle::setVolume(const double _volume) {
    this->volume = _volume;
}

void Particle::applyForce(const Vector3D& _force) {
    this->force += _force;
}

void Particle::update(const float deltaTime) {
    Vector3D acceleration = force / mass;

    this->velocity += acceleration * deltaTime;
    this->position += velocity * deltaTime;

    this->force = Vector3D(); // reset forces 
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
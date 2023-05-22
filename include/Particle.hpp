#ifndef PARTICLE_H_INCLUDED

#define PARTICLE_H_INCLUDED

#include "Vector3D.hpp"
#include "Shape.hpp"

#include <vector>

enum class Medium {
    Air,
    Water
};

class Particle {
    static std::vector<Particle*> particles;

private:
    double mass;
    bool charge;
    Vector3D acceleration;
    Vector3D position;
    Vector3D velocity;
    Medium medium;
    Shape* shape;

public:
    // Constructors
    Particle(double, bool, Vector3D, Vector3D, Shape*);

    // Destructor
    ~Particle();

    // Getters
    double getMass() const;
    bool getCharge() const;
    Vector3D getPosition() const;
    Shape* getShape() const;
    Vector3D getVelocity() const;

    double getDragCoefficient(Vector3D) const;
    
    // Update functions
    void updateAcceleration();
    void updatePosition();
    void updateVelocity();

    // To String function
    void print() const;

};

#endif
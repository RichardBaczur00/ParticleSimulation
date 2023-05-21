#include "Physics.hpp"
#include "Constants.h"

Vector3D gravitationalForce(Particle particle) {
    return GRAVITY * particle.getMass();
}

Vector3D dragForce(Particle particle) {
   
}


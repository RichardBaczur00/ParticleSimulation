#include "Physics.hpp"
#include "Constants.h"

Vector3D gravitationalForce(Particle particle) {
    return GRAVITY * particle.getMass();
}

Vector3D dragForce(Particle particle, double fluidDensity) {
   double area = particle.getShape()->calculateEffectiveCrossSectionalArea();
   double dragCoefficient = particle.getDragCoefficient(Vector3D()); // just have no flow (this will kinda render the force useless, but there is still things that need to be added to be able to calculate this)
   Vector3D velocity = particle.getVelocity();

   double velocityMagnitude = velocity.magnitude();
   double velocityMagnitudeSqrd = velocityMagnitude * velocityMagnitude;

   double dragForceMagnitude = 0.5 * fluidDensity * area * dragCoefficient * velocityMagnitudeSqrd;

   return velocity.normalize() * (-dragForceMagnitude);
}


#ifndef PHYSICS_H_INCLUDED

#define PHYSICS_H_INCLUDED

#include "Particle.hpp"

#include "VoxelGrid.hpp"

#include <vector>

Vector3D dragForce(Particle&, double);
Vector3D gravitationForce(Particle&);
std::vector<Vector3D> calculatePressureForce(Particle&, VoxelGrid&);
Vector3D calculateViscosityForce(Particle&);
Vector3D calculateSurfaceTensionForce(Particle&);
Vector3D calculateInteractionForce(Particle&, Particle&);

#endif
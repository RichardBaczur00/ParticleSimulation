#include "Physics.hpp"
#include "Constants.h"

#include <tuple>
#include <vector>

Vector3D gravitationalForce(Particle& particle) {
    return GRAVITY * particle.getMass();
}

Vector3D dragForce(Particle& particle, double fluidDensity) {
   double area = particle.getShape()->calculateEffectiveCrossSectionalArea();
   double dragCoefficient = particle.getDragCoefficient(Vector3D()); // just have no flow (this will kinda render the force useless, but there is still things that need to be added to be able to calculate this)
   Vector3D velocity = particle.getVelocity();

   double velocityMagnitude = velocity.magnitude();
   double velocityMagnitudeSqrd = velocityMagnitude * velocityMagnitude;

   double dragForceMagnitude = 0.5 * fluidDensity * area * dragCoefficient * velocityMagnitudeSqrd;

   return velocity.normalize() * (-dragForceMagnitude);
}

double calculateDivergence(const VoxelGrid& grid, const std::tuple<int, int, int> position) {
    double divergence = 0.0f;
    const std::vector<Voxel*> neighbors = grid.getNeighbors(position);

    const Particle* centerParticle = grid.getVoxel(position).type;
    const Vector3D& centerForce = centerParticle->getForce();

    for (const auto& neighbor : neighbors) {
        const std::tuple<int, int, int> neighborPosition(neighbor->x, neighbor->y, neighbor->z);
        const Particle* particle = grid.getVoxel(neighborPosition).type;
        const Vector3D force = particle->getForce();

        const double dx = force.getX() - centerForce.getX();
        const double dy = force.getY() - centerForce.getY();
        const double dz = force.getZ() - centerForce.getZ();

        divergence += dx + dy + dz;   
    }

    return divergence / neighbors.size();
}

Vector3D calculatePressureForce(Particle& particle, VoxelGrid& grid) {
    // TODO: Implement Pressure Force
    int sizeX = std::get<0>(grid.getSize());
    int sizeY = std::get<1>(grid.getSize());
    int sizeZ = std::get<2>(grid.getSize());

    // Divergence of velocity field
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            for (int k = 0; k < sizeZ; ++k) {
                const std::tuple<int, int, int> pos(i, j, k);
                Voxel& voxel = grid.getVoxel(pos);
                Particle* particle = voxel.type;
                particle->setDivergence(calculateDivergence(grid, pos));
            }
        }
    }

}

Vector3D calculateViscosityForce(Particle& particle) {
    // TOOD: Implement Viscosity Force
}

Vector3D calculateSurfaceTensionForce(Particle& particle) {
    // TODO: Implement Surface Tension Force
}

Vector3D calculateInteractionForce(Particle& particle, Particle& neighbor) {
    // TODO: Implement Interaction Force
}


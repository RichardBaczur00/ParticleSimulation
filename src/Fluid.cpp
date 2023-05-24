#include "Fluid.hpp"

Fluid::Fluid(VoxelGrid& grid) : voxelGrid(grid) {}

void Fluid::addParticle(const Particle& particle) {
    this->particles.push_back(particle);
}

void Fluid::update(const float deltaTime) {
    applyExternalForces();

    for (Particle& particle : this->particles) {
        applyInternalForces(particle);
        applyNeighborForces(particle);

        particle.update(deltaTime);
    }
}

void Fluid::applyExternalForces() {
    for (Particle& particle : this->particles) {
        particle.applyForce(gravitationForce(particle));
    }
}

void Fluid::applyInternalForces(Particle& particle) {
    Vector3D pressureForce = calculatePressureForce(particle, this->voxelGrid);
    Vector3D viscosityForce = calculateViscosityForce(particle);
    Vector3D surfaceTensionForce = calculateSurfaceTensionForce(particle);

    particle.applyForce(pressureForce);
    particle.applyForce(viscosityForce);
    particle.applyForce(surfaceTensionForce);
}

std::vector<Particle*> convertVoxelToParticle(const std::vector<Voxel*> voxelVector) {
    std::vector<Particle*> particles;
    for (const auto& voxel : voxelVector) {
        particles.push_back(voxel->type);
    }
    return particles;
}

void Fluid::applyNeighborForces(Particle& particle) {
    std::vector<Particle*> neighbors = convertVoxelToParticle(voxelGrid.getNeighbors(particle));

    for (Particle* neighbor : neighbors) {
        Vector3D interactionForce = calculateInteractionForce(particle, *neighbor);
        particle.applyForce(interactionForce);
    }
}
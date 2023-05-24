#ifndef FLUID_H_INCLUDED

#define FLUID_H_INCLUDED

#include "Particle.hpp"
#include "VoxelGrid.hpp"
#include "Physics.hpp"

#include <vector>

class Fluid {
private:
    std::vector<Particle> particles;
    VoxelGrid& voxelGrid;

public:
    Fluid(VoxelGrid&);

    void addParticle(const Particle&);
    void update(const float);

private:
    void applyExternalForces();
    void applyInternalForces(Particle&);
    void applyNeighborForces(Particle&);
};

#endif
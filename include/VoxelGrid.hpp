#ifndef VOXELGRID_H_INCLUDED

#define VOXELGRID_H_INCLUDED

#include "Particle.hpp"

#include <vector>
#include <tuple>


struct Voxel {
    int x, y, z;
    Particle* type;
};

class VoxelGrid {
private:
    std::tuple<int, int, int> size;
    double voxelSize;
    std::vector<Voxel&> voxels;

public:
    VoxelGrid();
    VoxelGrid(const std::tuple<int, int, int>&, const double);

    std::tuple<int, int, int> getSize() const;
    double getVoxelSize() const;
    Voxel& getVoxel(const std::tuple<int, int, int>&) const;
    void setVoxel(const std::tuple<int, int, int>&, Particle&);

    bool isValidVoxel(const std::tuple<int, int, int>&) const;

    void clearGrid();

    std::vector<Voxel*> getNeighbors(const Particle&) const;
    std::vector<Voxel*> getNeighbors(const std::tuple<int, int, int>) const;

};

#endif
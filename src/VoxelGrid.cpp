#include "VoxelGrid.hpp"
#include "Constants.h"

#include <tuple>

VoxelGrid::VoxelGrid() : 
    size(DEFAULT_VOXEL_GRID_SIZE), voxels(DEFAULT_VOXEL_SIZE) {
        int x = std::get<0>(size);
        int y = std::get<1>(size);
        int z = std::get<2>(size);

        this->voxels.resize(x * y * z);
}

VoxelGrid::VoxelGrid(const std::tuple<int, int, int>& _size, const double _voxelSize) : 
    size(_size), voxelSize(_voxelSize) {
        int x = std::get<0>(size);
        int y = std::get<1>(size);
        int z = std::get<2>(size);

        this->voxels.resize(x * y * z);
}

std::tuple<int, int, int> VoxelGrid::getSize() const {
    return this->size;
}

double VoxelGrid::getVoxelSize() const {
    return this->voxelSize;
}

Voxel& VoxelGrid::getVoxel(const std::tuple<int, int, int>& position) const {
    int x = std::get<0>(position);
    int y = std::get<1>(position);
    int z = std::get<2>(position);

    int sizeX = std::get<0>(position);
    int sizeY = std::get<1>(position);

    return voxels[x + y * sizeX + z * sizeX * sizeY];
}

void VoxelGrid::setVoxel(const std::tuple<int, int, int>& position, Particle& particle) {
    int x = std::get<0>(position);
    int y = std::get<1>(position);
    int z = std::get<2>(position);

    int sizeX = std::get<0>(position);
    int sizeY = std::get<1>(position);
    
    voxels[x + y * sizeX + z * sizeX * sizeY].type = &particle;
}

void VoxelGrid::clearGrid() {
    this->voxels.clear();

    int x = std::get<0>(this->size);
    int y = std::get<1>(this->size);
    int z = std::get<2>(this->size);

    this->voxels.resize(x * y * z);
}

bool VoxelGrid::isValidVoxel(const std::tuple<int, int, int>& position) const {
    int x = std::get<0>(position);
    int y = std::get<1>(position);
    int z = std::get<2>(position);

    int ubX = std::get<0>(this->size);
    int ubY = std::get<1>(this->size);
    int ubZ = std::get<2>(this->size);

    bool validX = 0 <= x && x <= ubX;
    bool validY = 0 <= y && y <= ubY;
    bool validZ = 0 <= z && z <= ubZ;

    return validX && validY && validZ;    
}

std::vector<Voxel*> VoxelGrid::getNeighbors(const Particle& particle) const {
    std::vector<Voxel*> neighbors;

    int voxelX = static_cast<int>(particle.getPosition().getX() / this->voxelSize);
    int voxelY = static_cast<int>(particle.getPosition().getY() / this->voxelSize);
    int voxelZ = static_cast<int>(particle.getPosition().getZ() / this->voxelSize);

    for (int x = voxelX - 1; x <= voxelX + 1; ++x) {
        for (int y = voxelY - 1; y <= voxelY + 1; ++y) {
            for (int z = voxelZ - 1; z <= voxelZ + 1; ++z) {
                if (this->isValidVoxel(std::tuple<int, int, int>(x, y, z))) {
                    Voxel* voxel = &this->getVoxel(std::tuple<int, int, int>(x, y, z));
                    neighbors.push_back(voxel);
                }
            }
        }
    }

    return neighbors;
}

std::vector<Voxel*> VoxelGrid::getNeighbors(const std::tuple<int, int, int> position) const {
    std::vector<Voxel*> neighbors;

    int voxelX = std::get<0>(position);
    int voxelY = std::get<1>(position);
    int voxelZ = std::get<2>(position);

    for (int x = voxelX - 1; x <= voxelX + 1; ++x) {
        for (int y = voxelY - 1; y <= voxelY + 1; ++y) {
            for (int z = voxelZ - 1; z <= voxelZ + 1; ++z) {
                if (this->isValidVoxel(std::tuple<int, int, int>(x, y, z))) {
                    Voxel* voxel = &this->getVoxel(std::tuple<int, int, int>(x, y, z));
                    neighbors.push_back(voxel);
                }
            }
        }
    }

    return neighbors;
}

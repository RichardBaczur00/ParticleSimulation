#include "Matrix3x3.hpp"

#include "Vector3D.hpp"

#include <cmath>

Matrix3x3::Matrix3x3() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            elements[i][j] = 0;
        }
    }
}

void Matrix3x3::setElement(int row, int col, float val) {
    elements[row][col] = val;
}

float Matrix3x3::getElement(int row, int col) const {
    return elements[row][col];
}

void Matrix3x3::setRotationZ(float angle) {
    elements[0][0] = elements[1][1] = std::cos(angle);
    elements[0][1] = std::sin(angle);
    elements[1][0] = -std::sin(angle);
    elements[2][2] = 1.0;
}

Vector3D Matrix3x3::operator*(const Vector3D& other) const {
    float resultX = this->getElement(0, 0) * other.getX() +
                    this->getElement(0, 1) * other.getY() +
                    this->getElement(0, 2) * other.getZ();
    
    float resultY = this->getElement(1, 0) * other.getX() +
                    this->getElement(1, 1) * other.getY() + 
                    this->getElement(1, 2) * other.getZ();
    
    float resultZ = this->getElement(2, 0) * other.getX() +
                    this->getElement(2, 1) * other.getX() +
                    this->getElement(2, 2) * other.getZ();
    
    return Vector3D(resultX, resultY, resultZ);
}
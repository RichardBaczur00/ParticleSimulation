#include "Vector3D.hpp"
#include "math.h"

Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0) {}

Vector3D::Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

double Vector3D::getX() const {
    return this->x;
}

double Vector3D::getY() const {
    return this->y;
}

double Vector3D::getZ() const {
    return this->z;
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(this->x + other.getX(), this->y + other.getY(), this->z + other.getZ());
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(this->x - other.getX(), this->y - other.getY(), this->z - other.getZ());
}

Vector3D Vector3D::operator*(const double scalar) const {
    return Vector3D(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3D Vector3D::operator/(const double scalar) const {
    if (scalar == 0) {
        return Vector3D();
    }

    return Vector3D(this->x / scalar, this->y / scalar, this->z / scalar);
}

Vector3D Vector3D::operator+=(const Vector3D& other) {
    *this = *this + other;
    return *this;
}

Vector3D Vector3D::operator-=(const Vector3D& other) {
    *this = *this - other;
    return *this;
}

double Vector3D::dotProduct(const Vector3D& other) const {
    return this->x * other.getX() + this->y * other.getY() + this->z * other.getZ();
}

Vector3D Vector3D::crossProduct(const Vector3D& other) const {
    double crossX = this->y * other.getZ() - this->z * other.getY();
    double crossY = this->z * other.getX() - this->x * other.getZ();
    double crossZ = this->x * other.getY() - this->y * other.getX();
    return Vector3D(crossX, crossY, crossZ);
}

double Vector3D::magnitude() const {
    return std::sqrt(
        this->x * this->x + 
        this->y * this->y + 
        this->z * this->z
    );
}

Vector3D Vector3D::normalize() const {
    double mag = this->magnitude();
    return *this / mag;
}
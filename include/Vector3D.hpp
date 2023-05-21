#ifndef VECTOR3D_H_INCLUDED

#define VECTOR3D_H_INCLUDED

class Vector3D {
private:
    double x;
    double y;
    double z;

public:
    Vector3D();
    Vector3D(double, double, double);

    double getX() const;
    double getY() const;
    double getZ() const;

    Vector3D operator+(const Vector3D&) const;
    Vector3D operator-(const Vector3D&) const;
    Vector3D operator*(const double) const;
    Vector3D operator/(const double) const;
    
    Vector3D operator+=(const Vector3D&);
    Vector3D operator-=(const Vector3D&);

    double dotProduct(const Vector3D&) const;
    Vector3D crossProduct(const Vector3D&) const;

    double magnitude() const;

    Vector3D normalize() const;
};

#endif
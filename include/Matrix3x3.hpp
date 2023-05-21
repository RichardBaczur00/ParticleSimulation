#ifndef MATRIX_H_INCLUDED

#define MATRIX_H_INCLUDED

class Matrix3x3 {
private:
    float elements[3][3];

public:
    Matrix3x3();

    void setElement(int, int, float);
    float getElement(int, int) const;

    void setRotationZ(float angle);

    Vector3D operator*(const Vector3D&) const;
};

#endif
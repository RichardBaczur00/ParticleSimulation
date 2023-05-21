#ifndef CONSTANTS_H_INCLUDED

#define CONSTANTS_H_INCLUDED

#include "Vector3D.hpp"

#include <cmath>

const float TIME_STEP = 0.01f;

const Vector3D GRAVITY(0, 9.8f, 0);

const double AIR_DENSITY = 1.225f;
const double WATER_DENSITY = 1000.f;

const float FLOW_DIRECTION_THRESHOLD = 0.95f;

const double PI = std::acos(-1.0f);
const double STRAIGHT_ANGLE = 180.0f;

const double CUBE_WATER_DRAG_COEFF = 1.15f;
const double SPHERE_WATER_DRAG_COEFF = 0.45f;
const double CYLINDER_WATER_ALIGN_DRAG_COEFF = 1.0f;
const double CYLINDER_WATER_NON_ALIGN_DRAG_COEFF = 0.35f;

const double CUBE_AIR_DRAG_COEFF = 1.125f;
const double SPHERE_AIR_DRAG_COEFF = 0.35f;
const double CYLINDER_AIR_ALIGN_DRAG_COEFF = 0.975f;
const double CYLINDER_AIR_NON_ALIGN_DRAG_COEFF = 0.575f;


#endif
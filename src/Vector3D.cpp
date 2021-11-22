//
// Created by Adrián Jaén on 21/11/2021.
//

#include "../include/Vector3D.h"
#include "cfloat"

float Vector3D::getX() const {return x;}

float Vector3D::getY() const {return y;}

float Vector3D::getZ() const {return z;}

void Vector3D::set(Vector3D v) {
    x=v.getX();
    y=v.getY();
    z=v.getZ();

    normalize();
}

void Vector3D::setX(float value) {x=value;}

void Vector3D::setY(float value) {y=value;}

void Vector3D::setZ(float value) {z=value;}

Vector3D::Vector3D() {
    x=0, y=0, z=0;
}

Vector3D::Vector3D(float a, float b, float c) {
    x = a, y = b, z = c;
}

void Vector3D::normalize() {
    double mod = sqrt(x*x + y*y + z*z);
    mod = round(mod * 10000.0) / 10000.0;
    x/=mod, y/=mod, z/=mod;
}

void Vector3D::ridZeros() {
    if(x == 0){x = FLT_MIN;}
    if(y == 0){y = FLT_MIN;}
    if(z == 0){z = FLT_MIN;}
}

